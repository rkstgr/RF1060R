/**
 * @file
 * @anchor UlRdr
 * Encryption Commands for Rijkspas Readers.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ULRDR_H__
#define __BRP_BALTECH_API_CMDS_ULRDR_H__
#include "../typedefs.h"
/**
 * @anchor UlRdr_ErrResponse
 * Response received from reader is unexpected.
 */
#define BRP_UlRdr_ErrResponse BRP_ERR_STATUS(0xA500, 0x01)
/**
 * @anchor UlRdr_ErrSequence
 * Command sequence was not kept.
 */
#define BRP_UlRdr_ErrSequence BRP_ERR_STATUS(0xA500, 0x02)
/**
 * @anchor UlRdr_ErrSignature
 * Signature of SEND_ENCRYPTED is invalid.
 */
#define BRP_UlRdr_ErrSignature BRP_ERR_STATUS(0xA500, 0x03)
/**
 * @anchor UlRdr_SendAuth1
 * Retrieves the command that has to be sent to the reader to unlock, to initiate
 * authentication.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] SendDevCode Device Code to send.
 * @param[out] SendCmdCode Command Code to send.
 * @param[out] SendParams Params to send.
 * @param[out] SendParams_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_UlRdr_SendAuth1(brp_protocol protocol, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool);
/**
 * @anchor UlRdr_RecvAuth1
 * Passes the response of the reader to unlock.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RecvStatus Received StatusCode.
 * @param[in] RecvResult Received Result.
 * @param[in] RecvResult_len 
 */
brp_errcode brp_UlRdr_RecvAuth1(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len);
/**
 * @anchor UlRdr_SendAuth2
 * Retrieves the command that has to be send to the reader to unlock, to continue
 * authentication.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] SendDevCode Device Code to send.
 * @param[out] SendCmdCode Command Code to send.
 * @param[out] SendParams Params to send.
 * @param[out] SendParams_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_UlRdr_SendAuth2(brp_protocol protocol, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool);
/**
 * @anchor UlRdr_RecvAuth2
 * Passes the response of the reader to unlock.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RecvStatus Received StatusCode.
 * @param[in] RecvResult Received Result.
 * @param[in] RecvResult_len 
 */
brp_errcode brp_UlRdr_RecvAuth2(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len);
/**
 * @anchor UlRdr_SendEncryptedCmd
 * Encrypts the given command with the session key generated in the previous
 * 3-pass-authentication. Before doing so, the signature is checked.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Signature Signature of the following command.
 * @param[in] DevCode Device Code of the command to encrypt.
 * @param[in] CmdCode Command Code of the command to encrypt.
 * @param[in] Params Params of the command to encrypt.
 * @param[in] Params_len 
 * @param[out] SendDevCode Device Code to send.
 * @param[out] SendCmdCode Command Code to send.
 * @param[out] SendParams Params to send.
 * @param[out] SendParams_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_UlRdr_SendEncryptedCmd(brp_protocol protocol, brp_buf Signature, unsigned DevCode, unsigned CmdCode, brp_buf Params, size_t Params_len, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool);
/**
 * @anchor UlRdr_RecvEncryptedCmd
 * Check the response received by the command
 * [UlRdr.SendEncryptedCmd](@ref UlRdr_SendEncryptedCmd).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RecvStatus Received StatusCode.
 * @param[in] RecvResult Received Result.
 * @param[in] RecvResult_len 
 * @param[out] Status Decrypted status code.
 */
brp_errcode brp_UlRdr_RecvEncryptedCmd(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len, unsigned* Status);
#endif
/**
 * @}
 */
