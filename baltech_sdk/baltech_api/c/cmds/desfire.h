/**
 * @file
 * @anchor Desfire
 * With this command group, you can access MIFARE DESFire cards in low-level
 * mode.
 * 
 * You can use these commands to completely manage the card's cryptographic
 * functionality and to simplify the handling of DESFire cards.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_DESFIRE_H__
#define __BRP_BALTECH_API_CMDS_DESFIRE_H__
#include "../typedefs.h"
/**
 * @anchor Desfire_ErrIso14NoTag
 * There's no card in the HF field, or the card doesn't respond.
 */
#define BRP_Desfire_ErrIso14NoTag BRP_ERR_STATUS(0x1B00, 0x01)
/**
 * @anchor Desfire_ErrBreak
 * The command has been aborted because the HF interface has been requested by
 * another task or command. Please reselect the card.
 * 
 * **This error only occurs when you combine VHL and low-level commands. We
 * highly recommend you avoid that combination as these 2 command sets will
 * interfere with each other's card states.**
 */
#define BRP_Desfire_ErrBreak BRP_ERR_STATUS(0x1B00, 0x03)
/**
 * @anchor Desfire_ErrIso14Hf
 * The response frame received from the PICC is invalid, e.g. it may contain an
 * invalid number of bits. Please rerun the command.
 */
#define BRP_Desfire_ErrIso14Hf BRP_ERR_STATUS(0x1B00, 0x04)
/**
 * @anchor Desfire_ErrIso14CardInvalid
 * The card behaves in an unspecified way or is corrupted. Please rerun the
 * command or reselect the card.
 */
#define BRP_Desfire_ErrIso14CardInvalid BRP_ERR_STATUS(0x1B00, 0x05)
/**
 * @anchor Desfire_ErrReaderChipCommunication
 * Communication with the reader's HF interface has failed. Please reset the HF
 * interface with [Sys.HFReset](@ref Sys_HFReset) and check the reader
 * status with [Sys.GetBootStatus](@ref Sys_GetBootStatus).
 */
#define BRP_Desfire_ErrReaderChipCommunication BRP_ERR_STATUS(0x1B00, 0x06)
/**
 * @anchor Desfire_ErrIso14ApduCmd
 * ISO 14443-4 error: The command or parameters are invalid.
 */
#define BRP_Desfire_ErrIso14ApduCmd BRP_ERR_STATUS(0x1B00, 0x07)
/**
 * @anchor Desfire_ErrIso14InvalidResponse
 * ISO 14443-4 error: The card returned an invalid response, e.g. data with an
 * invalid length. This may have several reasons, e.g. a wrong card type.
 */
#define BRP_Desfire_ErrIso14InvalidResponse BRP_ERR_STATUS(0x1B00, 0x08)
/**
 * @anchor Desfire_ErrPcdAuthentication
 * Authentication with the PICC has failed, e.g. because the encryption algorithm
 * or key is wrong.
 */
#define BRP_Desfire_ErrPcdAuthentication BRP_ERR_STATUS(0x1B00, 0x09)
/**
 * @anchor Desfire_ErrIntegrity
 * Secure messaging error: The CRC or MAC checksum doesn't match the transmitted
 * data. Authentication has been lost. Please reauthenticate and rerun the
 * commands.
 */
#define BRP_Desfire_ErrIntegrity BRP_ERR_STATUS(0x1B00, 0x0A)
/**
 * @anchor Desfire_ErrPcdKey
 * The key in the SAM/crypto memory is invalid or missing.
 */
#define BRP_Desfire_ErrPcdKey BRP_ERR_STATUS(0x1B00, 0x0B)
/**
 * @anchor Desfire_ErrNoChanges
 * Card error as per DESFire specification: No changes done to backup files,
 * CommitTransaction / AbortTransaction not necessary.
 */
#define BRP_Desfire_ErrNoChanges BRP_ERR_STATUS(0x1B00, 0x0C)
/**
 * @anchor Desfire_ErrPcdParam
 * The BRP command contains an invalid parameter.
 */
#define BRP_Desfire_ErrPcdParam BRP_ERR_STATUS(0x1B00, 0x0D)
/**
 * @anchor Desfire_VcsAndProxCheckError
 * The proximity check has timed out. Please reselect the card.
 */
#define BRP_Desfire_VcsAndProxCheckError BRP_ERR_STATUS(0x1B00, 0x0F)
/**
 * @anchor Desfire_ErrFirmwareNotSupported
 * This command or parameter isn't supported by the reader firmware.
 */
#define BRP_Desfire_ErrFirmwareNotSupported BRP_ERR_STATUS(0x1B00, 0x10)
/**
 * @anchor Desfire_ErrSamCommunication
 * Communication with the SAM has failed. This may have several reasons, e.g. the
 * wrong SAM type or a failure to activate the SAM. Please check the SAM status
 * and reset the reader with [Sys.Reset](@ref Sys_Reset).
 */
#define BRP_Desfire_ErrSamCommunication BRP_ERR_STATUS(0x1B00, 0x11)
/**
 * @anchor Desfire_ErrSamUnlock
 * Unlocking/authenticating with the SAM has failed. Please check the
 * __SamAVx__ configuration values.
 */
#define BRP_Desfire_ErrSamUnlock BRP_ERR_STATUS(0x1B00, 0x12)
/**
 * @anchor Desfire_ErrHardwareNotSupported
 * This command isn't supported by the reader hardware.
 * 
 * **This error may refer to any hardware component.**
 */
#define BRP_Desfire_ErrHardwareNotSupported BRP_ERR_STATUS(0x1B00, 0x13)
/**
 * @anchor Desfire_ErrIllegalCmdLegacy
 * Card error as per DESFire specification: Command code not supported by card.
 * This status code is identical to ErrIllegalCmd (0x33) und returned be older
 * firmware versions.
 */
#define BRP_Desfire_ErrIllegalCmdLegacy BRP_ERR_STATUS(0x1B00, 0x1C)
/**
 * @anchor Desfire_ErrLength
 * Card error as per DESFire specification: Length of command string invalid.
 */
#define BRP_Desfire_ErrLength BRP_ERR_STATUS(0x1B00, 0x20)
/**
 * @anchor Desfire_ErrPermissionDenied
 * Card error as per DESFire specification: Current configuration/state does not
 * allow the requested command.
 */
#define BRP_Desfire_ErrPermissionDenied BRP_ERR_STATUS(0x1B00, 0x21)
/**
 * @anchor Desfire_ErrParameter
 * Card error as per DESFire specification: Value of the parameter invalid.
 */
#define BRP_Desfire_ErrParameter BRP_ERR_STATUS(0x1B00, 0x22)
/**
 * @anchor Desfire_ErrAppNotFound
 * Card error as per DESFire specification: Requested AID not present on PICC.
 */
#define BRP_Desfire_ErrAppNotFound BRP_ERR_STATUS(0x1B00, 0x23)
/**
 * @anchor Desfire_ErrAppIntegrity
 * Card error as per DESFire specification: Unrecoverable error in application.
 * Application will be disabled.
 */
#define BRP_Desfire_ErrAppIntegrity BRP_ERR_STATUS(0x1B00, 0x24)
/**
 * @anchor Desfire_ErrAuthentication
 * Card error as per DESFire specification: Current authentication status does
 * not allow execution of requested command.
 */
#define BRP_Desfire_ErrAuthentication BRP_ERR_STATUS(0x1B00, 0x25)
/**
 * @anchor Desfire_ErrBoundary
 * Card error as per DESFire specification: Attempted to read/write beyond the
 * limits of the file.
 */
#define BRP_Desfire_ErrBoundary BRP_ERR_STATUS(0x1B00, 0x27)
/**
 * @anchor Desfire_ErrPiccIntegrity
 * Card error as per DESFire specification: Unrecoverable error within PICC, PICC
 * will be disabled.
 */
#define BRP_Desfire_ErrPiccIntegrity BRP_ERR_STATUS(0x1B00, 0x28)
/**
 * @anchor Desfire_ErrCommandAborted
 * Card error as per DESFire specification: Previous command was not fully
 * completed. Not all frames were requested or provided by the reader.
 */
#define BRP_Desfire_ErrCommandAborted BRP_ERR_STATUS(0x1B00, 0x29)
/**
 * @anchor Desfire_ErrPiccDisabled
 * Card error as per DESFire specification: PICC was disabled by an unrecoverable
 * error.
 */
#define BRP_Desfire_ErrPiccDisabled BRP_ERR_STATUS(0x1B00, 0x2A)
/**
 * @anchor Desfire_ErrCount
 * Card error as per DESFire specification: Number of applications limited to 28,
 * no additional CreateApplication possible.
 */
#define BRP_Desfire_ErrCount BRP_ERR_STATUS(0x1B00, 0x2B)
/**
 * @anchor Desfire_ErrDuplicate
 * Card error as per DESFire specification: Creation of file/application failed
 * because file/application with same number already exists.
 */
#define BRP_Desfire_ErrDuplicate BRP_ERR_STATUS(0x1B00, 0x2C)
/**
 * @anchor Desfire_ErrEeprom
 * Card error as per DESFire specification: Could not complete NV-write operation
 * due to loss of power, internal backup/rollback mechanism activated.
 */
#define BRP_Desfire_ErrEeprom BRP_ERR_STATUS(0x1B00, 0x2D)
/**
 * @anchor Desfire_ErrFileNotFound
 * Card error as per DESFire specification: Specified file number does not exist.
 */
#define BRP_Desfire_ErrFileNotFound BRP_ERR_STATUS(0x1B00, 0x2E)
/**
 * @anchor Desfire_ErrFileIntegrity
 * Card error as per DESFire specification: Unrecoverable error within file, file
 * will be disabled.
 */
#define BRP_Desfire_ErrFileIntegrity BRP_ERR_STATUS(0x1B00, 0x2F)
/**
 * @anchor Desfire_ErrNoSuchKey
 * Card error as per DESFire specification: Invalid key number specified.
 */
#define BRP_Desfire_ErrNoSuchKey BRP_ERR_STATUS(0x1B00, 0x30)
/**
 * @anchor Desfire_ErrOutOfMemory
 * Card error as per DESFire specification: Insufficient NV-Memory to complete
 * command .
 */
#define BRP_Desfire_ErrOutOfMemory BRP_ERR_STATUS(0x1B00, 0x32)
/**
 * @anchor Desfire_ErrIllegalCmd
 * Card error as per DESFire specification: Command code not supported by card.
 */
#define BRP_Desfire_ErrIllegalCmd BRP_ERR_STATUS(0x1B00, 0x33)
/**
 * @anchor Desfire_ErrCmdOverflow
 * Card error as per DESFire specification: Too many commands in the session or
 * transaction.
 */
#define BRP_Desfire_ErrCmdOverflow BRP_ERR_STATUS(0x1B00, 0x34)
/**
 * @anchor Desfire_ExecCommand
 * Generic command to communicate to a DESFire card. Depending on the value of
 * the _CryptoMode_ parameter, data will be transmitted plain, MACed or
 * encrypted.
 * 
 * The DESFire command frame has to be split into two parts, header and data. The
 * data block will be encrypted whereas the header block is left unencrypted.
 * 
 * Example: in the Desfire _ChangeKeySettings_ command, the header is empty. The
 * encrypted key settings will be transferred in the data block.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Cmd DESFire Command code
 * @param[in] Header Header of command. The header is always sent bufunencrypted. It must not be larger than 59 bytes.
 * @param[in] Header_len 
 * @param[in] Param Parameter data of command (will be encrypted or MACed according to the value of the _CryptoMode_ variable).
 * @param[in] Param_len 
 * @param[in] CryptoMode Type of encryption.
 * @param[in] ResponseLen Expected length of response. For commands where the length of the response is not known by the host (i.e. [Desfire.ReadData](@ref Desfire_ReadData) with _Len_ = 0), this value has to be set to 0xFFFF.
 * @param[out] Resp Response of command.
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Desfire_ExecCommand(brp_protocol protocol, unsigned Cmd, brp_buf Header, size_t Header_len, brp_buf Param, size_t Param_len, brp_Desfire_ExecCommand_CryptoMode CryptoMode, unsigned ResponseLen, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
/**
 * @anchor Desfire_Authenticate
 * This command authenticates a card with the reader. All authentication modes of
 * DESFire cards are supported. Subsequent commands, such as
 * [Desfire.ExecCommand](@ref Desfire_ExecCommand), take the authentication mode
 * into account when communicating with a card.
 * 
 * The key used for authentication is specified in the __Device /
 * CryptoKey__ key of the reader's
 * configuration.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecureMessaging Sets the secure messaging mode.
 * @param[in] DesKeynr DESFire key number.
 * @param[in] KeyId ID of authentication key in the reader's configuration (0x00-0xBF).
 * @param[in] KeyHasDivData Specifies external diversification data (_KeyDivData_ parameter) if set.
 * @param[in] KeyDivMode Specifies diversification algorithm.
 * @param[in] KeyHasExtIdx Set this flag if extended crypto memory is used (using _KeyExtIdx_ parameter).
 * @param[in] KeyDivData Diversification data (8 byte for DES / 16 for AES key).
 * @param[in] KeyDivData_len 
 * @param[in] KeyExtIdx Crypto Memory Index (SAM or CryptoMemory) of authentication key    * SAM: Key version (0..0xFF)    * Crypto Memory: Page (0..15)
 */
brp_errcode brp_Desfire_Authenticate(brp_protocol protocol, brp_Desfire_Authenticate_SecureMessaging SecureMessaging, unsigned DesKeynr, unsigned KeyId, bool KeyHasDivData, brp_Desfire_Authenticate_KeyDivMode KeyDivMode, bool KeyHasExtIdx, brp_buf KeyDivData, size_t KeyDivData_len, unsigned KeyExtIdx);
/**
 * @anchor Desfire_AuthExtKey
 * This command authenticates a card with the reader, similarly to the
 * [Desfire.Authenticate](@ref Desfire_Authenticate) command, but uses an external
 * authentication key provided as a parameter. Allowed are keys with a length of
 * 8, 16 and 24 Byte.
 * 
 *   * 8 Byte keys are always DES keys. 
 *   * 16 Byte keys can be DES and AES keys. 
 *   * 24 Byte keys are only used for 3K3DES encryption.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecureMessaging Sets the secure messaging mode.
 * @param[in] DesKeyNr DESFire key number (0-13).
 * @param[in] CryptoMode Sets the encryption algorithm.
 * @param[in] Key Key to use for authentication
 * @param[in] Key_len 
 */
brp_errcode brp_Desfire_AuthExtKey(brp_protocol protocol, brp_Desfire_AuthExtKey_SecureMessaging SecureMessaging, unsigned DesKeyNr, brp_Desfire_AuthExtKey_CryptoMode CryptoMode, brp_buf Key, size_t Key_len);
/**
 * @anchor Desfire_SelectApplication
 * Selects an application of the DESFire card. Has to be called before any file
 * specific command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AppId ID of application to select - range from 0x00000000 to 0x00FFFFFF. The value 0 corresponds to the Master application (PICC level, root directory).
 */
brp_errcode brp_Desfire_SelectApplication(brp_protocol protocol, unsigned AppId);
/**
 * @anchor Desfire_ReadData
 * Reads data from a Standard or Backup data file.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId ID of file to read.
 * @param[in] Adr Offset position within file. Ranges from 0x000000 to (file size -1).
 * @param[in] Len Length of data to read. If _Len_ = 0, the entire data starting from the offset position will be read.
 * @param[in] Mode Communication settings linked to the file.
 * @param[out] Data Data read from card.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Desfire_ReadData(brp_protocol protocol, unsigned FileId, unsigned Adr, unsigned Len, brp_Desfire_ReadData_Mode Mode, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor Desfire_WriteData
 * Writes data to a Standard or a Backup data file.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileId ID of file to read.
 * @param[in] Adr Position within file.
 * @param[in] Data Data read from card.
 * @param[in] Data_len 
 * @param[in] Mode Communication settings linked to the file.
 */
brp_errcode brp_Desfire_WriteData(brp_protocol protocol, unsigned FileId, unsigned Adr, brp_buf Data, size_t Data_len, brp_Desfire_WriteData_Mode Mode);
/**
 * @anchor Desfire_ChangeExtKey
 * This command allows to change any key stored on the card.
 * 
 * The key length has to be set according to the desired encryption algorithm:
 * 
 *   * DES encryption uses keys of 8 Byte. 
 *   * 3DES and AES encryption uses keys of 16 Byte. 
 *   * 3K3DES encryption uses keys of 24 Byte.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] MasterKeyType These bits must only be set if the card's Master Key is changed. They specify the type of the new card's Master Key.
 * @param[in] IsKeySet Only needed for Desfire EV2 with multiple Keysets. If _true_ ,the reader executes the Desfire "ChangeKeyEV2" command instead of the Desfire "ChangeKey" command.
 * @param[in] IsAesKey Has to be set if the new key is an AES key.
 * @param[in] IsVersion Has to be set if the _NewKeyVersion_ parameter is present.
 * @param[in] IsChangeKey Has to be set if the key used to authenticate the card is the key that needs to be changed (as specified in _KeyNo_).  In this case, the parameter _OldKey_ has to be omitted.
 * @param[in] KeyNo Number of key (0-13) to modify. Has to be 0 if the application Master Key is changed.
 * @param[in] KeyVersion Version of the new key.  Remarks:    * If this value is not available (i.e. if _IsVersion_ is not set), 0 will be assumed as _NewKeyVersion_.
 * @param[in] NewKey New key (16 bytes).
 * @param[in] NewKey_len 
 * @param[in] OldKey Current key (16 bytes).
 * @param[in] OldKey_len 
 * @param[in] KeySet specifies KeySet needed for multiple keysets (EV2 extension).
 */
brp_errcode brp_Desfire_ChangeExtKey(brp_protocol protocol, brp_Desfire_ChangeExtKey_MasterKeyType MasterKeyType, bool IsKeySet, bool IsAesKey, bool IsVersion, bool IsChangeKey, unsigned KeyNo, unsigned KeyVersion, brp_buf NewKey, size_t NewKey_len, brp_buf OldKey, size_t OldKey_len, unsigned KeySet);
/**
 * @anchor Desfire_ChangeKey
 * Modifies a DESFire card key defined in the SAM or crypto memory.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] IsKeySet Only needed for Desfire EV2 with multiple Keysets. If _true_ ,the reader executes the Desfire "ChangeKeyEV2" command instead of the Desfire "ChangeKey" command.
 * @param[in] IsMasterKey Has to be set if the key to change is the PICC Master Key.
 * @param[in] IsChangeKey Has to be set if the key used to authenticate the card is the key that needs to be changed (as specified in _KeyNo_).  In this case, the parameter _CurKeyIdx_ has to be omitted.
 * @param[in] KeyNr Number of card key (0-13) to change.
 * @param[in] NewKeyDivMode Specifies diversification algorithm.
 * @param[in] NewKeyHasDivData Activates key diversification according to NXP AN10922.
 * @param[in] NewKeyHasExtIdx Activates key memory expansion.
 * @param[in] NewKeyIdx Index of key in the reader's SAM or crypto memory (configuration range 0x00-0xBF).
 * @param[in] CurKeyDivMode Specifies diversification algorithm.
 * @param[in] CurKeyHasDivData Activates key diversification according to NXP AN10922.
 * @param[in] CurKeyHasExtIdx Activates key memory expansion.
 * @param[in] CurKeyIdx Index of key in the reader's SAM or crypto memory (configuration range 0x00-0xBF).
 * @param[in] NewKeyDivData Diversification data of the new key.
 * @param[in] NewKeyDivData_len 
 * @param[in] CurKeyDivData Diversification data of the current key.
 * @param[in] CurKeyDivData_len 
 * @param[in] NewKeyExtIdx Crypto Memory Index (SAM or CryptoMemory) of new key    * SAM: Key version (0..0xFF)    * Crypto Memory: Page (0..15)
 * @param[in] CurKeyExtIdx Crypto Memory Index (SAM or CryptoMemory) of current key    * SAM: Key version (0..0xFF)    * Crypto Memory: Page (0..15)
 * @param[in] KeySet specifies a KeySet (needed for multiple keysets - EV2 extension).
 */
brp_errcode brp_Desfire_ChangeKey(brp_protocol protocol, bool IsKeySet, bool IsMasterKey, bool IsChangeKey, unsigned KeyNr, brp_Desfire_ChangeKey_NewKeyDivMode NewKeyDivMode, bool NewKeyHasDivData, bool NewKeyHasExtIdx, unsigned NewKeyIdx, brp_Desfire_ChangeKey_CurKeyDivMode CurKeyDivMode, bool CurKeyHasDivData, bool CurKeyHasExtIdx, unsigned CurKeyIdx, brp_buf NewKeyDivData, size_t NewKeyDivData_len, brp_buf CurKeyDivData, size_t CurKeyDivData_len, unsigned NewKeyExtIdx, unsigned CurKeyExtIdx, unsigned KeySet);
/**
 * @anchor Desfire_SetFraming
 * This command switches the DESFire communication protocol mode to use (std,
 * iso_wrapping). Please refer to the [DESFire
 * specification](http://www.nxp.com/products/identification-and-security/smart-
 * card-ics/mifare-ics/mifare-desfire:MC_53450) for more information.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CommMode Defines 14443-4 communication mode to DESFire card.
 */
brp_errcode brp_Desfire_SetFraming(brp_protocol protocol, brp_Desfire_SetFraming_CommMode CommMode);
/**
 * @anchor Desfire_ResetAuthentication
 * This command resets the reader's authentication state until the next call of
 * the [Desfire.Authenticate](@ref Desfire_Authenticate) or
 * [Desfire.AuthExtKey](@ref Desfire_AuthExtKey) commands. All following DESFire
 * commands will be sent and received in plain text without MAC.
 * 
 * It is not possible to run the [Desfire.ExecCommand](@ref Desfire_ExecCommand)
 * with _CryptoMode_ set to any other value than PLAIN after the execution of
 * this command, until the card is reauthenticated.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Desfire_ResetAuthentication(brp_protocol protocol);
/**
 * @anchor Desfire_CreateDam
 * This command creates a delegated application
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AppId ID of application to select - range from 0x00000001 to 0x00FFFFFF.
 * @param[in] AppParams Paramters for the delegated application
 * @param[in] AppParams_len 
 * @param[in] EncryptedDefaultDamKey Encrypted default DAM key (usually provided by the card issuer)
 * @param[in] EncryptedDefaultDamKey_len 
 * @param[in] DamMacKey Mac for DAM creation (usually provided by the card issuer)
 * @param[in] DamMacKey_len 
 */
brp_errcode brp_Desfire_CreateDam(brp_protocol protocol, unsigned AppId, brp_buf AppParams, size_t AppParams_len, brp_buf EncryptedDefaultDamKey, size_t EncryptedDefaultDamKey_len, brp_buf DamMacKey, size_t DamMacKey_len);
/**
 * @anchor Desfire_GetOriginalitySignature
 * This command returns the NXP originality signature of a desfire card.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Signature Card signature.
 * @param[out] Signature_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Desfire_GetOriginalitySignature(brp_protocol protocol, brp_buf* Signature, size_t* Signature_len, brp_mempool *mempool);
/**
 * @anchor Desfire_VirtualCardSelect
 * This command selects a virtual card
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ForceVcsAuthentication Forces authentication to a virtual card. A card without encryption returns [Desfire.VcsAndProxCheckError](@ref Desfire_VcsAndProxCheckError)
 * @param[in] UseExtVcSelectKeys Authenticates to a virtual card. A MAC and a encryption key has to be specified. Use (external) Virtual Card keys given as command parameter.
 * @param[in] DiversifyMacKey Diversifies VC Mac key.  Remarks for use of divinput:  VC-UID is obtained by decryption of the card response. If VC-UID is concatenated with divinput the input wil be limited to 31 bytes.
 * @param[in] DiversifyEncKey Diversifies VC Encryption key
 * @param[in] UseVcSelectKeys Authenticates to a virtual card. A MAC and a encryption key has to be specified. Use Keys stored in CryptoMemory or SAM.
 * @param[in] IID Virtual Card Identifier.
 * @param[in] IID_len 
 * @param[in] EncKeyIdx Crypto Memory Index (SAM or CryptoMemory) of virtual card select key    * SAM: MSByte: Key version / LSByte: KeyIdx    * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
 * @param[in] MacKeyIdx Crypto Memory Index (SAM or CryptoMemory) of MAC key    * SAM: MSByte: Key version / LSByte: KeyIdx    * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
 * @param[in] DivData Key diversification according to NXP AN10922.
 * @param[in] DivData_len 
 * @param[in] EncKey VC encryption key
 * @param[in] EncKey_len 
 * @param[in] MacKey VC MAC key
 * @param[in] MacKey_len 
 * @param[out] FciType 0: raw data 1: uid_len(1) and card type(1) 2: uid_len(1), card type(1) and memory size(1)
 * @param[out] Fci File control information
 * @param[out] Fci_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Desfire_VirtualCardSelect(brp_protocol protocol, bool ForceVcsAuthentication, bool UseExtVcSelectKeys, unsigned DiversifyMacKey, bool DiversifyEncKey, bool UseVcSelectKeys, brp_buf IID, size_t IID_len, unsigned EncKeyIdx, unsigned MacKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf EncKey, size_t EncKey_len, brp_buf MacKey, size_t MacKey_len, unsigned* FciType, brp_buf* Fci, size_t* Fci_len, brp_mempool *mempool);
/**
 * @anchor Desfire_ProxCheck
 * This command executes a proximity check of the card
 * 
 * @param[in] protocol used to execute the command
 * @param[in] M Number of random bytes which are send within one procimity check round.
 * @param[in] UseExtProxKey Use (external) Proximity key given as command parameter.  If the card is already authenticated (Card Authentication), do not activate this option.
 * @param[in] DiversifyProxKey Key diversification of the proximity key defined in Crypto Memory or SAM will be done according to NXP AN10922.
 * @param[in] UseProxKey Proximity key is defined in Crypto Memory or SAM.  If the card is already authenticated (VC Selection or Card Authentication), do not activate this option.
 * @param[in] ProxKeyIdx Crypto Memory Index (SAM or CryptoMemory) of proximity check key    * SAM: MSByte: Key version / LSByte: KeyIdx    * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
 * @param[in] DivData Key diversification according to NXP AN10922.
 * @param[in] DivData_len 
 * @param[in] ProxKey Proximity check key
 * @param[in] ProxKey_len 
 */
brp_errcode brp_Desfire_ProxCheck(brp_protocol protocol, unsigned M, bool UseExtProxKey, bool DiversifyProxKey, bool UseProxKey, unsigned ProxKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf ProxKey, size_t ProxKey_len);
/**
 * @anchor Desfire_GetDfNames
 * This command returns the application identifiers together with file IDs and
 * (optionally) DF names of all applications with ISO7816-4 support.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] AppNr 
 * @param[out] AppNr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Desfire_GetDfNames(brp_protocol protocol, brp_Desfire_GetDfNames_AppNr_Entry** AppNr, size_t* AppNr_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
