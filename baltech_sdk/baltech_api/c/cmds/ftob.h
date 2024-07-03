/**
 * @file
 * @anchor Ftob
 * Ftob card commands
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_FTOB_H__
#define __BRP_BALTECH_API_CMDS_FTOB_H__
#include "../typedefs.h"
/**
 * @anchor Ftob_ErrInvalidFilename
 * The specified file name is not supported by the reader.
 */
#define BRP_Ftob_ErrInvalidFilename BRP_ERR_STATUS(0x0300, 0x01)
/**
 * @anchor Ftob_ErrFileAccessDenied
 * Permission missing to read/write file.
 */
#define BRP_Ftob_ErrFileAccessDenied BRP_ERR_STATUS(0x0300, 0x02)
/**
 * @anchor Ftob_ErrWriteBlock
 * Cannot write data.
 */
#define BRP_Ftob_ErrWriteBlock BRP_ERR_STATUS(0x0300, 0x03)
/**
 * @anchor Ftob_ErrReadBlock
 * Cannot read data.
 */
#define BRP_Ftob_ErrReadBlock BRP_ERR_STATUS(0x0300, 0x04)
/**
 * @anchor Ftob_ErrNoFileActive
 * Cannot transfer data without opening a file.
 */
#define BRP_Ftob_ErrNoFileActive BRP_ERR_STATUS(0x0300, 0x05)
/**
 * @anchor Ftob_ErrOutOfMemory
 * Filesystem ran out of memory.
 */
#define BRP_Ftob_ErrOutOfMemory BRP_ERR_STATUS(0x0300, 0x06)
/**
 * @anchor Ftob_ErrBroken
 * Transfer was broken prematurely with FinishTransfer.
 */
#define BRP_Ftob_ErrBroken BRP_ERR_STATUS(0x0300, 0x07)
/**
 * @anchor Ftob_OpenReadFile
 * This commands starts reading a file from the reader. After executing this
 * command successfully, you may execute only FToB commands until finishing
 * transfer.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Filename Name of file to open for reading.
 * @param[in] Filename_len 
 */
brp_errcode brp_Ftob_OpenReadFile(brp_protocol protocol, brp_buf Filename, size_t Filename_len);
/**
 * @anchor Ftob_OpenWriteFile
 * This commands starts writing a file to the reader. After executing this
 * command successfully, you may execute only FToB commands until finishing
 * transfer.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Filename Name of file to open for writing.
 * @param[in] Filename_len 
 * @param[out] MaxBlockLen Maximum count of Bytes to send with a single [Ftob.WriteFileBlock](@ref Ftob_WriteFileBlock).
 */
brp_errcode brp_Ftob_OpenWriteFile(brp_protocol protocol, brp_buf Filename, size_t Filename_len, unsigned* MaxBlockLen);
/**
 * @anchor Ftob_ReadFileBlock
 * Use this command to receive a file block by block.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ToggleBit This value must be toggled after every successfully transferred block.
 * @param[in] MaxBlockLength Maximum length of received block.
 * @param[out] BlockData Content of read block.
 * @param[out] BlockData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Ftob_ReadFileBlock(brp_protocol protocol, bool ToggleBit, unsigned MaxBlockLength, brp_buf* BlockData, size_t* BlockData_len, brp_mempool *mempool);
/**
 * @anchor Ftob_WriteFileBlock
 * This command writes a file block by block.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ToggleBit This value must be toggled after every successfully transferred block.
 * @param[in] BlockData Content of block to write.
 * @param[in] BlockData_len 
 */
brp_errcode brp_Ftob_WriteFileBlock(brp_protocol protocol, bool ToggleBit, brp_buf BlockData, size_t BlockData_len);
/**
 * @anchor Ftob_CloseFile
 * This commands quits transferring a file.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Success Set to _true_ on success.
 */
brp_errcode brp_Ftob_CloseFile(brp_protocol protocol, bool Success);
#endif
/**
 * @}
 */
