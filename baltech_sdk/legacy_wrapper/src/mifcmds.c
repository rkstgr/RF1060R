#include "brp.h"
#include "mifcmds.h"

int mifcmd_request( int Handle,
	byte Mode, word* ATRQ,
	int * Status ) {

	byte *pATRQ;
	byte b_ATRQ[2];
	int return_val;
	int count;

	if ( ATRQ == NULL ) {
		count = 0;
		pATRQ = NULL;
	} else {
		count = 2;
		pATRQ = b_ATRQ;
	}

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_REQUEST,
								&Mode,
								1,
								BRP_TIMEOUT_SHORT,
								Status,
								pATRQ,
								NULL,
								count );

	if ( return_val == BRP_OK ) {
		if ( ATRQ != NULL ) {
			*ATRQ = (word) b_ATRQ[0];
			*ATRQ = *ATRQ << 8;
			*ATRQ = *ATRQ + (word) b_ATRQ[1];
		}
	}

	return return_val;
}
// ************************************************************

int mifcmd_anticoll( int Handle,
	byte BitCount, dword* Serial,
	int * Status ) {
	byte Data[5];
	int return_val;

	Data[0] = BitCount;
	Data[1] = (byte)( (*Serial) >> 24 );
	Data[2] = (byte)( (*Serial) >> 16 );
	Data[3] = (byte)( (*Serial) >> 8 );
	Data[4] = (byte)(*Serial);

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_ANTICOLL,
								Data,
								5,
								BRP_TIMEOUT_SHORT,
								Status,
								Data,
								NULL,
								4 );

	if ( return_val == BRP_OK ) {
		*Serial = (dword)Data[0];
		*Serial = *Serial << 8;
		*Serial = *Serial + (dword)Data[1];
		*Serial = *Serial << 8;
		*Serial = *Serial + (dword)Data[2];
		*Serial = *Serial << 8;
		*Serial = *Serial + (dword)Data[3];
	}

	return return_val;
}
// ************************************************************

int mifcmd_select( int Handle,
	dword Serial, byte* Size,
	int * Status ) {

	byte Data[4];
	int return_val;
	int count;

	if ( Size == NULL )
		count = 0;
	else
		count = 1;

	Data[0] = (byte)( Serial >> 24 );
	Data[1] = (byte)( Serial >> 16 );
	Data[2] = (byte)( Serial >> 8 );
	Data[3] = (byte)Serial;

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_SELECT,
								Data,
								4,
								BRP_TIMEOUT_SHORT,
								Status,
								Size,
								NULL,
								count );

	return return_val;
}
// ************************************************************

int mifcmd_auth_user( int Handle,
	byte AuthMode, byte Block, byte* Key,
	int * Status ) {

	byte Data[8];
	int return_val;

	Data[0] = AuthMode;
	Data[1] = Block;
	Data[2] = Key[0];
	Data[3] = Key[1];
	Data[4] = Key[2];
	Data[5] = Key[3];
	Data[6] = Key[4];
	Data[7] = Key[5];

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_AUTH_USER,
								Data,
								8,
								BRP_TIMEOUT_DEFAULT,
								Status,
								NULL,
								NULL,
								0 );

	return return_val;
}
// ************************************************************

int mifcmd_read( int Handle,
	byte Block, byte* Content,
	int * Status ) {
	byte Data[16];
	int return_val;

	Data[0] = Block;

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_READ,
								Data,
								1,
								BRP_TIMEOUT_DEFAULT,
								Status,
								Content,
								NULL,
								16 );

	return return_val;
}
// ************************************************************

int mifcmd_write( int Handle,
	byte Block, byte* Content,
	int * Status ) {
	byte Data[17];
	int return_val;

	Data[0] = Block;
	Data[1] = Content[0];
	Data[2] = Content[1];
	Data[3] = Content[2];
	Data[4] = Content[3];
	Data[5] = Content[4];
	Data[6] = Content[5];
	Data[7] = Content[6];
	Data[8] = Content[7];
	Data[9] = Content[8];
	Data[10] = Content[9];
	Data[11] = Content[10];
	Data[12] = Content[11];
	Data[13] = Content[12];
	Data[14] = Content[13];
	Data[15] = Content[14];
	Data[16] = Content[15];

	return_val = brp_exec_command ( Handle,
								MIFCMD_DEV_CODE,
								MIFCMD_WRITE,
								Data,
								17,
								BRP_TIMEOUT_DEFAULT,
								Status,
								Content,
								NULL,
								0 );

	return return_val;
}
// ************************************************************

