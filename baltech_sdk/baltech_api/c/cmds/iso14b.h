/**
 * @file
 * @anchor Iso14b
 * This command group implements the low-level ISO 14443-3 (Type B) commands
 * according to the [ISO 14443-3 (Type B)
 * standard](https://www.iso.org/standard/50942.html)
 * 
 * A PICC compliant to ISO 14443-3 (Type B) is always in one of five states:
 * 
 *   1. Power off state 
 *   2. Idle state 
 *   3. Ready state 
 *   4. Active state 
 *   5. Halt state 
 * 
 * As long as the PICC is not present in the HF field of an antenna, it is in
 * _power off_ state. When the PICC gets into the HF field, it will switch to
 * _idle state_ automatically. The [Iso14b.Request](@ref Iso14b_Request) command
 * scans for PICCs in idle state and returns necessary information about them to
 * the host. Furthermore, this command will change the state of the detected
 * PICCs to _ready state_. The [Iso14b.Halt](@ref Iso14b_Halt) command can be used
 * to set PICCs from ready state to _halt state_ so that they do not respond to
 * conventional [Iso14b.Request](@ref Iso14b_Request) commands any longer. PICCs in
 * halt state can only be reactivated by setting a special parameter flag in the
 * [Iso14b.Request](@ref Iso14b_Request) command.
 * 
 * From ready state, one or more PICCs may be switched to the _active state_ via
 * the [Iso14b.Attrib](@ref Iso14b_Attrib) command. Not all PICCs support being in
 * active state while other PICCs are at the same time: such PICCs need to be
 * selected exclusively instead.
 * 
 * Communication with the PICC by means of APDU exchanges is subject to the ISO
 * 14443-4 standard which is explained in detail in the [_Iso14L4_ command group
 * documentation](@ref Iso14L4). Only PICCs in active state are able to
 * execute ISO 14443-4 commands. For proprietary PICCs which are not compliant to
 * the ISO 14443-4 standard, [Iso14b.TransparentCmd](@ref Iso14b_TransparentCmd)
 * should be used instead. It provides a raw communication channel between the
 * application and the PICC, without any interpretation of the transferred data
 * within the reader, thereby allowing to send/receive arbitrary request/response
 * data to/from the PICC.
 * 
 * After data exchange is completed, the PICC may automatically be switched to
 * halt state so that it does not respond to any command which may follow.
 * Depending on the PICC being compliant to the ISO 14443-4 standard or not,
 * either a special command of the [_Iso14L4_ command
 * group](@ref Iso14L4) or a proprietary card command transmitted via
 * [Iso14b.TransparentCmd](@ref Iso14b_TransparentCmd) have to be used for this
 * purpose. PICCs in halt state can only be reactivated by setting as special
 * parameter flag in the [Iso14b.Request](@ref Iso14b_Request) command.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ISO14B_H__
#define __BRP_BALTECH_API_CMDS_ISO14B_H__
#include "../typedefs.h"
/**
 * @anchor Iso14b_ErrNoTag
 * No card in field of antenna or card in field of antenna does not match given
 * VHL-file.
 */
#define BRP_Iso14b_ErrNoTag BRP_ERR_STATUS(0x1400, 0x01)
/**
 * @anchor Iso14b_ErrCollision
 * More than one PICC answered in the same time slot and none of them could
 * therefore be requested correctly. The [Iso14b.Request](@ref Iso14b_Request)
 * command needs to be called again, maybe with more time slots.
 */
#define BRP_Iso14b_ErrCollision BRP_ERR_STATUS(0x1400, 0x02)
/**
 * @anchor Iso14b_ErrAuth
 * Authentication error.
 */
#define BRP_Iso14b_ErrAuth BRP_ERR_STATUS(0x1400, 0x03)
/**
 * @anchor Iso14b_ErrHf
 * General HF error.
 */
#define BRP_Iso14b_ErrHf BRP_ERR_STATUS(0x1400, 0x04)
/**
 * @anchor Iso14b_ErrFrame
 * Bit error, parity error or frame error (start/stop bit).
 */
#define BRP_Iso14b_ErrFrame BRP_ERR_STATUS(0x1400, 0x07)
/**
 * @anchor Iso14b_ErrCrc
 * CRC checksum error.
 */
#define BRP_Iso14b_ErrCrc BRP_ERR_STATUS(0x1400, 0x08)
/**
 * @anchor Iso14b_ErrCom
 * Error in communication with reader chip.
 */
#define BRP_Iso14b_ErrCom BRP_ERR_STATUS(0x1400, 0x10)
/**
 * @anchor Iso14b_ErrEeprom
 * Error accessing EEPROM of the reader chip.
 */
#define BRP_Iso14b_ErrEeprom BRP_ERR_STATUS(0x1400, 0x21)
/**
 * @anchor Iso14b_ErrCardNotSupported
 * Reader chip does not support card type.
 */
#define BRP_Iso14b_ErrCardNotSupported BRP_ERR_STATUS(0x1400, 0x22)
/**
 * @anchor Iso14b_ErrMem
 * Either internal list of labels or response buffer full.
 */
#define BRP_Iso14b_ErrMem BRP_ERR_STATUS(0x1400, 0x23)
/**
 * @anchor Iso14b_ErrHwNotSupported
 * Command not supported by hardware.
 */
#define BRP_Iso14b_ErrHwNotSupported BRP_ERR_STATUS(0x1400, 0x24)
/**
 * @anchor Iso14b_Request
 * Scan for ISO 14443 (Type B) compliant PICCs in the field of the antenna.
 * 
 * If a collision occurred in at least one time slot (signaled by status code
 * ISO14B_COLLISION_ERR), this command needs to be called again with an increased
 * number of time slots so that more PICCs can be detected.
 * 
 * The ISO14B_MEM_ERR status code signals that more PICCs are available than can
 * be handled with the buffer provided by the reader for BRP communication. The
 * [Iso14b.Halt](@ref Iso14b_Halt) command can be used to disable undesired PICCs
 * before calling the Iso14b.Request command again.
 * 
 * PICCs that have been returned by this command may subsequently be switched to
 * the active state via the [Iso14b.Attrib](@ref Iso14b_Attrib) command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ReqAll If set, all PICCs (even those in halt state) will be requested.
 * @param[in] TimeSlots Number of time slots which should be used for requesting PICCs. The more PICCs are expected, the higher this value should be. In one time slot, at most one PICC may answer.
 * @param[in] AFI _Application Family Id_ (AFI)  Possible values: 0x00 .. 0x8F  The high nibble specifies the _application family_ , the low nibble the _sub- family_. Use 0x00 when scanning operations should detect all PICCs regardless of their AFI.  Possible values for the application family:    * 0x0: all    * 0x1: transport    * 0x2: financial    * 0x3: identification    * 0x4: telecommunication    * 0x5: medical    * 0x6: multimedia    * 0x7: gaming    * 0x8: data storage    * 0x9-0xF: rfu   Possible values for sub-family:    * 0x0: all sub-families    * 0x1 .. 0xF: specified sub-family
 * @param[out] ValueList 
 * @param[out] ValueList_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14b_Request(brp_protocol protocol, bool ReqAll, brp_Iso14b_Request_TimeSlots TimeSlots, unsigned AFI, brp_Iso14b_Request_ValueList_Entry** ValueList, size_t* ValueList_len, brp_mempool *mempool);
/**
 * @anchor Iso14b_Attrib
 * Select the PICC with given _PUPI_ serial number for further communication. The
 * desired PICC must have been reported by the [Iso14b.Request](@ref Iso14b_Request)
 * command before.
 * 
 * The parameters given in the _Param_ bit mask have to match both the supported
 * communication parameters of the reader and of the current PICC, according to
 * the _ProtInfo_ bit mask returned by the [Iso14b.Request](@ref Iso14b_Request)
 * command. These parameters will be applied for all ISO 14443-4 APDUs that will
 * be exchanged via the [Iso14L4.ExchangeAPDU](@ref Iso14L4_ExchangeAPDU) command.
 * 
 * Furthermore, a unique communication channel ID (CID) has to be assigned, which
 * identifies the PICC and which will also be needed by the ISO 14443-4 commands.
 * 
 * Normally, there may be up to 14 PICCs in active state at the same time and
 * each PICC will be uniquely identified by its CID. However, there are exist
 * PICCs which do no support being assigned a CID. Only one of these PICCs may be
 * in active state at the same time (along with other PICCs supporting the CID
 * feature). The same restriction also holds for PICCs which are assigned a CID
 * of 0x00 with this command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PUPI _Pseudo-Unique PICC Identifier_ (PUPI), serial number of targeted PICC.
 * @param[in] TR0 PICC's minimum delay before responding after the end of a command sent by PCD. The values introduced in this parameter need to be divided by the ISO 14443 subcarrier frequency (abbreviated as _fs_).
 * @param[in] TR1 Minimum delay between subcarrier modulation start and beginning of data transmission. The values introduced in this parameter need to be divided by the ISO 14443 subcarrier frequency (abbreviated as _fs_).
 * @param[in] EOF_ _End Of Frame_ (EOF) flag for sending data to reader.
 * @param[in] SOF _Start Of Frame_ (SOF) flag for sending data to reader.
 * @param[in] DSI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] DRI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] FSDI _Frame Size proximity coupling Device Integer_ (FSDI) value. This value is mapped to the Frame Size proximity coupling Device (FSD) value, which indicates the maximum frame size accepted by the PCD.  **The current Baltech reader supports FSD of at least up to 64 bytes (FSDI=0x05). It is not recommended to use a smaller FSDI. Future versions of the Baltech reader might support higher FSDI values.**
 * @param[in] CID _Channel ID_ (CID) which should be assigned to this PICC. Possible values:    * 0x00: PICC will respond also to ISO 14443-4 commands with CID disabled    * 0x01-0x0E: valid CID value    * 0x0F-0xFF: rfu
 * @param[in] EnHLR If this flag is set, the _High Layer Response_ (HLR) variable will be returned by this command.
 * @param[in] EnMBLI If this flag is set, the _Maximum Buffer Length Index_ (MBLI) variable will be returned by this command.
 * @param[in] EnCID If this flag is set, the CID of the PICC will be returned by this command.
 * @param[out] AssignedCID _Channel ID_ (CID) which has been assigned to the PICC. If the PICC does not support the feature of being assigned a CID, 0x00 will be returned instead. Possible values:    * 0x00: PICC will respond also to ISO 14443-4 commands with CID disabled    * 0x01-0x0E: valid CID value    * 0x0F-0xFF: rfu
 * @param[out] MBLI _Maximum Buffer Length Index_ (MBLI) of PICC. This value is necessary to compute the _Maximum Buffer Length_ (MBL) value, describing the length of the PICC's internal buffer to receive chained frames. MBL is computed using MBLI using the following formula:  MBL = FSC * 2 ^ (MBLI-1)  The FSC variable is determined by the FSCI value returned by the [Iso14b.Request](@ref Iso14b_Request) command.  The amount of data transferred with one call of the [Iso14L4.ExchangeAPDU](@ref Iso14L4_ExchangeAPDU) command should never exceed MBL.  Possible values:    * 0x00: PICC does not provide MBLI    * 0x01-0x0F: valid MBLI value    * 0x10-0xFF: rfu
 * @param[out] HLR _Higher Layer Response_ (HLR) or PICC.  **The HLR is not available from PICCs fully compliant to the ISO 14443-3 standard.**
 * @param[out] HLR_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14b_Attrib(brp_protocol protocol, brp_buf PUPI, brp_Iso14b_Attrib_TR0 TR0, brp_Iso14b_Attrib_TR1 TR1, brp_Iso14b_Attrib_EOF_ EOF_, brp_Iso14b_Attrib_SOF SOF, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_Iso14b_Attrib_FSDI FSDI, unsigned CID, bool EnHLR, bool EnMBLI, bool EnCID, unsigned* AssignedCID, unsigned* MBLI, brp_buf* HLR, size_t* HLR_len, brp_mempool *mempool);
/**
 * @anchor Iso14b_Halt
 * Switch the PICC with the given _PUPI_ serial number into halt state, so that
 * it will not answer to further [Iso14b.Request](@ref Iso14b_Request) commands,
 * except when the _ReqAll_ flag parameter of the
 * [Iso14b.Request](@ref Iso14b_Request) command is set. The memory occupied by this
 * PICC's information will also be freed, which makes it is available for future
 * calls of the [Iso14b.Request](@ref Iso14b_Request) command. Use this command in
 * order to deactivate some of the PICCs in case the
 * [Iso14b.ErrMem](@ref Iso14b_ErrMem) status code has been returned by the last
 * call of [Iso14b.Request](@ref Iso14b_Request).
 * 
 * **This command only works for PICCs in ready state. For PICCs in active state,
 * the[ Iso14L4.Deselect](@ref Iso14L4_Deselect) command should be used
 * instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PUPI _Pseudo-Unique PICC Identifier_ (PUPI) of the tag that should go into halt mode.
 */
brp_errcode brp_Iso14b_Halt(brp_protocol protocol, brp_buf PUPI);
/**
 * @anchor Iso14b_SetTransparentSettings
 * **This command is obsolete and included here only for compatibility reasons.
 * Please use the[ Iso14b.TransparentCmd](@ref Iso14b_TransparentCmd) command
 * instead.**
 * 
 * Sets reader chip configuration. If this command is not called, default
 * parameters will be used.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Tags 
 * @param[in] Tags_len 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso14b_SetTransparentSettings(brp_protocol protocol, brp_Iso14b_SetTransparentSettings_Tags_Entry* Tags, size_t Tags_len);
/**
 * @anchor Iso14b_GetTransparentSettings
 * **This command is obsolete and included here only for compatibility reasons.
 * Please use the[ Iso14b.TransparentCmd](@ref Iso14b_TransparentCmd) command
 * instead.**
 * 
 * Gets reader chip configuration.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Tags 
 * @param[out] Tags_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso14b_GetTransparentSettings(brp_protocol protocol, brp_Iso14b_GetTransparentSettings_Tags_Entry** Tags, size_t* Tags_len, brp_mempool *mempool);
/**
 * @anchor Iso14b_TransparentCmd
 * This command sends a data stream to a card and returns the communication
 * status and the received card data stream to the host.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnCRCRX Enable CRC check over received data.
 * @param[in] EnCRCTX Enable CRC over transmitted data.
 * @param[in] SendDataLen Number of bytes to send.
 * @param[in] Timeout Timeout in ms between sending the last bit to the card and receiving the first bit from the card.
 * @param[in] DSI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] DRI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] SendData Data to transmit.  **Bits will always be transferred LSB first.**
 * @param[in] SendData_len 
 * @param[out] RecvData Returned data.
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14b_TransparentCmd(brp_protocol protocol, unsigned EnCRCRX, unsigned EnCRCTX, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
