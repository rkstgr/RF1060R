#include "brp.h"
#include "iso15693.h"
#include "oswrapper.h"
#include <string.h>


void iso15693_init_SetParam_request( iso15693_SetParam_request * structure ) {
	structure->TenthModIndex = false;
	structure->TxMode1of4 = true;
	structure->HighDataRate = true;
	structure->DualSubcarrier = false;
}

int iso15693_set_param( int Handle, iso15693_SetParam_request * request,
				int *Status ) {
	int return_val;

	unsigned char Data;

	Data = 0x00;

	if ( request != NULL ) {
		if ( request->TenthModIndex == true )
			Data = Data + ISO15693_PARAM_TENTH_MOD_INDEX;
		if ( request->TxMode1of4 == true )
			Data = Data + ISO15693_PARAM_TX_MODE_1_OF_4;
		if ( request->HighDataRate == true )
			Data = Data + ISO15693_PARAM_HIGH_DATA_RATE;
		if ( request->DualSubcarrier == true )
			Data = Data + ISO15693_PARAM_DUAL_SUBCARRIER;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_SET_PARAM,
								&Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso15693_get_param( int Handle, iso15693_GetParam_response * response,
				int *Status ) {
	int return_val;

	unsigned char Data;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_GET_PARAM,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		if ( response != NULL ) {
			response->TenthModIndex = ( Data & ISO15693_PARAM_TENTH_MOD_INDEX ) == ISO15693_PARAM_TENTH_MOD_INDEX;
			response->TxMode1of4 = ( Data & ISO15693_PARAM_TX_MODE_1_OF_4 ) == ISO15693_PARAM_TX_MODE_1_OF_4;
			response->HighDataRate = ( Data & ISO15693_PARAM_HIGH_DATA_RATE ) == ISO15693_PARAM_HIGH_DATA_RATE;
			response->DualSubcarrier = ( Data & ISO15693_PARAM_DUAL_SUBCARRIER ) == ISO15693_PARAM_DUAL_SUBCARRIER;
		} else
			return( BRP_ERR_WRONG_PARAMETERS );
	}

	return( return_val );
}

void iso15693_init_GetUIDList_request( iso15693_GetUIDList_request * structure ) {
	structure->EnAFI = false;
	structure->NextBlock = false;
	structure->AutoQuiet = false;
	structure->DSFID = false;
	structure->Slot16 = false;
}

int iso15693_get_uid_list( int Handle, iso15693_GetUIDList_request * request,
				bool * more, int * count, iso15693_UID * labels, unsigned int max_count,
				int *Status ) {
	int return_val;

	unsigned char * Data;

	int Len, DsfidLen, i;

	if ( request != NULL ) {
		if ( request->DSFID == true ) {
			DsfidLen = 1;
		} else {
			DsfidLen = 0;
		}

		Data = (unsigned char *) malloc( max_count * ( ISO15693_UID_SIZE + DsfidLen ) + 2 );

		if ( Data == NULL )
			return( BRP_ERR_INSUFFICIENT_MEM );

		if ( request->DSFID == true ) {
			Data[0] = ISO15693_GETUID_DSFID;
		} else {
			Data[0] = 0x00;
		}

		if ( request->EnAFI == true ) {
			Len = 2;
			Data[0] = Data[0] + ISO15693_GETUID_EN_AFI;
		} else
			Len = 1;
		if ( request->NextBlock == true )
			Data[0] = Data[0] + ISO15693_GETUID_NEXT_BLOCK;
		if ( request->AutoQuiet == true )
			Data[0] = Data[0] + ISO15693_GETUID_AUTO_QUIET;
		if ( request->Slot16 == true )
			Data[0] = Data[0] + ISO15693_GETUID_16SLOTS;
		Data[1] = request->AFI;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_GET_UID_LIST,
								Data,
								Len,
								BRP_TIMEOUT_VAR( max_count * ISO15693_UID_SIZE ),
								Status,
								Data,
								&Len,
								max_count * ( ISO15693_UID_SIZE + DsfidLen ) + 2 );

	if ( return_val == BRP_OK ) {
		if ( more != NULL ) {
			if ( Data[0] == BRP_FALSE )
				*more = false;
			else
				*more = true;
		}

		*count = (int) Data[1];

		for ( i = 0; i < *count; i++ ) {
			memcpy( labels[i].UID, Data + ( 2 + i * ( ISO15693_UID_SIZE + DsfidLen ) ), ISO15693_UID_SIZE );
			if ( request->DSFID == true )
				labels[i].DSFID = *( Data + ( 2 + ISO15693_UID_SIZE + i * ( ISO15693_UID_SIZE + DsfidLen ) ) );
		}
	}

	free( Data );

	return( return_val );
}

int iso15693_set_mode( int Handle, byte mode, unsigned char *UID,
				int *Status ) {
	int return_val;

	int Len;

	unsigned char Data[9];

	if ( UID == NULL ) {
		Len	= 1;
	} else {
		Len = 9;
		memcpy( Data + 1, UID, 8 );
	}

	Data[0] = mode;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_SET_MODE,
								Data,
								Len,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso15693_stay_quiet( int Handle,
				int *Status ) {
	int return_val;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_STAY_QUIET,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso15693_read_block( int Handle, byte block_id, byte block_num, bool en_block_sec,
			byte * label_stat, byte * block_len, byte data[], byte block_sec_stat[],
			byte max_block_len, int *Status ) {
	int return_val;

	int Len, MaxLen, SecLen, i;

	unsigned char *Data;

	if ( en_block_sec == true ) {
		SecLen = 1;
		MaxLen = ( max_block_len + SecLen ) * ( block_num + 1 ) + 2;
		Data = (unsigned char *) malloc( MaxLen );
		if ( Data == NULL )
			return( BRP_ERR_INSUFFICIENT_MEM );

		if ( MaxLen > 2 )
			Data[2] = BRP_TRUE;
	} else {
		SecLen = 0;
		MaxLen = ( max_block_len + SecLen ) * ( block_num + 1 ) + 2;
		Data = (unsigned char *) malloc( MaxLen );
		if ( Data == NULL )
			return( BRP_ERR_INSUFFICIENT_MEM );

		if ( MaxLen > 2 )
			Data[2] = BRP_FALSE;
	}

	Data[0] = block_id;
	Data[1] = block_num;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_READ_BLOCK,
								Data,
								3,
								BRP_TIMEOUT_VAR( 3 + 8 * ( block_num + 1 ) ),
								Status,
								Data,
								&Len,
								MaxLen );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];
		*block_len = Data[1];

		for ( i = 0; i < block_num + 1; i++ ) {
			memcpy( data + ( ( *block_len - SecLen ) * i ), Data + ( ( *block_len ) * i + 2 ), *block_len - SecLen );
			if ( block_sec_stat != NULL ) {
				if ( en_block_sec == true ) {
					block_sec_stat[i] = Data[( ( *block_len ) * i ) + *block_len + 1];
				}
			}
		}

		*block_len = *block_len - SecLen;
	}

	free( Data );

	return( return_val );
}

int iso15693_write_block( int Handle, byte block_id, byte block_num,
			byte block_len, byte data[],
			byte * label_stat, int *Status ) {
	int return_val;

	unsigned char * Data;

	Data = (unsigned char *) malloc( block_len * block_num + 4 );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = block_id;
	Data[1] = block_num;
	Data[2] = block_len;
	memcpy( Data + 3, data, block_len * ( block_num + 1 ) );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_WRITE_BLOCK,
								Data,
								3 + block_len * ( block_num + 1 ),
								BRP_TIMEOUT_VAR( 3 + block_len * ( block_num + 1 ) ),
								Status,
								Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];
	}

	free( Data );

	return( return_val );
}

int iso15693_lock_block( int Handle, byte block_id,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	Data = block_id;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_LOCK_BLOCK,
								&Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_reset_to_ready( int Handle,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_RESET_TO_READY,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_write_afi( int Handle, byte afi,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	Data = afi;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_WRITE_AFI,
								&Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_lock_afi( int Handle,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_LOCK_AFI,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_write_dsfid( int Handle, byte dsfid,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	Data = dsfid;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_WRITE_DSFID,
								&Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_lock_dsfid( int Handle,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_LOCK_DSFID,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								&Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data;
	}

	return( return_val );
}

int iso15693_get_system_information( int Handle, iso15693_SystemInformation * info,
				byte * label_stat, int *Status ) {
	int return_val;

	int i;

	unsigned char Data[15];

	i = 0;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_GET_SYSTEM_INFO,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								15 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];

		info->EnICRef = ( Data[1] & ISO15693_INFO_ICREF ) == ISO15693_INFO_ICREF;
		info->EnMemSize = ( Data[1] & ISO15693_INFO_MEM_SIZE ) == ISO15693_INFO_MEM_SIZE;
		info->EnAFI = ( Data[1] & ISO15693_INFO_AFI ) == ISO15693_INFO_AFI;
		info->EnDSFID = ( Data[1] & ISO15693_INFO_DSFID ) == ISO15693_INFO_DSFID;

		memcpy( info->SNR, Data + 2, ISO15693_UID_SIZE );

		if ( info->EnDSFID == true ) {
			info->DSFID = Data[i + 10];
			i = i + 1;
		}
		if ( info->EnAFI == true ) {
			info->AFI = Data[i + 10];
			i = i + 1;
		}
		if ( info->EnMemSize == true ) {
			info->BlockNum = Data[i + 10] + 1;
			i = i + 1;
			info->BlockSize = Data[i + 10] + 1;
			i = i + 1;
		}
		if ( info->EnICRef == true )
			info->ICRef = Data[i + 10];
	}

	return( return_val );
}

int iso15693_get_security_status( int Handle, byte block_id, byte block_num,
				byte * block_stat,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char *Data;

	Data = (unsigned char*) malloc( block_num + 1 );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = block_id;
	Data[1] = block_num;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_GET_SECURITY_STATUS,
								Data,
								2,
								BRP_TIMEOUT_VAR( block_num + 1 ),
								Status,
								Data,
								NULL,
								block_num + 2 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];

		memcpy( block_stat, Data + 1, block_num + 1 );
	}

	free( Data );

	return( return_val );
}

int iso15693_custom_command( int Handle, iso15693_CustomCmd_settings *settings,
				int len, byte  * data, int * resp_len, byte * resp, int max_resp_len,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char * Data;

	int Len;

	if ( len + 6 > max_resp_len + 3 )
		Data = (unsigned char*) malloc( len + 6 );
	else
		Data = (unsigned char*) malloc( max_resp_len + 3 );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = settings->Cmd;
	if ( settings->Opt == true )
		Data[1] = BRP_TRUE;
	else
		Data[1] = BRP_FALSE;
	Data[2] = settings->MFC;
	Data[3] = settings->TO;

	Data[4] = (unsigned char) ( len >> 8 );
	Data[5] = (unsigned char) len;

	memcpy( Data + 6, data, len );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_CUSTOM_CMD,
								Data,
								len + 6,
								BRP_TIMEOUT_VAR( len + 6 ),
								Status,
								Data,
								&Len,
								max_resp_len + 3 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];

		*resp_len = Data[1];
		*resp_len = *resp_len << 8;
		*resp_len = *resp_len + Data[2];

		if ( Len != *resp_len + 3 ) {
			free( Data );
			return( BRP_ERR_CORRUPTED_FRAME );
		}

		memcpy( resp, Data + 3, *resp_len );
	}

	free( Data );

	return( return_val );
}

void iso15693_init_CustomCmd_settings( iso15693_CustomCmd_settings * structure ) {
	structure->Opt = false;
	structure->TO = 200;
}

int iso15693_transparent_cmd( int Handle, iso15693_TransparentCmd_settings* settings,
				int len, byte * data, int * resp_len, byte* resp, int max_resp_len,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char * Data;

	int Len;

	if ( len + 5 > max_resp_len + 3 )
		Data = (unsigned char*) malloc( len + 5 );
	else
		Data = (unsigned char*) malloc( max_resp_len + 3 );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = 0x00;
	if ( settings->EnCRCRX == true )
		Data[0] = Data[0] + ISO15693_CRCRX;
	if ( settings->EnCRCTX == true )
		Data[0] = Data[0] + ISO15693_CRCTX;
	if ( settings->EnRxWait == true )
		Data[0] = Data[0] + ISO15693_ENRXWAIT;

	Data[1] = (unsigned char) (len >> 8);
	Data[2] = (unsigned char) len;

	Data[3] = (unsigned char) (settings->Timeout >> 8);
	Data[4] = (unsigned char) settings->Timeout;



	memcpy( Data + 5, data, len );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_TRANSPARENT_CMD,
								Data,
								len + 5,
								BRP_TIMEOUT_VAR( len + 5 ),
								Status,
								Data,
								&Len,
								max_resp_len + 3 );

	if ( return_val == BRP_OK ) {
		*label_stat = 0;

		*resp_len = Data[0];
		*resp_len = *resp_len << 8;
		*resp_len = *resp_len + Data[1];

		if ( Len != *resp_len + 2 ) {
			free( Data );
			return( BRP_ERR_CORRUPTED_FRAME );
		}

		memcpy( resp, Data + 2, *resp_len );
	}

	free( Data );

	return( return_val );
}

void iso15693_init_TransparentCmd_settings( iso15693_TransparentCmd_settings * structure ) {
	structure->EnRxWait = false;
	structure->EnCRCRX = true;
	structure->EnCRCTX = true;
	structure->Timeout = 200;
}

int iso15693_myd_authenticate( int Handle, iso15693_MydAuthenticate_settings* settings,
				byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data[27];
	int offset;

	Data[0] = settings->KeyAddress;

	Data[1] = 0x00;
	if ( settings->EnDivKey == true ) {
		Data[1] = Data[1] + ISO15693_ENDIV;
	}
	if ( settings->EnKey == true ) {
		Data[1] = Data[1] + ISO15693_ENKEY;
	}
	if ( settings->EnDivData == true ) {
		Data[1] = Data[1] + ISO15693_ENDATA;
	}

	offset = 2;
        if ( settings->EnDivKey == true ) {
		memcpy( Data + offset, settings->DivKey, 8 );
		offset = offset + 8;
        }

	if ( settings->EnKey == true ) {
		memcpy( Data + offset, settings->Key, 16 );
		offset = offset + 16;
	} else {
		Data[offset] = settings->ValueID;
		offset = offset + 1;
	}

	if ( settings->EnDivData == true ) {
		memcpy( Data + offset, settings->DivData, 8 );
		offset = offset + 8;
	}

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_MYD_AUTHENTICATE,
								Data,
								offset,
								BRP_TIMEOUT_DEFAULT,
								Status,
								Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];
	}

	return( return_val );
}

void iso15693_init_MydAuthenticate_settings( iso15693_MydAuthenticate_settings* structure ) {
	structure->KeyAddress = 0x00;
	structure->EnDivKey = false;
	structure->EnKey = false;
	structure->EnDivData = false;
}

int iso15693_myd_read( int Handle, iso15693_MydRead_settings* settings,
				int * len, unsigned char * data, byte * label_stat, int *Status ) {
	int return_val;

	unsigned char Data[13];

	int Len;

	Data[0] = 0x00;
	if ( settings->EnSecure == true ) {
		Data[0] = Data[0] + ISO15693_ENSECURE;
	}
	if ( settings->EnRestricted == true ) {
		Data[0] = Data[0] + ISO15693_ENRESTRICTED;
	}

	Data[1] = (unsigned char) (settings->PageAddress >> 8);
	Data[2] = (unsigned char) settings->PageAddress;

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_MYD_READ,
								Data,
								3,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								&Len,
								13 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];

		*len = (int) Data[1];

		memcpy( data, Data + 2, *len );
	}

	return( return_val );
}

void iso15693_init_MydRead_settings( iso15693_MydRead_settings* structure ) {
	structure->EnSecure = false;
	structure->EnRestricted = false;
	structure->PageAddress = 0;
}

int iso15693_myd_write( int Handle, iso15693_MydWrite_request* request,
				byte* label_stat, int *Status ) {
	int return_val;

	unsigned char Data[14];

	int Len;

	Data[0] = 0x00;
	if ( request->EnSecure == true ) {
		Data[0] = Data[0] + ISO15693_ENSECURE;
	}
	if ( request->EnRestricted == true ) {
		Data[0] = Data[0] + ISO15693_ENRESTRICTED;
	}
	if ( request->EnPrepare == true ) {
		Data[0] = Data[0] + ISO15693_ENPREPARE;
	}
	if ( request->EnSingleByte == true ) {
		Data[0] = Data[0] + ISO15693_ENSINGLE_BYTE;
	}
	if ( request->EnReread == true ) {
		Data[0] = Data[0] + ISO15693_ENREREAD;
	}

	Data[1] = (unsigned char) (request->PageAddress >> 8);
	Data[2] = (unsigned char) request->PageAddress;

	if ( request->EnSingleByte == true ) {
		Data[3] = (unsigned char) request->ByteAddress;
		Len = 1;
	} else {
		Data[3] = (unsigned char) request->Len;
		Len = request->Len;
	}

	memcpy( Data + 4, request->Data, Len );

	return_val = brp_exec_command ( Handle,
								ISO15693_DEV_CODE,
								ISO15693_MYD_WRITE,
								Data,
								4 + Len,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								1 );

	if ( return_val == BRP_OK ) {
		*label_stat = Data[0];
	}

	return( return_val );
}

void iso15693_init_MydWrite_request( iso15693_MydWrite_request* structure ) {
	structure->EnSecure = false;
	structure->EnRestricted = false;
	structure->EnPrepare = false;
	structure->EnSingleByte = false;
	structure->EnReread = false;

	structure->PageAddress = 0;
	structure->ByteAddress = 0;
	structure->Len = 2;
}

