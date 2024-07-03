/**
 * @file
 * @anchor VHL
 * _VHL_ stands for _Very High Level_ card access. With this command group, you
 * can handle nearly all aspects of the card technology used in your project
 * while avoiding complex low-level command sequences.
 * 
 * **You cannot mix VHL and low-level commands.**
 * 
 * For more details on how to implement VHL, please see our [ VHL workflow
 * overview](https://docs.baltech.de/developers/map-vhl.html).
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_VHL_H__
#define __BRP_BALTECH_API_CMDS_VHL_H__
#include "../typedefs.h"
/**
 * @anchor VHL_ErrNoTag
 * This status code occurs in the following cases:
 * 
 *   * There's no card in the antenna field.
 *   * The card doesn't respond, i.e. it doesn't match the given VHL file.
 *   * You use an HID Prox/Indala/Keri card, but the reader doesn't have the [required Prox license](https://docs.baltech.de/project-setup/get-prox-license-for-hid-prox-indala-keri.html). 
 * 
 * This status code is the only one that requires a reselection of the card with
 * [VHL.Select](@ref VHL_Select).
 */
#define BRP_VHL_ErrNoTag BRP_ERR_STATUS(0x0100, 0x01)
/**
 * @anchor VHL_ErrCardNotSelected
 * The command can't be run because no card is selected.
 */
#define BRP_VHL_ErrCardNotSelected BRP_ERR_STATUS(0x0100, 0x02)
/**
 * @anchor VHL_ErrHf
 * Communication problems with the card occurred. Data may have been corrupted.
 */
#define BRP_VHL_ErrHf BRP_ERR_STATUS(0x0100, 0x03)
/**
 * @anchor VHL_ErrConfig
 * The VHL file structure in the reader configuration is invalid or the specified
 * VHL file isn't available.
 */
#define BRP_VHL_ErrConfig BRP_ERR_STATUS(0x0100, 0x04)
/**
 * @anchor VHL_ErrAuth
 * An authentication error occurred. Data may have been written partially. This
 * may occur if the specified VHL file uses invalid keys (MIFARE) or the
 * specified stamp is not in the reader's EEPROM (LEGIC).
 */
#define BRP_VHL_ErrAuth BRP_ERR_STATUS(0x0100, 0x05)
/**
 * @anchor VHL_ErrRead
 * The communication sequence was OK, but reading failed. The card remains
 * selected. This may occur if the specified VHL file is too long for the
 * physical card storage.
 */
#define BRP_VHL_ErrRead BRP_ERR_STATUS(0x0100, 0x06)
/**
 * @anchor VHL_ErrWrite
 * The communication sequence was OK, but writing failed. Data may have been
 * written partially. The card remains selected. This may occur if the specified
 * VHL file is too long for the physical card storage.
 */
#define BRP_VHL_ErrWrite BRP_ERR_STATUS(0x0100, 0x07)
/**
 * @anchor VHL_ConfcardRead
 * A BALTECH ConfigCard has been detected successfully and will be read after
 * this command.
 */
#define BRP_VHL_ConfcardRead BRP_ERR_STATUS(0x0100, 0x08)
/**
 * @anchor VHL_ErrInvalidCardType
 * The desired card type doesn't match the card family of the currently selected
 * card.
 */
#define BRP_VHL_ErrInvalidCardType BRP_ERR_STATUS(0x0100, 0x09)
/**
 * @anchor VHL_ErrNotSupported
 * The command is currently not supported. Future releases may support the
 * command.
 */
#define BRP_VHL_ErrNotSupported BRP_ERR_STATUS(0x0100, 0x0A)
/**
 * @anchor VHL_ErrFormat
 * The communication sequence was OK, but formatting failed. Data may have been
 * written partially. The card remains selected.
 */
#define BRP_VHL_ErrFormat BRP_ERR_STATUS(0x0100, 0x0B)
/**
 * @anchor VHL_ErrHw
 * An error occurred while communicating with the reader chip/SAM.
 */
#define BRP_VHL_ErrHw BRP_ERR_STATUS(0x0100, 0x0C)
/**
 * @anchor VHL_ErrApdu
 * Card communication error: The command has been aborted, or the response hasn't
 * been read completely.
 */
#define BRP_VHL_ErrApdu BRP_ERR_STATUS(0x0100, 0x0D)
/**
 * @anchor VHL_Select
 * This command selects a card or tag in the antenna field for further
 * operations. You need to run it successfully before you can use the following
 * VHL commands:
 * 
 *   * [VHL.GetSnr](@ref VHL_GetSnr)
 *   * [VHL.GetATR](@ref VHL_GetATR)
 *   * [VHL.Read](@ref VHL_Read)
 *   * [VHL.Write](@ref VHL_Write)
 *   * [VHL.ExchangeAPDU](@ref VHL_ExchangeAPDU)
 * 
 * ## Handling multiple cards in the antenna field
 * 
 * Using the _Reselect_ parameter, you can interact with a card that you've
 * already processed before (learn more in the _Parameters_ section below).
 * 
 * **Certain cards return[ random
 * IDs](https://docs.baltech.de/glossary.html#random-id) . If 2 or more cards
 * with random IDs _AND_ the same card family are present in the antenna field at
 * the same time,_VHL.Select_ detects these cards more than once.**
 * 
 * ## Potential error cases after selection
 * 
 * After running _VHL.Select_ successfully, the above commands will usually be
 * executed successfully, even if the card temporarily leaves the antenna field.
 * Communication parameters such as _bit rate_ and _frame size_ are automatically
 * chosen to optimize performance.
 * 
 * However, problems with certain cards (e.g. MIFARE proX/DESFire) may occur when
 * they're in the border area of the antenna field and brought in very slowly. In
 * these cases, _VHL.Select_ may be executed successful, but the subsequent
 * command may fail.
 * 
 * **In this case, make sure your application guarantees a suitable card
 * distance, either by user guidance or by repetition of the[
 * VHL.IsSelected](@ref VHL_IsSelected) command until its success. This is
 * especially important in conjunction with the[
 * VHL.ExchangeAPDU](@ref VHL_ExchangeAPDU) command since it doesn't perform retries
 * internally.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CardFamiliesFilter Selects the physical HF protocols that the reader will scan for cards. _VHLSelect_ scans for the specified card families in a round-robin algorithm, i.e. the more card families you specify, the more time is needed to run a complete scan loop.  **Not all card types support all VHL commands. For details, see our overview of[ supported commands](https://docs.baltech.de/developers/supported-card- types.html) .**
 * @param[in] Reselect If _false_ , the reader will deselect the current card and select the next one in the field. Cards you've already selected before will be ignored. Once you've run through all the cards in the field, you'll get a [VHL.ErrNoTag](@ref VHL_ErrNoTag) status code. Cards will be reselected again when they're removed from the antenna field and then enter it again.  If _true_ , the reader will "forget" which cards it has already selected since the last execution of _VHL.Select_ and will start all over with the first card. This means that the same card is reselected over and over again, while other cards in the field are ignored.  **To avoid this and start reselection only when all cards in the field have been selected once, set _Reselect_ to _false_ until you get a _VHL.ErrNoTag_ status. Then set _Reselect_ to _true_ .**
 * @param[in] AcceptConfCard If true, the reader will scan every detected card and check if it's a [ BALTECH ConfigCard](https://docs.baltech.de/installation/deploy-config-via- configcard.html) before returning from _VHL.Select_. Once the reader has found a ConfigCard, it will do the following:    * Return the error code [VHL.ConfcardRead](@ref VHL_ConfcardRead)   * Transfer the configuration stored on the ConfigCard to its own configuration   * Reboot to activate the new configuration  **Reading ConfigCards currently only works if[ legacy firmware support](https://docs.baltech.de/project-setup/fill-out-administrative- information.html#support-legacy-firmware-versions) is enabled for the configuration. ConfigCards without legacy firmware support can currently only be read via[ Autoread](autoread.xml) .**
 * @param[out] SelectedCardType The type of the selected card. Since there are no reliable identification standards amongst card manufacturers, we use a heuristic that examines the UID, its length, and other information as documented [here](https://docs.baltech.de/developers/supported-card-types.html).  **Due to the lack of standards, we cannot guarantee the card type is always identified correctly.**
 */
brp_errcode brp_VHL_Select(brp_protocol protocol, brp_CardFamilies CardFamiliesFilter, bool Reselect, bool AcceptConfCard, brp_CardType* SelectedCardType);
/**
 * @anchor VHL_GetSnr
 * This command returns the serial number (UID) of the currently selected card.
 * The UID is the number sent when the card is selected; this may also be a
 * random ID.
 * 
 * If [VHL.Select](@ref VHL_Select) hasn't been executed successfully before, the
 * reader will return [VHL.ErrCardNotSelected](@ref VHL_ErrCardNotSelected). If the
 * last selected card is no longer available in the antenna field, or a
 * read/write operation failed previous to this command, the returned serial
 * number is undefined.
 * 
 * **Don't make security-critical decisions by only examining the card's serial
 * number.**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Snr Serial number (UID) of the card. The length of this field depends on the selected card type.
 * @param[out] Snr_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_GetSnr(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool);
/**
 * @anchor VHL_Read
 * This command reads data from a card based on a VHL file. In this file, you
 * specify the card-specific memory structure. You can either [add the VHL file
 * to your reader configuration](https://docs.baltech.de/developers/configure-
 * rfid-interface.html#add-a-vhl-file) or create it dynamically using
 * [VHL.Setup](@ref VHL_Setup).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Id ID of VHL file (starting at 0)    * If you create the VHL file dynamically, use the ID _0xFF_.   * If you've added the VHL file to the reader configuration, please resolve the ID from the VHL file name using [VHL.ResolveFilename](@ref VHL_ResolveFilename).    **Don't hardcode the ID. Otherwise, your application won't work anymore if e.g. a project manager later merges VHL files into a different configuration using BALTECH ConfigEditor. This process may result in a new ID, but not in a new name.**
 * @param[in] Adr Address of the byte where you want to start reading
 * @param[in] Len Number of bytes to read
 * @param[out] Data Data read from the card
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_Read(brp_protocol protocol, unsigned Id, unsigned Adr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor VHL_Write
 * This command writes data to a card based on a VHL file. In this file, you
 * specify the card-specific memory structure. You can either [add the VHL file
 * to your reader configuration](https://docs.baltech.de/developers/configure-
 * rfid-interface.html#add-a-vhl-file) or create it dynamically using
 * [VHL.Setup](@ref VHL_Setup).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Id ID of VHL file (starting at 0)    * If you create the VHL file dynamically, use _0xFF_.   * If you've added the VHL file to the reader configuration, please resolve the ID from the filename using [VHL.ResolveFilename](@ref VHL_ResolveFilename).    **Don't hardcode the ID. Otherwise, your application won't work anymore if e.g. a project manager later merges VHL files into a different configuration using BALTECH ConfigEditor. This process may result in a new ID, but not in a new name.**
 * @param[in] Adr Address of the byte where you want to start writing
 * @param[in] Data Data to write
 * @param[in] Data_len 
 */
brp_errcode brp_VHL_Write(brp_protocol protocol, unsigned Id, unsigned Adr, brp_buf Data, size_t Data_len);
/**
 * @anchor VHL_IsSelected
 * This command checks if the card/label selected by the last execution of the
 * [VHL.Select](@ref VHL_Select) command is still in the HF field of the antenna. If
 * the card/label has been taken away from the reader and put back on it _after_
 * the last execution of [VHL.Select](@ref VHL_Select), or if
 * [VHL.Select](@ref VHL_Select) has not been called after a card has been put on
 * the reader, this command will return the
 * [VHL.ErrCardNotSelected](@ref VHL_ErrCardNotSelected) status code.
 * 
 * **For 125 kHz cards, a retry is automatically performed in case of a misread
 * to improve reliability. Please note that this may increase reaction time for
 * 125 kHz cards to a maximum of 100 ms.**
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_VHL_IsSelected(brp_protocol protocol);
/**
 * @anchor VHL_GetLegacyATR
 * This command is deprecated and should only be used for compatibility purposes
 * with older firmware version. It returns the Answer To Reset (ATR) of the
 * currently selected card in a legacy format, i.e. not conform with the [PC/SC
 * specification, version
 * 2](http://pcscworkgroup.com/Download/Specifications/pcsc3_v2.01.09.pdf). For
 * new projects it is recommended to use the [VHL.GetATR](@ref VHL_GetATR) command
 * instead.
 * 
 * If the [VHL.Select](@ref VHL_Select) command has not been successfully executed
 * before this command, the [VHL.ErrCardNotSelected](@ref VHL_ErrCardNotSelected)
 * status code will be returned. If the last selected card is no longer available
 * in the field of the antenna, or if a read/write operation failed before
 * executing this command, the returned ATR is undefined.
 * 
 * The returned _ATR_ variable always has the following format:
 * 
 *   * 0x3B 
 *   * Length of card UID (in bytes) 
 *   * Card UID
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ATR Answer To Reset value in legacy format.
 * @param[out] ATR_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_GetLegacyATR(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool);
/**
 * @anchor VHL_ExchangeAPDU
 * This command sends APDUs to the currently selected card. APDUs are the
 * communication units between a reader and an ISO 14443-4 card. They're defined
 * in the [ISO/IEC 7816-4
 * standard](http://www.iso.org/iso/catalogue_detail.htm?csnumber=54550).
 * _VHL.ExchangeAPDU_ transmits the actual APDU command via the _Cmd_ parameter
 * and returns the APDU response as _Resp_.
 * 
 * ## Keep an eye on the frame size
 * 
 * The combined size of transmitted and received APDU data (i.e. the combined
 * size of _Cmd_ and _Resp_) must not exceed the maximum frame size supported by
 * your reader's firmware version. To check the maximum frame size, run
 * [Sys.GetBufferSize](@ref Sys_GetBufferSize) and refer to the _TotalSize_
 * response value.
 * 
 * **For larger amount of data, please use[
 * VHL.ExchangeLongAPDU](@ref VHL_ExchangeLongAPDU) instead.**
 * 
 * ## No error correction or retry mechanisms
 * 
 * The reader firmware does _not_ perform any error handling operations with
 * ISO/IEC 7816-4 inter-industry commands. Errors will be directly reported as
 * part of the _Resp_ value without further action, so you have to take care of
 * error handling in your application.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AssumedCardType Forces the reader to assume a certain card type. By default (i.e. if _CardType_ is 0x00), the reader uses the card type detected by [VHL.Select](@ref VHL_Select).
 * @param[in] Cmd APDU command data
 * @param[in] Cmd_len 
 * @param[out] Resp APDU response data
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_ExchangeAPDU(brp_protocol protocol, brp_CardType AssumedCardType, brp_buf Cmd, size_t Cmd_len, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
/**
 * @anchor VHL_Setup
 * This command creates a VHL file dynamically and transfers it to the reader's
 * RAM. The VHL file specifies the card-specific memory structure required to
 * call [VHL.Read](@ref VHL_Read) or [VHL.Write](@ref VHL_Write). You need to run
 * _VHL.Setup_ if you don't want to configure the readers with a static VHL file
 * ( [ learn more](https://docs.baltech.de/developers/map-vhl-without-
 * config.html)).
 * 
 * **To run[ VHL.Format](@ref VHL_Format) , you cannot use a dynamic VHL file. In
 * this case, you have to follow the[ standard VHL
 * implementation](https://docs.baltech.de/developers/map-vhl.html) with a static
 * VHL file.**
 * 
 * ## What to specify
 * 
 * To describe the memory structure, provide a list of parameters depending on
 * the card type (see optional fields in the _Parameters_ table below). If you
 * omit a parameter, the reader will use the default value. To fill in the
 * parameter values, please refer to the card specification. For LEGIC or MIFARE
 * cards, you can also [analyze the card
 * structure](https://docs.baltech.de/project-setup/analyze-card-structure.html)
 * using BALTECH ID-engine Explorer.
 * 
 * ## Mixing dynamic and static VHL files
 * 
 * In principle, it is possible to mix dynamic VHL files and static VHL files (as
 * part of the reader configuration for the [ standard VHL
 * implementation](https://docs.baltech.de/developers/map-vhl.html)). However,
 * please note that the dynamic VHL file is lost as soon as you run
 * [VHL.Read](@ref VHL_Read) or [VHL.Write](@ref VHL_Write) with a static VHL file.
 * Thus, if you later want to run _VHL.Read_ or _VHL.Write_ with the dynamic VHL
 * file again, you first need to rerun _VHL.Setup_ to recreate the dynamic VHL
 * file.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ConsideredCardType Type of card to consider. The default value is 0x00, i.e. the reader will use the card type detected by [VHL.Select](@ref VHL_Select). To handle the card as a different type (e.g. handle a DESFire card as an inter-industry ISO 14443-4 card), set this value to the desired card type.  **Not all card types support all VHL commands. For details, see our overview of[ supported commands](https://docs.baltech.de/developers/supported-card- types.html)**
 * @param[in] MifareKey Encryption key to access the card.
 * @param[in] AsKeyA If _true_ , Key A is used to access the card.   If _false_ , Key B is used.
 * @param[in] MadId 2-byte application ID (AID) that identifies the sectors to access. If specified, only the payload of that application will be accessed. If not specified, the payload of all sectors will be accessed.  **All sector trailer blocks and block 0 will be omitted, i.e. the following block order is used: 1,2,4,5,6,8, etc. (0,3,7, etc. are omitted).**
 * @param[in] AppId Application ID, ranging from 0 to 0x00FFFFFF (big-endian)
 * @param[in] DesfireFileDesc 
 * @param[in] Key Key with preceding crypto byte. Please refer to __Device / CryptoKey SubKey__ for more details.
 * @param[in] Key_len 
 * @param[in] SegmentInfo Either segment number or stamp, as defined in the _EnStamp_ parameter. By default, the first segment will be accessed using its segment number.
 * @param[in] SegmentInfo_len 
 * @param[in] EnStamp If _true_ , _SegmentInfo_ contains a stamp, i.e. the identifier of the application.   If _false_ , it contains a segment number.  **This parameter will only be evaluated if _SegmentInfo_ has a length of 1. In this case, the reader can't distinguish between ID and stamp as a valid segment number always has length 1.**
 * @param[in] AdrMode Specifies the addressing mode. This parameter is only available on readers supporting LEGIC advant. LEGIC prime readers ignore it.  **To allow for backward compatibility with LEGIC prime readers, omitting this parameter will _not_ result in the default value, but in the following behavior: VHL address 0 is mapped to protocol header address _25_ , starting with the first data byte after the longest possible LEGIC prime stamp.**
 * @param[in] FirstBlock First block of the application data
 * @param[in] BlockCount Number of blocks occupied by the application data
 * @param[in] OptionFlag Option flag value for read/write operations
 * @param[in] BlockSize Block size in bytes
 * @param[in] FileLen File length
 * @param[in] SelectFileCmdList 
 * @param[in] SelectFileCmdList_len 
 */
brp_errcode brp_VHL_Setup(brp_protocol protocol, brp_CardType ConsideredCardType, brp_buf MifareKey, bool AsKeyA, unsigned MadId, unsigned AppId, brp_DesfireFileDescription DesfireFileDesc, brp_buf Key, size_t Key_len, brp_buf SegmentInfo, size_t SegmentInfo_len, bool EnStamp, brp_VHL_Setup_AdrMode AdrMode, unsigned FirstBlock, unsigned BlockCount, brp_VHL_Setup_OptionFlag OptionFlag, unsigned BlockSize, unsigned FileLen, brp_VHL_Setup_SelectFileCmdList_Entry* SelectFileCmdList, size_t SelectFileCmdList_len);
/**
 * @anchor VHL_SetupMifare
 * This commands prepares the reader to access Mifare cards with the given Mifare
 * key settings. It can be called before using [VHL.Read](@ref VHL_Read) and
 * [VHL.Write](@ref VHL_Write) with Mifare cards without configuring the reader with
 * a VHL-file, i.e. when the _ID_ parameter of [VHL.Read](@ref VHL_Read) or
 * [VHL.Write](@ref VHL_Write) is set to 0xFF.
 * 
 * All data blocks of the card starting from sector 1 will be included in the ad
 * hoc VHL-file. This only makes sense if all blocks can be accessed using the
 * same key. If this assumption is too simplistic for your application, please
 * use a normal VHL-file to set up the reader.
 * 
 * **After calling[ VHL.Select](@ref VHL_Select) ,[ VHL.Read](@ref VHL_Read) or[
 * VHL.Write](@ref VHL_Write) with an _ID_ parameter other than 0xFF, or after a
 * reboot, the settings made by this command are lost.**
 * 
 * **For new applications, the command[ VHL.Setup](@ref VHL_Setup) should be used
 * instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CustomKey If _true_ , use the key given in the _Key_ parameter. If _false_ , use 0xFF FF FF FF FF FF as key.
 * @param[in] KeyA If _true_ , use Key A, else use Key B. Please refer to the [Mifare standard specification](https://www.nxp.com/documents/data_sheet/MF1S70YYX_V1.pdf) for details about Key A and Key B.
 * @param[in] Key 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_VHL_SetupMifare(brp_protocol protocol, bool CustomKey, bool KeyA, brp_buf Key);
/**
 * @anchor VHL_SetupLegic
 * This commands prepares the reader to access LEGIC cards with the given
 * settings. It can be called before using [VHL.Read](@ref VHL_Read) and
 * [VHL.Write](@ref VHL_Write) with LEGIC cards without configuring the reader with
 * a VHL-file, i.e. when the _ID_ parameter of [VHL.Read](@ref VHL_Read) or
 * [VHL.Write](@ref VHL_Write) is set to 0xFF.
 * 
 * A distinct segment of the LEGIC card to access may be specified, either
 * according to its fixed segment ID (through the _SegmentID_ parameter) or
 * according to its stamp (through the _Stamp_ parameter).
 * 
 * This command works with a fixed address mapping for the application data: VHL
 * address 0 corresponds to Protocol Header address 25, the first data byte after
 * the longest possible LEGIC Prime stamp. If this assumption is too simplistic
 * for your application, please use [VHL.Setup](@ref VHL_Setup) or a normal VHL-file
 * to set up the reader.
 * 
 * **After calling[ VHL.Select](@ref VHL_Select) ,[ VHL.Read](@ref VHL_Read) or[
 * VHL.Write](@ref VHL_Write) with an _ID_ parameter other than 0xFF, or after a
 * reboot, the settings made by this command are lost.**
 * 
 * **For new applications, the command[ VHL.Setup](@ref VHL_Setup) should be used
 * instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StampLen Length of the _Stamp_ parameter used to access the card, varying from 1 to 7. If this parameter is set to 0, the card will be accessed according to a fixed segment ID specified in the _SegmentID_ parameter.
 * @param[in] SegmentID 
 * @param[in] Stamp 
 * @param[in] Stamp_len 
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_VHL_SetupLegic(brp_protocol protocol, unsigned StampLen, unsigned SegmentID, brp_buf Stamp, size_t Stamp_len);
/**
 * @anchor VHL_SetupISO15
 * This commands prepares the reader to access ISO15693 cards with the given
 * settings. It can be called before using [VHL.Read](@ref VHL_Read) and
 * [VHL.Write](@ref VHL_Write) with ISO15693 cards without configuring the reader
 * with a VHL-file, i.e. when the _ID_ parameter of [VHL.Read](@ref VHL_Read) or
 * [VHL.Write](@ref VHL_Write) is set to 0xFF.
 * 
 * **After calling[ VHL.Select](@ref VHL_Select) ,[ VHL.Read](@ref VHL_Read) or[
 * VHL.Write](@ref VHL_Write) with an _ID_ parameter other than 0xFF, or after a
 * reboot, the settings made by this command are lost.**
 * 
 * **For new applications, the command[ VHL.Setup](@ref VHL_Setup) should be used
 * instead.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FirstBlock First block in the data area to read/write.
 * @param[in] BlockCount Number of blocks in the data area to read/write.
 * @param[in] OptionFlag If _true_ , low level read/write commands will be executed with the option flag set. Please refer to the [ISO15693 standard specification](http://www.iso.org/iso/iso_catalogue/catalogue_tc/catalogue_detail.htm?csnumber=43467) for detailed information on this flag.
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_VHL_SetupISO15(brp_protocol protocol, unsigned FirstBlock, unsigned BlockCount, bool OptionFlag);
/**
 * @anchor VHL_CheckReconfigErr
 * This command will return _true_ if the last call of [VHL.Select](@ref VHL_Select)
 * was unsuccessful and returned the [VHL.ConfcardRead](@ref VHL_ConfcardRead)
 * status code.
 * 
 * **To clear the[ VHL.ConfcardRead](@ref VHL_ConfcardRead) status code, the reader
 * has to be reset.**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Failed _true_ if last reconfiguration via [VHL.Select](@ref VHL_Select) failed.
 */
brp_errcode brp_VHL_CheckReconfigErr(brp_protocol protocol, bool* Failed);
/**
 * @anchor VHL_ExchangeLongAPDU
 * This command sends basic Inter-Industry commands to the currently selected
 * card in accordance with the [ISO/IEC 7816-4
 * standard](http://www.iso.org/iso/catalogue_detail.htm?csnumber=54550). This
 * command has the same functionality as [VHL.ExchangeAPDU](@ref VHL_ExchangeAPDU),
 * but it allows the application to send commands and receive responses larger
 * than the reader's internal protocol buffers by splitting the command. See the
 * [Sys.GetBufferSize](@ref Sys_GetBufferSize) command documentation for
 * more details about the reader's internal buffers.
 * 
 * When splitting a command into multiple blocks, this command has to be repeated
 * to transfer the APDU as _Cmd_ parameter block by block. As long as the
 * _ContinueCmd_ parameter is set to _true_ , the reader will wait for further
 * output before transmitting the APDU. The last block of the APDU can be sent by
 * setting _ContinueCmd_ to _false_. The reader will only start transferring the
 * response once the last block of the APDU command has been sent. If the
 * response is bigger than one communication frame, it is split in the same
 * manner as the command with the _ContinueResp_ flag set to _true_ as long as
 * the response has not been completely received. The command is completely
 * exchanged when the _ContinueResp_ flag is set to _false_.
 * 
 * A command transfer can be broken if the reader returns an error status code or
 * by starting a new VHL.ExchangeLongAPDU sequence. When starting a new APDU the
 * _Reset_ parameter of the first VHL.ExchangeLongAPDU call always has to be set
 * to _true_ (it does not matter if the command breaks a preceding
 * VHL.ExchangeLongAPDU or not).
 * 
 * The splitting of a command into blocks is determined by the size of the
 * reader's sending and receiving buffers. The size of these buffers can be
 * obtained by the [Sys.GetBufferSize](@ref Sys_GetBufferSize) command. A
 * frame must not exceed _MaxSendSize_ \- 4 or _TotalSize_ \- 8.
 * 
 * **The sum of the amount of data transmitted and received through _Cmd_ and
 * _Resp_ has to be smaller than or equal to _TotalSize_ .**
 * 
 * The following example shows how a 1000 Byte APDU Command which returns a 500
 * Byte response is transferred to a reader having a buffer of 400 Bytes (i.e.
 * for which [Sys.GetBufferSize](@ref Sys_GetBufferSize) returns a 400 Byte
 * _MaxSendSize_ and a 400 Byte _TotalSize_ ):
 * 
 *   1. ExchangeLongAPDU(Reset=True, ContinueCmd=True, Cmd=bytes 0..391) >= ContinueResp=True, Resp=empty 
 *   2. ExchangeLongAPDU(Reset=False, ContinueCmd=True, Cmd=bytes 392..783) >= ContinueResp=True, Resp=empty 
 *   3. ExchangeLongAPDU(Reset=False, ContinueCmd=False, Cmd=bytes 784..999) >= ContinueResp=True, Resp=0..175 
 *   4. ExchangeLongAPDU(Reset=False, ContinueCmd=False, Cmd=empty) >= ContinueResp=False, Resp=176..499
 * 
 * @param[in] protocol used to execute the command
 * @param[in] AssumedCardType Forces the reader to assume a specified card type. By default (i.e. _CardType_ = 0x00), the reader uses the card type detected by the [VHL.Select](@ref VHL_Select) command.
 * @param[in] Reset If _true_ , restart a new APDU.
 * @param[in] ContinueCmd If _true_ , the content of _Cmd_ will be appended to the last command(s).
 * @param[in] Cmd APDU Command data.
 * @param[in] Cmd_len 
 * @param[out] ContinueResp If _true_ , the content of _Resp_ will be appended to the response of the last command(s)
 * @param[out] Resp APDU response data.
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_ExchangeLongAPDU(brp_protocol protocol, brp_CardType AssumedCardType, bool Reset, bool ContinueCmd, brp_buf Cmd, size_t Cmd_len, bool* ContinueResp, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
/**
 * @anchor VHL_GetFileInfo
 * This command returns the available size of the VHL-file whose ID is specified
 * by the _ID_ parameter. Two values are returned: the length of the VHL-file
 * (_Len_) and the size of a single block (_BlockSize_).
 * 
 * **The size of the returned value _Len_ indicates the maximum number of bytes
 * which can be read/written with the[ VHL.Read](@ref VHL_Read) or[
 * VHL.Write](@ref VHL_Write) commands. Attempting to read or write a larger amount
 * of Bytes with[ VHL.Read](@ref VHL_Read) or[ VHL.Write](@ref VHL_Write) will generate
 * an error status code ([ VHL.ErrRead](@ref VHL_ErrRead) or[
 * VHL.ErrWrite](@ref VHL_ErrWrite) ).**
 * 
 * If the card system organizes its memory in blocks, _BlockSize_ returns the
 * size of a single block. If the memory is not organized in blocks, 1 will be
 * returned. 0 will be returned if the block sizes are not unique (currently,
 * there is no such card system in existence).
 * 
 * **This command can only be executed if a card is selected, e.g. with a
 * previous call of[ VHL.Select](@ref VHL_Select) .**
 * 
 * **The returned VHL-file size corresponds to the reader's configuration values.
 * It does not necessarily guarantee that a file of the returned sized can be
 * read on the card. In some cases, the actual size of the card may be smaller
 * than the returned VHL-file size.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Id ID of VHL-file in configuration memory (starting at 0).  **To keep your application ConfigEditor compatible do not hardcode this ID in your application, but resolve it from a name via[ VHL.ResolveFilename](@ref VHL_ResolveFilename) .**
 * @param[out] Len Size of VHL-file in bytes.
 * @param[out] BlockSize Size of a single block.
 */
brp_errcode brp_VHL_GetFileInfo(brp_protocol protocol, unsigned Id, unsigned* Len, unsigned* BlockSize);
/**
 * @anchor VHL_GetATR
 * This command returns the Answer to Reset (ATR) of the currently selected card
 * as defined in the [PC/SC specification, version
 * 2](http://pcscworkgroup.com/Download/Specifications/pcsc3_v2.01.09.pdf). If
 * [VHL.Select](@ref VHL_Select) hasn't been executed successfully before, the
 * [VHL.ErrCardNotSelected](@ref VHL_ErrCardNotSelected) status code will be
 * returned. If the last selected card is no longer available in the antenna
 * field, or a read/write operation failed previous to this command, the returned
 * ATR is undefined.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ATR ATR value in standardized format
 * @param[out] ATR_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_VHL_GetATR(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool);
/**
 * @anchor VHL_Format
 * This command formats a blank card based on a VHL file. In this file, you
 * specify the card-specific memory structure.
 * 
 * **_VHL.Format_ only works with the[ standard VHL
 * implementation](https://docs.baltech.de/developers/map-vhl.html) using a
 * static VHL file. You cannot use a dynamic VHL file created with[
 * VHL.Setup](@ref VHL_Setup) .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Id ID of VHL file   Please resolve it from the filename using [VHL.ResolveFilename](@ref VHL_ResolveFilename).  **Don't hardcode the ID. Otherwise, your application won't work anymore if e.g. a project manager later merges VHL files into a different configuration using BALTECH ConfigEditor. This process may result in a new ID, but not in a new name.**
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_VHL_Format(brp_protocol protocol, unsigned Id);
/**
 * @anchor VHL_ResolveFilename
 * This command returns the ID of a VHL file based on its filename. To to do, the
 * command searches for a file whose configuration value
 * __VhlCfg.File.Filename__ matches the passed
 * _Filename_ exactly.
 * 
 * Use this ID to reference the VHL file in the following commands:
 * 
 *   * [VHL.Read](@ref VHL_Read)
 *   * [VHL.Write](@ref VHL_Write)
 *   * [VHL.Format](@ref VHL_Format)
 *   * [VHL.GetFileInfo](@ref VHL_GetFileInfo)
 * 
 * **We strongly recommend you don't hardcode file IDs, but always resolve them
 * via this command. Otherwise, your application won't work anymore if e.g. a
 * project manager later merges VHL files into a different configuration using
 * BALTECH ConfigEditor. This process may result in a new ID, but not in a new
 * name.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FileName Name of VHL file  **The filename is case sensitive. Exactly 1 file with the given name must exist. If there are several or no files with exactly this name,[ VHL.ErrConfig](@ref VHL_ErrConfig) is returned.**
 * @param[out] Id ID of VHL file
 */
brp_errcode brp_VHL_ResolveFilename(brp_protocol protocol, char* FileName, unsigned* Id);
#endif
/**
 * @}
 */
