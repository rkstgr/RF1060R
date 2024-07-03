/**
 * @file
 * @anchor EpcUid
 * Commands for UID / EPC tags.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_EPCUID_H__
#define __BRP_BALTECH_API_CMDS_EPCUID_H__
#include "../typedefs.h"
/**
 * @anchor EpcUid_ErrNoTag
 * No label in field of antenna.
 */
#define BRP_EpcUid_ErrNoTag BRP_ERR_STATUS(0x2200, 0x01)
/**
 * @anchor EpcUid_ErrHf
 * General HF error.
 */
#define BRP_EpcUid_ErrHf BRP_ERR_STATUS(0x2200, 0x04)
/**
 * @anchor EpcUid_ErrCom
 * Error in communication to reader chip.
 */
#define BRP_EpcUid_ErrCom BRP_ERR_STATUS(0x2200, 0x10)
/**
 * @anchor EpcUid_ErrCmd
 * Command and/or parameters invalid.
 */
#define BRP_EpcUid_ErrCmd BRP_ERR_STATUS(0x2200, 0x20)
/**
 * @anchor EpcUid_UidReplyRound
 * This command scans for labels in the field using time slots. All labels with
 * consistent data according to _SelectionMask_ bits are responding in time
 * slots. If the _FixSlot_ flag is set, a successfully recognized label (CRC OK)
 * will be set to the FIXED SLOT state. All successfully recognized label data
 * will be transferred to the host. If the internal reader buffer is to small,
 * _MemStatusFlag_ will be set.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EPC EPC if _true_ , UID if _false_.
 * @param[in] FixSlot Label will be fixed to F slot if _true_.
 * @param[in] SlotCoding 0: 1 slot  1, 3, 7, 0xF, 0x1F..0xFF: (x+1) * 2 slots
 * @param[in] MaskLength Bit length of _SelectionMask_ parameter.
 * @param[in] SelectionMask Present if _MaskLength_ > 0\. Only labels with consistent data are responding.
 * @param[in] SelectionMask_len 
 * @param[in] HashValue Used by EPC labels to calculate random slot position.
 * @param[out] MemStatusFlag Returns 1 if reader buffer is to small for all label data, else 0.
 * @param[out] LabelNr Number of successfully recognized labels.
 * @param[out] LabelLength Length of a label reply in Bytes.
 * @param[out] LabelData Label data (length: _LabelNr_ x _LabelLength_).
 * @param[out] LabelData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_UidReplyRound(brp_protocol protocol, bool EPC, bool FixSlot, unsigned SlotCoding, unsigned MaskLength, brp_buf SelectionMask, size_t SelectionMask_len, unsigned HashValue, unsigned* MemStatusFlag, unsigned* LabelNr, unsigned* LabelLength, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool);
/**
 * @anchor EpcUid_UidWrite
 * This command writes data Bytes to a label. The address of the data to write is
 * specified in the _BlockAdr_ parameter. As an enhancement to the specification,
 * multiple Bytes can be written.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EPC EPC if _true_ , UID if _false_.
 * @param[in] BlockAdr Start address of data to write.
 * @param[in] BlockData Block data.
 * @param[in] BlockData_len 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_UidWrite(brp_protocol protocol, bool EPC, unsigned BlockAdr, brp_buf BlockData, size_t BlockData_len);
/**
 * @anchor EpcUid_UidDestroy
 * This command will render the label permanently unable to give any replies. The
 * command can be used for both EPC and UID labels.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EpcUidData Length UID/EPC block data.
 * @param[in] EpcUidData_len 
 * @param[in] DestroyCode Destroy code which has to match.
 * @param[in] DestroyCode_len 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_UidDestroy(brp_protocol protocol, brp_buf EpcUidData, size_t EpcUidData_len, brp_buf DestroyCode, size_t DestroyCode_len);
/**
 * @anchor EpcUid_EpcSetMode
 * This command specifies HF coding.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DR848 Sets divider ratio to 424 or 848 kBaud.
 * @param[in] Coding Specifies modulation type.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_EpcSetMode(brp_protocol protocol, unsigned DR848, brp_EpcUid_EpcSetMode_Coding Coding);
/**
 * @anchor EpcUid_EpcSelect
 * This command selects a particular tag population.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Truncate Specifies if the tag answer in a subsequent BeginRound command starts after Mask bits or from begin of memory.
 * @param[in] Target Specifies flag which should be modified.
 * @param[in] Action Specifies action to a flag select by the _Target_ bit value.
 * @param[in] MemBank Specifies memory bank.
 * @param[in] MaskPointerLength Specifies length of pointer (8, 16, 24, 32).
 * @param[in] MaskPointer Memory bit address.
 * @param[in] MaskPointer_len 
 * @param[in] MaskLength Bit length of _SelectionMask_ parameter.
 * @param[in] SelectionMask 
 * @param[in] SelectionMask_len 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_EpcSelect(brp_protocol protocol, unsigned Truncate, unsigned Target, unsigned Action, brp_EpcUid_EpcSelect_MemBank MemBank, unsigned MaskPointerLength, brp_buf MaskPointer, size_t MaskPointer_len, unsigned MaskLength, brp_buf SelectionMask, size_t SelectionMask_len);
/**
 * @anchor EpcUid_EpcInventory
 * This command executes an inventory command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Sel Specifies flags for which tags should respond to command (0/1: All, 2:~SL, 3:SL).
 * @param[in] Session Chooses a session for command (0:S0, 2:S2).
 * @param[in] SlotCoding Number of slots.  0..15: 2^Q - 1 slots.
 * @param[out] MemStatusFlag True if buffer to small for all tagged labels.
 * @param[out] LabelNr Number of successfully recognized labels.
 * @param[out] LabelData Label data.
 * @param[out] LabelData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_EpcUid_EpcInventory(brp_protocol protocol, unsigned Sel, unsigned Session, unsigned SlotCoding, unsigned* MemStatusFlag, unsigned* LabelNr, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
