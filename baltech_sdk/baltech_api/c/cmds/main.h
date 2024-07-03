/**
 * @file
 * @anchor Main
 * This command group contains commands needed to update the firmware of the
 * reader.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_MAIN_H__
#define __BRP_BALTECH_API_CMDS_MAIN_H__
#include "../typedefs.h"
/**
 * @anchor Main_ErrOutdatedFirmware
 * Is returned by isFirmwareUpToDate() if the following piece of firmware is not
 * up to date.
 */
#define BRP_Main_ErrOutdatedFirmware BRP_ERR_STATUS(0xF000, 0x01)
/**
 * @anchor Main_ErrUnknownVersion
 * Is returned by isFirmwareUpToDate() if it's unknown whether the following
 * piece of firmware is outdated or not.
 */
#define BRP_Main_ErrUnknownVersion BRP_ERR_STATUS(0xF000, 0x02)
/**
 * @anchor Main_ErrInvalidState
 * Is returned by Bf3UploadStart if an upload process is already running or by
 * Bf3UploadContinue if an upload process is currently not active.
 */
#define BRP_Main_ErrInvalidState BRP_ERR_STATUS(0xF000, 0x10)
/**
 * @anchor Main_ErrReadFile
 * Is returned by Bf3UploadContinue if BF3/BEC2 file data couldn't be retrieved
 * from the host.
 */
#define BRP_Main_ErrReadFile BRP_ERR_STATUS(0xF000, 0x11)
/**
 * @anchor Main_ErrInvalidFormat
 * Is returned by Bf3UploadContinue if the BF3/BEC2 file has an invalid format.
 */
#define BRP_Main_ErrInvalidFormat BRP_ERR_STATUS(0xF000, 0x12)
/**
 * @anchor Main_ErrInvalidCustomerKey
 * Is returned by Bf3UploadContinue if the customer key of the BEC2 file doesn't
 * match the customer key stored in the reader.
 */
#define BRP_Main_ErrInvalidCustomerKey BRP_ERR_STATUS(0xF000, 0x13)
/**
 * @anchor Main_ErrInvalidConfigSecurityCode
 * Is returned by Bf3UploadContinue if the Config Security Code of the BEC2 file
 * doesn't match the Config Security Code stored in the reader.
 */
#define BRP_Main_ErrInvalidConfigSecurityCode BRP_ERR_STATUS(0xF000, 0x14)
/**
 * @anchor Main_ErrInvalidConfigVersion
 * Is returned by Bf3UploadContinue if the configuration version of the BEC2 file
 * is older than the configuration version stored in the reader.
 */
#define BRP_Main_ErrInvalidConfigVersion BRP_ERR_STATUS(0xF000, 0x15)
/**
 * @anchor Main_ErrInvalidCmac
 * Is returned by Bf3UploadContinue if the Message Authentication Code (CMAC) of
 * the BF3/BEC2 file is incorrect.
 */
#define BRP_Main_ErrInvalidCmac BRP_ERR_STATUS(0xF000, 0x16)
/**
 * @anchor Main_ErrUpload
 * Is returned by Bf3UploadContinue if a component of the current BF3/BEC2 file
 * couldn't be written to the reader memory.
 */
#define BRP_Main_ErrUpload BRP_ERR_STATUS(0xF000, 0x17)
/**
 * @anchor Main_ErrUnsupportedFirmware
 * Is returned by Bf3UploadContinue if the BF3/BEC2 file contains a firmware
 * which is not supported by the reader hardware.
 */
#define BRP_Main_ErrUnsupportedFirmware BRP_ERR_STATUS(0xF000, 0x18)
/**
 * @anchor Main_ErrAlreadyUpToDate
 * Is returned by Bf3UploadContinue if all relevant components of the current
 * BF3/BEC2 file are already up to date.
 */
#define BRP_Main_ErrAlreadyUpToDate BRP_ERR_STATUS(0xF000, 0x19)
/**
 * @anchor Main_ErrMissingConfigSecurityCode
 * Is returned by Bf3UploadContinue if the reader was not able to decode the
 * current BEC2 file, because there is no Config Security Code stored in the
 * reader yet.
 */
#define BRP_Main_ErrMissingConfigSecurityCode BRP_ERR_STATUS(0xF000, 0x1A)
/**
 * @anchor Main_ErrInvalidEccKey
 * The elliptic curve key that is used to encrypt the configuration is wrong.
 */
#define BRP_Main_ErrInvalidEccKey BRP_ERR_STATUS(0xF000, 0x1B)
/**
 * @anchor Main_Bf2Upload
 * This command transfers a single line of a BF2 file to the reader (needed for
 * firmware upload).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Lines 
 * @param[in] Lines_len 
 * @param[out] ResultCode Error code of this operation
 * @param[out] InvertedResultCode Value of _ResultCode_ with inverted bits (= _ResultCode_ XOR 0xFF)
 */
brp_errcode brp_Main_Bf2Upload(brp_protocol protocol, unsigned* Lines, size_t Lines_len, brp_Main_Bf2Upload_ResultCode* ResultCode, unsigned* InvertedResultCode);
/**
 * @anchor Main_SwitchFW
 * After uploading the complete firmware with [Main.Bf2Upload](@ref Main_Bf2Upload),
 * this command is needed to activate the new firmware and reboot the reader.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Main_SwitchFW(brp_protocol protocol);
/**
 * @anchor Main_MatchPlatformId2
 * This command checks if the PlatformID2 of the reader matches the PlatformID2
 * provided in the _Filter_ parameter.
 * 
 * **If this command is not available, the[
 * Sys.GetPlatformId](@ref Sys_GetPlatformId) command can be used as a
 * fallback.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Filter Filter string from a BF2 file to compare to the reader's PlatformID2.
 * @param[in] Filter_len 
 * @param[out] Matches Returns _true_ if the _Filter_ string matches the PlatformID2 of the reader.
 */
brp_errcode brp_Main_MatchPlatformId2(brp_protocol protocol, brp_buf Filter, size_t Filter_len, bool* Matches);
/**
 * @anchor Main_IsFirmwareUpToDate
 * This command checks if the following part of the firmware is already up to
 * date. It must be called exactly in the order it occurs in the BF2 file: If the
 * firmware is split in 2 parts and this command is in between them, it has to be
 * called after transferring the first part and before loading the second part.
 * Otherwise it is not guaranteed that it works correctly.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] VersionDesc A pattern that describes the firmware version of the following firmware part. Should not be interpreted by user software!
 * @param[in] VersionDesc_len 
 */
brp_errcode brp_Main_IsFirmwareUpToDate(brp_protocol protocol, brp_buf VersionDesc, size_t VersionDesc_len);
/**
 * @anchor Main_Bf3UploadStart
 * This command starts the upload of a BEC2/BF3 file to update the reader's
 * configuration and/or firmware.  
 * The reader responds by requesting the first data block within the BEC2/BF3
 * file. To transfer this data block, run the
 * [Main.Bf3UploadContinue](@ref Main_Bf3UploadContinue) command afterwards.
 * 
 * **For more details about implementation, please refer to the help topic[
 * Implement wired upload via the
 * host](https://docs.baltech.de/developers/implement-wired-upload.html) .**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ReqDataAdr Start byte of first data block requested by the reader
 * @param[out] ReqDataLen Number of bytes of first data block requested by the reader
 */
brp_errcode brp_Main_Bf3UploadStart(brp_protocol protocol, unsigned* ReqDataAdr, unsigned* ReqDataLen);
/**
 * @anchor Main_Bf3UploadContinue
 * This command is used to transfer the data of a BEC2/BF3 file block by block to
 * the reader.  
 * The host transfers the data block of the BEC2/BF3 file which has been
 * requested by the reader previously. The response parameter _RequiredAction_
 * indicates how the host has to proceed afterwards:
 * 
 *   * Transfer the next data block. 
 *   * Disconnect and reconnect to the reader. 
 *   * Upload completed - no more data to transfer. 
 * 
 * **For more details about implementation, please refer to the help topic[
 * Implement wired upload via the
 * host](https://docs.baltech.de/developers/implement-wired-upload.html) .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DataAdr Address of data block that is being transferred. Has to correspond to the _ReqDataAdr_ parameter in the reader's response to the previous command (i.e. the last _Bf3UploadContinue_ or the [Main.Bf3UploadStart](@ref Main_Bf3UploadStart) command).
 * @param[in] Data Data requested by the reader
 * @param[in] Data_len 
 * @param[out] Reconnect If _true_ , the host has to disconnect and reconnect to the reader.
 * @param[out] Continue If _true_ , the host has to continue by transferring the next data block of the BEC2/BF3 file.  If _false_ , the reader has received all required data blocks: Upload is completed.
 * @param[out] ReqDataAdr Start byte of next data block requested by the reader
 * @param[out] ReqDataLen Number of bytes of next data block requested by the reader. This value may also be 0.
 * @param[out] ContainsEstimation If _true_ , the response contains estimation information fields.
 * @param[out] ContainsReconnectRetryTimeout If _true_ , the response contains the _ReconnectRetryTimeout_ field.
 * @param[out] ReconnectRetryTimeout If a reconnect is requested, this field specifies how long the host has to try (time period in ms).  **You need to add the _ReconnectRetryTimout_ to the OS-specific base reconnect timeout.   For Windows, we recommend a base reconnect timeout of 10000 ms. For all other platforms, please check how long it takes for a reader to be available again after a reboot.**
 * @param[out] EstimatedNumberOfBytes This is an estimation of the total amount of data bytes that have to be transferred from the host to the reader to upload the current BEC2/BF3 file.  **  This information is only returned once as soon as the reader has gathered enough data to perform this estimation.  _Note:_   In special cases, e.g. if you re-perform a firmware upload that was aborted before, the reader returns a worst-case estimation that may be higher than the actual amount of data bytes to transfer.  **
 * @param[out] EstimatedTimeOverhead This is an estimation of the total time in ms the reader requires for additional internal tasks during the upload, which lead to occasional communication pauses.  If the reader can maintain communication during such a task, it keeps responding to calls of the _Bf3UploadContinue_ command; the _ReqDataLen_ response parameter will then be set to _0_. If the reader can't maintain communication, it asks for a reconnect with an additional retry timeout, which is indicated by the optional _ReconnectRetryTimeout_ parameter.  **This information is only returned once as soon as the reader has gathered enough data to perform this estimation.**
 */
brp_errcode brp_Main_Bf3UploadContinue(brp_protocol protocol, unsigned DataAdr, brp_buf Data, size_t Data_len, bool* Reconnect, bool* Continue, unsigned* ReqDataAdr, unsigned* ReqDataLen, bool* ContainsEstimation, bool* ContainsReconnectRetryTimeout, unsigned* ReconnectRetryTimeout, unsigned* EstimatedNumberOfBytes, unsigned* EstimatedTimeOverhead);
#endif
/**
 * @}
 */
