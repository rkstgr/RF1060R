/**
 * @file
 * @anchor Hitag
 * This are Hitag 125 kHz card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_HITAG_H__
#define __BRP_BALTECH_API_CMDS_HITAG_H__
#include "../typedefs.h"
/**
 * @anchor Hitag_ErrHtgNoTag
 * No tag error.
 */
#define BRP_Hitag_ErrHtgNoTag BRP_ERR_STATUS(0x3000, 0x01)
/**
 * @anchor Hitag_ErrHtgCollision
 * Collision occurred.
 */
#define BRP_Hitag_ErrHtgCollision BRP_ERR_STATUS(0x3000, 0x02)
/**
 * @anchor Hitag_ErrHtgRxdata
 * Wrong length or wrong data.
 */
#define BRP_Hitag_ErrHtgRxdata BRP_ERR_STATUS(0x3000, 0x03)
/**
 * @anchor Hitag_HtgChecksum
 * Receive checksum error.
 */
#define BRP_Hitag_HtgChecksum BRP_ERR_STATUS(0x3000, 0x04)
/**
 * @anchor Hitag_HtgWrongParam
 * Wrong command parameter.
 */
#define BRP_Hitag_HtgWrongParam BRP_ERR_STATUS(0x3000, 0x07)
/**
 * @anchor Hitag_ErrHtgAuth
 * Authentication error.
 */
#define BRP_Hitag_ErrHtgAuth BRP_ERR_STATUS(0x3000, 0x09)
/**
 * @anchor Hitag_ErrHtgOvTo
 * ISR buffer overflow during send/receive, TO during send.
 */
#define BRP_Hitag_ErrHtgOvTo BRP_ERR_STATUS(0x3000, 0x08)
/**
 * @anchor Hitag_ErrHtgHw
 * Reader chip HW error.
 */
#define BRP_Hitag_ErrHtgHw BRP_ERR_STATUS(0x3000, 0x0A)
/**
 * @anchor Hitag_ErrHtgCr
 * Crypt processor HW error.
 */
#define BRP_Hitag_ErrHtgCr BRP_ERR_STATUS(0x3000, 0x0B)
/**
 * @anchor Hitag_ErrHtgCfg
 * Update of configuration not successful.
 */
#define BRP_Hitag_ErrHtgCfg BRP_ERR_STATUS(0x3000, 0x0C)
/**
 * @anchor Hitag_ErrHtgHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_Hitag_ErrHtgHfreqctrl BRP_ERR_STATUS(0x3000, 0x0D)
/**
 * @anchor Hitag_ErrHtgHwNotSupported
 * Hardware not supported.
 */
#define BRP_Hitag_ErrHtgHwNotSupported BRP_ERR_STATUS(0x3000, 0x0F)
/**
 * @anchor Hitag_Request
 * Request and AC / according to Mode byte you can request Hitag-1 and Hitag-S
 * tags.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] TagType 
 * @param[in] Mode 
 * @param[out] Snr Serial Number of selected label.
 */
brp_errcode brp_Hitag_Request(brp_protocol protocol, brp_Hitag_Request_TagType TagType, brp_Hitag_Request_Mode Mode, unsigned* Snr);
/**
 * @anchor Hitag_Select
 * Selects a Hitag-1 or Hitag-S tag and returns page 1.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SelMode 
 * @param[in] Pwd Password for Hitag2.
 * @param[out] Page1 Page 1 (CON and (PWDH0)).
 */
brp_errcode brp_Hitag_Select(brp_protocol protocol, brp_Hitag_Select_SelMode SelMode, unsigned Pwd, unsigned* Page1);
/**
 * @anchor Hitag_Halt
 * Sets a Hitag1/S label in halt mode.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Hitag_Halt(brp_protocol protocol);
/**
 * @anchor Hitag_Read
 * Reads a Hitag1/S label.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[in] InvRead B3 = 1: for Hitag2: Inverted read, result is returned not inverted.
 * @param[in] KeyB B2 = 1: for Hitag1: KeyB will be used for authentification.
 * @param[in] Encrypt B1 = 1: for Hitag1: block will be read encrypted.
 * @param[in] BlockRead B0 = 1: block(up to 4 pages) will be read instead of a single block.
 * @param[out] PageNr 
 * @param[out] PageNr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Hitag_Read(brp_protocol protocol, unsigned Address, bool InvRead, bool KeyB, bool Encrypt, bool BlockRead, unsigned** PageNr, size_t* PageNr_len, brp_mempool *mempool);
/**
 * @anchor Hitag_Write
 * Writes data to a Hitag1/S label.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[in] KeyB B2 = 1: for Hitag1: KeyB will be used for authentification.
 * @param[in] Encrypt B1 = 1: for Hitag1: block will be read encrypted.
 * @param[in] BlockWrite B0 = 1: block(up to 4 pages) will be read instead of a single block.
 * @param[in] PageNr 
 * @param[in] PageNr_len 
 */
brp_errcode brp_Hitag_Write(brp_protocol protocol, unsigned Address, bool KeyB, bool Encrypt, bool BlockWrite, unsigned* PageNr, size_t PageNr_len);
/**
 * @anchor Hitag_PersonaliseHtg
 * Writes personalization data for Hitag1/2 to coprocessor.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Reset B1=True: reset Htg1/2/S personalization values to 0xFF.
 * @param[in] HtgS B0=True: Personalize HtgS (3 words) instead of Htg1/2 (9 words).
 * @param[in] Len 
 * @param[in] Len_len 
 */
brp_errcode brp_Hitag_PersonaliseHtg(brp_protocol protocol, bool Reset, bool HtgS, unsigned* Len, size_t Len_len);
#endif
/**
 * @}
 */
