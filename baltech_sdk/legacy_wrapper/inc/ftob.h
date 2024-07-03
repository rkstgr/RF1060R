
#if ! defined(__BALTECH_DRIVER_FTOB_COMMANDS__)
#define __BALTECH_DRIVER_FTOB_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// the max number for handles of ftob layer.
#define FTOB_MAX_OPENED_HANDLES		32

// the max size for a filename
#define FTOB_MAX_FILE_NAME_LENGTH	128

// the devcode for FTOB
#define FTOB_DEV_CODE		0x03

// define cmd_codes for the requests to the reader
#define FTOB_START_READ_FILE	0x00
#define FTOB_START_WRITE_FILE	0x01
#define FTOB_READ_FILE_BLOCK	0x02
#define FTOB_WRITE_FILE_BLOCK	0x03
#define FTOB_CLOSE_FILE			0x04

// define stati coming from the reader
#define FTOB_ERR_INVALID_FILENAME	0x0301
#define FTOB_ERR_ACCESS_DENIED		0x0302
#define FTOB_ERR_WRITE_BLOCK		0x0303
#define FTOB_ERR_READ_BLOCK			0x0304
#define FTOB_ERR_NO_FILE_ACTIVE		0x0305
#define FTOB_ERR_OUT_OF_MEMORY		0x0306

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************
// ftob_open_file:
// This command opens a file in either read or write access mode. The write
// mode can create AND overwrite files on the reader without further information
// about that.
// Handle:			The handle that should be used for this request
// FileName:		this null-terminated string references the filename
//					the reader should grant access to.
// AccessMode:		If you want to read from the file use 'R' and if you
//					want to write the file use 'W' when opening the file
// Status[2 Byte]:  The status of the reader layer. Can be NULL.
#define FTOB_MODE_READ	'R'
#define FTOB_MODE_WRITE	'W'
int ftob_open_file( int Handle,
				byte * FileName, char AccessMode,
				int * Status );

// ftob_write_file
// this command write Length bytes to the readers opened file. Note that the
// Length can exceed the buffer size given by the ftob_set_buffer_size. Note
// that the BRP layer can report BRP_ERR_BUFFER_OVERFLOW if the buffer size is
// too big for it.
// The write file does not send all data to the reader. To ensure this you can
// use ftob_flush. The ftob_close_file tries to flush a file opened in write
// mode as well.
// Handle:			The handle that should be used for this request
// Data:			The data for the reader. This buffer has to provide as many
//					bytes as the ftob is using as buffer_size (default = 128)
// Length:			The length of the data.
// Status[2 Byte]:  The status of the reader layer. Can be NULL.
int ftob_write_file( int Handle,
				byte * Data, dword Length,
				int * Status );

// ftob_read_file
// this command reads Length Bytes from the reader. The maximal length is set
// by using the ftob_set_buf_size. If there are more bytes in the file than
// space in the buffer the read request gives back only buf_size bytes and the
// read_file has to be used again, if the file should be read out completely.
// Please note that the BRP Layer can report BRP_ERR_BUFFER_OVERFLOW if the file
// and the ftob buffer size is bigger than the BRP ones.
// Handle:			The handle that should be used for this request
// Data:			The answer of the reader. This buffer has to provide as many
//					bytes as the ftob is using as buffer_size (default = 128)
// Length[1 Byte]:	The length of the data.
// Status[2 Byte]:  The status of the reader layer. Can be NULL.
int ftob_read_file( int Handle,
				byte * Data, dword * Length, dword MaxLength,
				int * Status );

// ftob_flush
// Calling this you can ensure that any file opened in write mode is written
// completely to the reader.
// Handle:			The handle that should be used for this request
// Status[2 Byte]:  The status of the reader layer. Can be NULL.
int ftob_flush( int Handle,
				int * Status );

// ftob_close_file
// this command flushes any not transmitted data and closes the connection.
// Handle:			The handle that should be used for this request
// Success:			This boolean is used to tell the reader (in write mode only)
//					that the file was successfully transmitted.
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int ftob_close_file( int Handle, bool Success,
				int * Status );

// max_retries
// this is a property of the ftob and stores the number of retries if an read or
// write error occures. The default value is:
#define FTOB_DFLT_RETRY_COUNT		2
int ftob_set_max_retries( int Handle, unsigned int Retries );
unsigned int ftob_get_max_retries( int Handle );

#if defined(__cplusplus)
}
#endif

#endif