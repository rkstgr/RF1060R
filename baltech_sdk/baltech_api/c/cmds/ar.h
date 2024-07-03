/**
 * @file
 * @anchor AR
 * With the _Autoread_ command group, you can control a reader configured for
 * Autoread mode. This mode allows the reader to autonomously scan for cards,
 * validate and read them, and interact with the user (e.g. give feedback via
 * beeper/LED or switch a door relay). Besides, the reader buffers data read from
 * the card, so the host application can retrieve it.
 * 
 * For more details on how to implement Autoread, please see our [ Autoread
 * workflow overview](https://docs.baltech.de/developers/map-autoread-brp.html).
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_AR_H__
#define __BRP_BALTECH_API_CMDS_AR_H__
#include "../typedefs.h"
/**
 * @anchor AR_ErrNoMessage
 * No valid card has been presented to the reader so far.
 */
#define BRP_AR_ErrNoMessage BRP_ERR_STATUS(0x0500, 0x01)
/**
 * @anchor AR_ErrScriptRuntime
 * A runtime error occurred when executing the script.
 */
#define BRP_AR_ErrScriptRuntime BRP_ERR_STATUS(0x0500, 0x02)
/**
 * @anchor AR_ErrScriptSyntax
 * There's a syntax error in the script code.
 */
#define BRP_AR_ErrScriptSyntax BRP_ERR_STATUS(0x0500, 0x03)
/**
 * @anchor AR_ErrScriptNotImplemented
 * The script ran the command
 * __DefaultAction__.
 */
#define BRP_AR_ErrScriptNotImplemented BRP_ERR_STATUS(0x0500, 0x04)
/**
 * @anchor AR_ErrArDisabled
 * Autoread is disabled.
 */
#define BRP_AR_ErrArDisabled BRP_ERR_STATUS(0x0500, 0x10)
/**
 * @anchor AR_SetMode
 * This command controls Autoread mode at runtime. Usually, the Autoread
 * subsystem will be stared at boot time if the reader is __ configured to work
 * autonomously__.
 * However, you can still enable and disable Autoread at runtime. This is e.g.
 * needed if you use [ VHL & Autoread](https://docs.baltech.de/developers/map-
 * vhl-autoread.html) in combination, so you can interrupt Autoread to run VHL
 * commands.
 * 
 * **_AR.SetMode_ automatically empties the reader's message buffer. This ensures
 * that the next[ AR.GetMessage](@ref AR_GetMessage) you run doesn't return "old"
 * data from a card detected before running _AR.SetMode_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode Defines if Autoread is active, so the reader scans autonomously for cards.  **The reader will disable Autoread mode automatically if you execute a card- accessing command (e.g[ VHL.Select](@ref VHL_Select) ).**
 */
brp_errcode brp_AR_SetMode(brp_protocol protocol, brp_AutoReadMode Mode);
/**
 * @anchor AR_GetMessage
 * This command checks if a card has been presented to the reader since the last
 * _AR.GetMessage_ execution. If yes, the card identification will be returned in
 * _MsgData_. If no, the [AR.ErrNoMessage](@ref AR_ErrNoMessage) status code will be
 * returned.
 * 
 * Apart from card identifications, some readers support additional types of
 * messages, e.g. PINs entered via the keyboard. This information is returned in
 * _MsgType_.
 * 
 * **Read results are buffered in the reader's memory for 5 seconds, i.e. that's
 * the time frame you have to execute this command.**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] MsgType Event that triggered the message. It allows the host application to interpret the message content correctly.
 * @param[out] MsgData Content of message (usually an ASCII string)
 * @param[out] MsgData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_AR_GetMessage(brp_protocol protocol, brp_MessageType* MsgType, brp_buf* MsgData, size_t* MsgData_len, brp_mempool *mempool);
/**
 * @anchor AR_RunScript
 * This command runs a [BaltechScript](../cfg/baltechscript.xml). This is a small
 * sequence of instructions for the reader to execute. Typically, it's used to
 * control reader feedback, i.e. LEDs, beeper, relay, and other I/O ports when
 * you have highly specific requirements and/or want to store the script on the
 * reader.
 * 
 * **Instead of _AR.RunScript_ , we recommend the[ UI command
 * set](userinterface.xml) as it's easier to implement and sufficient for the
 * majority of use cases.**
 * 
 * ## Script structure
 * 
 * A script consists of the following parts:
 * 
 *   * _Frame value_ (e.g. 0x01 for Enable)
 *   * _Port_ (e.g. 0x00 for the green LED)
 *   * _Parameters_ if applicable (e.g. number of repetitions and delay after each change of state)
 * 
 * ## Examples
 * 
 * Here are a few examples of how to create a script. We'll use the following
 * script commands as they're the most important ones:
 * 
 *   * __Enable__
 *   * __Disable__
 *   * __Toggle__
 *   * __ToggleInverted__
 * 
 * ### Single script to control 1 port
 * 
 * In this example, we'll switch on the green LED permanently. To do so, we need
 * to run the __Enable__ script as
 * follows:
 * 
 * `01 00`
 * 
 *   * _01_ is the frame value for _Enable_.
 *   * _00_ is the parameter value for the _green LED_.
 * 
 * ### Sequence of scripts
 * 
 * You can run a sequence of scripts in parallel by concatenating them.
 * 
 * #### Simultaneous feedback sequence
 * 
 * In this example, we'll switch on the green LED permanently. At the same time,
 * we have the beeper beep 3 times for 200 ms. To do so, we extend the _Enable_
 * script from the above example with a
 * __Toggle__ script:
 * 
 * `01 00 03 02 03 02`
 * 
 * The _Toggle_ script in this sequence is composed as follows:
 * 
 *   * _03_ is the frame value for _Toggle_.
 *   * _02_ is the parameter for the _beeper_.
 *   * _03_ is the _repeat count_.
 *   * _02_ is the _delay_ : 
 * 
 * The unit of this value is 1/10 sec, i.e. it's 200 ms in this example. This
 * time period applies to the length of the beep and the delay afterwards, i.e.
 * you have a duration of 2x200 ms per beep and a duration of 1200 ms for the
 * entire sequence.
 * 
 * #### Consecutive feedback sequence
 * 
 * Concatenated scripts are always executed in parallel. However, you can still
 * produce a consecutive feedback sequence using
 * __ToggleInverted__ and an
 * appropriate delay. In this example, we'll use the toggle script from the above
 * example to have the beeper beep 3 times for 200 ms. After the third beep, the
 * red LED is enabled:
 * 
 * `03 02 03 02 06 01 01 0C`
 * 
 * The _ToggleInverted_ script in this sequence is composed as follows:
 * 
 *   * _06_ is the frame value for _ToggleInverted_.
 *   * _01_ is the parameter for the _red LED_.
 *   * _01_ is the _repeat count_.
 *   * _0C_ is the _delay_ : 
 * 
 * The unit of this value is 1/10 sec, i.e. it's 1200 ms in this example. This
 * corresponds to the duration of the _Toggle_ script that runs in parallel (see
 * also previous example). Thus the LED (controlled by the _ToggleInverted_
 * script) turns on after the beeper sequence (controlled by the _Toggle_ script)
 * is completed.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Script Script to execute
 * @param[in] Script_len 
 */
brp_errcode brp_AR_RunScript(brp_protocol protocol, brp_buf Script, size_t Script_len);
#endif
/**
 * @}
 */
