#include "typedefs.h"
bool brp_AutoRunCommand_RunMode_is_valid(int val) {
	switch (val) {
		case 0: /* Standard*/
		case 1: /* Continuous*/
		case 2: /* Repeat*/
			return true;
		default:
			return false;
	}
}
bool brp_KeyAccessRights_DiversificationMode_is_valid(int val) {
	switch (val) {
		case 0: /* NoDiversification*/
		case 2: /* ModeAv2*/
			return true;
		default:
			return false;
	}
}
bool brp_RunSequenceCmd_CmdCode_is_valid(int val) {
	switch (val) {
		case 1: /* EnablePort*/
		case 2: /* DisablePort*/
		case 5: /* RepeatLoop*/
		case 8: /* WaitMs*/
		case 9: /* WaitSec*/
		case 16: /* EnablePortGreenLed*/
		case 17: /* EnablePortRedLed*/
		case 18: /* EnablePortBeeper*/
		case 19: /* EnablePortRelay*/
		case 22: /* EnablePortBlue*/
		case 32: /* DisablePortGreenLed*/
		case 33: /* DisablePortRedLed*/
		case 34: /* DisablePortBeeper*/
		case 35: /* DisablePortRelay*/
		case 38: /* DisablePortBlue*/
		case 48: /* InvertPortGreenLed*/
		case 49: /* InvertPortRedLed*/
		case 50: /* InvertPortBeeper*/
		case 51: /* InvertPortRelay*/
		case 54: /* InvertPortBlue*/
		case 81: /* Repeat1Times*/
		case 82: /* RepeatLoop2Times*/
		case 83: /* RepeatLoop3Times*/
		case 84: /* RepeatLoop4Times*/
		case 85: /* RepeatLoop5Times*/
		case 86: /* RepeatLoop6Times*/
		case 87: /* RepeatLoop7Times*/
		case 88: /* RepeatLoop8Times*/
		case 89: /* RepeatLoop9Times*/
		case 90: /* RepeatLoop10Times*/
		case 91: /* RepeatLoop11Times*/
		case 92: /* RepeatLoop12Times*/
		case 93: /* RepeatLoop13Times*/
		case 94: /* RepeatLoop14Times*/
		case 95: /* RepeatLoop15Times*/
		case 129: /* Wait100Ms*/
		case 130: /* Wait200Ms*/
		case 131: /* Wait300Ms*/
		case 132: /* Wait400Ms*/
		case 133: /* Wait500Ms*/
		case 134: /* Wait600Ms*/
		case 135: /* Wait700Ms*/
		case 136: /* Wait800Ms*/
		case 137: /* Wait900Ms*/
		case 138: /* Wait1000Ms*/
		case 139: /* Wait1100Ms*/
		case 140: /* Wait1200Ms*/
		case 141: /* Wait1300Ms*/
		case 142: /* Wait1400Ms*/
		case 143: /* Wait1500Ms*/
		case 144: /* Wait1600Ms*/
		case 145: /* Wait1700Ms*/
		case 146: /* Wait1800Ms*/
		case 147: /* Wait1900Ms*/
		case 148: /* Wait2000Ms*/
		case 149: /* Wait2100Ms*/
		case 150: /* Wait2200Ms*/
		case 151: /* Wait2300Ms*/
		case 152: /* Wait2400Ms*/
		case 153: /* Wait2500Ms*/
		case 154: /* Wait2600Ms*/
		case 155: /* Wait2700Ms*/
		case 156: /* Wait2800Ms*/
		case 157: /* Wait2900Ms*/
		case 158: /* Wait3000Ms*/
		case 159: /* Wait3100Ms*/
		case 160: /* Wait3200Ms*/
		case 161: /* Wait3300Ms*/
		case 162: /* Wait3400Ms*/
		case 163: /* Wait3500Ms*/
		case 164: /* Wait3600Ms*/
		case 165: /* Wait3700Ms*/
		case 166: /* Wait3800Ms*/
		case 167: /* Wait3900Ms*/
		case 168: /* Wait4000Ms*/
		case 169: /* Wait4100Ms*/
		case 170: /* Wait4200Ms*/
		case 171: /* Wait4300Ms*/
		case 172: /* Wait4400Ms*/
		case 173: /* Wait4500Ms*/
		case 174: /* Wait4600Ms*/
		case 175: /* Wait4700Ms*/
		case 176: /* Wait4800Ms*/
		case 177: /* Wait4900Ms*/
		case 178: /* Wait5000Ms*/
		case 179: /* Wait5100Ms*/
		case 180: /* Wait5200Ms*/
		case 181: /* Wait5300Ms*/
		case 182: /* Wait5400Ms*/
		case 183: /* Wait5500Ms*/
		case 184: /* Wait5600Ms*/
		case 185: /* Wait5700Ms*/
		case 186: /* Wait5800Ms*/
		case 187: /* Wait5900Ms*/
		case 188: /* Wait6000Ms*/
		case 189: /* Wait6100Ms*/
		case 190: /* Wait6200Ms*/
		case 191: /* Wait6300Ms*/
		case 241: /* EndOfSequence*/
		case 242: /* StartLoop*/
		case 243: /* OnStop*/
			return true;
		default:
			return false;
	}
}
bool brp_DesfireFileDescription_FileCommunicationSecurity_is_valid(int val) {
	switch (val) {
		case 0: /* Plain*/
		case 1: /* Mac*/
		case 3: /* Encrypted*/
			return true;
		default:
			return false;
	}
}
bool brp_DesfireFileDescription_FileType_is_valid(int val) {
	switch (val) {
		case 0: /* Standard*/
		case 1: /* Backup*/
		case 2: /* BackupManualCommit*/
			return true;
		default:
			return false;
	}
}
bool brp_VirtualLedDefinition_PhysicalLedSelection_is_valid(int val) {
	switch (val) {
		case 1: /* Right*/
		case 2: /* Left*/
		case 3: /* All*/
			return true;
		default:
			return false;
	}
}
bool brp_BlePeriph_GetEvents_EventId_is_valid(int val) {
	switch (val) {
		case 1: /* Connect*/
		case 2: /* Disconnect*/
		case 3: /* Write*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_ExecCommand_CryptoMode_is_valid(int val) {
	switch (val) {
		case 0: /* Plain*/
		case 1: /* MAC*/
		case 3: /* Encrypted*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_Authenticate_SecureMessaging_is_valid(int val) {
	switch (val) {
		case 0: /* EV1*/
		case 1: /* Native*/
		case 2: /* EV2*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_Authenticate_KeyDivMode_is_valid(int val) {
	switch (val) {
		case 0: /* NoDiv*/
		case 1: /* SamAV1OneRound*/
		case 2: /* SamAV1TwoRounds*/
		case 3: /* SamAV2*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_AuthExtKey_SecureMessaging_is_valid(int val) {
	switch (val) {
		case 0: /* EV1*/
		case 1: /* Native*/
		case 2: /* EV2*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_AuthExtKey_CryptoMode_is_valid(int val) {
	switch (val) {
		case 1: /* DES*/
		case 2: /* TripleDES*/
		case 3: /* ThreeKeyTripleDES*/
		case 4: /* AES*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_ReadData_Mode_is_valid(int val) {
	switch (val) {
		case 0: /* Plain*/
		case 1: /* MAC*/
		case 3: /* Encrypted*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_WriteData_Mode_is_valid(int val) {
	switch (val) {
		case 0: /* Plain*/
		case 1: /* MAC*/
		case 3: /* Encrypted*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_ChangeExtKey_MasterKeyType_is_valid(int val) {
	switch (val) {
		case 0: /* DESorTripleDES*/
		case 1: /* ThreeKeyTripleDES*/
		case 2: /* AES*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_ChangeKey_NewKeyDivMode_is_valid(int val) {
	switch (val) {
		case 0: /* SamAv1OneRound*/
		case 1: /* SamAv1TwoRounds*/
		case 2: /* SamAv2*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_ChangeKey_CurKeyDivMode_is_valid(int val) {
	switch (val) {
		case 0: /* SamAv1OneRound*/
		case 1: /* SamAv1TwoRounds*/
		case 2: /* SamAv2*/
			return true;
		default:
			return false;
	}
}
bool brp_Desfire_SetFraming_CommMode_is_valid(int val) {
	switch (val) {
		case 1: /* DESFireNative*/
		case 2: /* ISO7816Compatible*/
			return true;
		default:
			return false;
	}
}
bool brp_EM_DecodeCfg_RxMod_is_valid(int val) {
	switch (val) {
		case 0: /* Unknown*/
		case 16: /* Manchester*/
		case 32: /* Biphase*/
		case 48: /* NRZ*/
			return true;
		default:
			return false;
	}
}
bool brp_Eth_GetTcpConnectionStatus_Status_is_valid(int val) {
	switch (val) {
		case 0: /* NotConnected*/
		case 1: /* ConnectionTrialRunning*/
		case 2: /* Connected*/
			return true;
		default:
			return false;
	}
}
bool brp_Eth_OpenTcpConnection_ConnectionReason_is_valid(int val) {
	switch (val) {
		case 1: /* Powerup*/
		case 2: /* LinkChange*/
		case 4: /* SessionkeyTimeout*/
		case 8: /* Message*/
		case 16: /* UdpIntrospection*/
		case 32: /* Reset*/
		case 32768: /* FailedConnectionTrials*/
			return true;
		default:
			return false;
	}
}
bool brp_Felica_GenericCmd_FastBaud_is_valid(int val) {
	switch (val) {
		case 0: /* Kbps212*/
		case 1: /* Kbps424*/
			return true;
		default:
			return false;
	}
}
bool brp_Felica_Request_FastBaud_is_valid(int val) {
	switch (val) {
		case 0: /* Kbps212*/
		case 1: /* Kbps424*/
			return true;
		default:
			return false;
	}
}
bool brp_Hitag_Request_TagType_is_valid(int val) {
	switch (val) {
		case 0: /* HitagS*/
		case 1: /* Hitag1*/
		case 2: /* Hitag2Manchester*/
		case 3: /* Hitag2Biphase*/
			return true;
		default:
			return false;
	}
}
bool brp_Hitag_Request_Mode_is_valid(int val) {
	switch (val) {
		case 0: /* StdHtg12S*/
		case 1: /* AdvHtg1S*/
		case 2: /* FAdvHS*/
			return true;
		default:
			return false;
	}
}
bool brp_Hitag_Select_SelMode_is_valid(int val) {
	switch (val) {
		case 0: /* Select*/
		case 1: /* Quiet*/
		case 2: /* AuthPwd*/
		case 3: /* H2AuthOnlyPwd*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14a_RequestLegacy_UIDSize_is_valid(int val) {
	switch (val) {
		case 0: /* SingleSize*/
		case 1: /* DoubleSize*/
		case 2: /* TripleSize*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14a_RequestATS_FSDI_is_valid(int val) {
	switch (val) {
		case 0: /* Bytes16*/
		case 1: /* Bytes24*/
		case 2: /* Bytes32*/
		case 3: /* Bytes40*/
		case 4: /* Bytes48*/
		case 5: /* Bytes64*/
		case 6: /* Bytes96*/
		case 7: /* Bytes128*/
		case 8: /* Bytes256*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Request_TimeSlots_is_valid(int val) {
	switch (val) {
		case 0: /* TimeSlots1*/
		case 1: /* TimeSlots2*/
		case 2: /* TimeSlots4*/
		case 3: /* TimeSlots8*/
		case 4: /* TimeSlots16*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Request_FSCI_is_valid(int val) {
	switch (val) {
		case 0: /* Bytes16*/
		case 1: /* Bytes24*/
		case 2: /* Bytes32*/
		case 3: /* Bytes40*/
		case 4: /* Bytes48*/
		case 5: /* Bytes64*/
		case 6: /* Bytes96*/
		case 7: /* Bytes128*/
		case 8: /* Bytes256*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Request_ProtType_is_valid(int val) {
	switch (val) {
		case 0: /* NoISO14443L4Support*/
		case 1: /* ISO14443L4Support*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Request_FWI_is_valid(int val) {
	switch (val) {
		case 0: /* Us302*/
		case 1: /* Us604*/
		case 2: /* Us1208*/
		case 3: /* Us2416*/
		case 4: /* Us4832*/
		case 5: /* Us9664*/
		case 6: /* Ms19*/
		case 7: /* Ms39*/
		case 8: /* Ms77*/
		case 9: /* Ms155*/
		case 10: /* Ms309*/
		case 11: /* Ms618*/
		case 12: /* Ms1237*/
		case 13: /* Ms2474*/
		case 14: /* Ms4948*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Attrib_TR0_is_valid(int val) {
	switch (val) {
		case 0: /* Numerator64*/
		case 1: /* Numerator48*/
		case 2: /* Numerator16*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Attrib_TR1_is_valid(int val) {
	switch (val) {
		case 0: /* Numerator80*/
		case 1: /* Numerator64*/
		case 2: /* Numerator16*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Attrib_EOF__is_valid(int val) {
	switch (val) {
		case 0: /* EOFrequired*/
		case 1: /* EOFoptional*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Attrib_SOF_is_valid(int val) {
	switch (val) {
		case 0: /* SOFrequired*/
		case 1: /* SOFoptional*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14b_Attrib_FSDI_is_valid(int val) {
	switch (val) {
		case 0: /* Bytes16*/
		case 1: /* Bytes24*/
		case 2: /* Bytes32*/
		case 3: /* Bytes40*/
		case 4: /* Bytes48*/
		case 5: /* Bytes64*/
		case 6: /* Bytes96*/
		case 7: /* Bytes128*/
		case 8: /* Bytes256*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14L4_SetupAPDU_FSCI_is_valid(int val) {
	switch (val) {
		case 0: /* Bytes16*/
		case 1: /* Bytes24*/
		case 2: /* Bytes32*/
		case 3: /* Bytes40*/
		case 4: /* Bytes48*/
		case 5: /* Bytes64*/
		case 6: /* Bytes96*/
		case 7: /* Bytes128*/
		case 8: /* Bytes256*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso14L4_SetupAPDU_FWI_is_valid(int val) {
	switch (val) {
		case 0: /* Us302*/
		case 1: /* Us604*/
		case 2: /* Us1208*/
		case 3: /* Us2416*/
		case 4: /* Us4832*/
		case 5: /* Us9664*/
		case 6: /* Ms19*/
		case 7: /* Ms39*/
		case 8: /* Ms77*/
		case 9: /* Ms155*/
		case 10: /* Ms309*/
		case 11: /* Ms618*/
		case 12: /* Ms1237*/
		case 13: /* Ms2474*/
		case 14: /* Ms4948*/
			return true;
		default:
			return false;
	}
}
bool brp_Iso78_OpenSam_LID_is_valid(int val) {
	switch (val) {
		case 0: /* AV2*/
		case 1: /* HID*/
		case 16: /* Gen1*/
		case 17: /* Gen2*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_Select_MediaType_is_valid(int val) {
	switch (val) {
		case 1: /* GAM*/
		case 2: /* SAM*/
		case 3: /* IAM*/
		case 4: /* IM*/
		case 5: /* NM*/
		case 6: /* XAM1*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_Select_EvStat_is_valid(int val) {
	switch (val) {
		case 0: /* OKNoEvent*/
		case 1: /* EEPROMFull*/
		case 2: /* StampToEEPROM*/
		case 3: /* SamOutOfHF*/
		case 4: /* NoStampOnSAM*/
		case 5: /* StampDeleted*/
		case 6: /* StampDeletionAborted*/
		case 7: /* StampAlreadyInEEPROM*/
		case 8: /* StampNotStoredToEEPROM*/
		case 9: /* NewStampExtended*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_Idle_PowOff_is_valid(int val) {
	switch (val) {
		case 0: /* On*/
		case 1: /* Off*/
		case 2: /* OffPowerReduced*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_GenSetRead_WriteExMode_is_valid(int val) {
	switch (val) {
		case 0: /* ArbitraryWriting*/
		case 1: /* DecrementOnly*/
		case 2: /* IncrementOnly*/
		case 3: /* InvalidMode*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_ReadSMStatus_MIMVersion_is_valid(int val) {
	switch (val) {
		case 0: /* MIM022*/
		case 2: /* MIM256*/
		case 3: /* MIM1024*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_SetPassword_PwdStat_is_valid(int val) {
	switch (val) {
		case 0: /* Deactivated*/
		case 1: /* Activated*/
		case 2: /* AlreadySet*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_Lock_PwdStat_is_valid(int val) {
	switch (val) {
		case 0: /* Activated*/
		case 1: /* Deactivated*/
			return true;
		default:
			return false;
	}
}
bool brp_Lg_Unlock_PwdStat_is_valid(int val) {
	switch (val) {
		case 0: /* Unlocked*/
		case 1: /* NotActivated*/
		case 2: /* AlreadyUnlocked*/
			return true;
		default:
			return false;
	}
}
bool brp_Main_Bf2Upload_ResultCode_is_valid(int val) {
	switch (val) {
		case 0: /* Success*/
		case 1: /* InvalidChecksum*/
		case 2: /* ProgrammingTimeout*/
		case 3: /* VerifyTimeout*/
		case 4: /* UnsupportedCodeType*/
		case 5: /* ProtocolError*/
		case 6: /* SecuredByConfigSecurityCode*/
			return true;
		default:
			return false;
	}
}
bool brp_Mce_Enable_Mode_is_valid(int val) {
	switch (val) {
		case 0: /* Disable*/
		case 1: /* Enable*/
			return true;
		default:
			return false;
	}
}
bool brp_Mif_SetFraming_CommMode_is_valid(int val) {
	switch (val) {
		case 1: /* MifareNative*/
		case 2: /* MifareISO*/
			return true;
		default:
			return false;
	}
}
bool brp_MobileId_Enable_Mode_is_valid(int val) {
	switch (val) {
		case 0: /* Disable*/
		case 1: /* Enable*/
			return true;
		default:
			return false;
	}
}
bool brp_Sys_CfgLoadFinish_FinalizeAction_is_valid(int val) {
	switch (val) {
		case 0: /* CancelCfgLoad*/
		case 1: /* FinalizeCfgLoadWithoutReboot*/
		case 2: /* FinalizeCfgLoadWithReboot*/
			return true;
		default:
			return false;
	}
}
bool brp_TTF_ReadByteStream_RxMod_is_valid(int val) {
	switch (val) {
		case 16: /* Manchester*/
		case 32: /* Biphase*/
		case 48: /* Ind*/
		case 80: /* HIDP*/
		case 96: /* PSK*/
		case 112: /* SMPL*/
			return true;
		default:
			return false;
	}
}
bool brp_EpcUid_EpcSetMode_Coding_is_valid(int val) {
	switch (val) {
		case 0: /* FM0*/
		case 1: /* Miller8*/
		case 2: /* Man2*/
		case 3: /* Man4*/
			return true;
		default:
			return false;
	}
}
bool brp_EpcUid_EpcSelect_MemBank_is_valid(int val) {
	switch (val) {
		case 1: /* EPC*/
		case 2: /* TID*/
		case 3: /* User*/
			return true;
		default:
			return false;
	}
}
bool brp_Ultralight_AuthE2_DivMode_is_valid(int val) {
	switch (val) {
		case 0: /* NoDiv*/
		case 1: /* SamAv1OneRound*/
		case 2: /* SamAv1TwoRounds*/
		case 3: /* SamAv2*/
			return true;
		default:
			return false;
	}
}
bool brp_Ultralight_AuthUser_CryptoMode_is_valid(int val) {
	switch (val) {
		case 0: /* TripleDES*/
		case 1: /* AES*/
			return true;
		default:
			return false;
	}
}
bool brp_UsbHost_SetupPipes_Type_is_valid(int val) {
	switch (val) {
		case 0: /* Control*/
		case 1: /* Interrupt*/
		case 2: /* Bulk*/
		case 3: /* Isochronous*/
			return true;
		default:
			return false;
	}
}
bool brp_UI_Toggle_Polarity_is_valid(int val) {
	switch (val) {
		case 0: /* Normal*/
		case 1: /* Inverted*/
			return true;
		default:
			return false;
	}
}
bool brp_VHL_Setup_AdrMode_is_valid(int val) {
	switch (val) {
		case 0: /* ProtocolHeader*/
		case 1: /* Advant*/
			return true;
		default:
			return false;
	}
}
bool brp_VHL_Setup_OptionFlag_is_valid(int val) {
	switch (val) {
		case 0: /* OptFlagZero*/
		case 1: /* OptFlagOne*/
		case 2: /* OptFlagAuto*/
			return true;
		default:
			return false;
	}
}
bool brp_VHL_Setup_FileSpecifier_is_valid(int val) {
	switch (val) {
		case 0: /* SelectByPath*/
		case 1: /* SelectByName*/
		case 2: /* SelectByAPDU*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_GetReaderChipType_ChipType_is_valid(int val) {
	switch (val) {
		case 1: /* RC500*/
		case 4: /* RC632*/
		case 5: /* RC663*/
		case 33: /* PN512*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_GetSamType_ChipType_is_valid(int val) {
	switch (val) {
		case 1: /* TDA8007C2*/
		case 2: /* TDA8007C3*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_HfAcquire_ModuleId_is_valid(int val) {
	switch (val) {
		case 0: /* No*/
		case 1: /* RC*/
		case 3: /* Legic*/
		case 17: /* PN*/
		case 19: /* LegicAdvant*/
		case 24: /* RC125*/
		case 26: /* PN2*/
		case 34: /* RC663*/
		case 36: /* HTRC110*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_AesWrapKey_WrappedKeyNr_is_valid(int val) {
	switch (val) {
		case 0: /* WrapNone*/
		case 1: /* WrapDHUK*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_AesEncrypt_WrappedKeyNr_is_valid(int val) {
	switch (val) {
		case 0: /* WrapNone*/
		case 1: /* WrapDHUK*/
			return true;
		default:
			return false;
	}
}
bool brp_DHWCtrl_AesDecrypt_WrappedKeyNr_is_valid(int val) {
	switch (val) {
		case 0: /* WrapNone*/
		case 1: /* WrapDHUK*/
			return true;
		default:
			return false;
	}
}
bool brp_FileType_is_valid(int val) {
	switch (val) {
		case 0: /* FileByDfName*/
		case 1: /* FileByFileId*/
		case 2: /* FileByApduCmd*/
			return true;
		default:
			return false;
	}
}
bool brp_MifarePlusKeyMemoryType_is_valid(int val) {
	switch (val) {
		case 0: /* CryptoKey*/
		case 1: /* SamKey*/
		case 2: /* ReaderChipKey*/
		case 3: /* VhlKey*/
			return true;
		default:
			return false;
	}
}
bool brp_TemplateBitorder_is_valid(int val) {
	switch (val) {
		case 0: /* Lsb*/
		case 1: /* Msb*/
			return true;
		default:
			return false;
	}
}
bool brp_ProtocolID_is_valid(int val) {
	switch (val) {
		case 3: /* BrpSerial*/
		case 4: /* BrpRs485*/
		case 5: /* BrpHid*/
		case 9: /* DebugInterface*/
		case 16: /* Snet*/
		case 17: /* Bpa9*/
		case 32: /* Wiegand*/
		case 33: /* Omron*/
		case 34: /* ClkData*/
		case 35: /* RawSerial*/
		case 36: /* LowLevelIoPorts*/
		case 43: /* KeyboardEmulation*/
		case 54: /* Ccid*/
		case 55: /* RawSerial2*/
		case 56: /* Osdp*/
		case 134: /* BrpTcp*/
			return true;
		default:
			return false;
	}
}
bool brp_MessageType_is_valid(int val) {
	switch (val) {
		case 0: /* Card*/
		case 1: /* AlarmOn*/
		case 2: /* AlarmOff*/
		case 3: /* Keyboard*/
		case 4: /* CardRemoval*/
		case 5: /* FunctionKey*/
		case 6: /* Logs*/
			return true;
		default:
			return false;
	}
}
bool brp_MaxBaudrateIso14443_is_valid(int val) {
	switch (val) {
		case 0: /* Dri106Dsi106*/
		case 1: /* Dri212Dsi106*/
		case 2: /* Dri424Dsi106*/
		case 3: /* Dri848Dsi106*/
		case 4: /* Dri106Dsi212*/
		case 5: /* Dri212Dsi212*/
		case 6: /* Dri424Dsi212*/
		case 7: /* Dri848Dsi212*/
		case 8: /* Dri106Dsi424*/
		case 9: /* Dri212Dsi424*/
		case 10: /* Dri424Dsi424*/
		case 11: /* Dri848Dsi424*/
		case 12: /* Dri106Dsi848*/
		case 13: /* Dri212Dsi848*/
		case 14: /* Dri424Dsi848*/
		case 15: /* Dri848Dsi848*/
			return true;
		default:
			return false;
	}
}
bool brp_CryptoAlgorithm_is_valid(int val) {
	switch (val) {
		case 1: /* DES*/
		case 2: /* TripleDES*/
		case 3: /* ThreeKeyTripleDES*/
		case 4: /* AES*/
		case 5: /* MifareClassic*/
			return true;
		default:
			return false;
	}
}
bool brp_DivisorInteger_is_valid(int val) {
	switch (val) {
		case 0: /* Kbps106*/
		case 1: /* Kbps212*/
		case 2: /* Kbps424*/
		case 3: /* Kbps848*/
			return true;
		default:
			return false;
	}
}
bool brp_FeatureID_is_valid(int val) {
	switch (val) {
		case 1: /* GreenLed*/
		case 2: /* RedLed*/
		case 3: /* Beeper*/
		case 4: /* Relay*/
		case 5: /* MHz13*/
		case 6: /* Khz125*/
		case 7: /* Iso14443A*/
		case 8: /* Iso14443AUidOnly*/
		case 9: /* Iso14443B*/
		case 10: /* Iso14443BUidOnly*/
		case 11: /* Iso15693*/
		case 12: /* Iso15693UidOnly*/
		case 13: /* Felica*/
		case 14: /* FelicaUidOnly*/
		case 15: /* Legic*/
		case 16: /* Sam*/
		case 17: /* SamAv2*/
		case 18: /* SamHid*/
		case 19: /* Picopass*/
		case 35: /* MifareClassic*/
		case 36: /* MifarePlusEv0*/
		case 37: /* MifareDESFireEv1*/
		case 38: /* Srix*/
		case 39: /* Jewel*/
		case 40: /* ISO14443L4*/
		case 41: /* InterIndustry*/
		case 42: /* EM4205*/
		case 43: /* EM4100*/
		case 44: /* EM4450*/
		case 45: /* FarpointePyramid*/
		case 46: /* HidProx32*/
		case 47: /* HidAwid*/
		case 48: /* HidProx*/
		case 49: /* HidIoProx*/
		case 50: /* Indala*/
		case 51: /* Keri*/
		case 52: /* IndalaSecure*/
		case 53: /* Quadrakey*/
		case 54: /* SecuraKey*/
		case 55: /* GProx*/
		case 56: /* Hitag1S*/
		case 57: /* Hitag2M*/
		case 58: /* Hitag2B*/
		case 59: /* BlueLed*/
		case 60: /* Cotag*/
		case 61: /* PicopassUidOnly*/
		case 62: /* IdTeck*/
		case 63: /* Tamper*/
		case 64: /* MaxHfBaudrate106kbps*/
		case 65: /* MaxHfBaudrate212kbps*/
		case 66: /* MaxHfBaudrate424kbps*/
		case 67: /* FirmwareLoader*/
		case 68: /* FwUploadViaBrpOverSer*/
		case 69: /* AesHostProtocolEncryption*/
		case 70: /* PkiHostProtocolEncryption*/
		case 71: /* HidIClass*/
		case 72: /* HidIClassSr*/
		case 73: /* HidIClassSeAndSeos*/
		case 74: /* MifareUltralight*/
		case 75: /* CardEmulationISO14443L4*/
		case 76: /* MifareDESFireEv2*/
		case 77: /* MifarePlusEv1*/
		case 78: /* SamAv3*/
		case 79: /* OsdpV217*/
		case 80: /* Bluetooth*/
		case 81: /* RgbLed*/
		case 82: /* RgbLedLimited*/
		case 83: /* Bec2Upload*/
		case 84: /* MifareDESFireEv3*/
			return true;
		default:
			return false;
	}
}
bool brp_Parity_is_valid(int val) {
	switch (val) {
		case 69: /* Even*/
		case 78: /* None_*/
		case 79: /* Odd*/
			return true;
		default:
			return false;
	}
}
bool brp_Baudrate_is_valid(int val) {
	switch (val) {
		case 3: /* Baud300*/
		case 6: /* Baud600*/
		case 12: /* Baud1200*/
		case 24: /* Baud2400*/
		case 48: /* Baud4800*/
		case 96: /* Baud9600*/
		case 144: /* Baud14400*/
		case 192: /* Baud19200*/
		case 288: /* Baud28800*/
		case 384: /* Baud38400*/
		case 576: /* Baud57600*/
		case 1152: /* Baud115200*/
		case 5000: /* Baud500000*/
		case 5760: /* Baud576000*/
		case 9216: /* Baud921600*/
			return true;
		default:
			return false;
	}
}
bool brp_IoPort_is_valid(int val) {
	switch (val) {
		case 0: /* GreenLed*/
		case 1: /* RedLed*/
		case 2: /* Beeper*/
		case 3: /* Relay*/
		case 4: /* Input0*/
		case 5: /* Input1*/
		case 6: /* BlueLed*/
		case 7: /* TamperAlarm*/
		case 8: /* Gpio0*/
		case 9: /* Gpio1*/
		case 10: /* Gpio2*/
		case 11: /* Gpio3*/
		case 12: /* Gpio4*/
		case 13: /* Gpio5*/
		case 14: /* Gpio6*/
		case 15: /* Gpio7*/
		case 64: /* CustomVled0*/
		case 65: /* CustomVled1*/
		case 66: /* CustomVled2*/
		case 67: /* CustomVled3*/
		case 68: /* CustomVled4*/
		case 69: /* CustomVled5*/
		case 70: /* CustomVled6*/
		case 71: /* CustomVled7*/
		case 72: /* CustomVled8*/
		case 73: /* CustomVled9*/
		case 74: /* CustomVled10*/
		case 75: /* CustomVled11*/
		case 76: /* CustomVled12*/
		case 77: /* CustomVled13*/
		case 78: /* CustomVled14*/
		case 79: /* CustomVled15*/
			return true;
		default:
			return false;
	}
}
bool brp_FireEventAtPowerup_is_valid(int val) {
	switch (val) {
		case 0: /* Never*/
		case 1: /* IfClear*/
		case 2: /* IfSet*/
		case 3: /* Always*/
			return true;
		default:
			return false;
	}
}
bool brp_CardType_is_valid(int val) {
	switch (val) {
		case 0: /* Default*/
		case 16: /* MifareClassic*/
		case 17: /* Iso14443aGeneric*/
		case 18: /* Iso14443aInterIndustry*/
		case 19: /* MifareUltraLight*/
		case 20: /* MifareDesfire*/
		case 21: /* InfineonSle55*/
		case 22: /* Iso14443aIntIndustryMif*/
		case 23: /* MifarePlusL2*/
		case 24: /* LEGICAdvantIso14443a*/
		case 25: /* MifarePlusL3*/
		case 32: /* LEGICPrimeLegacy*/
		case 33: /* LEGICAdvantLegacy*/
		case 48: /* Iso15693*/
		case 50: /* LEGICAdvantIso15693*/
		case 64: /* Iso14443bUnknown*/
		case 65: /* Iso14443bIntIndustry*/
		case 66: /* IClassIso14B*/
		case 80: /* IClassIso14B2*/
		case 96: /* IClass*/
		case 112: /* Felica*/
		case 128: /* EM4205*/
		case 129: /* EM4100*/
		case 131: /* EM4450*/
		case 132: /* Pyramid*/
		case 133: /* HidProx32*/
		case 134: /* Keri*/
		case 135: /* Quadrakey*/
		case 136: /* HidIndala*/
		case 137: /* HidAwid*/
		case 138: /* HidProx*/
		case 139: /* HidIoprox*/
		case 140: /* Hitag1S*/
		case 141: /* Hitag2M*/
		case 142: /* Hitag2B*/
		case 143: /* TTF*/
		case 144: /* STSRIX*/
		case 160: /* SecuraKey*/
		case 161: /* GProx*/
		case 162: /* HidIndalaSecure*/
		case 163: /* Cotag*/
		case 164: /* Idteck*/
		case 176: /* BluetoothMce*/
		case 192: /* LEGICPrime*/
		case 224: /* HidSio*/
			return true;
		default:
			return false;
	}
}
bool brp_AuthReqUpload_is_valid(int val) {
	switch (val) {
		case 0: /* Default*/
		case 1: /* None_*/
		case 2: /* CustomerKey*/
		case 3: /* ConfigSecurityCode*/
		case 4: /* Version*/
		case 5: /* GreaterVersion*/
			return true;
		default:
			return false;
	}
}
bool brp_AutoReadMode_is_valid(int val) {
	switch (val) {
		case 0: /* Disabled*/
		case 1: /* Enabled*/
		case 2: /* EnableOnce*/
		case 255: /* EnableIfDefinedRules*/
			return true;
		default:
			return false;
	}
}
brp_errcode brp_ASK_SecuraKeyRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 54);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_ASK_GproxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 54);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_ASK_CotagRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 54);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_AR_SetMode(brp_protocol protocol, brp_AutoReadMode Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_AR_GetMessage(brp_protocol protocol, brp_MessageType* MsgType, brp_buf* MsgData, size_t* MsgData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _MsgData_len;
	if(MsgData_len == NULL) MsgData_len = &_MsgData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _MsgType_int_val = brp_frame_read_int8(&_reader);
	if (! brp_MessageType_is_valid(_MsgType_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (MsgType != NULL)
		(*MsgType) = (brp_MessageType)_MsgType_int_val;
	(*MsgData_len) = brp_frame_read_int8(&_reader);
	if (MsgData != NULL) {
		(*MsgData) = (brp_buf)brp_mempool_create_buf(mempool, (*MsgData_len));
		if((*MsgData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*MsgData), (*MsgData_len));
	} else
		brp_frame_skip(&_reader, (*MsgData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_AR_RunScript(brp_protocol protocol, brp_buf Script, size_t Script_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Script_len);
	brp_frame_write(_frame, (brp_buf)Script, Script_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Bat_Run(brp_protocol protocol, brp_Bat_Run_SubCmds_Entry* SubCmds, size_t SubCmds_len, brp_Bat_Run_Rsps_Entry** Rsps, size_t* Rsps_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Rsps_len;
	if(Rsps_len == NULL) Rsps_len = &_Rsps_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int8(_frame, (unsigned)SubCmds_len);
	for(size_t _SubCmds_ndx = 0;_SubCmds_ndx < SubCmds_len;_SubCmds_ndx++) {
		brp_Bat_Run_SubCmds_Entry SubCmds_Entry = SubCmds[_SubCmds_ndx];
		unsigned ConditionBits = SubCmds_Entry.ConditionBits;
		unsigned DevCode = SubCmds_Entry.DevCode;
		unsigned CmdCode = SubCmds_Entry.CmdCode;
		brp_buf Params = SubCmds_Entry.Params;
		size_t Params_len = SubCmds_Entry.Params_len;
		brp_frame_write_int16(_frame, (unsigned)ConditionBits);
		brp_frame_write_int8(_frame, (unsigned)DevCode);
		brp_frame_write_int8(_frame, (unsigned)CmdCode);
		brp_frame_write_int16(_frame, (unsigned)Params_len);
		brp_frame_write(_frame, (brp_buf)Params, Params_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Rsps_len) = brp_frame_read_int8(&_reader);
	if (Rsps != NULL) {
		(*Rsps) = (brp_Bat_Run_Rsps_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*Rsps) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Rsps_ndx = 1;!((_Rsps_ndx > (*Rsps_len)) | brp_frame_read_err(&_reader));_Rsps_ndx++) {
		brp_Bat_Run_Rsps_Entry _Rsps_Entry;
		brp_Bat_Run_Rsps_Entry *Rsps_Entry = &_Rsps_Entry;
		unsigned _Status;
		unsigned *Status = &_Status;
		brp_buf _Resp;
		brp_buf *Resp = &_Resp;
		size_t _Resp_len;
		size_t *Resp_len = &_Resp_len;
		(*Status) = (unsigned)brp_frame_read_int8(&_reader);
		(*Resp_len) = brp_frame_read_int16(&_reader);
		if (Resp != NULL) {
			(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
			if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
		} else
			brp_frame_skip(&_reader, (*Resp_len));
		if(Rsps_Entry != NULL) {
			Rsps_Entry->Status = *Status;
			Rsps_Entry->Resp = *Resp;
			Rsps_Entry->Resp_len = *Resp_len;
		}
		if (Rsps != NULL) {
			(*Rsps) = (brp_Bat_Run_Rsps_Entry*)brp_mempool_resize_buf((brp_buf)(*Rsps), (_Rsps_ndx * sizeof(brp_Bat_Run_Rsps_Entry)));
			if((*Rsps) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Rsps)[_Rsps_ndx-1] = *Rsps_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Bat_CheckStatus(brp_protocol protocol, unsigned CondBitNdx, unsigned* StatusCodes, size_t StatusCodes_len, bool Invert) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CondBitNdx);
	brp_frame_write_int8(_frame, (unsigned)StatusCodes_len);
	for(size_t _StatusCodes_ndx = 0;_StatusCodes_ndx < StatusCodes_len;_StatusCodes_ndx++) {
		unsigned StatusCode = StatusCodes[_StatusCodes_ndx];
		brp_frame_write_int8(_frame, (unsigned)StatusCode);
	}
	brp_frame_write_int8(_frame, (unsigned)Invert);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Bat_CheckAny(brp_protocol protocol, unsigned CondBitNdx, unsigned CondBits, bool Invert) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CondBitNdx);
	brp_frame_write_int16(_frame, (unsigned)CondBits);
	brp_frame_write_int8(_frame, (unsigned)Invert);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Bat_CheckTemplate(brp_protocol protocol, unsigned CondBitNdx, brp_buf Template, size_t Template_len, unsigned* FieldBitLens, size_t FieldBitLens_len, bool Invert) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CondBitNdx);
	brp_frame_write_int8(_frame, (unsigned)Template_len);
	brp_frame_write(_frame, (brp_buf)Template, Template_len);
	brp_frame_write_int8(_frame, (unsigned)FieldBitLens_len);
	for(size_t _FieldBitLens_ndx = 0;_FieldBitLens_ndx < FieldBitLens_len;_FieldBitLens_ndx++) {
		unsigned FieldLen = FieldBitLens[_FieldBitLens_ndx];
		brp_frame_write_int8(_frame, (unsigned)FieldLen);
	}
	brp_frame_write_int8(_frame, (unsigned)Invert);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Bat_Delay(brp_protocol protocol, unsigned DelayTime) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)DelayTime);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_DefineService(brp_protocol protocol, brp_buf ServiceUUID, size_t ServiceUUID_len, brp_BlePeriph_DefineService_Characteristics_Entry* Characteristics, size_t Characteristics_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ServiceUUID_len);
	brp_frame_write(_frame, (brp_buf)ServiceUUID, ServiceUUID_len);
	brp_frame_write_int8(_frame, (unsigned)Characteristics_len);
	for(size_t _Characteristics_ndx = 0;_Characteristics_ndx < Characteristics_len;_Characteristics_ndx++) {
		brp_BlePeriph_DefineService_Characteristics_Entry Characteristics_Entry = Characteristics[_Characteristics_ndx];
		brp_buf CharacteristicUUID = Characteristics_Entry.CharacteristicUUID;
		size_t CharacteristicUUID_len = Characteristics_Entry.CharacteristicUUID_len;
		unsigned Size = Characteristics_Entry.Size;
		bool SupportsRead = Characteristics_Entry.SupportsRead;
		bool SupportsWrite = Characteristics_Entry.SupportsWrite;
		bool SupportsNotify = Characteristics_Entry.SupportsNotify;
		bool SupportsIndicate = Characteristics_Entry.SupportsIndicate;
		bool VariableSize = Characteristics_Entry.VariableSize;
		brp_frame_write_int8(_frame, (unsigned)CharacteristicUUID_len);
		brp_frame_write(_frame, (brp_buf)CharacteristicUUID, CharacteristicUUID_len);
		brp_frame_write_int16(_frame, (unsigned)Size);
		unsigned bitmask_1772207507776 = 0;
		bitmask_1772207507776 |= (SupportsRead & 0b1) << 7;
		bitmask_1772207507776 |= (SupportsWrite & 0b1) << 6;
		bitmask_1772207507776 |= (SupportsNotify & 0b1) << 5;
		bitmask_1772207507776 |= (SupportsIndicate & 0b1) << 4;
		bitmask_1772207507776 |= (VariableSize & 0b1) << 3;
		brp_frame_write_int8(_frame, (unsigned)bitmask_1772207507776);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_Enable(brp_protocol protocol, bool Activate) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Activate);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_SetDeviceName(brp_protocol protocol, brp_buf DeviceName, size_t DeviceName_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)DeviceName_len);
	brp_frame_write(_frame, (brp_buf)DeviceName, DeviceName_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_SetCharacteristic(brp_protocol protocol, unsigned CharacteristicNdx, brp_buf NewValue, size_t NewValue_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)CharacteristicNdx);
	brp_frame_write_int16(_frame, (unsigned)NewValue_len);
	brp_frame_write(_frame, (brp_buf)NewValue, NewValue_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_GetCharacteristic(brp_protocol protocol, unsigned CharacteristicNdx, brp_buf* CurrentValue, size_t* CurrentValue_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _CurrentValue_len;
	if(CurrentValue_len == NULL) CurrentValue_len = &_CurrentValue_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)CharacteristicNdx);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CurrentValue_len) = brp_frame_read_int16(&_reader);
	if (CurrentValue != NULL) {
		(*CurrentValue) = (brp_buf)brp_mempool_create_buf(mempool, (*CurrentValue_len));
		if((*CurrentValue) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*CurrentValue), (*CurrentValue_len));
	} else
		brp_frame_skip(&_reader, (*CurrentValue_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_GetEvents(brp_protocol protocol, brp_BlePeriph_GetEvents_Events_Entry** Events, size_t* Events_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Events_len;
	if(Events_len == NULL) Events_len = &_Events_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Events_len) = brp_frame_read_int8(&_reader);
	if (Events != NULL) {
		(*Events) = (brp_BlePeriph_GetEvents_Events_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*Events) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Events_ndx = 1;!((_Events_ndx > (*Events_len)) | brp_frame_read_err(&_reader));_Events_ndx++) {
		brp_BlePeriph_GetEvents_Events_Entry _Events_Entry;
		brp_BlePeriph_GetEvents_Events_Entry *Events_Entry = &_Events_Entry;
		brp_BlePeriph_GetEvents_EventId _EventId;
		brp_BlePeriph_GetEvents_EventId *EventId = &_EventId;
		unsigned _CharacteristicNdx;
		unsigned *CharacteristicNdx = &_CharacteristicNdx;
		int _EventId_int_val = brp_frame_read_int8(&_reader);
		if (! brp_BlePeriph_GetEvents_EventId_is_valid(_EventId_int_val))
			return BRP_ERR_PAYLOAD_FORMAT;
		if (EventId != NULL)
			(*EventId) = (brp_BlePeriph_GetEvents_EventId)_EventId_int_val;
		(*CharacteristicNdx) = (unsigned)brp_frame_read_int16(&_reader);
		if(Events_Entry != NULL) {
			Events_Entry->EventId = *EventId;
			Events_Entry->CharacteristicNdx = *CharacteristicNdx;
		}
		if (Events != NULL) {
			(*Events) = (brp_BlePeriph_GetEvents_Events_Entry*)brp_mempool_resize_buf((brp_buf)(*Events), (_Events_ndx * sizeof(brp_BlePeriph_GetEvents_Events_Entry)));
			if((*Events) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Events)[_Events_ndx-1] = *Events_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_BlePeriph_GetRSSI(brp_protocol protocol, unsigned* AbsRSSI) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_AbsRSSI;
	if (AbsRSSI == NULL) AbsRSSI = &_tmp_AbsRSSI;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 75);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*AbsRSSI) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_CardEmu_GetMaxFrameSize(brp_protocol protocol, unsigned* MaxFrameSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_MaxFrameSize;
	if (MaxFrameSize == NULL) MaxFrameSize = &_tmp_MaxFrameSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MaxFrameSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_CardEmu_StartEmu(brp_protocol protocol, brp_buf Snr, unsigned ATQA, unsigned SAK, unsigned Timeout, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _FirstCmd_len;
	if(FirstCmd_len == NULL) FirstCmd_len = &_FirstCmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 1000);
	unsigned char Padding[] = { 0x0 };
	brp_frame_write( _frame, Padding, 1);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_frame_write_int16(_frame, (unsigned)ATQA);
	brp_frame_write_int8(_frame, (unsigned)SAK);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FirstCmd_len) = brp_frame_read_int16(&_reader);
	if (FirstCmd != NULL) {
		(*FirstCmd) = (brp_buf)brp_mempool_create_buf(mempool, (*FirstCmd_len));
		if((*FirstCmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*FirstCmd), (*FirstCmd_len));
	} else
		brp_frame_skip(&_reader, (*FirstCmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_CardEmu_TransparentCmd(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Cmd_len;
	if(Cmd_len == NULL) Cmd_len = &_Cmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Rsp_len);
	brp_frame_write(_frame, (brp_buf)Rsp, Rsp_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Cmd_len) = brp_frame_read_int16(&_reader);
	if (Cmd != NULL) {
		(*Cmd) = (brp_buf)brp_mempool_create_buf(mempool, (*Cmd_len));
		if((*Cmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Cmd), (*Cmd_len));
	} else
		brp_frame_skip(&_reader, (*Cmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_CardEmu_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ExtFieldStat;
	if (ExtFieldStat == NULL) ExtFieldStat = &_tmp_ExtFieldStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ExtFieldStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_CardEmu_StartNfc(brp_protocol protocol, bool NfcAPassiv, brp_buf Snr, unsigned ATQA, unsigned SAK, unsigned Timeout, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _FirstCmd_len;
	if(FirstCmd_len == NULL) FirstCmd_len = &_FirstCmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 1000);
	unsigned bitmask_1772207510992 = 0;
	bitmask_1772207510992 |= (NfcAPassiv & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207510992);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_frame_write_int16(_frame, (unsigned)ATQA);
	brp_frame_write_int8(_frame, (unsigned)SAK);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FirstCmd_len) = brp_frame_read_int16(&_reader);
	if (FirstCmd != NULL) {
		(*FirstCmd) = (brp_buf)brp_mempool_create_buf(mempool, (*FirstCmd_len));
		if((*FirstCmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*FirstCmd), (*FirstCmd_len));
	} else
		brp_frame_skip(&_reader, (*FirstCmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_EncryptBlock(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf Block, brp_buf* EncryptedBlock, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	if((KeyIndex) == (0)) {
		size_t KeyValue_len = 10;
		brp_frame_write(_frame, (brp_buf)KeyValue, KeyValue_len);
	}
	size_t Block_len = 8;
	brp_frame_write(_frame, (brp_buf)Block, Block_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _EncryptedBlock_len = 8;
	size_t* EncryptedBlock_len = &_EncryptedBlock_len;
	if (EncryptedBlock != NULL) {
		(*EncryptedBlock) = (brp_buf)brp_mempool_create_buf(mempool, (*EncryptedBlock_len));
		if((*EncryptedBlock) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncryptedBlock), (*EncryptedBlock_len));
	} else
		brp_frame_skip(&_reader, (*EncryptedBlock_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_DecryptBlock(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf Block, brp_buf* UnencryptedBlock, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	if((KeyIndex) == (0)) {
		size_t KeyValue_len = 10;
		brp_frame_write(_frame, (brp_buf)KeyValue, KeyValue_len);
	}
	size_t Block_len = 8;
	brp_frame_write(_frame, (brp_buf)Block, Block_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _UnencryptedBlock_len = 8;
	size_t* UnencryptedBlock_len = &_UnencryptedBlock_len;
	if (UnencryptedBlock != NULL) {
		(*UnencryptedBlock) = (brp_buf)brp_mempool_create_buf(mempool, (*UnencryptedBlock_len));
		if((*UnencryptedBlock) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*UnencryptedBlock), (*UnencryptedBlock_len));
	} else
		brp_frame_skip(&_reader, (*UnencryptedBlock_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_EncryptBuffer(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf InitialVector, brp_buf Buffer, size_t Buffer_len, brp_buf* NextInitialVector, brp_buf* EncryptedBuffer, size_t* EncryptedBuffer_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncryptedBuffer_len;
	if(EncryptedBuffer_len == NULL) EncryptedBuffer_len = &_EncryptedBuffer_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	if((KeyIndex) == (0)) {
		size_t KeyValue_len = 10;
		brp_frame_write(_frame, (brp_buf)KeyValue, KeyValue_len);
	}
	size_t InitialVector_len = 8;
	brp_frame_write(_frame, (brp_buf)InitialVector, InitialVector_len);
	brp_frame_write_int8(_frame, (unsigned)Buffer_len);
	brp_frame_write(_frame, (brp_buf)Buffer, Buffer_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _NextInitialVector_len = 8;
	size_t* NextInitialVector_len = &_NextInitialVector_len;
	if (NextInitialVector != NULL) {
		(*NextInitialVector) = (brp_buf)brp_mempool_create_buf(mempool, (*NextInitialVector_len));
		if((*NextInitialVector) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*NextInitialVector), (*NextInitialVector_len));
	} else
		brp_frame_skip(&_reader, (*NextInitialVector_len));
	(*EncryptedBuffer_len) = brp_frame_read_int8(&_reader);
	if (EncryptedBuffer != NULL) {
		(*EncryptedBuffer) = (brp_buf)brp_mempool_create_buf(mempool, (*EncryptedBuffer_len));
		if((*EncryptedBuffer) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncryptedBuffer), (*EncryptedBuffer_len));
	} else
		brp_frame_skip(&_reader, (*EncryptedBuffer_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_DecryptBuffer(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf InitialVector, brp_buf Buffer, size_t Buffer_len, brp_buf* NextInitialVector, brp_buf* UnencryptedBuffer, size_t* UnencryptedBuffer_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _UnencryptedBuffer_len;
	if(UnencryptedBuffer_len == NULL) UnencryptedBuffer_len = &_UnencryptedBuffer_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	if((KeyIndex) == (0)) {
		size_t KeyValue_len = 10;
		brp_frame_write(_frame, (brp_buf)KeyValue, KeyValue_len);
	}
	size_t InitialVector_len = 8;
	brp_frame_write(_frame, (brp_buf)InitialVector, InitialVector_len);
	brp_frame_write_int8(_frame, (unsigned)Buffer_len);
	brp_frame_write(_frame, (brp_buf)Buffer, Buffer_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _NextInitialVector_len = 8;
	size_t* NextInitialVector_len = &_NextInitialVector_len;
	if (NextInitialVector != NULL) {
		(*NextInitialVector) = (brp_buf)brp_mempool_create_buf(mempool, (*NextInitialVector_len));
		if((*NextInitialVector) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*NextInitialVector), (*NextInitialVector_len));
	} else
		brp_frame_skip(&_reader, (*NextInitialVector_len));
	(*UnencryptedBuffer_len) = brp_frame_read_int8(&_reader);
	if (UnencryptedBuffer != NULL) {
		(*UnencryptedBuffer) = (brp_buf)brp_mempool_create_buf(mempool, (*UnencryptedBuffer_len));
		if((*UnencryptedBuffer) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*UnencryptedBuffer), (*UnencryptedBuffer_len));
	} else
		brp_frame_skip(&_reader, (*UnencryptedBuffer_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_BalKeyEncryptBuffer(brp_protocol protocol, unsigned KeyVersion, unsigned EmbeddedKeyIndex, unsigned EmbeddedKeyPos, brp_buf Buffer, size_t Buffer_len, brp_buf InitialVector, size_t InitialVector_len, brp_buf* EncryptedBuffer, size_t* EncryptedBuffer_len, brp_buf* NextInitialVector, size_t* NextInitialVector_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncryptedBuffer_len;
	if(EncryptedBuffer_len == NULL) EncryptedBuffer_len = &_EncryptedBuffer_len;
	size_t _NextInitialVector_len;
	if(NextInitialVector_len == NULL) NextInitialVector_len = &_NextInitialVector_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyVersion);
	brp_frame_write_int8(_frame, (unsigned)EmbeddedKeyIndex);
	brp_frame_write_int8(_frame, (unsigned)EmbeddedKeyPos);
	brp_frame_write_int8(_frame, (unsigned)Buffer_len);
	brp_frame_write(_frame, (brp_buf)Buffer, Buffer_len);
	brp_frame_write_int8(_frame, (unsigned)InitialVector_len);
	brp_frame_write(_frame, (brp_buf)InitialVector, InitialVector_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*EncryptedBuffer_len) = brp_frame_read_int8(&_reader);
	if (EncryptedBuffer != NULL) {
		(*EncryptedBuffer) = (brp_buf)brp_mempool_create_buf(mempool, (*EncryptedBuffer_len));
		if((*EncryptedBuffer) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncryptedBuffer), (*EncryptedBuffer_len));
	} else
		brp_frame_skip(&_reader, (*EncryptedBuffer_len));
	(*NextInitialVector_len) = brp_frame_read_int8(&_reader);
	if (NextInitialVector != NULL) {
		(*NextInitialVector) = (brp_buf)brp_mempool_create_buf(mempool, (*NextInitialVector_len));
		if((*NextInitialVector) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*NextInitialVector), (*NextInitialVector_len));
	} else
		brp_frame_skip(&_reader, (*NextInitialVector_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_GetKeySig(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, unsigned* KeySignature) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_KeySignature;
	if (KeySignature == NULL) KeySignature = &_tmp_KeySignature;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	if((KeyIndex) == (0)) {
		size_t KeyValue_len = 10;
		brp_frame_write(_frame, (brp_buf)KeyValue, KeyValue_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*KeySignature) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Crypto_CopyConfigKey(brp_protocol protocol, unsigned KeyIndex, bool ForceDefaultKey) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 2000);
	brp_frame_write_int8(_frame, (unsigned)KeyIndex);
	brp_frame_write_int8(_frame, (unsigned)ForceDefaultKey);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Dbg_ReadLogs(brp_protocol protocol, char** LogData, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 243);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _LogData_len = 0;
	size_t* LogData_len = &_LogData_len;
	(*LogData_len) = brp_frame_read_int16(&_reader);
	if (LogData != NULL) {
		(*LogData) = (char*)brp_mempool_create_buf(mempool, (*LogData_len));
		if((*LogData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LogData), (*LogData_len));
	} else
		brp_frame_skip(&_reader, (*LogData_len));
	if(LogData != NULL) {
		(*LogData_len) += 1;
		(*LogData) = (char*)brp_mempool_resize_buf((brp_buf)(*LogData), (*LogData_len));
		if((*LogData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*LogData)[(*LogData_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Dbg_RunCmd(brp_protocol protocol, char* Cmd) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 243);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	size_t Cmd_len = strlen(Cmd);
	if(strlen(Cmd) != 1)return BRP_ERR_INVALID_API_CALL;
	brp_frame_write(_frame, (brp_buf)Cmd, Cmd_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ExecCommand(brp_protocol protocol, unsigned Cmd, brp_buf Header, size_t Header_len, brp_buf Param, size_t Param_len, brp_Desfire_ExecCommand_CryptoMode CryptoMode, unsigned ResponseLen, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int8(_frame, (unsigned)Cmd);
	brp_frame_write_int8(_frame, (unsigned)Header_len);
	brp_frame_write(_frame, (brp_buf)Header, Header_len);
	brp_frame_write_int16(_frame, (unsigned)Param_len);
	brp_frame_write(_frame, (brp_buf)Param, Param_len);
	brp_frame_write_int8(_frame, (unsigned)CryptoMode);
	brp_frame_write_int16(_frame, (unsigned)ResponseLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Resp_len) = brp_frame_read_int16(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_Authenticate(brp_protocol protocol, brp_Desfire_Authenticate_SecureMessaging SecureMessaging, unsigned DesKeynr, unsigned KeyId, bool KeyHasDivData, brp_Desfire_Authenticate_KeyDivMode KeyDivMode, bool KeyHasExtIdx, brp_buf KeyDivData, size_t KeyDivData_len, unsigned KeyExtIdx) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 2000);
	brp_frame_write_int8(_frame, (unsigned)SecureMessaging);
	brp_frame_write_int8(_frame, (unsigned)DesKeynr);
	brp_frame_write_int8(_frame, (unsigned)KeyId);
	unsigned bitmask_1772207518096 = 0;
	bitmask_1772207518096 |= (KeyHasDivData & 0b1) << 4;
	bitmask_1772207518096 |= (KeyDivMode & 0b111) << 1;
	bitmask_1772207518096 |= (KeyHasExtIdx & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207518096);
	if(KeyHasDivData) {
		brp_frame_write_int8(_frame, (unsigned)KeyDivData_len);
		brp_frame_write(_frame, (brp_buf)KeyDivData, KeyDivData_len);
	}
	if(KeyHasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)KeyExtIdx);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_AuthExtKey(brp_protocol protocol, brp_Desfire_AuthExtKey_SecureMessaging SecureMessaging, unsigned DesKeyNr, brp_Desfire_AuthExtKey_CryptoMode CryptoMode, brp_buf Key, size_t Key_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 2000);
	brp_frame_write_int8(_frame, (unsigned)SecureMessaging);
	brp_frame_write_int8(_frame, (unsigned)DesKeyNr);
	brp_frame_write_int8(_frame, (unsigned)CryptoMode);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_SelectApplication(brp_protocol protocol, unsigned AppId) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int32(_frame, (unsigned)AppId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ReadData(brp_protocol protocol, unsigned FileId, unsigned Adr, unsigned Len, brp_Desfire_ReadData_Mode Mode, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)FileId);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int16(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_WriteData(brp_protocol protocol, unsigned FileId, unsigned Adr, brp_buf Data, size_t Data_len, brp_Desfire_WriteData_Mode Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)FileId);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ChangeExtKey(brp_protocol protocol, brp_Desfire_ChangeExtKey_MasterKeyType MasterKeyType, bool IsKeySet, bool IsAesKey, bool IsVersion, bool IsChangeKey, unsigned KeyNo, unsigned KeyVersion, brp_buf NewKey, size_t NewKey_len, brp_buf OldKey, size_t OldKey_len, unsigned KeySet) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 1000);
	unsigned bitmask_1772207520736 = 0;
	bitmask_1772207520736 |= (MasterKeyType & 0b11) << 6;
	bitmask_1772207520736 |= (IsKeySet & 0b1) << 3;
	bitmask_1772207520736 |= (IsAesKey & 0b1) << 2;
	bitmask_1772207520736 |= (IsVersion & 0b1) << 1;
	bitmask_1772207520736 |= (IsChangeKey & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207520736);
	brp_frame_write_int8(_frame, (unsigned)KeyNo);
	if(IsVersion) {
		brp_frame_write_int8(_frame, (unsigned)KeyVersion);
	}
	brp_frame_write_int8(_frame, (unsigned)NewKey_len);
	brp_frame_write(_frame, (brp_buf)NewKey, NewKey_len);
	brp_frame_write_int8(_frame, (unsigned)OldKey_len);
	brp_frame_write(_frame, (brp_buf)OldKey, OldKey_len);
	if(IsKeySet) {
		brp_frame_write_int8(_frame, (unsigned)KeySet);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ChangeKey(brp_protocol protocol, bool IsKeySet, bool IsMasterKey, bool IsChangeKey, unsigned KeyNr, brp_Desfire_ChangeKey_NewKeyDivMode NewKeyDivMode, bool NewKeyHasDivData, bool NewKeyHasExtIdx, unsigned NewKeyIdx, brp_Desfire_ChangeKey_CurKeyDivMode CurKeyDivMode, bool CurKeyHasDivData, bool CurKeyHasExtIdx, unsigned CurKeyIdx, brp_buf NewKeyDivData, size_t NewKeyDivData_len, brp_buf CurKeyDivData, size_t CurKeyDivData_len, unsigned NewKeyExtIdx, unsigned CurKeyExtIdx, unsigned KeySet) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 1000);
	unsigned bitmask_1772207521696 = 0;
	bitmask_1772207521696 |= (IsKeySet & 0b1) << 2;
	bitmask_1772207521696 |= (IsMasterKey & 0b1) << 1;
	bitmask_1772207521696 |= (IsChangeKey & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207521696);
	brp_frame_write_int8(_frame, (unsigned)KeyNr);
	unsigned bitmask_1772207358208 = 0;
	bitmask_1772207358208 |= (NewKeyDivMode & 0b11) << 3;
	bitmask_1772207358208 |= (NewKeyHasDivData & 0b1) << 1;
	bitmask_1772207358208 |= (NewKeyHasExtIdx & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207358208);
	brp_frame_write_int8(_frame, (unsigned)NewKeyIdx);
	unsigned bitmask_1772207358688 = 0;
	bitmask_1772207358688 |= (CurKeyDivMode & 0b11) << 3;
	bitmask_1772207358688 |= (CurKeyHasDivData & 0b1) << 1;
	bitmask_1772207358688 |= (CurKeyHasExtIdx & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207358688);
	brp_frame_write_int8(_frame, (unsigned)CurKeyIdx);
	if(NewKeyHasDivData) {
		brp_frame_write_int8(_frame, (unsigned)NewKeyDivData_len);
		brp_frame_write(_frame, (brp_buf)NewKeyDivData, NewKeyDivData_len);
	}
	if(CurKeyHasDivData) {
		brp_frame_write_int8(_frame, (unsigned)CurKeyDivData_len);
		brp_frame_write(_frame, (brp_buf)CurKeyDivData, CurKeyDivData_len);
	}
	if(NewKeyHasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)NewKeyExtIdx);
	}
	if(CurKeyHasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)CurKeyExtIdx);
	}
	if(IsKeySet) {
		brp_frame_write_int8(_frame, (unsigned)KeySet);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_SetFraming(brp_protocol protocol, brp_Desfire_SetFraming_CommMode CommMode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CommMode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ResetAuthentication(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 1000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_CreateDam(brp_protocol protocol, unsigned AppId, brp_buf AppParams, size_t AppParams_len, brp_buf EncryptedDefaultDamKey, size_t EncryptedDefaultDamKey_len, brp_buf DamMacKey, size_t DamMacKey_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 2000);
	brp_frame_write_int32(_frame, (unsigned)AppId);
	brp_frame_write_int8(_frame, (unsigned)AppParams_len);
	brp_frame_write(_frame, (brp_buf)AppParams, AppParams_len);
	brp_frame_write_int8(_frame, (unsigned)EncryptedDefaultDamKey_len);
	brp_frame_write(_frame, (brp_buf)EncryptedDefaultDamKey, EncryptedDefaultDamKey_len);
	brp_frame_write_int8(_frame, (unsigned)DamMacKey_len);
	brp_frame_write(_frame, (brp_buf)DamMacKey, DamMacKey_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_GetOriginalitySignature(brp_protocol protocol, brp_buf* Signature, size_t* Signature_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Signature_len;
	if(Signature_len == NULL) Signature_len = &_Signature_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 1000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Signature_len) = brp_frame_read_int8(&_reader);
	if (Signature != NULL) {
		(*Signature) = (brp_buf)brp_mempool_create_buf(mempool, (*Signature_len));
		if((*Signature) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Signature), (*Signature_len));
	} else
		brp_frame_skip(&_reader, (*Signature_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_VirtualCardSelect(brp_protocol protocol, bool ForceVcsAuthentication, bool UseExtVcSelectKeys, unsigned DiversifyMacKey, bool DiversifyEncKey, bool UseVcSelectKeys, brp_buf IID, size_t IID_len, unsigned EncKeyIdx, unsigned MacKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf EncKey, size_t EncKey_len, brp_buf MacKey, size_t MacKey_len, unsigned* FciType, brp_buf* Fci, size_t* Fci_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Fci_len;
	if(Fci_len == NULL) Fci_len = &_Fci_len;
	unsigned _tmp_FciType;
	if (FciType == NULL) FciType = &_tmp_FciType;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 2000);
	unsigned bitmask_1772207360608 = 0;
	bitmask_1772207360608 |= (ForceVcsAuthentication & 0b1) << 5;
	bitmask_1772207360608 |= (UseExtVcSelectKeys & 0b1) << 4;
	bitmask_1772207360608 |= (DiversifyMacKey & 0b11) << 2;
	bitmask_1772207360608 |= (DiversifyEncKey & 0b1) << 1;
	bitmask_1772207360608 |= (UseVcSelectKeys & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207360608);
	brp_frame_write_int8(_frame, (unsigned)IID_len);
	brp_frame_write(_frame, (brp_buf)IID, IID_len);
	if(UseVcSelectKeys) {
		brp_frame_write_int16(_frame, (unsigned)EncKeyIdx);
		brp_frame_write_int16(_frame, (unsigned)MacKeyIdx);
	}
	if(((((DiversifyMacKey) == (1)) || ((DiversifyMacKey) == (2))) || ((DiversifyMacKey) == (3))) || (DiversifyEncKey)) {
		brp_frame_write_int8(_frame, (unsigned)DivData_len);
		brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	}
	if(UseExtVcSelectKeys) {
		brp_frame_write_int8(_frame, (unsigned)EncKey_len);
		brp_frame_write(_frame, (brp_buf)EncKey, EncKey_len);
		brp_frame_write_int8(_frame, (unsigned)MacKey_len);
		brp_frame_write(_frame, (brp_buf)MacKey, MacKey_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FciType) = (unsigned)brp_frame_read_int8(&_reader);
	(*Fci_len) = brp_frame_read_int8(&_reader);
	if (Fci != NULL) {
		(*Fci) = (brp_buf)brp_mempool_create_buf(mempool, (*Fci_len));
		if((*Fci) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Fci), (*Fci_len));
	} else
		brp_frame_skip(&_reader, (*Fci_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_ProxCheck(brp_protocol protocol, unsigned M, bool UseExtProxKey, bool DiversifyProxKey, bool UseProxKey, unsigned ProxKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf ProxKey, size_t ProxKey_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 12);
	brp_frame_write_int32(_frame, 2000);
	unsigned bitmask_1772207361664 = 0;
	bitmask_1772207361664 |= (M & 0b111) << 4;
	bitmask_1772207361664 |= (UseExtProxKey & 0b1) << 2;
	bitmask_1772207361664 |= (DiversifyProxKey & 0b1) << 1;
	bitmask_1772207361664 |= (UseProxKey & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207361664);
	if(UseProxKey) {
		brp_frame_write_int16(_frame, (unsigned)ProxKeyIdx);
	}
	if((DiversifyProxKey) && (UseProxKey)) {
		brp_frame_write_int8(_frame, (unsigned)DivData_len);
		brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	}
	if(UseExtProxKey) {
		brp_frame_write_int8(_frame, (unsigned)ProxKey_len);
		brp_frame_write(_frame, (brp_buf)ProxKey, ProxKey_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Desfire_GetDfNames(brp_protocol protocol, brp_Desfire_GetDfNames_AppNr_Entry** AppNr, size_t* AppNr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _AppNr_len;
	if(AppNr_len == NULL) AppNr_len = &_AppNr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int8(_frame, 13);
	brp_frame_write_int32(_frame, 3000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*AppNr_len) = brp_frame_read_int8(&_reader);
	if (AppNr != NULL) {
		(*AppNr) = (brp_Desfire_GetDfNames_AppNr_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*AppNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _AppNr_ndx = 1;!((_AppNr_ndx > (*AppNr_len)) | brp_frame_read_err(&_reader));_AppNr_ndx++) {
		brp_Desfire_GetDfNames_AppNr_Entry _AppNr_Entry;
		brp_Desfire_GetDfNames_AppNr_Entry *AppNr_Entry = &_AppNr_Entry;
		unsigned _AppId;
		unsigned *AppId = &_AppId;
		unsigned _IsoFileId;
		unsigned *IsoFileId = &_IsoFileId;
		brp_buf _IsoDfName;
		brp_buf *IsoDfName = &_IsoDfName;
		size_t _IsoDfName_len;
		size_t *IsoDfName_len = &_IsoDfName_len;
		(*AppId) = (unsigned)brp_frame_read_int32(&_reader);
		(*IsoFileId) = (unsigned)brp_frame_read_int16(&_reader);
		(*IsoDfName_len) = brp_frame_read_int8(&_reader);
		if (IsoDfName != NULL) {
			(*IsoDfName) = (brp_buf)brp_mempool_create_buf(mempool, (*IsoDfName_len));
			if((*IsoDfName) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*IsoDfName), (*IsoDfName_len));
		} else
			brp_frame_skip(&_reader, (*IsoDfName_len));
		if(AppNr_Entry != NULL) {
			AppNr_Entry->AppId = *AppId;
			AppNr_Entry->IsoFileId = *IsoFileId;
			AppNr_Entry->IsoDfName = *IsoDfName;
			AppNr_Entry->IsoDfName_len = *IsoDfName_len;
		}
		if (AppNr != NULL) {
			(*AppNr) = (brp_Desfire_GetDfNames_AppNr_Entry*)brp_mempool_resize_buf((brp_buf)(*AppNr), (_AppNr_ndx * sizeof(brp_Desfire_GetDfNames_AppNr_Entry)));
			if((*AppNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*AppNr)[_AppNr_ndx-1] = *AppNr_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_Enable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_SetContrast(brp_protocol protocol, unsigned Contrast) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Contrast);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_EnableBacklight(brp_protocol protocol, bool EnableLight) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)EnableLight);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_Clear(brp_protocol protocol, bool DelPermanentDefines) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)DelPermanentDefines);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_Load(brp_protocol protocol, brp_buf PageDesc, size_t PageDesc_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write(_frame, (brp_buf)PageDesc, PageDesc_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Disp_Extend(brp_protocol protocol, brp_buf PageDesc, size_t PageDesc_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write(_frame, (brp_buf)PageDesc, PageDesc_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_DecodeCfg(brp_protocol protocol, brp_EM_DecodeCfg_RxMod RxMod, unsigned RxBaud) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)RxMod);
	brp_frame_write_int8(_frame, (unsigned)RxBaud);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Read4100(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Read4205(brp_protocol protocol, unsigned Address, unsigned* Page) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Page;
	if (Page == NULL) Page = &_tmp_Page;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Page) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Write4205(brp_protocol protocol, unsigned Address, unsigned Page) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_frame_write_int32(_frame, (unsigned)Page);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Halt4205(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Login4205(brp_protocol protocol, unsigned Password) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Password);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Protect4205(brp_protocol protocol, unsigned ProtectMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)ProtectMask);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Read4469(brp_protocol protocol, unsigned Address, unsigned* Page) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Page;
	if (Page == NULL) Page = &_tmp_Page;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 24);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Page) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Write4469(brp_protocol protocol, unsigned Address, unsigned Page) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 25);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_frame_write_int32(_frame, (unsigned)Page);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Halt4469(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Login4469(brp_protocol protocol, unsigned Password) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Password);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EM_Read4450(brp_protocol protocol, unsigned StartAdr, unsigned EndAdr, unsigned** PageNr, size_t* PageNr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _PageNr_len;
	if(PageNr_len == NULL) PageNr_len = &_PageNr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)StartAdr);
	brp_frame_write_int8(_frame, (unsigned)EndAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PageNr_len) = brp_frame_read_int8(&_reader);
	if (PageNr != NULL) {
		(*PageNr) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*PageNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _PageNr_ndx = 1;!((_PageNr_ndx > (*PageNr_len)) | brp_frame_read_err(&_reader));_PageNr_ndx++) {
		unsigned _Page;
		unsigned *Page = &_Page;
		(*Page) = (unsigned)brp_frame_read_int32(&_reader);
		if (PageNr != NULL) {
			(*PageNr) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*PageNr), (_PageNr_ndx * sizeof(unsigned)));
			if((*PageNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*PageNr)[_PageNr_ndx-1] = *Page;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_GetMacAdr(brp_protocol protocol, brp_buf* MAC, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _MAC_len = 6;
	size_t* MAC_len = &_MAC_len;
	if (MAC != NULL) {
		(*MAC) = (brp_buf)brp_mempool_create_buf(mempool, (*MAC_len));
		if((*MAC) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*MAC), (*MAC_len));
	} else
		brp_frame_skip(&_reader, (*MAC_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_GetConnDevIP(brp_protocol protocol, brp_buf* IP, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _IP_len = 4;
	size_t* IP_len = &_IP_len;
	if (IP != NULL) {
		(*IP) = (brp_buf)brp_mempool_create_buf(mempool, (*IP_len));
		if((*IP) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*IP), (*IP_len));
	} else
		brp_frame_skip(&_reader, (*IP_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_CreateRecoveryPoint(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_DelRecoveryPoint(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_GetNetworkStatus(brp_protocol protocol, unsigned* PortStatus, brp_buf* StaticIPAdr, brp_buf* StaticIPNetmask, brp_buf* StaticIPGateway, brp_buf* DHCPAdr, brp_buf* DHCPNetmask, brp_buf* DHCPGateway, brp_buf* LinkLocalAdr, brp_buf* LinkLocalNetmask, brp_buf* LinkLocalGateway, brp_buf* DNSAdr, brp_buf* HostAdr, unsigned* HostPort, unsigned* AutocloseTimeout, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_PortStatus;
	if (PortStatus == NULL) PortStatus = &_tmp_PortStatus;
	unsigned _tmp_HostPort;
	if (HostPort == NULL) HostPort = &_tmp_HostPort;
	unsigned _tmp_AutocloseTimeout;
	if (AutocloseTimeout == NULL) AutocloseTimeout = &_tmp_AutocloseTimeout;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PortStatus) = (unsigned)brp_frame_read_int8(&_reader);
	size_t _StaticIPAdr_len = 4;
	size_t* StaticIPAdr_len = &_StaticIPAdr_len;
	if (StaticIPAdr != NULL) {
		(*StaticIPAdr) = (brp_buf)brp_mempool_create_buf(mempool, (*StaticIPAdr_len));
		if((*StaticIPAdr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*StaticIPAdr), (*StaticIPAdr_len));
	} else
		brp_frame_skip(&_reader, (*StaticIPAdr_len));
	size_t _StaticIPNetmask_len = 4;
	size_t* StaticIPNetmask_len = &_StaticIPNetmask_len;
	if (StaticIPNetmask != NULL) {
		(*StaticIPNetmask) = (brp_buf)brp_mempool_create_buf(mempool, (*StaticIPNetmask_len));
		if((*StaticIPNetmask) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*StaticIPNetmask), (*StaticIPNetmask_len));
	} else
		brp_frame_skip(&_reader, (*StaticIPNetmask_len));
	size_t _StaticIPGateway_len = 4;
	size_t* StaticIPGateway_len = &_StaticIPGateway_len;
	if (StaticIPGateway != NULL) {
		(*StaticIPGateway) = (brp_buf)brp_mempool_create_buf(mempool, (*StaticIPGateway_len));
		if((*StaticIPGateway) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*StaticIPGateway), (*StaticIPGateway_len));
	} else
		brp_frame_skip(&_reader, (*StaticIPGateway_len));
	size_t _DHCPAdr_len = 4;
	size_t* DHCPAdr_len = &_DHCPAdr_len;
	if (DHCPAdr != NULL) {
		(*DHCPAdr) = (brp_buf)brp_mempool_create_buf(mempool, (*DHCPAdr_len));
		if((*DHCPAdr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*DHCPAdr), (*DHCPAdr_len));
	} else
		brp_frame_skip(&_reader, (*DHCPAdr_len));
	size_t _DHCPNetmask_len = 4;
	size_t* DHCPNetmask_len = &_DHCPNetmask_len;
	if (DHCPNetmask != NULL) {
		(*DHCPNetmask) = (brp_buf)brp_mempool_create_buf(mempool, (*DHCPNetmask_len));
		if((*DHCPNetmask) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*DHCPNetmask), (*DHCPNetmask_len));
	} else
		brp_frame_skip(&_reader, (*DHCPNetmask_len));
	size_t _DHCPGateway_len = 4;
	size_t* DHCPGateway_len = &_DHCPGateway_len;
	if (DHCPGateway != NULL) {
		(*DHCPGateway) = (brp_buf)brp_mempool_create_buf(mempool, (*DHCPGateway_len));
		if((*DHCPGateway) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*DHCPGateway), (*DHCPGateway_len));
	} else
		brp_frame_skip(&_reader, (*DHCPGateway_len));
	size_t _LinkLocalAdr_len = 4;
	size_t* LinkLocalAdr_len = &_LinkLocalAdr_len;
	if (LinkLocalAdr != NULL) {
		(*LinkLocalAdr) = (brp_buf)brp_mempool_create_buf(mempool, (*LinkLocalAdr_len));
		if((*LinkLocalAdr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LinkLocalAdr), (*LinkLocalAdr_len));
	} else
		brp_frame_skip(&_reader, (*LinkLocalAdr_len));
	size_t _LinkLocalNetmask_len = 4;
	size_t* LinkLocalNetmask_len = &_LinkLocalNetmask_len;
	if (LinkLocalNetmask != NULL) {
		(*LinkLocalNetmask) = (brp_buf)brp_mempool_create_buf(mempool, (*LinkLocalNetmask_len));
		if((*LinkLocalNetmask) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LinkLocalNetmask), (*LinkLocalNetmask_len));
	} else
		brp_frame_skip(&_reader, (*LinkLocalNetmask_len));
	size_t _LinkLocalGateway_len = 4;
	size_t* LinkLocalGateway_len = &_LinkLocalGateway_len;
	if (LinkLocalGateway != NULL) {
		(*LinkLocalGateway) = (brp_buf)brp_mempool_create_buf(mempool, (*LinkLocalGateway_len));
		if((*LinkLocalGateway) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LinkLocalGateway), (*LinkLocalGateway_len));
	} else
		brp_frame_skip(&_reader, (*LinkLocalGateway_len));
	size_t _DNSAdr_len = 4;
	size_t* DNSAdr_len = &_DNSAdr_len;
	if (DNSAdr != NULL) {
		(*DNSAdr) = (brp_buf)brp_mempool_create_buf(mempool, (*DNSAdr_len));
		if((*DNSAdr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*DNSAdr), (*DNSAdr_len));
	} else
		brp_frame_skip(&_reader, (*DNSAdr_len));
	size_t _HostAdr_len = 4;
	size_t* HostAdr_len = &_HostAdr_len;
	if (HostAdr != NULL) {
		(*HostAdr) = (brp_buf)brp_mempool_create_buf(mempool, (*HostAdr_len));
		if((*HostAdr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*HostAdr), (*HostAdr_len));
	} else
		brp_frame_skip(&_reader, (*HostAdr_len));
	(*HostPort) = (unsigned)brp_frame_read_int16(&_reader);
	(*AutocloseTimeout) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_GetMIBCounters(brp_protocol protocol, unsigned Port, unsigned** MIBCounterList, size_t* MIBCounterList_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _MIBCounterList_len;
	if(MIBCounterList_len == NULL) MIBCounterList_len = &_MIBCounterList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MIBCounterList_len) = brp_frame_read_int8(&_reader);
	if (MIBCounterList != NULL) {
		(*MIBCounterList) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*MIBCounterList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _MIBCounterList_ndx = 1;!((_MIBCounterList_ndx > (*MIBCounterList_len)) | brp_frame_read_err(&_reader));_MIBCounterList_ndx++) {
		unsigned _Value;
		unsigned *Value = &_Value;
		(*Value) = (unsigned)brp_frame_read_int32(&_reader);
		if (MIBCounterList != NULL) {
			(*MIBCounterList) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*MIBCounterList), (_MIBCounterList_ndx * sizeof(unsigned)));
			if((*MIBCounterList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*MIBCounterList)[_MIBCounterList_ndx-1] = *Value;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_GetTcpConnectionStatus(brp_protocol protocol, brp_Eth_GetTcpConnectionStatus_Status* Status) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _Status_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Eth_GetTcpConnectionStatus_Status_is_valid(_Status_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (Status != NULL)
		(*Status) = (brp_Eth_GetTcpConnectionStatus_Status)_Status_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_OpenTcpConnection(brp_protocol protocol, brp_Eth_OpenTcpConnection_ConnectionReason ConnectionReason) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)ConnectionReason);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Eth_CloseTcpConnection(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Felica_GenericCmd(brp_protocol protocol, brp_Felica_GenericCmd_FastBaud FastBaud, unsigned Cmd, brp_buf Param, size_t Param_len, unsigned Timeout, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 28);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FastBaud);
	brp_frame_write_int8(_frame, (unsigned)Cmd);
	brp_frame_write_int8(_frame, (unsigned)Param_len);
	brp_frame_write(_frame, (brp_buf)Param, Param_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Resp_len) = brp_frame_read_int8(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Felica_SetUID2(brp_protocol protocol, brp_buf UID2) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 28);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	size_t UID2_len = 8;
	brp_frame_write(_frame, (brp_buf)UID2, UID2_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Felica_Request(brp_protocol protocol, brp_Felica_Request_FastBaud FastBaud, unsigned SystemCode, unsigned RequestCode, unsigned* ColFlag, brp_Felica_Request_Labels_Entry** Labels, size_t* Labels_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Labels_len;
	if(Labels_len == NULL) Labels_len = &_Labels_len;
	unsigned _tmp_ColFlag;
	if (ColFlag == NULL) ColFlag = &_tmp_ColFlag;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 28);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FastBaud);
	brp_frame_write_int16(_frame, (unsigned)SystemCode);
	brp_frame_write_int8(_frame, (unsigned)RequestCode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ColFlag) = (unsigned)brp_frame_read_int8(&_reader);
	(*Labels_len) = brp_frame_read_int8(&_reader);
	if (Labels != NULL) {
		(*Labels) = (brp_Felica_Request_Labels_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*Labels) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Labels_ndx = 1;!((_Labels_ndx > (*Labels_len)) | brp_frame_read_err(&_reader));_Labels_ndx++) {
		brp_Felica_Request_Labels_Entry _Labels_Entry;
		brp_Felica_Request_Labels_Entry *Labels_Entry = &_Labels_Entry;
		brp_buf _NFCID;
		brp_buf *NFCID = &_NFCID;
		size_t _NFCID_len;
		size_t *NFCID_len = &_NFCID_len;
		(*NFCID_len) = brp_frame_read_int8(&_reader);
		if (NFCID != NULL) {
			(*NFCID) = (brp_buf)brp_mempool_create_buf(mempool, (*NFCID_len));
			if((*NFCID) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*NFCID), (*NFCID_len));
		} else
			brp_frame_skip(&_reader, (*NFCID_len));
		if(Labels_Entry != NULL) {
			Labels_Entry->NFCID = *NFCID;
			Labels_Entry->NFCID_len = *NFCID_len;
		}
		if (Labels != NULL) {
			(*Labels) = (brp_Felica_Request_Labels_Entry*)brp_mempool_resize_buf((brp_buf)(*Labels), (_Labels_ndx * sizeof(brp_Felica_Request_Labels_Entry)));
			if((*Labels) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Labels)[_Labels_ndx-1] = *Labels_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_GetMemoryInfo(brp_protocol protocol, unsigned* TotalMem, unsigned* FreeMem) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_TotalMem;
	if (TotalMem == NULL) TotalMem = &_tmp_TotalMem;
	unsigned _tmp_FreeMem;
	if (FreeMem == NULL) FreeMem = &_tmp_FreeMem;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*TotalMem) = (unsigned)brp_frame_read_int32(&_reader);
	(*FreeMem) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_Format(brp_protocol protocol, bool QuickFormat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 5000);
	brp_frame_write_int8(_frame, (unsigned)QuickFormat);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_CreateFile(brp_protocol protocol, unsigned FileId, unsigned RecordSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_frame_write_int8(_frame, (unsigned)RecordSize);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_DeleteFile(brp_protocol protocol, unsigned FileId) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_RenameFile(brp_protocol protocol, unsigned FileId, unsigned NewFileId) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_frame_write_int16(_frame, (unsigned)NewFileId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_GetRecordSize(brp_protocol protocol, unsigned FileId, unsigned* RecordSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_RecordSize;
	if (RecordSize == NULL) RecordSize = &_tmp_RecordSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecordSize) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_GetFileSize(brp_protocol protocol, unsigned FileId, unsigned* FileSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_FileSize;
	if (FileSize == NULL) FileSize = &_tmp_FileSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FileSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_ReadRecords(brp_protocol protocol, unsigned FileId, unsigned StartRecord, unsigned RecordCount, brp_FlashFS_ReadRecords_RecordList_Entry** RecordList, size_t* RecordList_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecordList_len;
	if(RecordList_len == NULL) RecordList_len = &_RecordList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_frame_write_int16(_frame, (unsigned)StartRecord);
	brp_frame_write_int16(_frame, (unsigned)RecordCount);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecordList_len) = brp_frame_read_int16(&_reader);
	if (RecordList != NULL) {
		(*RecordList) = (brp_FlashFS_ReadRecords_RecordList_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*RecordList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _RecordList_ndx = 1;!((_RecordList_ndx > (*RecordList_len)) | brp_frame_read_err(&_reader));_RecordList_ndx++) {
		brp_FlashFS_ReadRecords_RecordList_Entry _RecordList_Entry;
		brp_FlashFS_ReadRecords_RecordList_Entry *RecordList_Entry = &_RecordList_Entry;
		brp_buf _Record;
		brp_buf *Record = &_Record;
		size_t _Record_len;
		size_t *Record_len = &_Record_len;
		(*Record_len) = brp_frame_read_int8(&_reader);
		if (Record != NULL) {
			(*Record) = (brp_buf)brp_mempool_create_buf(mempool, (*Record_len));
			if((*Record) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*Record), (*Record_len));
		} else
			brp_frame_skip(&_reader, (*Record_len));
		if(RecordList_Entry != NULL) {
			RecordList_Entry->Record = *Record;
			RecordList_Entry->Record_len = *Record_len;
		}
		if (RecordList != NULL) {
			(*RecordList) = (brp_FlashFS_ReadRecords_RecordList_Entry*)brp_mempool_resize_buf((brp_buf)(*RecordList), (_RecordList_ndx * sizeof(brp_FlashFS_ReadRecords_RecordList_Entry)));
			if((*RecordList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*RecordList)[_RecordList_ndx-1] = *RecordList_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_FlashFS_WriteRecords(brp_protocol protocol, unsigned FileId, unsigned StartRecord, brp_FlashFS_WriteRecords_RecordList_Entry* RecordList, size_t RecordList_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 73);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)FileId);
	brp_frame_write_int16(_frame, (unsigned)StartRecord);
	brp_frame_write_int16(_frame, (unsigned)RecordList_len);
	for(size_t _RecordList_ndx = 0;_RecordList_ndx < RecordList_len;_RecordList_ndx++) {
		brp_FlashFS_WriteRecords_RecordList_Entry RecordList_Entry = RecordList[_RecordList_ndx];
		brp_buf Record = RecordList_Entry.Record;
		size_t Record_len = RecordList_Entry.Record_len;
		brp_frame_write_int8(_frame, (unsigned)Record_len);
		brp_frame_write(_frame, (brp_buf)Record, Record_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ftob_OpenReadFile(brp_protocol protocol, brp_buf Filename, size_t Filename_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)Filename_len);
	brp_frame_write(_frame, (brp_buf)Filename, Filename_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ftob_OpenWriteFile(brp_protocol protocol, brp_buf Filename, size_t Filename_len, unsigned* MaxBlockLen) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_MaxBlockLen;
	if (MaxBlockLen == NULL) MaxBlockLen = &_tmp_MaxBlockLen;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)Filename_len);
	brp_frame_write(_frame, (brp_buf)Filename, Filename_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MaxBlockLen) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ftob_ReadFileBlock(brp_protocol protocol, bool ToggleBit, unsigned MaxBlockLength, brp_buf* BlockData, size_t* BlockData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _BlockData_len;
	if(BlockData_len == NULL) BlockData_len = &_BlockData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)ToggleBit);
	brp_frame_write_int16(_frame, (unsigned)MaxBlockLength);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*BlockData_len) = brp_frame_read_int16(&_reader);
	if (BlockData != NULL) {
		(*BlockData) = (brp_buf)brp_mempool_create_buf(mempool, (*BlockData_len));
		if((*BlockData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*BlockData), (*BlockData_len));
	} else
		brp_frame_skip(&_reader, (*BlockData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ftob_WriteFileBlock(brp_protocol protocol, bool ToggleBit, brp_buf BlockData, size_t BlockData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)ToggleBit);
	brp_frame_write_int16(_frame, (unsigned)BlockData_len);
	brp_frame_write(_frame, (brp_buf)BlockData, BlockData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ftob_CloseFile(brp_protocol protocol, bool Success) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)Success);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_IndalaRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_ProxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_AwidRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_IoProxRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_Prox32Read(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_PyramidRead(brp_protocol protocol, unsigned* Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	unsigned _tmp_Len;
	if (Len == NULL) Len = &_tmp_Len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Len) = (unsigned)brp_frame_read_int8(&_reader);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_IndalaSecureRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_HID_IdteckRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_Request(brp_protocol protocol, brp_Hitag_Request_TagType TagType, brp_Hitag_Request_Mode Mode, unsigned* Snr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Snr;
	if (Snr == NULL) Snr = &_tmp_Snr;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)TagType);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Snr) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_Select(brp_protocol protocol, brp_Hitag_Select_SelMode SelMode, unsigned Pwd, unsigned* Page1) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Page1;
	if (Page1 == NULL) Page1 = &_tmp_Page1;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SelMode);
	if((SelMode) == (brp_Hitag_Select_SelMode_H2AuthOnlyPwd)) {
		brp_frame_write_int32(_frame, (unsigned)Pwd);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Page1) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_Halt(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_Read(brp_protocol protocol, unsigned Address, bool InvRead, bool KeyB, bool Encrypt, bool BlockRead, unsigned** PageNr, size_t* PageNr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _PageNr_len;
	if(PageNr_len == NULL) PageNr_len = &_PageNr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	unsigned bitmask_1772207085200 = 0;
	bitmask_1772207085200 |= (InvRead & 0b1) << 3;
	bitmask_1772207085200 |= (KeyB & 0b1) << 2;
	bitmask_1772207085200 |= (Encrypt & 0b1) << 1;
	bitmask_1772207085200 |= (BlockRead & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207085200);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PageNr_len) = brp_frame_read_int8(&_reader);
	if (PageNr != NULL) {
		(*PageNr) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*PageNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _PageNr_ndx = 1;!((_PageNr_ndx > (*PageNr_len)) | brp_frame_read_err(&_reader));_PageNr_ndx++) {
		unsigned _Page;
		unsigned *Page = &_Page;
		(*Page) = (unsigned)brp_frame_read_int32(&_reader);
		if (PageNr != NULL) {
			(*PageNr) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*PageNr), (_PageNr_ndx * sizeof(unsigned)));
			if((*PageNr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*PageNr)[_PageNr_ndx-1] = *Page;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_Write(brp_protocol protocol, unsigned Address, bool KeyB, bool Encrypt, bool BlockWrite, unsigned* PageNr, size_t PageNr_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	unsigned bitmask_1772207085824 = 0;
	bitmask_1772207085824 |= (KeyB & 0b1) << 2;
	bitmask_1772207085824 |= (Encrypt & 0b1) << 1;
	bitmask_1772207085824 |= (BlockWrite & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207085824);
	brp_frame_write_int8(_frame, (unsigned)PageNr_len);
	for(size_t _PageNr_ndx = 0;_PageNr_ndx < PageNr_len;_PageNr_ndx++) {
		unsigned Page = PageNr[_PageNr_ndx];
		brp_frame_write_int32(_frame, (unsigned)Page);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Hitag_PersonaliseHtg(brp_protocol protocol, bool Reset, bool HtgS, unsigned* Len, size_t Len_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 48);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207086304 = 0;
	bitmask_1772207086304 |= (Reset & 0b1) << 1;
	bitmask_1772207086304 |= (HtgS & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207086304);
	brp_frame_write_int8(_frame, (unsigned)Len_len);
	for(size_t _Len_ndx = 0;_Len_ndx < Len_len;_Len_ndx++) {
		unsigned Data = Len[_Len_ndx];
		brp_frame_write_int32(_frame, (unsigned)Data);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I2c_SetSpeed(brp_protocol protocol, bool FastMode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FastMode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I2c_Read(brp_protocol protocol, unsigned Address, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_frame_write_int8(_frame, (unsigned)ReadLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int8(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I2c_Write(brp_protocol protocol, unsigned Address, brp_buf WriteData, size_t WriteData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_frame_write_int8(_frame, (unsigned)WriteData_len);
	brp_frame_write(_frame, (brp_buf)WriteData, WriteData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I2c_TxRx(brp_protocol protocol, unsigned Address, brp_buf CmdData, size_t CmdData_len, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_frame_write_int8(_frame, (unsigned)CmdData_len);
	brp_frame_write(_frame, (brp_buf)CmdData, CmdData_len);
	brp_frame_write_int8(_frame, (unsigned)ReadLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int8(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_RequestLegacy(brp_protocol protocol, bool ReqAll, brp_Iso14a_RequestLegacy_UIDSize* UIDSize, unsigned* Coll, unsigned* ProprietaryCoding) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207088560 = 0;
	bitmask_1772207088560 |= (ReqAll & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207088560);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned bitmask_1772207088752 = brp_frame_read_int16(&_reader);
	if(UIDSize != NULL)
		(*UIDSize) = (bitmask_1772207088752>>14) & 0b11;
	if(Coll != NULL)
		(*Coll) = (bitmask_1772207088752>>8) & 0b11111;
	if(ProprietaryCoding != NULL)
		(*ProprietaryCoding) = (bitmask_1772207088752>>0) & 0b1111;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_Select(brp_protocol protocol, unsigned CascLev, unsigned BitCount, brp_buf PreSelSer, size_t PreSelSer_len, unsigned* SAK, brp_buf* Serial, size_t* Serial_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Serial_len;
	if(Serial_len == NULL) Serial_len = &_Serial_len;
	unsigned _tmp_SAK;
	if (SAK == NULL) SAK = &_tmp_SAK;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CascLev);
	brp_frame_write_int8(_frame, (unsigned)BitCount);
	brp_frame_write(_frame, (brp_buf)PreSelSer, PreSelSer_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SAK) = (unsigned)brp_frame_read_int8(&_reader);
	(*Serial_len) = brp_frame_read_int8(&_reader);
	if (Serial != NULL) {
		(*Serial) = (brp_buf)brp_mempool_create_buf(mempool, (*Serial_len));
		if((*Serial) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Serial), (*Serial_len));
	} else
		brp_frame_skip(&_reader, (*Serial_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_Halt(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_RequestATS(brp_protocol protocol, brp_Iso14a_RequestATS_FSDI FSDI, unsigned CID, brp_buf* ATS, size_t* ATS_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ATS_len;
	if(ATS_len == NULL) ATS_len = &_ATS_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207089856 = 0;
	bitmask_1772207089856 |= (FSDI & 0b1111) << 4;
	bitmask_1772207089856 |= (CID & 0b1111) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207089856);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ATS_len) = brp_frame_rest( & _reader);
	if (ATS != NULL) {
		(*ATS) = (brp_buf)brp_mempool_create_buf(mempool, (*ATS_len));
		if((*ATS) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATS), (*ATS_len));
	} else
		brp_frame_skip(&_reader, (*ATS_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_PerformPPS(brp_protocol protocol, unsigned CID, brp_DivisorInteger DSI, brp_DivisorInteger DRI) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CID);
	unsigned bitmask_1772207090720 = 0;
	bitmask_1772207090720 |= (DSI & 0b11) << 2;
	bitmask_1772207090720 |= (DRI & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207090720);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_Request(brp_protocol protocol, bool ReqAll, brp_buf* ATQA, bool* Collision, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	bool _tmp_Collision;
	if (Collision == NULL) Collision = &_tmp_Collision;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207091440 = 0;
	bitmask_1772207091440 |= (ReqAll & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207091440);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _ATQA_len = 2;
	size_t* ATQA_len = &_ATQA_len;
	if (ATQA != NULL) {
		(*ATQA) = (brp_buf)brp_mempool_create_buf(mempool, (*ATQA_len));
		if((*ATQA) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATQA), (*ATQA_len));
	} else
		brp_frame_skip(&_reader, (*ATQA_len));
	(*Collision) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelectedSnr, brp_buf* SelectedSnr, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 24);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BitCount);
	size_t PreSelectedSnr_len = 4;
	brp_frame_write(_frame, (brp_buf)PreSelectedSnr, PreSelectedSnr_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _SelectedSnr_len = 4;
	size_t* SelectedSnr_len = &_SelectedSnr_len;
	if (SelectedSnr != NULL) {
		(*SelectedSnr) = (brp_buf)brp_mempool_create_buf(mempool, (*SelectedSnr_len));
		if((*SelectedSnr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*SelectedSnr), (*SelectedSnr_len));
	} else
		brp_frame_skip(&_reader, (*SelectedSnr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_SelectOnly(brp_protocol protocol, brp_buf Snr, unsigned* SAK) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_SAK;
	if (SAK == NULL) SAK = &_tmp_SAK;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 25);
	brp_frame_write_int32(_frame, 100);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SAK) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_TransparentCmd(brp_protocol protocol, bool EnMifBwProt, bool EnBitmode, bool EnCRCRX, bool EnCRCTX, bool ParityMode, bool EnParity, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, brp_buf* RcvData, size_t* RcvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RcvData_len;
	if(RcvData_len == NULL) RcvData_len = &_RcvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207092496 = 0;
	bitmask_1772207092496 |= (EnMifBwProt & 0b1) << 7;
	bitmask_1772207092496 |= (EnBitmode & 0b1) << 4;
	bitmask_1772207092496 |= (EnCRCRX & 0b1) << 3;
	bitmask_1772207092496 |= (EnCRCTX & 0b1) << 2;
	bitmask_1772207092496 |= (ParityMode & 0b1) << 1;
	bitmask_1772207092496 |= (EnParity & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207092496);
	brp_frame_write_int16(_frame, (unsigned)SendDataLen);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	unsigned bitmask_1772207092976 = 0;
	bitmask_1772207092976 |= (DSI & 0b11) << 2;
	bitmask_1772207092976 |= (DRI & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207092976);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RcvData_len) = brp_frame_read_int16(&_reader);
	if (RcvData != NULL) {
		(*RcvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RcvData_len));
		if((*RcvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RcvData), (*RcvData_len));
	} else
		brp_frame_skip(&_reader, (*RcvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14a_TransparentCmdBitlen(brp_protocol protocol, bool EnHighBaudOld, bool EnParTx, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, unsigned* RecvDataLen, unsigned* CollisionPosition, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	unsigned _tmp_RecvDataLen;
	if (RecvDataLen == NULL) RecvDataLen = &_tmp_RecvDataLen;
	unsigned _tmp_CollisionPosition;
	if (CollisionPosition == NULL) CollisionPosition = &_tmp_CollisionPosition;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int8(_frame, 35);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207093840 = 0;
	bitmask_1772207093840 |= (EnHighBaudOld & 0b1) << 6;
	bitmask_1772207093840 |= (EnParTx & 0b1) << 5;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207093840);
	brp_frame_write_int16(_frame, (unsigned)SendDataLen);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	unsigned bitmask_1772207094176 = 0;
	bitmask_1772207094176 |= (DSI & 0b11) << 2;
	bitmask_1772207094176 |= (DRI & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207094176);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvDataLen) = (unsigned)brp_frame_read_int16(&_reader);
	(*CollisionPosition) = (unsigned)brp_frame_read_int16(&_reader);
	(*RecvData_len) = brp_frame_rest( & _reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_Request(brp_protocol protocol, bool ReqAll, brp_Iso14b_Request_TimeSlots TimeSlots, unsigned AFI, brp_Iso14b_Request_ValueList_Entry** ValueList, size_t* ValueList_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ValueList_len;
	if(ValueList_len == NULL) ValueList_len = &_ValueList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207095712 = 0;
	bitmask_1772207095712 |= (ReqAll & 0b1) << 3;
	bitmask_1772207095712 |= (TimeSlots & 0b111) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207095712);
	brp_frame_write_int8(_frame, (unsigned)AFI);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ValueList_len) = brp_frame_read_int8(&_reader);
	if (ValueList != NULL) {
		(*ValueList) = (brp_Iso14b_Request_ValueList_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*ValueList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _ValueList_ndx = 1;!((_ValueList_ndx > (*ValueList_len)) | brp_frame_read_err(&_reader));_ValueList_ndx++) {
		brp_Iso14b_Request_ValueList_Entry _ValueList_Entry;
		brp_Iso14b_Request_ValueList_Entry *ValueList_Entry = &_ValueList_Entry;
		brp_buf _PUPI;
		brp_buf *PUPI = &_PUPI;
		brp_buf _AppData;
		brp_buf *AppData = &_AppData;
		unsigned _Synced;
		unsigned *Synced = &_Synced;
		unsigned _Send848;
		unsigned *Send848 = &_Send848;
		unsigned _Send424;
		unsigned *Send424 = &_Send424;
		unsigned _Send212;
		unsigned *Send212 = &_Send212;
		unsigned _Recv848;
		unsigned *Recv848 = &_Recv848;
		unsigned _Recv424;
		unsigned *Recv424 = &_Recv424;
		unsigned _Recv212;
		unsigned *Recv212 = &_Recv212;
		brp_Iso14b_Request_FSCI _FSCI;
		brp_Iso14b_Request_FSCI *FSCI = &_FSCI;
		brp_Iso14b_Request_ProtType _ProtType;
		brp_Iso14b_Request_ProtType *ProtType = &_ProtType;
		brp_Iso14b_Request_FWI _FWI;
		brp_Iso14b_Request_FWI *FWI = &_FWI;
		unsigned _ADC;
		unsigned *ADC = &_ADC;
		unsigned _CID;
		unsigned *CID = &_CID;
		unsigned _NAD;
		unsigned *NAD = &_NAD;
		size_t _PUPI_len = 4;
		size_t* PUPI_len = &_PUPI_len;
		if (PUPI != NULL) {
			(*PUPI) = (brp_buf)brp_mempool_create_buf(mempool, (*PUPI_len));
			if((*PUPI) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*PUPI), (*PUPI_len));
		} else
			brp_frame_skip(&_reader, (*PUPI_len));
		size_t _AppData_len = 4;
		size_t* AppData_len = &_AppData_len;
		if (AppData != NULL) {
			(*AppData) = (brp_buf)brp_mempool_create_buf(mempool, (*AppData_len));
			if((*AppData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*AppData), (*AppData_len));
		} else
			brp_frame_skip(&_reader, (*AppData_len));
		unsigned bitmask_1772206883504 = brp_frame_read_int8(&_reader);
		if(Synced != NULL)
			(*Synced) = (bitmask_1772206883504>>7) & 0b1;
		if(Send848 != NULL)
			(*Send848) = (bitmask_1772206883504>>6) & 0b1;
		if(Send424 != NULL)
			(*Send424) = (bitmask_1772206883504>>5) & 0b1;
		if(Send212 != NULL)
			(*Send212) = (bitmask_1772206883504>>4) & 0b1;
		if(Recv848 != NULL)
			(*Recv848) = (bitmask_1772206883504>>2) & 0b1;
		if(Recv424 != NULL)
			(*Recv424) = (bitmask_1772206883504>>1) & 0b1;
		if(Recv212 != NULL)
			(*Recv212) = (bitmask_1772206883504>>0) & 0b1;
		unsigned bitmask_1772206883552 = brp_frame_read_int16(&_reader);
		if(FSCI != NULL)
			(*FSCI) = (bitmask_1772206883552>>12) & 0b1111;
		if(ProtType != NULL)
			(*ProtType) = (bitmask_1772206883552>>8) & 0b1111;
		if(FWI != NULL)
			(*FWI) = (bitmask_1772206883552>>4) & 0b1111;
		if(ADC != NULL)
			(*ADC) = (bitmask_1772206883552>>2) & 0b11;
		if(CID != NULL)
			(*CID) = (bitmask_1772206883552>>1) & 0b1;
		if(NAD != NULL)
			(*NAD) = (bitmask_1772206883552>>0) & 0b1;
		if(ValueList_Entry != NULL) {
			ValueList_Entry->PUPI = *PUPI;
			ValueList_Entry->AppData = *AppData;
			ValueList_Entry->Synced = *Synced;
			ValueList_Entry->Send848 = *Send848;
			ValueList_Entry->Send424 = *Send424;
			ValueList_Entry->Send212 = *Send212;
			ValueList_Entry->Recv848 = *Recv848;
			ValueList_Entry->Recv424 = *Recv424;
			ValueList_Entry->Recv212 = *Recv212;
			ValueList_Entry->FSCI = *FSCI;
			ValueList_Entry->ProtType = *ProtType;
			ValueList_Entry->FWI = *FWI;
			ValueList_Entry->ADC = *ADC;
			ValueList_Entry->CID = *CID;
			ValueList_Entry->NAD = *NAD;
		}
		if (ValueList != NULL) {
			(*ValueList) = (brp_Iso14b_Request_ValueList_Entry*)brp_mempool_resize_buf((brp_buf)(*ValueList), (_ValueList_ndx * sizeof(brp_Iso14b_Request_ValueList_Entry)));
			if((*ValueList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*ValueList)[_ValueList_ndx-1] = *ValueList_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_Attrib(brp_protocol protocol, brp_buf PUPI, brp_Iso14b_Attrib_TR0 TR0, brp_Iso14b_Attrib_TR1 TR1, brp_Iso14b_Attrib_EOF_ EOF_, brp_Iso14b_Attrib_SOF SOF, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_Iso14b_Attrib_FSDI FSDI, unsigned CID, bool EnHLR, bool EnMBLI, bool EnCID, unsigned* AssignedCID, unsigned* MBLI, brp_buf* HLR, size_t* HLR_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _HLR_len;
	if(HLR_len == NULL) HLR_len = &_HLR_len;
	unsigned _tmp_AssignedCID;
	if (AssignedCID == NULL) AssignedCID = &_tmp_AssignedCID;
	unsigned _tmp_MBLI;
	if (MBLI == NULL) MBLI = &_tmp_MBLI;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	size_t PUPI_len = 4;
	brp_frame_write(_frame, (brp_buf)PUPI, PUPI_len);
	unsigned bitmask_1772206885664 = 0;
	bitmask_1772206885664 |= (TR0 & 0b11) << 22;
	bitmask_1772206885664 |= (TR1 & 0b11) << 20;
	bitmask_1772206885664 |= (EOF_ & 0b1) << 19;
	bitmask_1772206885664 |= (SOF & 0b1) << 18;
	bitmask_1772206885664 |= (DSI & 0b11) << 14;
	bitmask_1772206885664 |= (DRI & 0b11) << 12;
	bitmask_1772206885664 |= (FSDI & 0b1111) << 8;
	brp_frame_write_int24(_frame, (unsigned)bitmask_1772206885664);
	brp_frame_write_int8(_frame, (unsigned)CID);
	unsigned bitmask_1772206887536 = 0;
	bitmask_1772206887536 |= (EnHLR & 0b1) << 2;
	bitmask_1772206887536 |= (EnMBLI & 0b1) << 1;
	bitmask_1772206887536 |= (EnCID & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206887536);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(EnCID) {
		(*AssignedCID) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(EnMBLI) {
		(*MBLI) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(EnHLR) {
		(*HLR_len) = brp_frame_read_int8(&_reader);
		if (HLR != NULL) {
			(*HLR) = (brp_buf)brp_mempool_create_buf(mempool, (*HLR_len));
			if((*HLR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*HLR), (*HLR_len));
		} else
			brp_frame_skip(&_reader, (*HLR_len));
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_Halt(brp_protocol protocol, brp_buf PUPI) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	size_t PUPI_len = 4;
	brp_frame_write(_frame, (brp_buf)PUPI, PUPI_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_SetTransparentSettings(brp_protocol protocol, brp_Iso14b_SetTransparentSettings_Tags_Entry* Tags, size_t Tags_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int32(_frame, 100);
	for(size_t _Tags_ndx = 0;_Tags_ndx < Tags_len;_Tags_ndx++) {
		brp_Iso14b_SetTransparentSettings_Tags_Entry Tags_Entry = Tags[_Tags_ndx];
		unsigned ID = Tags_Entry.ID;
		unsigned Value = Tags_Entry.Value;
		brp_frame_write_int8(_frame, (unsigned)ID);
		brp_frame_write_int8(_frame, (unsigned)Value);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_GetTransparentSettings(brp_protocol protocol, brp_Iso14b_GetTransparentSettings_Tags_Entry** Tags, size_t* Tags_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Tags_len;
	if(Tags_len == NULL) Tags_len = &_Tags_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Tags_len) = brp_frame_rest( & _reader);
	if (Tags != NULL) {
		(*Tags) = (brp_Iso14b_GetTransparentSettings_Tags_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*Tags) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Tags_ndx = 1;!(brp_frame_read_eof(&_reader) | brp_frame_read_err(&_reader));_Tags_ndx++) {
		brp_Iso14b_GetTransparentSettings_Tags_Entry _Tags_Entry;
		brp_Iso14b_GetTransparentSettings_Tags_Entry *Tags_Entry = &_Tags_Entry;
		unsigned _ID;
		unsigned *ID = &_ID;
		unsigned _Value;
		unsigned *Value = &_Value;
		(*ID) = (unsigned)brp_frame_read_int8(&_reader);
		(*Value) = (unsigned)brp_frame_read_int8(&_reader);
		if(Tags_Entry != NULL) {
			Tags_Entry->ID = *ID;
			Tags_Entry->Value = *Value;
		}
		if (Tags != NULL) {
			(*Tags) = (brp_Iso14b_GetTransparentSettings_Tags_Entry*)brp_mempool_resize_buf((brp_buf)(*Tags), (_Tags_ndx * sizeof(brp_Iso14b_GetTransparentSettings_Tags_Entry)));
			if((*Tags) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Tags)[_Tags_ndx-1] = *Tags_Entry;
		}
		(*Tags_len) = _Tags_ndx;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14b_TransparentCmd(brp_protocol protocol, unsigned EnCRCRX, unsigned EnCRCTX, unsigned SendDataLen, unsigned Timeout, brp_DivisorInteger DSI, brp_DivisorInteger DRI, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772206888928 = 0;
	bitmask_1772206888928 |= (EnCRCRX & 0b1) << 1;
	bitmask_1772206888928 |= (EnCRCTX & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206888928);
	brp_frame_write_int16(_frame, (unsigned)SendDataLen);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	unsigned bitmask_1772206889216 = 0;
	bitmask_1772206889216 |= (DSI & 0b11) << 2;
	bitmask_1772206889216 |= (DRI & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206889216);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14L4_SetupAPDU(brp_protocol protocol, bool EnDefault, unsigned ToggleAB, bool EnNAD, bool EnCID, unsigned CID, unsigned NAD, brp_Iso14L4_SetupAPDU_FSCI FSCI, brp_Iso14L4_SetupAPDU_FWI FWI, brp_DivisorInteger DSI, brp_DivisorInteger DRI) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772206890368 = 0;
	bitmask_1772206890368 |= (EnDefault & 0b1) << 3;
	bitmask_1772206890368 |= (ToggleAB & 0b1) << 2;
	bitmask_1772206890368 |= (EnNAD & 0b1) << 1;
	bitmask_1772206890368 |= (EnCID & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206890368);
	brp_frame_write_int8(_frame, (unsigned)CID);
	brp_frame_write_int8(_frame, (unsigned)NAD);
	unsigned bitmask_1772206890752 = 0;
	bitmask_1772206890752 |= (FSCI & 0b1111) << 12;
	bitmask_1772206890752 |= (FWI & 0b1111) << 8;
	bitmask_1772206890752 |= (DSI & 0b11) << 2;
	bitmask_1772206890752 |= (DRI & 0b11) << 0;
	brp_frame_write_int16(_frame, (unsigned)bitmask_1772206890752);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14L4_ExchangeAPDU(brp_protocol protocol, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 60000);
	brp_frame_write_int16(_frame, (unsigned)SendData_len);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14L4_Deselect(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 2000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I4CE_StartEmu(brp_protocol protocol, brp_buf Snr, unsigned FWT, unsigned TimeoutPCD, unsigned TimeoutAPDU, brp_buf ATS, size_t ATS_len, unsigned AutoWTX, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _FirstCmd_len;
	if(FirstCmd_len == NULL) FirstCmd_len = &_FirstCmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 72);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 1000);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_frame_write_int16(_frame, (unsigned)FWT);
	brp_frame_write_int16(_frame, (unsigned)TimeoutPCD);
	brp_frame_write_int16(_frame, (unsigned)TimeoutAPDU);
	brp_frame_write_int8(_frame, (unsigned)ATS_len);
	brp_frame_write(_frame, (brp_buf)ATS, ATS_len);
	brp_frame_write_int8(_frame, (unsigned)AutoWTX);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FirstCmd_len) = brp_frame_read_int16(&_reader);
	if (FirstCmd != NULL) {
		(*FirstCmd) = (brp_buf)brp_mempool_create_buf(mempool, (*FirstCmd_len));
		if((*FirstCmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*FirstCmd), (*FirstCmd_len));
	} else
		brp_frame_skip(&_reader, (*FirstCmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I4CE_ExchangeInverseAPDU(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Cmd_len;
	if(Cmd_len == NULL) Cmd_len = &_Cmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 72);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)Rsp_len);
	brp_frame_write(_frame, (brp_buf)Rsp, Rsp_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Cmd_len) = brp_frame_read_int16(&_reader);
	if (Cmd != NULL) {
		(*Cmd) = (brp_buf)brp_mempool_create_buf(mempool, (*Cmd_len));
		if((*Cmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Cmd), (*Cmd_len));
	} else
		brp_frame_skip(&_reader, (*Cmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I4CE_ExtendWaitingTime(brp_protocol protocol, unsigned WaitingTimeout, unsigned WTXM, unsigned RefreshTimeRatio) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 72);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)WaitingTimeout);
	brp_frame_write_int8(_frame, (unsigned)WTXM);
	brp_frame_write_int8(_frame, (unsigned)RefreshTimeRatio);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_I4CE_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ExtFieldStat;
	if (ExtFieldStat == NULL) ExtFieldStat = &_tmp_ExtFieldStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 72);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ExtFieldStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14CE_ActivateCardAPDU(brp_protocol protocol, bool SpecifyTimeoutApdu, bool AutoWTX, unsigned ATQA, brp_buf Snr, bool DSEqualToDR, bool DS8, bool DS4, bool DS2, bool DR8, bool DR4, bool DR2, unsigned FWT, unsigned TimeoutPCD, unsigned TimeoutApdu, brp_buf ATS, size_t ATS_len, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _FirstCmd_len;
	if(FirstCmd_len == NULL) FirstCmd_len = &_FirstCmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 74);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 2000);
	unsigned bitmask_1772206895120 = 0;
	bitmask_1772206895120 |= (SpecifyTimeoutApdu & 0b1) << 1;
	bitmask_1772206895120 |= (AutoWTX & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206895120);
	brp_frame_write_int16(_frame, (unsigned)ATQA);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	unsigned bitmask_1772206895408 = 0;
	bitmask_1772206895408 |= (DSEqualToDR & 0b1) << 7;
	bitmask_1772206895408 |= (DS8 & 0b1) << 6;
	bitmask_1772206895408 |= (DS4 & 0b1) << 5;
	bitmask_1772206895408 |= (DS2 & 0b1) << 4;
	bitmask_1772206895408 |= (DR8 & 0b1) << 2;
	bitmask_1772206895408 |= (DR4 & 0b1) << 1;
	bitmask_1772206895408 |= (DR2 & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206895408);
	brp_frame_write_int16(_frame, (unsigned)FWT);
	brp_frame_write_int16(_frame, (unsigned)TimeoutPCD);
	if(SpecifyTimeoutApdu) {
		brp_frame_write_int16(_frame, (unsigned)TimeoutApdu);
	}
	brp_frame_write_int8(_frame, (unsigned)ATS_len);
	brp_frame_write(_frame, (brp_buf)ATS, ATS_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FirstCmd_len) = brp_frame_read_int16(&_reader);
	if (FirstCmd != NULL) {
		(*FirstCmd) = (brp_buf)brp_mempool_create_buf(mempool, (*FirstCmd_len));
		if((*FirstCmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*FirstCmd), (*FirstCmd_len));
	} else
		brp_frame_skip(&_reader, (*FirstCmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14CE_ExchangeCardAPDU(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Cmd_len;
	if(Cmd_len == NULL) Cmd_len = &_Cmd_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 74);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)Rsp_len);
	brp_frame_write(_frame, (brp_buf)Rsp, Rsp_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Cmd_len) = brp_frame_read_int16(&_reader);
	if (Cmd != NULL) {
		(*Cmd) = (brp_buf)brp_mempool_create_buf(mempool, (*Cmd_len));
		if((*Cmd) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Cmd), (*Cmd_len));
	} else
		brp_frame_skip(&_reader, (*Cmd_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14CE_ExtendWaitingTime(brp_protocol protocol, unsigned WaitingTimeout, unsigned WTXM, unsigned RefreshTimeRatio) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 74);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)WaitingTimeout);
	brp_frame_write_int8(_frame, (unsigned)WTXM);
	brp_frame_write_int8(_frame, (unsigned)RefreshTimeRatio);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso14CE_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ExtFieldStat;
	if (ExtFieldStat == NULL) ExtFieldStat = &_tmp_ExtFieldStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 74);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ExtFieldStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_SetParam(brp_protocol protocol, bool ModulationIndex, bool TXMode, bool HighDataRate, bool DualSubcarrier) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772206897616 = 0;
	bitmask_1772206897616 |= (ModulationIndex & 0b1) << 3;
	bitmask_1772206897616 |= (TXMode & 0b1) << 2;
	bitmask_1772206897616 |= (HighDataRate & 0b1) << 1;
	bitmask_1772206897616 |= (DualSubcarrier & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206897616);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_GetParam(brp_protocol protocol, unsigned* ModulationIndex, unsigned* TXMode, unsigned* HighDataRate, unsigned* DualSubcarrier) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned bitmask_1772206898048 = brp_frame_read_int8(&_reader);
	if(ModulationIndex != NULL)
		(*ModulationIndex) = (bitmask_1772206898048>>3) & 0b1;
	if(TXMode != NULL)
		(*TXMode) = (bitmask_1772206898048>>2) & 0b1;
	if(HighDataRate != NULL)
		(*HighDataRate) = (bitmask_1772206898048>>1) & 0b1;
	if(DualSubcarrier != NULL)
		(*DualSubcarrier) = (bitmask_1772206898048>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_GetUIDList(brp_protocol protocol, bool EnAFI, bool NextBlock, bool AutoQuiet, bool EnDSFID, bool En16Slots, unsigned AFI, unsigned* More, brp_Iso15_GetUIDList_Labels_Entry** Labels, size_t* Labels_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Labels_len;
	if(Labels_len == NULL) Labels_len = &_Labels_len;
	unsigned _tmp_More;
	if (More == NULL) More = &_tmp_More;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772206898480 = 0;
	bitmask_1772206898480 |= (EnAFI & 0b1) << 4;
	bitmask_1772206898480 |= (NextBlock & 0b1) << 3;
	bitmask_1772206898480 |= (AutoQuiet & 0b1) << 2;
	bitmask_1772206898480 |= (EnDSFID & 0b1) << 1;
	bitmask_1772206898480 |= (En16Slots & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772206898480);
	if(EnAFI) {
		brp_frame_write_int8(_frame, (unsigned)AFI);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*More) = (unsigned)brp_frame_read_int8(&_reader);
	(*Labels_len) = brp_frame_read_int8(&_reader);
	if (Labels != NULL) {
		(*Labels) = (brp_Iso15_GetUIDList_Labels_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*Labels) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Labels_ndx = 1;!((_Labels_ndx > (*Labels_len)) | brp_frame_read_err(&_reader));_Labels_ndx++) {
		brp_Iso15_GetUIDList_Labels_Entry _Labels_Entry;
		brp_Iso15_GetUIDList_Labels_Entry *Labels_Entry = &_Labels_Entry;
		brp_buf _UID;
		brp_buf *UID = &_UID;
		unsigned _DSFID;
		unsigned *DSFID = &_DSFID;
		size_t _UID_len = 8;
		size_t* UID_len = &_UID_len;
		if (UID != NULL) {
			(*UID) = (brp_buf)brp_mempool_create_buf(mempool, (*UID_len));
			if((*UID) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*UID), (*UID_len));
		} else
			brp_frame_skip(&_reader, (*UID_len));
		if(EnDSFID) {
			(*DSFID) = (unsigned)brp_frame_read_int8(&_reader);
		}
		if(Labels_Entry != NULL) {
			Labels_Entry->UID = *UID;
			Labels_Entry->DSFID = *DSFID;
		}
		if (Labels != NULL) {
			(*Labels) = (brp_Iso15_GetUIDList_Labels_Entry*)brp_mempool_resize_buf((brp_buf)(*Labels), (_Labels_ndx * sizeof(brp_Iso15_GetUIDList_Labels_Entry)));
			if((*Labels) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Labels)[_Labels_ndx-1] = *Labels_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_SetMode(brp_protocol protocol, unsigned Mode, brp_buf UID) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	if((Mode) != (0)) {
		size_t UID_len = 8;
		brp_frame_write(_frame, (brp_buf)UID, UID_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_StayQuiet(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_ReadBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, bool EnBlockSec, unsigned* LabelStat, unsigned* BlockLen, brp_Iso15_ReadBlock_Data_Entry** Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	unsigned _tmp_BlockLen;
	if (BlockLen == NULL) BlockLen = &_tmp_BlockLen;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)BlockNum);
	brp_frame_write_int8(_frame, (unsigned)EnBlockSec);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if((*LabelStat) == (0)) {
		(*BlockLen) = (unsigned)brp_frame_read_int8(&_reader);
		(*Data_len) = brp_frame_rest( & _reader);
		if (Data != NULL) {
			(*Data) = (brp_Iso15_ReadBlock_Data_Entry*)brp_mempool_create_buf(mempool, 0);
			if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		}
		for(size_t _Data_ndx = 1;!(brp_frame_read_eof(&_reader) | brp_frame_read_err(&_reader));_Data_ndx++) {
			brp_Iso15_ReadBlock_Data_Entry _Data_Entry;
			brp_Iso15_ReadBlock_Data_Entry *Data_Entry = &_Data_Entry;
			brp_buf _BlockData;
			brp_buf *BlockData = &_BlockData;
			unsigned _BlockSecData;
			unsigned *BlockSecData = &_BlockSecData;
			size_t _BlockData_len = 0;
			size_t* BlockData_len = &_BlockData_len;
			if (BlockData != NULL) {
				(*BlockData) = (brp_buf)brp_mempool_create_buf(mempool, (*BlockData_len));
				if((*BlockData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
				brp_frame_read(&_reader, (brp_buf)(*BlockData), (*BlockData_len));
			} else
				brp_frame_skip(&_reader, (*BlockData_len));
			if(EnBlockSec) {
				(*BlockSecData) = (unsigned)brp_frame_read_int8(&_reader);
			}
			if(Data_Entry != NULL) {
				Data_Entry->BlockData = *BlockData;
				Data_Entry->BlockSecData = *BlockSecData;
			}
			if (Data != NULL) {
				(*Data) = (brp_Iso15_ReadBlock_Data_Entry*)brp_mempool_resize_buf((brp_buf)(*Data), (_Data_ndx * sizeof(brp_Iso15_ReadBlock_Data_Entry)));
				if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
				(*Data)[_Data_ndx-1] = *Data_Entry;
			}
			(*Data_len) = _Data_ndx;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_WriteBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, unsigned BlockLen, bool OptionFlag, brp_buf* Data, size_t Data_len, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)BlockNum);
	brp_frame_write_int8(_frame, (unsigned)BlockLen);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	for(size_t _Data_ndx = 0;_Data_ndx < Data_len;_Data_ndx++) {
		brp_buf SingleBlock = Data[_Data_ndx];
		size_t SingleBlock_len = 0;
		brp_frame_write(_frame, (brp_buf)SingleBlock, SingleBlock_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_LockBlock(brp_protocol protocol, unsigned BlockID, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_ResetToReady(brp_protocol protocol, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_WriteAFI(brp_protocol protocol, unsigned AFI, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AFI);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_LockAFI(brp_protocol protocol, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_WriteDSFID(brp_protocol protocol, unsigned DSFID, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)DSFID);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_LockDSFID(brp_protocol protocol, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 12);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_GetSystemInformation(brp_protocol protocol, unsigned* LabelStat, bool* EnICRef, bool* EnMemSize, bool* EnAFI, bool* EnDSFID, brp_buf* SNR, unsigned* DSFID, unsigned* AFI, unsigned* BlockNum, unsigned* BlockSize, unsigned* ICRef, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	unsigned _tmp_DSFID;
	if (DSFID == NULL) DSFID = &_tmp_DSFID;
	unsigned _tmp_AFI;
	if (AFI == NULL) AFI = &_tmp_AFI;
	unsigned _tmp_BlockNum;
	if (BlockNum == NULL) BlockNum = &_tmp_BlockNum;
	unsigned _tmp_BlockSize;
	if (BlockSize == NULL) BlockSize = &_tmp_BlockSize;
	unsigned _tmp_ICRef;
	if (ICRef == NULL) ICRef = &_tmp_ICRef;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 13);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if((*LabelStat) == (0)) {
		unsigned bitmask_1772207836800 = brp_frame_read_int8(&_reader);
		if(EnICRef != NULL)
			(*EnICRef) = (bitmask_1772207836800>>3) & 0b1;
		if(EnMemSize != NULL)
			(*EnMemSize) = (bitmask_1772207836800>>2) & 0b1;
		if(EnAFI != NULL)
			(*EnAFI) = (bitmask_1772207836800>>1) & 0b1;
		if(EnDSFID != NULL)
			(*EnDSFID) = (bitmask_1772207836800>>0) & 0b1;
		size_t _SNR_len = 8;
		size_t* SNR_len = &_SNR_len;
		if (SNR != NULL) {
			(*SNR) = (brp_buf)brp_mempool_create_buf(mempool, (*SNR_len));
			if((*SNR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*SNR), (*SNR_len));
		} else
			brp_frame_skip(&_reader, (*SNR_len));
	}
	if(((*LabelStat) == (0)) && (*EnDSFID)) {
		(*DSFID) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(((*LabelStat) == (0)) && (*EnAFI)) {
		(*AFI) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(((*LabelStat) == (0)) && (*EnMemSize)) {
		(*BlockNum) = (unsigned)brp_frame_read_int8(&_reader);
		(*BlockSize) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(((*LabelStat) == (0)) && (*EnICRef)) {
		(*ICRef) = (unsigned)brp_frame_read_int8(&_reader);
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_GetSecurityStatus(brp_protocol protocol, unsigned BlockID, unsigned BlockNum, unsigned* LabelStat, unsigned** BlockStat, size_t* BlockStat_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _BlockStat_len;
	if(BlockStat_len == NULL) BlockStat_len = &_BlockStat_len;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 14);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)BlockNum);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	(*BlockStat_len) = brp_frame_rest( & _reader);
	if (BlockStat != NULL) {
		(*BlockStat) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*BlockStat) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _BlockStat_ndx = 1;!(brp_frame_read_eof(&_reader) | brp_frame_read_err(&_reader));_BlockStat_ndx++) {
		unsigned _Status;
		unsigned *Status = &_Status;
		(*Status) = (unsigned)brp_frame_read_int8(&_reader);
		if (BlockStat != NULL) {
			(*BlockStat) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*BlockStat), (_BlockStat_ndx * sizeof(unsigned)));
			if((*BlockStat) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*BlockStat)[_BlockStat_ndx-1] = *Status;
		}
		(*BlockStat_len) = _BlockStat_ndx;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_CustomCommand(brp_protocol protocol, unsigned Cmd, unsigned Opt, unsigned MFC, unsigned TO, brp_buf RequestData, size_t RequestData_len, unsigned* LabelStat, brp_buf* ResponseData, size_t* ResponseData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ResponseData_len;
	if(ResponseData_len == NULL) ResponseData_len = &_ResponseData_len;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 15);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Cmd);
	brp_frame_write_int8(_frame, (unsigned)Opt);
	brp_frame_write_int8(_frame, (unsigned)MFC);
	brp_frame_write_int8(_frame, (unsigned)TO);
	brp_frame_write_int16(_frame, (unsigned)RequestData_len);
	brp_frame_write(_frame, (brp_buf)RequestData, RequestData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if((*LabelStat) == (0)) {
		(*ResponseData_len) = brp_frame_read_int16(&_reader);
		if (ResponseData != NULL) {
			(*ResponseData) = (brp_buf)brp_mempool_create_buf(mempool, (*ResponseData_len));
			if((*ResponseData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*ResponseData), (*ResponseData_len));
		} else
			brp_frame_skip(&_reader, (*ResponseData_len));
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_ReadSingleBlock(brp_protocol protocol, unsigned BlockID, bool EnBlockSec, unsigned* LabelStat, brp_buf* Payload, size_t* Payload_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Payload_len;
	if(Payload_len == NULL) Payload_len = &_Payload_len;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)EnBlockSec);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if((*LabelStat) == (0)) {
		(*Payload_len) = brp_frame_read_int8(&_reader);
		if (Payload != NULL) {
			(*Payload) = (brp_buf)brp_mempool_create_buf(mempool, (*Payload_len));
			if((*Payload) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*Payload), (*Payload_len));
		} else
			brp_frame_skip(&_reader, (*Payload_len));
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_WriteSingleBlock(brp_protocol protocol, unsigned BlockID, unsigned BlockLen, bool OptionFlag, brp_buf SingleBlockData, size_t SingleBlockData_len, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockID);
	brp_frame_write_int8(_frame, (unsigned)BlockLen);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_frame_write(_frame, (brp_buf)SingleBlockData, SingleBlockData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_TransparentCmdLegacy(brp_protocol protocol, bool EnRxWait, bool EnCRCRX, bool EnCRCTX, unsigned Len, unsigned Timeout, brp_buf Data, unsigned RxWait, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _LabelData_len;
	if(LabelData_len == NULL) LabelData_len = &_LabelData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772207839536 = 0;
	bitmask_1772207839536 |= (EnRxWait & 0b1) << 4;
	bitmask_1772207839536 |= (EnCRCRX & 0b1) << 3;
	bitmask_1772207839536 |= (EnCRCTX & 0b1) << 2;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207839536);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	size_t Data_len = 0;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	if(EnRxWait) {
		brp_frame_write_int16(_frame, (unsigned)RxWait);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelData_len) = brp_frame_read_int16(&_reader);
	if (LabelData != NULL) {
		(*LabelData) = (brp_buf)brp_mempool_create_buf(mempool, (*LabelData_len));
		if((*LabelData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LabelData), (*LabelData_len));
	} else
		brp_frame_skip(&_reader, (*LabelData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_WriteMultipleBlocks(brp_protocol protocol, unsigned FirstBlockId, brp_Iso15_WriteMultipleBlocks_WriteBlocks_Entry* WriteBlocks, size_t WriteBlocks_len, bool OptionFlag, unsigned* LabelStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FirstBlockId);
	brp_frame_write_int16(_frame, (unsigned)WriteBlocks_len);
	for(size_t _WriteBlocks_ndx = 0;_WriteBlocks_ndx < WriteBlocks_len;_WriteBlocks_ndx++) {
		brp_Iso15_WriteMultipleBlocks_WriteBlocks_Entry WriteBlocks_Entry = WriteBlocks[_WriteBlocks_ndx];
		brp_buf WriteBlock = WriteBlocks_Entry.WriteBlock;
		size_t WriteBlock_len = WriteBlocks_Entry.WriteBlock_len;
		brp_frame_write_int8(_frame, (unsigned)WriteBlock_len);
		brp_frame_write(_frame, (brp_buf)WriteBlock, WriteBlock_len);
	}
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_ReadMultipleBlocks(brp_protocol protocol, unsigned FirstBlockId, unsigned BlockCount, bool EnBlockSec, unsigned* LabelStat, brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry** RecvBlocks, size_t* RecvBlocks_len, unsigned** BlocksSecData, size_t* BlocksSecData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvBlocks_len;
	if(RecvBlocks_len == NULL) RecvBlocks_len = &_RecvBlocks_len;
	size_t _BlocksSecData_len;
	if(BlocksSecData_len == NULL) BlocksSecData_len = &_BlocksSecData_len;
	unsigned _tmp_LabelStat;
	if (LabelStat == NULL) LabelStat = &_tmp_LabelStat;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FirstBlockId);
	brp_frame_write_int16(_frame, (unsigned)BlockCount);
	brp_frame_write_int8(_frame, (unsigned)EnBlockSec);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LabelStat) = (unsigned)brp_frame_read_int8(&_reader);
	(*RecvBlocks_len) = brp_frame_read_int16(&_reader);
	if (RecvBlocks != NULL) {
		(*RecvBlocks) = (brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*RecvBlocks) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _RecvBlocks_ndx = 1;!((_RecvBlocks_ndx > (*RecvBlocks_len)) | brp_frame_read_err(&_reader));_RecvBlocks_ndx++) {
		brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry _RecvBlocks_Entry;
		brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry *RecvBlocks_Entry = &_RecvBlocks_Entry;
		brp_buf _RecvBlock;
		brp_buf *RecvBlock = &_RecvBlock;
		size_t _RecvBlock_len;
		size_t *RecvBlock_len = &_RecvBlock_len;
		(*RecvBlock_len) = brp_frame_read_int8(&_reader);
		if (RecvBlock != NULL) {
			(*RecvBlock) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvBlock_len));
			if((*RecvBlock) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			brp_frame_read(&_reader, (brp_buf)(*RecvBlock), (*RecvBlock_len));
		} else
			brp_frame_skip(&_reader, (*RecvBlock_len));
		if(RecvBlocks_Entry != NULL) {
			RecvBlocks_Entry->RecvBlock = *RecvBlock;
			RecvBlocks_Entry->RecvBlock_len = *RecvBlock_len;
		}
		if (RecvBlocks != NULL) {
			(*RecvBlocks) = (brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry*)brp_mempool_resize_buf((brp_buf)(*RecvBlocks), (_RecvBlocks_ndx * sizeof(brp_Iso15_ReadMultipleBlocks_RecvBlocks_Entry)));
			if((*RecvBlocks) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*RecvBlocks)[_RecvBlocks_ndx-1] = *RecvBlocks_Entry;
		}
	}
	(*BlocksSecData_len) = brp_frame_read_int16(&_reader);
	if (BlocksSecData != NULL) {
		(*BlocksSecData) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*BlocksSecData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _BlocksSecData_ndx = 1;!((_BlocksSecData_ndx > (*BlocksSecData_len)) | brp_frame_read_err(&_reader));_BlocksSecData_ndx++) {
		unsigned _BlockSecData;
		unsigned *BlockSecData = &_BlockSecData;
		(*BlockSecData) = (unsigned)brp_frame_read_int8(&_reader);
		if (BlocksSecData != NULL) {
			(*BlocksSecData) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*BlocksSecData), (_BlocksSecData_ndx * sizeof(unsigned)));
			if((*BlocksSecData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*BlocksSecData)[_BlocksSecData_ndx-1] = *BlockSecData;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso15_TransparentCmd(brp_protocol protocol, brp_buf SendData, size_t SendData_len, unsigned Timeout, bool EnCrcRx, bool EnCrcTx, unsigned RxWait, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int8(_frame, 35);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)SendData_len);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_frame_write_int8(_frame, (unsigned)EnCrcRx);
	brp_frame_write_int8(_frame, (unsigned)EnCrcTx);
	brp_frame_write_int16(_frame, (unsigned)RxWait);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_SelectSlot(brp_protocol protocol, unsigned SlotIndex) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SlotIndex);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_OpenSamLegacy(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ATR_len;
	if(ATR_len == NULL) ATR_len = &_ATR_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 1200);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ATR_len) = brp_frame_read_int8(&_reader);
	if (ATR != NULL) {
		(*ATR) = (brp_buf)brp_mempool_create_buf(mempool, (*ATR_len));
		if((*ATR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATR), (*ATR_len));
	} else
		brp_frame_skip(&_reader, (*ATR_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_CloseSamLegacy(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_ExchangeApduLegacy(brp_protocol protocol, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)SendData_len);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_OpenSam(brp_protocol protocol, brp_Iso78_OpenSam_LID LID, unsigned* SamHandle, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ATR_len;
	if(ATR_len == NULL) ATR_len = &_ATR_len;
	unsigned _tmp_SamHandle;
	if (SamHandle == NULL) SamHandle = &_tmp_SamHandle;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)LID);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SamHandle) = (unsigned)brp_frame_read_int8(&_reader);
	(*ATR_len) = brp_frame_read_int8(&_reader);
	if (ATR != NULL) {
		(*ATR) = (brp_buf)brp_mempool_create_buf(mempool, (*ATR_len));
		if((*ATR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATR), (*ATR_len));
	} else
		brp_frame_skip(&_reader, (*ATR_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_CloseSam(brp_protocol protocol, unsigned SamHandle) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SamHandle);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Iso78_ExchangeApdu(brp_protocol protocol, unsigned SamHandle, brp_buf SendData, size_t SendData_len, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 64);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SamHandle);
	brp_frame_write_int16(_frame, (unsigned)SendData_len);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Keyboard_Exist(brp_protocol protocol, bool* KeyboardConnected) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_KeyboardConnected;
	if (KeyboardConnected == NULL) KeyboardConnected = &_tmp_KeyboardConnected;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*KeyboardConnected) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Keyboard_CurrentKey(brp_protocol protocol, unsigned* Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Key;
	if (Key == NULL) Key = &_tmp_Key;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Key) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Keyboard_EnableWakeup(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Keyboard_WaitForKey(brp_protocol protocol, unsigned Timeout, unsigned* Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Key;
	if (Key == NULL) Key = &_tmp_Key;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 66000);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Key) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Legic_TransparentCommand4000(brp_protocol protocol, unsigned CmdCode, brp_buf CmdParams, size_t CmdParams_len, unsigned Timeout, unsigned* Status, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	unsigned _tmp_Status;
	if (Status == NULL) Status = &_tmp_Status;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 30);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)CmdCode);
	brp_frame_write_int8(_frame, (unsigned)CmdParams_len);
	brp_frame_write(_frame, (brp_buf)CmdParams, CmdParams_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Status) = (unsigned)brp_frame_read_int8(&_reader);
	(*Resp_len) = brp_frame_read_int8(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_Select(brp_protocol protocol, unsigned TO, unsigned Adr, unsigned Len, unsigned PollTime, unsigned CRCAdr, unsigned SafeDat, unsigned ChgSeg, unsigned ProtHead, unsigned CRCCalc, unsigned CRCChk, unsigned SegID, brp_buf Stamp, size_t Stamp_len, brp_Lg_Select_MediaType* MediaType, unsigned* FuncLevel, unsigned* OrgLevel, brp_Lg_Select_EvStat* EvStat, unsigned* ActSegID, unsigned* ActAdr, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	unsigned _tmp_FuncLevel;
	if (FuncLevel == NULL) FuncLevel = &_tmp_FuncLevel;
	unsigned _tmp_OrgLevel;
	if (OrgLevel == NULL) OrgLevel = &_tmp_OrgLevel;
	unsigned _tmp_ActSegID;
	if (ActSegID == NULL) ActSegID = &_tmp_ActSegID;
	unsigned _tmp_ActAdr;
	if (ActAdr == NULL) ActAdr = &_tmp_ActAdr;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 2000);
	brp_frame_write_int8(_frame, (unsigned)TO);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Len);
	brp_frame_write_int8(_frame, (unsigned)PollTime);
	brp_frame_write_int16(_frame, (unsigned)CRCAdr);
	unsigned bitmask_1772207845968 = 0;
	bitmask_1772207845968 |= (SafeDat & 0b1) << 4;
	bitmask_1772207845968 |= (ChgSeg & 0b1) << 3;
	bitmask_1772207845968 |= (ProtHead & 0b1) << 2;
	bitmask_1772207845968 |= (CRCCalc & 0b1) << 1;
	bitmask_1772207845968 |= (CRCChk & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772207845968);
	brp_frame_write_int8(_frame, (unsigned)SegID);
	brp_frame_write(_frame, (brp_buf)Stamp, Stamp_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _MediaType_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Lg_Select_MediaType_is_valid(_MediaType_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (MediaType != NULL)
		(*MediaType) = (brp_Lg_Select_MediaType)_MediaType_int_val;
	(*FuncLevel) = (unsigned)brp_frame_read_int8(&_reader);
	(*OrgLevel) = (unsigned)brp_frame_read_int8(&_reader);
	int _EvStat_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Lg_Select_EvStat_is_valid(_EvStat_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (EvStat != NULL)
		(*EvStat) = (brp_Lg_Select_EvStat)_EvStat_int_val;
	(*ActSegID) = (unsigned)brp_frame_read_int8(&_reader);
	(*ActAdr) = (unsigned)brp_frame_read_int16(&_reader);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_Idle(brp_protocol protocol, brp_Lg_Idle_PowOff PowOff) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PowOff);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_GenSetRead(brp_protocol protocol, unsigned DesiredGenSetNum, unsigned* GenSetNum, brp_buf* Stamp, unsigned* StampLen, unsigned* WriteExLen, bool* WriteExShad, brp_Lg_GenSetRead_WriteExMode* WriteExMode, unsigned* WriteExStart, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_GenSetNum;
	if (GenSetNum == NULL) GenSetNum = &_tmp_GenSetNum;
	unsigned _tmp_StampLen;
	if (StampLen == NULL) StampLen = &_tmp_StampLen;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 500);
	brp_frame_write_int8(_frame, (unsigned)DesiredGenSetNum);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*GenSetNum) = (unsigned)brp_frame_read_int8(&_reader);
	size_t _Stamp_len = 7;
	size_t* Stamp_len = &_Stamp_len;
	if (Stamp != NULL) {
		(*Stamp) = (brp_buf)brp_mempool_create_buf(mempool, (*Stamp_len));
		if((*Stamp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Stamp), (*Stamp_len));
	} else
		brp_frame_skip(&_reader, (*Stamp_len));
	(*StampLen) = (unsigned)brp_frame_read_int8(&_reader);
	unsigned bitmask_1772207848272 = brp_frame_read_int24(&_reader);
	if(WriteExLen != NULL)
		(*WriteExLen) = (bitmask_1772207848272>>16) & 0b11111111;
	if(WriteExShad != NULL)
		(*WriteExShad) = (bitmask_1772207848272>>15) & 0b1;
	if(WriteExMode != NULL)
		(*WriteExMode) = (bitmask_1772207848272>>13) & 0b11;
	if(WriteExStart != NULL)
		(*WriteExStart) = (bitmask_1772207848272>>0) & 0b111111111111;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_GenSetDelete(brp_protocol protocol, unsigned GenSetNum, unsigned* DeletedGenSetNum) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_DeletedGenSetNum;
	if (DeletedGenSetNum == NULL) DeletedGenSetNum = &_tmp_DeletedGenSetNum;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)GenSetNum);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*DeletedGenSetNum) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_ReadMIM(brp_protocol protocol, unsigned Adr, unsigned Len, unsigned* DataAdr, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	unsigned _tmp_DataAdr;
	if (DataAdr == NULL) DataAdr = &_tmp_DataAdr;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*DataAdr) = (unsigned)brp_frame_read_int16(&_reader);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_ReadMIMCRC(brp_protocol protocol, unsigned Adr, unsigned Len, unsigned CRCAdr, unsigned* DataAdr, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	unsigned _tmp_DataAdr;
	if (DataAdr == NULL) DataAdr = &_tmp_DataAdr;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Len);
	brp_frame_write_int16(_frame, (unsigned)CRCAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*DataAdr) = (unsigned)brp_frame_read_int16(&_reader);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_WriteMIM(brp_protocol protocol, unsigned Adr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 1500);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_WriteMIMCRC(brp_protocol protocol, unsigned Adr, unsigned DataLen, unsigned CRCAdr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 1500);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)DataLen);
	brp_frame_write_int16(_frame, (unsigned)CRCAdr);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_MakeMIMCRC(brp_protocol protocol, unsigned Adr, unsigned Len, unsigned CRCAdr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 1500);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Len);
	brp_frame_write_int16(_frame, (unsigned)CRCAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_ReadSMStatus(brp_protocol protocol, brp_buf* RFU, unsigned* SWV, unsigned* SmStat, unsigned* HfPow, bool* NoMIM, brp_Lg_ReadSMStatus_MIMVersion* MIMVersion, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_SWV;
	if (SWV == NULL) SWV = &_tmp_SWV;
	unsigned _tmp_SmStat;
	if (SmStat == NULL) SmStat = &_tmp_SmStat;
	unsigned _tmp_HfPow;
	if (HfPow == NULL) HfPow = &_tmp_HfPow;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 13);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _RFU_len = 3;
	size_t* RFU_len = &_RFU_len;
	if (RFU != NULL) {
		(*RFU) = (brp_buf)brp_mempool_create_buf(mempool, (*RFU_len));
		if((*RFU) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RFU), (*RFU_len));
	} else
		brp_frame_skip(&_reader, (*RFU_len));
	(*SWV) = (unsigned)brp_frame_read_int8(&_reader);
	(*SmStat) = (unsigned)brp_frame_read_int8(&_reader);
	(*HfPow) = (unsigned)brp_frame_read_int8(&_reader);
	unsigned bitmask_1772208064112 = brp_frame_read_int8(&_reader);
	if(NoMIM != NULL)
		(*NoMIM) = (bitmask_1772208064112>>4) & 0b1;
	if(MIMVersion != NULL)
		(*MIMVersion) = (bitmask_1772208064112>>0) & 0b11;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_SetPassword(brp_protocol protocol, brp_buf Password, brp_Lg_SetPassword_PwdStat* PwdStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 14);
	brp_frame_write_int32(_frame, 2500);
	size_t Password_len = 4;
	brp_frame_write(_frame, (brp_buf)Password, Password_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _PwdStat_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Lg_SetPassword_PwdStat_is_valid(_PwdStat_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (PwdStat != NULL)
		(*PwdStat) = (brp_Lg_SetPassword_PwdStat)_PwdStat_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_Lock(brp_protocol protocol, brp_Lg_Lock_PwdStat* PwdStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 15);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _PwdStat_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Lg_Lock_PwdStat_is_valid(_PwdStat_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (PwdStat != NULL)
		(*PwdStat) = (brp_Lg_Lock_PwdStat)_PwdStat_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lg_Unlock(brp_protocol protocol, brp_buf Password, brp_Lg_Unlock_PwdStat* PwdStat) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	size_t Password_len = 4;
	brp_frame_write(_frame, (brp_buf)Password, Password_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _PwdStat_int_val = brp_frame_read_int8(&_reader);
	if (! brp_Lg_Unlock_PwdStat_is_valid(_PwdStat_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (PwdStat != NULL)
		(*PwdStat) = (brp_Lg_Unlock_PwdStat)_PwdStat_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lga_TransparentCommand(brp_protocol protocol, unsigned CmdCode, brp_buf CmdParams, size_t CmdParams_len, unsigned Timeout, unsigned* Status, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	unsigned _tmp_Status;
	if (Status == NULL) Status = &_tmp_Status;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)CmdCode);
	brp_frame_write_int8(_frame, (unsigned)CmdParams_len);
	brp_frame_write(_frame, (brp_buf)CmdParams, CmdParams_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Status) = (unsigned)brp_frame_read_int8(&_reader);
	(*Resp_len) = brp_frame_read_int8(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lic_GetLicenses(brp_protocol protocol, brp_LicenseBitMask* LicenseBitMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _LicenseBitMask_int = brp_frame_read_int32(&_reader);
	if(LicenseBitMask != NULL)
		(LicenseBitMask->Ble) = (_LicenseBitMask_int>>3) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->BleLicRequired) = (_LicenseBitMask_int>>2) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->HidOnlyForSE) = (_LicenseBitMask_int>>1) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->Hid) = (_LicenseBitMask_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Lic_ReadLicCard(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 2000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_Bf2Upload(brp_protocol protocol, unsigned* Lines, size_t Lines_len, brp_Main_Bf2Upload_ResultCode* ResultCode, unsigned* InvertedResultCode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_InvertedResultCode;
	if (InvertedResultCode == NULL) InvertedResultCode = &_tmp_InvertedResultCode;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 5000);
	for(size_t _Lines_ndx = 0;_Lines_ndx < Lines_len;_Lines_ndx++) {
		unsigned Line = Lines[_Lines_ndx];
		brp_frame_write_int8(_frame, (unsigned)Line);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _ResultCode_int_val = brp_frame_read_int8(&_reader);
	if (ResultCode != NULL) {
		if (brp_Main_Bf2Upload_ResultCode_is_valid(_ResultCode_int_val))
			(*ResultCode) = (brp_Main_Bf2Upload_ResultCode)_ResultCode_int_val;
		else
			(*ResultCode) = brp_Main_Bf2Upload_ResultCode_undefined;
	}
	(*InvertedResultCode) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_SwitchFW(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_MatchPlatformId2(brp_protocol protocol, brp_buf Filter, size_t Filter_len, bool* Matches) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_Matches;
	if (Matches == NULL) Matches = &_tmp_Matches;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write(_frame, (brp_buf)Filter, Filter_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Matches) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_IsFirmwareUpToDate(brp_protocol protocol, brp_buf VersionDesc, size_t VersionDesc_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 5000);
	brp_frame_write_int8(_frame, (unsigned)VersionDesc_len);
	brp_frame_write(_frame, (brp_buf)VersionDesc, VersionDesc_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_Bf3UploadStart(brp_protocol protocol, unsigned* ReqDataAdr, unsigned* ReqDataLen) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ReqDataAdr;
	if (ReqDataAdr == NULL) ReqDataAdr = &_tmp_ReqDataAdr;
	unsigned _tmp_ReqDataLen;
	if (ReqDataLen == NULL) ReqDataLen = &_tmp_ReqDataLen;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReqDataAdr) = (unsigned)brp_frame_read_int32(&_reader);
	(*ReqDataLen) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Main_Bf3UploadContinue(brp_protocol protocol, unsigned DataAdr, brp_buf Data, size_t Data_len, bool* Reconnect, bool* Continue, unsigned* ReqDataAdr, unsigned* ReqDataLen, bool* ContainsEstimation, bool* ContainsReconnectRetryTimeout, unsigned* ReconnectRetryTimeout, unsigned* EstimatedNumberOfBytes, unsigned* EstimatedTimeOverhead) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ReqDataAdr;
	if (ReqDataAdr == NULL) ReqDataAdr = &_tmp_ReqDataAdr;
	unsigned _tmp_ReqDataLen;
	if (ReqDataLen == NULL) ReqDataLen = &_tmp_ReqDataLen;
	unsigned _tmp_ReconnectRetryTimeout;
	if (ReconnectRetryTimeout == NULL) ReconnectRetryTimeout = &_tmp_ReconnectRetryTimeout;
	unsigned _tmp_EstimatedNumberOfBytes;
	if (EstimatedNumberOfBytes == NULL) EstimatedNumberOfBytes = &_tmp_EstimatedNumberOfBytes;
	unsigned _tmp_EstimatedTimeOverhead;
	if (EstimatedTimeOverhead == NULL) EstimatedTimeOverhead = &_tmp_EstimatedTimeOverhead;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 240);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int32(_frame, (unsigned)DataAdr);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned bitmask_1772208069584 = brp_frame_read_int8(&_reader);
	if(Reconnect != NULL)
		(*Reconnect) = (bitmask_1772208069584>>1) & 0b1;
	if(Continue != NULL)
		(*Continue) = (bitmask_1772208069584>>0) & 0b1;
	(*ReqDataAdr) = (unsigned)brp_frame_read_int32(&_reader);
	(*ReqDataLen) = (unsigned)brp_frame_read_int16(&_reader);
	unsigned bitmask_1772208069872 = brp_frame_read_int8(&_reader);
	if(ContainsEstimation != NULL)
		(*ContainsEstimation) = (bitmask_1772208069872>>1) & 0b1;
	if(ContainsReconnectRetryTimeout != NULL)
		(*ContainsReconnectRetryTimeout) = (bitmask_1772208069872>>0) & 0b1;
	if(*ContainsReconnectRetryTimeout) {
		(*ReconnectRetryTimeout) = (unsigned)brp_frame_read_int32(&_reader);
	}
	if(*ContainsEstimation) {
		(*EstimatedNumberOfBytes) = (unsigned)brp_frame_read_int32(&_reader);
		(*EstimatedTimeOverhead) = (unsigned)brp_frame_read_int32(&_reader);
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mce_Enable(brp_protocol protocol, brp_Mce_Enable_Mode Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 77);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mce_Request(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Snr_len;
	if(Snr_len == NULL) Snr_len = &_Snr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 77);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Snr_len) = brp_frame_read_int8(&_reader);
	if (Snr != NULL) {
		(*Snr) = (brp_buf)brp_mempool_create_buf(mempool, (*Snr_len));
		if((*Snr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Snr), (*Snr_len));
	} else
		brp_frame_skip(&_reader, (*Snr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_LoadKey(brp_protocol protocol, unsigned KeyIdx, brp_buf Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)KeyIdx);
	size_t Key_len = 6;
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Request(brp_protocol protocol, unsigned ReqAll, unsigned* ATQA) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ATQA;
	if (ATQA == NULL) ATQA = &_tmp_ATQA;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208072752 = 0;
	bitmask_1772208072752 |= (ReqAll & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208072752);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ATQA) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelSer, brp_buf* Snr, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BitCount);
	size_t PreSelSer_len = 4;
	brp_frame_write(_frame, (brp_buf)PreSelSer, PreSelSer_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _Snr_len = 4;
	size_t* Snr_len = &_Snr_len;
	if (Snr != NULL) {
		(*Snr) = (brp_buf)brp_mempool_create_buf(mempool, (*Snr_len));
		if((*Snr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Snr), (*Snr_len));
	} else
		brp_frame_skip(&_reader, (*Snr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Select(brp_protocol protocol, brp_buf Snr, unsigned* SAK) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_SAK;
	if (SAK == NULL) SAK = &_tmp_SAK;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SAK) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_AuthE2(brp_protocol protocol, unsigned AuthMode, unsigned Block, unsigned KeyIdx) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AuthMode);
	brp_frame_write_int8(_frame, (unsigned)Block);
	brp_frame_write_int8(_frame, (unsigned)KeyIdx);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_AuthUser(brp_protocol protocol, unsigned AuthMode, unsigned Block, brp_buf Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AuthMode);
	brp_frame_write_int8(_frame, (unsigned)Block);
	size_t Key_len = 6;
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Read(brp_protocol protocol, unsigned Block, brp_buf* BlockData, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Block);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _BlockData_len = 16;
	size_t* BlockData_len = &_BlockData_len;
	if (BlockData != NULL) {
		(*BlockData) = (brp_buf)brp_mempool_create_buf(mempool, (*BlockData_len));
		if((*BlockData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*BlockData), (*BlockData_len));
	} else
		brp_frame_skip(&_reader, (*BlockData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Write(brp_protocol protocol, unsigned Block, brp_buf BlockData) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Block);
	size_t BlockData_len = 16;
	brp_frame_write(_frame, (brp_buf)BlockData, BlockData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ChangeValue(brp_protocol protocol, unsigned Mode, unsigned Block, unsigned Value) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_frame_write_int8(_frame, (unsigned)Block);
	brp_frame_write_int32(_frame, (unsigned)Value);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ChangeValueBackup(brp_protocol protocol, unsigned Mode, unsigned Block, unsigned Value) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_frame_write_int8(_frame, (unsigned)Block);
	brp_frame_write_int32(_frame, (unsigned)Value);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_TransferBlock(brp_protocol protocol, unsigned Block) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Block);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_Halt(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_AuthE2Extended(brp_protocol protocol, unsigned AuthLevel, bool KeyHasExtIdx, unsigned EV1Mode, bool IsKeyB, unsigned Block, unsigned KeyIdx, unsigned KeyExtIdx, brp_buf DivData, size_t DivData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208075536 = 0;
	bitmask_1772208075536 |= (AuthLevel & 0b11) << 6;
	bitmask_1772208075536 |= (KeyHasExtIdx & 0b1) << 2;
	bitmask_1772208075536 |= (EV1Mode & 0b1) << 1;
	bitmask_1772208075536 |= (IsKeyB & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208075536);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_frame_write_int8(_frame, (unsigned)KeyIdx);
	if(KeyHasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)KeyExtIdx);
	}
	brp_frame_write_int8(_frame, (unsigned)DivData_len);
	brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_AuthUserExtended(brp_protocol protocol, unsigned AuthLevel, unsigned EV1Mode, unsigned KeyB, unsigned Block, brp_buf Key, size_t Key_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208076208 = 0;
	bitmask_1772208076208 |= (AuthLevel & 0b11) << 6;
	bitmask_1772208076208 |= (EV1Mode & 0b1) << 1;
	bitmask_1772208076208 |= (KeyB & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208076208);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ResetAuth(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ReadSL3(brp_protocol protocol, unsigned NoMacOnCmd, unsigned PlainData, unsigned NoMacOnResp, unsigned Block, unsigned BlockNr, brp_buf* BlockData, size_t* BlockData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _BlockData_len;
	if(BlockData_len == NULL) BlockData_len = &_BlockData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208076736 = 0;
	bitmask_1772208076736 |= (NoMacOnCmd & 0b1) << 2;
	bitmask_1772208076736 |= (PlainData & 0b1) << 1;
	bitmask_1772208076736 |= (NoMacOnResp & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208076736);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_frame_write_int8(_frame, (unsigned)BlockNr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*BlockData_len) = brp_frame_read_int16(&_reader);
	if (BlockData != NULL) {
		(*BlockData) = (brp_buf)brp_mempool_create_buf(mempool, (*BlockData_len));
		if((*BlockData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*BlockData), (*BlockData_len));
	} else
		brp_frame_skip(&_reader, (*BlockData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_WriteSL3(brp_protocol protocol, unsigned PlainData, unsigned NoMacOnResp, unsigned Block, brp_buf BlockData, size_t BlockData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208077312 = 0;
	bitmask_1772208077312 |= (PlainData & 0b1) << 1;
	bitmask_1772208077312 |= (NoMacOnResp & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208077312);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_frame_write_int16(_frame, (unsigned)BlockData_len);
	brp_frame_write(_frame, (brp_buf)BlockData, BlockData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ChangeAESKey(brp_protocol protocol, bool KeyHasExtIdx, unsigned NoMacOnResp, unsigned Block, unsigned KeyIdx, unsigned KeyExtIdx, brp_buf DivData, size_t DivData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 21);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208077744 = 0;
	bitmask_1772208077744 |= (KeyHasExtIdx & 0b1) << 3;
	bitmask_1772208077744 |= (NoMacOnResp & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208077744);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_frame_write_int8(_frame, (unsigned)KeyIdx);
	if(KeyHasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)KeyExtIdx);
	}
	brp_frame_write_int8(_frame, (unsigned)DivData_len);
	brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ValueSL3(brp_protocol protocol, unsigned NoMacOnResp, unsigned Cmd, unsigned Block, unsigned DestBlock, unsigned Value, brp_buf* TMCounterTMValue, size_t* TMCounterTMValue_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _TMCounterTMValue_len;
	if(TMCounterTMValue_len == NULL) TMCounterTMValue_len = &_TMCounterTMValue_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208078368 = 0;
	bitmask_1772208078368 |= (NoMacOnResp & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208078368);
	brp_frame_write_int8(_frame, (unsigned)Cmd);
	brp_frame_write_int16(_frame, (unsigned)Block);
	if(((Cmd) == (3)) || ((Cmd) == (4))) {
		brp_frame_write_int16(_frame, (unsigned)DestBlock);
	}
	if(((((Cmd) == (0)) || ((Cmd) == (1))) || ((Cmd) == (3))) || ((Cmd) == (4))) {
		brp_frame_write_int32(_frame, (unsigned)Value);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*TMCounterTMValue_len) = brp_frame_read_int8(&_reader);
	if (TMCounterTMValue != NULL) {
		(*TMCounterTMValue) = (brp_buf)brp_mempool_create_buf(mempool, (*TMCounterTMValue_len));
		if((*TMCounterTMValue) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*TMCounterTMValue), (*TMCounterTMValue_len));
	} else
		brp_frame_skip(&_reader, (*TMCounterTMValue_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ProxCheck(brp_protocol protocol, unsigned M, unsigned DisableIsoWrapping, bool UseExtProxKey, bool DiversifyProxKey, bool UseProxKey, unsigned ProxKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf ProxKey, size_t ProxKey_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 23);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208275664 = 0;
	bitmask_1772208275664 |= (M & 0b111) << 4;
	bitmask_1772208275664 |= (DisableIsoWrapping & 0b1) << 3;
	bitmask_1772208275664 |= (UseExtProxKey & 0b1) << 2;
	bitmask_1772208275664 |= (DiversifyProxKey & 0b1) << 1;
	bitmask_1772208275664 |= (UseProxKey & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208275664);
	if(UseProxKey) {
		brp_frame_write_int16(_frame, (unsigned)ProxKeyIdx);
	}
	if((DiversifyProxKey) && (UseProxKey)) {
		brp_frame_write_int8(_frame, (unsigned)DivData_len);
		brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	}
	if(UseExtProxKey) {
		brp_frame_write_int8(_frame, (unsigned)ProxKey_len);
		brp_frame_write(_frame, (brp_buf)ProxKey, ProxKey_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_GetCardVersion(brp_protocol protocol, brp_buf* CardVersion, size_t* CardVersion_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _CardVersion_len;
	if(CardVersion_len == NULL) CardVersion_len = &_CardVersion_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 24);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CardVersion_len) = brp_frame_read_int8(&_reader);
	if (CardVersion != NULL) {
		(*CardVersion) = (brp_buf)brp_mempool_create_buf(mempool, (*CardVersion_len));
		if((*CardVersion) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*CardVersion), (*CardVersion_len));
	} else
		brp_frame_skip(&_reader, (*CardVersion_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_ReadSig(brp_protocol protocol, brp_buf* NxpSignature, size_t* NxpSignature_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _NxpSignature_len;
	if(NxpSignature_len == NULL) NxpSignature_len = &_NxpSignature_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 25);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*NxpSignature_len) = brp_frame_read_int8(&_reader);
	if (NxpSignature != NULL) {
		(*NxpSignature) = (brp_buf)brp_mempool_create_buf(mempool, (*NxpSignature_len));
		if((*NxpSignature) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*NxpSignature), (*NxpSignature_len));
	} else
		brp_frame_skip(&_reader, (*NxpSignature_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_VirtualCardSelect(brp_protocol protocol, bool ForceVcsAuthentication, bool UseExtVcSelectKeys, unsigned DiversifyMacKey, bool DiversifyEncKey, bool UseVcSelectKeys, brp_buf IID, size_t IID_len, unsigned EncKeyIdx, unsigned MacKeyIdx, brp_buf DivData, size_t DivData_len, brp_buf EncKey, size_t EncKey_len, brp_buf MacKey, size_t MacKey_len, unsigned* FciType, brp_buf* Fci, size_t* Fci_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Fci_len;
	if(Fci_len == NULL) Fci_len = &_Fci_len;
	unsigned _tmp_FciType;
	if (FciType == NULL) FciType = &_tmp_FciType;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208276768 = 0;
	bitmask_1772208276768 |= (ForceVcsAuthentication & 0b1) << 5;
	bitmask_1772208276768 |= (UseExtVcSelectKeys & 0b1) << 4;
	bitmask_1772208276768 |= (DiversifyMacKey & 0b11) << 2;
	bitmask_1772208276768 |= (DiversifyEncKey & 0b1) << 1;
	bitmask_1772208276768 |= (UseVcSelectKeys & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208276768);
	brp_frame_write_int8(_frame, (unsigned)IID_len);
	brp_frame_write(_frame, (brp_buf)IID, IID_len);
	if(UseVcSelectKeys) {
		brp_frame_write_int16(_frame, (unsigned)EncKeyIdx);
		brp_frame_write_int16(_frame, (unsigned)MacKeyIdx);
	}
	if(((((DiversifyMacKey) == (1)) || ((DiversifyMacKey) == (2))) || ((DiversifyMacKey) == (3))) || (DiversifyEncKey)) {
		brp_frame_write_int8(_frame, (unsigned)DivData_len);
		brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	}
	if(UseExtVcSelectKeys) {
		brp_frame_write_int8(_frame, (unsigned)EncKey_len);
		brp_frame_write(_frame, (brp_buf)EncKey, EncKey_len);
		brp_frame_write_int8(_frame, (unsigned)MacKey_len);
		brp_frame_write(_frame, (brp_buf)MacKey, MacKey_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FciType) = (unsigned)brp_frame_read_int8(&_reader);
	(*Fci_len) = brp_frame_read_int8(&_reader);
	if (Fci != NULL) {
		(*Fci) = (brp_buf)brp_mempool_create_buf(mempool, (*Fci_len));
		if((*Fci) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Fci), (*Fci_len));
	} else
		brp_frame_skip(&_reader, (*Fci_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_SectorSwitch(brp_protocol protocol, bool L3SectorSwitch, unsigned SectorSwitchKeyIdx, brp_buf SectorSwitchKeyDivData, size_t SectorSwitchKeyDivData_len, brp_Mif_SectorSwitch_SectorSpec_Entry* SectorSpec, size_t SectorSpec_len, brp_buf SectorKeysDivData, size_t SectorKeysDivData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208277824 = 0;
	bitmask_1772208277824 |= (L3SectorSwitch & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208277824);
	brp_frame_write_int16(_frame, (unsigned)SectorSwitchKeyIdx);
	brp_frame_write_int8(_frame, (unsigned)SectorSwitchKeyDivData_len);
	brp_frame_write(_frame, (brp_buf)SectorSwitchKeyDivData, SectorSwitchKeyDivData_len);
	brp_frame_write_int8(_frame, (unsigned)SectorSpec_len);
	for(size_t _SectorSpec_ndx = 0;_SectorSpec_ndx < SectorSpec_len;_SectorSpec_ndx++) {
		brp_Mif_SectorSwitch_SectorSpec_Entry SectorSpec_Entry = SectorSpec[_SectorSpec_ndx];
		unsigned BlockAddress = SectorSpec_Entry.BlockAddress;
		unsigned SectorKeyIdx = SectorSpec_Entry.SectorKeyIdx;
		brp_frame_write_int16(_frame, (unsigned)BlockAddress);
		brp_frame_write_int16(_frame, (unsigned)SectorKeyIdx);
	}
	brp_frame_write_int8(_frame, (unsigned)SectorKeysDivData_len);
	brp_frame_write(_frame, (brp_buf)SectorKeysDivData, SectorKeysDivData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_CommitReaderID(brp_protocol protocol, unsigned Block, brp_buf* EncTRI, size_t* EncTRI_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncTRI_len;
	if(EncTRI_len == NULL) EncTRI_len = &_EncTRI_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 29);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Block);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*EncTRI_len) = brp_frame_read_int8(&_reader);
	if (EncTRI != NULL) {
		(*EncTRI) = (brp_buf)brp_mempool_create_buf(mempool, (*EncTRI_len));
		if((*EncTRI) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncTRI), (*EncTRI_len));
	} else
		brp_frame_skip(&_reader, (*EncTRI_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Mif_SetFraming(brp_protocol protocol, brp_Mif_SetFraming_CommMode CommMode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int8(_frame, 28);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CommMode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MobileId_Enable(brp_protocol protocol, brp_MobileId_Enable_Mode Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 76);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MobileId_Setup(brp_protocol protocol, brp_buf Key, size_t Key_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 76);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MobileId_GetVirtualCredentialId(brp_protocol protocol, brp_buf* CredentialId, size_t* CredentialId_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _CredentialId_len;
	if(CredentialId_len == NULL) CredentialId_len = &_CredentialId_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 76);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CredentialId_len) = brp_frame_read_int8(&_reader);
	if (CredentialId != NULL) {
		(*CredentialId) = (brp_buf)brp_mempool_create_buf(mempool, (*CredentialId_len));
		if((*CredentialId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*CredentialId), (*CredentialId_len));
	} else
		brp_frame_skip(&_reader, (*CredentialId_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MsgQueue_GetMsgSize(brp_protocol protocol, unsigned* BufferSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_BufferSize;
	if (BufferSize == NULL) BufferSize = &_tmp_BufferSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 166);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*BufferSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MsgQueue_Receive(brp_protocol protocol, unsigned Timeout, brp_buf* RecvMsg, size_t* RecvMsg_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvMsg_len;
	if(RecvMsg_len == NULL) RecvMsg_len = &_RecvMsg_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 166);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 5000);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvMsg_len) = brp_frame_read_int16(&_reader);
	if (RecvMsg != NULL) {
		(*RecvMsg) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvMsg_len));
		if((*RecvMsg) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvMsg), (*RecvMsg_len));
	} else
		brp_frame_skip(&_reader, (*RecvMsg_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MsgQueue_Send(brp_protocol protocol, brp_buf SendMsg, size_t SendMsg_len, unsigned Timeout) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 166);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 5000);
	brp_frame_write_int16(_frame, (unsigned)SendMsg_len);
	brp_frame_write(_frame, (brp_buf)SendMsg, SendMsg_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_MsgQueue_SendReceive(brp_protocol protocol, brp_buf SendMsg, size_t SendMsg_len, unsigned Timeout, brp_buf* RecvMsg, size_t* RecvMsg_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvMsg_len;
	if(RecvMsg_len == NULL) RecvMsg_len = &_RecvMsg_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 166);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 5000);
	brp_frame_write_int16(_frame, (unsigned)SendMsg_len);
	brp_frame_write(_frame, (brp_buf)SendMsg, SendMsg_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvMsg_len) = brp_frame_read_int16(&_reader);
	if (RecvMsg != NULL) {
		(*RecvMsg) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvMsg_len));
		if((*RecvMsg) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvMsg), (*RecvMsg_len));
	} else
		brp_frame_skip(&_reader, (*RecvMsg_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_SetHfMode(brp_protocol protocol, unsigned HfMode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)HfMode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_RequestAnticoll(brp_protocol protocol, brp_buf* ASNB, size_t* ASNB_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ASNB_len;
	if(ASNB_len == NULL) ASNB_len = &_ASNB_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ASNB_len) = brp_frame_read_int8(&_reader);
	if (ASNB != NULL) {
		(*ASNB) = (brp_buf)brp_mempool_create_buf(mempool, (*ASNB_len));
		if((*ASNB) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ASNB), (*ASNB_len));
	} else
		brp_frame_skip(&_reader, (*ASNB_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_Select(brp_protocol protocol, brp_buf ASNB, size_t ASNB_len, brp_buf* Serial, size_t* Serial_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Serial_len;
	if(Serial_len == NULL) Serial_len = &_Serial_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ASNB_len);
	brp_frame_write(_frame, (brp_buf)ASNB, ASNB_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Serial_len) = brp_frame_read_int8(&_reader);
	if (Serial != NULL) {
		(*Serial) = (brp_buf)brp_mempool_create_buf(mempool, (*Serial_len));
		if((*Serial) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Serial), (*Serial_len));
	} else
		brp_frame_skip(&_reader, (*Serial_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_Halt(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_SelectBookPage(brp_protocol protocol, unsigned Book, unsigned Page, brp_buf* Page1, size_t* Page1_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Page1_len;
	if(Page1_len == NULL) Page1_len = &_Page1_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Book);
	brp_frame_write_int8(_frame, (unsigned)Page);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Page1_len) = brp_frame_read_int8(&_reader);
	if (Page1 != NULL) {
		(*Page1) = (brp_buf)brp_mempool_create_buf(mempool, (*Page1_len));
		if((*Page1) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Page1), (*Page1_len));
	} else
		brp_frame_skip(&_reader, (*Page1_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_Authenticate(brp_protocol protocol, bool IsDebitKey, unsigned KeyIdx) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)IsDebitKey);
	brp_frame_write_int16(_frame, (unsigned)KeyIdx);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_Read(brp_protocol protocol, unsigned PageAdr, unsigned PageNr, brp_buf* PageData, size_t* PageData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _PageData_len;
	if(PageData_len == NULL) PageData_len = &_PageData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PageAdr);
	brp_frame_write_int8(_frame, (unsigned)PageNr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PageData_len) = brp_frame_read_int8(&_reader);
	if (PageData != NULL) {
		(*PageData) = (brp_buf)brp_mempool_create_buf(mempool, (*PageData_len));
		if((*PageData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*PageData), (*PageData_len));
	} else
		brp_frame_skip(&_reader, (*PageData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pico_Write(brp_protocol protocol, unsigned PageAdr, brp_buf PageData, size_t PageData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PageAdr);
	brp_frame_write_int8(_frame, (unsigned)PageData_len);
	brp_frame_write(_frame, (brp_buf)PageData, PageData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_PfsGenKey(brp_protocol protocol, brp_buf TmpHostPubKey, size_t TmpHostPubKey_len, brp_buf* TmpRdrPubKey, size_t* TmpRdrPubKey_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _TmpRdrPubKey_len;
	if(TmpRdrPubKey_len == NULL) TmpRdrPubKey_len = &_TmpRdrPubKey_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 16000);
	brp_frame_write_int16(_frame, (unsigned)TmpHostPubKey_len);
	brp_frame_write(_frame, (brp_buf)TmpHostPubKey, TmpHostPubKey_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*TmpRdrPubKey_len) = brp_frame_read_int16(&_reader);
	if (TmpRdrPubKey != NULL) {
		(*TmpRdrPubKey) = (brp_buf)brp_mempool_create_buf(mempool, (*TmpRdrPubKey_len));
		if((*TmpRdrPubKey) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*TmpRdrPubKey), (*TmpRdrPubKey_len));
	} else
		brp_frame_skip(&_reader, (*TmpRdrPubKey_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_PfsAuthHostCert(brp_protocol protocol, brp_buf EncryptedPayload, size_t EncryptedPayload_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 16000);
	brp_frame_write_int16(_frame, (unsigned)EncryptedPayload_len);
	brp_frame_write(_frame, (brp_buf)EncryptedPayload, EncryptedPayload_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_PfsAuthRdrCert(brp_protocol protocol, brp_buf* EncryptedResponse, size_t* EncryptedResponse_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncryptedResponse_len;
	if(EncryptedResponse_len == NULL) EncryptedResponse_len = &_EncryptedResponse_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 16000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*EncryptedResponse_len) = brp_frame_read_int16(&_reader);
	if (EncryptedResponse != NULL) {
		(*EncryptedResponse) = (brp_buf)brp_mempool_create_buf(mempool, (*EncryptedResponse_len));
		if((*EncryptedResponse) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncryptedResponse), (*EncryptedResponse_len));
	} else
		brp_frame_skip(&_reader, (*EncryptedResponse_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_Tunnel2(brp_protocol protocol, unsigned SequenceCounter, brp_buf CmdHMAC, brp_buf EncryptedCmd, size_t EncryptedCmd_len, brp_buf* RspHMAC, brp_buf* EncryptedRsp, size_t* EncryptedRsp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncryptedRsp_len;
	if(EncryptedRsp_len == NULL) EncryptedRsp_len = &_EncryptedRsp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)SequenceCounter);
	size_t CmdHMAC_len = 16;
	brp_frame_write(_frame, (brp_buf)CmdHMAC, CmdHMAC_len);
	brp_frame_write_int16(_frame, (unsigned)EncryptedCmd_len);
	brp_frame_write(_frame, (brp_buf)EncryptedCmd, EncryptedCmd_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _RspHMAC_len = 16;
	size_t* RspHMAC_len = &_RspHMAC_len;
	if (RspHMAC != NULL) {
		(*RspHMAC) = (brp_buf)brp_mempool_create_buf(mempool, (*RspHMAC_len));
		if((*RspHMAC) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RspHMAC), (*RspHMAC_len));
	} else
		brp_frame_skip(&_reader, (*RspHMAC_len));
	(*EncryptedRsp_len) = brp_frame_read_int16(&_reader);
	if (EncryptedRsp != NULL) {
		(*EncryptedRsp) = (brp_buf)brp_mempool_create_buf(mempool, (*EncryptedRsp_len));
		if((*EncryptedRsp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncryptedRsp), (*EncryptedRsp_len));
	} else
		brp_frame_skip(&_reader, (*EncryptedRsp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_GetX509Csr(brp_protocol protocol, brp_buf* Csr, size_t* Csr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Csr_len;
	if(Csr_len == NULL) Csr_len = &_Csr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 16000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Csr_len) = brp_frame_read_int16(&_reader);
	if (Csr != NULL) {
		(*Csr) = (brp_buf)brp_mempool_create_buf(mempool, (*Csr_len));
		if((*Csr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Csr), (*Csr_len));
	} else
		brp_frame_skip(&_reader, (*Csr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_StoreX509Cert(brp_protocol protocol, unsigned SecLevel, brp_buf Cert, size_t Cert_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 16000);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	brp_frame_write_int16(_frame, (unsigned)Cert_len);
	brp_frame_write(_frame, (brp_buf)Cert, Cert_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Pki_StoreX509RootCert(brp_protocol protocol, unsigned SecLevel, brp_buf Cert, size_t Cert_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 16000);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	brp_frame_write_int16(_frame, (unsigned)Cert_len);
	brp_frame_write(_frame, (brp_buf)Cert, Cert_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_QKey_Read(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 53);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Rtc_GetTime(brp_protocol protocol, unsigned ClockId, unsigned* Now) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Now;
	if (Now == NULL) Now = &_tmp_Now;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ClockId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Now) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Rtc_SetTime(brp_protocol protocol, unsigned ClockId, unsigned Now) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ClockId);
	brp_frame_write_int32(_frame, (unsigned)Now);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_GetAcMask(brp_protocol protocol, unsigned SecLevel, brp_HostSecurityAccessConditionBits* AcMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _AcMask_int = brp_frame_read_int32(&_reader);
	if(AcMask != NULL)
		(AcMask->EthernetAccess) = (_AcMask_int>>28) & 0b1;
	if(AcMask != NULL)
		(AcMask->AutoreadAccess) = (_AcMask_int>>27) & 0b1;
	if(AcMask != NULL)
		(AcMask->CryptoAccess) = (_AcMask_int>>26) & 0b1;
	if(AcMask != NULL)
		(AcMask->Bf2Upload) = (_AcMask_int>>25) & 0b1;
	if(AcMask != NULL)
		(AcMask->ExtendedAccess) = (_AcMask_int>>24) & 0b1;
	if(AcMask != NULL)
		(AcMask->FlashFileSystemWrite) = (_AcMask_int>>23) & 0b1;
	if(AcMask != NULL)
		(AcMask->FlashFileSystemRead) = (_AcMask_int>>22) & 0b1;
	if(AcMask != NULL)
		(AcMask->RtcWrite) = (_AcMask_int>>21) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlExchangeapdu) = (_AcMask_int>>20) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlFormat) = (_AcMask_int>>19) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlWrite) = (_AcMask_int>>18) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlRead) = (_AcMask_int>>17) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlSelect) = (_AcMask_int>>16) & 0b1;
	if(AcMask != NULL)
		(AcMask->ExtSamAccess) = (_AcMask_int>>15) & 0b1;
	if(AcMask != NULL)
		(AcMask->HfLowlevelAccess) = (_AcMask_int>>14) & 0b1;
	if(AcMask != NULL)
		(AcMask->GuiAccess) = (_AcMask_int>>13) & 0b1;
	if(AcMask != NULL)
		(AcMask->IoPortWrite) = (_AcMask_int>>12) & 0b1;
	if(AcMask != NULL)
		(AcMask->IoPortRead) = (_AcMask_int>>11) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigReset) = (_AcMask_int>>10) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigWrite) = (_AcMask_int>>9) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigRead) = (_AcMask_int>>8) & 0b1;
	if(AcMask != NULL)
		(AcMask->SysReset) = (_AcMask_int>>7) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask2) = (_AcMask_int>>6) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask1) = (_AcMask_int>>5) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask0) = (_AcMask_int>>4) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey3) = (_AcMask_int>>3) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey2) = (_AcMask_int>>2) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey1) = (_AcMask_int>>1) & 0b1;
	if(AcMask != NULL)
		(AcMask->FactoryReset) = (_AcMask_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_SetAcMask(brp_protocol protocol, unsigned SecLevel, brp_HostSecurityAccessConditionBits AcMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	unsigned _AcMask_int = 0;
	_AcMask_int |= (AcMask.EthernetAccess & 0b1) << 28;
	_AcMask_int |= (AcMask.AutoreadAccess & 0b1) << 27;
	_AcMask_int |= (AcMask.CryptoAccess & 0b1) << 26;
	_AcMask_int |= (AcMask.Bf2Upload & 0b1) << 25;
	_AcMask_int |= (AcMask.ExtendedAccess & 0b1) << 24;
	_AcMask_int |= (AcMask.FlashFileSystemWrite & 0b1) << 23;
	_AcMask_int |= (AcMask.FlashFileSystemRead & 0b1) << 22;
	_AcMask_int |= (AcMask.RtcWrite & 0b1) << 21;
	_AcMask_int |= (AcMask.VhlExchangeapdu & 0b1) << 20;
	_AcMask_int |= (AcMask.VhlFormat & 0b1) << 19;
	_AcMask_int |= (AcMask.VhlWrite & 0b1) << 18;
	_AcMask_int |= (AcMask.VhlRead & 0b1) << 17;
	_AcMask_int |= (AcMask.VhlSelect & 0b1) << 16;
	_AcMask_int |= (AcMask.ExtSamAccess & 0b1) << 15;
	_AcMask_int |= (AcMask.HfLowlevelAccess & 0b1) << 14;
	_AcMask_int |= (AcMask.GuiAccess & 0b1) << 13;
	_AcMask_int |= (AcMask.IoPortWrite & 0b1) << 12;
	_AcMask_int |= (AcMask.IoPortRead & 0b1) << 11;
	_AcMask_int |= (AcMask.ConfigReset & 0b1) << 10;
	_AcMask_int |= (AcMask.ConfigWrite & 0b1) << 9;
	_AcMask_int |= (AcMask.ConfigRead & 0b1) << 8;
	_AcMask_int |= (AcMask.SysReset & 0b1) << 7;
	_AcMask_int |= (AcMask.SetAccessConditionMask2 & 0b1) << 6;
	_AcMask_int |= (AcMask.SetAccessConditionMask1 & 0b1) << 5;
	_AcMask_int |= (AcMask.SetAccessConditionMask0 & 0b1) << 4;
	_AcMask_int |= (AcMask.SetKey3 & 0b1) << 3;
	_AcMask_int |= (AcMask.SetKey2 & 0b1) << 2;
	_AcMask_int |= (AcMask.SetKey1 & 0b1) << 1;
	_AcMask_int |= (AcMask.FactoryReset & 0b1) << 0;
	brp_frame_write_int32(_frame, (unsigned)_AcMask_int);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_SetKey(brp_protocol protocol, unsigned ContinuousIV, unsigned Encrypted, unsigned MACed, unsigned SessionKey, unsigned DeriveKey, unsigned SecLevel, brp_buf Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 1000);
	unsigned bitmask_1772208289872 = 0;
	bitmask_1772208289872 |= (ContinuousIV & 0b1) << 7;
	bitmask_1772208289872 |= (Encrypted & 0b1) << 6;
	bitmask_1772208289872 |= (MACed & 0b1) << 5;
	bitmask_1772208289872 |= (SessionKey & 0b1) << 4;
	bitmask_1772208289872 |= (DeriveKey & 0b11) << 2;
	bitmask_1772208289872 |= (SecLevel & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208289872);
	size_t Key_len = 16;
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_AuthPhase1(brp_protocol protocol, unsigned SecLevel, brp_buf RndA, brp_buf* EncRndA, brp_buf* RndB, bool* ContinuousIV, bool* Encrypted, bool* MACed, bool* SessionKey, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	size_t RndA_len = 16;
	brp_frame_write(_frame, (brp_buf)RndA, RndA_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _EncRndA_len = 16;
	size_t* EncRndA_len = &_EncRndA_len;
	if (EncRndA != NULL) {
		(*EncRndA) = (brp_buf)brp_mempool_create_buf(mempool, (*EncRndA_len));
		if((*EncRndA) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncRndA), (*EncRndA_len));
	} else
		brp_frame_skip(&_reader, (*EncRndA_len));
	size_t _RndB_len = 16;
	size_t* RndB_len = &_RndB_len;
	if (RndB != NULL) {
		(*RndB) = (brp_buf)brp_mempool_create_buf(mempool, (*RndB_len));
		if((*RndB) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RndB), (*RndB_len));
	} else
		brp_frame_skip(&_reader, (*RndB_len));
	unsigned bitmask_1772208290640 = brp_frame_read_int8(&_reader);
	if(ContinuousIV != NULL)
		(*ContinuousIV) = (bitmask_1772208290640>>7) & 0b1;
	if(Encrypted != NULL)
		(*Encrypted) = (bitmask_1772208290640>>6) & 0b1;
	if(MACed != NULL)
		(*MACed) = (bitmask_1772208290640>>5) & 0b1;
	if(SessionKey != NULL)
		(*SessionKey) = (bitmask_1772208290640>>4) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_AuthPhase2(brp_protocol protocol, brp_buf EncRndB) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	size_t EncRndB_len = 16;
	brp_frame_write(_frame, (brp_buf)EncRndB, EncRndB_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_Tunnel(brp_protocol protocol, bool ContinuousIV, bool Encrypted, bool MACed, bool SessionKey, unsigned SecLevel, brp_buf TunnelledCmd, size_t TunnelledCmd_len, brp_buf* TunnelledResp, size_t* TunnelledResp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _TunnelledResp_len;
	if(TunnelledResp_len == NULL) TunnelledResp_len = &_TunnelledResp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208291264 = 0;
	bitmask_1772208291264 |= (ContinuousIV & 0b1) << 7;
	bitmask_1772208291264 |= (Encrypted & 0b1) << 6;
	bitmask_1772208291264 |= (MACed & 0b1) << 5;
	bitmask_1772208291264 |= (SessionKey & 0b1) << 4;
	bitmask_1772208291264 |= (SecLevel & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208291264);
	brp_frame_write(_frame, (brp_buf)TunnelledCmd, TunnelledCmd_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*TunnelledResp_len) = brp_frame_rest( & _reader);
	if (TunnelledResp != NULL) {
		(*TunnelledResp) = (brp_buf)brp_mempool_create_buf(mempool, (*TunnelledResp_len));
		if((*TunnelledResp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*TunnelledResp), (*TunnelledResp_len));
	} else
		brp_frame_skip(&_reader, (*TunnelledResp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_Reset(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 10000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_LockReset(brp_protocol protocol, unsigned SecLevel) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int8(_frame, (unsigned)SecLevel);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sec_GetCurAcMask(brp_protocol protocol, brp_HostSecurityAccessConditionBits* AcMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _AcMask_int = brp_frame_read_int32(&_reader);
	if(AcMask != NULL)
		(AcMask->EthernetAccess) = (_AcMask_int>>28) & 0b1;
	if(AcMask != NULL)
		(AcMask->AutoreadAccess) = (_AcMask_int>>27) & 0b1;
	if(AcMask != NULL)
		(AcMask->CryptoAccess) = (_AcMask_int>>26) & 0b1;
	if(AcMask != NULL)
		(AcMask->Bf2Upload) = (_AcMask_int>>25) & 0b1;
	if(AcMask != NULL)
		(AcMask->ExtendedAccess) = (_AcMask_int>>24) & 0b1;
	if(AcMask != NULL)
		(AcMask->FlashFileSystemWrite) = (_AcMask_int>>23) & 0b1;
	if(AcMask != NULL)
		(AcMask->FlashFileSystemRead) = (_AcMask_int>>22) & 0b1;
	if(AcMask != NULL)
		(AcMask->RtcWrite) = (_AcMask_int>>21) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlExchangeapdu) = (_AcMask_int>>20) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlFormat) = (_AcMask_int>>19) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlWrite) = (_AcMask_int>>18) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlRead) = (_AcMask_int>>17) & 0b1;
	if(AcMask != NULL)
		(AcMask->VhlSelect) = (_AcMask_int>>16) & 0b1;
	if(AcMask != NULL)
		(AcMask->ExtSamAccess) = (_AcMask_int>>15) & 0b1;
	if(AcMask != NULL)
		(AcMask->HfLowlevelAccess) = (_AcMask_int>>14) & 0b1;
	if(AcMask != NULL)
		(AcMask->GuiAccess) = (_AcMask_int>>13) & 0b1;
	if(AcMask != NULL)
		(AcMask->IoPortWrite) = (_AcMask_int>>12) & 0b1;
	if(AcMask != NULL)
		(AcMask->IoPortRead) = (_AcMask_int>>11) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigReset) = (_AcMask_int>>10) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigWrite) = (_AcMask_int>>9) & 0b1;
	if(AcMask != NULL)
		(AcMask->ConfigRead) = (_AcMask_int>>8) & 0b1;
	if(AcMask != NULL)
		(AcMask->SysReset) = (_AcMask_int>>7) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask2) = (_AcMask_int>>6) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask1) = (_AcMask_int>>5) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetAccessConditionMask0) = (_AcMask_int>>4) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey3) = (_AcMask_int>>3) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey2) = (_AcMask_int>>2) & 0b1;
	if(AcMask != NULL)
		(AcMask->SetKey1) = (_AcMask_int>>1) & 0b1;
	if(AcMask != NULL)
		(AcMask->FactoryReset) = (_AcMask_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Srix_Select(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Snr_len;
	if(Snr_len == NULL) Snr_len = &_Snr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 36);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Snr_len) = brp_frame_read_int8(&_reader);
	if (Snr != NULL) {
		(*Snr) = (brp_buf)brp_mempool_create_buf(mempool, (*Snr_len));
		if((*Snr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Snr), (*Snr_len));
	} else
		brp_frame_skip(&_reader, (*Snr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Srix_Read(brp_protocol protocol, unsigned Adr, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 36);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Srix_Write(brp_protocol protocol, unsigned Adr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 36);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetBufferSize(brp_protocol protocol, unsigned* MaxSendSize, unsigned* MaxRecvSize, unsigned* TotalSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_MaxSendSize;
	if (MaxSendSize == NULL) MaxSendSize = &_tmp_MaxSendSize;
	unsigned _tmp_MaxRecvSize;
	if (MaxRecvSize == NULL) MaxRecvSize = &_tmp_MaxRecvSize;
	unsigned _tmp_TotalSize;
	if (TotalSize == NULL) TotalSize = &_tmp_TotalSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 50);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MaxSendSize) = (unsigned)brp_frame_read_int16(&_reader);
	(*MaxRecvSize) = (unsigned)brp_frame_read_int16(&_reader);
	(*TotalSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_HFReset(brp_protocol protocol, unsigned OffDuration) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)OffDuration);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_Reset(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetInfo(brp_protocol protocol, char** Info, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 50);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _Info_len = 0;
	size_t* Info_len = &_Info_len;
	if (Info != NULL) {
		(*Info) = (char*)brp_mempool_create_buf(mempool, 0);
		if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(char _char = brp_frame_read_int8(&_reader); !((_char == 0x00) | brp_frame_read_err(&_reader));_char = brp_frame_read_int8(&_reader)) {
		if(Info != NULL) {
			(*Info_len) += 1;
			(*Info) = (char*)brp_mempool_resize_buf((brp_buf)(*Info), (*Info_len));
			if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Info)[(*Info_len)-1] = _char;
		}
	}
	if(Info != NULL) {
		(*Info_len) += 1;
		(*Info) = (char*)brp_mempool_resize_buf((brp_buf)(*Info), (*Info_len));
		if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*Info)[(*Info_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetBootStatus(brp_protocol protocol, brp_Sys_GetBootStatus_BootStatus* BootStatus) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 50);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _BootStatus_int = brp_frame_read_int32(&_reader);
	if(BootStatus != NULL)
		(BootStatus->NewerReaderChipFirmware) = (_BootStatus_int>>31) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->UnexpectedReboots) = (_BootStatus_int>>30) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->FactorySettings) = (_BootStatus_int>>29) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->ConfigurationInconsistent) = (_BootStatus_int>>28) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Bluetooth) = (_BootStatus_int>>23) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->WiFi) = (_BootStatus_int>>22) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Tamper) = (_BootStatus_int>>21) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->BatteryManagement) = (_BootStatus_int>>20) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Keyboard) = (_BootStatus_int>>19) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->FirmwareVersionBlocked) = (_BootStatus_int>>18) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Display) = (_BootStatus_int>>17) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->ConfCardPresented) = (_BootStatus_int>>16) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Ethernet) = (_BootStatus_int>>15) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->ExtendedLED) = (_BootStatus_int>>14) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Rf125kHz) = (_BootStatus_int>>12) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Rf13MHz) = (_BootStatus_int>>10) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Rf13MHzLegic) = (_BootStatus_int>>9) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Rf13MHzLegacy) = (_BootStatus_int>>8) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->HWoptions) = (_BootStatus_int>>7) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->RTC) = (_BootStatus_int>>5) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Dataflash) = (_BootStatus_int>>4) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->Configuration) = (_BootStatus_int>>2) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->CorruptFirmware) = (_BootStatus_int>>1) & 0b1;
	if(BootStatus != NULL)
		(BootStatus->IncompleteFirmware) = (_BootStatus_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetPort(brp_protocol protocol, brp_IoPortBitmask* PortMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _PortMask_int = brp_frame_read_int16(&_reader);
	if(PortMask != NULL)
		(PortMask->Gpio7) = (_PortMask_int>>15) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio6) = (_PortMask_int>>14) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio5) = (_PortMask_int>>13) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio4) = (_PortMask_int>>12) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio3) = (_PortMask_int>>11) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio2) = (_PortMask_int>>10) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio1) = (_PortMask_int>>9) & 0b1;
	if(PortMask != NULL)
		(PortMask->Gpio0) = (_PortMask_int>>8) & 0b1;
	if(PortMask != NULL)
		(PortMask->TamperAlarm) = (_PortMask_int>>7) & 0b1;
	if(PortMask != NULL)
		(PortMask->BlueLed) = (_PortMask_int>>6) & 0b1;
	if(PortMask != NULL)
		(PortMask->Input1) = (_PortMask_int>>5) & 0b1;
	if(PortMask != NULL)
		(PortMask->Input0) = (_PortMask_int>>4) & 0b1;
	if(PortMask != NULL)
		(PortMask->Relay) = (_PortMask_int>>3) & 0b1;
	if(PortMask != NULL)
		(PortMask->Beeper) = (_PortMask_int>>2) & 0b1;
	if(PortMask != NULL)
		(PortMask->RedLed) = (_PortMask_int>>1) & 0b1;
	if(PortMask != NULL)
		(PortMask->GreenLed) = (_PortMask_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_SetPort(brp_protocol protocol, brp_IoPortBitmask PortMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	unsigned _PortMask_int = 0;
	_PortMask_int |= (PortMask.Gpio7 & 0b1) << 15;
	_PortMask_int |= (PortMask.Gpio6 & 0b1) << 14;
	_PortMask_int |= (PortMask.Gpio5 & 0b1) << 13;
	_PortMask_int |= (PortMask.Gpio4 & 0b1) << 12;
	_PortMask_int |= (PortMask.Gpio3 & 0b1) << 11;
	_PortMask_int |= (PortMask.Gpio2 & 0b1) << 10;
	_PortMask_int |= (PortMask.Gpio1 & 0b1) << 9;
	_PortMask_int |= (PortMask.Gpio0 & 0b1) << 8;
	_PortMask_int |= (PortMask.TamperAlarm & 0b1) << 7;
	_PortMask_int |= (PortMask.BlueLed & 0b1) << 6;
	_PortMask_int |= (PortMask.Input1 & 0b1) << 5;
	_PortMask_int |= (PortMask.Input0 & 0b1) << 4;
	_PortMask_int |= (PortMask.Relay & 0b1) << 3;
	_PortMask_int |= (PortMask.Beeper & 0b1) << 2;
	_PortMask_int |= (PortMask.RedLed & 0b1) << 1;
	_PortMask_int |= (PortMask.GreenLed & 0b1) << 0;
	brp_frame_write_int16(_frame, (unsigned)_PortMask_int);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgGetValue(brp_protocol protocol, unsigned Key, unsigned Value, brp_buf* Content, size_t* Content_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Content_len;
	if(Content_len == NULL) Content_len = &_Content_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Key);
	brp_frame_write_int8(_frame, (unsigned)Value);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Content_len) = brp_frame_read_int8(&_reader);
	if (Content != NULL) {
		(*Content) = (brp_buf)brp_mempool_create_buf(mempool, (*Content_len));
		if((*Content) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Content), (*Content_len));
	} else
		brp_frame_skip(&_reader, (*Content_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgSetValue(brp_protocol protocol, unsigned Key, unsigned Value, brp_buf Content, size_t Content_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write_int16(_frame, (unsigned)Key);
	brp_frame_write_int8(_frame, (unsigned)Value);
	brp_frame_write_int8(_frame, (unsigned)Content_len);
	brp_frame_write(_frame, (brp_buf)Content, Content_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgDelValues(brp_protocol protocol, unsigned Key, unsigned Value) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write_int16(_frame, (unsigned)Key);
	brp_frame_write_int8(_frame, (unsigned)Value);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgGetKeyList(brp_protocol protocol, unsigned** KeyList, size_t* KeyList_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _KeyList_len;
	if(KeyList_len == NULL) KeyList_len = &_KeyList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*KeyList_len) = brp_frame_read_int8(&_reader);
	if (KeyList != NULL) {
		(*KeyList) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*KeyList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _KeyList_ndx = 1;!((_KeyList_ndx > (*KeyList_len)) | brp_frame_read_err(&_reader));_KeyList_ndx++) {
		unsigned _Key;
		unsigned *Key = &_Key;
		(*Key) = (unsigned)brp_frame_read_int16(&_reader);
		if (KeyList != NULL) {
			(*KeyList) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*KeyList), (_KeyList_ndx * sizeof(unsigned)));
			if((*KeyList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*KeyList)[_KeyList_ndx-1] = *Key;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgGetValueList(brp_protocol protocol, unsigned Key, unsigned** ValueList, size_t* ValueList_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ValueList_len;
	if(ValueList_len == NULL) ValueList_len = &_ValueList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 12);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Key);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ValueList_len) = brp_frame_read_int8(&_reader);
	if (ValueList != NULL) {
		(*ValueList) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*ValueList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _ValueList_ndx = 1;!((_ValueList_ndx > (*ValueList_len)) | brp_frame_read_err(&_reader));_ValueList_ndx++) {
		unsigned _Value;
		unsigned *Value = &_Value;
		(*Value) = (unsigned)brp_frame_read_int8(&_reader);
		if (ValueList != NULL) {
			(*ValueList) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*ValueList), (_ValueList_ndx * sizeof(unsigned)));
			if((*ValueList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*ValueList)[_ValueList_ndx-1] = *Value;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgWriteTlvSector(brp_protocol protocol, brp_buf TlvBlock, size_t TlvBlock_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 13);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write(_frame, (brp_buf)TlvBlock, TlvBlock_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgCheck(brp_protocol protocol, unsigned* TotalSize, unsigned* FreeSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_TotalSize;
	if (TotalSize == NULL) TotalSize = &_tmp_TotalSize;
	unsigned _tmp_FreeSize;
	if (FreeSize == NULL) FreeSize = &_tmp_FreeSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*TotalSize) = (unsigned)brp_frame_read_int16(&_reader);
	(*FreeSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_ConfigPort(brp_protocol protocol, brp_IoPortBitmask InpOutp, brp_IoPortBitmask DefaultState) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 14);
	brp_frame_write_int32(_frame, 100);
	unsigned _InpOutp_int = 0;
	_InpOutp_int |= (InpOutp.Gpio7 & 0b1) << 15;
	_InpOutp_int |= (InpOutp.Gpio6 & 0b1) << 14;
	_InpOutp_int |= (InpOutp.Gpio5 & 0b1) << 13;
	_InpOutp_int |= (InpOutp.Gpio4 & 0b1) << 12;
	_InpOutp_int |= (InpOutp.Gpio3 & 0b1) << 11;
	_InpOutp_int |= (InpOutp.Gpio2 & 0b1) << 10;
	_InpOutp_int |= (InpOutp.Gpio1 & 0b1) << 9;
	_InpOutp_int |= (InpOutp.Gpio0 & 0b1) << 8;
	_InpOutp_int |= (InpOutp.TamperAlarm & 0b1) << 7;
	_InpOutp_int |= (InpOutp.BlueLed & 0b1) << 6;
	_InpOutp_int |= (InpOutp.Input1 & 0b1) << 5;
	_InpOutp_int |= (InpOutp.Input0 & 0b1) << 4;
	_InpOutp_int |= (InpOutp.Relay & 0b1) << 3;
	_InpOutp_int |= (InpOutp.Beeper & 0b1) << 2;
	_InpOutp_int |= (InpOutp.RedLed & 0b1) << 1;
	_InpOutp_int |= (InpOutp.GreenLed & 0b1) << 0;
	brp_frame_write_int16(_frame, (unsigned)_InpOutp_int);
	unsigned _DefaultState_int = 0;
	_DefaultState_int |= (DefaultState.Gpio7 & 0b1) << 15;
	_DefaultState_int |= (DefaultState.Gpio6 & 0b1) << 14;
	_DefaultState_int |= (DefaultState.Gpio5 & 0b1) << 13;
	_DefaultState_int |= (DefaultState.Gpio4 & 0b1) << 12;
	_DefaultState_int |= (DefaultState.Gpio3 & 0b1) << 11;
	_DefaultState_int |= (DefaultState.Gpio2 & 0b1) << 10;
	_DefaultState_int |= (DefaultState.Gpio1 & 0b1) << 9;
	_DefaultState_int |= (DefaultState.Gpio0 & 0b1) << 8;
	_DefaultState_int |= (DefaultState.TamperAlarm & 0b1) << 7;
	_DefaultState_int |= (DefaultState.BlueLed & 0b1) << 6;
	_DefaultState_int |= (DefaultState.Input1 & 0b1) << 5;
	_DefaultState_int |= (DefaultState.Input0 & 0b1) << 4;
	_DefaultState_int |= (DefaultState.Relay & 0b1) << 3;
	_DefaultState_int |= (DefaultState.Beeper & 0b1) << 2;
	_DefaultState_int |= (DefaultState.RedLed & 0b1) << 1;
	_DefaultState_int |= (DefaultState.GreenLed & 0b1) << 0;
	brp_frame_write_int16(_frame, (unsigned)_DefaultState_int);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_SetRegister(brp_protocol protocol, bool ResetRegister, brp_Sys_SetRegister_RegisterAssignments_Entry* RegisterAssignments, size_t RegisterAssignments_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 15);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ResetRegister);
	brp_frame_write_int8(_frame, (unsigned)RegisterAssignments_len);
	for(size_t _RegisterAssignments_ndx = 0;_RegisterAssignments_ndx < RegisterAssignments_len;_RegisterAssignments_ndx++) {
		brp_Sys_SetRegister_RegisterAssignments_Entry RegisterAssignments_Entry = RegisterAssignments[_RegisterAssignments_ndx];
		unsigned ID = RegisterAssignments_Entry.ID;
		unsigned Value = RegisterAssignments_Entry.Value;
		brp_frame_write_int16(_frame, (unsigned)ID);
		brp_frame_write_int16(_frame, (unsigned)Value);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetRegister(brp_protocol protocol, unsigned ID, unsigned* Value) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Value;
	if (Value == NULL) Value = &_tmp_Value;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)ID);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Value) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_PowerDown(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_SelectProtocol(brp_protocol protocol, brp_ProtocolID Protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Protocol);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_SetCommParam(brp_protocol protocol, brp_Baudrate NewBaudrate, brp_Parity NewParity, unsigned CWT) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)NewBaudrate);
	brp_frame_write_int8(_frame, (unsigned)NewParity);
	brp_frame_write_int8(_frame, (unsigned)CWT);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgLoadBlock(brp_protocol protocol, unsigned Version, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write_int8(_frame, (unsigned)Version);
	brp_frame_write_int8(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetPlatformId(brp_protocol protocol, brp_buf* PlatformId, unsigned* BootloaderId, unsigned* BootloaderMajor, unsigned* BootloaderMinor, unsigned* BootloaderBuild, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_BootloaderId;
	if (BootloaderId == NULL) BootloaderId = &_tmp_BootloaderId;
	unsigned _tmp_BootloaderMajor;
	if (BootloaderMajor == NULL) BootloaderMajor = &_tmp_BootloaderMajor;
	unsigned _tmp_BootloaderMinor;
	if (BootloaderMinor == NULL) BootloaderMinor = &_tmp_BootloaderMinor;
	unsigned _tmp_BootloaderBuild;
	if (BootloaderBuild == NULL) BootloaderBuild = &_tmp_BootloaderBuild;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 23);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _PlatformId_len = 5;
	size_t* PlatformId_len = &_PlatformId_len;
	if (PlatformId != NULL) {
		(*PlatformId) = (brp_buf)brp_mempool_create_buf(mempool, (*PlatformId_len));
		if((*PlatformId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*PlatformId), (*PlatformId_len));
	} else
		brp_frame_skip(&_reader, (*PlatformId_len));
	(*BootloaderId) = (unsigned)brp_frame_read_int8(&_reader);
	(*BootloaderMajor) = (unsigned)brp_frame_read_int8(&_reader);
	(*BootloaderMinor) = (unsigned)brp_frame_read_int8(&_reader);
	(*BootloaderBuild) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgReset(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 24);
	brp_frame_write_int32(_frame, 10000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_StopProtocol(brp_protocol protocol, brp_ProtocolID Protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 25);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Protocol);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgGetId(brp_protocol protocol, char** ConfigId, char** ConfigName, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _ConfigId_len = 0;
	size_t* ConfigId_len = &_ConfigId_len;
	(*ConfigId_len) = brp_frame_read_int8(&_reader);
	if (ConfigId != NULL) {
		(*ConfigId) = (char*)brp_mempool_create_buf(mempool, (*ConfigId_len));
		if((*ConfigId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ConfigId), (*ConfigId_len));
	} else
		brp_frame_skip(&_reader, (*ConfigId_len));
	if(ConfigId != NULL) {
		(*ConfigId_len) += 1;
		(*ConfigId) = (char*)brp_mempool_resize_buf((brp_buf)(*ConfigId), (*ConfigId_len));
		if((*ConfigId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*ConfigId)[(*ConfigId_len)-1] = 0;
	}
	size_t _ConfigName_len = 0;
	size_t* ConfigName_len = &_ConfigName_len;
	(*ConfigName_len) = brp_frame_read_int8(&_reader);
	if (ConfigName != NULL) {
		(*ConfigName) = (char*)brp_mempool_create_buf(mempool, (*ConfigName_len));
		if((*ConfigName) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ConfigName), (*ConfigName_len));
	} else
		brp_frame_skip(&_reader, (*ConfigName_len));
	if(ConfigName != NULL) {
		(*ConfigName_len) += 1;
		(*ConfigName) = (char*)brp_mempool_resize_buf((brp_buf)(*ConfigName), (*ConfigName_len));
		if((*ConfigName) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*ConfigName)[(*ConfigName_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgGetDeviceSettingsId(brp_protocol protocol, char** ConfigId, char** ConfigName, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _ConfigId_len = 0;
	size_t* ConfigId_len = &_ConfigId_len;
	(*ConfigId_len) = brp_frame_read_int8(&_reader);
	if (ConfigId != NULL) {
		(*ConfigId) = (char*)brp_mempool_create_buf(mempool, (*ConfigId_len));
		if((*ConfigId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ConfigId), (*ConfigId_len));
	} else
		brp_frame_skip(&_reader, (*ConfigId_len));
	if(ConfigId != NULL) {
		(*ConfigId_len) += 1;
		(*ConfigId) = (char*)brp_mempool_resize_buf((brp_buf)(*ConfigId), (*ConfigId_len));
		if((*ConfigId) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*ConfigId)[(*ConfigId_len)-1] = 0;
	}
	size_t _ConfigName_len = 0;
	size_t* ConfigName_len = &_ConfigName_len;
	(*ConfigName_len) = brp_frame_read_int8(&_reader);
	if (ConfigName != NULL) {
		(*ConfigName) = (char*)brp_mempool_create_buf(mempool, (*ConfigName_len));
		if((*ConfigName) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ConfigName), (*ConfigName_len));
	} else
		brp_frame_skip(&_reader, (*ConfigName_len));
	if(ConfigName != NULL) {
		(*ConfigName_len) += 1;
		(*ConfigName) = (char*)brp_mempool_resize_buf((brp_buf)(*ConfigName), (*ConfigName_len));
		if((*ConfigName) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*ConfigName)[(*ConfigName_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_FactoryResetLegacy(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int32(_frame, 30000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetStatistics(brp_protocol protocol, bool DeleteCounters, brp_Sys_GetStatistics_CounterTuple_Entry** CounterTuple, size_t* CounterTuple_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _CounterTuple_len;
	if(CounterTuple_len == NULL) CounterTuple_len = &_CounterTuple_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 35);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)DeleteCounters);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CounterTuple_len) = brp_frame_read_int8(&_reader);
	if (CounterTuple != NULL) {
		(*CounterTuple) = (brp_Sys_GetStatistics_CounterTuple_Entry*)brp_mempool_create_buf(mempool, 0);
		if((*CounterTuple) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _CounterTuple_ndx = 1;!((_CounterTuple_ndx > (*CounterTuple_len)) | brp_frame_read_err(&_reader));_CounterTuple_ndx++) {
		brp_Sys_GetStatistics_CounterTuple_Entry _CounterTuple_Entry;
		brp_Sys_GetStatistics_CounterTuple_Entry *CounterTuple_Entry = &_CounterTuple_Entry;
		unsigned _ID;
		unsigned *ID = &_ID;
		unsigned _Value;
		unsigned *Value = &_Value;
		(*ID) = (unsigned)brp_frame_read_int8(&_reader);
		(*Value) = (unsigned)brp_frame_read_int8(&_reader);
		if(CounterTuple_Entry != NULL) {
			CounterTuple_Entry->ID = *ID;
			CounterTuple_Entry->Value = *Value;
		}
		if (CounterTuple != NULL) {
			(*CounterTuple) = (brp_Sys_GetStatistics_CounterTuple_Entry*)brp_mempool_resize_buf((brp_buf)(*CounterTuple), (_CounterTuple_ndx * sizeof(brp_Sys_GetStatistics_CounterTuple_Entry)));
			if((*CounterTuple) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*CounterTuple)[_CounterTuple_ndx-1] = *CounterTuple_Entry;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetFeatures(brp_protocol protocol, brp_FeatureID** FeatureList, size_t* FeatureList_len, brp_FeatureID* MaxFeatureID, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _FeatureList_len;
	if(FeatureList_len == NULL) FeatureList_len = &_FeatureList_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 36);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*FeatureList_len) = brp_frame_read_int8(&_reader);
	if (FeatureList != NULL) {
		(*FeatureList) = (brp_FeatureID*)brp_mempool_create_buf(mempool, 0);
		if((*FeatureList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _FeatureList_ndx = 1;!((_FeatureList_ndx > (*FeatureList_len)) | brp_frame_read_err(&_reader));_FeatureList_ndx++) {
		brp_FeatureID _SupportedFeatureID;
		brp_FeatureID *SupportedFeatureID = &_SupportedFeatureID;
		int _SupportedFeatureID_int_val = brp_frame_read_int16(&_reader);
		if (SupportedFeatureID != NULL) {
			if (brp_FeatureID_is_valid(_SupportedFeatureID_int_val))
				(*SupportedFeatureID) = (brp_FeatureID)_SupportedFeatureID_int_val;
			else
				(*SupportedFeatureID) = brp_FeatureID_undefined;
		}
		if (FeatureList != NULL) {
			(*FeatureList) = (brp_FeatureID*)brp_mempool_resize_buf((brp_buf)(*FeatureList), (_FeatureList_ndx * sizeof(brp_FeatureID)));
			if((*FeatureList) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*FeatureList)[_FeatureList_ndx-1] = *SupportedFeatureID;
		}
	}
	int _MaxFeatureID_int_val = brp_frame_read_int16(&_reader);
	if (MaxFeatureID != NULL) {
		if (brp_FeatureID_is_valid(_MaxFeatureID_int_val))
			(*MaxFeatureID) = (brp_FeatureID)_MaxFeatureID_int_val;
		else
			(*MaxFeatureID) = brp_FeatureID_undefined;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetPartNumber(brp_protocol protocol, char** PartNo, char** HwRevNo, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _PartNo_len = 0;
	size_t* PartNo_len = &_PartNo_len;
	(*PartNo_len) = brp_frame_read_int8(&_reader);
	if (PartNo != NULL) {
		(*PartNo) = (char*)brp_mempool_create_buf(mempool, (*PartNo_len));
		if((*PartNo) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*PartNo), (*PartNo_len));
	} else
		brp_frame_skip(&_reader, (*PartNo_len));
	if(PartNo != NULL) {
		(*PartNo_len) += 1;
		(*PartNo) = (char*)brp_mempool_resize_buf((brp_buf)(*PartNo), (*PartNo_len));
		if((*PartNo) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*PartNo)[(*PartNo_len)-1] = 0;
	}
	size_t _HwRevNo_len = 0;
	size_t* HwRevNo_len = &_HwRevNo_len;
	(*HwRevNo_len) = brp_frame_read_int8(&_reader);
	if (HwRevNo != NULL) {
		(*HwRevNo) = (char*)brp_mempool_create_buf(mempool, (*HwRevNo_len));
		if((*HwRevNo) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*HwRevNo), (*HwRevNo_len));
	} else
		brp_frame_skip(&_reader, (*HwRevNo_len));
	if(HwRevNo != NULL) {
		(*HwRevNo_len) += 1;
		(*HwRevNo) = (char*)brp_mempool_resize_buf((brp_buf)(*HwRevNo), (*HwRevNo_len));
		if((*HwRevNo) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*HwRevNo)[(*HwRevNo_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgLoadPrepare(brp_protocol protocol, brp_AuthReqUpload AuthReq) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 38);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write_int8(_frame, (unsigned)AuthReq);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_CfgLoadFinish(brp_protocol protocol, brp_Sys_CfgLoadFinish_FinalizeAction FinalizeAction) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 39);
	brp_frame_write_int32(_frame, 10000);
	brp_frame_write_int8(_frame, (unsigned)FinalizeAction);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_FactoryReset(brp_protocol protocol, bool PerformReboot) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 40);
	brp_frame_write_int32(_frame, 30000);
	brp_frame_write_int8(_frame, (unsigned)PerformReboot);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetLicenses(brp_protocol protocol, brp_LicenseBitMask* LicenseBitMask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 41);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	unsigned _LicenseBitMask_int = brp_frame_read_int32(&_reader);
	if(LicenseBitMask != NULL)
		(LicenseBitMask->Ble) = (_LicenseBitMask_int>>3) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->BleLicRequired) = (_LicenseBitMask_int>>2) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->HidOnlyForSE) = (_LicenseBitMask_int>>1) & 0b1;
	if(LicenseBitMask != NULL)
		(LicenseBitMask->Hid) = (_LicenseBitMask_int>>0) & 0b1;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Sys_GetFwCrc(brp_protocol protocol, unsigned* CRC) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_CRC;
	if (CRC == NULL) CRC = &_tmp_CRC;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 127);
	brp_frame_write_int32(_frame, 1000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CRC) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_TTF_ReadByteStream(brp_protocol protocol, bool ResetDataPtr, unsigned SamplingTime, unsigned Rxlen, brp_TTF_ReadByteStream_RxMod RxMod, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 52);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208776112 = 0;
	bitmask_1772208776112 |= (ResetDataPtr & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208776112);
	brp_frame_write_int8(_frame, (unsigned)SamplingTime);
	brp_frame_write_int16(_frame, (unsigned)Rxlen);
	brp_frame_write_int8(_frame, (unsigned)RxMod);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int16(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_TTF_IdteckRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 52);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int8(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_UidReplyRound(brp_protocol protocol, bool EPC, bool FixSlot, unsigned SlotCoding, unsigned MaskLength, brp_buf SelectionMask, size_t SelectionMask_len, unsigned HashValue, unsigned* MemStatusFlag, unsigned* LabelNr, unsigned* LabelLength, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _LabelData_len;
	if(LabelData_len == NULL) LabelData_len = &_LabelData_len;
	unsigned _tmp_MemStatusFlag;
	if (MemStatusFlag == NULL) MemStatusFlag = &_tmp_MemStatusFlag;
	unsigned _tmp_LabelNr;
	if (LabelNr == NULL) LabelNr = &_tmp_LabelNr;
	unsigned _tmp_LabelLength;
	if (LabelLength == NULL) LabelLength = &_tmp_LabelLength;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208777360 = 0;
	bitmask_1772208777360 |= (EPC & 0b1) << 1;
	bitmask_1772208777360 |= (FixSlot & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208777360);
	brp_frame_write_int8(_frame, (unsigned)SlotCoding);
	brp_frame_write_int8(_frame, (unsigned)MaskLength);
	brp_frame_write_int8(_frame, (unsigned)SelectionMask_len);
	brp_frame_write(_frame, (brp_buf)SelectionMask, SelectionMask_len);
	if(EPC) {
		brp_frame_write_int8(_frame, (unsigned)HashValue);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MemStatusFlag) = (unsigned)brp_frame_read_int8(&_reader);
	(*LabelNr) = (unsigned)brp_frame_read_int16(&_reader);
	(*LabelLength) = (unsigned)brp_frame_read_int8(&_reader);
	(*LabelData_len) = brp_frame_rest( & _reader);
	if (LabelData != NULL) {
		(*LabelData) = (brp_buf)brp_mempool_create_buf(mempool, (*LabelData_len));
		if((*LabelData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LabelData), (*LabelData_len));
	} else
		brp_frame_skip(&_reader, (*LabelData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_UidWrite(brp_protocol protocol, bool EPC, unsigned BlockAdr, brp_buf BlockData, size_t BlockData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208778176 = 0;
	bitmask_1772208778176 |= (EPC & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208778176);
	brp_frame_write_int8(_frame, (unsigned)BlockAdr);
	brp_frame_write_int8(_frame, (unsigned)BlockData_len);
	brp_frame_write(_frame, (brp_buf)BlockData, BlockData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_UidDestroy(brp_protocol protocol, brp_buf EpcUidData, size_t EpcUidData_len, brp_buf DestroyCode, size_t DestroyCode_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)EpcUidData_len);
	brp_frame_write(_frame, (brp_buf)EpcUidData, EpcUidData_len);
	brp_frame_write_int8(_frame, (unsigned)DestroyCode_len);
	brp_frame_write(_frame, (brp_buf)DestroyCode, DestroyCode_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_EpcSetMode(brp_protocol protocol, unsigned DR848, brp_EpcUid_EpcSetMode_Coding Coding) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208778800 = 0;
	bitmask_1772208778800 |= (DR848 & 0b1) << 2;
	bitmask_1772208778800 |= (Coding & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208778800);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_EpcSelect(brp_protocol protocol, unsigned Truncate, unsigned Target, unsigned Action, brp_EpcUid_EpcSelect_MemBank MemBank, unsigned MaskPointerLength, brp_buf MaskPointer, size_t MaskPointer_len, unsigned MaskLength, brp_buf SelectionMask, size_t SelectionMask_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208779328 = 0;
	bitmask_1772208779328 |= (Truncate & 0b1) << 6;
	bitmask_1772208779328 |= (Target & 0b111) << 3;
	bitmask_1772208779328 |= (Action & 0b111) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208779328);
	brp_frame_write_int8(_frame, (unsigned)MemBank);
	brp_frame_write_int8(_frame, (unsigned)MaskPointerLength);
	brp_frame_write_int8(_frame, (unsigned)MaskPointer_len);
	brp_frame_write(_frame, (brp_buf)MaskPointer, MaskPointer_len);
	brp_frame_write_int8(_frame, (unsigned)MaskLength);
	brp_frame_write(_frame, (brp_buf)SelectionMask, SelectionMask_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_EpcUid_EpcInventory(brp_protocol protocol, unsigned Sel, unsigned Session, unsigned SlotCoding, unsigned* MemStatusFlag, unsigned* LabelNr, brp_buf* LabelData, size_t* LabelData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _LabelData_len;
	if(LabelData_len == NULL) LabelData_len = &_LabelData_len;
	unsigned _tmp_MemStatusFlag;
	if (MemStatusFlag == NULL) MemStatusFlag = &_tmp_MemStatusFlag;
	unsigned _tmp_LabelNr;
	if (LabelNr == NULL) LabelNr = &_tmp_LabelNr;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208780096 = 0;
	bitmask_1772208780096 |= (Sel & 0b11) << 2;
	bitmask_1772208780096 |= (Session & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208780096);
	brp_frame_write_int8(_frame, (unsigned)SlotCoding);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MemStatusFlag) = (unsigned)brp_frame_read_int8(&_reader);
	(*LabelNr) = (unsigned)brp_frame_read_int16(&_reader);
	(*LabelData_len) = brp_frame_rest( & _reader);
	if (LabelData != NULL) {
		(*LabelData) = (brp_buf)brp_mempool_create_buf(mempool, (*LabelData_len));
		if((*LabelData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*LabelData), (*LabelData_len));
	} else
		brp_frame_skip(&_reader, (*LabelData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ultralight_ExecCmd(brp_protocol protocol, unsigned Cmd, brp_buf Param, size_t Param_len, brp_buf* Response, size_t* Response_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Response_len;
	if(Response_len == NULL) Response_len = &_Response_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Cmd);
	brp_frame_write_int8(_frame, (unsigned)Param_len);
	brp_frame_write(_frame, (brp_buf)Param, Param_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Response_len) = brp_frame_read_int8(&_reader);
	if (Response != NULL) {
		(*Response) = (brp_buf)brp_mempool_create_buf(mempool, (*Response_len));
		if((*Response) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Response), (*Response_len));
	} else
		brp_frame_skip(&_reader, (*Response_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ultralight_Read(brp_protocol protocol, unsigned PageAdr, brp_buf* PageData, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PageAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _PageData_len = 16;
	size_t* PageData_len = &_PageData_len;
	if (PageData != NULL) {
		(*PageData) = (brp_buf)brp_mempool_create_buf(mempool, (*PageData_len));
		if((*PageData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*PageData), (*PageData_len));
	} else
		brp_frame_skip(&_reader, (*PageData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ultralight_Write(brp_protocol protocol, unsigned PageAdr, brp_buf PageData) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PageAdr);
	size_t PageData_len = 4;
	brp_frame_write(_frame, (brp_buf)PageData, PageData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ultralight_AuthE2(brp_protocol protocol, brp_Ultralight_AuthE2_DivMode DivMode, bool HasExtIdx, unsigned KeyIdx, brp_buf DivData, size_t DivData_len, unsigned KeyExtIdx) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208782064 = 0;
	bitmask_1772208782064 |= (DivMode & 0b11) << 1;
	bitmask_1772208782064 |= (HasExtIdx & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208782064);
	brp_frame_write_int8(_frame, (unsigned)KeyIdx);
	brp_frame_write_int8(_frame, (unsigned)DivData_len);
	brp_frame_write(_frame, (brp_buf)DivData, DivData_len);
	if(HasExtIdx) {
		brp_frame_write_int8(_frame, (unsigned)KeyExtIdx);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_Ultralight_AuthUser(brp_protocol protocol, brp_Ultralight_AuthUser_CryptoMode CryptoMode, brp_buf Key, size_t Key_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772208782784 = 0;
	bitmask_1772208782784 |= (CryptoMode & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772208782784);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_SendAuth1(brp_protocol protocol, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _SendParams_len;
	if(SendParams_len == NULL) SendParams_len = &_SendParams_len;
	unsigned _tmp_SendDevCode;
	if (SendDevCode == NULL) SendDevCode = &_tmp_SendDevCode;
	unsigned _tmp_SendCmdCode;
	if (SendCmdCode == NULL) SendCmdCode = &_tmp_SendCmdCode;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SendDevCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendCmdCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendParams_len) = brp_frame_read_int16(&_reader);
	if (SendParams != NULL) {
		(*SendParams) = (brp_buf)brp_mempool_create_buf(mempool, (*SendParams_len));
		if((*SendParams) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*SendParams), (*SendParams_len));
	} else
		brp_frame_skip(&_reader, (*SendParams_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_RecvAuth1(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)RecvStatus);
	brp_frame_write_int16(_frame, (unsigned)RecvResult_len);
	brp_frame_write(_frame, (brp_buf)RecvResult, RecvResult_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_SendAuth2(brp_protocol protocol, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _SendParams_len;
	if(SendParams_len == NULL) SendParams_len = &_SendParams_len;
	unsigned _tmp_SendDevCode;
	if (SendDevCode == NULL) SendDevCode = &_tmp_SendDevCode;
	unsigned _tmp_SendCmdCode;
	if (SendCmdCode == NULL) SendCmdCode = &_tmp_SendCmdCode;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SendDevCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendCmdCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendParams_len) = brp_frame_read_int16(&_reader);
	if (SendParams != NULL) {
		(*SendParams) = (brp_buf)brp_mempool_create_buf(mempool, (*SendParams_len));
		if((*SendParams) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*SendParams), (*SendParams_len));
	} else
		brp_frame_skip(&_reader, (*SendParams_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_RecvAuth2(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)RecvStatus);
	brp_frame_write_int16(_frame, (unsigned)RecvResult_len);
	brp_frame_write(_frame, (brp_buf)RecvResult, RecvResult_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_SendEncryptedCmd(brp_protocol protocol, brp_buf Signature, unsigned DevCode, unsigned CmdCode, brp_buf Params, size_t Params_len, unsigned* SendDevCode, unsigned* SendCmdCode, brp_buf* SendParams, size_t* SendParams_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _SendParams_len;
	if(SendParams_len == NULL) SendParams_len = &_SendParams_len;
	unsigned _tmp_SendDevCode;
	if (SendDevCode == NULL) SendDevCode = &_tmp_SendDevCode;
	unsigned _tmp_SendCmdCode;
	if (SendCmdCode == NULL) SendCmdCode = &_tmp_SendCmdCode;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	size_t Signature_len = 16;
	brp_frame_write(_frame, (brp_buf)Signature, Signature_len);
	brp_frame_write_int8(_frame, (unsigned)DevCode);
	brp_frame_write_int8(_frame, (unsigned)CmdCode);
	brp_frame_write_int16(_frame, (unsigned)Params_len);
	brp_frame_write(_frame, (brp_buf)Params, Params_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*SendDevCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendCmdCode) = (unsigned)brp_frame_read_int8(&_reader);
	(*SendParams_len) = brp_frame_read_int16(&_reader);
	if (SendParams != NULL) {
		(*SendParams) = (brp_buf)brp_mempool_create_buf(mempool, (*SendParams_len));
		if((*SendParams) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*SendParams), (*SendParams_len));
	} else
		brp_frame_skip(&_reader, (*SendParams_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UlRdr_RecvEncryptedCmd(brp_protocol protocol, unsigned RecvStatus, brp_buf RecvResult, size_t RecvResult_len, unsigned* Status) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Status;
	if (Status == NULL) Status = &_tmp_Status;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 165);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)RecvStatus);
	brp_frame_write_int16(_frame, (unsigned)RecvResult_len);
	brp_frame_write(_frame, (brp_buf)RecvResult, RecvResult_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Status) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_Enable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_IsConnected(brp_protocol protocol, bool* Connected) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_Connected;
	if (Connected == NULL) Connected = &_tmp_Connected;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Connected) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_SetupPipes(brp_protocol protocol, brp_UsbHost_SetupPipes_Pipes_Entry* Pipes, size_t Pipes_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Pipes_len);
	for(size_t _Pipes_ndx = 0;_Pipes_ndx < Pipes_len;_Pipes_ndx++) {
		brp_UsbHost_SetupPipes_Pipes_Entry Pipes_Entry = Pipes[_Pipes_ndx];
		unsigned No = Pipes_Entry.No;
		brp_UsbHost_SetupPipes_Type Type = Pipes_Entry.Type;
		unsigned FrameSize = Pipes_Entry.FrameSize;
		brp_frame_write_int8(_frame, (unsigned)No);
		brp_frame_write_int8(_frame, (unsigned)Type);
		brp_frame_write_int8(_frame, (unsigned)FrameSize);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_SetAddr(brp_protocol protocol, unsigned Address) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Address);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_Reset(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_TransRawSetup(brp_protocol protocol, brp_buf SetupData, unsigned PipeNo, unsigned Timeout) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	size_t SetupData_len = 8;
	brp_frame_write(_frame, (brp_buf)SetupData, SetupData_len);
	brp_frame_write_int8(_frame, (unsigned)PipeNo);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_TransSetupIn(brp_protocol protocol, brp_buf SetupData, unsigned PipeNo, unsigned Timeout, brp_buf* InData, size_t* InData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _InData_len;
	if(InData_len == NULL) InData_len = &_InData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	size_t SetupData_len = 8;
	brp_frame_write(_frame, (brp_buf)SetupData, SetupData_len);
	brp_frame_write_int8(_frame, (unsigned)PipeNo);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*InData_len) = brp_frame_read_int16(&_reader);
	if (InData != NULL) {
		(*InData) = (brp_buf)brp_mempool_create_buf(mempool, (*InData_len));
		if((*InData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*InData), (*InData_len));
	} else
		brp_frame_skip(&_reader, (*InData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_TransSetupOut(brp_protocol protocol, brp_buf SetupData, brp_buf OutData, size_t OutData_len, unsigned PipeNo, unsigned Timeout) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	size_t SetupData_len = 8;
	brp_frame_write(_frame, (brp_buf)SetupData, SetupData_len);
	brp_frame_write_int16(_frame, (unsigned)OutData_len);
	brp_frame_write(_frame, (brp_buf)OutData, OutData_len);
	brp_frame_write_int8(_frame, (unsigned)PipeNo);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_TransIn(brp_protocol protocol, unsigned PipeNo, unsigned Timeout, brp_buf* InData, size_t* InData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _InData_len;
	if(InData_len == NULL) InData_len = &_InData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)PipeNo);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*InData_len) = brp_frame_read_int16(&_reader);
	if (InData != NULL) {
		(*InData) = (brp_buf)brp_mempool_create_buf(mempool, (*InData_len));
		if((*InData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*InData), (*InData_len));
	} else
		brp_frame_skip(&_reader, (*InData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_TransOut(brp_protocol protocol, brp_buf OutData, size_t OutData_len, unsigned PipeNo, bool Continue, unsigned Timeout) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)OutData_len);
	brp_frame_write(_frame, (brp_buf)OutData, OutData_len);
	brp_frame_write_int8(_frame, (unsigned)PipeNo);
	brp_frame_write_int8(_frame, (unsigned)Continue);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_Suspend(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UsbHost_Resume(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int8(_frame, 12);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UI_Enable(brp_protocol protocol, brp_IoPort Port) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UI_Disable(brp_protocol protocol, brp_IoPort Port) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UI_Toggle(brp_protocol protocol, brp_IoPort Port, unsigned ToggleCount, unsigned Timespan1, unsigned Timespan2, brp_UI_Toggle_Polarity Polarity) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int8(_frame, (unsigned)ToggleCount);
	brp_frame_write_int16(_frame, (unsigned)Timespan1);
	brp_frame_write_int16(_frame, (unsigned)Timespan2);
	brp_frame_write_int8(_frame, (unsigned)Polarity);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UI_SetRgbLed(brp_protocol protocol, unsigned LedBitMask, unsigned RgbColor, unsigned TransitionTime) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)LedBitMask);
	brp_frame_write_int32(_frame, (unsigned)RgbColor);
	brp_frame_write_int16(_frame, (unsigned)TransitionTime);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_UI_PulseRgbLed(brp_protocol protocol, unsigned LedBitMask, unsigned RgbColor1, unsigned RgbColor2, unsigned TransitionTime, unsigned Period) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)LedBitMask);
	brp_frame_write_int32(_frame, (unsigned)RgbColor1);
	brp_frame_write_int32(_frame, (unsigned)RgbColor2);
	brp_frame_write_int16(_frame, (unsigned)TransitionTime);
	brp_frame_write_int16(_frame, (unsigned)Period);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_Select(brp_protocol protocol, brp_CardFamilies CardFamiliesFilter, bool Reselect, bool AcceptConfCard, brp_CardType* SelectedCardType) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 3000);
	unsigned _CardFamiliesFilter_int = 0;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.LEGICPrime & 0b1) << 11;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.BluetoothMce & 0b1) << 10;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Khz125Part2 & 0b1) << 9;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Srix & 0b1) << 8;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Khz125Part1 & 0b1) << 7;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Felica & 0b1) << 6;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.IClass & 0b1) << 5;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.IClassIso14B & 0b1) << 4;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Iso14443B & 0b1) << 3;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Iso15693 & 0b1) << 2;
	_CardFamiliesFilter_int |= (CardFamiliesFilter.Iso14443A & 0b1) << 0;
	brp_frame_write_int16(_frame, (unsigned)_CardFamiliesFilter_int);
	brp_frame_write_int8(_frame, (unsigned)Reselect);
	brp_frame_write_int8(_frame, (unsigned)AcceptConfCard);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _SelectedCardType_int_val = brp_frame_read_int8(&_reader);
	if (SelectedCardType != NULL) {
		if (brp_CardType_is_valid(_SelectedCardType_int_val))
			(*SelectedCardType) = (brp_CardType)_SelectedCardType_int_val;
		else
			(*SelectedCardType) = brp_CardType_undefined;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_GetSnr(brp_protocol protocol, brp_buf* Snr, size_t* Snr_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Snr_len;
	if(Snr_len == NULL) Snr_len = &_Snr_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Snr_len) = brp_frame_rest( & _reader);
	if (Snr != NULL) {
		(*Snr) = (brp_buf)brp_mempool_create_buf(mempool, (*Snr_len));
		if((*Snr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Snr), (*Snr_len));
	} else
		brp_frame_skip(&_reader, (*Snr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_Read(brp_protocol protocol, unsigned Id, unsigned Adr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)Id);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_Write(brp_protocol protocol, unsigned Id, unsigned Adr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 3000);
	brp_frame_write_int8(_frame, (unsigned)Id);
	brp_frame_write_int16(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_IsSelected(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 3000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_GetLegacyATR(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ATR_len;
	if(ATR_len == NULL) ATR_len = &_ATR_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ATR_len) = brp_frame_read_int8(&_reader);
	if (ATR != NULL) {
		(*ATR) = (brp_buf)brp_mempool_create_buf(mempool, (*ATR_len));
		if((*ATR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATR), (*ATR_len));
	} else
		brp_frame_skip(&_reader, (*ATR_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_ExchangeAPDU(brp_protocol protocol, brp_CardType AssumedCardType, brp_buf Cmd, size_t Cmd_len, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 60000);
	brp_frame_write_int8(_frame, (unsigned)AssumedCardType);
	brp_frame_write_int16(_frame, (unsigned)Cmd_len);
	brp_frame_write(_frame, (brp_buf)Cmd, Cmd_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Resp_len) = brp_frame_read_int16(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_Setup(brp_protocol protocol, brp_CardType ConsideredCardType, brp_buf MifareKey, bool AsKeyA, unsigned MadId, unsigned AppId, brp_DesfireFileDescription DesfireFileDesc, brp_buf Key, size_t Key_len, brp_buf SegmentInfo, size_t SegmentInfo_len, bool EnStamp, brp_VHL_Setup_AdrMode AdrMode, unsigned FirstBlock, unsigned BlockCount, brp_VHL_Setup_OptionFlag OptionFlag, unsigned BlockSize, unsigned FileLen, brp_VHL_Setup_SelectFileCmdList_Entry* SelectFileCmdList, size_t SelectFileCmdList_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ConsideredCardType);
	unsigned char RFU[] = { 0x0 };
	brp_frame_write( _frame, RFU, 1);
	if((ConsideredCardType) == (brp_CardType_MifareClassic)) {
		unsigned char MifareKeyLen[] = { 0x6 };
		brp_frame_write( _frame, MifareKeyLen, 1);
		size_t MifareKey_len = 6;
		brp_frame_write(_frame, (brp_buf)MifareKey, MifareKey_len);
		unsigned char AsKeyALen[] = { 0x1 };
		brp_frame_write( _frame, AsKeyALen, 1);
		brp_frame_write_int8(_frame, (unsigned)AsKeyA);
		unsigned char MadIdLen[] = { 0x2 };
		brp_frame_write( _frame, MadIdLen, 1);
		brp_frame_write_int16(_frame, (unsigned)MadId);
	}
	if((ConsideredCardType) == (brp_CardType_MifareDesfire)) {
		unsigned char AppIdLen[] = { 0x4 };
		brp_frame_write( _frame, AppIdLen, 1);
		brp_frame_write_int32(_frame, (unsigned)AppId);
		unsigned char DesfireFileDescLen[] = { 0x10 };
		brp_frame_write( _frame, DesfireFileDescLen, 1);
		unsigned FileNo = DesfireFileDesc.FileNo;
		brp_DesfireFileDescription_FileCommunicationSecurity FileCommunicationSecurity = DesfireFileDesc.FileCommunicationSecurity;
		brp_DesfireFileDescription_FileType FileType = DesfireFileDesc.FileType;
		unsigned ReadKeyNo = DesfireFileDesc.ReadKeyNo;
		unsigned WriteKeyNo = DesfireFileDesc.WriteKeyNo;
		unsigned Offset = DesfireFileDesc.Offset;
		unsigned Length = DesfireFileDesc.Length;
		unsigned ReadKeyIdx = DesfireFileDesc.ReadKeyIdx;
		unsigned WriteKeyIdx = DesfireFileDesc.WriteKeyIdx;
		unsigned AccessRightsLowByte = DesfireFileDesc.AccessRightsLowByte;
		unsigned ChangeKeyIdx = DesfireFileDesc.ChangeKeyIdx;
		unsigned FileSize = DesfireFileDesc.FileSize;
		unsigned IsoFid = DesfireFileDesc.IsoFid;
		brp_frame_write_int8(_frame, (unsigned)FileNo);
		brp_frame_write_int8(_frame, (unsigned)FileCommunicationSecurity);
		brp_frame_write_int8(_frame, (unsigned)FileType);
		brp_frame_write_int8(_frame, (unsigned)ReadKeyNo);
		brp_frame_write_int8(_frame, (unsigned)WriteKeyNo);
		brp_frame_write_int16(_frame, (unsigned)Offset);
		brp_frame_write_int16(_frame, (unsigned)Length);
		brp_frame_write_int8(_frame, (unsigned)ReadKeyIdx);
		brp_frame_write_int8(_frame, (unsigned)WriteKeyIdx);
		brp_frame_write_int8(_frame, (unsigned)AccessRightsLowByte);
		brp_frame_write_int8(_frame, (unsigned)ChangeKeyIdx);
		brp_frame_write_int16(_frame, (unsigned)FileSize);
		brp_frame_write_int16(_frame, (unsigned)IsoFid);
		brp_frame_write_int8(_frame, (unsigned)Key_len);
		brp_frame_write(_frame, (brp_buf)Key, Key_len);
	}
	if((((ConsideredCardType) == (brp_CardType_LEGICPrimeLegacy)) || ((ConsideredCardType) == (brp_CardType_LEGICAdvantLegacy))) || (((ConsideredCardType) == (brp_CardType_LEGICPrime)) || (((ConsideredCardType) == (brp_CardType_LEGICAdvantIso14443a)) || ((ConsideredCardType) == (brp_CardType_LEGICAdvantIso15693))))) {
		brp_frame_write_int8(_frame, (unsigned)SegmentInfo_len);
		brp_frame_write(_frame, (brp_buf)SegmentInfo, SegmentInfo_len);
		unsigned char EnStampLen[] = { 0x1 };
		brp_frame_write( _frame, EnStampLen, 1);
		brp_frame_write_int8(_frame, (unsigned)EnStamp);
		unsigned char AdrModeLen[] = { 0x1 };
		brp_frame_write( _frame, AdrModeLen, 1);
		brp_frame_write_int8(_frame, (unsigned)AdrMode);
	}
	if((ConsideredCardType) == (brp_CardType_Iso15693)) {
		unsigned char FirstBlockLen[] = { 0x1 };
		brp_frame_write( _frame, FirstBlockLen, 1);
		brp_frame_write_int8(_frame, (unsigned)FirstBlock);
		unsigned char BlockCountLen[] = { 0x1 };
		brp_frame_write( _frame, BlockCountLen, 1);
		brp_frame_write_int8(_frame, (unsigned)BlockCount);
		unsigned char OptionFlagLen[] = { 0x1 };
		brp_frame_write( _frame, OptionFlagLen, 1);
		brp_frame_write_int8(_frame, (unsigned)OptionFlag);
		unsigned char BlockSizeLen[] = { 0x1 };
		brp_frame_write( _frame, BlockSizeLen, 1);
		brp_frame_write_int8(_frame, (unsigned)BlockSize);
	}
	if(((ConsideredCardType) == (brp_CardType_Iso14443aInterIndustry)) || ((ConsideredCardType) == (brp_CardType_Iso14443aIntIndustryMif))) {
		unsigned char FileLenLength[] = { 0x4 };
		brp_frame_write( _frame, FileLenLength, 1);
		brp_frame_write_int32(_frame, (unsigned)FileLen);
		for(size_t _SelectFileCmdList_ndx = 0;_SelectFileCmdList_ndx < SelectFileCmdList_len;_SelectFileCmdList_ndx++) {
			brp_VHL_Setup_SelectFileCmdList_Entry SelectFileCmdList_Entry = SelectFileCmdList[_SelectFileCmdList_ndx];
			brp_VHL_Setup_FileSpecifier FileSpecifier = SelectFileCmdList_Entry.FileSpecifier;
			brp_buf FileDescriptor = SelectFileCmdList_Entry.FileDescriptor;
			size_t FileDescriptor_len = SelectFileCmdList_Entry.FileDescriptor_len;
			unsigned char FileSpecifierLen[] = { 0x1 };
			brp_frame_write( _frame, FileSpecifierLen, 1);
			brp_frame_write_int8(_frame, (unsigned)FileSpecifier);
			brp_frame_write_int8(_frame, (unsigned)FileDescriptor_len);
			brp_frame_write(_frame, (brp_buf)FileDescriptor, FileDescriptor_len);
		}
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_SetupMifare(brp_protocol protocol, bool CustomKey, bool KeyA, brp_buf Key) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772209200944 = 0;
	bitmask_1772209200944 |= (CustomKey & 0b1) << 1;
	bitmask_1772209200944 |= (KeyA & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772209200944);
	if(CustomKey) {
		size_t Key_len = 6;
		brp_frame_write(_frame, (brp_buf)Key, Key_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_SetupLegic(brp_protocol protocol, unsigned StampLen, unsigned SegmentID, brp_buf Stamp, size_t Stamp_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 9);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)StampLen);
	if((StampLen) == (0)) {
		brp_frame_write_int8(_frame, (unsigned)SegmentID);
	}
	if((StampLen) > (0)) {
		brp_frame_write(_frame, (brp_buf)Stamp, Stamp_len);
	}
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_SetupISO15(brp_protocol protocol, unsigned FirstBlock, unsigned BlockCount, bool OptionFlag) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 10);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FirstBlock);
	brp_frame_write_int8(_frame, (unsigned)BlockCount);
	brp_frame_write_int8(_frame, (unsigned)OptionFlag);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_CheckReconfigErr(brp_protocol protocol, bool* Failed) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_Failed;
	if (Failed == NULL) Failed = &_tmp_Failed;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 11);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Failed) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_ExchangeLongAPDU(brp_protocol protocol, brp_CardType AssumedCardType, bool Reset, bool ContinueCmd, brp_buf Cmd, size_t Cmd_len, bool* ContinueResp, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Resp_len;
	if(Resp_len == NULL) Resp_len = &_Resp_len;
	bool _tmp_ContinueResp;
	if (ContinueResp == NULL) ContinueResp = &_tmp_ContinueResp;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 12);
	brp_frame_write_int32(_frame, 60000);
	brp_frame_write_int8(_frame, (unsigned)AssumedCardType);
	brp_frame_write_int8(_frame, (unsigned)Reset);
	brp_frame_write_int8(_frame, (unsigned)ContinueCmd);
	brp_frame_write_int16(_frame, (unsigned)Cmd_len);
	brp_frame_write(_frame, (brp_buf)Cmd, Cmd_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ContinueResp) = (bool)brp_frame_read_int8(&_reader);
	(*Resp_len) = brp_frame_read_int16(&_reader);
	if (Resp != NULL) {
		(*Resp) = (brp_buf)brp_mempool_create_buf(mempool, (*Resp_len));
		if((*Resp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Resp), (*Resp_len));
	} else
		brp_frame_skip(&_reader, (*Resp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_GetFileInfo(brp_protocol protocol, unsigned Id, unsigned* Len, unsigned* BlockSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Len;
	if (Len == NULL) Len = &_tmp_Len;
	unsigned _tmp_BlockSize;
	if (BlockSize == NULL) BlockSize = &_tmp_BlockSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 13);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Id);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Len) = (unsigned)brp_frame_read_int16(&_reader);
	(*BlockSize) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_GetATR(brp_protocol protocol, brp_buf* ATR, size_t* ATR_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ATR_len;
	if(ATR_len == NULL) ATR_len = &_ATR_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 14);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ATR_len) = brp_frame_read_int8(&_reader);
	if (ATR != NULL) {
		(*ATR) = (brp_buf)brp_mempool_create_buf(mempool, (*ATR_len));
		if((*ATR) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATR), (*ATR_len));
	} else
		brp_frame_skip(&_reader, (*ATR_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_Format(brp_protocol protocol, unsigned Id) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 15);
	brp_frame_write_int32(_frame, 4000);
	brp_frame_write_int8(_frame, (unsigned)Id);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_VHL_ResolveFilename(brp_protocol protocol, char* FileName, unsigned* Id) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_Id;
	if (Id == NULL) Id = &_tmp_Id;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	size_t FileName_len = strlen(FileName);
	brp_frame_write_int8(_frame, (unsigned)FileName_len);
	brp_frame_write(_frame, (brp_buf)FileName, FileName_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Id) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PortConfig(brp_protocol protocol, unsigned Port, unsigned Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PortGet(brp_protocol protocol, unsigned Port, bool* Level) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_Level;
	if (Level == NULL) Level = &_tmp_Level;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 1);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Level) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PortSet(brp_protocol protocol, unsigned Port, bool Level) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 2);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int8(_frame, (unsigned)Level);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PortWait(brp_protocol protocol, unsigned Port, bool Level, unsigned Timeout, unsigned* ReactionTime) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ReactionTime;
	if (ReactionTime == NULL) ReactionTime = &_tmp_ReactionTime;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 5);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int8(_frame, (unsigned)Level);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReactionTime) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetResetCause(brp_protocol protocol, unsigned* ResetCause) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_ResetCause;
	if (ResetCause == NULL) ResetCause = &_tmp_ResetCause;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 6);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ResetCause) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_APortMeasure(brp_protocol protocol, unsigned Port, unsigned Count, unsigned** Voltages, size_t* Voltages_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Voltages_len;
	if(Voltages_len == NULL) Voltages_len = &_Voltages_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 7);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int8(_frame, (unsigned)Count);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Voltages_len) = brp_frame_rest( & _reader);
	if (Voltages != NULL) {
		(*Voltages) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*Voltages) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _Voltages_ndx = 1;!(brp_frame_read_eof(&_reader) | brp_frame_read_err(&_reader));_Voltages_ndx++) {
		unsigned _Voltage;
		unsigned *Voltage = &_Voltage;
		(*Voltage) = (unsigned)brp_frame_read_int16(&_reader);
		if (Voltages != NULL) {
			(*Voltages) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*Voltages), (_Voltages_ndx * sizeof(unsigned)));
			if((*Voltages) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Voltages)[_Voltages_ndx-1] = *Voltage;
		}
		(*Voltages_len) = _Voltages_ndx;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_SRAMTest(brp_protocol protocol, unsigned SramSize, bool* Success) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	bool _tmp_Success;
	if (Success == NULL) Success = &_tmp_Success;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 4);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)SramSize);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Success) = (bool)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_SetBaudrate(brp_protocol protocol, brp_Baudrate NewBaudrate) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 3);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)NewBaudrate);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_MirrorData(brp_protocol protocol, brp_buf Data, size_t Data_len, brp_buf* MirroredData, size_t* MirroredData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _MirroredData_len;
	if(MirroredData_len == NULL) MirroredData_len = &_MirroredData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 8);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*MirroredData_len) = brp_frame_read_int16(&_reader);
	if (MirroredData != NULL) {
		(*MirroredData) = (brp_buf)brp_mempool_create_buf(mempool, (*MirroredData_len));
		if((*MirroredData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*MirroredData), (*MirroredData_len));
	} else
		brp_frame_skip(&_reader, (*MirroredData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DispEnable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 16);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DispBacklight(brp_protocol protocol, bool Backlight) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 17);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Backlight);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DispColor(brp_protocol protocol, unsigned Color) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 18);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Color);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DispContrast(brp_protocol protocol, unsigned Contrast) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 19);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Contrast);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DispBox(brp_protocol protocol, unsigned X, unsigned Y, unsigned Width, unsigned Height) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 20);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)X);
	brp_frame_write_int8(_frame, (unsigned)Y);
	brp_frame_write_int8(_frame, (unsigned)Width);
	brp_frame_write_int8(_frame, (unsigned)Height);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Ser2Ctrl(brp_protocol protocol, unsigned InterfaceID, bool Enable, brp_Baudrate NewBaudrate, brp_Parity NewParity, unsigned Stopbits) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 21);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)InterfaceID);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_frame_write_int16(_frame, (unsigned)NewBaudrate);
	brp_frame_write_int8(_frame, (unsigned)NewParity);
	brp_frame_write_int8(_frame, (unsigned)Stopbits);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Ser2WriteRead(brp_protocol protocol, unsigned MaxReadCount, unsigned Timeout, brp_buf WriteData, size_t WriteData_len, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 22);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)MaxReadCount);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_frame_write_int16(_frame, (unsigned)WriteData_len);
	brp_frame_write(_frame, (brp_buf)WriteData, WriteData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int16(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Ser2Flush(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 32);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Delay1ms(brp_protocol protocol, unsigned Delay) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 23);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Delay);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Delay10us(brp_protocol protocol, unsigned Delay) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 24);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Delay);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PowermgrSuspend(brp_protocol protocol, unsigned Delay, bool KeyboardWakeup) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 25);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Delay);
	brp_frame_write_int8(_frame, (unsigned)KeyboardWakeup);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ScanMatrix(brp_protocol protocol, unsigned Bitmask) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 26);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Bitmask);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetReaderChipType(brp_protocol protocol, brp_DHWCtrl_GetReaderChipType_ChipType* ChipType) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 27);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _ChipType_int_val = brp_frame_read_int8(&_reader);
	if (! brp_DHWCtrl_GetReaderChipType_ChipType_is_valid(_ChipType_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (ChipType != NULL)
		(*ChipType) = (brp_DHWCtrl_GetReaderChipType_ChipType)_ChipType_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_SelectAntenna(brp_protocol protocol, unsigned Ant) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 28);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Ant);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetSamType(brp_protocol protocol, brp_DHWCtrl_GetSamType_ChipType* ChipType) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 29);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	int _ChipType_int_val = brp_frame_read_int8(&_reader);
	if (! brp_DHWCtrl_GetSamType_ChipType_is_valid(_ChipType_int_val))
		return BRP_ERR_PAYLOAD_FORMAT;
	if (ChipType != NULL)
		(*ChipType) = (brp_DHWCtrl_GetSamType_ChipType)_ChipType_int_val;
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_HfAcquire(brp_protocol protocol, brp_DHWCtrl_HfAcquire_ModuleId ModuleId) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 30);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)ModuleId);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_EepromWrite(brp_protocol protocol, unsigned Address, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 33);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Address);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DataflashGetSize(brp_protocol protocol, unsigned Device, unsigned* PageCount, unsigned* PageSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_PageCount;
	if (PageCount == NULL) PageCount = &_tmp_PageCount;
	unsigned _tmp_PageSize;
	if (PageSize == NULL) PageSize = &_tmp_PageSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 34);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Device);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PageCount) = (unsigned)brp_frame_read_int16(&_reader);
	(*PageSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DataflashErasePages(brp_protocol protocol, unsigned Device, unsigned StartPage, unsigned Len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 35);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Device);
	brp_frame_write_int16(_frame, (unsigned)StartPage);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DataflashRead(brp_protocol protocol, unsigned Device, unsigned Page, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 36);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Device);
	brp_frame_write_int16(_frame, (unsigned)Page);
	brp_frame_write_int16(_frame, (unsigned)StartAdr);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int16(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_DataflashWrite(brp_protocol protocol, unsigned Device, unsigned Mode, unsigned Page, unsigned StartAdr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 37);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Device);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_frame_write_int16(_frame, (unsigned)Page);
	brp_frame_write_int16(_frame, (unsigned)StartAdr);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_EepromRead(brp_protocol protocol, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 38);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)StartAdr);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int16(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_SecurityAndConfigReset(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 39);
	brp_frame_write_int32(_frame, 10000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PulseGenerate(brp_protocol protocol, unsigned Port, unsigned Frequency) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 40);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Port);
	brp_frame_write_int16(_frame, (unsigned)Frequency);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitSer2(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 49);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitRtc(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 50);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitLcdDrv(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 51);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitRc(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 52);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitMf(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 53);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitIso14A(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 54);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitIso14B(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 55);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitIso15(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 56);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitLg(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 57);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitLga(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 58);
	brp_frame_write_int32(_frame, 3000);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitDf(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 59);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitRc125(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 60);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitCc(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 61);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitUsbHost(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 62);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitNic(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 63);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_BohEnable(brp_protocol protocol, bool Enable, bool Bug6WorkaroundEnabled) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_frame_write_int8(_frame, (unsigned)Bug6WorkaroundEnabled);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicEnable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicGetChipType(brp_protocol protocol, brp_buf* ChipType, size_t* ChipType_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ChipType_len;
	if(ChipType_len == NULL) ChipType_len = &_ChipType_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 67);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ChipType_len) = brp_frame_read_int8(&_reader);
	if (ChipType != NULL) {
		(*ChipType) = (brp_buf)brp_mempool_create_buf(mempool, (*ChipType_len));
		if((*ChipType) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ChipType), (*ChipType_len));
	} else
		brp_frame_skip(&_reader, (*ChipType_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicGetLinkStatus(brp_protocol protocol, unsigned* LinkStatus) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LinkStatus;
	if (LinkStatus == NULL) LinkStatus = &_tmp_LinkStatus;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 68);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LinkStatus) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicSend(brp_protocol protocol, brp_buf SendData, size_t SendData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)SendData_len);
	brp_frame_write(_frame, (brp_buf)SendData, SendData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicReceive(brp_protocol protocol, unsigned Timeout, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _RecvData_len;
	if(RecvData_len == NULL) RecvData_len = &_RecvData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 70);
	brp_frame_write_int32(_frame, 1000);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RecvData_len) = brp_frame_read_int16(&_reader);
	if (RecvData != NULL) {
		(*RecvData) = (brp_buf)brp_mempool_create_buf(mempool, (*RecvData_len));
		if((*RecvData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*RecvData), (*RecvData_len));
	} else
		brp_frame_skip(&_reader, (*RecvData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_NicSetMAC(brp_protocol protocol, brp_buf MAC) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 71);
	brp_frame_write_int32(_frame, 100);
	size_t MAC_len = 6;
	brp_frame_write(_frame, (brp_buf)MAC, MAC_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiSetSpeed(brp_protocol protocol, unsigned Speed) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 80);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Speed);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiEnable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 81);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiSingleSend(brp_protocol protocol, unsigned CmdCode, unsigned Address, unsigned CmdData, unsigned Delay) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 82);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CmdCode);
	brp_frame_write_int16(_frame, (unsigned)Address);
	brp_frame_write_int8(_frame, (unsigned)CmdData);
	brp_frame_write_int16(_frame, (unsigned)Delay);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiSingleRecv(brp_protocol protocol, unsigned CmdCode, unsigned Address, unsigned* CmdData) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_CmdData;
	if (CmdData == NULL) CmdData = &_tmp_CmdData;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 83);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CmdCode);
	brp_frame_write_int16(_frame, (unsigned)Address);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CmdData) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiAlternateSend(brp_protocol protocol, unsigned CmdCodeA, unsigned CmdCodeB, unsigned Address, brp_buf CmdData, size_t CmdData_len, unsigned Delay) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 84);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CmdCodeA);
	brp_frame_write_int8(_frame, (unsigned)CmdCodeB);
	brp_frame_write_int16(_frame, (unsigned)Address);
	brp_frame_write_int16(_frame, (unsigned)CmdData_len);
	brp_frame_write(_frame, (brp_buf)CmdData, CmdData_len);
	brp_frame_write_int16(_frame, (unsigned)Delay);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_ApspiAlternateRecv(brp_protocol protocol, unsigned CmdCodeA, unsigned CmdCodeB, unsigned Address, unsigned CmdDataLen, brp_buf* CmdData, size_t* CmdData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _CmdData_len;
	if(CmdData_len == NULL) CmdData_len = &_CmdData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 85);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)CmdCodeA);
	brp_frame_write_int8(_frame, (unsigned)CmdCodeB);
	brp_frame_write_int16(_frame, (unsigned)Address);
	brp_frame_write_int16(_frame, (unsigned)CmdDataLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*CmdData_len) = brp_frame_read_int16(&_reader);
	if (CmdData != NULL) {
		(*CmdData) = (brp_buf)brp_mempool_create_buf(mempool, (*CmdData_len));
		if((*CmdData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*CmdData), (*CmdData_len));
	} else
		brp_frame_skip(&_reader, (*CmdData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiEnable(brp_protocol protocol, bool Enable) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 86);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Enable);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiEraseDevice(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 87);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiReadFlash(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 88);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)ReadLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int16(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiEraseFlashPage(brp_protocol protocol, unsigned Adr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 89);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiWriteFlashPage(brp_protocol protocol, unsigned Adr, brp_buf WriteData, size_t WriteData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 90);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)WriteData_len);
	brp_frame_write(_frame, (brp_buf)WriteData, WriteData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiProgramFlashPage(brp_protocol protocol, unsigned Adr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 91);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiReadEeprom(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 92);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)ReadLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int16(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiProgramEepromPage(brp_protocol protocol, unsigned Adr, brp_buf WriteData, size_t WriteData_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 93);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)WriteData_len);
	brp_frame_write(_frame, (brp_buf)WriteData, WriteData_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiReadFuses(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReadData_len;
	if(ReadData_len == NULL) ReadData_len = &_ReadData_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 94);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int16(_frame, (unsigned)ReadLen);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReadData_len) = brp_frame_read_int16(&_reader);
	if (ReadData != NULL) {
		(*ReadData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReadData_len));
		if((*ReadData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReadData), (*ReadData_len));
	} else
		brp_frame_skip(&_reader, (*ReadData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_PdiWriteFuse(brp_protocol protocol, unsigned Adr, unsigned Fuse) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 95);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)Fuse);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_FlashGetPageSize(brp_protocol protocol, unsigned* PageSize) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_PageSize;
	if (PageSize == NULL) PageSize = &_tmp_PageSize;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 96);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*PageSize) = (unsigned)brp_frame_read_int16(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_FlashErasePage(brp_protocol protocol, unsigned StartAdr, unsigned Len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 97);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)StartAdr);
	brp_frame_write_int32(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_FlashRead(brp_protocol protocol, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 98);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)StartAdr);
	brp_frame_write_int16(_frame, (unsigned)Len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_read_int16(&_reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_FlashWritePage(brp_protocol protocol, unsigned StartAdr, brp_buf Data, size_t Data_len) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 99);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)StartAdr);
	brp_frame_write_int16(_frame, (unsigned)Data_len);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_FlashProgramPage(brp_protocol protocol, unsigned StartAdr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 100);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)StartAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_RegisterRead(brp_protocol protocol, unsigned RegAdr, unsigned* RegValue) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_RegValue;
	if (RegValue == NULL) RegValue = &_tmp_RegValue;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 101);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)RegAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*RegValue) = (unsigned)brp_frame_read_int32(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_RegisterWrite(brp_protocol protocol, unsigned RegAdr, unsigned RegValue) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 102);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int32(_frame, (unsigned)RegAdr);
	brp_frame_write_int32(_frame, (unsigned)RegValue);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_AesWrapKey(brp_protocol protocol, brp_DHWCtrl_AesWrapKey_WrappedKeyNr WrappedKeyNr, brp_buf Key, size_t Key_len, brp_buf* WrappedKey, size_t* WrappedKey_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _WrappedKey_len;
	if(WrappedKey_len == NULL) WrappedKey_len = &_WrappedKey_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 104);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)WrappedKeyNr);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*WrappedKey_len) = brp_frame_read_int8(&_reader);
	if (WrappedKey != NULL) {
		(*WrappedKey) = (brp_buf)brp_mempool_create_buf(mempool, (*WrappedKey_len));
		if((*WrappedKey) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*WrappedKey), (*WrappedKey_len));
	} else
		brp_frame_skip(&_reader, (*WrappedKey_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_AesEncrypt(brp_protocol protocol, brp_DHWCtrl_AesEncrypt_WrappedKeyNr WrappedKeyNr, brp_buf Block, size_t Block_len, brp_buf Key, size_t Key_len, brp_buf* EncBlock, size_t* EncBlock_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EncBlock_len;
	if(EncBlock_len == NULL) EncBlock_len = &_EncBlock_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 105);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)WrappedKeyNr);
	brp_frame_write_int8(_frame, (unsigned)Block_len);
	brp_frame_write(_frame, (brp_buf)Block, Block_len);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*EncBlock_len) = brp_frame_read_int8(&_reader);
	if (EncBlock != NULL) {
		(*EncBlock) = (brp_buf)brp_mempool_create_buf(mempool, (*EncBlock_len));
		if((*EncBlock) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EncBlock), (*EncBlock_len));
	} else
		brp_frame_skip(&_reader, (*EncBlock_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_AesDecrypt(brp_protocol protocol, brp_DHWCtrl_AesDecrypt_WrappedKeyNr WrappedKeyNr, brp_buf EncBlock, size_t EncBlock_len, brp_buf Key, size_t Key_len, brp_buf* Block, size_t* Block_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Block_len;
	if(Block_len == NULL) Block_len = &_Block_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 106);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)WrappedKeyNr);
	brp_frame_write_int8(_frame, (unsigned)EncBlock_len);
	brp_frame_write(_frame, (brp_buf)EncBlock, EncBlock_len);
	brp_frame_write_int8(_frame, (unsigned)Key_len);
	brp_frame_write(_frame, (brp_buf)Key, Key_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Block_len) = brp_frame_read_int8(&_reader);
	if (Block != NULL) {
		(*Block) = (brp_buf)brp_mempool_create_buf(mempool, (*Block_len));
		if((*Block) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Block), (*Block_len));
	} else
		brp_frame_skip(&_reader, (*Block_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetPlatformId2(brp_protocol protocol, unsigned** HWCIdLst, size_t* HWCIdLst_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _HWCIdLst_len;
	if(HWCIdLst_len == NULL) HWCIdLst_len = &_HWCIdLst_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 123);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*HWCIdLst_len) = brp_frame_read_int8(&_reader);
	if (HWCIdLst != NULL) {
		(*HWCIdLst) = (unsigned*)brp_mempool_create_buf(mempool, 0);
		if((*HWCIdLst) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(size_t _HWCIdLst_ndx = 1;!((_HWCIdLst_ndx > (*HWCIdLst_len)) | brp_frame_read_err(&_reader));_HWCIdLst_ndx++) {
		unsigned _HWCId;
		unsigned *HWCId = &_HWCId;
		(*HWCId) = (unsigned)brp_frame_read_int16(&_reader);
		if (HWCIdLst != NULL) {
			(*HWCIdLst) = (unsigned*)brp_mempool_resize_buf((brp_buf)(*HWCIdLst), (_HWCIdLst_ndx * sizeof(unsigned)));
			if((*HWCIdLst) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*HWCIdLst)[_HWCIdLst_ndx-1] = *HWCId;
		}
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetProdLoader(brp_protocol protocol, unsigned* LoaderBaudrate) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_LoaderBaudrate;
	if (LoaderBaudrate == NULL) LoaderBaudrate = &_tmp_LoaderBaudrate;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 124);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*LoaderBaudrate) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_StartProdLoader(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 125);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Run(brp_protocol protocol, brp_buf CommandList, size_t CommandList_len, unsigned* Status, brp_buf* Response, size_t* Response_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Response_len;
	if(Response_len == NULL) Response_len = &_Response_len;
	unsigned _tmp_Status;
	if (Status == NULL) Status = &_tmp_Status;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 127);
	brp_frame_write_int32(_frame, 20000);
	brp_frame_write(_frame, (brp_buf)CommandList, CommandList_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Status) = (unsigned)brp_frame_read_int8(&_reader);
	(*Response_len) = brp_frame_read_int16(&_reader);
	if (Response != NULL) {
		(*Response) = (brp_buf)brp_mempool_create_buf(mempool, (*Response_len));
		if((*Response) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Response), (*Response_len));
	} else
		brp_frame_skip(&_reader, (*Response_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_GetStartupRun(brp_protocol protocol, unsigned* Status, brp_buf* Response, size_t* Response_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Response_len;
	if(Response_len == NULL) Response_len = &_Response_len;
	unsigned _tmp_Status;
	if (Status == NULL) Status = &_tmp_Status;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 126);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Status) = (unsigned)brp_frame_read_int8(&_reader);
	(*Response_len) = brp_frame_read_int16(&_reader);
	if (Response != NULL) {
		(*Response) = (brp_buf)brp_mempool_create_buf(mempool, (*Response_len));
		if((*Response) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Response), (*Response_len));
	} else
		brp_frame_skip(&_reader, (*Response_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_InitBgm(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 128);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_BgmExec(brp_protocol protocol, brp_buf Cmd, size_t Cmd_len, unsigned Timeout, brp_buf* Rsp, size_t* Rsp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Rsp_len;
	if(Rsp_len == NULL) Rsp_len = &_Rsp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 129);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Cmd_len);
	brp_frame_write(_frame, (brp_buf)Cmd, Cmd_len);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Rsp_len) = brp_frame_read_int8(&_reader);
	if (Rsp != NULL) {
		(*Rsp) = (brp_buf)brp_mempool_create_buf(mempool, (*Rsp_len));
		if((*Rsp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Rsp), (*Rsp_len));
	} else
		brp_frame_skip(&_reader, (*Rsp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Sm4x00BootloaderStart(brp_protocol protocol, brp_buf* BootloaderString, size_t* BootloaderString_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _BootloaderString_len;
	if(BootloaderString_len == NULL) BootloaderString_len = &_BootloaderString_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 130);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*BootloaderString_len) = brp_frame_read_int8(&_reader);
	if (BootloaderString != NULL) {
		(*BootloaderString) = (brp_buf)brp_mempool_create_buf(mempool, (*BootloaderString_len));
		if((*BootloaderString) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*BootloaderString), (*BootloaderString_len));
	} else
		brp_frame_skip(&_reader, (*BootloaderString_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Sm4x00EraseFlash(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 131);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Sm4x00WaitForFlashErase(brp_protocol protocol, unsigned Timeout, brp_buf* EraseResponse, size_t* EraseResponse_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _EraseResponse_len;
	if(EraseResponse_len == NULL) EraseResponse_len = &_EraseResponse_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 132);
	brp_frame_write_int32(_frame, 1500);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*EraseResponse_len) = brp_frame_read_int8(&_reader);
	if (EraseResponse != NULL) {
		(*EraseResponse) = (brp_buf)brp_mempool_create_buf(mempool, (*EraseResponse_len));
		if((*EraseResponse) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*EraseResponse), (*EraseResponse_len));
	} else
		brp_frame_skip(&_reader, (*EraseResponse_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_Sm4x00ProgramBlock(brp_protocol protocol, bool IsLast, brp_buf FwBlock, size_t FwBlock_len, brp_buf* ProgramResponse, size_t* ProgramResponse_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ProgramResponse_len;
	if(ProgramResponse_len == NULL) ProgramResponse_len = &_ProgramResponse_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 133);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)IsLast);
	brp_frame_write_int8(_frame, (unsigned)FwBlock_len);
	brp_frame_write(_frame, (brp_buf)FwBlock, FwBlock_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ProgramResponse_len) = brp_frame_read_int8(&_reader);
	if (ProgramResponse != NULL) {
		(*ProgramResponse) = (brp_buf)brp_mempool_create_buf(mempool, (*ProgramResponse_len));
		if((*ProgramResponse) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ProgramResponse), (*ProgramResponse_len));
	} else
		brp_frame_skip(&_reader, (*ProgramResponse_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_DHWCtrl_BgmRead(brp_protocol protocol, unsigned Timeout, brp_buf* Rsp, size_t* Rsp_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Rsp_len;
	if(Rsp_len == NULL) Rsp_len = &_Rsp_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 224);
	brp_frame_write_int8(_frame, 134);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int16(_frame, (unsigned)Timeout);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Rsp_len) = brp_frame_read_int16(&_reader);
	if (Rsp != NULL) {
		(*Rsp) = (brp_buf)brp_mempool_create_buf(mempool, (*Rsp_len));
		if((*Rsp) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Rsp), (*Rsp_len));
	} else
		brp_frame_skip(&_reader, (*Rsp_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Request(brp_protocol protocol, bool ReqAll, brp_buf* ATQA, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 65);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772209670032 = 0;
	bitmask_1772209670032 |= (ReqAll & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772209670032);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _ATQA_len = 2;
	size_t* ATQA_len = &_ATQA_len;
	if (ATQA != NULL) {
		(*ATQA) = (brp_buf)brp_mempool_create_buf(mempool, (*ATQA_len));
		if((*ATQA) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ATQA), (*ATQA_len));
	} else
		brp_frame_skip(&_reader, (*ATQA_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Anticoll(brp_protocol protocol, unsigned BitCount, brp_buf PreSelectedSnr, brp_buf* SelectedSnr, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 66);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BitCount);
	size_t PreSelectedSnr_len = 4;
	brp_frame_write(_frame, (brp_buf)PreSelectedSnr, PreSelectedSnr_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _SelectedSnr_len = 4;
	size_t* SelectedSnr_len = &_SelectedSnr_len;
	if (SelectedSnr != NULL) {
		(*SelectedSnr) = (brp_buf)brp_mempool_create_buf(mempool, (*SelectedSnr_len));
		if((*SelectedSnr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*SelectedSnr), (*SelectedSnr_len));
	} else
		brp_frame_skip(&_reader, (*SelectedSnr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Select(brp_protocol protocol, brp_buf Snr) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 67);
	brp_frame_write_int32(_frame, 100);
	size_t Snr_len = 4;
	brp_frame_write(_frame, (brp_buf)Snr, Snr_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Halt(brp_protocol protocol) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 69);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadBlock(brp_protocol protocol, unsigned Adr, brp_buf* Data, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 112);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _Data_len = 32;
	size_t* Data_len = &_Data_len;
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadMultipleBlocks(brp_protocol protocol, unsigned Adr, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 118);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)NumBlocks);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_WriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 113);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned* DataLo, unsigned* DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_DataLo;
	if (DataLo == NULL) DataLo = &_tmp_DataLo;
	unsigned _tmp_DataHi;
	if (DataHi == NULL) DataHi = &_tmp_DataHi;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 114);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockAdr);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*DataLo) = (unsigned)brp_frame_read_int8(&_reader);
	(*DataHi) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_WriteWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned DataLo, unsigned DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 115);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockAdr);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_frame_write_int8(_frame, (unsigned)DataLo);
	brp_frame_write_int8(_frame, (unsigned)DataHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_WriteFile(brp_protocol protocol, unsigned FileNr, unsigned Mode, unsigned BlockAdr, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 116);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)FileNr);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_frame_write_int8(_frame, (unsigned)BlockAdr);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Test(brp_protocol protocol, unsigned Mode, unsigned* Teststatus, brp_buf* Snr, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	unsigned _tmp_Teststatus;
	if (Teststatus == NULL) Teststatus = &_tmp_Teststatus;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 117);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Teststatus) = (unsigned)brp_frame_read_int8(&_reader);
	size_t _Snr_len = 4;
	size_t* Snr_len = &_Snr_len;
	if (Snr != NULL) {
		(*Snr) = (brp_buf)brp_mempool_create_buf(mempool, (*Snr_len));
		if((*Snr) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Snr), (*Snr_len));
	} else
		brp_frame_skip(&_reader, (*Snr_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_FastWriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 124);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_FastWriteWord(brp_protocol protocol, unsigned BlockAdr, unsigned WordAdr, unsigned DataLo, unsigned DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 125);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockAdr);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_frame_write_int8(_frame, (unsigned)DataLo);
	brp_frame_write_int8(_frame, (unsigned)DataHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_HighSpeedWriteBlock(brp_protocol protocol, unsigned Adr, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 96);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_GetBootStatus(brp_protocol protocol, unsigned Mode, unsigned* BootStatusLo, unsigned* BootStatusHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_BootStatusLo;
	if (BootStatusLo == NULL) BootStatusLo = &_tmp_BootStatusLo;
	unsigned _tmp_BootStatusHi;
	if (BootStatusHi == NULL) BootStatusHi = &_tmp_BootStatusHi;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 52);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*BootStatusLo) = (unsigned)brp_frame_read_int8(&_reader);
	(*BootStatusHi) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ContinousReadBlocks(brp_protocol protocol, unsigned Adr, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 97);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Adr);
	brp_frame_write_int8(_frame, (unsigned)NumBlocks);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_SetReturnLink(brp_protocol protocol, unsigned Mode) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 127);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Mode);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_HFReset(brp_protocol protocol, unsigned OffDurationLo, unsigned OffDurationHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 78);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)OffDurationLo);
	brp_frame_write_int8(_frame, (unsigned)OffDurationHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_Reset(brp_protocol protocol, unsigned Quit) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 54);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)Quit);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_GetInfo(brp_protocol protocol, char** Info, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 79);
	brp_frame_write_int32(_frame, 100);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _Info_len = 0;
	size_t* Info_len = &_Info_len;
	if (Info != NULL) {
		(*Info) = (char*)brp_mempool_create_buf(mempool, 0);
		if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
	}
	for(char _char = brp_frame_read_int8(&_reader); !((_char == 0x00) | brp_frame_read_err(&_reader));_char = brp_frame_read_int8(&_reader)) {
		if(Info != NULL) {
			(*Info_len) += 1;
			(*Info) = (char*)brp_mempool_resize_buf((brp_buf)(*Info), (*Info_len));
			if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
			(*Info)[(*Info_len)-1] = _char;
		}
	}
	if(Info != NULL) {
		(*Info_len) += 1;
		(*Info) = (char*)brp_mempool_resize_buf((brp_buf)(*Info), (*Info_len));
		if((*Info) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		(*Info)[(*Info_len)-1] = 0;
	}
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_TransparentCmd(brp_protocol protocol, unsigned EnBitMode, unsigned EnCRCRX, unsigned EnCRCTX, unsigned ParityMode, unsigned EnParity, unsigned LenLo, unsigned LenHi, unsigned TimeoutLo, unsigned TimeoutHi, unsigned DSI, unsigned DRI, brp_buf Data, size_t Data_len, unsigned* ReturnLenLo, unsigned* ReturnLenHi, unsigned* ColPos, brp_buf* ReturnData, size_t* ReturnData_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _ReturnData_len;
	if(ReturnData_len == NULL) ReturnData_len = &_ReturnData_len;
	unsigned _tmp_ReturnLenLo;
	if (ReturnLenLo == NULL) ReturnLenLo = &_tmp_ReturnLenLo;
	unsigned _tmp_ReturnLenHi;
	if (ReturnLenHi == NULL) ReturnLenHi = &_tmp_ReturnLenHi;
	unsigned _tmp_ColPos;
	if (ColPos == NULL) ColPos = &_tmp_ColPos;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 126);
	brp_frame_write_int32(_frame, 100);
	unsigned bitmask_1772209675408 = 0;
	bitmask_1772209675408 |= (EnBitMode & 0b1) << 4;
	bitmask_1772209675408 |= (EnCRCRX & 0b1) << 3;
	bitmask_1772209675408 |= (EnCRCTX & 0b1) << 2;
	bitmask_1772209675408 |= (ParityMode & 0b1) << 1;
	bitmask_1772209675408 |= (EnParity & 0b1) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772209675408);
	brp_frame_write_int8(_frame, (unsigned)LenLo);
	brp_frame_write_int8(_frame, (unsigned)LenHi);
	brp_frame_write_int8(_frame, (unsigned)TimeoutLo);
	brp_frame_write_int8(_frame, (unsigned)TimeoutHi);
	unsigned bitmask_1772209675936 = 0;
	bitmask_1772209675936 |= (DSI & 0b11) << 2;
	bitmask_1772209675936 |= (DRI & 0b11) << 0;
	brp_frame_write_int8(_frame, (unsigned)bitmask_1772209675936);
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*ReturnLenLo) = (unsigned)brp_frame_read_int8(&_reader);
	(*ReturnLenHi) = (unsigned)brp_frame_read_int8(&_reader);
	(*ColPos) = (unsigned)brp_frame_read_int16(&_reader);
	(*ReturnData_len) = brp_frame_rest( & _reader);
	if (ReturnData != NULL) {
		(*ReturnData) = (brp_buf)brp_mempool_create_buf(mempool, (*ReturnData_len));
		if((*ReturnData) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*ReturnData), (*ReturnData_len));
	} else
		brp_frame_skip(&_reader, (*ReturnData_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf* Data, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 128);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	size_t _Data_len = 32;
	size_t* Data_len = &_Data_len;
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_WriteBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 129);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadWordExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned WordAdr, unsigned* DataLo, unsigned* DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	unsigned _tmp_DataLo;
	if (DataLo == NULL) DataLo = &_tmp_DataLo;
	unsigned _tmp_DataHi;
	if (DataHi == NULL) DataHi = &_tmp_DataHi;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 130);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*DataLo) = (unsigned)brp_frame_read_int8(&_reader);
	(*DataHi) = (unsigned)brp_frame_read_int8(&_reader);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_WriteWordExtended(brp_protocol protocol, unsigned BlockAdrLo, unsigned BlockAdrHi, unsigned WordAdr, unsigned DataLo, unsigned DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 131);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockAdrLo);
	brp_frame_write_int8(_frame, (unsigned)BlockAdrHi);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_frame_write_int8(_frame, (unsigned)DataLo);
	brp_frame_write_int8(_frame, (unsigned)DataHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ReadMultipleBlocksExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 132);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	brp_frame_write_int8(_frame, (unsigned)NumBlocks);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_FastWriteWordExtended(brp_protocol protocol, unsigned BlockAdrLo, unsigned BlockAdrHi, unsigned WordAdr, unsigned DataLo, unsigned DataHi) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 136);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)BlockAdrLo);
	brp_frame_write_int8(_frame, (unsigned)BlockAdrHi);
	brp_frame_write_int8(_frame, (unsigned)WordAdr);
	brp_frame_write_int8(_frame, (unsigned)DataLo);
	brp_frame_write_int8(_frame, (unsigned)DataHi);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_ContinousReadBlocksExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, unsigned NumBlocks, brp_buf* Data, size_t* Data_len, brp_mempool *mempool) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	if(mempool == NULL) {
		mempool = &protocol->mempool;
		brp_mempool_free(mempool);
	}
	size_t _Data_len;
	if(Data_len == NULL) Data_len = &_Data_len;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 137);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	brp_frame_write_int8(_frame, (unsigned)NumBlocks);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	(*Data_len) = brp_frame_rest( & _reader);
	if (Data != NULL) {
		(*Data) = (brp_buf)brp_mempool_create_buf(mempool, (*Data_len));
		if((*Data) == NULL) return BRP_ERR_OUT_OF_MEMORY;
		brp_frame_read(&_reader, (brp_buf)(*Data), (*Data_len));
	} else
		brp_frame_skip(&_reader, (*Data_len));
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

brp_errcode brp_LT_HighSpeedWriteBlockExtended(brp_protocol protocol, unsigned AdrLo, unsigned AdrHi, brp_buf Data) {
	if(protocol == NULL) return BRP_ERR_INVALID_API_CALL;
	brp_frame _frame = &protocol->send_frame;;
	brp_frame_write_start(_frame);
	brp_frame_write_int8(_frame, 0);
	brp_frame_write_int8(_frame, 160);
	brp_frame_write_int8(_frame, 138);
	brp_frame_write_int32(_frame, 100);
	brp_frame_write_int8(_frame, (unsigned)AdrLo);
	brp_frame_write_int8(_frame, (unsigned)AdrHi);
	size_t Data_len = 32;
	brp_frame_write(_frame, (brp_buf)Data, Data_len);
	brp_errcode _status_code = brp_send_frame(protocol);
	if (_status_code != BRP_OK) return _status_code;
	
	_status_code = brp_recv_any_frame(protocol, BRP_INFINITE);
	if(_status_code != BRP_OK) return _status_code;
	brp_frame_reader _reader;
	brp_frame_read_start(&_reader, &protocol->recv_frame);
	if(brp_frame_read_err(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	if(!brp_frame_read_eof(&_reader)) return BRP_ERR_PAYLOAD_FORMAT;
	return BRP_OK;
}

