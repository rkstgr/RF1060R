/**
 * @file
 * @anchor Rtc
 * If the reader has a Real Time Clock (RTC) on board, its current time can be
 * set and retrieved with commands from this command group.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_RTC_H__
#define __BRP_BALTECH_API_CMDS_RTC_H__
#include "../typedefs.h"
/**
 * @anchor Rtc_ErrHardware
 * The RTC hardware is defect.
 */
#define BRP_Rtc_ErrHardware BRP_ERR_STATUS(0x0400, 0x01)
/**
 * @anchor Rtc_ErrVoltageLow
 * The battery of the RTC is low. The time may be invalid.
 */
#define BRP_Rtc_ErrVoltageLow BRP_ERR_STATUS(0x0400, 0x02)
/**
 * @anchor Rtc_GetTime
 * Retrieve current time of on-board RTC.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ClockId Index of clock to get time of.
 * @param[out] Now Datetime in local time (PC local).
 */
brp_errcode brp_Rtc_GetTime(brp_protocol protocol, unsigned ClockId, unsigned* Now);
/**
 * @anchor Rtc_SetTime
 * Set the time of the on-board RTC.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ClockId Index of clock to set.
 * @param[in] Now When _Now_ is an integer, its value represents the seconds since 1.1.1970-00:00:00 GMT (UNIX Time).  When _Now_ is a _datetime()_ object, it must be set to the local time, not the UTC (or GMT) time. This is due to the fact that the _mktime()_ function is used internally, transforming the local time into UNIX Time.
 */
brp_errcode brp_Rtc_SetTime(brp_protocol protocol, unsigned ClockId, unsigned Now);
#endif
/**
 * @}
 */
