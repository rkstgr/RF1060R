/**
 * @file
 * @anchor I4CE
 * This command group allows to emulate an ISO 14443-4 card.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_I4CE_H__
#define __BRP_BALTECH_API_CMDS_I4CE_H__
#include "../typedefs.h"
/**
 * @anchor I4CE_ErrIso144State
 * Emulated PICC currently not in the proper state to exchange ISO14443-4 APDUs
 * (PCD didn't activate the protocol or PICC has been deselected).
 * 
 * Card emulation has to be restarted.
 */
#define BRP_I4CE_ErrIso144State BRP_ERR_STATUS(0x4800, 0x01)
/**
 * @anchor I4CE_ErrCom
 * Communication problem between microcontroller and reader chip.
 */
#define BRP_I4CE_ErrCom BRP_ERR_STATUS(0x4800, 0x02)
/**
 * @anchor I4CE_ErrTransmission
 * HF transmission error (e.g. CRC, framing,...).
 */
#define BRP_I4CE_ErrTransmission BRP_ERR_STATUS(0x4800, 0x03)
/**
 * @anchor I4CE_ErrTimeout
 * Timeout: no APDU was received from the PCD within the specified time.
 */
#define BRP_I4CE_ErrTimeout BRP_ERR_STATUS(0x4800, 0x04)
/**
 * @anchor I4CE_ErrOverflow
 * Buffer overflow: the PCD sent more data than the receive buffer of the
 * emulated PICC can handle.
 */
#define BRP_I4CE_ErrOverflow BRP_ERR_STATUS(0x4800, 0x05)
/**
 * @anchor I4CE_ErrInternal
 * Internal error - should never occur.
 */
#define BRP_I4CE_ErrInternal BRP_ERR_STATUS(0x4800, 0x06)
/**
 * @anchor I4CE_StartEmu
 * **This command is marked as deprecated as it is not supported by Baltech's
 * SDK. There is currently no alternative for this command.**
 * 
 * This command starts the reader's passive mode, emulating an ISO14443-4
 * compatible card, and returns the first APDU request received.
 * 
 * The emulated PICC answers all ISO14443-3 request, anticollision and select
 * commands. It utilizes the 4-Byte serial number specified in the _Snr_
 * parameter. The Byte order corresponds to ISO14443-3: The first Byte (uid0)
 * will be transmitted first to the reader. It has to be 0x08 as this indicates a
 * random serial number.
 * 
 * To identify potential errors, the PCD starts a timer within which the PICC has
 * to respond, after sending out each frame. This time duration is the so-called
 * _frame waiting time_ (FWT). FWT is determined by the PICC during protocol
 * activation and is valid for all further communication. This parameter should
 * be chosen as large as required, but as small as possible. The communication
 * speed between card emulator and host and the processing speed of the host
 * should be taken into consideration. It is possible to increase the FWT
 * temporarily for a single frame by calling the
 * [I4CE.ExtendWaitingTime](@ref I4CE_ExtendWaitingTime) command. Since the ISO14443
 * protocol specification only allows discrete FWT values, the firmware
 * calculates the lowest value that meets the specified waiting time according to
 * the equation
 * 
 * FWI = (256 * 16 / fc) * 2 ^ FWT,
 * 
 * where fc is the RFID carrier frequency. The highest possible FWT value is 4949
 * ms.
 * 
 * Two timeout parameters triggering two timers have to be specified for this
 * command. The first timer, associated to the _TimeoutPCD_ parameter, stops as
 * soon as the first PCD command frame after the card selection as defined in
 * ISO14443-3 is received. If the emulated PICC does not receive anything within
 * _TimeoutPCD_ , this command will return an
 * [I4CE.ErrIso144State](@ref I4CE_ErrIso144State) status code, which indicates that
 * the PICC did not receive the required protocol activation sequence to exchange
 * ISO14443-4 APDUs. If a PCD frame is received before _TimeoutPCD_ elapses, the
 * second timer, associated to the _TimeoutAPDU_ variable, is started. If this
 * timer elapses before the reader receives the first protocol activation
 * sequence and the first APDU, the [I4CE.ErrTimeout](@ref I4CE_ErrTimeout) status
 * code is returned. Otherwise, the first APDU request is returned in the
 * command's response.
 * 
 * The ATS (historical bytes) the card emulation shall use may be specified by
 * the _ATS_ parameter if required. This parameter may also be left out, in which
 * case no historical bytes are sent.
 * 
 * As already mentioned, ISO14443-4 specifies that a card has to send a response
 * within _FWT_ ms. The command
 * [I4CE.ExtendWaitingTime](@ref I4CE_ExtendWaitingTime) can be called to extend
 * this time temporarily if the host cannot prepare the APDU within the defined
 * FWT time. A more convenient way to perform this action is to use the
 * _automatic WTX mode_ : If the parameter _AutoWTX_ is set to 1, the card
 * emulation will automatically transmit WTX requests periodically every 0.9 *
 * FWT ms after the successful execution of the I4CE.StartEmu command and of all
 * subsequent [I4CE.ExchangeInverseAPDU](@ref I4CE_ExchangeInverseAPDU) commands. In
 * practice, this allows to ignore the FWT limits, since the card emulation
 * itself keeps the communication with the PCD alive.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Snr Card serial number of the emulated PICC according to the [ISO14443-3 specification](https://www.iso.org/standard/50942.html) (uid0, uid1, uid2, uid3).
 * @param[in] FWT Frame waiting time in ms. This is the maximum time the PCD waits for the next PICC response.  If FWT is set to 0 the default frame waiting time of 77.328 ms will be applied.
 * @param[in] TimeoutPCD Maximum time (in ms) to wait for the first frame sent from the PCD.  A value of 0xFFFF corresponds to an infinite time.
 * @param[in] TimeoutAPDU Maximum time (in ms) to wait for the first ISO14443-4 APDU after the first received PCD frame.  A value of 0xFFFF corresponds to an infinite timeout.
 * @param[in] ATS ATS (Historical Bytes) to use for card emulation.
 * @param[in] ATS_len 
 * @param[in] AutoWTX Enable/disable automatic _Waiting Time Extension_ (WTX).
 * @param[out] FirstCmd First ISO14443-4 APDU request received from the PCD.
 * @param[out] FirstCmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_I4CE_StartEmu(brp_protocol protocol, brp_buf Snr, unsigned FWT, unsigned TimeoutPCD, unsigned TimeoutAPDU, brp_buf ATS, size_t ATS_len, unsigned AutoWTX, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool);
/**
 * @anchor I4CE_ExchangeInverseAPDU
 * **This command is marked as deprecated as it is not supported by Baltech's
 * SDK. There is currently no alternative for this command.**
 * 
 * Send an APDU response to the APDU request received during the last call of
 * I4CE.ExchangeInverseAPDU or [I4CE.StartEmu](@ref I4CE_StartEmu), and receive the
 * next PCD APDU request.
 * 
 * The _Timeout_ parameter specifies the maximum time in ms to wait for the next
 * APDU. If no request could be received from the PCD, I4CE.ExchangeInverseAPDU
 * returns the [I4CE.ErrTimeout](@ref I4CE_ErrTimeout) status code.
 * 
 * In case the received APDU does not fit into the internal buffer of the
 * emulated PICC, the part of the frame which could be processed is returned
 * together with an [I4CE.ErrOverflow](@ref I4CE_ErrOverflow) status code. The
 * buffer size is firmware dependent and can be retrieved via the
 * [Sys.GetBufferSize](@ref Sys_GetBufferSize) command.
 * 
 * The command returns the [I4CE.ErrIso144State](@ref I4CE_ErrIso144State) status
 * code if the PICC is not in the proper state to exchange ISO14443-4 APDUs. This
 * is the case if [I4CE.StartEmu](@ref I4CE_StartEmu) has not previously been
 * successfully executed, or if the PCD has terminated the communication by e.g.
 * executing the [Iso14L4.Deselect](@ref Iso14L4_Deselect) command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Rsp APDU which shall be sent to the PCD as a response to the last command.
 * @param[in] Rsp_len 
 * @param[in] Timeout Maximum time (in ms) to wait for the next ISO14443-4 APDU request.  A value of 0xFFFF corresponds to an infinite timeout.
 * @param[out] Cmd Next ISO14443-4 APDU request received from the PCD.
 * @param[out] Cmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_I4CE_ExchangeInverseAPDU(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool);
/**
 * @anchor I4CE_ExtendWaitingTime
 * This command enables to extend the waiting time for the response from the PCD.
 * This command is required in case the host needs a longer time than FWT (see
 * description of the [I4CE.StartEmu](@ref I4CE_StartEmu) command) to prepare a
 * response APDU to the last request APDU from the PCD. After calling this
 * command, the PICC repeatedly sends WTX requests to the PCD for
 * _WaitingTimeout_ ms.
 * 
 * **This command should be run in BRP _Continuous Mode_ , since it can
 * explicitly be stopped by the host by executing the _Break_ command. If this
 * command is not run in BRP Continuous Mode, the reader has to wait for the
 * _WaitingTimeout_ duration before finalizing the execution of the command.**
 * 
 * The WTX request refresh interval may be accommodated with the _WTXM_ and
 * _RefreshRatio_ parameters according to the formula:
 * 
 * t(refresh) = FWT * WTXM * RefreshRatio / 100.
 * 
 * By default, the waiting time is renewed every (0.9 * FWT) ms (WTXM = 1,
 * RefreshRatio = 90).
 * 
 * Please note that according to the [ISO/IEC
 * 14443-4:2008](https://www.iso.org/standard/50648.html) specification, the
 * maximum allowed value for FWT and for the extension FWT * WTXM is 4949 ms.
 * 
 * **This command should only be used if the _AutoWTX_ parameter in the[
 * I4CE.StartEmu](@ref I4CE_StartEmu) command is set to 0. Otherwise, the card
 * emulation automatically takes care of extending the frame waiting time.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] WaitingTimeout Time (in ms) for which the emulated PICC should send WTX requests repeatedly. A value of 0xFFFF corresponds to an infinite value.
 * @param[in] WTXM _Waiting Time Extension Multiplier_ (WTXM). This parameter extends the actual frame waiting time (FWT) by this multiplier (FWT_temp = FWT * WTXM). WTXM has to be comprised between 1 and 59.
 * @param[in] RefreshTimeRatio Together with parameter _WTXM_ , this value defines the WTX request refresh cycle time interval:  t(refresh) = FWT * WTXM / RefreshTimeRatio.  The value range of _RefreshTimeRatio_ is 0..100. t(refresh) is expressed in ms.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_I4CE_ExtendWaitingTime(brp_protocol protocol, unsigned WaitingTimeout, unsigned WTXM, unsigned RefreshTimeRatio);
/**
 * @anchor I4CE_GetExternalHfStatus
 * Polls for an external HF field and returns the status in the _ExtFieldStat_
 * variable.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ExtFieldStat _true_ (1) indicates that an external HF field has been detected, while _false_ (0) indicates the opposite.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_I4CE_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat);
#endif
/**
 * @}
 */
