/**
 * @file
 * @anchor QKey
 * These are the Quadrakey 125kHz card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_QKEY_H__
#define __BRP_BALTECH_API_CMDS_QKEY_H__
#include "../typedefs.h"
/**
 * @anchor QKey_ErrQkeyNoTag
 * No tag error.
 */
#define BRP_QKey_ErrQkeyNoTag BRP_ERR_STATUS(0x3500, 0x01)
/**
 * @anchor QKey_ErrQkeyRxdata
 * Wrong length or wrong data.
 */
#define BRP_QKey_ErrQkeyRxdata BRP_ERR_STATUS(0x3500, 0x03)
/**
 * @anchor QKey_ErrQkeyParity
 * Parity error.
 */
#define BRP_QKey_ErrQkeyParity BRP_ERR_STATUS(0x3500, 0x05)
/**
 * @anchor QKey_ErrQkeyParam
 * Wrong command param (on HF).
 */
#define BRP_QKey_ErrQkeyParam BRP_ERR_STATUS(0x3500, 0x07)
/**
 * @anchor QKey_ErrQkeyHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_QKey_ErrQkeyHfreqctrl BRP_ERR_STATUS(0x3500, 0x08)
/**
 * @anchor QKey_ErrQkeyHw
 * Missing Platform ID or Readerchip error.
 */
#define BRP_QKey_ErrQkeyHw BRP_ERR_STATUS(0x3500, 0x09)
/**
 * @anchor QKey_ErrQkeyHwNotSupported
 * Hardware not supported.
 */
#define BRP_QKey_ErrQkeyHwNotSupported BRP_ERR_STATUS(0x3500, 0x0B)
/**
 * @anchor QKey_Read
 * Returns data of quadrakey tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Quadrakey data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_QKey_Read(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
