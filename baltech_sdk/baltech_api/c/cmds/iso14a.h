/**
 * @file
 * @anchor Iso14a
 * This command group implements the low-level ISO 14443-3 (Type A) commands
 * according to the [ISO 14443-3 (Type A)
 * standard](https://www.iso.org/standard/50942.html).
 * 
 * A PICC compliant to ISO 14443-3 (Type A) is always in one of five states:
 * 
 *   1. Power off state 
 *   2. Idle state 
 *   3. Ready state 
 *   4. Active state 
 *   5. Halt state 
 * 
 * As long as the PICC is not present in the HF field, it is in _power off_
 * state. When the PICC gets into the field of the antenna, it automatically
 * switches to the _idle state_. Once the [Iso14a.Request](@ref Iso14a_Request)
 * command is invoked, PICCs in idle state will switch to the _ready state_. From
 * there, a certain PICC, only one at the same time, may be switched to the
 * _active state_ via the [Iso14a.Select](@ref Iso14a_Select) command. This
 * mechanism is identical for all ISO 14443 Type A PICCs.
 * 
 * PICC communication by means of APDU exchanges is subject to the ISO 14443-4
 * standard which is explained in detail in the [_Iso14L4_ command group
 * documentation](@ref Iso14L4). Only PICCs which are compliant to ISO
 * 14443-4 are able to execute commands transmitted according to ISO 14443-4,
 * providing these PICCs are in the active state. However, before the first APDU
 * exchange can be performed, the command
 * [Iso14a.RequestATS](@ref Iso14a_RequestATS) has to be executed in order to enable
 * the ISO 14443-4 mode in the PICC. The command
 * [Iso14a.PerformPPS](@ref Iso14a_PerformPPS) can be optionally invoked after
 * [Iso14a.RequestATS](@ref Iso14a_RequestATS) in order to increase communication
 * speed.
 * 
 * For proprietary PICCs that are not compliant to the [ISO 14443-4
 * standard](http://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=70172),
 * the command [Iso14a.TransparentCmd](@ref Iso14a_TransparentCmd) should be used
 * for communication. It provides a raw communication channel between application
 * and PICC, without any interpretation of the transferred data within the
 * reader, and therewith allows to send/receive arbitrary command/response data
 * to/from the PICC.
 * 
 * After data exchange is completed, the PICC may be switched to the halt state
 * so that it will not respond to any command which may follow. Depending on the
 * PICC being in 14443-4 mode or not, either a special command of the [ISO
 * 14443-4 command group](@ref Iso14L4) or the
 * [Iso14a.Halt](@ref Iso14a_Halt) command have to be used for this purpose. PICCs
 * in halt state can only be reactivated by setting as special flag in the
 * [Iso14a.Request](@ref Iso14a_Request) command.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ISO14A_H__
#define __BRP_BALTECH_API_CMDS_ISO14A_H__
#include "../typedefs.h"
/**
 * @anchor Iso14a_ErrNoTag
 * No card in field of antenna or card in field of antenna does not match the
 * given VHL-file.
 */
#define BRP_Iso14a_ErrNoTag BRP_ERR_STATUS(0x1300, 0x01)
/**
 * @anchor Iso14a_ErrCollision
 * More than one PICC answered in the same time slot and none of them could
 * therefore be requested correctly.
 * 
 * **In case this status code is returned by the[
 * Iso14a.Request](@ref Iso14a_Request) command, when two or more ISO 14443 Type A
 * PICCs of different types (e.g. one Mifare Classic card and one Mifare DESFire
 * card) are present in the HF field of the reader, the AQTA response will still
 * be returned and the card selection procedure can be continued normally with
 * the[ Iso14a.Select](@ref Iso14a_Select) command.**
 */
#define BRP_Iso14a_ErrCollision BRP_ERR_STATUS(0x1300, 0x02)
/**
 * @anchor Iso14a_ErrHf
 * General HF error.
 */
#define BRP_Iso14a_ErrHf BRP_ERR_STATUS(0x1300, 0x04)
/**
 * @anchor Iso14a_ErrKey
 * Key error (Only triggered by Mifare authentication).
 */
#define BRP_Iso14a_ErrKey BRP_ERR_STATUS(0x1300, 0x06)
/**
 * @anchor Iso14a_ErrFrame
 * Bit error, Parity error or Frame error (start/stop bit).
 */
#define BRP_Iso14a_ErrFrame BRP_ERR_STATUS(0x1300, 0x07)
/**
 * @anchor Iso14a_ErrCrc
 * CRC checksum error.
 */
#define BRP_Iso14a_ErrCrc BRP_ERR_STATUS(0x1300, 0x08)
/**
 * @anchor Iso14a_ErrCom
 * Error in communication with reader chip.
 */
#define BRP_Iso14a_ErrCom BRP_ERR_STATUS(0x1300, 0x10)
/**
 * @anchor Iso14a_ErrEeprom
 * Error accessing EEPROM of the reader chip.
 */
#define BRP_Iso14a_ErrEeprom BRP_ERR_STATUS(0x1300, 0x21)
/**
 * @anchor Iso14a_ErrCardNotSupported
 * Reader chip does not support card type.
 */
#define BRP_Iso14a_ErrCardNotSupported BRP_ERR_STATUS(0x1300, 0x22)
/**
 * @anchor Iso14a_ErrHwNotSupported
 * Command not supported by hardware.
 */
#define BRP_Iso14a_ErrHwNotSupported BRP_ERR_STATUS(0x1300, 0x23)
/**
 * @anchor Iso14a_BreakErr
 * Command has been interrupted.
 */
#define BRP_Iso14a_BreakErr BRP_ERR_STATUS(0x1300, 0x30)
/**
 * @anchor Iso14a_RequestLegacy
 * This commands scans for ISO 14443-3 (Type A) compliant PICCs in the field of
 * the antenna.
 * 
 * If the _ReqAll_ parameter flag is set, both PICCs in idle state and PICCs in
 * halt state will be switched to ready state. If this flag is not set, only
 * PICCs in idle state will be switched to ready state.
 * 
 * **Only PICCs in ready state may be selected via the[
 * Iso14a.Select](@ref Iso14a_Select) command.**
 * 
 * **This command may return the[ Iso14a.ErrCollision](@ref Iso14a_ErrCollision)
 * status code when executed successfully, in case two or more PICCs of different
 * types are present in the HF field of the reader. In this case, the selection
 * PICC procedure can be carried out normally with the[
 * Iso14a.Select](@ref Iso14a_Select) command.**
 * 
 * This command covers the commands REQA and WAKE-UP as specified by the ISO
 * 14443-3 standard.
 * 
 * **For new applications, the command[ Iso14a.Request](@ref Iso14a_Request) should
 * be used instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ReqAll If enabled, all PICCs (even those in halt state) will be requested.
 * @param[out] UIDSize Length of "Unique IDentifier" (UID). The UID may be either a fixed number or a number generated randomly by the PICC (and therefore not unique!).
 * @param[out] Coll If any bit set, a collision occurred
 * @param[out] ProprietaryCoding Proprietary coding.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso14a_RequestLegacy(brp_protocol protocol, bool ReqAll, brp_Iso14a_RequestLegacy_UIDSize* UIDSize, unsigned* Coll, unsigned* ProprietaryCoding);
/**
 * @anchor Iso14a_Select
 * This command Performs the anti-collision and selection sequence of a PICC in
 * the field of the antenna. The PICC has to be in ready state (see
 * [Iso14a.Request](@ref Iso14a_Request) command) for this command to succeed.
 * 
 * PICCs exist with three different lengths of serial numbers:
 * 
 *   * Four bytes (single size) 
 *   * Seven bytes (double size) 
 *   * Ten bytes (triple size) 
 * 
 * In manual anti-collision mode, the Iso14a.Select command can only return 4
 * Bytes of the serial number at a time, in the _Serial_ returned variable.
 * Iso14a.Select therefore needs to be called one, two or three times to read
 * serial numbers of single, double or triple size, respectively. Each call of
 * the Iso14a.Select command is associated to a specific _cascade level_ ,
 * specified by the _CascLev_ parameter. The first call of Iso14a.Select is
 * associated to cascade level 1, the second call to cascade level 2, and the
 * third call to cascade level 3.
 * 
 * The fact that a serial number has not been completely returned by the
 * Iso14a.Select command is indicated by a _cascade tag_ (CT, 0x88), in the first
 * byte of the returned _Serial_ variable. In this case, the Iso14a.Select
 * command needs to be called with the next higher cascade level (for instance
 * _CascLev_ = 2 if Iso14a.Select was called with _CascLev_ = 1). The complete
 * serial number of a PICC consists then of the concatenation of the (up to 3)
 * returned values of _Serial_ , after removing the cascade tags(s) from these
 * values. A completed selection flow is signaled by the _Casc_ flag in the _SAK_
 * byte and by the missing cascade tag in the returned serial number.
 * 
 * Using the _PreSelSer_ parameter, the serial number (or an initial part of it)
 * of a given PICC can be specified to be selected within a specific cascade
 * level (up to four bytes) in order to speed up the anti-collision sequence. The
 * CT must be included in _PreSelSer_ if it belongs to non-final parts of the
 * serial number.
 * 
 * For convenience reasons, an automatic anti-collision mode has been
 * implemented. This mode can be activated by setting the _CascLev_ parameter to
 * 0. In this case, the PICC can be selected with a single call of Iso14a.Select
 * and the returned _Serial_ variable contains the complete serial number,
 * without cascade tag(s).
 * 
 * **In this case, cascade tags must be manually added to the _PreSelSer_
 * parameter to be able to use the preselection feature.**
 * 
 * This command combines the commands ANTICOLL and SELECT as specified in the ISO
 * 14443-3 (Type A) standard.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CascLev Selects cascade level of anti-collision sequence:    * 0: complete serial number    * 1, 2 or 3: cascade level 1, 2 or 3
 * @param[in] BitCount Number of valid bits in _PreSelSer_ (0 - 96).
 * @param[in] PreSelSer Part of serial number (beginning at its head), which will be used for the preselection of a PICC.
 * @param[in] PreSelSer_len 
 * @param[out] SAK Select Acknowledge (SAK), according to the ISO 14443-3 (Type A) standard.
 * @param[out] Serial Serial number of selected label.
 * @param[out] Serial_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_Select(brp_protocol protocol, unsigned CascLev, unsigned BitCount, brp_buf PreSelSer, size_t PreSelSer_len, unsigned* SAK, brp_buf* Serial, size_t* Serial_len, brp_mempool *mempool);
/**
 * @anchor Iso14a_Halt
 * Switch PICC to halt state.
 * 
 * The PICC has to be selected before it may be switched to halt state.
 * 
 * **This command only works for PICCs that are, though in active state, not in
 * ISO 14443-4 mode. For such PICCs, the[ Iso14L4.Deselect](@ref Iso14L4_Deselect)
 * command should be used instead.**
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Iso14a_Halt(brp_protocol protocol);
/**
 * @anchor Iso14a_RequestATS
 * This command requests the Answer to Select (ATS) of the PICC according to the
 * ISO 14443-3 (Type A) standard.
 * 
 * RequestATS has to be called by the PCD (reader) directly after a successful
 * call of the [Iso14a.Select](@ref Iso14a_Select) command if
 * 
 *   1. The selected PICC is ISO 14443-4 compliant (according to _SAK_ byte) and 
 *   2. communication as specified by ISO 14443-4 shall be performed via the [Iso14L4.ExchangeAPDU](@ref Iso14L4_ExchangeAPDU) command. 
 * 
 * Since it is possible to keep several PICCs in active state at the same time
 * according to ISO 14443-4, a unique CID has to be assigned to each of them.
 * However, if you only want to communicate with a single label at a given time,
 * the value 0 should be assigned to the _CID_ variable. In this case, it is
 * possible to call the
 * [Iso14L4.ExchangeAPDU](@ref Iso14L4_ExchangeAPDU) command without
 * bothering about CIDs.
 * 
 * Please refer to the [Iso14a.PerformPPS](@ref Iso14a_PerformPPS) and
 * [Iso14L4.ExchangeAPDU](@ref Iso14L4_ExchangeAPDU) command
 * descriptions for more information about frame sizes and timing issues.
 * 
 * After successful execution of this command, the communication parameters can
 * be tuned with the [Iso14a.PerformPPS](@ref Iso14a_PerformPPS) command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FSDI _Frame Size proximity coupling Device Integer_ (FSDI) value. This value is mapped to the Frame Size proximity coupling Device (FSD) value, which indicates the maximum frame size accepted by the PCD.  **The current Baltech reader supports FSD of at least up to 64 bytes (FSDI=0x05). It is not recommended to use a smaller FSDI. Future versions of the Baltech reader might support higher FSDI values.**
 * @param[in] CID Channel ID which shall be assigned to this PICC. Possible values:    * 0x00: PICC will also respond to ISO 14443-4 commands with CID disabled.    * 0x01-0x0E: valid CID value.    * 0x0F-0xFF: rfu.
 * @param[out] ATS Answer To Selection (ATS) of the PICC. This field has a variable length up to 32 Bytes according to the ISO 14443-4 standard.
 * @param[out] ATS_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_RequestATS(brp_protocol protocol, brp_Iso14a_RequestATS_FSDI FSDI, unsigned CID, brp_buf* ATS, size_t* ATS_len, brp_mempool *mempool);
/**
 * @anchor Iso14a_PerformPPS
 * This command sets up the communication parameters for ISO 14443-4 commands.
 * 
 * Iso14a.PerformPPS may be used to change the default communication parameters
 * in order to achieve faster HF communication. This command has to be executed
 * directly after the [Iso14a.RequestATS](@ref Iso14a_RequestATS) command but it is
 * not necessary to execute it at all.
 * 
 * This command covers the PPS command as specified by ISO 14443-3 (type A).
 * 
 * The _PPS1_ bit mask is only sent to the PICC if DSI or DRI differ from the
 * current settings.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CID _Channel ID_ (CID) assigned to this PICC.  Possible values:    * 0x00: PICC will respond to ISO 14443-4 commands with CID disabled.    * 0x01-0x0E: valid CID value.    * 0x0F-0xFF: rfu.
 * @param[in] DSI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] DRI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 */
brp_errcode brp_Iso14a_PerformPPS(brp_protocol protocol, unsigned CID, brp_DivisorInteger DSI, brp_DivisorInteger DRI);
/**
 * @anchor Iso14a_Request
 * This commands scans for ISO 14443-3 (Type A) compliant PICCs in the field of
 * the antenna.
 * 
 * If the _ReqAll_ parameter flag is set, both PICCs in idle state and PICCs in
 * halt state will be switched to ready state. If this flag is not set, only
 * PICCs in idle state will be switched to ready state.
 * 
 * **Only PICCs in ready state may be selected via the[
 * Iso14a.Select](@ref Iso14a_Select) command.**
 * 
 * This command covers the commands REQA and WAKE-UP as specified by the ISO
 * 14443-3 standard.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ReqAll If enabled, all PICCs (even those in halt state) will be requested.
 * @param[out] ATQA Answer to request of type A (ATQA), according to the ISO 14443-3 standard.
 * @param[out] Collision True if a Collision was detected.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_Request(brp_protocol protocol, bool ReqAll, brp_buf* ATQA, bool* Collision, brp_mempool *mempool);
/**
 * @anchor Iso14a_Anticoll
 * This command performs an anti-collision sequence.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BitCount Number of preselected bits.
 * @param[in] PreSelectedSnr Part of serial number which will be used for a preselection of cards.
 * @param[out] SelectedSnr Serial number of selected label.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelectedSnr, brp_buf* SelectedSnr, brp_mempool *mempool);
/**
 * @anchor Iso14a_SelectOnly
 * This command selects a PICC with a 4 Byte serial number.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Snr Serial number of card.
 * @param[out] SAK Select Acknowledge (SAK), according to the ISO 14443-3 (Type A) standard.
 */
brp_errcode brp_Iso14a_SelectOnly(brp_protocol protocol, brp_buf Snr, unsigned* SAK);
/**
 * @anchor Iso14a_TransparentCmd
 * This command sends a data stream to a card and returns the communication
 * status and the received card data stream to the host.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnMifBwProt Enables Mifare backwards compatibility protocol:    * Data bytes sent to the card are counted in Bytes, and bits 0..3 of _Mode_ bit mask are taken into account.    * Data bytes received from the card are counted in Bytes, 4 bit error codes (Mifare, Mifare+) are counted as one byte.    * First data byte in answer (byte 2) specifies data type: 0x00 for normal data, 0x01 for 4 bit error codes.
 * @param[in] EnBitmode Enable bit mode used for anti-collision sequence (send single bits instead of whole bytes). When this flag is set, the _EnParity_ , _ParityMode_ , _EnCRCTX_ , and _EnCRCRX_ flags will be automatically disabled by the reader and therefore will have no effect. _SendDataLen_ and _RcvDataLen_ are interpreted in bits instead of bytes.
 * @param[in] EnCRCRX Enable CRC check over received data.
 * @param[in] EnCRCTX Enable CRC check over transmitted data.
 * @param[in] ParityMode Toggle even/odd parity mode. ISO 14443 (Type A) uses odd parity. Possible values are 0 (even parity) and 1 (odd parity).
 * @param[in] EnParity Parity generation is enabled when this flag is set.
 * @param[in] SendDataLen Number of bytes to send.
 * @param[in] Timeout Timeout in ms between sending the last bit to the card and receiving the first bit from the card.
 * @param[in] DSI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] DRI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] SendData Data to send  **Bits will always be transferred LSB first.**
 * @param[in] SendData_len 
 * @param[out] RcvData Returned data
 * @param[out] RcvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_TransparentCmd(brp_protocol protocol, bool EnMifBwProt, bool EnBitmode, bool EnCRCRX, bool EnCRCTX, bool ParityMode, bool EnParity, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, brp_buf* RcvData, size_t* RcvData_len, brp_mempool *mempool);
/**
 * @anchor Iso14a_TransparentCmdBitlen
 * This command is similar to _Iso14a.TransparentCmd_. The difference is that the
 * length of data to send is given in bits instead of bytes.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnHighBaudOld Use high bit rates type A as specified in [ISO 14443-2 Amendment Part 2](https://www.iso.org/obp/ui/#iso:std:iso-iec:14443:-2:ed-2:v1:amd:2:v1:en).
 * @param[in] EnParTx If this bit is set in combination with _EnBitMode_ , parity generation in Tx direction (PCD to PICC) will be done by the PCD.
 * @param[in] SendDataLen Number of bits to send
 * @param[in] Timeout Timeout in ms between sending the last bit to the card and receiving the first bit from the card.
 * @param[in] DSI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] DRI _Divisor Send/Receive Integer_ (DSI/DRI)  This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which determines bit rate for sending data from PICC to PCD. The possible DS/DR values (mapped to the DSI/DRI index) are listed below.
 * @param[in] SendData Data to send  **Bits will always be transferred LSB first.**
 * @param[in] SendData_len 
 * @param[out] RecvDataLen Returned data length in bit.
 * @param[out] CollisionPosition Position of bit where first collision occurred.
 * @param[out] RecvData Data to send  **Bits will always be transferred LSB first.**
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso14a_TransparentCmdBitlen(brp_protocol protocol, bool EnHighBaudOld, bool EnParTx, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, unsigned* RecvDataLen, unsigned* CollisionPosition, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
