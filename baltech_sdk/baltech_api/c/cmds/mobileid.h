/**
 * @file
 * @anchor MobileId
 * With this command group, you can set up the Mobile ID functionality to read
 * virtual credentials from smartphones.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_MOBILEID_H__
#define __BRP_BALTECH_API_CMDS_MOBILEID_H__
#include "../typedefs.h"
/**
 * @anchor MobileId_ErrNoCredential
 * No valid credential has been presented to the reader so far.
 */
#define BRP_MobileId_ErrNoCredential BRP_ERR_STATUS(0x4C00, 0x01)
/**
 * @anchor MobileId_ErrProtocol
 * The credential is trying to perform an action that doesn't comply with the
 * BALTECH Mobile ID protocol. (For details, please refer to the protocol
 * specification, available on request.)
 */
#define BRP_MobileId_ErrProtocol BRP_ERR_STATUS(0x4C00, 0x02)
/**
 * @anchor MobileId_ErrAuthentication
 * An authentication error occured, e.g. invalid encryption key or authentication
 * tag.
 */
#define BRP_MobileId_ErrAuthentication BRP_ERR_STATUS(0x4C00, 0x03)
/**
 * @anchor MobileId_ErrCredentialVersion
 * The version of the presented credential is not compatible with the current
 * reader firmware.
 */
#define BRP_MobileId_ErrCredentialVersion BRP_ERR_STATUS(0x4C00, 0x04)
/**
 * @anchor MobileId_ErrCredentialCmac
 * The presented credential is rejected due to an invalid CMAC.
 */
#define BRP_MobileId_ErrCredentialCmac BRP_ERR_STATUS(0x4C00, 0x05)
/**
 * @anchor MobileId_Enable
 * This command enables/disables Mobile ID.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode 
 */
brp_errcode brp_MobileId_Enable(brp_protocol protocol, brp_MobileId_Enable_Mode Mode);
/**
 * @anchor MobileId_Setup
 * This command is used to set up Mobile ID parameters.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Key Encryption key
 * @param[in] Key_len 
 */
brp_errcode brp_MobileId_Setup(brp_protocol protocol, brp_buf Key, size_t Key_len);
/**
 * @anchor MobileId_GetVirtualCredentialId
 * This command checks if a Mobile ID credential has been presented to the reader
 * since the last _MobileId.GetVirtualCredentialId_ execution.
 * 
 *   * If a valid credential is detected, the credential identification will be returned in _CredentialId_. 
 *   * If no credential is detected, the [MobileId.ErrNoCredential](@ref MobileId_ErrNoCredential) status code will be returned. 
 *   * If an invalid credential is detected, one of the other status codes will be returned. 
 * 
 * **If you use Autoread, run[ AR.GetMessage](@ref AR_GetMessage)
 * instead of this command to retrieve the ID of a presented credential.**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] CredentialId ASCII-encoded value containing the credential ID
 * @param[out] CredentialId_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_MobileId_GetVirtualCredentialId(brp_protocol protocol, brp_buf* CredentialId, size_t* CredentialId_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
