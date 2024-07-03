#include "brp.h"
#include "ftob.h"
#include "oswrapper.h"
#include <string.h>

////////// some private settings

#define FTOB_WRITE_HEADER		3
#define FTOB_READ_HEADER		2

#define FTOB_NO_KNOWN_SIZE		0

static struct {
	unsigned int retry_count;

	unsigned int buf_size;
	unsigned int recv_size;

	byte* buffer;
	byte* write_data;
	byte* read_data;
	unsigned int len;
	bool need_flush;
	bool toggle;
} handle_list[BRP_MAX_HANDLES];
//------------------------------------------------------------------------

///////// some private functions
int ftob_set_buffer_size( int Handle, unsigned int SendSize,
	unsigned int RecvSize ) {
	int brp_send_size, brp_recv_size;
	int return_val;

	// get the buffer information from brp
	return_val = brp_get_bufsize( Handle, NULL,
					&brp_send_size, &brp_recv_size );
	// if something went wrong
	if ( return_val != BRP_OK )
		return( return_val );

	// if the size from user is too big
	if ( (int) SendSize > brp_send_size - FTOB_WRITE_HEADER )
		SendSize = brp_send_size - FTOB_WRITE_HEADER;
	if ( (int) RecvSize > brp_recv_size - FTOB_READ_HEADER )
		RecvSize = brp_recv_size - FTOB_READ_HEADER;

	// if no Size is reported
	if ( SendSize == 0 )
		SendSize = brp_send_size - FTOB_WRITE_HEADER;
	if ( RecvSize == 0 )
		RecvSize = brp_recv_size - FTOB_READ_HEADER;

	// only resize if the buffers are too small
	if ( ( handle_list[Handle].buf_size < SendSize ) &&
		( handle_list[Handle].recv_size < RecvSize ) ) {
		handle_list[Handle].buf_size = SendSize;
		handle_list[Handle].recv_size = RecvSize;

		if ( handle_list[Handle].buffer != NULL )
			free( handle_list[Handle].buffer );
		handle_list[Handle].buffer = (byte*) malloc( SendSize + FTOB_WRITE_HEADER );
		if ( handle_list[Handle].buffer == NULL )
			return( BRP_ERR_BUFFER_OVERFLOW );
		handle_list[Handle].write_data = handle_list[Handle].buffer + FTOB_WRITE_HEADER;
		handle_list[Handle].read_data = handle_list[Handle].buffer + FTOB_READ_HEADER;
	}

	return( BRP_OK );
}
//------------------------------------------------------------------------

unsigned int ftob_get_buffer_size( int Handle ) {
	return( handle_list[Handle].buf_size );
}
//------------------------------------------------------------------------

int OpenReadFile( int Handle, byte* Name, int len, int* Status ){
	byte* data;

	int return_val;

	data = (byte*) malloc( len + 1 );

	// Filename Length
	data[0] = (byte) len;
	// Filename
	memcpy( data + 1, Name, len );

	return_val = brp_exec_command ( Handle,
								FTOB_DEV_CODE,
								FTOB_START_READ_FILE,
								data,
								len + 1,
								BRP_TIMEOUT_VAR( len + 1 ),
								Status,
								NULL,
								NULL,
								0 );
	free( data );

	return( return_val );
}
//------------------------------------------------------------------------

int OpenWriteFile( int Handle, byte* Name, int len, int* Status ){
	byte* data;

	int return_val;
	byte answer[2];
	dword size;

	data = (byte*) malloc( len + 1 );

	// Filename Length
	data[0] = (byte) len;
	// Filename
	memcpy( data + 1, Name, len );

	return_val = brp_exec_command ( Handle,
								FTOB_DEV_CODE,
								FTOB_START_WRITE_FILE,
								data,
								len + 1,
								BRP_TIMEOUT_VAR( len + 1 ),
								Status,
								answer,
								NULL,
								2 );
	free( data );

	if ( return_val == BRP_OK ) {
		// get the maxsize for the reader.
		size = answer[0];
		size = size << 8;
		size = size + answer[1];

		// set the max buffer size
		ftob_set_buffer_size( Handle, size, FTOB_NO_KNOWN_SIZE );
	}

	return( return_val );
}
//------------------------------------------------------------------------

int ReadFileBlock( int Handle, bool Toggle, int* Status ){
	int return_val;
	int len;
	int buf_len;

	buf_len = handle_list[Handle].recv_size;

	// set the toggle bit
	if ( Toggle == true )
		handle_list[Handle].buffer[0] = BRP_TRUE;
	else
		handle_list[Handle].buffer[0] = BRP_FALSE;
	// Set the maxlen of the buffer.
	handle_list[Handle].buffer[1] = (byte) (buf_len >> 8);
	handle_list[Handle].buffer[2] = (byte) buf_len;

	return_val = brp_exec_command ( Handle,
								FTOB_DEV_CODE,
								FTOB_READ_FILE_BLOCK,
								handle_list[Handle].buffer,
								3,
								BRP_TIMEOUT_VAR( buf_len + 3 ),
								Status,
								handle_list[Handle].buffer,
								&len,
								handle_list[Handle].recv_size + FTOB_READ_HEADER );
	if ( return_val != BRP_OK )
		return( return_val );

	// receive the length of data that was received
	handle_list[Handle].len = handle_list[Handle].buffer[0];
	handle_list[Handle].len = handle_list[Handle].len << 8;
	handle_list[Handle].len = handle_list[Handle].len + handle_list[Handle].buffer[1];

	return( return_val );
}
//------------------------------------------------------------------------

int WriteFileBlock( int Handle, bool Toggle, int* Status ){
	int return_val;

	// set the toggle bit
	if ( Toggle == true )
		handle_list[Handle].buffer[0] = BRP_TRUE;
	else
		handle_list[Handle].buffer[0] = BRP_FALSE;
	// set the length of the data
	handle_list[Handle].buffer[1] = (byte) ( handle_list[Handle].len >> 8 );
	handle_list[Handle].buffer[2] = (byte) handle_list[Handle].len;

	return_val = brp_exec_command ( Handle,
								FTOB_DEV_CODE,
								FTOB_WRITE_FILE_BLOCK,
								handle_list[Handle].buffer,
								handle_list[Handle].len + 3,
								BRP_TIMEOUT_VAR( handle_list[Handle].len ),
								Status,
								NULL,
								NULL,
								0 );
	return( return_val );
}
//------------------------------------------------------------------------

int CloseFile( int Handle, bool Success, int* Status ) {
	byte data[1];
	int return_val;

	// set the success bit
	if ( Success == true )
		data[0] = BRP_TRUE;
	else
		data[0] = BRP_FALSE;

	return_val = brp_exec_command ( Handle,
								FTOB_DEV_CODE,
								FTOB_CLOSE_FILE,
								data,
								1,
								BRP_TIMEOUT_LONG,
								Status,
								NULL,
								NULL,
								0 );

	return( return_val );
}
//------------------------------------------------------------------------

///////// properties
int ftob_set_max_retries( int Handle, unsigned int Retries ) {
	handle_list[Handle].retry_count = Retries;
	return( BRP_OK );
}
//------------------------------------------------------------------------

unsigned int ftob_get_max_retries( int Handle ) {
	return( handle_list[Handle].retry_count );
}
//------------------------------------------------------------------------

///////// public stuff
int ftob_open_file( int Handle,
				byte * FileName, char AccessMode,
				int * Status ) {
	int return_val;
	int NameLen;

	NameLen = (int) strlen( (char*) FileName ); // assumption: Filenames are not longer than an int

	// check the length of the filename.
	if ( NameLen > FTOB_MAX_FILE_NAME_LENGTH ) {
		*Status = FTOB_ERR_INVALID_FILENAME;
		return( BRP_ERR_STATUS );
	}

	// set the buffersize
	return_val = ftob_set_buffer_size( Handle, FTOB_NO_KNOWN_SIZE, FTOB_NO_KNOWN_SIZE );
	if ( return_val != BRP_OK )
		return( return_val );

	// set the default retry count
	handle_list[Handle].retry_count = FTOB_DFLT_RETRY_COUNT;

	// set the length of the data
	handle_list[Handle].len = 0;

	// set the toggle bit
	handle_list[Handle].toggle = false;

	// set the variable to determine whether something is not send to reader yet
	handle_list[Handle].need_flush = false;

	// open the file in the specific mode
	if ( AccessMode == FTOB_MODE_WRITE )
		return_val = OpenWriteFile( Handle, FileName, NameLen , Status );
	else
		return_val = OpenReadFile( Handle, FileName, NameLen , Status );

	return( return_val );
}
//------------------------------------------------------------------------

int ftob_write_file( int Handle,
				byte * Data, dword Length,
				int * Status ) {
	int return_val;
	dword length_counter;
	int fail_count;

	length_counter = Length;

	fail_count = 0;

	// is there something that needs to be flushed?
	return_val = ftob_flush( Handle, Status );

	if ( return_val != BRP_OK )
		return( return_val );

	while ( length_counter > 0 ) {
		// if enough data is there to transmit
		if ( length_counter >= handle_list[Handle].buf_size ) {
			// store the data to the buffer
			memcpy( handle_list[Handle].write_data, Data + Length - length_counter, handle_list[Handle].buf_size );
			handle_list[Handle].len = handle_list[Handle].buf_size;

			// write the data and if failure try it retry_count times again
			do {
				return_val = WriteFileBlock( Handle,
								handle_list[Handle].toggle, Status );
				if ( return_val != BRP_OK ) {
					fail_count = fail_count + 1;
				} else {
					// reset the toggle bit
					if ( handle_list[Handle].toggle == true )
						handle_list[Handle].toggle = false;
					else
						handle_list[Handle].toggle = true;
				}
			} while ( ( return_val != BRP_OK )
				&& ( (unsigned int) fail_count < handle_list[Handle].retry_count ) );

			// calculate the new length
			length_counter = length_counter - handle_list[Handle].buf_size;
			// care about the toggle bit
			if ( length_counter == 0 )
				handle_list[Handle].toggle = false;
		} else {
			// store the data to the buffer
			memcpy( handle_list[Handle].write_data, Data + Length - length_counter, length_counter );
			handle_list[Handle].len = length_counter;
			handle_list[Handle].need_flush = true;
			length_counter = 0;
		}
	}

	return( return_val );
}
//------------------------------------------------------------------------

int ftob_read_file( int Handle,
				byte * Data, dword * Length, dword MaxLength,
				int * Status )  {
	int return_val;
	int fail_count;

	*Length = 0;
	fail_count = 0;

	// write the data and if failure try it retry_count times again
	do {
		// test the length of the given user buffer
		if ( *Length + handle_list[Handle].recv_size > MaxLength ) {
			return( BRP_ERR_BUFFER_OVERFLOW );
		} else {
			return_val = ReadFileBlock( Handle, handle_list[Handle].toggle, Status );
			if ( return_val != BRP_OK ) {
				fail_count = fail_count + 1;
			} else {
				// store the data to the buffer
				memcpy( Data + *Length, handle_list[Handle].read_data, handle_list[Handle].len );

				// calculate the new length
				*Length = *Length + handle_list[Handle].len;

				// reset the toggle bit
				if ( handle_list[Handle].toggle == true )
					handle_list[Handle].toggle = false;
				else
					handle_list[Handle].toggle = true;
			}
		}
	} while ( ( (unsigned int) fail_count < handle_list[Handle].retry_count )
		&& ( handle_list[Handle].len > 0 ) );

	return( return_val );
}
//------------------------------------------------------------------------

int ftob_flush( int Handle,
				int * Status )  {
	int return_val;
	int fail_count;

	if ( handle_list[Handle].need_flush == false )
		return ( BRP_OK );

	fail_count = 0;

	// write the data and if failure try it retry_count times again
	do {
		return_val = WriteFileBlock( Handle,
						handle_list[Handle].toggle, Status );
		if ( return_val != BRP_OK ) {
			fail_count = fail_count + 1;
		} else {
			// reset the toggle bit
			if ( handle_list[Handle].toggle == true )
				handle_list[Handle].toggle = false;
			else
				handle_list[Handle].toggle = true;
		}
	} while ( ( return_val != BRP_OK )
		&& ( (unsigned int) fail_count < handle_list[Handle].retry_count ) );

	// if the data was transmitted (the file is flushed) set need flush to false
	if ( return_val == BRP_OK )
		handle_list[Handle].need_flush = false;

	return( return_val );
}
//------------------------------------------------------------------------

int ftob_close_file( int Handle, bool Success,
				int * Status ) {
	int return_val;

	// test if a flush is needed
	if ( handle_list[Handle].need_flush == true ) {
		return_val = ftob_flush( Handle, Status );
		if ( return_val != BRP_OK )
			Success = false;
	}

	return_val = CloseFile( Handle, Success, Status );

	return ( return_val );
}
//------------------------------------------------------------------------
