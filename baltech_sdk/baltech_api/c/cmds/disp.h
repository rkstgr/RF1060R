/**
 * @file
 * @anchor Disp
 * These are the Display Control commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_DISP_H__
#define __BRP_BALTECH_API_CMDS_DISP_H__
#include "../typedefs.h"
/**
 * @anchor Disp_DispPageNotFound
 * Page was neither found in configuration nor in flash
 */
#define BRP_Disp_DispPageNotFound BRP_ERR_STATUS(0x4100, 0x01)
/**
 * @anchor Disp_DispUnexpectedEop
 * Unexpected end of page
 */
#define BRP_Disp_DispUnexpectedEop BRP_ERR_STATUS(0x4100, 0x02)
/**
 * @anchor Disp_DispOutOfMem
 * Too much defines, too much frames or too much strings used by this page
 */
#define BRP_Disp_DispOutOfMem BRP_ERR_STATUS(0x4100, 0x03)
/**
 * @anchor Disp_DispFrameNotFound
 * The specified frame is not defined
 */
#define BRP_Disp_DispFrameNotFound BRP_ERR_STATUS(0x4100, 0x04)
/**
 * @anchor Disp_DispUnknownCommand
 * The render command is not known
 */
#define BRP_Disp_DispUnknownCommand BRP_ERR_STATUS(0x4100, 0x05)
/**
 * @anchor Disp_DispStringTooLong
 * String is too long
 */
#define BRP_Disp_DispStringTooLong BRP_ERR_STATUS(0x4100, 0x06)
/**
 * @anchor Disp_DispInvalidFont
 * invalid font
 */
#define BRP_Disp_DispInvalidFont BRP_ERR_STATUS(0x4100, 0x07)
/**
 * @anchor Disp_Enable
 * Enable/Disable Display.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable 
 */
brp_errcode brp_Disp_Enable(brp_protocol protocol, bool Enable);
/**
 * @anchor Disp_SetContrast
 * Set contrast of display
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Contrast 
 */
brp_errcode brp_Disp_SetContrast(brp_protocol protocol, unsigned Contrast);
/**
 * @anchor Disp_EnableBacklight
 * Enable/Disable display backlight
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnableLight 
 */
brp_errcode brp_Disp_EnableBacklight(brp_protocol protocol, bool EnableLight);
/**
 * @anchor Disp_Clear
 * Clear Page description.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DelPermanentDefines If TRUE, all defines will be deleted. Otherwise the permanent defines (>=0x80) will be kept.
 */
brp_errcode brp_Disp_Clear(brp_protocol protocol, bool DelPermanentDefines);
/**
 * @anchor Disp_Load
 * Load page description.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageDesc 
 * @param[in] PageDesc_len 
 */
brp_errcode brp_Disp_Load(brp_protocol protocol, brp_buf PageDesc, size_t PageDesc_len);
/**
 * @anchor Disp_Extend
 * Extend page description
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageDesc 
 * @param[in] PageDesc_len 
 */
brp_errcode brp_Disp_Extend(brp_protocol protocol, brp_buf PageDesc, size_t PageDesc_len);
#endif
/**
 * @}
 */
