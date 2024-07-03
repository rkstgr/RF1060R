/**
 * @file
 * @anchor HID
 * This are HID 125kHz card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_HID_H__
#define __BRP_BALTECH_API_CMDS_HID_H__
#include "../typedefs.h"
/**
 * @anchor HID_ErrHidNoTag
 * No tag error.
 */
#define BRP_HID_ErrHidNoTag BRP_ERR_STATUS(0x3300, 0x01)
/**
 * @anchor HID_ErrHidRxdata
 * Wrong length or wrong data.
 */
#define BRP_HID_ErrHidRxdata BRP_ERR_STATUS(0x3300, 0x03)
/**
 * @anchor HID_ErrHidParity
 * Parity error.
 */
#define BRP_HID_ErrHidParity BRP_ERR_STATUS(0x3300, 0x05)
/**
 * @anchor HID_ErrHidParam
 * Wrong command param (on HF).
 */
#define BRP_HID_ErrHidParam BRP_ERR_STATUS(0x3300, 0x07)
/**
 * @anchor HID_ErrHidHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_HID_ErrHidHfreqctrl BRP_ERR_STATUS(0x3300, 0x08)
/**
 * @anchor HID_ErrHidHw
 * Reader chip hardware error.
 */
#define BRP_HID_ErrHidHw BRP_ERR_STATUS(0x3300, 0x09)
/**
 * @anchor HID_ErrHidHwNotSupported
 * Hardware not supported.
 */
#define BRP_HID_ErrHidHwNotSupported BRP_ERR_STATUS(0x3300, 0x0B)
/**
 * @anchor HID_ErrLicense
 * You use an HID Prox/Indala/Keri card, but the reader doesn't have the
 * [required Prox license](https://docs.baltech.de/project-setup/get-prox-
 * license-for-hid-prox-indala-keri.html).
 */
#define BRP_HID_ErrLicense BRP_ERR_STATUS(0x3300, 0x0C)
/**
 * @anchor HID_IndalaRead
 * Returns data of Indala tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Indala data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_IndalaRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_ProxRead
 * Returns raw data of HID prox tag (read only tag / 44 bit).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data HID data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_ProxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_AwidRead
 * Returns number of a AWID tag (read only tag / 44 bit).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Awid data
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_AwidRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_IoProxRead
 * Returns number of a IoProx tag (read only tag / 64 bit).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data IoProx data (5 byte).
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_IoProxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_Prox32Read
 * Returns raw data of HID prox 32 (orange) tag (read only tag / 32bit).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data HID prox32 data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_Prox32Read(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_PyramidRead
 * Returns number of Farpointe Pyramid cards (variable bitlength).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Len 
 * @param[out] Data 
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_PyramidRead(brp_protocol protocol, unsigned* Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_IndalaSecureRead
 * Returns data of indala tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Indala data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_IndalaSecureRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor HID_IdteckRead
 * Returns data of idteck tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Idteck data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_HID_IdteckRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
