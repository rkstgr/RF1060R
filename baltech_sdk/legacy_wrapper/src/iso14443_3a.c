#include "brp.h"
#include "iso14443_3a.h"
#include "oswrapper.h"
#include <string.h>

int iso14443_3a_request( int Handle, bool ReqAll, iso14443_3a_ATQA * ATQA,
				int *Status ) {
	int return_val;

	unsigned char Data[2];

	// build request
	if ( ReqAll == true )
		Data[0] = ISO14443_3A_REQ_ALL_TRUE;
	else
		Data[0] = ISO14443_3A_REQ_ALL_FALSE;

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_REQUEST,
								Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								2 );

	// build response
	if ( ( return_val == BRP_OK ) && ( ATQA != NULL ) ) {
		ATQA->UIDsize = ( ISO14443_3A_UID_MASK & Data[0] ) >> 6;
		ATQA->Coll = ISO14443_3A_COLL_MASK & Data[0];
	} else if ( ATQA == NULL )
		return( BRP_ERR_WRONG_PARAMETERS );

	return( return_val );
}

int iso14443_3a_select( int Handle, iso14443_3a_Select_request * request,
				iso14443_3a_SAK * SAK, int *Status ) {
	int return_val;

	unsigned char Data[12];

	int Len;

	// build request
	if ( request != NULL ) {
		Len = ( request->BitCount + 7 ) / 8; // len of preselser

		Data[0] = request->CascLev;
		Data[1] = request->BitCount;
		memcpy( Data + 2, request->PreSelSer, Len );
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_SELECT,
								Data,
								Len + 2,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								12 );

	// build response
	if ( ( return_val == BRP_OK ) && ( SAK != NULL ) ) {
		SAK->Comp = ( ( ISO14443_3A_COMP_MASK & Data[0] ) == ISO14443_3A_COMP_MASK );
		SAK->Casc = ( ( ISO14443_3A_CASC_MASK & Data[0] ) == ISO14443_3A_CASC_MASK );
		SAK->SerLen = Data[1];
		memcpy( SAK->Serial, Data + 2, SAK->SerLen );
	} else if ( SAK == NULL )
		return( BRP_ERR_WRONG_PARAMETERS );

	return( return_val );
}

int iso14443_3a_halt( int Handle, int *Status ) {
	int return_val;

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_HALT,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso14443_3a_request_ats( int Handle, iso14443_3a_RATSParam * RATSParam,
				iso14443_3a_ATS * ATS, int *Status ) {
	int return_val;

	unsigned char Data[32];
	int bc;

	bc = 0;

	// Build request
	if ( RATSParam != NULL ) {
		Data[0] = RATSParam->FSDI;
		Data[0] = Data[0] << 4;
		Data[0] = Data[0] + RATSParam->CID;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_REQUEST_ATS,
								Data,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								32 );

	// build response
	if ( ( return_val == BRP_OK ) && ( ATS != NULL ) ) {
		// Byte 0
		ATS->TL = Data[0];
		ATS->T0_valid = ( ATS->TL > 1 );

		// Byte 1
		if ( ATS->T0_valid == true ) {
			bc = bc + 1;
			ATS->TC_valid = ( ( ISO14443_3A_TC_VALID_MASK & Data[bc] ) == ISO14443_3A_TC_VALID_MASK );
			ATS->TB_valid = ( ( ISO14443_3A_TB_VALID_MASK & Data[bc] ) == ISO14443_3A_TB_VALID_MASK );
			ATS->TA_valid = ( ( ISO14443_3A_TA_VALID_MASK & Data[bc] ) == ISO14443_3A_TA_VALID_MASK );

			ATS->T0_FSCI = Data[bc] & ISO14443_3A_FSCI_MASK;
		}

		// ********
		if ( ATS->TA_valid == true ) {
			bc = bc + 1;
			ATS->TA_EqDSDR = ( ( ISO14443_3A_EQDSDR_MASK & Data[bc] ) == ISO14443_3A_EQDSDR_MASK );
			ATS->TA_DS8 = ( ( ISO14443_3A_DS8_MASK & Data[bc] ) == ISO14443_3A_DS8_MASK );
			ATS->TA_DS4 = ( ( ISO14443_3A_DS4_MASK & Data[bc] ) == ISO14443_3A_DS4_MASK );
			ATS->TA_DS2 = ( ( ISO14443_3A_DS2_MASK & Data[bc] ) == ISO14443_3A_DS2_MASK );
			ATS->TA_DR8 = ( ( ISO14443_3A_DR8_MASK & Data[bc] ) == ISO14443_3A_DR8_MASK );
			ATS->TA_DR4 = ( ( ISO14443_3A_DR4_MASK & Data[bc] ) == ISO14443_3A_DR4_MASK );
			ATS->TA_DR2 = ( ( ISO14443_3A_DR2_MASK & Data[bc] ) == ISO14443_3A_DR2_MASK );
		}

		// *********
		if ( ATS->TB_valid == true ) {
			bc = bc + 1;
			ATS->TB_FWI = ( ( ISO14443_3A_FWI_MASK & Data[bc] ) >> 4 );
			ATS->TB_SFGI = ( ISO14443_3A_SFGI_MASK & Data[bc] );
		}

		// *********
		if ( ATS->TC_valid == true ) {
			bc = bc + 1;
			ATS->TC_CID = ( ( ISO14443_3A_CID_MASK & Data[bc] ) == ISO14443_3A_CID_MASK );
			ATS->TC_NAD = ( ( ISO14443_3A_NAD_MASK & Data[bc] ) == ISO14443_3A_NAD_MASK );
		}

		// *********
		memcpy( ATS->AppInfo, Data + bc + 1, ATS->TL - bc - 1 );
	} else if ( ATS == NULL )
		return( BRP_ERR_WRONG_PARAMETERS );

	return( return_val );
}

int iso14443_3a_perform_pps( int Handle, iso14443_3a_PPS_request * request,
				int *Status ) {
	int return_val;

	unsigned char Data[2];

	// Build request
	if ( request != NULL ) {
		Data[0] = request->CID;
		Data[1] = request->DSI;
		Data[1] = Data[1] << 2;
		Data[1] = Data[1] + request->DRI;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_PERFORM_PPS,
								Data,
								2,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso14443_3a_set_transparent_setting( int Handle, iso14443_3a_tag * tag,
				int *Status ) {
	int return_val;

	unsigned char Data[2];

	// Build request
	if ( tag != NULL ) {
		Data[0] = tag->TagID;
		Data[1] = tag->TagValue;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_SET_TRANSPARENT_SETTING,
								Data,
								2,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso14443_3a_get_transparent_setting( int Handle, iso14443_3a_tag * tag,
				int *Status ) {
	int return_val;

	unsigned char Data[2];

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_GET_TRANSPARENT_SETTING,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								2 );

	// build response
	if ( ( return_val == BRP_OK ) && ( tag != NULL ) ) {
		tag->TagID = Data[0];
		tag->TagValue = Data[1];
	} else if ( tag == NULL )
		return( BRP_ERR_WRONG_PARAMETERS );

	return( return_val );
}

int iso14443_3a_transparent_cmd( int Handle, iso14443_3a_Transparent_request * request,
				iso14443_3a_Transparent_response * response, int *Status ) {
	int return_val;

	unsigned char *Data;
	int byte_len, brp_send_size, brp_recv_size, offset, max_size;

	// Build request
	// get the right len
	if ( request->EnBitMode == true )
		byte_len = ( request->Len + 7 ) / 8;
	else
		byte_len = request->Len;

	// get the buffer information from brp
	return_val = brp_get_bufsize( Handle, NULL,
				&brp_send_size, &brp_recv_size );

	if ( return_val != BRP_OK )
		return( return_val );

	if ( byte_len > brp_send_size )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data = (unsigned char *) malloc( ( brp_send_size > brp_recv_size ) ?
										brp_send_size : brp_recv_size );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	// Build byte 1
	Data[0] = 0x00;
	if ( request->EnParTx == true )
		Data[0] = Data[0] + ISO14443_3A_ENPARTX;
	if ( request->EnBitMode == true )
		Data[0] = Data[0] + ISO14443_3A_ENBITMODE;
	if ( request->EnCRCRX == true )
		Data[0] = Data[0] + ISO14443_3A_ENCRCRX;
	if ( request->EnCRCTX == true )
		Data[0] = Data[0] + ISO14443_3A_ENCRCTX;
	if ( request->ParityMode == true )
		Data[0] = Data[0] + ISO14443_3A_PARITYMODE;
	if ( request->EnParity == true )
		Data[0] = Data[0] + ISO14443_3A_ENPARITY;

	// ************
	Data[1] = (unsigned char) ( ( request->Len ) >> 8 );
	Data[2] = (unsigned char) request->Len;

	// ************
	Data[3] = (unsigned char) ( ( request->Timeout ) >> 8 );
	Data[4] = (unsigned char) request->Timeout;

	// ************
	if ( request->DSI_DRI_valid == true ) {
		Data[5] = ( request->DSI ) << 2;
		Data[5] = Data[5] + request->DRI;
		offset = 1;
	} else
		offset = 0;

	// ***********
	if ( request->Data != NULL )
		memcpy( Data + 5 + offset, request->Data, byte_len );
	else {
		free( Data );
		return( BRP_ERR_WRONG_PARAMETERS );
	}

	// check for the real max_len
	if ( response != NULL )
		max_size = ( brp_recv_size < response->max_len + 4 ) ?
						brp_recv_size : ( response->max_len + 4 );
	else {
		free( Data );
		return( BRP_ERR_WRONG_PARAMETERS );
	}

	return_val = brp_exec_command ( Handle,
								ISO14443_3A_DEV_CODE,
								ISO14443_3A_TRANSPARENT_CMD_14A,
								Data,
								byte_len + 5 + offset,
								BRP_TIMEOUT_VAR( request->Timeout / BRP_TIMEOUT_CHAR ),
								Status,
								Data,
								&byte_len,
								max_size );

	// build response
	if ( ( return_val == BRP_OK ) && ( response != NULL ) ) {
		response->Len = (short) ( Data[0] );
		response->Len = response->Len << 8;
		response->Len = response->Len + (short) ( Data[1] );

		if ( request->EnBitMode == true ) {
			response->CollPos = (short) ( Data[2] );
			response->CollPos = response->CollPos << 8;
			response->CollPos = response->CollPos + (short) ( Data[3] );
			offset = 4;
		} else {
			response->CollPos = 0;
			offset = 2;
		}

		if ( response->Data != NULL ) {
			memcpy( response->Data, Data + offset, response->Len );
		} else {
			free( Data );
			return( BRP_ERR_WRONG_PARAMETERS );
		}
	} else if ( response == NULL ) {
		free( Data );
		return( BRP_ERR_WRONG_PARAMETERS );
	}

	free( Data );

	return( return_val );
}

void iso14443_3a_init_Select_request( iso14443_3a_Select_request * structure ) {
	structure->CascLev = ISO14443_3A_CASCLEV_COMPLETE;
	structure->BitCount = 0;
}

void iso14443_3a_init_RATSParam( iso14443_3a_RATSParam * structure ) {
	structure->FSDI = ISO14443_3A_FSDI_64_BYTE;
	structure->CID = ISO14443_3A_CID_DISABLED;
}

void iso14443_3a_init_PPS_request( iso14443_3a_PPS_request * structure ) {
	structure->CID = ISO14443_3A_CID_DISABLED;
	structure->DSI = ISO14443_3A_DEFAULT_KBAUD;
	structure->DRI = ISO14443_3A_DEFAULT_KBAUD;
}

void iso14443_3a_init_Transparent_request( iso14443_3a_Transparent_request * structure ) {
	structure->EnParTx = false;
	structure->EnBitMode = false;
	structure->EnCRCRX = false;
	structure->EnCRCTX = false;
	structure->ParityMode = true;
	structure->EnParity = true;

	structure->Len = 0;
	structure->Timeout = 200;
	structure->DSI_DRI_valid = true;
	structure->DSI = ISO14443_3A_DEFAULT_KBAUD;
	structure->DRI = ISO14443_3A_DEFAULT_KBAUD;
}

