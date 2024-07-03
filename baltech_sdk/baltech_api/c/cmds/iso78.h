/**
 * @file
 * @anchor Iso78
 * This command group enables to access ISO 7816 compatible SAM modules attached
 * to the Baltech ID-engine reader. It creates a transparent channel to the SAM
 * which can be used in order to exchange APDUs following the ISO 7816-3
 * standard.
 * 
 * This command group supports multiple SAM slots, which can be switched via the
 * [Iso78.SelectSlot](@ref Iso78_SelectSlot) command.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ISO78_H__
#define __BRP_BALTECH_API_CMDS_ISO78_H__
#include "../typedefs.h"
/**
 * @anchor Iso78_ErrInvalidSlot
 * The specified slot index is not supported.
 */
#define BRP_Iso78_ErrInvalidSlot BRP_ERR_STATUS(0x4000, 0x02)
/**
 * @anchor Iso78_ErrAbort
 * SAM aborted command execution by sending an abort command.
 */
#define BRP_Iso78_ErrAbort BRP_ERR_STATUS(0x4000, 0x10)
/**
 * @anchor Iso78_ErrProtNotSupported
 * The specified protocol is not supported.
 */
#define BRP_Iso78_ErrProtNotSupported BRP_ERR_STATUS(0x4000, 0x20)
/**
 * @anchor Iso78_ErrCom
 * Communication error.
 */
#define BRP_Iso78_ErrCom BRP_ERR_STATUS(0x4000, 0x21)
/**
 * @anchor Iso78_ErrHw
 * Hardware error.
 */
#define BRP_Iso78_ErrHw BRP_ERR_STATUS(0x4000, 0x22)
/**
 * @anchor Iso78_ErrInvalid7816Cmd
 * The command/parameter(s) is/are not supported by the SAM.
 */
#define BRP_Iso78_ErrInvalid7816Cmd BRP_ERR_STATUS(0x4000, 0x31)
/**
 * @anchor Iso78_SelectSlot
 * This command can be used for readers with more than one SAM slot to switch
 * between the slots. The slots are indexed starting at 0. At power up, slot 0 is
 * selected. All following commands are routed to the SAM in the selected slot.
 * 
 * It is possible to switch the slots after opening a SAM.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SlotIndex Index of Slot to select.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso78_SelectSlot(brp_protocol protocol, unsigned SlotIndex);
/**
 * @anchor Iso78_OpenSamLegacy
 * This command sets up a communication channel to the SAM in the currently
 * selected slot. If Iso78.OpenSAM was executed successfully,
 * [Iso78.ExchangeApdu](@ref Iso78_ExchangeApdu) can then be used to communicate
 * with the SAM.
 * 
 * To close the communication channel after data exchange, the
 * [Iso78.CloseSam](@ref Iso78_CloseSam) command has to be called.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ATR ATR (Answer To Reset) string of SAM.
 * @param[out] ATR_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso78_OpenSamLegacy(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool);
/**
 * @anchor Iso78_CloseSamLegacy
 * This command closes a communication channel previously opened via the
 * [Iso78.OpenSAM](@ref Iso78_OpenSam) command. It is recommended to call this
 * command before physically removing the SAM from its slot since it also powers
 * down the SAM module.
 * 
 * @param[in] protocol used to execute the command
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso78_CloseSamLegacy(brp_protocol protocol);
/**
 * @anchor Iso78_ExchangeApduLegacy
 * This command sends an APDU command on the currently selected and opened SAM.
 * Please note that the complete APDU command including the CLA, INS, P1, P2, Lc
 * and Le values need part of the _SendData_ parameter.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SendData APDU command data including CLA, INS, P1, P2, Lc and Le.
 * @param[in] SendData_len 
 * @param[out] RecvData APDU response data.
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso78_ExchangeApduLegacy(brp_protocol protocol, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
/**
 * @anchor Iso78_OpenSam
 * This command sets up a communication channel to a Secure Access Module (SAM)
 * inserted into the reader. To select the SAM, you specify it using the _LID_
 * parameter as described below. Once you've run this command successfully, you
 * can run [Iso78.ExchangeApdu](@ref Iso78_ExchangeApdu) to communicate with the
 * SAM.
 * 
 * To close the communication channel after data exchange, run
 * [Iso78.CloseSam](@ref Iso78_CloseSam).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] LID Logical SAM-ID (LID)
 * @param[out] SamHandle Identifier for SAM communication. Use this value in all subsequent calls of [Iso78.CloseSam](@ref Iso78_CloseSam) and [Iso78.ExchangeApdu](@ref Iso78_ExchangeApdu).
 * @param[out] ATR ATR (Answer To Reset) string of SAM
 * @param[out] ATR_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso78_OpenSam(brp_protocol protocol, brp_Iso78_OpenSam_LID LID, unsigned* SamHandle, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool);
/**
 * @anchor Iso78_CloseSam
 * This command closes a communication channel previously opened via the
 * [Iso78.OpenSam](@ref Iso78_OpenSam) command. It is recommended to call this
 * command before physically removing the SAM from its slot since it also powers
 * down the SAM module.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SamHandle Identifier for SAM communication (use _SAM_Handle_ value returned by the [Iso78.OpenSam](@ref Iso78_OpenSam) command).
 */
brp_errcode brp_Iso78_CloseSam(brp_protocol protocol, unsigned SamHandle);
/**
 * @anchor Iso78_ExchangeApdu
 * This command sends an APDU command on the currently selected and opened SAM
 * module using a logical ID. Please note that the complete APDU command
 * including the CLA, INS, P1, P2, Lc and Le values need part of the _SendData_
 * parameter.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SamHandle Identifier for SAM communication (use _SAM_Handle_ value returned by the [Iso78.OpenSam](@ref Iso78_OpenSam) command).
 * @param[in] SendData APDU command data including CLA, INS, P1, P2, Lc and Le.
 * @param[in] SendData_len 
 * @param[out] RecvData APDU response data.
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso78_ExchangeApdu(brp_protocol protocol, unsigned SamHandle, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
