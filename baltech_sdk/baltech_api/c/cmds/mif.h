/**
 * @file
 * @anchor Mif
 * With this command group, you can access MIFARE cards in low-level mode.
 * 
 * Whenever a card enters the HF field, it will be in _idle state_. From the idle
 * state, a card switches to the _requested state_ as soon as the
 * [Mif.Request](@ref Mif_Request) command is executed. Cards in requested state
 * participate in the anti-collision sequence, controlled by the
 * [Mif.Anticoll](@ref Mif_Anticoll) command, resulting in an unambiguous serial
 * number belonging to one of the cards in the HF field. The card with this
 * serial number may now be selected with the [Mif.Select](@ref Mif_Select) command.
 * All other cards will fall back to idle state again and wait for the next call
 * of the [Mif.Request](@ref Mif_Request) command. The selected card, however,
 * changes from requested state to _selected state_.
 * 
 * **The[ Mif.Anticoll](@ref Mif_Anticoll) and[ Mif.Select](@ref Mif_Select) commands
 * can only process serial numbers with a length of 4 bytes. Since 2010, however,
 * MIFARE cards with a 7-byte serial number are available. Please use the[ ISO
 * 14443-3 (Type A) command group](@ref Iso14a) to select and process
 * cards with 7-byte serial numbers.**
 * 
 * When a card is in selected state, communication with the card is possible.
 * Nevertheless, it is necessary to be authenticated before a sector of the card
 * can be accessed. Authentication can be performed either with the
 * [Mif.AuthE2](@ref Mif_AuthE2) command or with the [Mif.AuthUser](@ref Mif_AuthUser)
 * command. Both commands send a key to the currently selected card along with
 * information regarding whether this key should be compared to key A or key B on
 * the card. If the given key matches the corresponding sector's key (either key
 * A or key B, as specified in the command's parameters), then access according
 * to the access conditions of the desired sector will be granted.
 * 
 * Finally, a card that is in select state can be set to _halt state_. A card in
 * halt state will not respond to any command unless a specially parameterized
 * [Mif.Request](@ref Mif_Request) command is called, or when it leaves and then re-
 * enters the HF field of the reader's antenna. The halt state is helpful when it
 * is necessary to deal with multiple cards present in the reader's antenna HF
 * field.
 * 
 * The [Mif.Read](@ref Mif_Read) and [Mif.Write](@ref Mif_Write) commands can be use to
 * read/write data from/to a certain block. Additionally, a data sector may be
 * turned into a special _value sector_ (also called _value block_), which is
 * initialized with a specific starting value and can then only be changed by
 * means of _increment_ and _decrement_ operations using the _ChangeValue_ or
 * _ChangeValueBackup_ commands. Value sectors are very useful in some scenarios,
 * such as for cash-based applications. To create a value sector, it is simply
 * required to write specially formatted data to it:
 * 
 *   * The first 4 bytes (bytes 0-3) represent the initially stored value. 
 *   * The following 4 bytes (bytes 4-7) have to be the _two's complement_ of the first 4 bytes. 
 *   * The next 4 bytes (bytes 8-11) are a copy of the first 4 bytes. 
 *   * The last 4 bytes (bytes 12-15) contain the 1-byte address of a block which can be used for backup management. This address is stored on both byte 12 and byte 14, while its two's complement is stored on both byte 13 and byte 15. These 4 bytes are not affected by calls of the [Mif.ChangeValue](@ref Mif_ChangeValue) and [Mif.ChangeValueBackup](@ref Mif_ChangeValueBackup) commands. 
 * 
 * Each increment and decrement operation has to be followed by a _transfer_
 * operation, using the [Mif.TransferBlock](@ref Mif_TransferBlock) command, in
 * order to make the increment/decrement persistent. This feature guarantees that
 * no data will be lost during a recalculation of the value on the card.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_MIF_H__
#define __BRP_BALTECH_API_CMDS_MIF_H__
#include "../typedefs.h"
/**
 * @anchor Mif_ErrNoTag
 * There's no card in the HF field, or the card doesn't respond.
 */
#define BRP_Mif_ErrNoTag BRP_ERR_STATUS(0x1000, 0x01)
/**
 * @anchor Mif_ErrCrc
 * The response frame is invalid, e.g. it may contain an invalid CRC checksum.
 * Please rerun the command.
 */
#define BRP_Mif_ErrCrc BRP_ERR_STATUS(0x1000, 0x02)
/**
 * @anchor Mif_ErrAuth
 * Card authentication has failed.
 */
#define BRP_Mif_ErrAuth BRP_ERR_STATUS(0x1000, 0x04)
/**
 * @anchor Mif_ErrParity
 * Legacy error code: The parity bits don't match the transmitted data.
 * Authentication has been lost. Please reauthenticate and rerun the commands.
 */
#define BRP_Mif_ErrParity BRP_ERR_STATUS(0x1000, 0x05)
/**
 * @anchor Mif_ErrCode
 * The card behaves in an unspecified way. Please rerun the command or reselect
 * the card.
 */
#define BRP_Mif_ErrCode BRP_ERR_STATUS(0x1000, 0x06)
/**
 * @anchor Mif_ErrSnr
 * Legacy error code: The serial number is wrong.
 */
#define BRP_Mif_ErrSnr BRP_ERR_STATUS(0x1000, 0x08)
/**
 * @anchor Mif_ErrKey
 * The key in the SAM/crypto memory is invalid or missing.
 */
#define BRP_Mif_ErrKey BRP_ERR_STATUS(0x1000, 0x09)
/**
 * @anchor Mif_ErrNotauth
 * Card authentication has failed. The current configuration/state doesn't allow
 * the requested command.
 */
#define BRP_Mif_ErrNotauth BRP_ERR_STATUS(0x1000, 0x0A)
/**
 * @anchor Mif_ErrBitcount
 * Legacy error code: HF data transition error. The number of received bits is
 * invalid.
 */
#define BRP_Mif_ErrBitcount BRP_ERR_STATUS(0x1000, 0x0B)
/**
 * @anchor Mif_ErrBytecount
 * Legacy error code: HF data transition error. The number of received bytes is
 * invalid.
 */
#define BRP_Mif_ErrBytecount BRP_ERR_STATUS(0x1000, 0x0C)
/**
 * @anchor Mif_VcsAndProxCheckError
 * The proximity check has timed out. Please reselect the card.
 */
#define BRP_Mif_VcsAndProxCheckError BRP_ERR_STATUS(0x1000, 0x0E)
/**
 * @anchor Mif_ErrWrite
 * Writing to the card has failed. Please rerun the command or check the access
 * conditions.
 */
#define BRP_Mif_ErrWrite BRP_ERR_STATUS(0x1000, 0x0F)
/**
 * @anchor Mif_ErrInc
 * Legacy error code: Increment couldn't be performed.
 */
#define BRP_Mif_ErrInc BRP_ERR_STATUS(0x1000, 0x10)
/**
 * @anchor Mif_ErrDecr
 * Legacy error code: Decrement couldn't be performed.
 */
#define BRP_Mif_ErrDecr BRP_ERR_STATUS(0x1000, 0x11)
/**
 * @anchor Mif_ErrRead
 * Reading data from the card has failed. Please rerun the command or check the
 * access conditions.
 */
#define BRP_Mif_ErrRead BRP_ERR_STATUS(0x1000, 0x12)
/**
 * @anchor Mif_ErrOvfl
 * Legacy error code: An overflow occurred during decrement or increment.
 */
#define BRP_Mif_ErrOvfl BRP_ERR_STATUS(0x1000, 0x13)
/**
 * @anchor Mif_ErrFraming
 * The response frame is invalid, e.g. it may contain an invalid number of bits.
 * Please rerun the command.
 */
#define BRP_Mif_ErrFraming BRP_ERR_STATUS(0x1000, 0x15)
/**
 * @anchor Mif_ErrBreak
 * The command has been aborted because the HF interface has been requested by
 * another task or command. Please reselect the card.
 * 
 * **This error only occurs when you combine VHL and low-level commands. We
 * highly recommend you avoid that combination as these 2 command sets will
 * interfere with each other's card states.**
 */
#define BRP_Mif_ErrBreak BRP_ERR_STATUS(0x1000, 0x16)
/**
 * @anchor Mif_ErrCmd
 * The specified command or parameters are unknown.
 */
#define BRP_Mif_ErrCmd BRP_ERR_STATUS(0x1000, 0x17)
/**
 * @anchor Mif_ErrColl
 * An error occurred in the anti-collision sequence. Please reselect the card.
 */
#define BRP_Mif_ErrColl BRP_ERR_STATUS(0x1000, 0x18)
/**
 * @anchor Mif_ErrReaderChipCommunication
 * Communication with the reader's HF interface has failed. Please reset the HF
 * interface with [Sys.HFReset](@ref Sys_HFReset) and check the reader
 * status with [Sys.GetBootStatus](@ref Sys_GetBootStatus).
 */
#define BRP_Mif_ErrReaderChipCommunication BRP_ERR_STATUS(0x1000, 0x1A)
/**
 * @anchor Mif_ErrFirmwareNotSupported
 * This command isn't supported by the reader firmware.
 */
#define BRP_Mif_ErrFirmwareNotSupported BRP_ERR_STATUS(0x1000, 0x1D)
/**
 * @anchor Mif_ErrVal
 * A value operation, e.g. increment or decrement, has failed. This may have
 * several reasons, e.g. an invalid value format, or the value to manipulate
 * doesn't exist on the card.
 */
#define BRP_Mif_ErrVal BRP_ERR_STATUS(0x1000, 0x1E)
/**
 * @anchor Mif_ErrIntegrity
 * Secure messaging error: The CRC or MAC checksum doesn't match the transmitted
 * data. Authentication has been lost. Please reauthenticate and rerun the
 * commands, or check the security conditions.
 */
#define BRP_Mif_ErrIntegrity BRP_ERR_STATUS(0x1000, 0x1F)
/**
 * @anchor Mif_CondNotvalid
 * Card error as per MIFARE specification: Condition of use not satisfied.
 */
#define BRP_Mif_CondNotvalid BRP_ERR_STATUS(0x1000, 0x20)
/**
 * @anchor Mif_ErrHwNotSupported
 * This command isn't supported by the reader hardware, i.e. by the SAM or reader
 * chip.
 */
#define BRP_Mif_ErrHwNotSupported BRP_ERR_STATUS(0x1000, 0x21)
/**
 * @anchor Mif_ErrSamUnlock
 * Unlocking/authenticating with the SAM has failed. Please check the
 * __SamAVx__ configuration values.
 */
#define BRP_Mif_ErrSamUnlock BRP_ERR_STATUS(0x1000, 0x22)
/**
 * @anchor Mif_ErrSamCommunication
 * Communication with the SAM has failed. This may have several reasons, e.g. the
 * wrong SAM type or a failure to activate the SAM. Please check the SAM status
 * and reset the reader with [Sys.Reset](@ref Sys_Reset).
 */
#define BRP_Mif_ErrSamCommunication BRP_ERR_STATUS(0x1000, 0x23)
/**
 * @anchor Mif_LoadKey
 * This command writes a MIFARE Classic key to the reader's secure key memory.
 * The reader can store 32 different keys so the key index must not exceed 31.
 * These keys will be used for the authentication of certain sectors.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIdx Key memory index: address in memory at which to store the key.
 * @param[in] Key The key itself.
 */
brp_errcode brp_Mif_LoadKey(brp_protocol protocol, unsigned KeyIdx, brp_buf Key);
/**
 * @anchor Mif_Request
 * Request labels in the field of the antenna.
 * 
 * _ATQA_ is a two byte value (MSB first). This value is called _tagtype_ and for
 * MIFARE 1 CSCs, it is expected to be equal to 0x0004.
 * 
 * **For new applications, the[ Iso14a.Request](@ref Iso14a_Request)
 * command should be used instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ReqAll If set, all cards (even those in halt state) will be requested. Otherwise, only cards in idle state will be requested.
 * @param[out] ATQA Answer to request.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Mif_Request(brp_protocol protocol, unsigned ReqAll, unsigned* ATQA);
/**
 * @anchor Mif_Anticoll
 * This command performs an anti-collision sequence.
 * 
 * A number of bits equal to the _BitCount_ value will be used in _PreSelSer_ for
 * preselection of cards in the HF field of the antenna. This means that only
 * cards with a serial number matching the first _BitCount_ bits of _PreSelSer_
 * will be taken into consideration. The command returns an unambiguous serial
 * number in the _Snr_ value which may be used for the card selection procedure,
 * using the [Mif.Select](@ref Mif_Select) command.
 * 
 * **For new applications, the[ Iso14a.Anticoll](@ref Iso14a_Anticoll)
 * command should be used instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] BitCount Number of bits to be considered in _PreSelSer_.
 * @param[in] PreSelSer Part of the card's serial number which will be used for preselection of cards. The amount of considered bits is specified by the _BitCount_ value.
 * @param[out] Snr Unambiguous serial number of selected label.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Mif_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelSer, brp_buf* Snr, brp_mempool *mempool);
/**
 * @anchor Mif_Select
 * This command selects a card with a 4 Byte serial number specified in the _Snr_
 * parameter.
 * 
 * **This command is deprecated. For new applications, the[
 * Iso14a.Select](@ref Iso14a_Select) command should be used
 * instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Snr Serial number of card.
 * @param[out] SAK Select Acknowledge (SAK), according to the ISO 14443-3 (Type A) standard.
 */
brp_errcode brp_Mif_Select(brp_protocol protocol, brp_buf Snr, unsigned* SAK);
/**
 * @anchor Mif_AuthE2
 * This command authenticates a certain sector of a card using a key from the
 * secure EEPROM of the Baltech reader chip.
 * 
 * Depending on the value of the _AuthMode_ variable, either key A or key B of
 * the sector specified by the _Block_ variable will be compared to the key
 * specified in _KeyIdx_.
 * 
 * It is only possible to authenticate one sector at a time.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AuthMode Authentication Mode. 0x60: Key A, 0x61: Key B.
 * @param[in] Block Block to authenticate.
 * @param[in] KeyIdx Index of key in EEPROM which shall be used for authentication (range: 0 to 31).
 */
brp_errcode brp_Mif_AuthE2(brp_protocol protocol, unsigned AuthMode, unsigned Block, unsigned KeyIdx);
/**
 * @anchor Mif_AuthUser
 * This command authenticates a certain sector of a card using the key specified
 * in the _Key_ variable.
 * 
 * Depending on the value of the _AuthMode_ variable, either key A or key B of
 * the sector specified by the _Block_ variable will be compared to the key
 * specified in _KeyIdx_.
 * 
 * It is only possible to authenticate one sector at a time.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AuthMode Authentication Mode. 0x60: Key A, 0x61: Key B.
 * @param[in] Block Block to authenticate.
 * @param[in] Key Key to use for authentication.
 */
brp_errcode brp_Mif_AuthUser(brp_protocol protocol, unsigned AuthMode, unsigned Block, brp_buf Key);
/**
 * @anchor Mif_Read
 * This command reads data from a specified block of the currently selected card,
 * providing authentication has been performed beforehand.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Block Block to read.
 * @param[out] BlockData Data of selected block.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_Read(brp_protocol protocol, unsigned Block, brp_buf* BlockData, brp_mempool *mempool);
/**
 * @anchor Mif_Write
 * This command write data to a specified block of the currently selected card,
 * providing authentication has been performed beforehand.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Block Block to write.
 * @param[in] BlockData Data of selected block.
 */
brp_errcode brp_Mif_Write(brp_protocol protocol, unsigned Block, brp_buf BlockData);
/**
 * @anchor Mif_ChangeValue
 * This command uses the value block specified by the _Block_ parameter and
 * performs an operation given by the _Mode_ parameter. The result is stored in
 * the card's Transfer Buffer.
 * 
 * _Mode_ = 1 increments the _value_ , _Mode_ = 0 decrements the value, _Mode_ =
 * 0x02 simply transfers the value to the Transfer Buffer - the _Value_ parameter
 * is ignored.
 * 
 * In order to persistently store the calculated value on the card, a _transfer_
 * operation, using the [Mif.TransferBlock](@ref Mif_TransferBlock) command, has to
 * be performed directly after the completion of this command.
 * 
 * This command can be used for MIFARE Classic cards and only works on value
 * sectors.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode Access mode. Possible values, 0x00: decrement, 0x01: increment, 0x02: restore/load.
 * @param[in] Block Sector to load data from (only value sectors are supported).
 * @param[in] Value Value to add/subtract. This parameter is ignored when _Mode_ = 0x02.
 */
brp_errcode brp_Mif_ChangeValue(brp_protocol protocol, unsigned Mode, unsigned Block, unsigned Value);
/**
 * @anchor Mif_ChangeValueBackup
 * This command is identical to [Mif.ChangeValue](@ref Mif_ChangeValue), but can
 * only be used for MIFARE cards which support automatic transfer, such as _Pro_
 * or _Light_ MIFARE variants.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Mode Access mode. Possible values, 0x00: decrement, 0x01: increment, 0x02: restore/load.
 * @param[in] Block Block to load data from (only value blocks are supported).
 * @param[in] Value Value to add/subtract. This parameter is ignored when _Mode_ = 0x02.
 */
brp_errcode brp_Mif_ChangeValueBackup(brp_protocol protocol, unsigned Mode, unsigned Block, unsigned Value);
/**
 * @anchor Mif_TransferBlock
 * This command transfers data from the card's internal Transfer Buffer to a
 * specified block.
 * 
 * This command needs to be called directly after any operation on the internal
 * data register performed by [Mif.ChangeValue](@ref Mif_ChangeValue) or
 * [Mif.ChangeValueBackup](@ref Mif_ChangeValueBackup) in order to make the results
 * of these commands persistent.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Block Sector to transfer the data to.
 */
brp_errcode brp_Mif_TransferBlock(brp_protocol protocol, unsigned Block);
/**
 * @anchor Mif_Halt
 * Switch card to halt state. The card has to be selected before it may be
 * switched to halt state.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Mif_Halt(brp_protocol protocol);
/**
 * @anchor Mif_AuthE2Extended
 * This command is identical to the [Mif.AuthE2](@ref Mif_AuthE2) command with the
 * exception that it supports stronger authentication methods (MIFARE and AES),
 * supported by MIFARE Pro cards.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AuthLevel Desired authentication level    * 0: AES SL1 authentication    * 1: AES SL2 authentication    * 2: AES SL3 authentication    * 3: MIFARE authentication
 * @param[in] KeyHasExtIdx Set this flag if extended crypto memory is used (using KeyExtIdx parameter).
 * @param[in] EV1Mode Switches to EV1 secure messaging. (Only supported by MFP EV1 cards)
 * @param[in] IsKeyB Key B is used when this flag is set, whereas Key A is used when this flag is cleared.
 * @param[in] Block Block/Key address of MIFARE Pro card.
 * @param[in] KeyIdx Crypto Memory Index (SAM or CryptoMemory) of MIFARE key    * SAM: 0-7F    * CrMem: 80-BF
 * @param[in] KeyExtIdx Crypto Memory Index (SAM or CryptoMemory) of authentication key    * SAM: SAM: Key version (0..0xFF)    * Crypto Memory: Page (0..15)
 * @param[in] DivData Key diversification according to NXP AN10922 will be done if diversification data bytes are specified.
 * @param[in] DivData_len 
 */
brp_errcode brp_Mif_AuthE2Extended(brp_protocol protocol, unsigned AuthLevel, bool KeyHasExtIdx, unsigned EV1Mode, bool IsKeyB, unsigned Block, unsigned KeyIdx, unsigned KeyExtIdx, brp_buf DivData, size_t DivData_len);
/**
 * @anchor Mif_AuthUserExtended
 * This command is identical to the [Mif.AuthUser](@ref Mif_AuthUser) command with
 * the exception that it supports stronger authentication methods (MIFARE and
 * AES), supported by MIFARE Pro cards.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AuthLevel Desired authentication level    * 0: AES SL1 authentication    * 1: AES SL2 authentication    * 2: AES SL3 authentication    * 3: MIFARE authentication
 * @param[in] EV1Mode Switches to EV1 secure messaging. (Only supported by MFP EV1 cards)
 * @param[in] KeyB Key B is used when this flag is set, whereas Key A is used when this flag is cleared.
 * @param[in] Block Block/Key address of MIFARE Pro card.
 * @param[in] Key Key to use for authentication.
 * @param[in] Key_len 
 */
brp_errcode brp_Mif_AuthUserExtended(brp_protocol protocol, unsigned AuthLevel, unsigned EV1Mode, unsigned KeyB, unsigned Block, brp_buf Key, size_t Key_len);
/**
 * @anchor Mif_ResetAuth
 * This command resets the reader's authentication state (used for MIFARE Pro
 * specific Read/Write counters.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Mif_ResetAuth(brp_protocol protocol);
/**
 * @anchor Mif_ReadSL3
 * This command reads blocks from an SL3-authenticated MIFARE Pro card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] NoMacOnCmd 
 * @param[in] PlainData 
 * @param[in] NoMacOnResp 
 * @param[in] Block Block number where reading starts.
 * @param[in] BlockNr Number of blocks to read.
 * @param[out] BlockData Read data blocks.
 * @param[out] BlockData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_ReadSL3(brp_protocol protocol, unsigned NoMacOnCmd, unsigned PlainData, unsigned NoMacOnResp, unsigned Block, unsigned BlockNr, brp_buf* BlockData, size_t* BlockData_len, brp_mempool *mempool);
/**
 * @anchor Mif_WriteSL3
 * This command writes blocks to an SL3-authenticated MIFARE Pro card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PlainData 
 * @param[in] NoMacOnResp 
 * @param[in] Block Block number where writing starts.
 * @param[in] BlockData Data blocks to write.
 * @param[in] BlockData_len 
 */
brp_errcode brp_Mif_WriteSL3(brp_protocol protocol, unsigned PlainData, unsigned NoMacOnResp, unsigned Block, brp_buf BlockData, size_t BlockData_len);
/**
 * @anchor Mif_ChangeAESKey
 * This command changes an AES key on a MIFARE Plus card.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyHasExtIdx Set this flag if extended crypto memory is used (using KeyExtIdx parameter).
 * @param[in] NoMacOnResp 
 * @param[in] Block Key block number.
 * @param[in] KeyIdx Crypto Memory Index of secure reader chip key    * SAM: 0-7F    * CrMem: 80-FC
 * @param[in] KeyExtIdx Crypto Memory Index (SAM or CryptoMemory) of authentication key    * SAM: SAM: Key version (0..0xFF)    * Crypto Memory: Page (0..15)
 * @param[in] DivData Key diversification according to NXP AN10922 will be done if diversification data bytes are specified.
 * @param[in] DivData_len 
 */
brp_errcode brp_Mif_ChangeAESKey(brp_protocol protocol, bool KeyHasExtIdx, unsigned NoMacOnResp, unsigned Block, unsigned KeyIdx, unsigned KeyExtIdx, brp_buf DivData, size_t DivData_len);
/**
 * @anchor Mif_ValueSL3
 * This command performs an operation on a value block.
 * 
 * It can be used for MIFARE Plus cards in security level 3.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] NoMacOnResp 
 * @param[in] Cmd Selects a value operation.  0 - Increment: Increments a value block by the given value and stores the result in the Transfer Buffer.  1 - Decrement: Decrements a value block by the given value and stores the result in the Transfer Buffer.  2 - Transfer: Transfers the content of the Transfer Buffer to the specified address. Can only be executed after an Increment, Decrement, IncrementTransfer, DecrementTransfer, or Restore command.  3 - IncrementTransfer: Combined Increment and Transfer.  4 - DecrementTransfer: Combined Decrement and Transfer.  5 - Restore: Copies the value block content to the TransferBuffer.
 * @param[in] Block Value block number.
 * @param[in] DestBlock Destination block number for combined IncrementTransfer or IncrementTransfer command.
 * @param[in] Value Value for Increment, Decrement, IncrementTransfer, IncrementTransfer.
 * @param[out] TMCounterTMValue Present if targeting a TMProtectedBlock which is configured to return TMC (4 bytes) and TMV (8 bytes)
 * @param[out] TMCounterTMValue_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_ValueSL3(brp_protocol protocol, unsigned NoMacOnResp, unsigned Cmd, unsigned Block, unsigned DestBlock, unsigned Value, brp_buf* TMCounterTMValue, size_t* TMCounterTMValue_len, brp_mempool *mempool);
/**
 * @anchor Mif_ProxCheck
 * This command performs a proximity check. The key-related parameters are only
 * used if no authentication has been performed before this command is called.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] M Number of random bytes which are sent within one proximity check round.
 * @param[in] DisableIsoWrapping 
 * @param[in] UseExtProxKey Use (external) Proximity key given as command parameter.  If the card is already authenticated (VC Selection or Card Authentication), do not activate this option.
 * @param[in] DiversifyProxKey Key diversification of the proximity key defined in Crypto Memory or SAM will be done according to NXP AN10922.
 * @param[in] UseProxKey Proximity key is defined in Crypto Memory or SAM.  If the card is already authenticated (Card Authentication), do not activate this option.
 * @param[in] ProxKeyIdx Crypto Memory Index (SAM or CryptoMemory) of Proximity Check Key    * SAM: MSByte: Key version / LSByte: KeyIdx    * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
 * @param[in] DivData Key diversification according to NXP AN10922.
 * @param[in] DivData_len 
 * @param[in] ProxKey Proximity Check Key
 * @param[in] ProxKey_len 
 */
brp_errcode brp_Mif_ProxCheck(brp_protocol protocol, unsigned M, unsigned DisableIsoWrapping, bool UseExtProxKey, bool DiversifyProxKey, bool UseProxKey, unsigned ProxKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf ProxKey, size_t ProxKey_len);
/**
 * @anchor Mif_GetCardVersion
 * This command returns HW- / SW- / Production-Information. (only MIFARE+ EV1 and
 * newer)
 * 
 * @param[in] protocol used to execute the command
 * @param[out] CardVersion Card version information -> HW- / SW- / Prod-Information
 * @param[out] CardVersion_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_GetCardVersion(brp_protocol protocol, brp_buf* CardVersion, size_t* CardVersion_len, brp_mempool *mempool);
/**
 * @anchor Mif_ReadSig
 * 
 * 
 * @param[in] protocol used to execute the command
 * @param[out] NxpSignature NXP Originality Signature
 * @param[out] NxpSignature_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_ReadSig(brp_protocol protocol, brp_buf* NxpSignature, size_t* NxpSignature_len, brp_mempool *mempool);
/**
 * @anchor Mif_VirtualCardSelect
 * Command is only supported by MIFARE Plus EV1 cards. Selected in ISO14443-3
 * mode the VCSupportLastISOL3 command is executed. Selected in ISO14443-4 mode
 * the IsoSelect command is executed If the card answers in the latter case with
 * a Payload (UID does not match or authentication with VCSelection is mandatory)
 * the reader executes an additional ISOExternalAuthentication command
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ForceVcsAuthentication Forces authentication to a virtual card. A card without encryption returns [Mif.VcsAndProxCheckError](@ref Mif_VcsAndProxCheckError)
 * @param[in] UseExtVcSelectKeys Authenticates to a virtual card. A MAC and an encryption key have to be specified. Use (external) Virtual Card keys given as command parameter.
 * @param[in] DiversifyMacKey Diversifies VC Mac key.  Remarks for use of divinput:  VC-UID is obtained by decryption of the card response. If VC-UID is concatenated with divinput the input wil be limited to 31 bytes.
 * @param[in] DiversifyEncKey Diversifies VC Encryption key
 * @param[in] UseVcSelectKeys Authenticates to a virtual card. A MAC and a encryption key has to be specified. Use keys stored in CryptoMemory or SAM.
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
brp_errcode brp_Mif_VirtualCardSelect(brp_protocol protocol, bool ForceVcsAuthentication, bool UseExtVcSelectKeys, unsigned DiversifyMacKey, bool DiversifyEncKey, bool UseVcSelectKeys, brp_buf IID, size_t IID_len, unsigned EncKeyIdx, unsigned MacKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf EncKey, size_t EncKey_len, brp_buf MacKey, size_t MacKey_len, unsigned* FciType, brp_buf* Fci, size_t* Fci_len, brp_mempool *mempool);
/**
 * @anchor Mif_SectorSwitch
 * This command performs a sector switch command (only for EV1 cards). Prior the
 * card has to be set in 14443-4 mode, all sectors are addressed with sector Key
 * B.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] L3SectorSwitch If _true_ , the target level of the sector switch is SL3, else SL1/SL3-Mixed.
 * @param[in] SectorSwitchKeyIdx Crypto Memory Index (SAM or CryptoMemory) of L1L3MixSectorSwitchKey or L3SectorSwitchKey    * SAM: MSByte: Key version / LSByte: KeyIdx    * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
 * @param[in] SectorSwitchKeyDivData If diversification data is specified, key diversification of the SectorSwitchKey will be done according to NXP AN10922.
 * @param[in] SectorSwitchKeyDivData_len 
 * @param[in] SectorSpec 
 * @param[in] SectorSpec_len 
 * @param[in] SectorKeysDivData If diversification data is specified, key diversification of the sector keys will be done according to NXP AN10922.
 * @param[in] SectorKeysDivData_len 
 */
brp_errcode brp_Mif_SectorSwitch(brp_protocol protocol, bool L3SectorSwitch, unsigned SectorSwitchKeyIdx, brp_buf SectorSwitchKeyDivData, size_t SectorSwitchKeyDivData_len, brp_Mif_SectorSwitch_SectorSpec_Entry* SectorSpec, size_t SectorSpec_len, brp_buf SectorKeysDivData, size_t SectorKeysDivData_len);
/**
 * @anchor Mif_CommitReaderID
 * This commands commits a reader ID from a card and returns the encrypted TMRI
 * to the host. Authentication must take place before using this command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Block Value block number.
 * @param[out] EncTRI Encrypted transaction reader ID
 * @param[out] EncTRI_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Mif_CommitReaderID(brp_protocol protocol, unsigned Block, brp_buf* EncTRI, size_t* EncTRI_len, brp_mempool *mempool);
/**
 * @anchor Mif_SetFraming
 * This command switches the communication protocol mode for MIFARE Plus EV1
 * cards.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CommMode Defines 14443-4 communication mode for MIFARE Plus EV1 cards.
 */
brp_errcode brp_Mif_SetFraming(brp_protocol protocol, brp_Mif_SetFraming_CommMode CommMode);
#endif
/**
 * @}
 */
