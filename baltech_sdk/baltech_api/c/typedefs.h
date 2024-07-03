/**
 * @{
 */
#ifndef __BRP_BALTECH_API_TYPEDEFS_H__
#define __BRP_BALTECH_API_TYPEDEFS_H__

#include "brp_lib.h"

#include <limits.h>
#if UINT_MAX < 0xFFFFFFFF
#error "baltech_api requires unsigned with a size of >=32bits"
#endif

#define BRP_BALTECH_API_VERSION "3.18.00"
/**
 * @anchor AutoRunCommand_RunMode
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_AutoRunCommand_RunMode_Standard = 0,
	/**
	 * 
	 */
	brp_AutoRunCommand_RunMode_Continuous = 1,
	/**
	 * 
	 */
	brp_AutoRunCommand_RunMode_Repeat = 2,
	brp_AutoRunCommand_RunMode_undefined = -1
} brp_AutoRunCommand_RunMode;
/**
 * @anchor KeyAccessRights_KeySettings
 * Accessrights for Keys. By default all operations are allowed. But with this
 * bitmask this key can be locked for some operations.
 */
typedef struct {
	/**
	 * 
	 */
	bool IsVersion;
	/**
	 * 
	 */
	bool IsDivInfo;
	/**
	 * 
	 */
	bool DenyFormat;
	/**
	 * 
	 */
	bool DenyWrite;
	/**
	 * 
	 */
	bool DenyRead;
} brp_KeyAccessRights_KeySettings;
/**
 * @anchor KeyAccessRights_DiversificationMode
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_KeyAccessRights_DiversificationMode_NoDiversification = 0,
	/**
	 * Key diversification according to NXP AN10922.
	 */
	brp_KeyAccessRights_DiversificationMode_ModeAv2 = 2,
	brp_KeyAccessRights_DiversificationMode_undefined = -1
} brp_KeyAccessRights_DiversificationMode;
/**
 * @anchor RunSequenceCmd_CmdCode
 * 
 */
typedef enum {
	/**
	 * Enable the port ID stored in the Field _Param_.
	 */
	brp_RunSequenceCmd_CmdCode_EnablePort = 1,
	/**
	 * Disable the port ID of the Field _Param_.
	 */
	brp_RunSequenceCmd_CmdCode_DisablePort = 2,
	/**
	 * Jumps back to the corresponding _StartLoop_ a specified number of repetitions.
	 * The field _Param_ specifies the number of loops (0-255).
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop = 5,
	/**
	 * Wait exactly the amount of ms specified in the field _Param_ before going on.
	 */
	brp_RunSequenceCmd_CmdCode_WaitMs = 8,
	/**
	 * Wait exactly the amount of seconds specified in _Param_ before going on.
	 */
	brp_RunSequenceCmd_CmdCode_WaitSec = 9,
	/**
	 * End Of Script Marker.
	 * 
	 * **Has to be present at the end of every script.**
	 */
	brp_RunSequenceCmd_CmdCode_EndOfSequence = 241,
	/**
	 * Starts a loop. Has to be followed by _RepeatLoopX_ or _RepeatLoop_.
	 */
	brp_RunSequenceCmd_CmdCode_StartLoop = 242,
	/**
	 * If execution of the sequence was aborted, jump to this label and run the
	 * following commands until EndOfSequence to restore a default LED state. The
	 * following commands must not contain _WaitXXX_ commands as it has to finish
	 * immediately.
	 */
	brp_RunSequenceCmd_CmdCode_OnStop = 243,
	/**
	 * This is a ShortCut for _EnablePort GreenLed_ (requires only one byte intead of
	 * 2).
	 */
	brp_RunSequenceCmd_CmdCode_EnablePortGreenLed = 16,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_EnablePortRedLed = 17,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_EnablePortBeeper = 18,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_EnablePortRelay = 19,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_EnablePortBlue = 22,
	/**
	 * This is a Shortcut for _DisablePort GreenLed_ (requires only one byte intead
	 * of 2).
	 */
	brp_RunSequenceCmd_CmdCode_DisablePortGreenLed = 32,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_DisablePortRedLed = 33,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_DisablePortBeeper = 34,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_DisablePortRelay = 35,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_DisablePortBlue = 38,
	/**
	 * This is a ShortCut for _EnablePort GreenLed_ , if GreenLed is enabled
	 * otherwise DisablePort GreenLed.
	 */
	brp_RunSequenceCmd_CmdCode_InvertPortGreenLed = 48,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_InvertPortRedLed = 49,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_InvertPortBeeper = 50,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_InvertPortRelay = 51,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_InvertPortBlue = 54,
	/**
	 * This is a Shortcut for _RepeatLoop 1_ which is actually a dummy operation, as
	 * the repeat block is was already executed once.
	 */
	brp_RunSequenceCmd_CmdCode_Repeat1Times = 81,
	/**
	 * This is a ShortCut for _RepeatLoop 2_. It repeats all operations since
	 * corresponding StartLoop exactly once. Thus in summary they were run twice
	 * (once the first time and once by repeating them).
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop2Times = 82,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop3Times = 83,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop4Times = 84,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop5Times = 85,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop6Times = 86,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop7Times = 87,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop8Times = 88,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop9Times = 89,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop10Times = 90,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop11Times = 91,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop12Times = 92,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop13Times = 93,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop14Times = 94,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_RepeatLoop15Times = 95,
	/**
	 * This is a Shortcut for _WaitMs 100_. It waits 100 ms before going on with the
	 * next operation.
	 */
	brp_RunSequenceCmd_CmdCode_Wait100Ms = 129,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait200Ms = 130,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait300Ms = 131,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait400Ms = 132,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait500Ms = 133,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait600Ms = 134,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait700Ms = 135,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait800Ms = 136,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait900Ms = 137,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1000Ms = 138,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1100Ms = 139,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1200Ms = 140,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1300Ms = 141,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1400Ms = 142,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1500Ms = 143,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1600Ms = 144,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1700Ms = 145,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1800Ms = 146,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait1900Ms = 147,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2000Ms = 148,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2100Ms = 149,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2200Ms = 150,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2300Ms = 151,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2400Ms = 152,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2500Ms = 153,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2600Ms = 154,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2700Ms = 155,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2800Ms = 156,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait2900Ms = 157,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3000Ms = 158,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3100Ms = 159,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3200Ms = 160,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3300Ms = 161,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3400Ms = 162,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3500Ms = 163,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3600Ms = 164,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3700Ms = 165,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3800Ms = 166,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait3900Ms = 167,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4000Ms = 168,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4100Ms = 169,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4200Ms = 170,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4300Ms = 171,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4400Ms = 172,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4500Ms = 173,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4600Ms = 174,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4700Ms = 175,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4800Ms = 176,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait4900Ms = 177,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5000Ms = 178,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5100Ms = 179,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5200Ms = 180,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5300Ms = 181,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5400Ms = 182,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5500Ms = 183,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5600Ms = 184,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5700Ms = 185,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5800Ms = 186,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait5900Ms = 187,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait6000Ms = 188,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait6100Ms = 189,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait6200Ms = 190,
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode_Wait6300Ms = 191,
	brp_RunSequenceCmd_CmdCode_undefined = -1
} brp_RunSequenceCmd_CmdCode;
/**
 * @anchor DesfireFileDescription_FileCommunicationSecurity
 * Communication settings that define if data is to be MAC'ed or encrypted before
 * it's transmitted to the host system.
 */
typedef enum {
	/**
	 * 
	 */
	brp_DesfireFileDescription_FileCommunicationSecurity_Plain = 0,
	/**
	 * 
	 */
	brp_DesfireFileDescription_FileCommunicationSecurity_Mac = 1,
	/**
	 * 
	 */
	brp_DesfireFileDescription_FileCommunicationSecurity_Encrypted = 3,
	brp_DesfireFileDescription_FileCommunicationSecurity_undefined = -1
} brp_DesfireFileDescription_FileCommunicationSecurity;
/**
 * @anchor DesfireFileDescription_FileType
 * Type of file to read
 * 
 * **Only Standard and Backup files are supported. There's no support for Cyclic,
 * Record, or Value files.**
 */
typedef enum {
	/**
	 * 
	 */
	brp_DesfireFileDescription_FileType_Standard = 0,
	/**
	 * Commit will be performed automatically.
	 */
	brp_DesfireFileDescription_FileType_Backup = 1,
	/**
	 * Commit will be performed when writing to address 0xFFFF.
	 */
	brp_DesfireFileDescription_FileType_BackupManualCommit = 2,
	brp_DesfireFileDescription_FileType_undefined = -1
} brp_DesfireFileDescription_FileType;
/**
 * @anchor VirtualLedDefinition_Mode
 * This byte is required to enable additional fields for the characterization of
 * the desired LED behavior.
 */
typedef struct {
	/**
	 * If _true_ , this virtual LED definition contains an individual transition
	 * time, which is applied to this VLED only. If _false_ , the __default transition
	 * time__ will be applied.
	 */
	bool ContainsTransitionTime;
	/**
	 * If _true_ , this virtual LED definition describes a pulse signal that
	 * continuously fades between 2 RGB colors. It contains the second RGB color
	 * value in an additional field.
	 */
	bool IsPulse;
	/**
	 * If _true_ , this virtual LED definition contains the field
	 * _PhysicalLedSelection_.  
	 * If _false_ , the firmware uses the default value _All_.
	 */
	bool ContainsPhysicalLedSelection;
} brp_VirtualLedDefinition_Mode;
/**
 * @anchor VirtualLedDefinition_PhysicalLedSelection
 * This field defines which physical LEDs are to be activated when the
 * corresponding VLED port is enabled.
 */
typedef enum {
	/**
	 * Activates only the LEDs on the right side.
	 */
	brp_VirtualLedDefinition_PhysicalLedSelection_Right = 1,
	/**
	 * Activates only the LEDs on the left side.
	 */
	brp_VirtualLedDefinition_PhysicalLedSelection_Left = 2,
	/**
	 * Activates all LEDs.
	 */
	brp_VirtualLedDefinition_PhysicalLedSelection_All = 3,
	brp_VirtualLedDefinition_PhysicalLedSelection_undefined = -1
} brp_VirtualLedDefinition_PhysicalLedSelection;
/**
 * @anchor Bat_Run_SubCmds_Entry
 * 
 */
typedef struct {
	/**
	 * All condition bits in this bit mask have to be set to execute this command.
	 */
	unsigned ConditionBits;
	/**
	 * Device Code of BRP command.
	 */
	unsigned DevCode;
	/**
	 * Command Code of BRP command.
	 */
	unsigned CmdCode;
	/**
	 * Parameters.
	 */
	brp_buf Params;
	/**
	 * 
	 */
	size_t Params_len;
} brp_Bat_Run_SubCmds_Entry;
/**
 * @anchor Bat_Run_Rsps_Entry
 * 
 */
typedef struct {
	/**
	 * Status Code.
	 */
	unsigned Status;
	/**
	 * Response Data.
	 */
	brp_buf Resp;
	/**
	 * 
	 */
	size_t Resp_len;
} brp_Bat_Run_Rsps_Entry;
/**
 * @anchor BlePeriph_DefineService_Characteristics_Entry
 * 
 */
typedef struct {
	/**
	 * Specifies the UUID (16 ir 128 bits) of the BLE characteristic
	 */
	brp_buf CharacteristicUUID;
	/**
	 * 
	 */
	size_t CharacteristicUUID_len;
	/**
	 * Specifies the size of the characteristic in bytes. If _VariableSize_ is set,
	 * this is not the exact size, but the maximum size of the attribute.
	 * 
	 * **The maximum size of a characteristic is 512 bytes.**
	 */
	unsigned Size;
	/**
	 * 
	 */
	bool SupportsRead;
	/**
	 * 
	 */
	bool SupportsWrite;
	/**
	 * 
	 */
	bool SupportsNotify;
	/**
	 * 
	 */
	bool SupportsIndicate;
	/**
	 * 
	 */
	bool VariableSize;
} brp_BlePeriph_DefineService_Characteristics_Entry;
/**
 * @anchor BlePeriph_GetEvents_EventId
 * 
 */
typedef enum {
	/**
	 * A BLE Central has connected to the reader.
	 */
	brp_BlePeriph_GetEvents_EventId_Connect = 1,
	/**
	 * The currently connected Central has disconnected.
	 */
	brp_BlePeriph_GetEvents_EventId_Disconnect = 2,
	/**
	 * An characteristic was modified by the Central. _CharacteristicNdx_ identifies
	 * the modified characteristic.
	 */
	brp_BlePeriph_GetEvents_EventId_Write = 3,
	brp_BlePeriph_GetEvents_EventId_undefined = -1
} brp_BlePeriph_GetEvents_EventId;
/**
 * @anchor BlePeriph_GetEvents_Events_Entry
 * 
 */
typedef struct {
	/**
	 * 
	 */
	brp_BlePeriph_GetEvents_EventId EventId;
	/**
	 * The characteristic that was modifed by the BLE Central. The characteristic is
	 * identified by the index within the _Characteristics_ array passed to
	 * [BlePeriph.DefineService](@ref BlePeriph_DefineService). Only relevant if
	 * _EventId_ is _Write_.
	 */
	unsigned CharacteristicNdx;
} brp_BlePeriph_GetEvents_Events_Entry;
/**
 * @anchor Desfire_ExecCommand_CryptoMode
 * Type of encryption.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_ExecCommand_CryptoMode_Plain = 0,
	/**
	 * 
	 */
	brp_Desfire_ExecCommand_CryptoMode_MAC = 1,
	/**
	 * 
	 */
	brp_Desfire_ExecCommand_CryptoMode_Encrypted = 3,
	brp_Desfire_ExecCommand_CryptoMode_undefined = -1
} brp_Desfire_ExecCommand_CryptoMode;
/**
 * @anchor Desfire_Authenticate_SecureMessaging
 * Sets the secure messaging mode.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_Authenticate_SecureMessaging_Native = 1,
	/**
	 * 
	 */
	brp_Desfire_Authenticate_SecureMessaging_EV1 = 0,
	/**
	 * 
	 */
	brp_Desfire_Authenticate_SecureMessaging_EV2 = 2,
	brp_Desfire_Authenticate_SecureMessaging_undefined = -1
} brp_Desfire_Authenticate_SecureMessaging;
/**
 * @anchor Desfire_Authenticate_KeyDivMode
 * Specifies diversification algorithm.
 */
typedef enum {
	/**
	 * No diversification.
	 */
	brp_Desfire_Authenticate_KeyDivMode_NoDiv = 0,
	/**
	 * SAM AV1 mode (3DES: 1 encryption round).
	 */
	brp_Desfire_Authenticate_KeyDivMode_SamAV1OneRound = 1,
	/**
	 * SAM AV1 compatible mode (AES, 3K3DES, 3DES: 2 encryption rounds).
	 */
	brp_Desfire_Authenticate_KeyDivMode_SamAV1TwoRounds = 2,
	/**
	 * SAM AV2 mode (AES according NXP: AN 10922).
	 */
	brp_Desfire_Authenticate_KeyDivMode_SamAV2 = 3,
	brp_Desfire_Authenticate_KeyDivMode_undefined = -1
} brp_Desfire_Authenticate_KeyDivMode;
/**
 * @anchor Desfire_AuthExtKey_SecureMessaging
 * Sets the secure messaging mode.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_SecureMessaging_Native = 1,
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_SecureMessaging_EV1 = 0,
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_SecureMessaging_EV2 = 2,
	brp_Desfire_AuthExtKey_SecureMessaging_undefined = -1
} brp_Desfire_AuthExtKey_SecureMessaging;
/**
 * @anchor Desfire_AuthExtKey_CryptoMode
 * Sets the encryption algorithm.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_CryptoMode_DES = 1,
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_CryptoMode_TripleDES = 2,
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_CryptoMode_ThreeKeyTripleDES = 3,
	/**
	 * 
	 */
	brp_Desfire_AuthExtKey_CryptoMode_AES = 4,
	brp_Desfire_AuthExtKey_CryptoMode_undefined = -1
} brp_Desfire_AuthExtKey_CryptoMode;
/**
 * @anchor Desfire_ReadData_Mode
 * Communication settings linked to the file.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_ReadData_Mode_Plain = 0,
	/**
	 * 
	 */
	brp_Desfire_ReadData_Mode_MAC = 1,
	/**
	 * 
	 */
	brp_Desfire_ReadData_Mode_Encrypted = 3,
	brp_Desfire_ReadData_Mode_undefined = -1
} brp_Desfire_ReadData_Mode;
/**
 * @anchor Desfire_WriteData_Mode
 * Communication settings linked to the file.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_WriteData_Mode_Plain = 0,
	/**
	 * 
	 */
	brp_Desfire_WriteData_Mode_MAC = 1,
	/**
	 * 
	 */
	brp_Desfire_WriteData_Mode_Encrypted = 3,
	brp_Desfire_WriteData_Mode_undefined = -1
} brp_Desfire_WriteData_Mode;
/**
 * @anchor Desfire_ChangeExtKey_MasterKeyType
 * These bits must only be set if the card's Master Key is changed. They specify
 * the type of the new card's Master Key.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Desfire_ChangeExtKey_MasterKeyType_DESorTripleDES = 0,
	/**
	 * 
	 */
	brp_Desfire_ChangeExtKey_MasterKeyType_ThreeKeyTripleDES = 1,
	/**
	 * 
	 */
	brp_Desfire_ChangeExtKey_MasterKeyType_AES = 2,
	brp_Desfire_ChangeExtKey_MasterKeyType_undefined = -1
} brp_Desfire_ChangeExtKey_MasterKeyType;
/**
 * @anchor Desfire_ChangeKey_NewKeyDivMode
 * Specifies diversification algorithm.
 */
typedef enum {
	/**
	 * SAM AV1 mode for all key types / one encryption round for DES keys.
	 */
	brp_Desfire_ChangeKey_NewKeyDivMode_SamAv1OneRound = 0,
	/**
	 * SAM AV1 mode only for DES keys - two encryption rounds.
	 */
	brp_Desfire_ChangeKey_NewKeyDivMode_SamAv1TwoRounds = 1,
	/**
	 * SAM AV2 mode.
	 */
	brp_Desfire_ChangeKey_NewKeyDivMode_SamAv2 = 2,
	brp_Desfire_ChangeKey_NewKeyDivMode_undefined = -1
} brp_Desfire_ChangeKey_NewKeyDivMode;
/**
 * @anchor Desfire_ChangeKey_CurKeyDivMode
 * Specifies diversification algorithm.
 */
typedef enum {
	/**
	 * SAM AV1 mode for all key types / one encryption round for DES keys.
	 */
	brp_Desfire_ChangeKey_CurKeyDivMode_SamAv1OneRound = 0,
	/**
	 * SAM AV1 mode only for DES keys - two encryption rounds).
	 */
	brp_Desfire_ChangeKey_CurKeyDivMode_SamAv1TwoRounds = 1,
	/**
	 * SAM AV2 mode.
	 */
	brp_Desfire_ChangeKey_CurKeyDivMode_SamAv2 = 2,
	brp_Desfire_ChangeKey_CurKeyDivMode_undefined = -1
} brp_Desfire_ChangeKey_CurKeyDivMode;
/**
 * @anchor Desfire_SetFraming_CommMode
 * Defines 14443-4 communication mode to DESFire card.
 */
typedef enum {
	/**
	 * DESFire native mode (default communication mode).
	 */
	brp_Desfire_SetFraming_CommMode_DESFireNative = 1,
	/**
	 * ISO 7816 compatible framing.
	 */
	brp_Desfire_SetFraming_CommMode_ISO7816Compatible = 2,
	brp_Desfire_SetFraming_CommMode_undefined = -1
} brp_Desfire_SetFraming_CommMode;
/**
 * @anchor Desfire_GetDfNames_AppNr_Entry
 * 
 */
typedef struct {
	/**
	 * Application ID - range from 0x00000000 to 0x00FFFFFF.
	 */
	unsigned AppId;
	/**
	 * ISO file ID
	 */
	unsigned IsoFileId;
	/**
	 * ISO DF filename (optional, 0..16 bytes)
	 */
	brp_buf IsoDfName;
	/**
	 * 
	 */
	size_t IsoDfName_len;
} brp_Desfire_GetDfNames_AppNr_Entry;
/**
 * @anchor EM_DecodeCfg_RxMod
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_EM_DecodeCfg_RxMod_Unknown = 0,
	/**
	 * 
	 */
	brp_EM_DecodeCfg_RxMod_Manchester = 16,
	/**
	 * 
	 */
	brp_EM_DecodeCfg_RxMod_Biphase = 32,
	/**
	 * 
	 */
	brp_EM_DecodeCfg_RxMod_NRZ = 48,
	brp_EM_DecodeCfg_RxMod_undefined = -1
} brp_EM_DecodeCfg_RxMod;
/**
 * @anchor Eth_GetTcpConnectionStatus_Status
 * BRP over TCP connection status.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Eth_GetTcpConnectionStatus_Status_NotConnected = 0,
	/**
	 * 
	 */
	brp_Eth_GetTcpConnectionStatus_Status_ConnectionTrialRunning = 1,
	/**
	 * 
	 */
	brp_Eth_GetTcpConnectionStatus_Status_Connected = 2,
	brp_Eth_GetTcpConnectionStatus_Status_undefined = -1
} brp_Eth_GetTcpConnectionStatus_Status;
/**
 * @anchor Eth_OpenTcpConnection_ConnectionReason
 * Connection reason bit mask that is sent to the host as soon as a connection is
 * established.
 */
typedef enum {
	/**
	 * This is the first connection after powerup.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_Powerup = 1,
	/**
	 * There has been a Link Change event.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_LinkChange = 2,
	/**
	 * The current PKI session is timing/has timed out. Restart PKI authentication.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_SessionkeyTimeout = 4,
	/**
	 * Autoread has detected a new card. The card number can be retrieved with
	 * AR.GetMessage.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_Message = 8,
	/**
	 * This is a UDP introspection induced connection trial. Open a PKI session,
	 * configure the device with the connection parameters of the host and restart
	 * the device afterwards.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_UdpIntrospection = 16,
	/**
	 * There has been a software reset.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_Reset = 32,
	/**
	 * There have been one or more connection trial failures before.
	 */
	brp_Eth_OpenTcpConnection_ConnectionReason_FailedConnectionTrials = 32768,
	brp_Eth_OpenTcpConnection_ConnectionReason_undefined = -1
} brp_Eth_OpenTcpConnection_ConnectionReason;
/**
 * @anchor Felica_GenericCmd_FastBaud
 * Baudrate PCD-PICC.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Felica_GenericCmd_FastBaud_Kbps212 = 0,
	/**
	 * 
	 */
	brp_Felica_GenericCmd_FastBaud_Kbps424 = 1,
	brp_Felica_GenericCmd_FastBaud_undefined = -1
} brp_Felica_GenericCmd_FastBaud;
/**
 * @anchor Felica_Request_FastBaud
 * Baudrate PCD-PICC.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Felica_Request_FastBaud_Kbps212 = 0,
	/**
	 * 
	 */
	brp_Felica_Request_FastBaud_Kbps424 = 1,
	brp_Felica_Request_FastBaud_undefined = -1
} brp_Felica_Request_FastBaud;
/**
 * @anchor Felica_Request_Labels_Entry
 * 
 */
typedef struct {
	/**
	 * ID of label. Random if first 2 bytes [01 FE] else unique.
	 */
	brp_buf NFCID;
	/**
	 * 
	 */
	size_t NFCID_len;
} brp_Felica_Request_Labels_Entry;
/**
 * @anchor FlashFS_ReadRecords_RecordList_Entry
 * 
 */
typedef struct {
	/**
	 * Record content. The size of the record equals the return value of
	 * [FlashFS.GetRecordSize](@ref FlashFS_GetRecordSize).
	 */
	brp_buf Record;
	/**
	 * 
	 */
	size_t Record_len;
} brp_FlashFS_ReadRecords_RecordList_Entry;
/**
 * @anchor FlashFS_WriteRecords_RecordList_Entry
 * 
 */
typedef struct {
	/**
	 * Record content. The size of the record must equal the return value of
	 * [FlashFS.GetRecordSize](@ref FlashFS_GetRecordSize)!
	 */
	brp_buf Record;
	/**
	 * 
	 */
	size_t Record_len;
} brp_FlashFS_WriteRecords_RecordList_Entry;
/**
 * @anchor Hitag_Request_TagType
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_Hitag_Request_TagType_HitagS = 0,
	/**
	 * 
	 */
	brp_Hitag_Request_TagType_Hitag1 = 1,
	/**
	 * 
	 */
	brp_Hitag_Request_TagType_Hitag2Manchester = 2,
	/**
	 * 
	 */
	brp_Hitag_Request_TagType_Hitag2Biphase = 3,
	brp_Hitag_Request_TagType_undefined = -1
} brp_Hitag_Request_TagType;
/**
 * @anchor Hitag_Request_Mode
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_Hitag_Request_Mode_StdHtg12S = 0,
	/**
	 * 
	 */
	brp_Hitag_Request_Mode_AdvHtg1S = 1,
	/**
	 * 
	 */
	brp_Hitag_Request_Mode_FAdvHS = 2,
	brp_Hitag_Request_Mode_undefined = -1
} brp_Hitag_Request_Mode;
/**
 * @anchor Hitag_Select_SelMode
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_Hitag_Select_SelMode_Select = 0,
	/**
	 * 
	 */
	brp_Hitag_Select_SelMode_Quiet = 1,
	/**
	 * 
	 */
	brp_Hitag_Select_SelMode_AuthPwd = 2,
	/**
	 * 
	 */
	brp_Hitag_Select_SelMode_H2AuthOnlyPwd = 3,
	brp_Hitag_Select_SelMode_undefined = -1
} brp_Hitag_Select_SelMode;
/**
 * @anchor Iso14a_RequestLegacy_UIDSize
 * Length of "Unique IDentifier" (UID). The UID may be either a fixed number or a
 * number generated randomly by the PICC (and therefore not unique!).
 */
typedef enum {
	/**
	 * UID length of 4 Bytes.
	 */
	brp_Iso14a_RequestLegacy_UIDSize_SingleSize = 0,
	/**
	 * UID length of 7 Bytes.
	 */
	brp_Iso14a_RequestLegacy_UIDSize_DoubleSize = 1,
	/**
	 * UID length of 10 Bytes.
	 */
	brp_Iso14a_RequestLegacy_UIDSize_TripleSize = 2,
	brp_Iso14a_RequestLegacy_UIDSize_undefined = -1
} brp_Iso14a_RequestLegacy_UIDSize;
/**
 * @anchor Iso14a_RequestATS_FSDI
 * _Frame Size proximity coupling Device Integer_ (FSDI) value. This value is
 * mapped to the Frame Size proximity coupling Device (FSD) value, which
 * indicates the maximum frame size accepted by the PCD.
 * 
 * **The current Baltech reader supports FSD of at least up to 64 bytes
 * (FSDI=0x05). It is not recommended to use a smaller FSDI. Future versions of
 * the Baltech reader might support higher FSDI values.**
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes16 = 0,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes24 = 1,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes32 = 2,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes40 = 3,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes48 = 4,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes64 = 5,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes96 = 6,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes128 = 7,
	/**
	 * 
	 */
	brp_Iso14a_RequestATS_FSDI_Bytes256 = 8,
	brp_Iso14a_RequestATS_FSDI_undefined = -1
} brp_Iso14a_RequestATS_FSDI;
/**
 * @anchor Iso14b_Request_TimeSlots
 * Number of time slots which should be used for requesting PICCs. The more PICCs
 * are expected, the higher this value should be. In one time slot, at most one
 * PICC may answer.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Request_TimeSlots_TimeSlots1 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Request_TimeSlots_TimeSlots2 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Request_TimeSlots_TimeSlots4 = 2,
	/**
	 * 
	 */
	brp_Iso14b_Request_TimeSlots_TimeSlots8 = 3,
	/**
	 * 
	 */
	brp_Iso14b_Request_TimeSlots_TimeSlots16 = 4,
	brp_Iso14b_Request_TimeSlots_undefined = -1
} brp_Iso14b_Request_TimeSlots;
/**
 * @anchor Iso14b_Request_FSCI
 * _Frame Size proximity Card Integer_ (FSCI). This value is mapped to the Frame
 * Size proximity Card (FSC) value, which indicates the maximum frame size
 * accepted by the PICC. The possible FSC values (mapped to the FSCI index) are
 * listed below.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes16 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes24 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes32 = 2,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes40 = 3,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes48 = 4,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes64 = 5,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes96 = 6,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes128 = 7,
	/**
	 * 
	 */
	brp_Iso14b_Request_FSCI_Bytes256 = 8,
	brp_Iso14b_Request_FSCI_undefined = -1
} brp_Iso14b_Request_FSCI;
/**
 * @anchor Iso14b_Request_ProtType
 * Protocol type.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Request_ProtType_NoISO14443L4Support = 0,
	/**
	 * 
	 */
	brp_Iso14b_Request_ProtType_ISO14443L4Support = 1,
	brp_Iso14b_Request_ProtType_undefined = -1
} brp_Iso14b_Request_ProtType;
/**
 * @anchor Iso14b_Request_FWI
 * _Frame Waiting time Integer_ (FWI). This value is necessary for calculation of
 * the _Frame Waiting Time_ (FWT) value, representing the maximum time needed by
 * the PICC between receiving a frame and sending the corresponding answer. FWT
 * is calculated by:
 * 
 * FWT = (256 * 16 / 13,56 MHz) * 2 ^ FWI
 * 
 * The FWT values given here (mapped to the FWI index) are approximate.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us302 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us604 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us1208 = 2,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us2416 = 3,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us4832 = 4,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Us9664 = 5,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms19 = 6,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms39 = 7,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms77 = 8,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms155 = 9,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms309 = 10,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms618 = 11,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms1237 = 12,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms2474 = 13,
	/**
	 * 
	 */
	brp_Iso14b_Request_FWI_Ms4948 = 14,
	brp_Iso14b_Request_FWI_undefined = -1
} brp_Iso14b_Request_FWI;
/**
 * @anchor Iso14b_Request_ValueList_Entry
 * 
 */
typedef struct {
	/**
	 * _Pseudo-Unique PICC Identifier_ (PUPI). With this identifier, each PICC can be
	 * distinguished from all others in the HF antenna field.
	 */
	brp_buf PUPI;
	/**
	 * _Application data field_. Contains information about the applications
	 * available on this PICC.
	 * 
	 * According to the _ADC_ value of the _ProtInfo_ bit mask, either a proprietary
	 * coding or CRC_B compression coding is used.
	 */
	brp_buf AppData;
	/**
	 * If this flag is set, data must be sent and received at equal bit rates.
	 */
	unsigned Synced;
	/**
	 * When this flag is set, the PICC can send data with a bit rate of up to 848
	 * kbit/s.
	 */
	unsigned Send848;
	/**
	 * When this flag is set, the PICC can send data with a bit rate of up to 424
	 * kbit/s.
	 */
	unsigned Send424;
	/**
	 * When this flag is set, the PICC can send data with a bit rate of up to 212
	 * kbit/s.
	 */
	unsigned Send212;
	/**
	 * When this flag is set, the PICC can receive data with a bit rate of up to 848
	 * kbit/s.
	 */
	unsigned Recv848;
	/**
	 * When this flag is set, the PICC can receive data with a bit rate of up to 424
	 * kbit/s.
	 */
	unsigned Recv424;
	/**
	 * When this flag is set, the PICC can receive data with a bit rate of up to 212
	 * kbit/s.
	 */
	unsigned Recv212;
	/**
	 * _Frame Size proximity Card Integer_ (FSCI). This value is mapped to the Frame
	 * Size proximity Card (FSC) value, which indicates the maximum frame size
	 * accepted by the PICC. The possible FSC values (mapped to the FSCI index) are
	 * listed below.
	 */
	brp_Iso14b_Request_FSCI FSCI;
	/**
	 * Protocol type.
	 */
	brp_Iso14b_Request_ProtType ProtType;
	/**
	 * _Frame Waiting time Integer_ (FWI). This value is necessary for calculation of
	 * the _Frame Waiting Time_ (FWT) value, representing the maximum time needed by
	 * the PICC between receiving a frame and sending the corresponding answer. FWT
	 * is calculated by:
	 * 
	 * FWT = (256 * 16 / 13,56 MHz) * 2 ^ FWI
	 * 
	 * The FWT values given here (mapped to the FWI index) are approximate.
	 */
	brp_Iso14b_Request_FWI FWI;
	/**
	 * Application Data Coding supported by the PICC. Possible values are:
	 * 
	 *   * 0x00: Application Data is coded using a proprietary mechanism 
	 *   * 0x01: Application Data is coded using CRC_B
	 */
	unsigned ADC;
	/**
	 * If this flag is set, the PPIC supports CID.
	 */
	unsigned CID;
	/**
	 * If this flag is set, the PPIC supports NAD.
	 */
	unsigned NAD;
} brp_Iso14b_Request_ValueList_Entry;
/**
 * @anchor Iso14b_Attrib_TR0
 * PICC's minimum delay before responding after the end of a command sent by PCD.
 * The values introduced in this parameter need to be divided by the ISO 14443
 * subcarrier frequency (abbreviated as _fs_).
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR0_Numerator64 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR0_Numerator48 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR0_Numerator16 = 2,
	brp_Iso14b_Attrib_TR0_undefined = -1
} brp_Iso14b_Attrib_TR0;
/**
 * @anchor Iso14b_Attrib_TR1
 * Minimum delay between subcarrier modulation start and beginning of data
 * transmission. The values introduced in this parameter need to be divided by
 * the ISO 14443 subcarrier frequency (abbreviated as _fs_).
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR1_Numerator80 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR1_Numerator64 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_TR1_Numerator16 = 2,
	brp_Iso14b_Attrib_TR1_undefined = -1
} brp_Iso14b_Attrib_TR1;
/**
 * @anchor Iso14b_Attrib_EOF_
 * _End Of Frame_ (EOF) flag for sending data to reader.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Attrib_EOF__EOFrequired = 0,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_EOF__EOFoptional = 1,
	brp_Iso14b_Attrib_EOF__undefined = -1
} brp_Iso14b_Attrib_EOF_;
/**
 * @anchor Iso14b_Attrib_SOF
 * _Start Of Frame_ (SOF) flag for sending data to reader.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Attrib_SOF_SOFrequired = 0,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_SOF_SOFoptional = 1,
	brp_Iso14b_Attrib_SOF_undefined = -1
} brp_Iso14b_Attrib_SOF;
/**
 * @anchor Iso14b_Attrib_FSDI
 * _Frame Size proximity coupling Device Integer_ (FSDI) value. This value is
 * mapped to the Frame Size proximity coupling Device (FSD) value, which
 * indicates the maximum frame size accepted by the PCD.
 * 
 * **The current Baltech reader supports FSD of at least up to 64 bytes
 * (FSDI=0x05). It is not recommended to use a smaller FSDI. Future versions of
 * the Baltech reader might support higher FSDI values.**
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes16 = 0,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes24 = 1,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes32 = 2,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes40 = 3,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes48 = 4,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes64 = 5,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes96 = 6,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes128 = 7,
	/**
	 * 
	 */
	brp_Iso14b_Attrib_FSDI_Bytes256 = 8,
	brp_Iso14b_Attrib_FSDI_undefined = -1
} brp_Iso14b_Attrib_FSDI;
/**
 * @anchor Iso14b_SetTransparentSettings_Tags_Entry
 * 
 */
typedef struct {
	/**
	 * ID of tag to set.
	 */
	unsigned ID;
	/**
	 * Value of tag to set.
	 */
	unsigned Value;
} brp_Iso14b_SetTransparentSettings_Tags_Entry;
/**
 * @anchor Iso14b_GetTransparentSettings_Tags_Entry
 * 
 */
typedef struct {
	/**
	 * ID of tag to set
	 */
	unsigned ID;
	/**
	 * Value of tag to set
	 */
	unsigned Value;
} brp_Iso14b_GetTransparentSettings_Tags_Entry;
/**
 * @anchor Iso14L4_SetupAPDU_FSCI
 * _Frame Size proximity Card Integer_ (FSCI). This value is mapped to the Frame
 * Size proximity Card (FSC) value, which indicates the maximum frame size
 * accepted by the PICC. The possible FSC values (mapped to the FSCI index) are
 * listed below.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes16 = 0,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes24 = 1,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes32 = 2,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes40 = 3,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes48 = 4,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes64 = 5,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes96 = 6,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes128 = 7,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FSCI_Bytes256 = 8,
	brp_Iso14L4_SetupAPDU_FSCI_undefined = -1
} brp_Iso14L4_SetupAPDU_FSCI;
/**
 * @anchor Iso14L4_SetupAPDU_FWI
 * _Frame Waiting time Integer_ (FWI). This value is necessary for calculation of
 * the _Frame Waiting Time_ (FWT) value, representing the maximum time needed by
 * the PICC between receiving a frame and sending the corresponding answer. FWT
 * is calculated by:
 * 
 * FWT = (256 * 16 / 13.56 MHz) * 2 ^ FWI
 * 
 * The FWT values given here (mapped to the FWI index) are approximate.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us302 = 0,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us604 = 1,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us1208 = 2,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us2416 = 3,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us4832 = 4,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Us9664 = 5,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms19 = 6,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms39 = 7,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms77 = 8,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms155 = 9,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms309 = 10,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms618 = 11,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms1237 = 12,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms2474 = 13,
	/**
	 * 
	 */
	brp_Iso14L4_SetupAPDU_FWI_Ms4948 = 14,
	brp_Iso14L4_SetupAPDU_FWI_undefined = -1
} brp_Iso14L4_SetupAPDU_FWI;
/**
 * @anchor Iso15_GetUIDList_Labels_Entry
 * 
 */
typedef struct {
	/**
	 * Unique ID of label.
	 */
	brp_buf UID;
	/**
	 * DSFID of label, only available, if DSFID bit in _Mode_ has been set.
	 */
	unsigned DSFID;
} brp_Iso15_GetUIDList_Labels_Entry;
/**
 * @anchor Iso15_ReadBlock_Data_Entry
 * 
 */
typedef struct {
	/**
	 * **Length is greater than 0! It was set to zero to provide length information**
	 * 
	 * Contains the actual data read from the block.
	 */
	brp_buf BlockData;
	/**
	 * Security status byte of the block.
	 */
	unsigned BlockSecData;
} brp_Iso15_ReadBlock_Data_Entry;
/**
 * @anchor Iso15_WriteMultipleBlocks_WriteBlocks_Entry
 * 
 */
typedef struct {
	/**
	 * Content that shall be written to blocks starting at _BlockId_
	 */
	brp_buf WriteBlock;
	/**
	 * 
	 */
	size_t WriteBlock_len;
} brp_Iso15_WriteMultipleBlocks_WriteBlocks_Entry;
/**
 * @anchor Iso15_ReadMultipleBlocks_RecvBlocks_Entry
 * 
 */
typedef struct {
	/**
	 * Contains the actual data read from a block.
	 */
	brp_buf RecvBlock;
	/**
	 * 
	 */
	size_t RecvBlock_len;
} brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry;
/**
 * @anchor Iso78_OpenSam_LID
 * Logical SAM-ID (LID)
 */
typedef enum {
	/**
	 * Use this value to select an _NXP MIFARE SAM AV2_ or _AV3_.
	 */
	brp_Iso78_OpenSam_LID_AV2 = 0,
	/**
	 * Use this value to select an _HID SE Processor_ (also known as _iClass SAM_).
	 */
	brp_Iso78_OpenSam_LID_HID = 1,
	/**
	 * Use this value to select a SAM different from those named above.
	 */
	brp_Iso78_OpenSam_LID_Gen1 = 16,
	/**
	 * Use this value only if the reader has 2 SAM slots, and both SAMs are different
	 * from those named above. In this case, use the values _Gen1_ and _Gen2_ in the
	 * following order:
	 * 
	 *   * Use _Gen1_ to select the first SAM.
	 *   * Use _Gen2_ to select the second SAM.
	 */
	brp_Iso78_OpenSam_LID_Gen2 = 17,
	brp_Iso78_OpenSam_LID_undefined = -1
} brp_Iso78_OpenSam_LID;
/**
 * @anchor Lg_Select_MediaType
 * Indicates the type of card that was selected.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_GAM = 1,
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_SAM = 2,
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_IAM = 3,
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_IM = 4,
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_NM = 5,
	/**
	 * 
	 */
	brp_Lg_Select_MediaType_XAM1 = 6,
	brp_Lg_Select_MediaType_undefined = -1
} brp_Lg_Select_MediaType;
/**
 * @anchor Lg_Select_EvStat
 * Event Status of operation.
 */
typedef enum {
	/**
	 * OK / no event.
	 */
	brp_Lg_Select_EvStat_OKNoEvent = 0,
	/**
	 * EEPROM for stamp data already full.
	 */
	brp_Lg_Select_EvStat_EEPROMFull = 1,
	/**
	 * Stamp data added to EEPROM.
	 */
	brp_Lg_Select_EvStat_StampToEEPROM = 2,
	/**
	 * Storing stamp data aborted because SAM out of HF field.
	 */
	brp_Lg_Select_EvStat_SamOutOfHF = 3,
	/**
	 * No stamp data available on SAM.
	 */
	brp_Lg_Select_EvStat_NoStampOnSAM = 4,
	/**
	 * Stamp data deleted.
	 */
	brp_Lg_Select_EvStat_StampDeleted = 5,
	/**
	 * Deletion of stamp aborted because SAM out of HF field.
	 */
	brp_Lg_Select_EvStat_StampDeletionAborted = 6,
	/**
	 * Stamp already in EEPROM.
	 */
	brp_Lg_Select_EvStat_StampAlreadyInEEPROM = 7,
	/**
	 * Stamp data was not stored to EEPROM.
	 */
	brp_Lg_Select_EvStat_StampNotStoredToEEPROM = 8,
	/**
	 * New stamp data with extended stamp Bytes was stored to EEPROM.
	 */
	brp_Lg_Select_EvStat_NewStampExtended = 9,
	brp_Lg_Select_EvStat_undefined = -1
} brp_Lg_Select_EvStat;
/**
 * @anchor Lg_Idle_PowOff
 * State of the HF field.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_Idle_PowOff_On = 0,
	/**
	 * 
	 */
	brp_Lg_Idle_PowOff_Off = 1,
	/**
	 * HF field off with additional power reduction features (without loss of
	 * functionality).
	 */
	brp_Lg_Idle_PowOff_OffPowerReduced = 2,
	brp_Lg_Idle_PowOff_undefined = -1
} brp_Lg_Idle_PowOff;
/**
 * @anchor Lg_GenSetRead_WriteExMode
 * Determines extended write conditions.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_GenSetRead_WriteExMode_ArbitraryWriting = 0,
	/**
	 * 
	 */
	brp_Lg_GenSetRead_WriteExMode_DecrementOnly = 1,
	/**
	 * 
	 */
	brp_Lg_GenSetRead_WriteExMode_IncrementOnly = 2,
	/**
	 * 
	 */
	brp_Lg_GenSetRead_WriteExMode_InvalidMode = 3,
	brp_Lg_GenSetRead_WriteExMode_undefined = -1
} brp_Lg_GenSetRead_WriteExMode;
/**
 * @anchor Lg_ReadSMStatus_MIMVersion
 * Size of detected MIM.
 */
typedef enum {
	/**
	 * 22 Bytes.
	 */
	brp_Lg_ReadSMStatus_MIMVersion_MIM022 = 0,
	/**
	 * 256 Bytes.
	 */
	brp_Lg_ReadSMStatus_MIMVersion_MIM256 = 2,
	/**
	 * 1024 Bytes.
	 */
	brp_Lg_ReadSMStatus_MIMVersion_MIM1024 = 3,
	brp_Lg_ReadSMStatus_MIMVersion_undefined = -1
} brp_Lg_ReadSMStatus_MIMVersion;
/**
 * @anchor Lg_SetPassword_PwdStat
 * Password protection status.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_SetPassword_PwdStat_Deactivated = 0,
	/**
	 * 
	 */
	brp_Lg_SetPassword_PwdStat_Activated = 1,
	/**
	 * 
	 */
	brp_Lg_SetPassword_PwdStat_AlreadySet = 2,
	brp_Lg_SetPassword_PwdStat_undefined = -1
} brp_Lg_SetPassword_PwdStat;
/**
 * @anchor Lg_Lock_PwdStat
 * Password protection status.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_Lock_PwdStat_Activated = 0,
	/**
	 * 
	 */
	brp_Lg_Lock_PwdStat_Deactivated = 1,
	brp_Lg_Lock_PwdStat_undefined = -1
} brp_Lg_Lock_PwdStat;
/**
 * @anchor Lg_Unlock_PwdStat
 * Password protection status.
 */
typedef enum {
	/**
	 * 
	 */
	brp_Lg_Unlock_PwdStat_Unlocked = 0,
	/**
	 * 
	 */
	brp_Lg_Unlock_PwdStat_NotActivated = 1,
	/**
	 * 
	 */
	brp_Lg_Unlock_PwdStat_AlreadyUnlocked = 2,
	brp_Lg_Unlock_PwdStat_undefined = -1
} brp_Lg_Unlock_PwdStat;
/**
 * @anchor Main_Bf2Upload_ResultCode
 * Error code of this operation
 */
typedef enum {
	/**
	 * Successful operation
	 */
	brp_Main_Bf2Upload_ResultCode_Success = 0,
	/**
	 * The checksum of the _line_ variable is invalid.
	 */
	brp_Main_Bf2Upload_ResultCode_InvalidChecksum = 1,
	/**
	 * Programming timeout; repeat operation (up to 3 times).
	 */
	brp_Main_Bf2Upload_ResultCode_ProgrammingTimeout = 2,
	/**
	 * Verify timeout; repeat operation (up to 3 times).
	 */
	brp_Main_Bf2Upload_ResultCode_VerifyTimeout = 3,
	/**
	 * Unsupported code type
	 */
	brp_Main_Bf2Upload_ResultCode_UnsupportedCodeType = 4,
	/**
	 * Protocol error
	 */
	brp_Main_Bf2Upload_ResultCode_ProtocolError = 5,
	/**
	 * Device is secured by a Config Security Code; perform a factory reset and
	 * repeat operation.
	 */
	brp_Main_Bf2Upload_ResultCode_SecuredByConfigSecurityCode = 6,
	brp_Main_Bf2Upload_ResultCode_undefined = -1
} brp_Main_Bf2Upload_ResultCode;
/**
 * @anchor Mce_Enable_Mode
 * 
 */
typedef enum {
	/**
	 * MCE will be enabled.
	 */
	brp_Mce_Enable_Mode_Disable = 0,
	/**
	 * MCE will be disabled.
	 */
	brp_Mce_Enable_Mode_Enable = 1,
	brp_Mce_Enable_Mode_undefined = -1
} brp_Mce_Enable_Mode;
/**
 * @anchor Mif_SectorSwitch_SectorSpec_Entry
 * 
 */
typedef struct {
	/**
	 * Block address of the sector that is switched to the targeted security level.
	 */
	unsigned BlockAddress;
	/**
	 * Crypto Memory Index (SAM or CryptoMemory) of the sector key.
	 * 
	 *   * SAM: MSByte: Key version / LSByte: KeyIdx 
	 *   * Crypto Memory: MSByte: Page (0..15) / LSByte: KeyIdx (0x80-0xBF)
	 */
	unsigned SectorKeyIdx;
} brp_Mif_SectorSwitch_SectorSpec_Entry;
/**
 * @anchor Mif_SetFraming_CommMode
 * Defines 14443-4 communication mode for MIFARE Plus EV1 cards.
 */
typedef enum {
	/**
	 * MIFARE native mode (default communication mode).
	 */
	brp_Mif_SetFraming_CommMode_MifareNative = 1,
	/**
	 * ISO 7816 compatible framing (only MIFARE Plus EV1)
	 */
	brp_Mif_SetFraming_CommMode_MifareISO = 2,
	brp_Mif_SetFraming_CommMode_undefined = -1
} brp_Mif_SetFraming_CommMode;
/**
 * @anchor MobileId_Enable_Mode
 * 
 */
typedef enum {
	/**
	 * Mobile ID is enabled.
	 */
	brp_MobileId_Enable_Mode_Disable = 0,
	/**
	 * Mobile ID is disabled.
	 */
	brp_MobileId_Enable_Mode_Enable = 1,
	brp_MobileId_Enable_Mode_undefined = -1
} brp_MobileId_Enable_Mode;
/**
 * @anchor Sys_GetBootStatus_BootStatus
 * 
 */
typedef struct {
	/**
	 * The reader chip has not accepted the reader chip firmware included in the
	 * latest firmware update, because it was already running a higher firmware
	 * version. This is a security feature that prevents the reader chip firmware
	 * from being downgraded below a specific version.
	 * 
	 * _Note:_ This only affects the reader chip, i.e. other reader components have
	 * accepted the latest firmware update.
	 * 
	 * _Solution:_ Usually, this is not an issue. However, if you want to get rid of
	 * this boot status, upgrade to the previously deployed firmware version or
	 * above.
	 */
	bool NewerReaderChipFirmware;
	/**
	 * At least 1 unexpected reboot has occurred. For details, see
	 * __Device/Statistics__.
	 */
	bool UnexpectedReboots;
	/**
	 * An error occurred during a factory reset, leaving the reader without any
	 * settings instead of restoring the factory settings.
	 */
	bool FactorySettings;
	/**
	 * The reader configuration is corrupted.  
	 * _Solution:_ Redeploy or update the reader configuration.
	 * 
	 * This is a legacy boot status. It's only returned by old firmware versions that
	 * don't yet support transaction security mechanisms. Newer firmware versions use
	 * the _Configuration_ bit.
	 */
	bool ConfigurationInconsistent;
	/**
	 * The Bluetooth chip of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Bluetooth;
	/**
	 * The WiFi chip of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool WiFi;
	/**
	 * The tamper alarm is defective.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Tamper;
	/**
	 * The battery management system of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool BatteryManagement;
	/**
	 * The keyboard of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Keyboard;
	/**
	 * The loaded firmware version is blacklisted (see __Device / Run /
	 * FirmwareVersionBlacklist__
	 * for more details).
	 */
	bool FirmwareVersionBlocked;
	/**
	 * The display of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Display;
	/**
	 * You've run a [VHL.Select](@ref VHL_Select) command with _AcceptConfCard_
	 * set to _true_ after presenting a
	 * [ConfigCard](https://docs.baltech.de/installation/deploy-config-via-
	 * configcard.html) to the reader.
	 * 
	 * This is a legacy boot status. On newer firmware versions, the
	 * [VHL.Select](@ref VHL_Select) command returns the
	 * [VHL.ConfcardRead](@ref VHL_ConfcardRead) status code.
	 */
	bool ConfCardPresented;
	/**
	 * The Ethernet interface of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Ethernet;
	/**
	 * The RGB LED features of the reader are defective.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool ExtendedLED;
	/**
	 * The 125 kHz RFID interface of the reader is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Rf125kHz;
	/**
	 * The 13.56 MHz RFID interface for ISO 14443/ISO 15693 card systems is
	 * defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Rf13MHz;
	/**
	 * The 13.56 Mhz RFID interface for LEGIC cards is defective, device out of
	 * order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Rf13MHzLegic;
	/**
	 * The 13.56 MHz RFID interface of the reader is defective, device out of order.
	 * 
	 * This is a legacy boot status. Newer firmware versions use the _Rf13Mhz_ bit.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Rf13MHzLegacy;
	/**
	 * A hardware options error occurred, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool HWoptions;
	/**
	 * The real-time clock is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool RTC;
	/**
	 * The data flash chip is defective, device out of order.
	 * 
	 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
	 * with us.**
	 */
	bool Dataflash;
	/**
	 * The reader configuration is corrupted.  
	 * _Solution:_ Redeploy or update the configuration.
	 */
	bool Configuration;
	/**
	 * The reader firmware is corrupted.  
	 * _Solution:_ Redeploy or update the firmware.
	 */
	bool CorruptFirmware;
	/**
	 * Due to an aborted upload, the firmware on the reader is incomplete and not
	 * fully functional.  
	 * _Solution:_ Repeat the firmware upload.
	 */
	bool IncompleteFirmware;
} brp_Sys_GetBootStatus_BootStatus;
/**
 * @anchor Sys_SetRegister_RegisterAssignments_Entry
 * 
 */
typedef struct {
	/**
	 * ID of register to set
	 */
	unsigned ID;
	/**
	 * New value of register to set
	 */
	unsigned Value;
} brp_Sys_SetRegister_RegisterAssignments_Entry;
/**
 * @anchor Sys_GetStatistics_CounterTuple_Entry
 * 
 */
typedef struct {
	/**
	 * ID of statistics counter (Baltech internal use)
	 */
	unsigned ID;
	/**
	 * Value of counter (Baltech internal use)
	 */
	unsigned Value;
} brp_Sys_GetStatistics_CounterTuple_Entry;
/**
 * @anchor Sys_CfgLoadFinish_FinalizeAction
 * Defines the reader's behaviour on error/success
 */
typedef enum {
	/**
	 * Cancel the BEC transfer and undo all configuration changes since
	 * [Sys.CfgLoadPrepare](@ref Sys_CfgLoadPrepare).
	 */
	brp_Sys_CfgLoadFinish_FinalizeAction_CancelCfgLoad = 0,
	/**
	 * Complete the BEC transfer, but don't reboot.
	 * 
	 * **A reboot is necessary to ensure all configuration changes are activated.
	 * Thus, we recommend you only use this value if another operation is pending
	 * that requires a reboot as well (e.g. a firmware update).**
	 */
	brp_Sys_CfgLoadFinish_FinalizeAction_FinalizeCfgLoadWithoutReboot = 1,
	/**
	 * Complete the BEC transfer and do an implicit reboot. This requires
	 * reconnecting as described in [Sys.Reset](@ref Sys_Reset).
	 * 
	 * **This is the value we generally recommend as the reboot ensures that all
	 * changes are activated.**
	 */
	brp_Sys_CfgLoadFinish_FinalizeAction_FinalizeCfgLoadWithReboot = 2,
	brp_Sys_CfgLoadFinish_FinalizeAction_undefined = -1
} brp_Sys_CfgLoadFinish_FinalizeAction;
/**
 * @anchor TTF_ReadByteStream_RxMod
 * Decoder settings - for ID-engine Z use SMPL.
 */
typedef enum {
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_Manchester = 16,
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_Biphase = 32,
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_Ind = 48,
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_HIDP = 80,
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_PSK = 96,
	/**
	 * 
	 */
	brp_TTF_ReadByteStream_RxMod_SMPL = 112,
	brp_TTF_ReadByteStream_RxMod_undefined = -1
} brp_TTF_ReadByteStream_RxMod;
/**
 * @anchor EpcUid_EpcSetMode_Coding
 * Specifies modulation type.
 */
typedef enum {
	/**
	 * 
	 */
	brp_EpcUid_EpcSetMode_Coding_FM0 = 0,
	/**
	 * 
	 */
	brp_EpcUid_EpcSetMode_Coding_Miller8 = 1,
	/**
	 * 
	 */
	brp_EpcUid_EpcSetMode_Coding_Man2 = 2,
	/**
	 * 
	 */
	brp_EpcUid_EpcSetMode_Coding_Man4 = 3,
	brp_EpcUid_EpcSetMode_Coding_undefined = -1
} brp_EpcUid_EpcSetMode_Coding;
/**
 * @anchor EpcUid_EpcSelect_MemBank
 * Specifies memory bank.
 */
typedef enum {
	/**
	 * 
	 */
	brp_EpcUid_EpcSelect_MemBank_EPC = 1,
	/**
	 * 
	 */
	brp_EpcUid_EpcSelect_MemBank_TID = 2,
	/**
	 * 
	 */
	brp_EpcUid_EpcSelect_MemBank_User = 3,
	brp_EpcUid_EpcSelect_MemBank_undefined = -1
} brp_EpcUid_EpcSelect_MemBank;
/**
 * @anchor Ultralight_AuthE2_DivMode
 * Specifies diversification algorithm.
 */
typedef enum {
	/**
	 * No diversification.
	 */
	brp_Ultralight_AuthE2_DivMode_NoDiv = 0,
	/**
	 * SAM AV1 mode (1 encryption round for Tripple DES keys).
	 */
	brp_Ultralight_AuthE2_DivMode_SamAv1OneRound = 1,
	/**
	 * SAM AV1 mode (2 encryption rounds for Tripple DES keys).
	 */
	brp_Ultralight_AuthE2_DivMode_SamAv1TwoRounds = 2,
	/**
	 * SAM AV2 mode (AES according to NXP: AN 10922).
	 */
	brp_Ultralight_AuthE2_DivMode_SamAv2 = 3,
	brp_Ultralight_AuthE2_DivMode_undefined = -1
} brp_Ultralight_AuthE2_DivMode;
/**
 * @anchor Ultralight_AuthUser_CryptoMode
 * Sets the encryption algorithm.
 */
typedef enum {
	/**
	 * For Ultralight-C authentication, a Tripple DES key has to be specified.
	 */
	brp_Ultralight_AuthUser_CryptoMode_TripleDES = 0,
	/**
	 * For Ultralight-EV1 password diversification (NXP AN12694), an AES key has to
	 * be specified.
	 */
	brp_Ultralight_AuthUser_CryptoMode_AES = 1,
	brp_Ultralight_AuthUser_CryptoMode_undefined = -1
} brp_Ultralight_AuthUser_CryptoMode;
/**
 * @anchor UsbHost_SetupPipes_Type
 * Type of Pipe.
 */
typedef enum {
	/**
	 * 
	 */
	brp_UsbHost_SetupPipes_Type_Control = 0,
	/**
	 * 
	 */
	brp_UsbHost_SetupPipes_Type_Interrupt = 1,
	/**
	 * 
	 */
	brp_UsbHost_SetupPipes_Type_Bulk = 2,
	/**
	 * 
	 */
	brp_UsbHost_SetupPipes_Type_Isochronous = 3,
	brp_UsbHost_SetupPipes_Type_undefined = -1
} brp_UsbHost_SetupPipes_Type;
/**
 * @anchor UsbHost_SetupPipes_Pipes_Entry
 * 
 */
typedef struct {
	/**
	 * Number of Pipe.
	 */
	unsigned No;
	/**
	 * Type of Pipe.
	 */
	brp_UsbHost_SetupPipes_Type Type;
	/**
	 * Maximum Packet Size of Pipe. Possible Values are 8, 16, 32 and 64.
	 */
	unsigned FrameSize;
} brp_UsbHost_SetupPipes_Pipes_Entry;
/**
 * @anchor UI_Toggle_Polarity
 * 
 */
typedef enum {
	/**
	 * The initial and final port state is disabled/inactive/low.
	 */
	brp_UI_Toggle_Polarity_Normal = 0,
	/**
	 * The initial and final port state is enabled/active/high.
	 */
	brp_UI_Toggle_Polarity_Inverted = 1,
	brp_UI_Toggle_Polarity_undefined = -1
} brp_UI_Toggle_Polarity;
/**
 * @anchor VHL_Setup_AdrMode
 * Specifies the addressing mode. This parameter is only available on readers
 * supporting LEGIC advant. LEGIC prime readers ignore it.
 * 
 * **To allow for backward compatibility with LEGIC prime readers, omitting this
 * parameter will _not_ result in the default value, but in the following
 * behavior: VHL address 0 is mapped to protocol header address _25_ , starting
 * with the first data byte after the longest possible LEGIC prime stamp.**
 */
typedef enum {
	/**
	 * To read the segment _stamp_ , use this mode.
	 * 
	 * VHL address 0 corresponds to protocol header address 18, starting with the
	 * first stamp data byte. The stamp, which has a length between 1 and 12 bytes,
	 * is followed by the application data.
	 */
	brp_VHL_Setup_AdrMode_ProtocolHeader = 0,
	/**
	 * To only read the _application data_ of the segment, use this mode.
	 * 
	 * VHL address 0 corresponds to address 0 in the user-specific application data
	 * area ("DATA area" according to the LEGIC documentation).
	 * 
	 * **
	 * 
	 * For _LEGIC prime_ cards, this addressing mode is available only with
	 * restrictions: Here, the stamp length is undefined - the card doesn't know it.
	 * So, when accessing the card using _VHL.Setup_ , the stamp in _SegmentInfo_
	 * with the given length will be applied.
	 * 
	 * If the actual stamp is longer, the reader assigns the remaining part of the
	 * stamp to the application data area (DATA). If the segment is accessed via
	 * segment number, no stamp length information is available at all. In this case,
	 * the application data area (DATA) contains the complete stamp (this is
	 * equivalent to the _ProtocolHeader_ addressing mode).
	 * 
	 * See the following table for examples.
	 * 
	 * **
	 * 
	 * _SegmentInfo_ | _EnStamp_ | _AdrMode_ | Result of VHL.Read(Id=0xFF, Adr=0, Len=5)  
	 * ---|---|---|---  
	 * 1 | False | _ProtocolHeader_ | 0x11 22 33 44 01  
	 * 0x11 22 33 | True | _ProtocolHeader_ | 0x11 22 33 44 01  
	 * 1 | False | _Advant_ | 0x11 22 33 44 01  
	 * 0x11 22 33 44 | False | _Advant_ | 0x01 02 03 04 05  
	 * 0x11 22 | True | _Advant_ | 0x33 44 01 02 03
	 */
	brp_VHL_Setup_AdrMode_Advant = 1,
	brp_VHL_Setup_AdrMode_undefined = -1
} brp_VHL_Setup_AdrMode;
/**
 * @anchor VHL_Setup_OptionFlag
 * Option flag value for read/write operations
 */
typedef enum {
	/**
	 * 
	 */
	brp_VHL_Setup_OptionFlag_OptFlagZero = 0,
	/**
	 * 
	 */
	brp_VHL_Setup_OptionFlag_OptFlagOne = 1,
	/**
	 * 
	 */
	brp_VHL_Setup_OptionFlag_OptFlagAuto = 2,
	brp_VHL_Setup_OptionFlag_undefined = -1
} brp_VHL_Setup_OptionFlag;
/**
 * @anchor VHL_Setup_FileSpecifier
 * The method to select the file.
 */
typedef enum {
	/**
	 * Select the file by path, i.e. a list of 16-bit file IDs  
	 * If a single file ID is used, a MF, DF, or EF can be specified -> P1 is set to
	 * 0  
	 * If a list of file ID is used, the path without the MF has to be specified ->
	 * P1 is set to 8
	 */
	brp_VHL_Setup_FileSpecifier_SelectByPath = 0,
	/**
	 * Select the file by DF name (1..16 bytes)
	 */
	brp_VHL_Setup_FileSpecifier_SelectByName = 1,
	/**
	 * Select the file using an APDU command
	 */
	brp_VHL_Setup_FileSpecifier_SelectByAPDU = 2,
	brp_VHL_Setup_FileSpecifier_undefined = -1
} brp_VHL_Setup_FileSpecifier;
/**
 * @anchor VHL_Setup_SelectFileCmdList_Entry
 * 
 */
typedef struct {
	/**
	 * The method to select the file.
	 */
	brp_VHL_Setup_FileSpecifier FileSpecifier;
	/**
	 * The path, filename, or APDU command by which to select the file. Depends on
	 * the method specified in _FileSpecifier_.
	 */
	brp_buf FileDescriptor;
	/**
	 * 
	 */
	size_t FileDescriptor_len;
} brp_VHL_Setup_SelectFileCmdList_Entry;
/**
 * @anchor DHWCtrl_GetReaderChipType_ChipType
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_GetReaderChipType_ChipType_RC500 = 1,
	/**
	 * 
	 */
	brp_DHWCtrl_GetReaderChipType_ChipType_RC632 = 4,
	/**
	 * 
	 */
	brp_DHWCtrl_GetReaderChipType_ChipType_RC663 = 5,
	/**
	 * 
	 */
	brp_DHWCtrl_GetReaderChipType_ChipType_PN512 = 33,
	brp_DHWCtrl_GetReaderChipType_ChipType_undefined = -1
} brp_DHWCtrl_GetReaderChipType_ChipType;
/**
 * @anchor DHWCtrl_GetSamType_ChipType
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_GetSamType_ChipType_TDA8007C2 = 1,
	/**
	 * 
	 */
	brp_DHWCtrl_GetSamType_ChipType_TDA8007C3 = 2,
	brp_DHWCtrl_GetSamType_ChipType_undefined = -1
} brp_DHWCtrl_GetSamType_ChipType;
/**
 * @anchor DHWCtrl_HfAcquire_ModuleId
 * HF subsystem to activate
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_No = 0,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_RC = 1,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_Legic = 3,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_PN = 17,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_LegicAdvant = 19,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_RC125 = 24,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_PN2 = 26,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_RC663 = 34,
	/**
	 * 
	 */
	brp_DHWCtrl_HfAcquire_ModuleId_HTRC110 = 36,
	brp_DHWCtrl_HfAcquire_ModuleId_undefined = -1
} brp_DHWCtrl_HfAcquire_ModuleId;
/**
 * @anchor DHWCtrl_AesWrapKey_WrappedKeyNr
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_AesWrapKey_WrappedKeyNr_WrapNone = 0,
	/**
	 * 
	 */
	brp_DHWCtrl_AesWrapKey_WrappedKeyNr_WrapDHUK = 1,
	brp_DHWCtrl_AesWrapKey_WrappedKeyNr_undefined = -1
} brp_DHWCtrl_AesWrapKey_WrappedKeyNr;
/**
 * @anchor DHWCtrl_AesEncrypt_WrappedKeyNr
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_AesEncrypt_WrappedKeyNr_WrapNone = 0,
	/**
	 * 
	 */
	brp_DHWCtrl_AesEncrypt_WrappedKeyNr_WrapDHUK = 1,
	brp_DHWCtrl_AesEncrypt_WrappedKeyNr_undefined = -1
} brp_DHWCtrl_AesEncrypt_WrappedKeyNr;
/**
 * @anchor DHWCtrl_AesDecrypt_WrappedKeyNr
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_DHWCtrl_AesDecrypt_WrappedKeyNr_WrapNone = 0,
	/**
	 * 
	 */
	brp_DHWCtrl_AesDecrypt_WrappedKeyNr_WrapDHUK = 1,
	brp_DHWCtrl_AesDecrypt_WrappedKeyNr_undefined = -1
} brp_DHWCtrl_AesDecrypt_WrappedKeyNr;
/**
 * @anchor CardTypes125KhzPart1
 * 
 */
typedef struct {
	/**
	 * Low level card type / programmable decoder
	 */
	bool TTF;
	/**
	 * HITAG 2 Biphase
	 */
	bool Hitag2B;
	/**
	 * HITAG 2 Manchester
	 */
	bool Hitag2M;
	/**
	 * HITAG 1 or S
	 */
	bool Hitag1S;
	/**
	 * ioProx
	 */
	bool HidIoprox;
	/**
	 * HID Proximity
	 */
	bool HidProx;
	/**
	 * AWID
	 */
	bool HidAwid;
	/**
	 * Indala ASP
	 */
	bool HidIndala;
	/**
	 * QuadraKey
	 */
	bool Quadrakey;
	/**
	 * Keri
	 */
	bool Keri;
	/**
	 * HID Prox32
	 */
	bool HidProx32;
	/**
	 * Farpointe Pyramid
	 */
	bool Pyramid;
	/**
	 * EM4450
	 */
	bool EM4450;
	/**
	 * EM4100/EM4102
	 */
	bool EM4100;
	/**
	 * EM4205/EM4305
	 */
	bool EM4205;
} brp_CardTypes125KhzPart1;
/**
 * @anchor CardTypes125KhzPart2
 * 
 */
typedef struct {
	/**
	 * Idteck
	 */
	bool Idteck;
	/**
	 * Cotag
	 */
	bool Cotag;
	/**
	 * Indala ASP+
	 */
	bool HidIndalaSecure;
	/**
	 * G-Prox
	 */
	bool GProx;
	/**
	 * SecuraKey
	 */
	bool SecuraKey;
} brp_CardTypes125KhzPart2;
/**
 * @anchor DesfireKeyIdx
 * * 0x00-0x7F: index to SAM key, key version has to be 0 
 *   * 0x80-0xBF: index to key defined in crypto memory of the reader: __Device/CryptoKey__
 *   * 0xC0-0xCB: index to key defined in VHL file: __DesfireKeyList__
 *   * 0xFE: _legacy_ , use transport key 0xFF: key index unused
 */
typedef unsigned brp_DesfireKeyIdx;
/**
 * @anchor FileType
 * Filetypes supported by VHL.
 */
typedef enum {
	/**
	 * File is specified by DF name
	 */
	brp_FileType_FileByDfName = 0,
	/**
	 * File is specified by 2 byte FID
	 */
	brp_FileType_FileByFileId = 1,
	/**
	 * File is specified by APDU Select command that has to be executed to activate a
	 * file.
	 */
	brp_FileType_FileByApduCmd = 2,
	brp_FileType_undefined = -1
} brp_FileType;
/**
 * @anchor SegmentIdentificationAndAddressing
 * This byte defines how a Legic segment shall be accessed.
 * 
 * There are two possibilities to select a certain segment on a Legic card:
 * 
 *   * ID: The reader selects the segment with the desired number. 
 *   * Stamp: The reader selects the first segment that matches the desired stamp. 
 * 
 * **If possible always stamp search should be used for segment identification to
 * guarantee that only genuine cards are processed!**
 * 
 * Legic advant compatible readers support two addressing modes:
 * 
 *   * Protocol Header: Stamp data (read-only) can be accessed starting with address 18 (data below address 18 is undefined). Application data follows directly after the stamp. 
 *   * Advant: Application data stored in S_DATA can be accessed starting with address 0. Stamp data is not accessible in this case.
 */
typedef struct {
	/**
	 * Use Advant address mode. If this bit is not set Protocol Header address mode
	 * will be applied.
	 */
	bool AdvantAddressMode;
	/**
	 * Use Stamp search to identify the desired segment. If this bit is not set the
	 * segment will be identified by ID.
	 */
	bool StampSearch;
} brp_SegmentIdentificationAndAddressing;
/**
 * @anchor AddressAndEnableCRC
 * This word defines the start address according to the addressing mode selected
 * in
 * __SegmentIdentificationAndAddressing__
 * for every fragment.
 * 
 * The MSB determines if a CRC check shall be applied for accessing this segment.
 */
typedef struct {
	/**
	 * CRC check is enabled for this fragment. In this case there must be an address
	 * entry in __LegicCRCAddressList__.
	 */
	bool EnableCRC;
} brp_AddressAndEnableCRC;
/**
 * @anchor CRCAddressAndCRCType
 * This word defines the CRC address according to the addressing mode selected in
 * __SegmentIdentificationAndAddressing__.
 * There must be an entry for every fragment that has enabled the CRC check in
 * AddressAndEnableCRC.
 * 
 * The MSB determines the CRC type.
 */
typedef struct {
	/**
	 * Use 16-bit CRC
	 */
	bool CRC16bit;
} brp_CRCAddressAndCRCType;
/**
 * @anchor MifareClassicVhlKeyAssignment
 * This bitmask can be combined with a reference to a key index in the readers
 * keylist and specifies more details.
 */
typedef struct {
	/**
	 * The key assigned to this sector shall not be taken from the VHL file
	 */
	bool Secure;
	/**
	 * The key assigned to this sector/block shall be applied as key B
	 */
	bool KeyB;
} brp_MifareClassicVhlKeyAssignment;
/**
 * @anchor MifarePlusKeyMemoryType
 * This value references a key memory type within the reader. VHL detects the
 * security level (SL0..3) of a Mifare classic/plus card automatically and
 * according to the security level the adequate key memories (AES and/or Mifare
 * keys) are chosen. For some key memory types a card in Mifare plus security
 * level 2 (SL2) needs both keys (AES and Mifare): then the configuration value
 * __MifarePlusKeyIdxOffset__ describes an
 * offset of Mifare keys to AES keys (! signed value).
 */
typedef enum {
	/**
	 * References keys within the __CryptoKey__ memory.  
	 * Key offset needed: refer to
	 * __MifarePlusKeyIdxOffset__
	 */
	brp_MifarePlusKeyMemoryType_CryptoKey = 0,
	/**
	 * References keys within a SAM, only available on SAM based readers: key index
	 * from 0x00 to 0x7F, a SAM key contains up to 3 AES keys with different versions
	 * or 3 Mifare key pairs (A and B). VHL uses always the first SAM key.  
	 * Key offset needed: see
	 * __MifarePlusKeyIdxOffset__
	 */
	brp_MifarePlusKeyMemoryType_SamKey = 1,
	/**
	 * References keys which are stored in reader chip memory: 32 keys (index 0..31)
	 * are available.
	 * 
	 * **This memory contains only keys for Mifare classic cards (SL1).**
	 */
	brp_MifarePlusKeyMemoryType_ReaderChipKey = 2,
	/**
	 * References keys which are defined in respective VHL files:  
	 * AES keys in __MifarePlusAesKeyList__  
	 * Mifare keys in __MifareKeyList__
	 */
	brp_MifarePlusKeyMemoryType_VhlKey = 3,
	brp_MifarePlusKeyMemoryType_undefined = -1
} brp_MifarePlusKeyMemoryType;
/**
 * @anchor TemplateBitorder
 * This is the bit order for the _CutNibbles_ command.
 */
typedef enum {
	/**
	 * Handle Bytes in Least significant bit first order.
	 */
	brp_TemplateBitorder_Lsb = 0,
	/**
	 * Handle Bytes in Most significant bit first order.
	 */
	brp_TemplateBitorder_Msb = 1,
	brp_TemplateBitorder_undefined = -1
} brp_TemplateBitorder;
/**
 * @anchor TemplateFilter
 * For every of these filter bits, a specific data conversion mechanism is
 * specified. This mechanism is applied to a TemplateCommand if the filterbit is
 * set.
 * 
 * The activated filters are applied ordered by there value. Starting with the
 * smallest value.
 */
typedef struct {
	/**
	 * Converts a BCD Number (must only contain nibbles 0-9, not A-F) to a binary
	 * number. Input and Output data are _MSB encoded_.
	 * 
	 * The length of the destination data is the length of the source data (in bytes)
	 * multiplied by 0.83048 (and rounded down to the next byte boundary).
	 * 
	 * **Some source data's binary representation is longer than the calculated
	 * destination length. If such source data could occur, an additional leading
	 * zerobyte has to be inserted in front of the source data**
	 * 
	 * ` 0x12 0x34 => 0x04 0xD2 `
	 */
	bool BcdToBin;
	/**
	 * Convert Binarydata to ASCII by converting the ASCII characters 0x00-0x09 to
	 * 0x30-0x39 and 0x0A-0x0F to 0x41-0x49. ` 0x01 0x0A -> 0x31 0x41 `
	 */
	bool BinToAscii;
	/**
	 * Splits the high and the low nibble of each byte into two separate bytes, where
	 * the high nibble is set to 0. ` 0x01 CF => 0x00 0x01 0x0C 0x0F `
	 */
	bool Unpack;
	/**
	 * Converts a binary Number to a BCD encoded number. Input and Output data are
	 * _MSB encoded_.
	 * 
	 * The length of the destination data is the length of the source data in bytes)
	 * multiplied by 1.2041 (and rounded up to the next byte boundary).
	 * 
	 * **This is not exactly the inverse of BcdToBin, since the length may differ.**
	 * 
	 * ` 0x04 0xD2 => 0x12 0x34 `
	 */
	bool BinToBcd;
	/**
	 * Swap the higher nibble (bits 5-7) of each byte with the lower nibble (bits
	 * 0-3). ` 0x12 0x34 0xEF => 0x21 0x43 0xFE `
	 */
	bool SwapNibbles;
	/**
	 * Merges two Bytes at a time to a single one by removing the leading nibble
	 * (which has to be 0) of each byte. ` 0x03 0x0F -> 0x3F `
	 */
	bool Pack;
	/**
	 * Convert ASCII to Binarydata by converting the ASCII characters 0x30-0x39 to
	 * 0x00-0x09 and 0x41-0x49 (0x61-0x66) to 0x0A-0x0F. ` 0x31 0x41 -> 0x01 0x0A `
	 */
	bool AsciiToBin;
	/**
	 * Swap the first byte with the last one, the second one with the next to last
	 * one and so on. ` 0x12 0x3D 0xEF => 0xEF 0x3D 0x12 `
	 */
	bool Reverse;
} brp_TemplateFilter;
/**
 * @anchor AutoRunCommand
 * 
 */
typedef struct {
	/**
	 * 
	 */
	brp_AutoRunCommand_RunMode RunMode;
	/**
	 * 
	 */
	unsigned DeviceCode;
	/**
	 * 
	 */
	unsigned CommandCode;
	/**
	 * The length of this block depends on the length of the command
	 */
	char* Parameter;
} brp_AutoRunCommand;
/**
 * @anchor ProtocolID
 * A list of all protocols.
 * 
 * **Not all protocols are available on all Firmware variants.**
 */
typedef enum {
	/**
	 * BRP protocol over UART. This protocol has also to be used if the USB-virtual-
	 * comport-emulation is used.
	 */
	brp_ProtocolID_BrpSerial = 3,
	/**
	 * BRP protocol over RS485 connection. Is used for long distances or when needing
	 * multiple devices on a single host.
	 */
	brp_ProtocolID_BrpRs485 = 4,
	/**
	 * BRP protocol over HID (Human Interface Device) Protocol. This is a standard
	 * USB Protocol with drivers for all OSes.
	 */
	brp_ProtocolID_BrpHid = 5,
	/**
	 * BRP protocol over TCP/IP.
	 */
	brp_ProtocolID_BrpTcp = 134,
	/**
	 * The debug interface may be used to look into the readers internals via a
	 * Terminal. Works over UART or virtual-comport-emulation.
	 */
	brp_ProtocolID_DebugInterface = 9,
	/**
	 * This is a autoread protocol that sends the ID read by autoread mode without
	 * any protocol overhead. Works over UART or virtual-comport-emulation.
	 */
	brp_ProtocolID_RawSerial = 35,
	/**
	 * This is a autoread protocol that sends the ID read by autoread mode via
	 * Wiegand protocol.
	 */
	brp_ProtocolID_Wiegand = 32,
	/**
	 * USB devices will register as keyboard if this value is active. When the
	 * autoread mode detected an ID it will be send by emulating keypresses.
	 */
	brp_ProtocolID_KeyboardEmulation = 43,
	/**
	 * configures the pins which are usually used by the _Wiegand_ / _RawSerial_ /...
	 * protocol as I/O Ports that can be controlled via scripts.
	 * 
	 * I/O Port  |  physical pin   
	 * ---|---  
	 * Gpio5  |  TX of RawSerial protocol   
	 * Gpio6  |  direction line on RS485 protocols   
	 * Gpio7  |  RX pin of RawSerial protocol
	 */
	brp_ProtocolID_LowLevelIoPorts = 36,
	/**
	 * 
	 */
	brp_ProtocolID_ClkData = 34,
	/**
	 * 
	 */
	brp_ProtocolID_Omron = 33,
	/**
	 * 
	 */
	brp_ProtocolID_Snet = 16,
	/**
	 * 
	 */
	brp_ProtocolID_Bpa9 = 17,
	/**
	 * Chip Card Interface Device (CCID). USB protocol that allows a smartcard to be
	 * connected to a computer via a card reader using a standard USB interface.
	 */
	brp_ProtocolID_Ccid = 54,
	/**
	 * This is a second autoread protocol that sends the ID read by autoread mode
	 * without any protocol overhead.
	 */
	brp_ProtocolID_RawSerial2 = 55,
	/**
	 * Open Supervised Standard Protocol. New Protocol Standard used for long
	 * distances or when needing multiple devices on a single host.
	 */
	brp_ProtocolID_Osdp = 56,
	brp_ProtocolID_undefined = -1
} brp_ProtocolID;
/**
 * @anchor MessageType
 * Event that triggered the message. It allows the host application to interpret
 * the message content correctly.
 */
typedef enum {
	/**
	 * A card was presented to the reader. The Autoread subsytem has read and
	 * converted the card's number based on the RFID interface component in the
	 * reader configuration. The result is returned in the message content.
	 */
	brp_MessageType_Card = 0,
	/**
	 * The tamper alarm was activated. By default, the message content is empty.
	 */
	brp_MessageType_AlarmOn = 1,
	/**
	 * The tamper alarm was deactivated. By default, the message content is empty.
	 */
	brp_MessageType_AlarmOff = 2,
	/**
	 * A PIN was entered via the reader's keyboard. The entered digits are returned
	 * in the message content.
	 */
	brp_MessageType_Keyboard = 3,
	/**
	 * A previously presented card has been removed. By default, the message content
	 * is empty.
	 * 
	 * **This message type is only generated if the reader is configured to scan for
	 * card removals (Device.Run.AutoreadWaitForCardRemoval).**
	 */
	brp_MessageType_CardRemoval = 4,
	/**
	 * The user has pressed a certain function key, e.g. the hash (#), star (*), or
	 * ENTER (E) key. The code of the entered key is returned in the message content.
	 */
	brp_MessageType_FunctionKey = 5,
	/**
	 * The reader returned a log message.
	 * 
	 * **When you request support, please forward these log messages to us to help us
	 * investigate the underlying issue. Please collect log messages from _all_
	 * readers in your project. Only then will they provide meaningful insights.**
	 */
	brp_MessageType_Logs = 6,
	brp_MessageType_undefined = -1
} brp_MessageType;
/**
 * @anchor MaxBaudrateIso14443
 * 
 */
typedef enum {
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri106Dsi106 = 0,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri212Dsi106 = 1,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri424Dsi106 = 2,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri848Dsi106 = 3,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri106Dsi212 = 4,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri212Dsi212 = 5,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri424Dsi212 = 6,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri848Dsi212 = 7,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri106Dsi424 = 8,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri212Dsi424 = 9,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri424Dsi424 = 10,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri848Dsi424 = 11,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri106Dsi848 = 12,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri212Dsi848 = 13,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri424Dsi848 = 14,
	/**
	 * 
	 */
	brp_MaxBaudrateIso14443_Dri848Dsi848 = 15,
	brp_MaxBaudrateIso14443_undefined = -1
} brp_MaxBaudrateIso14443;
/**
 * @anchor KeyAccessRights
 * 
 */
typedef struct {
	/**
	 * Accessrights for Keys. By default all operations are allowed. But with this
	 * bitmask this key can be locked for some operations.
	 */
	brp_KeyAccessRights_KeySettings KeySettings;
	/**
	 * Key version.
	 */
	unsigned Version;
	/**
	 * 
	 */
	brp_KeyAccessRights_DiversificationMode DiversificationMode;
	/**
	 * Index for data converter rule located in Project.DiversificationData: range
	 * 0..0x7F
	 */
	unsigned DivIdx;
} brp_KeyAccessRights;
/**
 * @anchor CryptoMemoryIndex
 * 
 */
typedef struct {
	/**
	 * Project crypto memory page (range 0..0x0F)
	 */
	unsigned Page;
	/**
	 * Project crypto memory index within page (range 0x80..0xBF)
	 */
	unsigned Idx;
} brp_CryptoMemoryIndex;
/**
 * @anchor CryptoAlgorithm
 * This byte defines the crypto algorithm that shall be used when working with
 * the key that is following. The CryptoAlgorithm furhtermore implies the length
 * of the following key
 */
typedef enum {
	/**
	 * Keylength: 8 byte
	 */
	brp_CryptoAlgorithm_DES = 1,
	/**
	 * Keylength: 16 byte
	 */
	brp_CryptoAlgorithm_TripleDES = 2,
	/**
	 * Keylength: 24 byte
	 */
	brp_CryptoAlgorithm_ThreeKeyTripleDES = 3,
	/**
	 * Keylength: 16 byte
	 */
	brp_CryptoAlgorithm_AES = 4,
	/**
	 * Keylength: 6 byte
	 */
	brp_CryptoAlgorithm_MifareClassic = 5,
	brp_CryptoAlgorithm_undefined = -1
} brp_CryptoAlgorithm;
/**
 * @anchor DivisorInteger
 * _Divisor Send/Receive Integer_ (DSI/DRI)
 * 
 * This parameter is mapped to the _Divisor Send/Receive_ (DS/DI) value, which
 * determines bit rate for sending data from PICC to PCD. The possible DS/DR
 * values (mapped to the DSI/DRI index) are listed below.
 */
typedef enum {
	/**
	 * 
	 */
	brp_DivisorInteger_Kbps106 = 0,
	/**
	 * 
	 */
	brp_DivisorInteger_Kbps212 = 1,
	/**
	 * 
	 */
	brp_DivisorInteger_Kbps424 = 2,
	/**
	 * 
	 */
	brp_DivisorInteger_Kbps848 = 3,
	brp_DivisorInteger_undefined = -1
} brp_DivisorInteger;
/**
 * @anchor Time
 * 
 */
typedef unsigned brp_Time;
/**
 * @anchor IoPortBitmask
 * 
 */
typedef struct {
	/**
	 * 
	 */
	bool Gpio7;
	/**
	 * 
	 */
	bool Gpio6;
	/**
	 * 
	 */
	bool Gpio5;
	/**
	 * 
	 */
	bool Gpio4;
	/**
	 * 
	 */
	bool Gpio3;
	/**
	 * 
	 */
	bool Gpio2;
	/**
	 * 
	 */
	bool Gpio1;
	/**
	 * 
	 */
	bool Gpio0;
	/**
	 * 
	 */
	bool TamperAlarm;
	/**
	 * 
	 */
	bool BlueLed;
	/**
	 * 
	 */
	bool Input1;
	/**
	 * 
	 */
	bool Input0;
	/**
	 * 
	 */
	bool Relay;
	/**
	 * 
	 */
	bool Beeper;
	/**
	 * 
	 */
	bool RedLed;
	/**
	 * 
	 */
	bool GreenLed;
} brp_IoPortBitmask;
/**
 * @anchor FeatureID
 * 
 */
typedef enum {
	/**
	 * The reader has a green LED.
	 */
	brp_FeatureID_GreenLed = 1,
	/**
	 * The reader has a red LED.
	 */
	brp_FeatureID_RedLed = 2,
	/**
	 * The reader has a beeper.
	 */
	brp_FeatureID_Beeper = 3,
	/**
	 * The reader can switch a relay.
	 */
	brp_FeatureID_Relay = 4,
	/**
	 * The reader supports 13.56 MHz cards.
	 */
	brp_FeatureID_MHz13 = 5,
	/**
	 * The reader supports 125 kHz cards.
	 */
	brp_FeatureID_Khz125 = 6,
	/**
	 * The reader supports ISO 14443 Type A cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Iso14443A = 7,
	/**
	 * The reader can read the UID of an ISO 14443 Type A card.
	 * 
	 * **If _Iso14443A_ is listed as well, that feature scope applies.**
	 */
	brp_FeatureID_Iso14443AUidOnly = 8,
	/**
	 * The reader supports ISO 14443 Type B cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Iso14443B = 9,
	/**
	 * The reader can read the UID of an ISO 14443 Type B card.
	 * 
	 * **If _Iso14443B_ is listed as well, that feature scope applies.**
	 */
	brp_FeatureID_Iso14443BUidOnly = 10,
	/**
	 * The reader supports ISO 15693 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Iso15693 = 11,
	/**
	 * The reader can read the UID of an ISO 15693 card.
	 * 
	 * **If _Iso15693_ is listed as well, that feature scope applies.**
	 */
	brp_FeatureID_Iso15693UidOnly = 12,
	/**
	 * The reader supports FeliCa cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Felica = 13,
	/**
	 * The reader can read the UID of a FeliCa card.
	 * 
	 * **If _FeliCa_ is listed as well, that feature scope applies.**
	 */
	brp_FeatureID_FelicaUidOnly = 14,
	/**
	 * The reader supports LEGIC cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Legic = 15,
	/**
	 * The reader has a SAM slot.
	 */
	brp_FeatureID_Sam = 16,
	/**
	 * A SAM AV2 card is inserted.
	 */
	brp_FeatureID_SamAv2 = 17,
	/**
	 * An HID SAM card is inserted.
	 */
	brp_FeatureID_SamHid = 18,
	/**
	 * The reader supports PicoPass cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Picopass = 19,
	/**
	 * The reader supports MIFARE Classic cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifareClassic = 35,
	/**
	 * The reader supports MIFARE Plus EV0 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifarePlusEv0 = 36,
	/**
	 * The reader supports MIFARE DESFire EV1 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifareDESFireEv1 = 37,
	/**
	 * The reader supports ST SRIX cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Srix = 38,
	/**
	 * The reader supports Jewel cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Jewel = 39,
	/**
	 * The reader supports ISO 14443-4 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_ISO14443L4 = 40,
	/**
	 * The reader supports inter-industry ISO 14443-4 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_InterIndustry = 41,
	/**
	 * The reader supports EM 4205 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_EM4205 = 42,
	/**
	 * The reader supports EM 4100 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_EM4100 = 43,
	/**
	 * The reader supports EM 4450 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_EM4450 = 44,
	/**
	 * The reader supports Farpointe Pyramid cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_FarpointePyramid = 45,
	/**
	 * The reader supports HID Prox32 tags as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidProx32 = 46,
	/**
	 * The reader supports HID AWID tags as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidAwid = 47,
	/**
	 * The reader supports HID Prox tags as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidProx = 48,
	/**
	 * The reader supports HID ioProx tags as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidIoProx = 49,
	/**
	 * The reader supports Indala cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Indala = 50,
	/**
	 * The reader supports Keri Systems cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Keri = 51,
	/**
	 * The reader supports Indala FlexSecur cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_IndalaSecure = 52,
	/**
	 * The reader supports QuadraKey cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Quadrakey = 53,
	/**
	 * The reader supports SecuraKey cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_SecuraKey = 54,
	/**
	 * The reader supports G-Prox cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_GProx = 55,
	/**
	 * The reader supports Hitag 1 and Hitag S cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Hitag1S = 56,
	/**
	 * The reader supports Hitag 2 Manchester cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Hitag2M = 57,
	/**
	 * The reader supports Hitag 2 Biphase cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Hitag2B = 58,
	/**
	 * The reader has a blue LED.
	 */
	brp_FeatureID_BlueLed = 59,
	/**
	 * The reader supports Cotag cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_Cotag = 60,
	/**
	 * The reader can read the UID of a PicoPass card.
	 * 
	 * **If _Picopass_ is listed as well, that feature scope applies.**
	 */
	brp_FeatureID_PicopassUidOnly = 61,
	/**
	 * The reader supports IDTECK cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_IdTeck = 62,
	/**
	 * The reader has a tamper alarm.
	 */
	brp_FeatureID_Tamper = 63,
	/**
	 * The hardware limits the HF baud rate to 106 kbps.
	 * 
	 * **This applies to LEGIC readers only.**
	 */
	brp_FeatureID_MaxHfBaudrate106kbps = 64,
	/**
	 * The hardware limits the HF baud rate to 212 kbps.
	 * 
	 * **This applies to LEGIC readers only.**
	 */
	brp_FeatureID_MaxHfBaudrate212kbps = 65,
	/**
	 * The hardware limits the HF baud rate to 424 kbps.
	 * 
	 * **This applies to LEGIC readers only.**
	 */
	brp_FeatureID_MaxHfBaudrate424kbps = 66,
	/**
	 * Due to an aborted upload, the firmware on the reader is incomplete and not
	 * fully functional.
	 * 
	 * **Repeat the firmware upload.**
	 */
	brp_FeatureID_FirmwareLoader = 67,
	/**
	 * The firmware can be updated via a serial interface (UART/RS-232/virtual COM
	 * port).
	 */
	brp_FeatureID_FwUploadViaBrpOverSer = 68,
	/**
	 * The reader supports AES-encrypted communication with the host.
	 */
	brp_FeatureID_AesHostProtocolEncryption = 69,
	/**
	 * The reader supports PKI-encrypted communication with the host.
	 */
	brp_FeatureID_PkiHostProtocolEncryption = 70,
	/**
	 * The reader supports HID iCLASS cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidIClass = 71,
	/**
	 * The reader supports HID iCLASS SR cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidIClassSr = 72,
	/**
	 * The reader supports HID iCLASS SE and Seos cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_HidIClassSeAndSeos = 73,
	/**
	 * The reader supports Mifare Ultralight cards as documented The reader supports
	 * Mifare Ultralight cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifareUltralight = 74,
	/**
	 * The reader supports the emulation of ISO14443-4 compatible cards.
	 */
	brp_FeatureID_CardEmulationISO14443L4 = 75,
	/**
	 * The reader supports MIFARE DESFire EV2 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifareDESFireEv2 = 76,
	/**
	 * The reader supports MIFARE Plus EV1 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifarePlusEv1 = 77,
	/**
	 * A SAM AV3 card is inserted.
	 */
	brp_FeatureID_SamAv3 = 78,
	/**
	 * The reader supports OSDP specification version 2.17.
	 */
	brp_FeatureID_OsdpV217 = 79,
	/**
	 * The reader supports Bluetooth Low Energy (BLE).
	 */
	brp_FeatureID_Bluetooth = 80,
	/**
	 * The reader has an RGB LED that is fully [
	 * customizable](https://docs.baltech.de/project-setup/customize-
	 * led.html#customization-options-supported-reader-types).
	 */
	brp_FeatureID_RgbLed = 81,
	/**
	 * The reader has an RGB LED that is [
	 * customizable](https://docs.baltech.de/project-setup/customize-
	 * led.html#customization-options-supported-reader-types) to a limited extend.
	 */
	brp_FeatureID_RgbLedLimited = 82,
	/**
	 * The reader supports firmware/configuration upload via BEC2 files.
	 */
	brp_FeatureID_Bec2Upload = 83,
	/**
	 * The reader supports MIFARE DESFire EV3 cards as documented
	 * [here](https://docs.baltech.de/developers/supported-card-types.html).
	 */
	brp_FeatureID_MifareDESFireEv3 = 84,
	brp_FeatureID_undefined = -1
} brp_FeatureID;
/**
 * @anchor Parity
 * Specifies the Parity-bit mode which is used for UART protocols.
 */
typedef enum {
	/**
	 * No Parity is used
	 */
	brp_Parity_None_ = 78,
	/**
	 * Parity is used. The Parity bit is set if number of set bits is even.
	 */
	brp_Parity_Even = 69,
	/**
	 * Parity is used. The Parity bit is set if number of set bits is odd.
	 */
	brp_Parity_Odd = 79,
	brp_Parity_undefined = -1
} brp_Parity;
/**
 * @anchor Baudrate
 * The Baudrate specifies the performance of an UART based interface in bits per
 * second.
 * 
 * **For the old-style 8bit format, which omits the least significant digit, this
 * format is not supported any more. Configurations using this format cannot be
 * opened.**
 */
typedef enum {
	/**
	 * 300 Baud
	 */
	brp_Baudrate_Baud300 = 3,
	/**
	 * 600 Baud
	 */
	brp_Baudrate_Baud600 = 6,
	/**
	 * 1200 Baud
	 */
	brp_Baudrate_Baud1200 = 12,
	/**
	 * 2400 Baud
	 */
	brp_Baudrate_Baud2400 = 24,
	/**
	 * 4800 Baud
	 */
	brp_Baudrate_Baud4800 = 48,
	/**
	 * 9600 Baud
	 */
	brp_Baudrate_Baud9600 = 96,
	/**
	 * 14400 Baud
	 */
	brp_Baudrate_Baud14400 = 144,
	/**
	 * 19200 Baud
	 */
	brp_Baudrate_Baud19200 = 192,
	/**
	 * 28800 Baud
	 */
	brp_Baudrate_Baud28800 = 288,
	/**
	 * 38400 Baud
	 */
	brp_Baudrate_Baud38400 = 384,
	/**
	 * 57600 Baud
	 */
	brp_Baudrate_Baud57600 = 576,
	/**
	 * 115200 Baud
	 */
	brp_Baudrate_Baud115200 = 1152,
	/**
	 * 500 kBaud
	 */
	brp_Baudrate_Baud500000 = 5000,
	/**
	 * 576 kBaud
	 */
	brp_Baudrate_Baud576000 = 5760,
	/**
	 * 921 kBaud
	 */
	brp_Baudrate_Baud921600 = 9216,
	brp_Baudrate_undefined = -1
} brp_Baudrate;
/**
 * @anchor IoPort
 * I/O pins of the reader that can be controlled by the user.
 */
typedef enum {
	/**
	 * Enable/disable/toggle the green LED (if available).
	 */
	brp_IoPort_GreenLed = 0,
	/**
	 * Enable/disable/toggle the red LED (if available).
	 */
	brp_IoPort_RedLed = 1,
	/**
	 * Enable/disable/toggle the beeper (if available).
	 */
	brp_IoPort_Beeper = 2,
	/**
	 * Enable/disable/toggle the relay (if available).
	 */
	brp_IoPort_Relay = 3,
	/**
	 * Retrieve the state of the custom input 0.
	 */
	brp_IoPort_Input0 = 4,
	/**
	 * Retrieve the state of the custom input 1.
	 */
	brp_IoPort_Input1 = 5,
	/**
	 * Enable/disable/toggle the blue LED (if available).
	 */
	brp_IoPort_BlueLed = 6,
	/**
	 * Retrieve the state of the tamper alarm.
	 */
	brp_IoPort_TamperAlarm = 7,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio0 = 8,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio1 = 9,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio2 = 10,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio3 = 11,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio4 = 12,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio5 = 13,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio6 = 14,
	/**
	 * Refers to a general purpose I/O. The physical pin assigned to this logical I/O
	 * port depends on the physical setup of the device.
	 */
	brp_IoPort_Gpio7 = 15,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled0 = 64,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled1 = 65,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled2 = 66,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled3 = 67,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled4 = 68,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled5 = 69,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled6 = 70,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled7 = 71,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled8 = 72,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled9 = 73,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled10 = 74,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled11 = 75,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled12 = 76,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled13 = 77,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled14 = 78,
	/**
	 * Custom Virtual LED (VLED) port. Allows RGB LEDs to be activated with a user-
	 * defined color.
	 */
	brp_IoPort_CustomVled15 = 79,
	brp_IoPort_undefined = -1
} brp_IoPort;
/**
 * @anchor RunSequenceCmd
 * 
 */
typedef struct {
	/**
	 * 
	 */
	brp_RunSequenceCmd_CmdCode CmdCode;
	/**
	 * The number of repetitions of the code block between the matching _tLoop_ this
	 * _atLoop_ mand. If this number is 2 the interpreter jumps back to _tLoop_
	 * exactly one time (which results in summary in to repetitions).
	 */
	unsigned RepeatCnt;
	/**
	 * This field represents a time (either in milliseconds or seconds). The UI-
	 * sequence interpreter will delay the amount of (milli-)seconds before going on.
	 */
	unsigned Param;
	/**
	 * I/O pins of the reader that can be controlled by the user.
	 */
	brp_IoPort SwitchIoPort;
} brp_RunSequenceCmd;
/**
 * @anchor FireEventAtPowerup
 * In Autoread mode this values are specifing the states that shall be assumed
 * for input ports before reading them the first time. If the first read results
 * in a different state than specified here, an event will be fired.
 */
typedef enum {
	/**
	 * Do never fire the corresponding event (no matter what the corresponding input
	 * port's state is)
	 */
	brp_FireEventAtPowerup_Never = 0,
	/**
	 * Fire the corresponding "OnClearXxxx" event if the corresponding input port's
	 * state is cleared.
	 */
	brp_FireEventAtPowerup_IfClear = 1,
	/**
	 * Fire the corresponding "OnSetXxxx" event if the corresponding input port's
	 * state is set.
	 */
	brp_FireEventAtPowerup_IfSet = 2,
	/**
	 * Fire the corresponding event always (no matter what the corresponding input
	 * port's state is)
	 */
	brp_FireEventAtPowerup_Always = 3,
	brp_FireEventAtPowerup_undefined = -1
} brp_FireEventAtPowerup;
/**
 * @anchor CardType
 * 
 */
typedef enum {
	/**
	 * See description above
	 */
	brp_CardType_Default = 0,
	/**
	 * MIFARE Classic (1k and 4k variants)
	 */
	brp_CardType_MifareClassic = 16,
	/**
	 * Generic ISO 14443-4 Type A without ISO 7816-4 support
	 */
	brp_CardType_Iso14443aGeneric = 17,
	/**
	 * ISO 14443-4 Type A compliant with ISO7816-4 and MIFARE L3
	 */
	brp_CardType_Iso14443aInterIndustry = 18,
	/**
	 * MIFARE Ultralight
	 */
	brp_CardType_MifareUltraLight = 19,
	/**
	 * MIFARE DESFire (2k, 4k, and 8k variants)
	 */
	brp_CardType_MifareDesfire = 20,
	/**
	 * Infineon my-d proximity (SLE55)
	 */
	brp_CardType_InfineonSle55 = 21,
	/**
	 * ISO 14443 Type A (NXP SmartMX/inter-industry)
	 */
	brp_CardType_Iso14443aIntIndustryMif = 22,
	/**
	 * MIFARE Plus L2 (2k and 4k variants)
	 */
	brp_CardType_MifarePlusL2 = 23,
	/**
	 * LEGIC advant ISO 14443 Type A
	 */
	brp_CardType_LEGICAdvantIso14443a = 24,
	/**
	 * MIFARE Plus L3
	 */
	brp_CardType_MifarePlusL3 = 25,
	/**
	 * LEGIC prime; this is a legacy value - it has been replaced by _LEGICPrime_.
	 */
	brp_CardType_LEGICPrimeLegacy = 32,
	/**
	 * LEGIC advant (ISO 14443 Type A/ISO 15693); this is a legacy value - it has
	 * been replaced by _LEGICAdvantIso14443a_ and _LEGICAdvantIso15693_.
	 */
	brp_CardType_LEGICAdvantLegacy = 33,
	/**
	 * ISO-15693-compliant label
	 */
	brp_CardType_Iso15693 = 48,
	/**
	 * LEGIC advant ISO 15693
	 */
	brp_CardType_LEGICAdvantIso15693 = 50,
	/**
	 * ISO 14443-4 Type B without ISO 7816-4 support
	 */
	brp_CardType_Iso14443bUnknown = 64,
	/**
	 * ISO 14443-4 Type B with ISO 7816-4 support
	 */
	brp_CardType_Iso14443bIntIndustry = 65,
	/**
	 * iCLASS via standard-compliant ISO 14443 Type B protocol (Level 3 compatible)
	 */
	brp_CardType_IClassIso14B = 66,
	/**
	 * iCLASS via proprietary ISO 14443 Type B protocol derivate (Level 2 compatible)
	 */
	brp_CardType_IClassIso14B2 = 80,
	/**
	 * iCLASS via ISO 15693
	 */
	brp_CardType_IClass = 96,
	/**
	 * FeliCa
	 */
	brp_CardType_Felica = 112,
	/**
	 * EM 4205/EM 4305
	 */
	brp_CardType_EM4205 = 128,
	/**
	 * EM 4100/EM 4102
	 */
	brp_CardType_EM4100 = 129,
	/**
	 * EM 4450
	 */
	brp_CardType_EM4450 = 131,
	/**
	 * Farpointe Pyramid
	 */
	brp_CardType_Pyramid = 132,
	/**
	 * HID Prox32
	 */
	brp_CardType_HidProx32 = 133,
	/**
	 * Keri
	 */
	brp_CardType_Keri = 134,
	/**
	 * QuadraKey
	 */
	brp_CardType_Quadrakey = 135,
	/**
	 * HID Indala ASP
	 */
	brp_CardType_HidIndala = 136,
	/**
	 * AWID
	 */
	brp_CardType_HidAwid = 137,
	/**
	 * HID Proximity
	 */
	brp_CardType_HidProx = 138,
	/**
	 * ioProx
	 */
	brp_CardType_HidIoprox = 139,
	/**
	 * HITAG 1 or S
	 */
	brp_CardType_Hitag1S = 140,
	/**
	 * HITAG 2 Manchester
	 */
	brp_CardType_Hitag2M = 141,
	/**
	 * HITAG 2 Biphase
	 */
	brp_CardType_Hitag2B = 142,
	/**
	 * Low-level card type/programmable decoder
	 */
	brp_CardType_TTF = 143,
	/**
	 * ST SRIX
	 */
	brp_CardType_STSRIX = 144,
	/**
	 * SecuraKey
	 */
	brp_CardType_SecuraKey = 160,
	/**
	 * G-Prox
	 */
	brp_CardType_GProx = 161,
	/**
	 * HID Indala ASP+
	 */
	brp_CardType_HidIndalaSecure = 162,
	/**
	 * Cotag
	 */
	brp_CardType_Cotag = 163,
	/**
	 * IDTECK
	 */
	brp_CardType_Idteck = 164,
	/**
	 * Bluetooth MCE; Mobile Card Emulation over Bluetooth
	 */
	brp_CardType_BluetoothMce = 176,
	/**
	 * LEGIC prime
	 */
	brp_CardType_LEGICPrime = 192,
	/**
	 * Abstract card type for reading SIO Elements
	 */
	brp_CardType_HidSio = 224,
	brp_CardType_undefined = -1
} brp_CardType;
/**
 * @anchor CardFamilies
 * 
 */
typedef struct {
	/**
	 * 
	 */
	bool LEGICPrime;
	/**
	 * 
	 */
	bool BluetoothMce;
	/**
	 * Scans for the following 125kHz cards: SecuraKey, G-Prox, Indala ASP+, Cotag,
	 * Idteck. To scan only for a part of this list, set the configuration value
	 * __ScanCardTypesPart2__
	 * accordingly. To scan for other 125kHz card types, set the _Khz125Part1_ flag.
	 */
	bool Khz125Part2;
	/**
	 * 
	 */
	bool Srix;
	/**
	 * Scans for the following 125kHz cards: EM4205, EM4305, EM4100, EM4102, EM4450,
	 * Farpointe Pyramid, HID prox, HID ioProx, HID Prox32, Keri, Quadrakey, Indala,
	 * AWID, HITAG 1 and S, HITAG 2, TTF (Tag talks first). To scan only for a part
	 * of this list, set the configuration value
	 * __ScanCardTypesPart1__
	 * accordingly. To scan for other 125kHz card types, set the _Khz125Part2_ flag.
	 */
	bool Khz125Part1;
	/**
	 * 
	 */
	bool Felica;
	/**
	 * Scans for iCLASS and iCLASS SR cards.
	 * 
	 * **This flag does not include iCLASS SE or iCLASS Seos. To scan for these card
	 * types, set the _Iso14443A_ flag.**
	 */
	bool IClass;
	/**
	 * Can be used instead of _iCLASS_ to increase scanning speed. (Its transport
	 * layer protocol is based on the faster ISO 14443 Type B protocol instead of the
	 * ISO-15693-like protocol of _iCLASS_).
	 * 
	 * **Not all iCLASS cards support ISO 14443 Type B. Thus, we recommend you use
	 * the _iCLASS_ flag for maximum compatibility and the _IClassIso14B_ flag for
	 * maximum speed. When in doubt, please check the specification of the cards used
	 * in your project.**
	 */
	bool IClassIso14B;
	/**
	 * 
	 */
	bool Iso14443B;
	/**
	 * Scans for ISO-15693-compatible cards, e.g. EM4033, EM4035, NXP ICODE, or LEGIC
	 * advant ISO 15693.
	 */
	bool Iso15693;
	/**
	 * Scans for ISO 14443 Type A compatible cards, e.g. MIFARE Classic, MIFARE Plus,
	 * MIFARE DESFire, NXP SmartMX, or Legic advant ISO 14443.
	 */
	bool Iso14443A;
} brp_CardFamilies;
/**
 * @anchor DesfireFileDescription
 * 
 */
typedef struct {
	/**
	 * The DESFire file number to access
	 */
	unsigned FileNo;
	/**
	 * Communication settings that define if data is to be MAC'ed or encrypted before
	 * it's transmitted to the host system.
	 */
	brp_DesfireFileDescription_FileCommunicationSecurity FileCommunicationSecurity;
	/**
	 * Type of file to read
	 * 
	 * **Only Standard and Backup files are supported. There's no support for Cyclic,
	 * Record, or Value files.**
	 */
	brp_DesfireFileDescription_FileType FileType;
	/**
	 * _ReadKeyNo_ , i.e. the index of the read key within the DESFire application
	 * key table
	 * 
	 * **The value 14 allows unencrypted access.**
	 */
	unsigned ReadKeyNo;
	/**
	 * _WriteKeyNo_ , i.e. the index of the write key within the DESFire application
	 * key table
	 * 
	 * **The value 14 allows unencrypted access.**
	 */
	unsigned WriteKeyNo;
	/**
	 * Number of the first byte in the DESFire file to map into the VHL file.
	 */
	unsigned Offset;
	/**
	 * Length of byte sequence within the DESFire file to map into the VHL file.
	 */
	unsigned Length;
	/**
	 * Index of the read key on the reader
	 * 
	 *   1. 0x00-0x7F refer to an index in a SAM (key version has to be 0). 
	 *   2. 0x80-0xBF refer to an index in __Crypto Key__. 
	 *   3. 0xC0-0xCB refer to an index in __VhlCfg/File/DesfireKeyList__.
	 */
	unsigned ReadKeyIdx;
	/**
	 * Index of the write key on the reader  
	 * If omitted and _WriteKeyNo_ is equal to _ReadKeyNo_ , it defaults to
	 * _ReadKeyIdx_. Otherwise it defaults to _ReadKeyIdx_ \+ 1.
	 * 
	 *   1. 0x00-0x7F refer to an index in a SAM (key version has to be 0). 
	 *   2. 0x80-0xBF refer to an index in __Crypto Key__. 
	 *   3. 0xC0-0xCB refers to an index in __VhlCfg/File/DesfireKeyList__.
	 */
	unsigned WriteKeyIdx;
	/**
	 * **Only needed to run[ VHL.Format](@ref VHL_Format) .**
	 * 
	 * This byte is composed of a high nibble (_ReadWriteKeyNo_) and a low nibble
	 * (_ChangeKeyNo_). It corresponds to the low byte of the access rights (see
	 * DESFire spec 3.5; chapter 8.3) of the DESFire file. The high byte is composed
	 * implicitly of _ReadKeyNo_ and _WriteKeyNo_.
	 */
	unsigned AccessRightsLowByte;
	/**
	 * **Only needed to run[ VHL.Format](@ref VHL_Format) .**
	 * 
	 * Index of the key on the reader that is used to change a key when running
	 * _VHL.Format_. If ChangeKeyNo (see _AccessRightsLowByte_) is equal to
	 * _WriteKeyNo_ , this value defaults to _WriteKeyIdx_. Otherwise, it defaults to
	 * _WriteKeyIdx_ \+ 1.
	 * 
	 *   1. 0x00-0x7F refer to an index in a SAM (key version has to be 0). 
	 *   2. 0x80-0xBF refer to an index in __Crypto Key__. 
	 *   3. 0xC0-0xCB refer to an index in __VhlCfg/File/DesfireKeyList__.
	 */
	unsigned ChangeKeyIdx;
	/**
	 * **Only needed to run[ VHL.Format](@ref VHL_Format) .**
	 * 
	 * The size of the DESfire file. It's usually _Offset_ \+ _Len_.
	 */
	unsigned FileSize;
	/**
	 * **Only needed to run[ VHL.Format](@ref VHL_Format) .**
	 * 
	 * ISO file identifier (ISO FID). If the card already contains a DESFire file
	 * with the same ISO FID, the existing file will be replaced. If this value is
	 * not specified (or 0x3F00), no ISO FID will be used.
	 */
	unsigned IsoFid;
} brp_DesfireFileDescription;
/**
 * @anchor AuthReqUpload
 * Specifies the authentication level the BEC/BEC2/BF3 file or ConfigCard has to
 * fulfill to be accepted.
 */
typedef enum {
	/**
	 * Default settings (Actual behavior is usage-dependent).
	 */
	brp_AuthReqUpload_Default = 0,
	/**
	 * Accept any kind of BEC/BEC2/BF3 files or ConfigCards, even unencrypted ones.
	 */
	brp_AuthReqUpload_None_ = 1,
	/**
	 * Accept only BEC/BEC2/BF3 files or ConfigCards that are encrypted with a
	 * matching __customer key__. Especially
	 * deny unencrypted files/ConfigCards.
	 */
	brp_AuthReqUpload_CustomerKey = 2,
	/**
	 * The __customer key__ _and_ the __Config
	 * Security Code__ have to match
	 * for this BEC/BEC2/BF3 file or ConfigCard to be accepted.
	 */
	brp_AuthReqUpload_ConfigSecurityCode = 3,
	/**
	 * The __customer key__ _and_ the __Config
	 * Security Code__ have to match
	 * for this BEC/BEC2/BF3 file or ConfigCard to be accepted. Furthermore, the
	 * version stored in the file/ConfigCard header has to be greater than or equal
	 * to the __RFID interface component
	 * version__.
	 */
	brp_AuthReqUpload_Version = 4,
	/**
	 * The __customer key__ _and_ the __Config
	 * Security Code__ have to match
	 * for this BEC/BEC2/BF3 file or ConfigCard to be accepted. Furthermore, the
	 * version stored in the file/ConfigCard header has to be greater than the __RFID
	 * interface component
	 * version__.
	 */
	brp_AuthReqUpload_GreaterVersion = 5,
	brp_AuthReqUpload_undefined = -1
} brp_AuthReqUpload;
/**
 * @anchor AutoReadMode
 * 
 */
typedef enum {
	/**
	 * Do not run Autoread at all.
	 */
	brp_AutoReadMode_Disabled = 0,
	/**
	 * The reader will boot in Autoread mode and scan for cards, no matter if its
	 * configuration contains an Autoread RFID interface component or not.
	 * 
	 * If there is an Autoread RFID interface component, the reader will check if a
	 * card is valid and buffer its card identification, so you can retrieve it using
	 * [AR.GetMessage](@ref AR_GetMessage). Then, the reader will
	 * continue scanning for other cards. If another card is detected before the last
	 * card identification has been retrieved by the host, the last card
	 * identifications will be queued in a last-in-first-out queue.
	 * 
	 * If there is no Autoread RFID interface component, project cards won't be read;
	 * however, the reader will still do the following:
	 * 
	 *   * Scan and accept ConfigCards. This means the reader can be reconfigured even if the connection to the host is interrupted.
	 *   * Fire __Baltech Script events__
	 */
	brp_AutoReadMode_Enabled = 1,
	/**
	 * Same as _Enabled_ ; however, the reader will stop Autoread mode as soon as it
	 * has detected (and read) a card. You can now interact with the card using [VHL
	 * commands](../cmds/vhl.xml). When you're done, reenable Autoread by running
	 * [AR.SetMode](@ref AR_SetMode) again.
	 */
	brp_AutoReadMode_EnableOnce = 2,
	/**
	 * The reader will boot in Autoread mode only if its configuration contains at
	 * least 1 Autoread RFID interface component, i.e. if the configuration value
	 * [Autoread/Rule[0]/Template](../cfg/autoread.xml#Autoread.Rule.Template) is
	 * defined. Then the behavior is the same as _Enabled_.
	 */
	brp_AutoReadMode_EnableIfDefinedRules = 255,
	brp_AutoReadMode_undefined = -1
} brp_AutoReadMode;
/**
 * @anchor HostSecurityAccessConditionBits
 * Every Feature in this list can be disabled by not setting the corresponding
 * bit.
 */
typedef struct {
	/**
	 * Provide Access to Ethernet BRP Commands
	 */
	bool EthernetAccess;
	/**
	 * Has to be cleared to deny control autoread task
	 */
	bool AutoreadAccess;
	/**
	 * Has to be cleared to deny allow access to the encryption unit
	 */
	bool CryptoAccess;
	/**
	 * Has to be cleared to deny allow to upload firmware
	 */
	bool Bf2Upload;
	/**
	 * Has to be cleared to deny allow access to the extended reader partition
	 */
	bool ExtendedAccess;
	/**
	 * Has to be cleared to deny write access to flash file system
	 */
	bool FlashFileSystemWrite;
	/**
	 * Has to be cleared to deny read access to flash file system
	 */
	bool FlashFileSystemRead;
	/**
	 * Has to be cleared to deny write access to RTC
	 */
	bool RtcWrite;
	/**
	 * Has to be cleared to deny running VHL APDU Exchange
	 */
	bool VhlExchangeapdu;
	/**
	 * Has to be cleared to deny formattings cards via VHL
	 */
	bool VhlFormat;
	/**
	 * Has to be cleared to deny writing cards via VHL
	 */
	bool VhlWrite;
	/**
	 * Has to be cleared to deny reading cards via VHL
	 */
	bool VhlRead;
	/**
	 * Has to be cleared to deny detection of cards via VHL
	 */
	bool VhlSelect;
	/**
	 * Has to be cleared to deny access to SAM over 7816-3 commands ( [Iso78 command
	 * group](@ref Iso78))
	 */
	bool ExtSamAccess;
	/**
	 * Has to be cleared to deny allow to access HF via low level commands
	 */
	bool HfLowlevelAccess;
	/**
	 * Has to be cleared to deny access to keypad/lcd
	 */
	bool GuiAccess;
	/**
	 * Has to be cleared to deny write access to io ports
	 */
	bool IoPortWrite;
	/**
	 * Has to be cleared to deny read access to io ports
	 */
	bool IoPortRead;
	/**
	 * Has to be cleared to deny reset configuration keys/while configuration.
	 */
	bool ConfigReset;
	/**
	 * Has to be cleared to deny write access to configuration keys/values.
	 */
	bool ConfigWrite;
	/**
	 * Has to be cleared to deny read access to configuration keys/values
	 */
	bool ConfigRead;
	/**
	 * Has to be cleared to deny allow reboot/powerdown of system
	 */
	bool SysReset;
	/**
	 * Has to be cleared to deny set ac 2
	 */
	bool SetAccessConditionMask2;
	/**
	 * Has to be cleared to deny set ac 1
	 */
	bool SetAccessConditionMask1;
	/**
	 * Has to be cleared to deny set ac 0
	 */
	bool SetAccessConditionMask0;
	/**
	 * Has to be cleared to deny set security key 3
	 */
	bool SetKey3;
	/**
	 * Has to be cleared to deny set security key 2
	 */
	bool SetKey2;
	/**
	 * Has to be cleared to deny set security key 1
	 */
	bool SetKey1;
	/**
	 * Has to be cleared to deny resetting system to factory settings
	 */
	bool FactoryReset;
} brp_HostSecurityAccessConditionBits;
/**
 * @anchor HostSecurityAuthenticationMode
 * Specifies a minimum of security requirements, when working in this security
 * level
 */
typedef struct {
	/**
	 * Initialvector of CBC encryption is not reset between commands. This prevents
	 * replay attacks during a single session but makes the connection more sensible
	 * to communication errors.
	 */
	bool RequireContinuousIv;
	/**
	 * Commands are transferred encrypted. No man in the middle can read the data
	 */
	bool RequireEncrypted;
	/**
	 * A Cryptographic Signature is attached to every command. No man in the middle
	 * can inject its own commands
	 */
	bool RequireMac;
	/**
	 * 3-pass authentication and sessionkey generation
	 */
	bool RequireSessionKey;
} brp_HostSecurityAuthenticationMode;
/**
 * @anchor FirmwareVersion
 * 
 */
typedef struct {
	/**
	 * BCD number that specifies a firmware ID
	 */
	unsigned FirmwareID;
	/**
	 * Binary that specifies the major number of the smallest blocked fw version
	 */
	unsigned SmallestBlockedFwVersionMajor;
	/**
	 * Binary that specifies the minor number of the smallest blocked fw version
	 */
	unsigned SmallestBlockedFwVersionMinor;
	/**
	 * Binary that specifies the build number of the smallest blocked fw version
	 */
	unsigned SmallestBlockedFwVersionBuild;
	/**
	 * Binary that specifies the major number of the greatest non-blocked fw version
	 */
	unsigned GreatestBlockedFwVersionMajor;
	/**
	 * Binary that specifies the minor number of the greatest non-blocked fw version
	 */
	unsigned GreatestBlockedFwVersionMinor;
	/**
	 * Binary that specifies the build number of the greatest non-blocked fw version
	 */
	unsigned GreatestBlockedFwVersionBuild;
} brp_FirmwareVersion;
/**
 * @anchor VirtualLedDefinition
 * 
 */
typedef struct {
	/**
	 * This byte is required to enable additional fields for the characterization of
	 * the desired LED behavior.
	 */
	brp_VirtualLedDefinition_Mode Mode;
	/**
	 * This is the color of the VLED port in the RGB color space (0x00RRGGBB). In
	 * case of a pulse signal, this is the first color value.
	 */
	unsigned RgbColor;
	/**
	 * This field defines which physical LEDs are to be activated when the
	 * corresponding VLED port is enabled.
	 */
	brp_VirtualLedDefinition_PhysicalLedSelection PhysicalLedSelection;
	/**
	 * This field is only available in case of a pulse signal. It defines the second
	 * RGB color of the pulse.
	 */
	unsigned RgbColor2;
	/**
	 * This field defines the transition time which is applied whenever this virtual
	 * LED is enabled. This value overrides the __default transition
	 * time__.
	 */
	unsigned TransitionTime;
} brp_VirtualLedDefinition;
/**
 * @anchor LicenseBitMask
 * License bit mask
 */
typedef struct {
	/**
	 * BLE license
	 * 
	 * Reader is licensed to operate with Bluetooth.
	 * 
	 * **This license is only applicable to readers supporting Bluetooth.**
	 */
	bool Ble;
	/**
	 * BLE license required
	 * 
	 * Reader requires a valid BLE license to operate with Bluetooth. If not set,
	 * Bluetooth can be used without a BLE license, provided that the reader hardware
	 * supports Bluetooth.
	 */
	bool BleLicRequired;
	/**
	 * SE [Prox license](https://docs.baltech.de/project-setup/get-prox-license-for-
	 * hid-prox-indala-keri.html#what-license-types-are-available):
	 * 
	 * Reader is licensed to read HID Prox, Indala, and Keri project cards if an _HID
	 * SE processor is inserted_  
	 * (also known as "iClass SAM").
	 * 
	 * **This license is only applicable to 125 kHz readers.**
	 */
	bool HidOnlyForSE;
	/**
	 * Standard [Prox license](https://docs.baltech.de/project-setup/get-prox-
	 * license-for-hid-prox-indala-keri.html#what-license-types-are-available):
	 * 
	 * Reader is licensed to read HID Prox, Indala, and Keri project cards.
	 * 
	 * **This license is only applicable to 125 kHz readers.**
	 */
	bool Hid;
} brp_LicenseBitMask;
#endif
/**
 * @}
 */
