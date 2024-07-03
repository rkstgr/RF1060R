/**
 * @file
 * This module is about decoding BASE64 encoded objects.
 *
 * As most PKI objects are usually stored BASE64 encoded ASN.1-DER strings
 * they have to be decoded before being processed. This includes
 * certificates (file format .crt and .pem) as well as keys (file format .key)
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */

#ifndef BRP_LIB_BASE64_H
#define BRP_LIB_BASE64_H


#include "frames.h"
#include "errorcodes.h"


/**
 * This function decodes any BASE64-encoded frame and stores the decoded data
 * in "decoded_frm"
 */
BRP_LIB brp_errcode brp_decode_base64_obj
(
	char * obj_name,        ///< Name of BASE64 object
	                        ///< (contained in header, surrounded by '---'s)
	brp_frame encoded_frm,  ///< encoded frame
	brp_frame decoded_frm   ///< decoded frame
);


#endif //BRP_LIB_BASE64_H

/** @} */ // end of defgroup brp_lib
