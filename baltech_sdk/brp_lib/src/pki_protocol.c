#include "brp_lib/brp_protocol.h"
#include "brp_lib/composite_protocol.h"
#include "brp_lib/pki_protocol.h"
#include "brp_lib/base64.h"
#include "uECC.h"
#include "sha256.h"
#include "aes.h"


#define TIMEOUT_PKICMD                 16000

#define AES_KEY_BITS                   128
#define AES_KEY_SIZE                   (AES_KEY_BITS/8)
#define PRIVATE_KEY_DERFMT_SIZE        121

#define CMDCODE_PFS_GEN_KEY            0x0901
#define CMDCODE_PFS_AUTH_HOST_CERT     0x0902
#define CMDCODE_PFS_AUTH_RDR_CERT      0x0903
#define CMDCODE_PFS_TUNNEL2            0x0904

#define ERR_CRYPTO                     BRP_ERR_STATUS(0x0900, 0x01)
#define ERR_TUNNEL                     BRP_ERR_STATUS(0x0900, 0x02)
#define ERR_CERT                       BRP_ERR_STATUS(0x0900, 0x03)
#define ERR_SEQCTR                     BRP_ERR_STATUS(0x0900, 0x04)
#define ERR_SECLEVEL_UNSUPPORTED       BRP_ERR_STATUS(0x0900, 0x05)
#define ERR_SESSION_TIMEOUT            BRP_ERR_STATUS(0x0900, 0x06)

#define ASN1_TAGID_INTEGER             0x02
#define ASN1_TAGID_BIT_STRING          0x03
#define ASN1_TAGID_OBJECT_ID           0x06
#define ASN1_TAGID_SEQ                 0x30
#define ASN1_TAGID_CERT_VERSION        0xA0


typedef struct pki_protocol_t {
	struct brp_protocol_t p;
	int security_level;
	struct brp_frame_t host_cert_chain;
	struct brp_frame_t dev_ca_cert_chain;
	struct brp_frame_t dev_cert;
	unsigned char private_key[PRIVATE_KEY_DERFMT_SIZE];
	brp_time session_timeout;
	unsigned char session_key[AES_KEY_SIZE];
	unsigned seq_ctr;
	int last_cmd_code;
} * pki_protocol;


static unsigned char pubkey_hdr_derfmt[] = {
	0x30, 0x59, 
		0x30, 0x13, 
			0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 
			0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 
		0x03, 0x42, 0x00, 0x04, /* inserts uECC_BYTES*2 sized pubkey here */ } ;


static unsigned char asn1_oid_prime256v1[] = {
	0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01,
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07
} ;


static unsigned char asn1_oid_ecdh_sha256[] = {
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02
} ;


brp_errcode map_pki_errcode(brp_errcode errcode)
{
	if (errcode & BRP_ERRGRP_DEVICE)
		switch (errcode)
		{
			case ERR_CERT:    return BRP_ERR_HOST_CERT_FORMAT;
			case ERR_SECLEVEL_UNSUPPORTED:
			                  return BRP_ERR_SEC_LEVEL_NOT_SUPPORTED;
			case ERR_SEQCTR:  return BRP_ERR_SEQ_CTR_NOT_IN_SYNC;
			case ERR_SESSION_TIMEOUT:
			                  return ERR_SESSION_TIMEOUT;
			default:          return BRP_ERR_CRYPTO_RECV_DEV;
		}
	else
		return errcode;
}


static brp_errcode exec_frame(brp_protocol protocol)
{
	brp_errcode errcode = brp_send_frame(protocol);
	if (errcode == BRP_OK)
		errcode = map_pki_errcode(brp_recv_any_frame(protocol, BRP_INFINITE));
	return errcode;
}


static void calc_sha256(brp_buf src, size_t len, brp_buf dest)
{
	SHA256_CTX ctx;
	sha256_init(&ctx);
	sha256_update(&ctx, src, len);
	sha256_final(&ctx, dest);
}


static void frame_write_pubkey_derfmt(brp_frame frame, brp_buf public_key)
{
	brp_frame_write_int16(frame,  sizeof(pubkey_hdr_derfmt) + uECC_BYTES*2);
	brp_frame_write(frame, pubkey_hdr_derfmt, sizeof(pubkey_hdr_derfmt));
	brp_frame_write(frame, public_key, uECC_BYTES*2);
}


static brp_buf frame_read_pubkey_derfmt(brp_frame_reader *frm_rdr)
{
	int pubkey_derfmt_len;
	brp_buf hdr_ptr;

	pubkey_derfmt_len = brp_frame_read_int16(frm_rdr);
	if (pubkey_derfmt_len != sizeof(pubkey_hdr_derfmt) + uECC_BYTES*2)
		return NULL;

	hdr_ptr = brp_frame_reader_next(frm_rdr, sizeof(pubkey_hdr_derfmt));
	if (hdr_ptr == NULL  ||
		memcmp(pubkey_hdr_derfmt, hdr_ptr, sizeof(pubkey_hdr_derfmt)) != 0)
		return NULL;

	return brp_frame_reader_next(frm_rdr, uECC_BYTES*2);
}


brp_errcode brp_pki_pfs_gen_key(brp_protocol protocol, brp_buf shared_secret)
{
	brp_buf dev_public_key;
	uint8_t public_key[uECC_BYTES*2], private_key[uECC_BYTES];
	uint8_t ecdh_result[uECC_BYTES], sha_result[SHA256_BLOCK_SIZE];
	brp_errcode errcode;
	brp_frame_reader recv_rdr;

	if (protocol == NULL)
		return BRP_ERR_INVALID_API_CALL;

	if (! uECC_make_key(public_key, private_key))
		return BRP_ERR_PKI_OPERATION_FAILED;

	brp_frame_write_start(&protocol->send_frame);
	brp_frame_write_int8(&protocol->send_frame, BRP_MODE_STD);
	brp_frame_write_int16(&protocol->send_frame, CMDCODE_PFS_GEN_KEY);
	brp_frame_write_int32(&protocol->send_frame, TIMEOUT_PKICMD);
	frame_write_pubkey_derfmt(&protocol->send_frame, public_key);
	if (brp_frame_write_err(&protocol->send_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	errcode = exec_frame(protocol);
	if (errcode == BRP_ERR_STATUS(0x0900, 0x03))
		// map "invalid certificate" to generic PKI format error
		// (as we did not transmit a certificate but only a public key...)
		return BRP_ERR_CRYPTO_FORMAT;
	if (errcode != BRP_OK)
		return errcode;
	brp_frame_read_start(&recv_rdr, &protocol->recv_frame);
	dev_public_key = frame_read_pubkey_derfmt(&recv_rdr);
	if (dev_public_key == NULL  ||  !brp_frame_read_eof(&recv_rdr))
		return BRP_ERR_CRYPTO_FORMAT;

	if (! uECC_shared_secret(dev_public_key, private_key, ecdh_result))
		return BRP_ERR_PKI_OPERATION_FAILED;

	calc_sha256(ecdh_result, sizeof(ecdh_result), sha_result);
	memcpy(shared_secret, sha_result, uECC_BYTES);

	return BRP_OK;
}


static brp_frame_reader asn1_enter_tag(
	brp_frame_reader * asn1_rdr, int expected_tag_id, size_t *return_tag_len)
{
	int tag_id;
	size_t tag_len;
	brp_frame_reader content;

	tag_id = brp_frame_read_int8(asn1_rdr);
	tag_len = brp_frame_read_int8(asn1_rdr);
	if (tag_len == 0x81)
		tag_len = brp_frame_read_int8(asn1_rdr);
	else if (tag_len == 0x82)
		tag_len = brp_frame_read_int16(asn1_rdr);
	else if (tag_len & 0x80)
		tag_len = BRP_FRAME_INVALID_SIZE;
	content = *asn1_rdr;
	brp_frame_skip(asn1_rdr, tag_len);

	if (tag_id != expected_tag_id  ||  tag_len == BRP_FRAME_INVALID_SIZE)
		asn1_rdr->err = true;

	if (return_tag_len != NULL)
		*return_tag_len = tag_len;
	content.err = asn1_rdr->err;
	return content;
}


static size_t asn1_skip_tag(brp_frame_reader * asn1_rdr, int expected_tag_id)
{
	brp_frame_reader start_rdr = *asn1_rdr;
	brp_frame_reader content_rdr =
			asn1_enter_tag(asn1_rdr, expected_tag_id, NULL);
	if (brp_frame_read_err(&content_rdr))
		return BRP_FRAME_INVALID_SIZE;
	return brp_frame_read_diff(asn1_rdr, &start_rdr);
}


static bool extract_from_cert_1(
	brp_frame_reader * cert,
	brp_frame_reader * issuer, size_t * issuer_len,
	brp_frame_reader * data, size_t * data_len,
	brp_buf signature)
{
	brp_frame_reader cert_seq, tbs_cert_seq, sig_bitstr, sig_seq, sig_algo, sig;
	size_t sig_algo_len, sig_len;
	unsigned dummy_zero, sig_part;

	cert_seq = asn1_enter_tag(cert, ASN1_TAGID_SEQ, NULL);
	*data = cert_seq;
	tbs_cert_seq = asn1_enter_tag(&cert_seq, ASN1_TAGID_SEQ, NULL);
	*data_len = brp_frame_read_diff(&cert_seq, data);
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_CERT_VERSION);
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_INTEGER); // serialnumber
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_SEQ);  // signature
	*issuer = asn1_enter_tag(&tbs_cert_seq, ASN1_TAGID_SEQ, issuer_len);

	sig_algo = asn1_enter_tag(&cert_seq, ASN1_TAGID_SEQ, &sig_algo_len);
	sig_bitstr = asn1_enter_tag(&cert_seq, ASN1_TAGID_BIT_STRING, NULL);
	dummy_zero = brp_frame_read_int8(&sig_bitstr);
	sig_seq = asn1_enter_tag(&sig_bitstr, ASN1_TAGID_SEQ, NULL);

	for (sig_part = 0; sig_part < 2; sig_part++)
	{
		sig = asn1_enter_tag(&sig_seq, ASN1_TAGID_INTEGER, &sig_len);
		if (brp_frame_read_err(&sig))
			return false;

		if (sig_len > uECC_BYTES)
		{
			brp_frame_skip(&sig, sig_len - uECC_BYTES);
			sig_len = uECC_BYTES;
		}
		else
		{
			memset(signature, 0, uECC_BYTES - sig_len);
			signature += (uECC_BYTES - sig_len);
		}

		brp_frame_read(&sig, signature, sig_len);
		signature += sig_len;
	}

	if (brp_frame_read_err(&*cert)  ||  brp_frame_read_err(&tbs_cert_seq))
		return false;

	if (dummy_zero != 0)
		return false;

	if (sig_algo_len != sizeof(asn1_oid_ecdh_sha256)  ||
	    memcmp(sig_algo.ptr, asn1_oid_ecdh_sha256, sig_algo_len) != 0)
	    return false;

	return true;
}


static bool extract_from_cert_2(
	brp_frame_reader * cert,
	brp_frame_reader * subject, size_t * subject_len,
	brp_frame_reader * pubkey)
{
	brp_frame_reader cert_seq, tbs_cert_seq, pubkey_seq, pubkey_algo;
	size_t pubkey_algo_len, pubkey_len;
	int pubkey_hdr;

	cert_seq = asn1_enter_tag(cert, ASN1_TAGID_SEQ, NULL);
	tbs_cert_seq = asn1_enter_tag(&cert_seq, ASN1_TAGID_SEQ, NULL);
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_CERT_VERSION);
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_INTEGER); // serialnumber
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_SEQ);   // signature algorithm
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_SEQ);   // issuer dn
	asn1_skip_tag(&tbs_cert_seq, ASN1_TAGID_SEQ);   // validity
	*subject = asn1_enter_tag(&tbs_cert_seq, ASN1_TAGID_SEQ, subject_len);
	pubkey_seq = asn1_enter_tag(&tbs_cert_seq, ASN1_TAGID_SEQ, NULL);
	pubkey_algo = asn1_enter_tag(&pubkey_seq, ASN1_TAGID_SEQ, &pubkey_algo_len);
	*pubkey = asn1_enter_tag(&pubkey_seq, ASN1_TAGID_BIT_STRING, &pubkey_len);

	if (brp_frame_read_err(&*cert)  ||  brp_frame_read_err(&pubkey_seq))
		return false;

	if (pubkey_algo_len != sizeof(asn1_oid_prime256v1)  ||
	    memcmp(pubkey_algo.ptr, asn1_oid_prime256v1, pubkey_algo_len) != 0)
	    return false;

	if (pubkey_len != 2 + 2*uECC_BYTES)
		return false;

	pubkey_hdr = brp_frame_read_int16(pubkey);
	if (pubkey_hdr != 0x0004)
		return false;

	return true;
}


static brp_errcode x509_verify(
	brp_frame_reader * cert, brp_frame_reader issuer_cert)
{
	brp_frame_reader issuer, signed_data, i_subject, i_pubkey;
	size_t issuer_len, signed_data_len, i_subject_len;
	unsigned char signature[2 * uECC_BYTES], hash[uECC_BYTES];
	bool valid_cert = extract_from_cert_1(
		cert, &issuer, &issuer_len, &signed_data, &signed_data_len, signature);
	bool valid_issuer_cert = extract_from_cert_2(
		&issuer_cert, &i_subject, &i_subject_len, &i_pubkey);

	if (! valid_cert)
		return BRP_ERR_DEV_CERT_FORMAT;

	if (! valid_issuer_cert)
		return BRP_ERR_HOST_CERT_FORMAT;
	
	if (issuer_len != i_subject_len  ||
	    memcmp(issuer.ptr, i_subject.ptr, issuer_len) != 0)
		return BRP_ERR_DEV_CERT_INVALID_SIGNATURE;

	calc_sha256(signed_data.ptr, signed_data_len, hash);
	if (! uECC_verify(i_pubkey.ptr, hash, signature))
		return BRP_ERR_DEV_CERT_INVALID_SIGNATURE;

	return BRP_OK;
}


static bool encrypt_frame(
		brp_frame frame, size_t offset, brp_buf key, brp_buf iv)
{
	aes_key_schedule key_schedule;
	size_t padding_len;

	padding_len = (AES_BLOCK_SIZE - ((frame->act_size-offset)%AES_BLOCK_SIZE));
	padding_len = padding_len == AES_BLOCK_SIZE ? 0 : padding_len;
	brp_frame_write_fill(frame, 0, padding_len);
	if (brp_frame_write_err(frame))
		return false;

	aes_key_setup(key, key_schedule, AES_KEY_BITS);
	aes_encrypt_cbc(frame->ptr + offset, (int) (frame->act_size - offset),
	                frame->ptr + offset,
	                key_schedule, AES_KEY_BITS, iv);

	return true;
}


static brp_errcode pfs_auth_host_cert(
	brp_protocol protocol, brp_buf shared_secret,
	int security_level, brp_time session_timeout, bool is_end_cert,
	brp_frame_reader * cert_rdr, size_t cert_size,
	brp_frame crypto_frame)
{
	brp_errcode errcode;

	if (session_timeout == BRP_INFINITE)
		// the firmware requires 0 instead of BRP_INFINITE
		session_timeout = 0;

	// build unencrypted frame first
	brp_frame_write_start(crypto_frame);
	brp_frame_write_int8(crypto_frame, (unsigned) security_level);
	brp_frame_write_int32(crypto_frame, (unsigned) session_timeout);
	brp_frame_write_int8(crypto_frame, (unsigned) is_end_cert);
	brp_frame_write_int16(crypto_frame, (unsigned) cert_size);
	brp_frame_write_frm(crypto_frame, cert_rdr, (unsigned) cert_size);
	if (brp_frame_read_err(&*cert_rdr))
		return BRP_ERR_HOST_CERT_FORMAT;
	if (brp_frame_write_err(crypto_frame))
		return BRP_ERR_OUT_OF_MEMORY;

	if (! encrypt_frame(crypto_frame, 0,
	                    shared_secret, shared_secret + AES_KEY_SIZE))
		return BRP_ERR_OUT_OF_MEMORY;

	// send frame
	brp_frame_write_start(&protocol->send_frame);
	brp_frame_write_int8(&protocol->send_frame, BRP_MODE_STD);
	brp_frame_write_int16(&protocol->send_frame, CMDCODE_PFS_AUTH_HOST_CERT);
	brp_frame_write_int32(&protocol->send_frame, TIMEOUT_PKICMD);
	brp_frame_write_int16(&protocol->send_frame, (int) crypto_frame->act_size);
	brp_frame_write(&protocol->send_frame,
	                crypto_frame->ptr, crypto_frame->act_size);
	if (brp_frame_write_err(&protocol->send_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	errcode = exec_frame(protocol);
	if (errcode != BRP_OK)
		return errcode;

	if (protocol->recv_frame.act_size != 0)
		return BRP_ERR_CRYPTO_FORMAT;

	return BRP_OK;
}


static brp_errcode pfs_auth_rdr_cert(
	brp_protocol protocol, brp_buf shared_secret, brp_frame rdr_cert_frame)
{
	size_t recv_len;
	brp_frame_reader recv_frame_rdr;
	brp_errcode errcode;
	aes_key_schedule key_schedule;
	unsigned char iv[AES_BLOCK_SIZE];

	brp_frame_write_start(&protocol->send_frame);
	brp_frame_write_int8(&protocol->send_frame, BRP_MODE_STD);
	brp_frame_write_int16(&protocol->send_frame, CMDCODE_PFS_AUTH_RDR_CERT);
	brp_frame_write_int32(&protocol->send_frame, TIMEOUT_PKICMD);
	if (brp_frame_write_err(&protocol->send_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	errcode = exec_frame(protocol);
	if (errcode != BRP_OK)
		return errcode;

	brp_frame_read_start(&recv_frame_rdr, &protocol->recv_frame);
	recv_len = brp_frame_read_int16(&recv_frame_rdr);
	brp_frame_read_frm(&recv_frame_rdr, rdr_cert_frame, recv_len);
	if (brp_frame_write_err(rdr_cert_frame)  &&
	    !brp_frame_read_err(&recv_frame_rdr))
		return BRP_ERR_OUT_OF_MEMORY;
	if (!brp_frame_read_eof(&recv_frame_rdr))
		return BRP_ERR_HOST_CERT_FORMAT;

	memcpy(iv, shared_secret + AES_KEY_SIZE, AES_BLOCK_SIZE);
	aes_key_setup(shared_secret, key_schedule, AES_KEY_BITS);
	aes_decrypt_cbc(rdr_cert_frame->ptr, (int) rdr_cert_frame->act_size,
	                rdr_cert_frame->ptr, key_schedule, AES_KEY_BITS, iv);

	return BRP_OK;
}


static brp_errcode walk_and_verify_to_last_cert(
	brp_frame_reader * cert_chain_rdr)
{
	brp_errcode errcode;
	brp_frame_reader issuer_cert;
	brp_frame_reader next_issuer_cert = *cert_chain_rdr;
	do
	{
		issuer_cert = next_issuer_cert;
		next_issuer_cert = *cert_chain_rdr;
		
		errcode = x509_verify(cert_chain_rdr, issuer_cert);
		if (errcode == BRP_ERR_DEV_CERT_FORMAT)
			return BRP_ERR_HOST_CERT_FORMAT;
		if (errcode != BRP_OK)
			return errcode;
	} while (!brp_frame_read_eof(&*cert_chain_rdr));
	
	*cert_chain_rdr = next_issuer_cert;
	return BRP_OK;
}


static brp_errcode send_cert_chain(
	brp_protocol protocol,
	brp_buf shared_secret,
	int security_level,
	brp_time session_timeout,
	brp_frame host_cert_chain,
	brp_frame crypto_frame)
{
	brp_frame_reader host_cert_chain_rdr;
	brp_errcode errcode;
	size_t cert_size;

	// skip first certificate
	brp_frame_read_start(&host_cert_chain_rdr, host_cert_chain);
	cert_size = asn1_skip_tag(&host_cert_chain_rdr, ASN1_TAGID_SEQ);
	if (cert_size == -1)
		return BRP_ERR_HOST_CERT_FORMAT;

	do
	{
		bool is_end_cert;
		brp_frame_reader host_cert = host_cert_chain_rdr;
		cert_size = asn1_skip_tag(&host_cert_chain_rdr, ASN1_TAGID_SEQ);
		if (cert_size == -1)
			return BRP_ERR_HOST_CERT_FORMAT;
		is_end_cert = brp_frame_read_eof(&host_cert_chain_rdr);

		errcode = pfs_auth_host_cert(
			protocol,
			shared_secret,
			security_level,
			session_timeout,
			is_end_cert,
			&host_cert,
			cert_size,
			crypto_frame);
		if (errcode != BRP_OK)
			return errcode;
	} while (! brp_frame_read_eof(&host_cert_chain_rdr));

	return BRP_OK;
}


static brp_errcode extract_from_resp(
	brp_frame resp_frame,
	brp_frame_reader * issuer_cert,
	brp_frame dev_cert,
	brp_buf public_key)
{
	brp_frame_reader resp_frame_rdr;
	brp_frame_reader dev_cert_rdr;
	brp_errcode errcode;
	size_t cert_size;
	brp_frame_reader subj, public_key_rdr;
	size_t subj_len;

	// check BRP frame for validity and extract device certificate (dev_cert)
	brp_frame_read_start(&resp_frame_rdr, resp_frame);
	cert_size = brp_frame_read_int16(&resp_frame_rdr);
	brp_frame_read_frm(&resp_frame_rdr, dev_cert, cert_size);
	if (brp_frame_write_err(dev_cert)  &&
	    !brp_frame_read_err(&resp_frame_rdr))
		return BRP_ERR_OUT_OF_MEMORY;
	while (brp_frame_rest(&resp_frame_rdr) > 0)
	{
		int zero_byte;
		zero_byte = brp_frame_read_int8(&resp_frame_rdr);
		if (zero_byte != 0)
			return BRP_ERR_CRYPTO_FORMAT;
	}
	if (brp_frame_read_err(&resp_frame_rdr))
		return BRP_ERR_CRYPTO_FORMAT;

	// check if device certificate (dev_cert) is valid
	brp_frame_read_start(&dev_cert_rdr, dev_cert);
	errcode = x509_verify(&dev_cert_rdr, *issuer_cert);
	if (errcode != BRP_OK)
		return errcode;
	if (! brp_frame_read_eof(&dev_cert_rdr))
		return BRP_ERR_DEV_CERT_FORMAT;

	// extract public key (public_key) from device certificate (dev_cert)
	brp_frame_read_start(&dev_cert_rdr, dev_cert);
	if (!extract_from_cert_2(&dev_cert_rdr,
	                         &subj, &subj_len, &public_key_rdr))
		return BRP_ERR_DEV_CERT_FORMAT;

	brp_frame_read(&public_key_rdr, public_key, uECC_BYTES*2);
	return BRP_OK;
}


static brp_errcode calc_session_key(brp_buf shared_secret,
                                    brp_buf private_key_derfmt,
                                    brp_buf public_key, brp_buf session_key)
{
	unsigned char iv[AES_BLOCK_SIZE];
	unsigned char shared_secret_2[uECC_BYTES];
	aes_key_schedule key_schedule;

	// replace this by an asn1_parser:
	brp_buf private_key = private_key_derfmt + 7;

	if (! uECC_shared_secret(public_key, private_key, shared_secret_2))
		return BRP_ERR_PKI_OPERATION_FAILED;

	memcpy(iv, shared_secret + AES_KEY_SIZE, AES_BLOCK_SIZE);
	aes_key_setup(shared_secret, key_schedule, AES_KEY_BITS);
	aes_encrypt_cbc(shared_secret_2, AES_BLOCK_SIZE,
	                session_key, key_schedule, AES_KEY_BITS, iv);

	return BRP_OK;
}

brp_errcode brp_pki_init_pfs_session(
	brp_protocol protocol,
	brp_buf session_key,
	brp_buf shared_secret,
	int security_level,
	brp_buf private_key_derfmt,
	brp_frame dev_cert_chain,
	brp_frame host_cert_chain,
	brp_frame dev_cert,
	brp_time session_timeout)
{
	struct brp_frame_t crypto_frame;
	brp_frame_reader issuer_cert;
	brp_errcode errcode;
	unsigned char dev_public_key[2 * uECC_BYTES];

	brp_frame_read_start(&issuer_cert, dev_cert_chain);
	errcode = walk_and_verify_to_last_cert(&issuer_cert);
	if (errcode != BRP_OK)
		return errcode;

	brp_frame_init(&crypto_frame);

	errcode = send_cert_chain(protocol, shared_secret, security_level,
	                          session_timeout, host_cert_chain, &crypto_frame);

	if (errcode == BRP_OK)
		errcode = pfs_auth_rdr_cert(protocol, shared_secret, &crypto_frame);

	if (errcode == BRP_OK)
		errcode = extract_from_resp(&crypto_frame, &issuer_cert,
		                            dev_cert, dev_public_key);

	brp_frame_deinit(&crypto_frame);

	if (errcode == BRP_OK)
		errcode = calc_session_key(shared_secret, private_key_derfmt,
		                           dev_public_key, session_key);

	return errcode;
}


static void init_iv(brp_buf iv, int leading_byte, unsigned long seq_ctr)
{
	memset(iv, 0, AES_BLOCK_SIZE);
	iv[0] = (unsigned char) leading_byte;
	iv[AES_BLOCK_SIZE-4] = (unsigned char) (seq_ctr >> 24);
	iv[AES_BLOCK_SIZE-3] = (unsigned char) (seq_ctr >> 16);
	iv[AES_BLOCK_SIZE-2] = (unsigned char) (seq_ctr >> 8);
	iv[AES_BLOCK_SIZE-1] = (unsigned char) (seq_ctr >> 0);
}


brp_errcode brp_pki_tunnel_send_frame(
	brp_protocol protocol, brp_buf session_key, unsigned long seq_ctr,
	brp_frame plain_cmd)
{
	brp_frame_reader plain_cmd_rdr;
	unsigned mode, cmd_code;
	brp_time cmd_timeout;
	aes_key_schedule key_schedule;
	unsigned char iv10[AES_BLOCK_SIZE], iv20[AES_BLOCK_SIZE];
	size_t enc_param_len;
	size_t hmac_offset, enc_param_len_offset, enc_param_offset;
	brp_frame send_frm = &protocol->send_frame;

	// read plain header
	brp_frame_read_start(&plain_cmd_rdr, plain_cmd);
	mode = brp_frame_read_int8(&plain_cmd_rdr);
	cmd_code = brp_frame_read_int16(&plain_cmd_rdr);
	cmd_timeout = (brp_time) brp_frame_read_int32(&plain_cmd_rdr);

	// write plain header of tunnel2 command
	brp_frame_write_start(send_frm);
	brp_frame_write_int8(send_frm, mode);
	brp_frame_write_int16(send_frm, (unsigned) CMDCODE_PFS_TUNNEL2);
	brp_frame_write_int32(send_frm, (unsigned) cmd_timeout);
	brp_frame_write_int32(send_frm, (unsigned) seq_ctr);
	hmac_offset = send_frm->act_size;
	brp_frame_write_fill(send_frm, 0, AES_BLOCK_SIZE);
	enc_param_len_offset = send_frm->act_size;
	brp_frame_write_int16(send_frm, 0);

	// write encrypted header of tunnel2 command
	enc_param_offset = send_frm->act_size;
	brp_frame_write_int16(send_frm, cmd_code);
	brp_frame_write_int16(send_frm, (unsigned) brp_frame_rest(&plain_cmd_rdr));
	brp_frame_write_frm_rest(send_frm, &plain_cmd_rdr);
	if (brp_frame_write_err(send_frm)  &&  !brp_frame_read_err(&plain_cmd_rdr))
		return BRP_ERR_OUT_OF_MEMORY;
	if (!brp_frame_read_eof(&plain_cmd_rdr))
		return BRP_ERR_CALLED_INVALID_FRAME;
	init_iv(iv10, 0x10, seq_ctr);
	if (! encrypt_frame(send_frm, enc_param_offset, session_key, iv10))
		return BRP_ERR_OUT_OF_MEMORY;

	// subsequently setting length of encrypted data
	enc_param_len = send_frm->act_size - enc_param_offset;
	send_frm->ptr[enc_param_len_offset] = (unsigned char) (enc_param_len >> 8);
	send_frm->ptr[enc_param_len_offset + 1] = (unsigned char) enc_param_len;

	// subsequently setting HMAC of encrypted data
	init_iv(iv20, 0x20, seq_ctr);
	aes_key_setup(session_key, key_schedule, AES_KEY_BITS);
	aes_encrypt_cbc_mac(
		send_frm->ptr + enc_param_offset,
		(int) (send_frm->act_size - enc_param_offset),
		send_frm->ptr + hmac_offset,
		key_schedule,
		AES_KEY_BITS,
		iv20);

	return brp_send_frame(protocol);
}


brp_errcode brp_pki_tunnel_recv_any_frame(
	brp_protocol protocol, brp_buf session_key, unsigned long seq_ctr,
	int cmd_code, brp_frame plain_rsp, brp_time timeout)
{
	aes_key_schedule key_schedule;
	unsigned char recv_hmac[AES_KEY_SIZE], act_hmac[AES_KEY_SIZE];
	unsigned char iv40[AES_BLOCK_SIZE], iv80[AES_BLOCK_SIZE];
	brp_frame_reader resp_frame_rdr;
	size_t enc_resp_len, plain_resp_len;
	unsigned status_byte;
	brp_errcode errcode;
	aes_key_setup(session_key, key_schedule, AES_KEY_BITS);

	errcode = brp_recv_any_frame(protocol, timeout);
	if (errcode != BRP_OK)
		return map_pki_errcode(errcode);

	brp_frame_read_start(&resp_frame_rdr, &protocol->recv_frame);
	brp_frame_read(&resp_frame_rdr, recv_hmac, AES_KEY_SIZE);
	enc_resp_len = brp_frame_read_int16(&resp_frame_rdr);

	init_iv(iv80, 0x80, seq_ctr);
	aes_encrypt_cbc_mac(resp_frame_rdr.ptr, (int) enc_resp_len, act_hmac,
		key_schedule, AES_KEY_BITS, iv80);
	if (memcmp(act_hmac, recv_hmac, AES_KEY_SIZE) != 0)
		return BRP_ERR_INVALID_HMAC;

	init_iv(iv40, 0x40, seq_ctr);
	aes_decrypt_cbc(resp_frame_rdr.ptr, (int) enc_resp_len, resp_frame_rdr.ptr,
		key_schedule, AES_KEY_BITS, iv40);

	status_byte = brp_frame_read_int8(&resp_frame_rdr);
	plain_resp_len = brp_frame_read_int16(&resp_frame_rdr);
	brp_frame_read_frm(&resp_frame_rdr, plain_rsp, plain_resp_len);
	if (brp_frame_write_err(plain_rsp) && !brp_frame_read_err(&resp_frame_rdr))
		return BRP_ERR_OUT_OF_MEMORY;

	if (brp_frame_read_err(&resp_frame_rdr))
		return BRP_ERR_CRYPTO_FORMAT;
	else
		while (! brp_frame_read_eof(&resp_frame_rdr))
		{
			int zero_byte;
			zero_byte = brp_frame_read_int8(&resp_frame_rdr);
			if (zero_byte != 0x00)
				return BRP_ERR_CRYPTO_FORMAT;
		}
	
	if (status_byte != 0x00)
		return BRP_ERR_STATUS(cmd_code, status_byte);

	return BRP_OK;
}


static brp_errcode open(pki_protocol protocol)
{
	unsigned char shared_secret[uECC_BYTES];
	brp_errcode errcode;
	errcode = brp_pki_pfs_gen_key(protocol->p.base_protocol, shared_secret);
	if (errcode != BRP_OK)
		return errcode;

	errcode = brp_pki_init_pfs_session(
		protocol->p.base_protocol,
		protocol->session_key,
		shared_secret,
		protocol->security_level,
		protocol->private_key,
		&protocol->dev_ca_cert_chain,
		&protocol->host_cert_chain,
		&protocol->dev_cert,
		protocol->session_timeout);
	if (errcode != BRP_OK)
		return errcode;

	protocol->seq_ctr = 0;
	return BRP_OK;
}


static brp_errcode close(pki_protocol protocol)
{
	memset(protocol->session_key, 0, AES_KEY_SIZE);
	return BRP_OK;
}


static brp_errcode send_frame(pki_protocol protocol)
{
	brp_errcode errcode;
	brp_frame_reader frame_rdr;
	brp_frame_read_start(&frame_rdr, &protocol->p.send_frame);
	brp_frame_skip(&frame_rdr, 1);   // mode
	protocol->last_cmd_code = brp_frame_read_int16(&frame_rdr);

	protocol->seq_ctr++;
	errcode = brp_pki_tunnel_send_frame(
		protocol->p.base_protocol,
		protocol->session_key,
		protocol->seq_ctr,
		&protocol->p.send_frame);
	return errcode;
}


static brp_errcode recv_any_frame(pki_protocol protocol, brp_time timeout)
{
	brp_errcode errcode = brp_pki_tunnel_recv_any_frame(
		protocol->p.base_protocol,
		protocol->session_key,
		protocol->seq_ctr,
		protocol->last_cmd_code,
		&protocol->p.recv_frame,
		timeout);
	return errcode;
}


static brp_errcode destroy(pki_protocol protocol)
{
	brp_frame_deinit(&protocol->dev_ca_cert_chain);
	brp_frame_deinit(&protocol->dev_cert);
	brp_frame_deinit(&protocol->host_cert_chain);
	memset(protocol->private_key, 0, PRIVATE_KEY_DERFMT_SIZE);
	brp_protocol_free(&protocol->p);
	return BRP_OK;
}


static void auto_decode(char * obj_name, brp_buf obj, size_t obj_len,
		brp_frame decoded_obj)
{
	struct brp_frame_t encoded_frm;
	size_t save_act_size = decoded_obj->act_size;
	
	brp_frame_init(&encoded_frm);
	brp_frame_write_start(&encoded_frm);
	brp_frame_write(&encoded_frm, obj, (unsigned) obj_len);
	if (brp_decode_base64_obj(obj_name, &encoded_frm, decoded_obj) != BRP_OK)
	{
		decoded_obj->act_size = save_act_size;
		brp_frame_write(decoded_obj, obj, obj_len);
	}
	brp_frame_deinit(&encoded_frm);
}


brp_protocol brp_create_pki(int security_level, brp_buf host_cert_chain,
	size_t host_cert_chain_len, brp_buf dev_ca_cert_chain,
	size_t dev_ca_cert_chain_len, brp_buf private_key, size_t private_key_len,
	brp_time session_timeout)
{
	pki_protocol protocol;
	brp_errcode add_host_certs_errcode, add_devca_certs_errcode;
	struct brp_frame_t private_key_frm;
	brp_frame_reader private_key_rdr;
	bool private_key_err;
	
	if (security_level < 1  ||  security_level > 3)
		return NULL;

	protocol = malloc(sizeof(struct pki_protocol_t));
	if (protocol == NULL)
		return NULL;
	
	memset(protocol, 0, sizeof(*protocol));
	protocol->p.protocol_id = BRP_PROTID_PKI;
	protocol->p.cb_open = (brp_cb_generic_t) open;
	protocol->p.cb_close = (brp_cb_generic_t) close;
	protocol->p.cb_send_frame = (brp_cb_generic_t) send_frame;
	protocol->p.cb_recv_any_frame = (brp_cb_recv_any_frame_t) recv_any_frame;
	protocol->p.cb_destroy = (brp_cb_generic_t) destroy;
	protocol->security_level = security_level;
	protocol->session_timeout = session_timeout;

	brp_frame_init(&protocol->p.recv_frame);
	brp_frame_init(&protocol->p.send_frame);
	
	brp_frame_init(&protocol->dev_cert);

	brp_frame_init(&private_key_frm);
	brp_frame_write_start(&private_key_frm);
	auto_decode("EC PRIVATE KEY",private_key,private_key_len,&private_key_frm);
	brp_frame_read_start(&private_key_rdr, &private_key_frm);
	brp_frame_read(&private_key_rdr, protocol->private_key,
			PRIVATE_KEY_DERFMT_SIZE);
	private_key_err = !brp_frame_read_eof(&private_key_rdr);
	brp_frame_deinit(&private_key_frm);

	brp_frame_init(&protocol->host_cert_chain);
	brp_frame_write_start(&protocol->host_cert_chain);
	add_host_certs_errcode = brp_append_host_certs(
			(brp_protocol)protocol, host_cert_chain, host_cert_chain_len);
	
	brp_frame_init(&protocol->dev_ca_cert_chain);
	brp_frame_write_start(&protocol->dev_ca_cert_chain);
	add_devca_certs_errcode = brp_append_dev_ca_certs(
			(brp_protocol)protocol, dev_ca_cert_chain, dev_ca_cert_chain_len);
	
	if (add_host_certs_errcode != BRP_OK  ||  add_devca_certs_errcode != BRP_OK
		||  private_key_err  ||  protocol->private_key[0] != ASN1_TAGID_SEQ)
	{
		destroy(protocol);
		return NULL;
	}

	return (brp_protocol) protocol;
}


brp_errcode brp_append_host_certs(
		brp_protocol protocol, brp_buf host_cert_chain,
		size_t host_cert_chain_len)
{
	pki_protocol pki_prot = (pki_protocol) require_protocol(
		protocol, BRP_PROTID_PKI, BRP_LAYERID_CRYPTO);
	if (pki_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;

	auto_decode("CERTIFICATE", host_cert_chain, host_cert_chain_len,
			&pki_prot->host_cert_chain);
	if (brp_frame_write_err(&pki_prot->host_cert_chain))
		return BRP_ERR_OUT_OF_MEMORY;
	return BRP_OK;
}


brp_errcode brp_append_dev_ca_certs(
	brp_protocol protocol, brp_buf dev_ca_cert_chain,
	size_t dev_ca_cert_chain_len)
{
	pki_protocol pki_prot = (pki_protocol) require_protocol(
		protocol, BRP_PROTID_PKI, BRP_LAYERID_CRYPTO);
	if (pki_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;

	auto_decode("CERTIFICATE", dev_ca_cert_chain, dev_ca_cert_chain_len,
			&pki_prot->dev_ca_cert_chain);
	if (brp_frame_write_err(&pki_prot->dev_ca_cert_chain))
		return BRP_ERR_OUT_OF_MEMORY;
	return BRP_OK;
}


brp_errcode brp_pki_save_session(
		brp_protocol protocol, brp_buf persistent_buf,
		size_t persistent_buf_size, size_t *persistent_buf_len)
{
	brp_frame_reader dev_cert_rdr;
	struct brp_frame_t frm;
	size_t local_persistent_buf_len;
	pki_protocol pki_prot = (pki_protocol) require_protocol(
		protocol, BRP_PROTID_PKI, BRP_LAYERID_CRYPTO);

	if (persistent_buf_len == NULL)
		persistent_buf_len = &local_persistent_buf_len;
	*persistent_buf_len = 0;
	if (pki_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;

	if (! protocol->opened)
		return BRP_ERR_INVALID_API_CALL;

	brp_frame_init(&frm);
	brp_frame_write_start(&frm);
	brp_frame_write_int32(&frm, (pki_prot)->seq_ctr);
	brp_frame_write(&frm, (pki_prot)->session_key, AES_KEY_SIZE);
	brp_frame_read_start(&dev_cert_rdr, &(pki_prot)->dev_cert);
	brp_frame_write_int16(&frm, (unsigned) brp_frame_rest(&dev_cert_rdr));
	brp_frame_write_frm_rest(&frm, &dev_cert_rdr);
	if (brp_frame_write_err(&frm))
	{
		brp_frame_deinit(&frm);
		return BRP_ERR_OUT_OF_MEMORY;
	}

	*persistent_buf_len = frm.act_size;
	memcpy(persistent_buf, frm.ptr, min(frm.act_size, persistent_buf_size));
	brp_frame_deinit(&frm);

	if (*persistent_buf_len > persistent_buf_size)
		return BRP_ERR_BUFFER_OVERFLOW;
	else
		return BRP_OK;
}


size_t brp_pki_get_session_buf_size(brp_protocol protocol)
{
	size_t buf_size;
	brp_errcode errcode = brp_pki_save_session(protocol, NULL, 0, &buf_size);
	return (errcode != BRP_ERR_BUFFER_OVERFLOW) ? 0 : buf_size;
}


brp_errcode brp_pki_restore_session(
		brp_protocol protocol, brp_buf persistent_buf,
		size_t persistent_buf_size)
{
	struct brp_frame_t frm;
	brp_frame_reader frm_rdr;
	size_t dev_cert_len;
	pki_protocol pki_prot = (pki_protocol) require_protocol(
		protocol, BRP_PROTID_PKI, BRP_LAYERID_CRYPTO);
	if (pki_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;

	// convert persistent_buf to a dummy frame, which can be read by frame_rdr
	frm.ptr = persistent_buf;
	frm.total_size = persistent_buf_size;
	frm.act_size = persistent_buf_size;

	brp_frame_read_start(&frm_rdr, &frm);
	pki_prot->seq_ctr = brp_frame_read_int32(&frm_rdr);
	brp_frame_read(&frm_rdr,
	               (pki_prot)->session_key, AES_KEY_SIZE);
	dev_cert_len = brp_frame_read_int16(&frm_rdr);
	brp_frame_read_frm(&frm_rdr, &(pki_prot)->dev_cert, dev_cert_len);
	if (brp_frame_write_err(&(pki_prot)->dev_cert)  &&
	    !brp_frame_read_err(&frm_rdr))
		return BRP_ERR_OUT_OF_MEMORY;
	if (! brp_frame_read_eof(&frm_rdr))
		return BRP_ERR_INVALID_API_CALL;

	pki_prot->p.opened = true;
	brp_open(protocol);

	return BRP_OK;
}


brp_errcode brp_pki_get_dev_cert(brp_protocol protocol, brp_buf dev_cert_buf,
								 size_t dev_cert_buf_size,
								 size_t *dev_cert_buf_len)
{
	brp_frame_reader dev_cert_rdr;
	size_t act_read_len;
	pki_protocol pki_prot = (pki_protocol) require_protocol(
		protocol, BRP_PROTID_PKI, BRP_LAYERID_CRYPTO);

	*dev_cert_buf_len = 0;

	if (pki_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;

	if (! protocol->opened)
		return BRP_ERR_CLOSED;

	brp_frame_read_start(&dev_cert_rdr, &pki_prot->dev_cert);
	*dev_cert_buf_len = brp_frame_rest(&dev_cert_rdr);
	brp_frame_read_var(&dev_cert_rdr, dev_cert_buf, dev_cert_buf_size,
	                   &act_read_len);
	if (act_read_len < (size_t) *dev_cert_buf_len)
		return BRP_ERR_BUFFER_OVERFLOW;

	return BRP_OK;
}
