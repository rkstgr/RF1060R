/**
 * @file
 * @anchor Iso15
 * The _ISO 15693_ command group contains commands for communication with labels
 * compatible to the ISO 15693 standard. This document does not replace the
 * [official ISO 15693
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467). It
 * is rather meant to be used in combination with it.
 * 
 * The Baltech reader understands the so-called _mandatory_ and _optional
 * commands_ as well as _custom commands_ for some label types. However, custom
 * commands are not documented in this page.
 * 
 * In order to communicate with an ISO 15693 compatible label, it is necessary to
 * know its UID. Every command sent to the reader uses the UID to address the
 * label. This is very important to guarantee that only one label reacts to the
 * command. A command may also be executed without specifying a UID if it is
 * certain that only one label is present in the reader's HF field. However, it
 * is most of the time difficult to know how many labels are present within the
 * antenna's field at a given time. Thus, it is advisable to execute the
 * [Iso15.GetUIDList](@ref Iso15_GetUIDList) command before starting to communicate
 * with the label. This command returns a list of available labels along with
 * their UIDs.
 * 
 * The [Iso15.StayQuiet](@ref Iso15_StayQuiet) command may be used to set a certain
 * label to _quiet-state_ , i.e. to keep the label from answering to subsequent
 * calls of the [Iso15.GetUIDList](@ref Iso15_GetUIDList) command. This may be
 * useful when a label has been fully processed and the application wants to scan
 * for other labels that may also be available in the reader's HF field at the
 * same time. The opposite command which sets a label back to _ready-state_ is
 * [Iso15.ResetToReady](@ref Iso15_ResetToReady). The addressed label will then
 * answer again to subsequent calls of [Iso15.GetUIDList](@ref Iso15_GetUIDList).
 * 
 * Once the UID of a specific label is known (e.g. by executing
 * [Iso15.GetUIDList](@ref Iso15_GetUIDList)), there are three options to
 * communicate with this label. The communication mode needs to be chosen using
 * the [Iso15.SetMode](@ref Iso15_SetMode) command. All subsequent commands
 * performing communication with the label will then use this mode. If a
 * different label must be addressed, [Iso15.SetMode](@ref Iso15_SetMode) has to be
 * called again. The three possible communication modes are:
 * 
 *   * _Addressed mode_ : The 8 byte UID of the label is used to address a distinct label. In this mode, the UID is included in each command frame sent to the label. 
 *   * _Selected mode_ : A label in selected mode responds to commands received from the reader without the need to transfer the UID in each command. Attention: This mode is optional and not supported by all types of ISO 15693 labels. 
 *   * _Unaddressed mode_ : If it is sure that only one label is in the field of the antennas you may execute commands in the unaddressed mode as well. Attention: All labels currently in the reader's antenna field will respond to commands when using this mode. 
 * 
 * The memory of labels compliant to ISO 15693 is organized as a sequence of
 * blocks where the block-size is fixed for a certain type of label. The default
 * length of a block is four byte. Each block can be directly accessed and the
 * available commands for data exchange, mainly [ReadBlock](@ref Iso15_ReadBlock)
 * and [WriteBlock](@ref Iso15_WriteBlock), are generally designed to handle one
 * block per call. [GetSystemInformation](@ref Iso15_GetSystemInformation) retrieves
 * general information about a specific label.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ISO15_H__
#define __BRP_BALTECH_API_CMDS_ISO15_H__
#include "../typedefs.h"
/**
 * @anchor Iso15_ErrNoTag
 * No label in field of antenna.
 */
#define BRP_Iso15_ErrNoTag BRP_ERR_STATUS(0x2100, 0x01)
/**
 * @anchor Iso15_ErrCollision
 * This status code is triggered by two events:
 * 
 *   * A collision between two or more labels occurred. 
 *   * DSFID different - cannot resolve collision.
 */
#define BRP_Iso15_ErrCollision BRP_ERR_STATUS(0x2100, 0x02)
/**
 * @anchor Iso15_ErrHf
 * General HF Error.
 */
#define BRP_Iso15_ErrHf BRP_ERR_STATUS(0x2100, 0x04)
/**
 * @anchor Iso15_ErrLabel
 * Label status error.
 */
#define BRP_Iso15_ErrLabel BRP_ERR_STATUS(0x2100, 0x05)
/**
 * @anchor Iso15_ErrCom
 * Error in communication to reader chip.
 */
#define BRP_Iso15_ErrCom BRP_ERR_STATUS(0x2100, 0x10)
/**
 * @anchor Iso15_ErrCmd
 * Command and/or parameters invalid.
 */
#define BRP_Iso15_ErrCmd BRP_ERR_STATUS(0x2100, 0x20)
/**
 * @anchor Iso15_ErrParamNotSupported
 * Reader chip does not support label type parameters.
 */
#define BRP_Iso15_ErrParamNotSupported BRP_ERR_STATUS(0x2100, 0x23)
/**
 * @anchor Iso15_ErrMem
 * Either internal list of labels or response buffer full.
 */
#define BRP_Iso15_ErrMem BRP_ERR_STATUS(0x2100, 0x24)
/**
 * @anchor Iso15_ErrLabelBlocksize
 * The blocks requested are not equal in size (Read multiple blocks).
 */
#define BRP_Iso15_ErrLabelBlocksize BRP_ERR_STATUS(0x2100, 0x25)
/**
 * @anchor Iso15_ErrHwNotSupported
 * Command not supported by hardware.
 */
#define BRP_Iso15_ErrHwNotSupported BRP_ERR_STATUS(0x2100, 0x26)
/**
 * @anchor Iso15_SetParam
 * This command configures the reader chip. If a parameter is not supported, a
 * status message is returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ModulationIndex Toggle modulation index 100% (0) /10% (1)
 * @param[in] TXMode Toggle 1 out of 256 (0) / 1 out of 4 (1) TX mode
 * @param[in] HighDataRate Toggle low (0) /high (1) data rate VICC
 * @param[in] DualSubcarrier Toggle single (0) /dual (1) subcarrier VICC
 */
brp_errcode brp_Iso15_SetParam(brp_protocol protocol, bool ModulationIndex, bool TXMode, bool HighDataRate, bool DualSubcarrier);
/**
 * @anchor Iso15_GetParam
 * This command reads the configuration of the reader chip.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ModulationIndex Toggle modulation index 100% (0) /10% (1)
 * @param[out] TXMode Toggle 1 out of 256 (0) / 1 out of 4 (1) TX mode
 * @param[out] HighDataRate Toggle low (0) /high (1) data rate VICC
 * @param[out] DualSubcarrier Toggle single (0) /dual (1) subcarrier VICC
 */
brp_errcode brp_Iso15_GetParam(brp_protocol protocol, unsigned* ModulationIndex, unsigned* TXMode, unsigned* HighDataRate, unsigned* DualSubcarrier);
/**
 * @anchor Iso15_GetUIDList
 * This command scans for ISO 15693 labels which are in the field of the readers
 * antenna and which are not in _quiet-state_. The list of UIDs is returned in
 * the response frame. Furthermore, the DSFID is send back if the _DSFID_ flag in
 * _Mode_ is set.
 * 
 * If the _More_ response value is different from zero, there are more tags to
 * scan, and Iso15.GetUIDList has to be called again with the _NextBlock_ flag
 * set to get the rest of the labels which have not been transferred within this
 * frame.
 * 
 * To optimize the label scanning time, the reader should be told if there are
 * many labels (more than 2 or 3) in the antenna's field. In this case, the
 * _En16Slots_ flag should be set. This bit will tell Iso15.GetUIDList to send
 * the inventory with 16 time slots instead of one.
 * 
 * Furthermore the _Autoquiet_ flag can be set to put every label into _quiet-
 * state_ after a successful scan. This will result in a kind of incremental
 * behaviour from Iso15.GetUIDList since after the first successful
 * Iso15.GetUIDList call, all following Iso15.GetUIDList calls will only return
 * labels which came into the field of the antenna after the last call.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnAFI EnAFI (bool): AFI byte shall be transmitted
 * @param[in] NextBlock NextBlock (bool): Scan for additional labels in HF field
 * @param[in] AutoQuiet AutoQuiet (bool): Enable auto-quiet mode
 * @param[in] EnDSFID DSFID (bool): Enable DSFID see response
 * @param[in] En16Slots 16Slots (bool): Enable 16 time-slots
 * @param[in] AFI Application Family Identifier. EnAFI flag in _Mode_ Byte has to be set, if AFI shall be used.
 * @param[out] More If set, then more than Num labels are in the field of antenna.
 * @param[out] Labels 
 * @param[out] Labels_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_GetUIDList(brp_protocol protocol, bool EnAFI, bool NextBlock, bool AutoQuiet, bool EnDSFID, bool En16Slots, unsigned AFI, unsigned* More, brp_Iso15_GetUIDList_Labels_Entry** Labels, size_t* Labels_len, brp_mempool *mempool);
/**
 * @anchor Iso15_SetMode
 * This command configures the mode to address a label.
 * 
 *   * _Unaddressed mode_ : The following label commands are sent to the label without an UID (broadcast). This implies that not more than one label should be in the antenna's field because every label is responding in this mode which would result in a collision. 
 *   * _Addressed mode_ : The following label commands are sent to the label including the UID given in _UID_. To talk to one distinct label among others, the Iso15.SetMode command has to be called with a value of 0x01 in the _Mode_ byte before execution of other label commands. 
 *   * _Selected mode_ : Useful if a lot of operations need to be performed with the same label since the UID is not transferred to the label over and over again. A Iso15.SetMode command with _Mode_ 0x02 implicitly executes a _Select_ command with the corresponding UID as parameter (see the [ISO 1593-3 standard](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467) for details). A previously selected label will be deselected automatically if a Iso15.SetMode command with Mode 0x02 and a different UID or a Iso15.SetMode command with Mode unequal 0x02 is executed. If a Iso15.SetMode command with Mode 0x02 fails, the reader remains in the unaddressed mode. 
 * 
 * **Please be aware that not all label types support all modes.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode 0x00: Unadressed mode, 0x01: adressed mode (default), 0x02: Selected mode
 * @param[in] UID Unique ID of label; only for addressed -/selected mode.
 */
brp_errcode brp_Iso15_SetMode(brp_protocol protocol, unsigned Mode, brp_buf UID);
/**
 * @anchor Iso15_StayQuiet
 * This command puts a label into the _quiet-state_. This command shall always be
 * executed in addressed mode (see the [Iso15.SetMode](@ref Iso15_SetMode) command).
 * After executing this command, the label will not response to any
 * [Iso15.GetUIDList](@ref Iso15_GetUIDList) command until its state machine is
 * reset (either by a physical HF-reset (i.e. switching off the field of the
 * antenna or taking the label out of the field) or by executing the commands
 * [Iso15.ResetToReady](@ref Iso15_ResetToReady) or [Iso15.SetMode](@ref Iso15_SetMode)
 * (using selected mode).
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Iso15_StayQuiet(brp_protocol protocol);
/**
 * @anchor Iso15_ReadBlock
 * **For new applications please use[
 * Iso15.WriteMultipleBlocks](@ref Iso15_ReadMultipleBlocks) as this command is
 * deprecated and may be removed in future.**
 * 
 * This command reads one or multiple blocks from a label.
 * 
 * This command implements the "read single block" and "read multiple blocks"
 * optional commands from the [ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of first block to read.
 * @param[in] BlockNum Number of blocks to read:    * 0x00: 1 block    * 0xFF: 256 blocks
 * @param[in] EnBlockSec Enable/Disable _BlockSecStat_ Byte in response frame.
 * @param[out] LabelStat Status code returned from label. The following bytes will only be returned, if _LabelStat_ is OK.
 * @param[out] BlockLen Amount of bytes to read in one block.
 * @param[out] Data 
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso15_ReadBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, bool EnBlockSec, unsigned* LabelStat, unsigned* BlockLen, brp_Iso15_ReadBlock_Data_Entry** Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor Iso15_WriteBlock
 * **For new applications please use[
 * Iso15.WriteMultipleBlocks](@ref Iso15_WriteMultipleBlocks) as this command is
 * deprecated and may be removed in future.**
 * 
 * This command writes one or multiple blocks to a label.
 * 
 * This command implements the "write multiple blocks" optional commands from the
 * [ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of first block to write.
 * @param[in] BlockNum Number of blocks to write:    * 0x00: 1 block    * 0xFF: 256 blocks
 * @param[in] BlockLen Length of each block (The length of the first block is considered to be representative).
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[in] Data 
 * @param[in] Data_len 
 * @param[out] LabelStat Status code returned from label.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso15_WriteBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, unsigned BlockLen, bool OptionFlag, brp_buf* Data, size_t Data_len, unsigned* LabelStat);
/**
 * @anchor Iso15_LockBlock
 * This command permanently locks the block with ID _BlockID_.
 * 
 * **This command is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of the block to be locked.
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_LockBlock(brp_protocol protocol, unsigned BlockID, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_ResetToReady
 * This command puts a label into _ready-state_ , according to the VICC state
 * transition diagram from the [ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * **This command is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_ResetToReady(brp_protocol protocol, unsigned* LabelStat);
/**
 * @anchor Iso15_WriteAFI
 * This commands writes the _AFI_ value into the label's memory.
 * 
 * **This commands is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AFI AFI
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_WriteAFI(brp_protocol protocol, unsigned AFI, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_LockAFI
 * This command locks the _AFI_ value permanently into the reader's memory.
 * 
 * **This commands is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_LockAFI(brp_protocol protocol, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_WriteDSFID
 * This commands writes the _DSFID_ value into the label's memory.
 * 
 * **This commands is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DSFID DSFID
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_WriteDSFID(brp_protocol protocol, unsigned DSFID, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_LockDSFID
 * This command locks the _DSFID_ value permanently into the reader's memory.
 * 
 * **This commands is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_LockDSFID(brp_protocol protocol, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_GetSystemInformation
 * This command gets the system information of a VICC.
 * 
 * **This commands is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 * @param[out] EnICRef IC reference present / supported.
 * @param[out] EnMemSize Memory size present / supported.
 * @param[out] EnAFI AFI present / supported.
 * @param[out] EnDSFID DSFID present / supported.
 * @param[out] SNR 
 * @param[out] DSFID 
 * @param[out] AFI 
 * @param[out] BlockNum Number of blocks - 1 (e.g. _BlockNum_ = 0 means 1 block is present).
 * @param[out] BlockSize Block size - 1 in Byte (e.g. _BlockSize_ = 0 means a block size of 1 Byte).
 * @param[out] ICRef 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_GetSystemInformation(brp_protocol protocol, unsigned* LabelStat, bool* EnICRef, bool* EnMemSize, bool* EnAFI, bool* EnDSFID, brp_buf* SNR, unsigned* DSFID, unsigned* AFI, unsigned* BlockNum, unsigned* BlockSize, unsigned* ICRef, brp_mempool *mempool);
/**
 * @anchor Iso15_GetSecurityStatus
 * This command retrieves the block security status of a label.
 * 
 * **This command is an _optional command_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of first block to read.
 * @param[in] BlockNum Number of blocks to write:    * 0x00: 1 block    * 0xFF: 256 blocks
 * @param[out] LabelStat Status code returned from label. The following Bytes will only be returned, if _LabelStat_ is OK.
 * @param[out] BlockStat 
 * @param[out] BlockStat_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_GetSecurityStatus(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, unsigned* LabelStat, unsigned** BlockStat, size_t* BlockStat_len, brp_mempool *mempool);
/**
 * @anchor Iso15_CustomCommand
 * This command executes any ISO 15693 manufacturer proprietary commands, so-
 * called _custom-commands_.
 * 
 * By default, the same label is addressed as in the last regular ISO 15693
 * command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Cmd Custom ISO 15693 command code.
 * @param[in] Opt Enables the usage of option flag Byte.
 * @param[in] MFC Manufacturer Code.
 * @param[in] TO Timeout in ms for label answer after it has fully received the command.
 * @param[in] RequestData Data block (request).
 * @param[in] RequestData_len 
 * @param[out] LabelStat Status code returned from label. The following bytes will only be returned, if _LabelStat_ is OK.
 * @param[out] ResponseData Data block (response).
 * @param[out] ResponseData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_CustomCommand(brp_protocol protocol, unsigned Cmd, unsigned Opt, unsigned MFC, unsigned TO, brp_buf RequestData, size_t RequestData_len, unsigned* LabelStat, brp_buf* ResponseData, size_t* ResponseData_len, brp_mempool *mempool);
/**
 * @anchor Iso15_ReadSingleBlock
 * This command reads a single block from a label.
 * 
 * This command implements the "read single block" optional command from the [ISO
 * 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of block to read.
 * @param[in] EnBlockSec Disable _BlockSecStat_ byte in answer.
 * @param[out] LabelStat Status code returned from label. The following bytes will only be returned, if _LabelStat_ is OK.
 * @param[out] Payload Payload data which are stored in the requested block.
 * @param[out] Payload_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_ReadSingleBlock(brp_protocol protocol, unsigned BlockID, bool EnBlockSec, unsigned* LabelStat, brp_buf* Payload, size_t* Payload_len, brp_mempool *mempool);
/**
 * @anchor Iso15_WriteSingleBlock
 * This command writes a single block to a label.
 * 
 * This command implements the "write single block" optional command from the
 * [ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockID ID of block to write
 * @param[in] BlockLen Length of each block (The length of the first block is considered to be representative).
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[in] SingleBlockData Block to write.
 * @param[in] SingleBlockData_len 
 * @param[out] LabelStat Status code returned from label. The following bytes will only be returned, if _LabelStat_ is OK.
 */
brp_errcode brp_Iso15_WriteSingleBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockLen, bool OptionFlag, brp_buf SingleBlockData, size_t SingleBlockData_len, unsigned* LabelStat);
/**
 * @anchor Iso15_TransparentCmdLegacy
 * **For new applications please use[
 * Iso15.TransparentCmd](@ref Iso15_TransparentCmd) as this command is deprecated
 * and may be removed in future.**
 * 
 * This command sends a data stream to a label and returns the communication
 * status and the received label data stream to the host. If no bytes are sent
 * and the CRC check is disabled, only an EOF is sent to the label. After
 * execution of this command, the _Mode_ parameter is reset to default.
 * 
 * **Please be aware that the _flag_ Byte (see the[ ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467) ,
 * 2001 p.9) is not generated by the reader. This flag has to be transmitted as
 * part of the _data_ string.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnRxWait If _true_ , param _RxWait_ is transmitted to the reader.
 * @param[in] EnCRCRX Enable CRC check over received data.
 * @param[in] EnCRCTX Enable CRC over transmitted data.
 * @param[in] Len Number of bytes to send.
 * @param[in] Timeout Timeout in ms between sending last bit to label and receiving first bit from label.
 * @param[in] Data **Length is greater than 0! It was set to zero to provide length information**
 * @param[in] RxWait After data transmission to the label, the receiver is delayed for a _RxWait_ time, measured in Rx bitclock steps. After execution of the command, _RxWait_ is reset to the default value.
 * @param[out] LabelData 
 * @param[out] LabelData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Iso15_TransparentCmdLegacy(brp_protocol protocol, bool EnRxWait, bool EnCRCRX, bool EnCRCTX, unsigned Len, unsigned Timeout, brp_buf Data, unsigned RxWait, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool);
/**
 * @anchor Iso15_WriteMultipleBlocks
 * Sends the "WriteMultipleBlocks" to the card to store the data passed in
 * _WriteBlocks_ to the data blocks of the presented card starting at block with
 * id _Blockid_. For more information about this command please refer to the [ISO
 * 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FirstBlockId Index (starting at 0) of first block to write.
 * @param[in] WriteBlocks 
 * @param[in] WriteBlocks_len 
 * @param[in] OptionFlag Option Flag according to the [ISO 15693-3 specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * @param[out] LabelStat Status code returned from label.
 */
brp_errcode brp_Iso15_WriteMultipleBlocks(brp_protocol protocol, unsigned FirstBlockId, brp_Iso15_WriteMultipleBlocks_WriteBlocks_Entry* WriteBlocks, size_t WriteBlocks_len, bool OptionFlag, unsigned* LabelStat);
/**
 * @anchor Iso15_ReadMultipleBlocks
 * This command reads one or multiple blocks from a label.
 * 
 * This command implements the (optional) "ReadMultipleBlocks" command from the
 * [ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FirstBlockId Index (starting at 0) of first block to read.
 * @param[in] BlockCount Number of blocks to read.
 * @param[in] EnBlockSec Enable/Disable _BlockSecStat_ Byte in response frame.
 * @param[out] LabelStat Status code returned from label. Is 0 if everything was OK, else an error code is returned.
 * @param[out] RecvBlocks if _LabelStat_ is not 0 (=error), this array will always be if size 0.
 * @param[out] RecvBlocks_len 
 * @param[out] BlocksSecData this array will always be of size 0 if LabelStat is not 0 (=error) or EnBlockSec was not set.
 * @param[out] BlocksSecData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_ReadMultipleBlocks(brp_protocol protocol, unsigned FirstBlockId, unsigned BlockCount, bool EnBlockSec, unsigned* LabelStat, brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry** RecvBlocks, size_t* RecvBlocks_len, unsigned** BlocksSecData, size_t* BlocksSecData_len, brp_mempool *mempool);
/**
 * @anchor Iso15_TransparentCmd
 * This command sends a data stream to a label and returns the communication
 * status and the received label data stream to the host. If no bytes are sent
 * and the CRC check is disabled, only an EOF is sent to the label. After
 * execution of this command, the _Mode_ parameter is reset to default.
 * 
 * **Please be aware that the _flag_ Byte (see the[ ISO 15693-3
 * specification](http://www.iso.org/iso/catalogue_detail.htm?csnumber=43467) ,
 * 2001 p.9) is not generated by the reader. This flag has to be transmitted as
 * part of the _data_ string.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SendData 
 * @param[in] SendData_len 
 * @param[in] Timeout Timeout in ms between sending last bit to label and receiving first bit from label.
 * @param[in] EnCrcRx Check CRC on _RecvData_ and remove it before returning it.
 * @param[in] EnCrcTx Add CRC to _SendData_ before transmitting it to card.
 * @param[in] RxWait After data transmission to the label, the receiver is delayed for a _RxWait_ time, measured in Rx bitclock steps. If this value is 0, no delay is added.
 * @param[out] RecvData 
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Iso15_TransparentCmd(brp_protocol protocol, brp_buf SendData, size_t SendData_len, unsigned Timeout, bool EnCrcRx, bool EnCrcTx, unsigned RxWait, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
