/**
 * @file
 * @anchor Ultralight
 * With this command group, you can access MIFARE Ultralight cards in low-level
 * mode. To work with this command group, a card has to be in ISO 14443-3 Type A
 * selected state. This can be achieved using the [Iso14a command
 * group](@ref Iso14a).
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ULTRALIGHT_H__
#define __BRP_BALTECH_API_CMDS_ULTRALIGHT_H__
#include "../typedefs.h"
/**
 * @anchor Ultralight_ErrNoTag
 * There's no card in the HF field, or the card doesn't respond.
 */
#define BRP_Ultralight_ErrNoTag BRP_ERR_STATUS(0x2500, 0x01)
/**
 * @anchor Ultralight_ErrAuth
 * Authentication with the card has failed.
 */
#define BRP_Ultralight_ErrAuth BRP_ERR_STATUS(0x2500, 0x02)
/**
 * @anchor Ultralight_ErrHf
 * The response frame is invalid, e.g. it may contain an invalid number of bits
 * or an invalid CRC checksum. Please rerun the command.
 */
#define BRP_Ultralight_ErrHf BRP_ERR_STATUS(0x2500, 0x03)
/**
 * @anchor Ultralight_ErrKey
 * The encryption key is undefined or inaccessible.
 */
#define BRP_Ultralight_ErrKey BRP_ERR_STATUS(0x2500, 0x04)
/**
 * @anchor Ultralight_ErrNack
 * The card didn't accept the command. Please check the conditions and rerun the
 * command.
 */
#define BRP_Ultralight_ErrNack BRP_ERR_STATUS(0x2500, 0x05)
/**
 * @anchor Ultralight_ErrInterface
 * Communication with the reader chip has failed. Please reset the reader with
 * [Sys.Reset](@ref Sys_Reset) and check the reader chip status with
 * [Sys.GetBootStatus](@ref Sys_GetBootStatus).
 */
#define BRP_Ultralight_ErrInterface BRP_ERR_STATUS(0x2500, 0x18)
/**
 * @anchor Ultralight_ErrCmd
 * The specified command or parameters are unknown.
 */
#define BRP_Ultralight_ErrCmd BRP_ERR_STATUS(0x2500, 0x19)
/**
 * @anchor Ultralight_ErrHwNotSupported
 * This command isn't supported by the reader hardware.
 */
#define BRP_Ultralight_ErrHwNotSupported BRP_ERR_STATUS(0x2500, 0x20)
/**
 * @anchor Ultralight_ErrFirmwareNotSupported
 * This command isn't supported by the reader firmware.
 */
#define BRP_Ultralight_ErrFirmwareNotSupported BRP_ERR_STATUS(0x2500, 0x21)
/**
 * @anchor Ultralight_BreakErr
 * The command has been aborted because the HF interface has been requested by
 * another task or command. Please reselect the card.
 * 
 * **This error only occurs when you combine VHL and low-level commands. We
 * highly recommend you avoid that combination as these 2 command sets will
 * interfere with each other's card states.**
 */
#define BRP_Ultralight_BreakErr BRP_ERR_STATUS(0x2500, 0x28)
/**
 * @anchor Ultralight_ExecCmd
 * Generic command to communicate to a Mifare Ultralight card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Cmd Ultralight command code.
 * @param[in] Param Command paramter.
 * @param[in] Param_len 
 * @param[out] Response Command response.
 * @param[out] Response_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Ultralight_ExecCmd(brp_protocol protocol, unsigned Cmd, brp_buf Param, size_t Param_len, brp_buf* Response, size_t* Response_len, brp_mempool *mempool);
/**
 * @anchor Ultralight_Read
 * Standard read command for Ultralight cards. Command returns 4 pages of a card
 * (16 byte).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageAdr Page address
 * @param[out] PageData Returns content of 4 pages.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Ultralight_Read(brp_protocol protocol, unsigned PageAdr, brp_buf* PageData, brp_mempool *mempool);
/**
 * @anchor Ultralight_Write
 * Standard write command for Ultralight cards. 1 page (4 bytes) is writen to a
 * card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageAdr Page address
 * @param[in] PageData 4 byte page data.
 */
brp_errcode brp_Ultralight_Write(brp_protocol protocol, unsigned PageAdr, brp_buf PageData);
/**
 * @anchor Ultralight_AuthE2
 * Authenticates to a Ultralight-c card.
 * 
 * The key used for authentication is specified in the __Device /
 * CryptoKey__ key of the reader's
 * configuration. Key has to be of type 3DES (16 bytes).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DivMode Specifies diversification algorithm.
 * @param[in] HasExtIdx 
 * @param[in] KeyIdx Index
 * @param[in] DivData Diversification data.
 * @param[in] DivData_len 
 * @param[in] KeyExtIdx Crypto memory index (SAM or crypto memory) of authentication key    * SAM: key version (0..0xFF)    * Crypto memory: page (0..15)
 */
brp_errcode brp_Ultralight_AuthE2(brp_protocol protocol, brp_Ultralight_AuthE2_DivMode DivMode, bool HasExtIdx, unsigned KeyIdx, brp_buf DivData, size_t DivData_len, unsigned KeyExtIdx);
/**
 * @anchor Ultralight_AuthUser
 * Authenticates to an Ultralight-C/EV1 card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CryptoMode Sets the encryption algorithm.
 * @param[in] Key Authentication key
 * @param[in] Key_len 
 */
brp_errcode brp_Ultralight_AuthUser(brp_protocol protocol, brp_Ultralight_AuthUser_CryptoMode CryptoMode, brp_buf Key, size_t Key_len);
#endif
/**
 * @}
 */
