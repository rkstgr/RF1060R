#include "brp.h"
#include "iso14443_3b.h"
#include "oswrapper.h"
#include <string.h>

int iso14443_3b_request( int Handle, iso14443_3b_Request_request * request,
				iso14443_3b_Request_response * response, int *response_count,
				int response_max_count, int *Status ) {
	int return_val, brp_send_size, brp_recv_size, max_size;

	unsigned char *Data;
	int Num, i;

	// build request
	// get the buffer information from brp
	return_val = brp_get_bufsize( Handle, NULL,
				&brp_send_size, &brp_recv_size );

	if ( return_val != BRP_OK )
		return( return_val );
	max_size = ( brp_send_size > brp_recv_size ) ?
										brp_send_size : brp_recv_size;

	Data = (unsigned char *) malloc( max_size );

	if ( Data == NULL )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = 0x00;

	if ( request->ReqAll == true )
		Data[0] = Data[0] + ISO14443_3B_REQALL;
	Data[0] = Data[0] + request->TimeSlots;
	Data[1] = request->AFI;

	return_val = brp_exec_command ( Handle,
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_REQUEST,
								Data,
								2,
								BRP_TIMEOUT_VAR( request->TimeSlots ),
								Status,
								Data,
								NULL,
								max_size );

	// build response
	if ( ( return_val == BRP_OK ) && ( response != NULL ) ) {
		int bc;
		Num = Data[0];
		if ( Num > response_max_count ) {
			free( Data );
			return( BRP_ERR_INSUFFICIENT_MEM );
		}
		for( i = 0; i < Num; i = i + 1 ) {
			bc = 1 + i * 11;

			response[i].PUPI[0] = Data[bc];
			response[i].PUPI[1] = Data[bc + 1];
			response[i].PUPI[2] = Data[bc + 2];
			response[i].PUPI[3] = Data[bc + 3];

			response[i].AppData[0] = Data[bc + 4];
			response[i].AppData[1] = Data[bc + 5];
			response[i].AppData[2] = Data[bc + 6];
			response[i].AppData[3] = Data[bc + 7];

			response[i].EqDSDR = ( Data[bc + 8] & ISO14443_3B_EQDSDR_MASK ) == ISO14443_3B_EQDSDR_MASK;
			response[i].DS8 = ( Data[bc + 8] & ISO14443_3B_DS8_MASK ) == ISO14443_3B_DS8_MASK;
			response[i].DS4 = ( Data[bc + 8] & ISO14443_3B_DS4_MASK ) == ISO14443_3B_DS4_MASK;
			response[i].DS2 = ( Data[bc + 8] & ISO14443_3B_DS2_MASK ) == ISO14443_3B_DS2_MASK;
			response[i].DR8 = ( Data[bc + 8] & ISO14443_3B_DR8_MASK ) == ISO14443_3B_DR8_MASK;
			response[i].DR4 = ( Data[bc + 8] & ISO14443_3B_DR4_MASK ) == ISO14443_3B_DR4_MASK;
			response[i].DR2 = ( Data[bc + 8] & ISO14443_3B_DR2_MASK ) == ISO14443_3B_DR2_MASK;

			response[i].FSCI = ( Data[bc + 9] & ISO14443_3B_FSCI_MASK ) >> 4;
			response[i].ProtType = Data[bc + 9] & ISO14443_3B_PROT_TYPE_MASK;

			response[i].FWI = ( Data[bc + 10] & ISO14443_3B_FWI_MASK ) >> 4;

			response[i].CID = ( Data[bc + 10] & ISO14443_3B_CID_MASK ) == ISO14443_3B_CID_MASK;
			response[i].NAD = ( Data[bc + 10] & ISO14443_3B_NAD_MASK ) == ISO14443_3B_NAD_MASK;
		}

		if ( response_count != NULL )
			*response_count = Num;
	} else if ( response == NULL ) {
		free( Data );
		return( BRP_ERR_WRONG_PARAMETERS );
	}

	free( Data );

	return( return_val );
}

int iso14443_3b_attrib( int Handle, iso14443_3b_Attrib_request * request,
				iso14443_3b_Attrib_response * response, int * Status ) {
	int return_val;
	int Len;

	unsigned char Data[259];

	// build request
	if ( request != NULL ) {
		Data[0] = request->PUPI[0];
		Data[1] = request->PUPI[1];
		Data[2] = request->PUPI[2];
		Data[3] = request->PUPI[3];

		Data[4] = request->TR0 << 6;
		Data[4] = Data[4] + ( request->TR1 << 4 );
		if (request->_EOF == true )
			Data[4] = Data[4] + ISO14443_3B_EOF;
		if (request->_SOF == true )
			Data[4] = Data[4] + ISO14443_3B_SOF;

		Data[5] = request->DSI << 6;
		Data[5] = Data[5] + ( request->DRI << 4);
		Data[5] = Data[5] + request->FSDI;

		Data[6] = ISO14443_3B_ATTRIB_RFU;

		Data[7] = request->CID;
		if ( ( !request->EnHLR ) &&
			( !request->EnMBLI ) &&
			( !request->EnCID ) ) {
			Len = 8;
		} else {
			Data[8] = 0;
			if ( request->EnHLR )
				Data[8] = Data[8] + ISO14443_3B_MODE_HLR;
			if ( request->EnMBLI )
				Data[8] = Data[8] + ISO14443_3B_MODE_MBLI;
			if ( request->EnCID )
				Data[8] = Data[8] + ISO14443_3B_MODE_CID;
			Len = 9;
		}
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_ATTRIB,
								Data,
								Len,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								259 );

	// build response
	if ( ( return_val == BRP_OK ) && ( response != NULL ) ) {
		int offset;
		offset = 0;
		if ( request->EnCID ) {
			response->CID = Data[0];
			offset++;
		}
		if ( request->EnMBLI ) {
			response->MBLI = Data[offset];
			offset++;
		}
		if ( request->EnHLR ) {
			response->Length = Data[offset];
			if ( response->HLR )
				memcpy( response->HLR, Data + offset, response->Length );
		}
	}

	return( return_val );
}

int iso14443_3b_halt( int Handle, unsigned char * PUPI, int *Status ) {
	int return_val;

	unsigned char Data[4];

	if ( PUPI != NULL )
		memcpy( Data, PUPI, 4 );

	return_val = brp_exec_command ( Handle,
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_HALT,
								Data,
								4,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso14443_3b_set_transparent_setting( int Handle, iso14443_3b_tag * tag,
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
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_SET_TRANSPARENT_SETTING,
								Data,
								2,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

int iso14443_3b_get_transparent_setting( int Handle, iso14443_3b_tag * tag,
				int *Status ) {
	int return_val;

	unsigned char Data[2];

	return_val = brp_exec_command ( Handle,
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_GET_TRANSPARENT_SETTING,
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

int iso14443_3b_transparent_cmd( int Handle, iso14443_3b_Transparent_request * request,
				iso14443_3b_Transparent_response * response, int *Status ) {
	int return_val;

	unsigned char *Data;
	int brp_send_size, brp_recv_size, offset, max_size;

	// Build request
	// get the buffer information from brp
	return_val = brp_get_bufsize( Handle, NULL,
				&brp_send_size, &brp_recv_size );

	if ( return_val != BRP_OK )
		return( return_val );

	if ( request->Len > brp_send_size )
		return( BRP_ERR_INSUFFICIENT_MEM );

	Data = (unsigned char *) malloc( ( brp_send_size > brp_recv_size ) ?
										brp_send_size : brp_recv_size );

	// Build byte 1
	Data[0] = 0x00;
	if ( request->EnCRCRX == true )
		Data[0] = Data[0] + ISO14443_3B_ENCRCRX;
	if ( request->EnCRCTX == true )
		Data[0] = Data[0] + ISO14443_3B_ENCRCTX;

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
		memcpy( Data + 5 + offset, request->Data, request->Len );
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
								ISO14443_3B_DEV_CODE,
								ISO14443_3B_TRANSPARENT_CMD_14B,
								Data,
								request->Len + 5 + offset,
								BRP_TIMEOUT_VAR( request->Timeout / BRP_TIMEOUT_CHAR ),
								Status,
								Data,
								NULL,
								max_size );

	// build response
	if ( ( return_val == BRP_OK ) && ( response != NULL ) ) {
		response->Len = (short) ( Data[0] );
		response->Len = response->Len << 8;
		response->Len = response->Len + (short) ( Data[1] );

		if ( response->Data != NULL ) {
			memcpy( response->Data, Data + 2, response->Len );
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

void iso14443_3b_init_Request_request( iso14443_3b_Request_request * structure ) {
	structure->ReqAll = false;
	structure->TimeSlots = ISO14443_3B_TIMESLOTS_1;
	structure->AFI = 0;
}

void iso14443_3b_init_Attrib_request( iso14443_3b_Attrib_request * structure ) {
	structure->TR0 = ISO14443_3B_TR0_DELAY_DEFAULT;
	structure->TR1 = ISO14443_3B_TR1_DELAY_DEFAULT;
	structure->_EOF = false;
	structure->_SOF = false;

	structure->DSI = ISO14443_3B_DEFAULT_KBAUD;
	structure->DRI = ISO14443_3B_DEFAULT_KBAUD;
	structure->FSDI = ISO14443_3B_FSDI_DEFAULT_BYTE;

	structure->CID = ISO14443_3B_CID_DISABLED;

	structure->EnHLR = false;
	structure->EnMBLI = false;
	structure->EnCID = false;
}

void iso14443_3b_init_Transparent_request( iso14443_3b_Transparent_request * structure ) {
	structure->EnCRCRX = false;
	structure->EnCRCTX = false;
	structure->Len = 0;
	structure->Timeout = 200;
	structure->DSI_DRI_valid = true;
	structure->DSI = ISO14443_3B_DEFAULT_KBAUD;
	structure->DRI = ISO14443_3B_DEFAULT_KBAUD;
}

