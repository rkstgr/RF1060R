/**
 * @file
 * @anchor FlashFS
 * This command group provides access to custom data that is stored in a
 * dataflash device.
 * 
 * The access is handled through a flash file system. Each file, which is
 * identified with a 16-bit ID, is organized in records of a fixed size. The
 * record size can be between 1 and 254 and must be determined at file creation,
 * but can be chosen individually for every file. All read and write operations
 * use a record as the smallest storage unit. Records may be appended to the end
 * of a file or they may overwrite existing records with new data.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_FLASHFS_H__
#define __BRP_BALTECH_API_CMDS_FLASHFS_H__
#include "../typedefs.h"
/**
 * @anchor FlashFS_ErrFsCorrupt
 * The file system is corrupt: Format required.
 */
#define BRP_FlashFS_ErrFsCorrupt BRP_ERR_STATUS(0x4900, 0x01)
/**
 * @anchor FlashFS_ErrRecordCorrupt
 * The current record is corrupt.
 */
#define BRP_FlashFS_ErrRecordCorrupt BRP_ERR_STATUS(0x4900, 0x02)
/**
 * @anchor FlashFS_ErrFlashAccess
 * Dataflash cannot be accessed: Hardware error.
 */
#define BRP_FlashFS_ErrFlashAccess BRP_ERR_STATUS(0x4900, 0x03)
/**
 * @anchor FlashFS_ErrDirectoryFull
 * The File cannot be created, since there are no more free entries.
 */
#define BRP_FlashFS_ErrDirectoryFull BRP_ERR_STATUS(0x4900, 0x04)
/**
 * @anchor FlashFS_ErrFileNotFound
 * The file is not created yet.
 */
#define BRP_FlashFS_ErrFileNotFound BRP_ERR_STATUS(0x4900, 0x05)
/**
 * @anchor FlashFS_ErrEndOfFile
 * The end of the file is reached: no more records available.
 */
#define BRP_FlashFS_ErrEndOfFile BRP_ERR_STATUS(0x4900, 0x06)
/**
 * @anchor FlashFS_ErrFull
 * There is no more space on the Dataflash.
 */
#define BRP_FlashFS_ErrFull BRP_ERR_STATUS(0x4900, 0x07)
/**
 * @anchor FlashFS_ErrFileExist
 * The file cannot be created, since it already exists.
 */
#define BRP_FlashFS_ErrFileExist BRP_ERR_STATUS(0x4900, 0x08)
/**
 * @anchor FlashFS_GetMemoryInfo
 * This command checks the consistency of the file system and retrieves
 * information about the available dataflash memory space.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] TotalMem Total amount of dataflash space (in Bytes).
 * @param[out] FreeMem Free amount of dataflash space (in Bytes).
 */
brp_errcode brp_FlashFS_GetMemoryInfo(brp_protocol protocol, unsigned* TotalMem, unsigned* FreeMem);
/**
 * @anchor FlashFS_Format
 * This command resets the complete file system. All data - managment structures,
 * files and records - gets lost.
 * 
 * A format is required before the first use.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] QuickFormat If _false_ , every sector of the dataflash will be erased, which can be very time-consuming. If _true_ , only the management structures are reset.
 */
brp_errcode brp_FlashFS_Format(brp_protocol protocol, bool QuickFormat);
/**
 * @anchor FlashFS_CreateFile
 * This command creates a new empty file, if the file doesn't exist yet. All
 * records of this file that may be created with the
 * [FlashFS.WriteRecords](@ref FlashFS_WriteRecords) command later have the
 * specified record size.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file that should be created.
 * @param[in] RecordSize Size of a single record of this file. Has to be between 1 and 254.
 */
brp_errcode brp_FlashFS_CreateFile(brp_protocol protocol, unsigned FileId, unsigned RecordSize);
/**
 * @anchor FlashFS_DeleteFile
 * This command deletes a file and all its contained records. The file will be
 * removed from the file system directory and the memory space allocated by its
 * records will be freed, so that other files can use this space.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file that shall be deleted.
 */
brp_errcode brp_FlashFS_DeleteFile(brp_protocol protocol, unsigned FileId);
/**
 * @anchor FlashFS_RenameFile
 * This command changes the File ID of a file from _FileId_ to _NewFileId_ ,
 * provided the file with ID _FileId_ exists and a file with ID _NewFileId_
 * doesn't exist yet.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId The File ID of the file that shall be renamed.
 * @param[in] NewFileId The new File ID the file to rename should get.
 */
brp_errcode brp_FlashFS_RenameFile(brp_protocol protocol, unsigned FileId, unsigned NewFileId);
/**
 * @anchor FlashFS_GetRecordSize
 * This command retrieves the size of a single record of a certain file. Every
 * file has a fix record size, which was specified at file creation.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file to get the record size from.
 * @param[out] RecordSize Record size of file (in Bytes).
 */
brp_errcode brp_FlashFS_GetRecordSize(brp_protocol protocol, unsigned FileId, unsigned* RecordSize);
/**
 * @anchor FlashFS_GetFileSize
 * This command retrieves the number of records a certain file contains.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file to get the file size from.
 * @param[out] FileSize Number of records the file contains.
 */
brp_errcode brp_FlashFS_GetFileSize(brp_protocol protocol, unsigned FileId, unsigned* FileSize);
/**
 * @anchor FlashFS_ReadRecords
 * This command reads one or more records from a file. If the file contains less
 * records than specified, the response only returns the available number of
 * records.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file to read from.
 * @param[in] StartRecord First record number to read.
 * @param[in] RecordCount Number of records to read. Should not be larger than the return value of [FlashFS.GetFileSize](@ref FlashFS_GetFileSize).
 * @param[out] RecordList 
 * @param[out] RecordList_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_FlashFS_ReadRecords(brp_protocol protocol, unsigned FileId, unsigned StartRecord, unsigned RecordCount, brp_FlashFS_ReadRecords_RecordList_Entry** RecordList, size_t* RecordList_len, brp_mempool *mempool);
/**
 * @anchor FlashFS_WriteRecords
 * This command writes one or more records to a file. By selecting an appropriate
 * _StartRecord_ parameter new records may be appended to the end of the file or
 * may overwrite existing records.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId File ID of the file to write to.
 * @param[in] StartRecord First record number to write. If this value equals the return value of [FlashFS.GetFileSize](@ref FlashFS_GetFileSize) (or is set to 0xFFFF) the records are appended to the end of the file. If _StartRecord_ is smaller than [FlashFS.GetFileSize](@ref FlashFS_GetFileSize), records are overwritten.
 * @param[in] RecordList 
 * @param[in] RecordList_len 
 */
brp_errcode brp_FlashFS_WriteRecords(brp_protocol protocol, unsigned FileId, unsigned StartRecord, brp_FlashFS_WriteRecords_RecordList_Entry* RecordList, size_t RecordList_len);
#endif
/**
 * @}
 */
