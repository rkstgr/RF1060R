/**
 * @file
 * @anchor ASK
 * This are ASK 125kHz card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ASK_H__
#define __BRP_BALTECH_API_CMDS_ASK_H__
#include "../typedefs.h"
/**
 * @anchor ASK_ErrAskNoTag
 * No Tag.
 */
#define BRP_ASK_ErrAskNoTag BRP_ERR_STATUS(0x3600, 0x01)
/**
 * @anchor ASK_ErrAskRxdata
 * Wrong length or wrong data.
 */
#define BRP_ASK_ErrAskRxdata BRP_ERR_STATUS(0x3600, 0x03)
/**
 * @anchor ASK_ErrAskParity
 * Parity error.
 */
#define BRP_ASK_ErrAskParity BRP_ERR_STATUS(0x3600, 0x05)
/**
 * @anchor ASK_ErrAskParam
 * Wrong command param (on HF).
 */
#define BRP_ASK_ErrAskParam BRP_ERR_STATUS(0x3600, 0x07)
/**
 * @anchor ASK_ErrAskHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_ASK_ErrAskHfreqctrl BRP_ERR_STATUS(0x3600, 0x08)
/**
 * @anchor ASK_ErrAskHw
 * Missing Platform ID or Readerchip error.
 */
#define BRP_ASK_ErrAskHw BRP_ERR_STATUS(0x3600, 0x09)
/**
 * @anchor ASK_ErrAskHwNotSupported
 * Hardware not supported.
 */
#define BRP_ASK_ErrAskHwNotSupported BRP_ERR_STATUS(0x3600, 0x0B)
/**
 * @anchor ASK_SecuraKeyRead
 * Returns data of SecuraKey tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data SecuraKey data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_ASK_SecuraKeyRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor ASK_GproxRead
 * Returns data of G-Prox tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data G-Prox data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_ASK_GproxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor ASK_CotagRead
 * Returns data of Cotag tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Cotag data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_ASK_CotagRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
