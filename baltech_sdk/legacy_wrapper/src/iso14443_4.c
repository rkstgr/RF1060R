#include "brp.h"
#include "iso14443_4.h"
#include "oswrapper.h"
#include <string.h>

int iso14443_4_setup_apdu( int Handle,
				iso14443_4_SetupAPDU_request * request, int *Status ) {
	int return_val;

	unsigned char Data[5];

	if ( request != NULL ) {
		Data[0] = 0x00;
		if ( request->EnDefault == true )
			Data[0] = Data[0] + ISO14443_4_ENDEFAULT;
		if ( request->UseB == true )
			Data[0] = Data[0] + ISO14443_4_USEB;
		if ( request->EnNAD == true )
			Data[0] = Data[0] + ISO14443_4_ENNAD;
		if ( request->EnCID == true )
			Data[0] = Data[0] + ISO14443_4_ENCID;

		Data[1] = request->CID;
		Data[2] = request->NAD;

		Data[3] = request->FSCI << 4;
		Data[3] = Data[3] + request->FWI;

		Data[4] = request->DSI << 2;
		Data[4] = Data[4] + request->DRI;
	} else
		return( BRP_ERR_WRONG_PARAMETERS );

	return_val = brp_exec_command ( Handle,
								ISO14443_4_DEV_CODE,
								ISO14443_4_SETUP,
								Data,
								5,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );
	return( return_val );
}

int iso14443_4_exchange_apdu( int Handle, unsigned char * param,
				int param_len, unsigned char * resp, int *resp_len,
				int resp_max_len, int *Status ) {
	int return_val;

	unsigned char * Data;

	Data = (unsigned char*) malloc( param_len + 2 );

	Data[0] = (unsigned char) ( param_len >> 8 );
	Data[1] = (unsigned char) param_len;

	if ( param != NULL )
		memcpy( Data + 2, param, param_len );

	return_val = brp_exec_command ( Handle,
								ISO14443_4_DEV_CODE,
								ISO14443_4_EXCHANGE_APDU,
								Data,
								param_len + 2,
								BRP_TIMEOUT_VAR( param_len + 450 ),
								Status,
								resp,
								resp_len,
								resp_max_len );

	free( Data );

	return( return_val );
}

int iso14443_4_deselect( int Handle, int *Status ) {
	int return_val;

	return_val = brp_exec_command ( Handle,
								ISO14443_4_DEV_CODE,
								ISO14443_4_DESELECT,
								NULL,
								0,
								BRP_TIMEOUT_SHORT,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}

void iso14443_4_init_SetupAPDU_request( iso14443_4_SetupAPDU_request * structure ) {
	structure->EnDefault = true;
	structure->UseB = true;
	structure->EnNAD = false;
	structure->EnCID = false;

	structure->CID = 0x00;
	structure->NAD = 0x00;

	structure->FSCI = ISO14443_4_FSCI_DEFAULT_BYTE;
	structure->FWI = 0x05;

	structure->DSI = ISO14443_4_DEFAULT_KBAUD;
	structure->DRI = ISO14443_4_DEFAULT_KBAUD;
}

