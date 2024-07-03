/**
 * @file
 * @anchor EM
 * These are EM-marin 125 kHz card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_EM_H__
#define __BRP_BALTECH_API_CMDS_EM_H__
#include "../typedefs.h"
/**
 * @anchor EM_ErrEmNoTag
 * No tag error.
 */
#define BRP_EM_ErrEmNoTag BRP_ERR_STATUS(0x3100, 0x01)
/**
 * @anchor EM_ErrEmRxdata
 * Wrong length or wrong data.
 */
#define BRP_EM_ErrEmRxdata BRP_ERR_STATUS(0x3100, 0x03)
/**
 * @anchor EM_ErrEmChecksum
 * Receive checksum error.
 */
#define BRP_EM_ErrEmChecksum BRP_ERR_STATUS(0x3100, 0x04)
/**
 * @anchor EM_ErrEmParity
 * Receive parity error.
 */
#define BRP_EM_ErrEmParity BRP_ERR_STATUS(0x3100, 0x05)
/**
 * @anchor EM_EmCmdError
 * Error detected during command execution.
 */
#define BRP_EM_EmCmdError BRP_ERR_STATUS(0x3100, 0x06)
/**
 * @anchor EM_EmTagtypeNotDetected
 * Unknown tag type or modulation not detected.
 */
#define BRP_EM_EmTagtypeNotDetected BRP_ERR_STATUS(0x3100, 0x07)
/**
 * @anchor EM_ErrEmOvTo
 * ISR buffer overflow during send/receive, TO during send.
 */
#define BRP_EM_ErrEmOvTo BRP_ERR_STATUS(0x3100, 0x08)
/**
 * @anchor EM_EmParamError
 * Host command parameter error.
 */
#define BRP_EM_EmParamError BRP_ERR_STATUS(0x3100, 0x09)
/**
 * @anchor EM_ErrEmHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_EM_ErrEmHfreqctrl BRP_ERR_STATUS(0x3100, 0x0A)
/**
 * @anchor EM_ErrEmHw
 * Missing Platform ID or Readerchip error.
 */
#define BRP_EM_ErrEmHw BRP_ERR_STATUS(0x3100, 0x0B)
/**
 * @anchor EM_ErrEmHwNotSupported
 * Hardware not supported.
 */
#define BRP_EM_ErrEmHwNotSupported BRP_ERR_STATUS(0x3100, 0x0D)
/**
 * @anchor EM_DecodeCfg
 * Configures Mod and Baudtype of receiver. When _RxMod_ is set to _unknown_ ,
 * the Mod is automatically scanned. When _RxBaud_ is set to _unknown_ , the
 * baudtype is automatically detected.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RxMod 
 * @param[in] RxBaud 0:unknown; 0x08..0x40:fc*x
 */
brp_errcode brp_EM_DecodeCfg(brp_protocol protocol, brp_EM_DecodeCfg_RxMod RxMod, unsigned RxBaud);
/**
 * @anchor EM_Read4100
 * Reads the UID from EM4100/4102 labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data 40 bits data of TTF tag.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_EM_Read4100(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor EM_Read4205
 * Reads a page from EM4205/4305 labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[out] Page Page of a label.
 */
brp_errcode brp_EM_Read4205(brp_protocol protocol, unsigned Address, unsigned* Page);
/**
 * @anchor EM_Write4205
 * Writes a page to EM4205/4305 labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[in] Page Page of a label.
 */
brp_errcode brp_EM_Write4205(brp_protocol protocol, unsigned Address, unsigned Page);
/**
 * @anchor EM_Halt4205
 * Disables a 4205 tag until next power on.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_EM_Halt4205(brp_protocol protocol);
/**
 * @anchor EM_Login4205
 * Login to a 4205 tag with data has to match block 1.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Password Password.
 */
brp_errcode brp_EM_Login4205(brp_protocol protocol, unsigned Password);
/**
 * @anchor EM_Protect4205
 * Protects data from being modified.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ProtectMask Bit mask of pages to protect.
 */
brp_errcode brp_EM_Protect4205(brp_protocol protocol, unsigned ProtectMask);
/**
 * @anchor EM_Read4469
 * Reads a page from EM4469/4569 labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[out] Page Page of a label.
 */
brp_errcode brp_EM_Read4469(brp_protocol protocol, unsigned Address, unsigned* Page);
/**
 * @anchor EM_Write4469
 * Writes a page to EM4469/4569 labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Page address of a label.
 * @param[in] Page Page of a label.
 */
brp_errcode brp_EM_Write4469(brp_protocol protocol, unsigned Address, unsigned Page);
/**
 * @anchor EM_Halt4469
 * Disables a EM4469/4569 tag until next power on.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_EM_Halt4469(brp_protocol protocol);
/**
 * @anchor EM_Login4469
 * Login to a EM4469/4569 tag with data has to match block 1.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Password Password.
 */
brp_errcode brp_EM_Login4469(brp_protocol protocol, unsigned Password);
/**
 * @anchor EM_Read4450
 * Reads pages from a EM4450 tag (start to end address).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Start page address of a label.
 * @param[in] EndAdr End page address of a label.
 * @param[out] PageNr 
 * @param[out] PageNr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_EM_Read4450(brp_protocol protocol, unsigned StartAdr, unsigned EndAdr, unsigned** PageNr, size_t* PageNr_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
