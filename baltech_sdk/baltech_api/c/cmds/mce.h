/**
 * @file
 * @anchor Mce
 * With the _MCE_ command group, you can set up and control the Mobile Card
 * Emulation (MCE) functionality.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_MCE_H__
#define __BRP_BALTECH_API_CMDS_MCE_H__
#include "../typedefs.h"
/**
 * @anchor Mce_ErrNoTag
 * No valid MCE device is currently presented to the reader.
 */
#define BRP_Mce_ErrNoTag BRP_ERR_STATUS(0x4D00, 0x01)
/**
 * @anchor Mce_ErrDisabled
 * MCE functionality is currently disabled.
 */
#define BRP_Mce_ErrDisabled BRP_ERR_STATUS(0x4D00, 0x03)
/**
 * @anchor Mce_ErrLicense
 * A valid BLE license is required, but not available.
 */
#define BRP_Mce_ErrLicense BRP_ERR_STATUS(0x4D00, 0x04)
/**
 * @anchor Mce_Enable
 * This command enables/disables Mobile Card Emulation (MCE).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode 
 */
brp_errcode brp_Mce_Enable(brp_protocol protocol, brp_Mce_Enable_Mode Mode);
/**
 * @anchor Mce_Request
 * This command is used to check if a Mobile Card Emulation (MCE) device (usually
 * a smartphone running a particular app) is currently presented to the reader.
 * As long as an MCE device is detected, the command returns the serial number
 * that has been transferred from the device to the reader.
 * 
 * If no MCE device is detected, the status code [Mce.ErrNoTag](@ref Mce_ErrNoTag)
 * will be returned. In case MCE is not enabled on the reader,
 * [Mce.ErrDisabled](@ref Mce_ErrDisabled) will be returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Snr Emulated serial number
 * @param[out] Snr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mce_Request(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
