/**
 * @file
 * @anchor UI
 * With the _User Interface_ command group, you can control the reader's feedback
 * to the card holder, e.g. via LEDs and beeper.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_UI_H__
#define __BRP_BALTECH_API_CMDS_UI_H__
#include "../typedefs.h"
/**
 * @anchor UI_ErrInvalidPort
 * The specified port isn't available or it doesn't support the desired
 * operation.
 */
#define BRP_UI_ErrInvalidPort BRP_ERR_STATUS(0x0A00, 0x01)
/**
 * @anchor UI_Enable
 * This command enables a specific port of the reader.
 * 
 * Depending on the type of the selected port, it does one of the following:
 * 
 *   * Drive an output pin high (GPIO)
 *   * Activate a peripheral component (beeper, relay)
 *   * Switch an LED to a certain color
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port I/O pins of the reader that can be controlled by the user.
 */
brp_errcode brp_UI_Enable(brp_protocol protocol, brp_IoPort Port);
/**
 * @anchor UI_Disable
 * This command disables a specific port of the reader.
 * 
 * Depending on the type of the selected port, it does one the following:
 * 
 *   * Drive an output pin low (GPIO)
 *   * Deactivate a peripheral component (beeper, relay)
 *   * Switch an LED off
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port I/O pins of the reader that can be controlled by the user.
 */
brp_errcode brp_UI_Disable(brp_protocol protocol, brp_IoPort Port);
/**
 * @anchor UI_Toggle
 * This command toggles the output state of a specific port.
 * 
 * A single toggle consists of 2 state changes: From the initial state to the
 * inverse state and back. The initial state is defined by the _Polarity_
 * parameter. This is also the state of the port at the end of the toggling
 * operation.
 * 
 * To stop the toggling, call [UI.Enable](@ref UI_Enable) or
 * [UI.Disable](@ref UI_Disable) for this port.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port I/O pins of the reader that can be controlled by the user.
 * @param[in] ToggleCount The number of toggles. To toggle forever, choose 0xFF.
 * @param[in] Timespan1 The time in ms that the port is to stay in the inverse state.
 * @param[in] Timespan2 The time in ms that the port is to stay in the initial state.
 * @param[in] Polarity 
 */
brp_errcode brp_UI_Toggle(brp_protocol protocol, brp_IoPort Port, unsigned ToggleCount, unsigned Timespan1, unsigned Timespan2, brp_UI_Toggle_Polarity Polarity);
/**
 * @anchor UI_SetRgbLed
 * This command changes the RGB color of a single LED or a group of LEDs. The
 * color may be activated instantly or smoothly by a sine-wave approximated
 * fading transition.
 * 
 * If the addressed LEDs are already active when this command is called, the
 * color first fades to black (off), before the transition to the new color
 * starts.
 * 
 * **This command gives you direct control of the reader's LEDs. It competes with
 * the command[ UI.Enable](@ref UI_Enable) , which can be used to switch LEDs via
 * Virtual LED port definitions (VLEDs)._UI.Enable_ operates on a higher
 * abstraction level. Don't mix the 2 commands as this may result in inconsistent
 * behavior.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] LedBitMask A bitmask containing all LEDs you want to switch.
 * @param[in] RgbColor The target RGB color (0x00RRGGBB).
 * @param[in] TransitionTime The time for the fading transition to activate the target RGB color in ms. If a color is currently activated, this is also the time for the transition to deactivate this color first. For an immediate color activation, set the value to 0.
 */
brp_errcode brp_UI_SetRgbLed(brp_protocol protocol, unsigned LedBitMask, unsigned RgbColor, unsigned TransitionTime);
/**
 * @anchor UI_PulseRgbLed
 * This command starts to pulse a single LED or a group of multiple LEDs
 * continuously by performing smooth sine-wave approximated transitions between 2
 * RGB colors.
 * 
 * To stop the pulsing, call the command [UI.SetRgbLed](@ref UI_SetRgbLed).
 * 
 * **This command gives you direct control of the reader's LEDs. It competes with
 * the command[ UI.Enable](@ref UI_Enable) , which can be used to switch LEDs via
 * Virtual LED port definitions (VLEDs)._UI.Enable_ operates on a higher
 * abstraction level. Don't mix the 2 commands as this may result in inconsistent
 * behavior.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] LedBitMask A bitmask containing all LEDs you want to switch.
 * @param[in] RgbColor1 The first RGB color of the desired pulse signal (0x00RRGGBB).
 * @param[in] RgbColor2 The second RGB color of the desired pulse signal (0x00RRGGBB).
 * @param[in] TransitionTime The time for the fading transition to activate the first RGB color in ms. If a color is currently activated, this is also the time to deactivate this color first. For an immediate color activation, choose the value 0.
 * @param[in] Period The period of the pulse signal in ms. This is the time to transition from the first RGB color to the second and back to the first.
 */
brp_errcode brp_UI_PulseRgbLed(brp_protocol protocol, unsigned LedBitMask, unsigned RgbColor1, unsigned RgbColor2, unsigned TransitionTime, unsigned Period);
#endif
/**
 * @}
 */
