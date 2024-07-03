/**
 * @file
 * @anchor Iso14CE
 * This command group allows to emulate an ISO 14443-4 card.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ISO14CE_H__
#define __BRP_BALTECH_API_CMDS_ISO14CE_H__
#include "../typedefs.h"
/**
 * @anchor Iso14CE_ErrIso144State
 * Emulated PICC currently not in the proper state to exchange ISO14443-4 APDUs
 * (PCD didn't activate the protocol)
 * 
 * Card emulation has to be restarted.
 */
#define BRP_Iso14CE_ErrIso144State BRP_ERR_STATUS(0x4A00, 0x01)
/**
 * @anchor Iso14CE_ErrCom
 * Communication problem between microcontroller and reader chip.
 */
#define BRP_Iso14CE_ErrCom BRP_ERR_STATUS(0x4A00, 0x02)
/**
 * @anchor Iso14CE_ErrTransmission
 * HF transmission error (e.g. CRC, framing,...).
 */
#define BRP_Iso14CE_ErrTransmission BRP_ERR_STATUS(0x4A00, 0x03)
/**
 * @anchor Iso14CE_ErrTimeout
 * Timeout: no APDU was received from the PCD within the specified time.
 */
#define BRP_Iso14CE_ErrTimeout BRP_ERR_STATUS(0x4A00, 0x04)
/**
 * @anchor Iso14CE_ErrOverflow
 * Buffer overflow: the PCD sent more data than the receive buffer of the
 * emulated PICC can handle.
 */
#define BRP_Iso14CE_ErrOverflow BRP_ERR_STATUS(0x4A00, 0x05)
/**
 * @anchor Iso14CE_ErrInternal
 * Internal error - should never occur.
 */
#define BRP_Iso14CE_ErrInternal BRP_ERR_STATUS(0x4A00, 0x06)
/**
 * @anchor Iso14CE_ErrDeselect
 * PICC has been deselected.
 */
#define BRP_Iso14CE_ErrDeselect BRP_ERR_STATUS(0x4A00, 0x07)
/**
 * @anchor Iso14CE_ActivateCardAPDU
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
 * [Iso14CE.ExtendWaitingTime](@ref Iso14CE_ExtendWaitingTime) command. Since the
 * ISO14443 protocol specification only allows discrete FWT values, the firmware
 * calculates the lowest value that meets the specified waiting time according to
 * the equation
 * 
 * FWI = (256 * 16 / fc) * 2 ^ FWT,
 * 
 * where fc is the RFID carrier frequency. The highest possible FWT value is 4949
 * ms.
 * 
 * 2 timeout parameters triggering a timer have to be specified for this command:
 * 
 *   * The first timer, associated with the _TimeoutPCD_ parameter, is used for the card activation sequence. Card activation is complete once the emulated PICC has received the RATS command. If the emulated PICC doesn't receive the required protocol activation sequence within _TimeoutPCD_ , this command will return an [Iso14CE.ErrIso144State](@ref Iso14CE_ErrIso144State) status code. For _TimeoutPCD_ , we recommend a value of 1000 ms - this provides the best results for the protocol activation sequence. 
 *   * The second timer is optional (default value: 100 ms) and associated with the _TimeoutApdu_ parameter. It stops as soon as the emulated PICC has received an optional PPS command frame or an APDU Exchange command after the RATS command as defined in ISO14443-4. If the emulated PICC doesn't receive anything within _TimeoutApdu_ , this command will return an [Iso14CE.ErrIso144State](@ref Iso14CE_ErrIso144State) status code. Otherwise, the first APDU request is returned in the command's response. 
 * 
 * The ATS (historical bytes) the card emulation shall use may be specified by
 * the _ATS_ parameter if required. This parameter may also be left out, in which
 * case no historical bytes are sent.
 * 
 * As already mentioned, ISO14443-4 specifies that a card has to send a response
 * within _FWT_ ms. The command
 * [I4CE.ExtendWaitingTime](@ref Iso14CE_ExtendWaitingTime) can be called to extend
 * this time temporarily if the host cannot prepare the APDU within the defined
 * FWT time. A more convenient way to perform this action is to use the
 * _automatic WTX mode_ : If the parameter _AutoWTX_ is set to 1, the card
 * emulation will automatically transmit WTX requests periodically every 0.9 *
 * FWT ms after the successful execution of the Iso14CE.StartEmu command and of
 * all subsequent [Iso14CE.ExchangeCardAPDU](@ref Iso14CE_ExchangeCardAPDU)
 * commands. In practice, this allows to ignore the FWT limits, since the card
 * emulation itself keeps the communication with the PCD alive.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SpecifyTimeoutApdu Has to be set if the _TimeoutApdu_ parameter is present.
 * @param[in] AutoWTX Enable/disable automatic _Waiting Time Extension_
 * @param[in] ATQA Attention: When transferred via HF, the ATQA is sent LSB (instead of the MSB order used here).
 * @param[in] Snr Card serial number of the emulated PICC according to the [ISO14443-3 specification](https://www.iso.org/standard/50942.html) (uid0, uid1, uid2, uid3).
 * @param[in] DSEqualToDR Same D for both directions
 * @param[in] DS8 supports 848 kBit PICC -> PCD
 * @param[in] DS4 supports 424 kBit PICC -> PCD
 * @param[in] DS2 supports 212 kBit PICC -> PCD
 * @param[in] DR8 supports 848 kBit PCD -> PICC
 * @param[in] DR4 supports 424 kBit PCD -> PICC
 * @param[in] DR2 supports 212 kBit PCD -> PICC
 * @param[in] FWT Frame waiting time in ms. This is the maximum time the PCD waits for the next PICC response.  If FWT is set to 0xFFFF the default frame waiting time of 77.328 ms will be applied.
 * @param[in] TimeoutPCD Maximum time (in ms) to wait for card activation. Card activation is complete after the PICC has received the RATS command.  A value of 0xFFFF corresponds to an infinite time.
 * @param[in] TimeoutApdu Maximum time (in ms) to wait for an optional Apdu or the first ISO14443-4 APDU after the first received PCD frame.  This value is optional - if not given as a parameter, it's set to 100ms.  A value of 0xFFFF corresponds to an infinite time.
 * @param[in] ATS ATS (Historical Bytes) to use for card emulation.
 * @param[in] ATS_len 
 * @param[out] FirstCmd First ISO14443-4 APDU request received from the PCD.
 * @param[out] FirstCmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14CE_ActivateCardAPDU(brp_protocol protocol, bool SpecifyTimeoutApdu, bool AutoWTX, unsigned ATQA, brp_buf Snr, bool DSEqualToDR, bool DS8, bool DS4, bool DS2, bool DR8, bool DR4, bool DR2, unsigned FWT, unsigned TimeoutPCD, unsigned TimeoutApdu, brp_buf ATS, size_t ATS_len, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool);
/**
 * @anchor Iso14CE_ExchangeCardAPDU
 * Send an APDU response to the APDU request received during the last call of
 * Iso14CE.ExchangeInverseAPDU or
 * [Iso14CE.ActivateCardAPDU](@ref Iso14CE_ActivateCardAPDU), and receive the next
 * PCD APDU request.
 * 
 * The _Timeout_ parameter specifies the maximum time in ms to wait for the next
 * APDU. If no request could be received from the PCD,
 * Iso14CE.ExchangeInverseAPDU returns the
 * [Iso14CE.ErrTimeout](@ref Iso14CE_ErrTimeout) status code.
 * 
 * In case the received APDU does not fit into the internal buffer of the
 * emulated PICC, the part of the frame which could be processed is returned
 * together with an [I4CE.ErrOverflow](@ref Iso14CE_ErrOverflow) status code. The
 * buffer size is firmware dependent and can be retrieved via the
 * [Sys.GetBufferSize](@ref Sys_GetBufferSize) command.
 * 
 * The command returns the [Iso14CE.ErrIso144State](@ref Iso14CE_ErrIso144State)
 * status code if the PICC is not in the proper state to exchange ISO14443-4
 * APDUs. This is the case if
 * [Iso14CE.ActivateCardAPDU](@ref Iso14CE_ActivateCardAPDU) has not previously been
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
 */
brp_errcode brp_Iso14CE_ExchangeCardAPDU(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool);
/**
 * @anchor Iso14CE_ExtendWaitingTime
 * This command enables to extend the waiting time for the response from the PCD.
 * This command is required in case the host needs a longer time than FWT (see
 * description of the [Iso14CE.ActivateCardAPDU](@ref Iso14CE_ActivateCardAPDU)
 * command) to prepare a response APDU to the last request APDU from the PCD.
 * After calling this command, the PICC repeatedly sends WTX requests to the PCD
 * for _WaitingTimeout_ ms.
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
 * Iso14CE.ActivateCardAPDU](@ref Iso14CE_ActivateCardAPDU) command is set to 0.
 * Otherwise, the card emulation automatically takes care of extending the frame
 * waiting time.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] WaitingTimeout Time (in ms) for which the emulated PICC should send WTX requests repeatedly. A value of 0xFFFF corresponds to an infinite value.
 * @param[in] WTXM _Waiting Time Extension Multiplier_ (WTXM). This parameter extends the actual frame waiting time (FWT) by this multiplier (FWT_temp = FWT * WTXM). WTXM has to be comprised between 1 and 59.
 * @param[in] RefreshTimeRatio Together with parameter _WTXM_ , this value defines the WTX request refresh cycle time interval:  t(refresh) = FWT * WTXM / RefreshTimeRatio.  The value range of _RefreshTimeRatio_ is 0..100. t(refresh) is expressed in ms.
 */
brp_errcode brp_Iso14CE_ExtendWaitingTime(brp_protocol protocol, unsigned WaitingTimeout, unsigned WTXM, unsigned RefreshTimeRatio);
/**
 * @anchor Iso14CE_GetExternalHfStatus
 * Polls for an external HF field and returns the status in the _ExtFieldStat_
 * variable.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ExtFieldStat _true_ (1) indicates that an external HF field has been detected, while _false_ (0) indicates the opposite.
 */
brp_errcode brp_Iso14CE_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat);
#endif
/**
 * @}
 */
