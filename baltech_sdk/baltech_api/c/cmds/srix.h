/**
 * @file
 * @anchor Srix
 * Srix card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_SRIX_H__
#define __BRP_BALTECH_API_CMDS_SRIX_H__
#include "../typedefs.h"
/**
 * @anchor Srix_ErrNoTag
 * No Tag
 */
#define BRP_Srix_ErrNoTag BRP_ERR_STATUS(0x2400, 0x01)
/**
 * @anchor Srix_ErrFrame
 * Frame Error (CRC, parity...)
 */
#define BRP_Srix_ErrFrame BRP_ERR_STATUS(0x2400, 0x03)
/**
 * @anchor Srix_ErrHf
 * General hf error
 */
#define BRP_Srix_ErrHf BRP_ERR_STATUS(0x2400, 0x04)
/**
 * @anchor Srix_ErrCom
 * Hardware error
 */
#define BRP_Srix_ErrCom BRP_ERR_STATUS(0x2400, 0x05)
/**
 * @anchor Srix_ErrSrixCardtypeNotSupported
 * Chip type not supported by reader chip
 */
#define BRP_Srix_ErrSrixCardtypeNotSupported BRP_ERR_STATUS(0x2400, 0x06)
/**
 * @anchor Srix_ErrHwNotSupported
 * Hardware does not support reader chip
 */
#define BRP_Srix_ErrHwNotSupported BRP_ERR_STATUS(0x2400, 0x07)
/**
 * @anchor Srix_ErrCmdBreak
 * Command has been interrupted
 */
#define BRP_Srix_ErrCmdBreak BRP_ERR_STATUS(0x2400, 0x08)
/**
 * @anchor Srix_Select
 * This command selects a label including anticollision.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Snr Serial number of selected label
 * @param[out] Snr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Srix_Select(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool);
/**
 * @anchor Srix_Read
 * This command reads a secure data page
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Page Address
 * @param[out] Data Data block
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Srix_Read(brp_protocol protocol, unsigned Adr, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor Srix_Write
 * This command writes data to a page address of a label.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Page Address of block to write
 * @param[in] Data Len of value counter / data block
 * @param[in] Data_len 
 */
brp_errcode brp_Srix_Write(brp_protocol protocol, unsigned Adr, brp_buf Data, size_t Data_len);
#endif
/**
 * @}
 */
