/**
 * @file
 * @anchor Keyboard
 * Commands to get a key from the keyboard and to control the keyboard.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_KEYBOARD_H__
#define __BRP_BALTECH_API_CMDS_KEYBOARD_H__
#include "../typedefs.h"
/**
 * @anchor Keyboard_Exist
 * Checks if a keyboard is connected. Returns _true_ if this is the case.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] KeyboardConnected _true_ when the keyboard is connected.
 */
brp_errcode brp_Keyboard_Exist(brp_protocol protocol, bool* KeyboardConnected);
/**
 * @anchor Keyboard_CurrentKey
 * Returns the keycode of the currently pressed key. This function does not
 * perform any key buffering or key repeating avoidance operation.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Key The keycode of the currently pressed key.
 */
brp_errcode brp_Keyboard_CurrentKey(brp_protocol protocol, unsigned* Key);
/**
 * @anchor Keyboard_EnableWakeup
 * Enables the keyboard wake-up feature. When this function is enabled, the
 * device will be woken up when it is in power down mode and a key is pressed.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable Enable keyboard wake-up.
 */
brp_errcode brp_Keyboard_EnableWakeup(brp_protocol protocol, bool Enable);
/**
 * @anchor Keyboard_WaitForKey
 * Waits until a key press is detected.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Timeout Time in milliseconds to wait for a key press. If no key press is detected within this time, Keyboard.WaitForKey returns KBD_KEY_NONE (0).
 * @param[out] Key 
 */
brp_errcode brp_Keyboard_WaitForKey(brp_protocol protocol, unsigned Timeout, unsigned* Key);
#endif
/**
 * @}
 */
