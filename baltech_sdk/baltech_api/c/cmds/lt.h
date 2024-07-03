/**
 * @file
 * @anchor LT
 * These are LT transponder commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_LT_H__
#define __BRP_BALTECH_API_CMDS_LT_H__
#include "../typedefs.h"
/**
 * @anchor LT_ErrLtNoTag
 * No tag present in the reader's RFID field.
 */
#define BRP_LT_ErrLtNoTag BRP_ERR_STATUS(0xA000, 0x01)
/**
 * @anchor LT_ErrLtCrc
 * CRC checksum error.
 */
#define BRP_LT_ErrLtCrc BRP_ERR_STATUS(0xA000, 0x02)
/**
 * @anchor LT_ErrLtParity
 * Parity error.
 */
#define BRP_LT_ErrLtParity BRP_ERR_STATUS(0xA000, 0x05)
/**
 * @anchor LT_LtNackReceived
 * NACK received, command not accepted.
 */
#define BRP_LT_LtNackReceived BRP_ERR_STATUS(0xA000, 0x06)
/**
 * @anchor LT_ErrLtHf
 * General HF error.
 */
#define BRP_LT_ErrLtHf BRP_ERR_STATUS(0xA000, 0x07)
/**
 * @anchor LT_ErrLtSnr
 * Collision occurred.
 */
#define BRP_LT_ErrLtSnr BRP_ERR_STATUS(0xA000, 0x08)
/**
 * @anchor LT_ErrLtBitcount
 * Wrong number of bits received from the transponder.
 */
#define BRP_LT_ErrLtBitcount BRP_ERR_STATUS(0xA000, 0x0B)
/**
 * @anchor LT_ErrLtFileov
 * To many blocks written to file.
 */
#define BRP_LT_ErrLtFileov BRP_ERR_STATUS(0xA000, 0x0C)
/**
 * @anchor LT_ErrLtCom
 * Communication error uC - reader chip.
 */
#define BRP_LT_ErrLtCom BRP_ERR_STATUS(0xA000, 0x0D)
/**
 * @anchor LT_ErrLtCmd
 * Command syntax error.
 */
#define BRP_LT_ErrLtCmd BRP_ERR_STATUS(0xA000, 0x13)
/**
 * @anchor LT_ErrLtEepRead
 * Error reading EEPROM of the reader.
 */
#define BRP_LT_ErrLtEepRead BRP_ERR_STATUS(0xA000, 0x15)
/**
 * @anchor LT_ErrLtEepWrite
 * Error writing EEPROM of the reader.
 */
#define BRP_LT_ErrLtEepWrite BRP_ERR_STATUS(0xA000, 0x16)
/**
 * @anchor LT_Request
 * According to the _ReqAll_ flag, either only PICCs in idle state or also PICCs
 * in halt state will be switched to ready state. Only PICCs in ready state may
 * be selected via the [LT.Select](@ref LT_Select) command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ReqAll If set, all PICCs (even those in halt state) will be requested.
 * @param[out] ATQA Answer To Request type A.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Request(brp_protocol protocol, bool ReqAll, brp_buf* ATQA, brp_mempool *mempool);
/**
 * @anchor LT_Anticoll
 * This command performs an anticollision sequence.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BitCount Number of preselected bits.
 * @param[in] PreSelectedSnr Part of serial number which will be used for preselection of cards.
 * @param[out] SelectedSnr Serialnr of selected label.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelectedSnr, brp_buf* SelectedSnr, brp_mempool *mempool);
/**
 * @anchor LT_Select
 * This command selects a PICC with 4-Byte serial number.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Snr Serial number of card.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Select(brp_protocol protocol, brp_buf Snr);
/**
 * @anchor LT_Halt
 * Switch PICC to halt state. The PICC has to be selected before it may be
 * switched to halt state.
 * 
 * @param[in] protocol used to execute the command
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Halt(brp_protocol protocol);
/**
 * @anchor LT_ReadBlock
 * Reads a block (32 Byte) from the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[out] Data Data block (32 Byte).
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadBlock(brp_protocol protocol, unsigned Adr, brp_buf* Data, brp_mempool *mempool);
/**
 * @anchor LT_ReadMultipleBlocks
 * Reads several blocks (32 Byte) from the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[in] NumBlocks Number of blocks to read.
 * @param[out] Data Data blocks.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadMultipleBlocks(brp_protocol protocol, unsigned Adr, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor LT_WriteBlock
 * Writes a block (32 Byte) to the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_WriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data);
/**
 * @anchor LT_ReadWord
 * Reads a word (2 Byte) from the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockAdr Block address.
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[out] DataLo Data word (LSByte).
 * @param[out] DataHi Data word (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned* DataLo, unsigned* DataHi);
/**
 * @anchor LT_WriteWord
 * Writes a word to the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockAdr Block address.
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[in] DataLo Data word (LSByte).
 * @param[in] DataHi Data word (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_WriteWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned DataLo, unsigned DataHi);
/**
 * @anchor LT_WriteFile
 * Writes a test file to the reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileNr File number (3 files: 0..2).
 * @param[in] Mode 
 * @param[in] BlockAdr Block address of the data block.
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_WriteFile(brp_protocol protocol, unsigned FileNr, unsigned Mode, unsigned BlockAdr, brp_buf Data);
/**
 * @anchor LT_Test
 * Writes a test file to the reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode 
 * @param[out] Teststatus 
 * @param[out] Snr Serial number.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Test(brp_protocol protocol, unsigned Mode, unsigned* Teststatus, brp_buf* Snr, brp_mempool *mempool);
/**
 * @anchor LT_FastWriteBlock
 * Writes a block (32 Byte) to the transponder, write time is reduced (LT5).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_FastWriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data);
/**
 * @anchor LT_FastWriteWord
 * Writes a word to the transponder, write time is reduced (LT5).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockAdr Block address.
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[in] DataLo Data word (LSByte).
 * @param[in] DataHi Data word (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_FastWriteWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned DataLo, unsigned DataHi);
/**
 * @anchor LT_HighSpeedWriteBlock
 * Writes a block (32 Byte) to the transponder, write time is reduced (LT5),
 * block 1 has to be unprotected.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_HighSpeedWriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data);
/**
 * @anchor LT_GetBootStatus
 * Retrieves the boot status of the reader, which describes the state of the
 * readers hardware. If a defect is detected during the self-test of the reader,
 * a bit will be set.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode 1: read and reset boot status.
 * @param[out] BootStatusLo Bitmask with one bit for every peripheral of the reader (LSByte).
 * @param[out] BootStatusHi Bitmask with one bit for every peripheral of the reader (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_GetBootStatus(brp_protocol protocol, unsigned Mode, unsigned* BootStatusLo, unsigned* BootStatusHi);
/**
 * @anchor LT_ContinousReadBlocks
 * Reads several blocks (32 Byte) from the transponder. Faster read because
 * transponder protocol has been optimized (LT5).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr Block address.
 * @param[in] NumBlocks Number of blocks to read.
 * @param[out] Data Data blocks.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ContinousReadBlocks(brp_protocol protocol, unsigned Adr, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor LT_SetReturnLink
 * Sets the transponder baud rate after selection.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode (0..3: 106..848 kBit / bit 7:0-permanent; 1: execute command once)
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_SetReturnLink(brp_protocol protocol, unsigned Mode);
/**
 * @anchor LT_HFReset
 * This command controls the antenna of the reader. It can be powered off and on
 * permanently or for a limited time.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] OffDurationLo Number of ms to power off HF antenna. If 0, it will be powered off until next command (LSByte).
 * @param[in] OffDurationHi Number of ms to power off HF antenna. If 0, it will be powered off until next command (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_HFReset(brp_protocol protocol, unsigned OffDurationLo, unsigned OffDurationHi);
/**
 * @anchor LT_Reset
 * This command reboots the reader. After this command you have to wait some time
 * until the reader reacts to requests.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Quit 0: warm / 1: cold reset
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_Reset(brp_protocol protocol, unsigned Quit);
/**
 * @anchor LT_GetInfo
 * Retrieves the firmware string, which provides information regarding the
 * firmware release of the reader and the reader's serial number.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Info 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_GetInfo(brp_protocol protocol, char** Info, brp_mempool *mempool);
/**
 * @anchor LT_TransparentCmd
 * 
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EnBitMode 
 * @param[in] EnCRCRX 
 * @param[in] EnCRCTX 
 * @param[in] ParityMode 
 * @param[in] EnParity 
 * @param[in] LenLo 
 * @param[in] LenHi 
 * @param[in] TimeoutLo 
 * @param[in] TimeoutHi 
 * @param[in] DSI 
 * @param[in] DRI 
 * @param[in] Data 
 * @param[in] Data_len 
 * @param[out] ReturnLenLo 
 * @param[out] ReturnLenHi 
 * @param[out] ColPos Collision Position.
 * @param[out] ReturnData 
 * @param[out] ReturnData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_TransparentCmd(brp_protocol protocol, unsigned EnBitMode, unsigned EnCRCRX, unsigned EnCRCTX, unsigned ParityMode, unsigned EnParity, unsigned LenLo, unsigned LenHi, unsigned TimeoutLo, unsigned TimeoutHi, unsigned DSI, unsigned DRI, brp_buf Data, size_t Data_len, unsigned* ReturnLenLo, unsigned* ReturnLenHi, unsigned* ColPos, brp_buf* ReturnData, size_t* ReturnData_len, brp_mempool *mempool);
/**
 * @anchor LT_ReadBlockExtended
 * Reads a block (32 Byte) from the transponder using a 16-bit block address.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[out] Data Block data 32 Bytes.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf* Data, brp_mempool *mempool);
/**
 * @anchor LT_WriteBlockExtended
 * Writes a block (32 Byte) to the transponder using a 16-bit block address.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_WriteBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf Data);
/**
 * @anchor LT_ReadWordExtended
 * Reads a word (2 Byte) from the transponder using a 16-bit address.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[out] DataLo 2 Bytes data (LSByte).
 * @param[out] DataHi 2 Bytes data (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadWordExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned WordAdr, unsigned* DataLo, unsigned* DataHi);
/**
 * @anchor LT_WriteWordExtended
 * Writes a word to the transponder using a 16-bit block address.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockAdrLo Block address (LSByte).
 * @param[in] BlockAdrHi Block address (MSByte).
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[in] DataLo Data word (LSByte).
 * @param[in] DataHi Data word (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_WriteWordExtended(brp_protocol protocol, unsigned BlockAdrLo, unsigned BlockAdrHi, unsigned WordAdr, unsigned DataLo, unsigned DataHi);
/**
 * @anchor LT_ReadMultipleBlocksExtended
 * Reads several blocks (32 Byte) from the transponder.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[in] NumBlocks Number of blocks to read.
 * @param[out] Data Data blocks.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ReadMultipleBlocksExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor LT_FastWriteWordExtended
 * Writes a word to the transponder using a 16-bit block address + fast mode.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BlockAdrLo Block address (LSByte).
 * @param[in] BlockAdrHi Block address (MSByte).
 * @param[in] WordAdr Word address within a block (0..15).
 * @param[in] DataLo Data word (LSByte).
 * @param[in] DataHi Data word (MSByte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_FastWriteWordExtended(brp_protocol protocol, unsigned BlockAdrLo, unsigned BlockAdrHi, unsigned WordAdr, unsigned DataLo, unsigned DataHi);
/**
 * @anchor LT_ContinousReadBlocksExtended
 * Reads several blocks (32 Byte) from the transponder using fast mode.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[in] NumBlocks Number of blocks to read.
 * @param[out] Data Data blocks.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_ContinousReadBlocksExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor LT_HighSpeedWriteBlockExtended
 * Writes a block (32 Byte) to the transponder using a 16-bit address, write time
 * is reduced (LT6).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AdrLo Block address (LSByte).
 * @param[in] AdrHi Block address (MSByte).
 * @param[in] Data Data block (32 Byte).
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_LT_HighSpeedWriteBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf Data);
#endif
/**
 * @}
 */
