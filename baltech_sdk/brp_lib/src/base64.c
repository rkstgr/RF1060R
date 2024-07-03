#include "brp_lib/base64.h"

#include <ctype.h>

static bool convert_chr_b64(char in_chr, char *out_chr_ptr)
{
	static const char reverse_b64_map[] =
	    "|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\]^"
	    "_`abcdefghijklmnopq";
	char conv_chr;
	
	if (in_chr < 43 || in_chr > 122)
		return false;
	conv_chr = reverse_b64_map[in_chr - 43];
	if (conv_chr == '$')
		return false;
	if (out_chr_ptr)
		*out_chr_ptr = (char) (conv_chr - 62);
	
	return true;
}

static bool base64_decode(brp_frame_reader * encoded_rdr, brp_frame decoded_frm)
{
	int ndx;
	int end_ndx = -1;
	do
	{
		char payload[4] = { 0, 0, 0, 0};
		for (ndx = 0; ndx < 4; ndx++)
		{
			int chr;
			while (true)
			{
				chr = brp_frame_read_int8(encoded_rdr);
				if (brp_frame_read_err(&*encoded_rdr))
					return ndx == 0;
				else if (isspace(chr))
					;
				else if (chr == '=')
				{
					if (end_ndx == -1)
						end_ndx = ndx;
					break;
				}
				else if (end_ndx != -1)
				{
					brp_frame_unread(encoded_rdr, sizeof(char));
					return false;
				}
				else if (convert_chr_b64((char)chr, payload + ndx))
					break;
				else
				{
					brp_frame_unread(encoded_rdr, sizeof(char));
					return ndx == 0;
				}
			}
		}
		
		if (end_ndx == 1)
		{
			brp_frame_unread(encoded_rdr, sizeof(char));
			return false;
		}
		
		if (end_ndx == -1 || end_ndx >= 2)
			brp_frame_write_int8(decoded_frm,
			                     ((payload[0]<<2) | (payload[1]>>4)));
		if (end_ndx == -1 || end_ndx >= 3)
			brp_frame_write_int8(decoded_frm,
			                     ((payload[1]<<4) | (payload[2]>>2)));
		if (end_ndx == -1 || end_ndx == 4)
			brp_frame_write_int8(decoded_frm,
			                     ((payload[2]<<6) | payload[3]));
	}
	while (end_ndx == -1);
	return true;
}


static bool skip_minus_bar(brp_frame_reader * rdr)
{
	bool min_1_detected = false;
	do
	{
		int val;
		val = brp_frame_read_int8(rdr);
		if (brp_frame_read_err(rdr)  ||  val != '-')
		{
			brp_frame_unread(rdr, sizeof(char));
			return min_1_detected;
		}
		min_1_detected = true;
	}
	while (! brp_frame_read_eof(&*rdr));
	return true;
}


static void skip_spaces(brp_frame_reader * rdr)
{
	while (! brp_frame_read_eof(&*rdr))
	{
		int val;
		val = brp_frame_read_int8(rdr);
		if (brp_frame_read_err(&*rdr)  ||  !isspace(val))
		{
			brp_frame_unread(rdr, sizeof(char));
			return;
		}
	}
}


static bool skip_str(brp_frame_reader * rdr, const char * str)
{
	int val;
	while (*str != '\0')
	{
		val = brp_frame_read_int8(rdr);
		if (brp_frame_read_err(&*rdr) || val != *str)
			return false;
		str++;
	}
	return true;
}


brp_errcode brp_decode_base64_obj(
	char * obj_name, brp_frame encoded_frm, brp_frame decoded_frm)
{
	bool ok = true;
	brp_frame_reader encoded_rdr;
	brp_frame_read_start(&encoded_rdr, encoded_frm);

	skip_spaces(&encoded_rdr);
	if (ok) ok = skip_minus_bar(&encoded_rdr);
	if (ok) ok = skip_str(&encoded_rdr, "BEGIN ");
	if (ok) ok = skip_str(&encoded_rdr, obj_name);
	if (ok) ok = skip_minus_bar(&encoded_rdr);
	if (ok) ok = base64_decode(&encoded_rdr, decoded_frm);
	skip_spaces(&encoded_rdr);
	if (ok) ok = skip_minus_bar(&encoded_rdr);
	if (ok) ok = skip_str(&encoded_rdr, "END ");
	if (ok) ok = skip_str(&encoded_rdr, obj_name);
	if (ok) ok = skip_minus_bar(&encoded_rdr);
	skip_spaces(&encoded_rdr);

	return ok && brp_frame_read_eof(&encoded_rdr)
	       ? BRP_OK : BRP_ERR_INVALID_API_CALL;
}
