
#if ! defined(__BALTECH_READER_PROTOCOL__)
#define __BALTECH_READER_PROTOCOL__

#if defined(__cplusplus)
extern "C" {
#endif

#include "oswrapper.h"
#include "serial.h"

#if defined(BRP_SDK_COMPATIBILITY)
	#include "brp_lib.h"
	
	// some constants have different meanings in the new driver DLL
	// in this case they are renamed to constname + '_'.
	#undef BRP_ERR_STATUS
	#define BRP_ERR_STATUS_(cmd_code, statuscode) \
		((brp_errcode)(((cmd_code) & 0xFF00u) \
					   | ((statuscode) & 0xFFu) \
					   | BRP_ERRGRP_DEVICE))
	#undef BRP_OK
	#undef BRP_ERR_BUSY
	#define BRP_ERR_BUSY_               (0x0007u | BRP_ERRGRP_LIB_INVALIDCALL)
	#undef BRP_ERR_TIMEOUT
	#define BRP_ERR_TIMEOUT_            (0x0023u | BRP_ERRGRP_COMM_TIMEOUT)
	#undef BRP_ERR_UNEXPECTED_FRAME
	#define BRP_ERR_UNEXPECTED_FRAME_   (0x0022u | BRP_ERRGRP_COMM_FRAMEFORMAT)
	#undef BRP_ERR_BUFFER_OVERFLOW
	#define BRP_ERR_BUFFER_OVERFLOW_    (0x0009u | BRP_ERRGRP_COMM_FRAMEFORMAT)
	#undef BRP_MODE_CONTINUOUS
	#define BRP_MODE_CONTINUOUS_        1
	#undef BRP_MODE_REPEAT
	#define BRP_MODE_REPEAT_            2
#else
	#if ! defined(BRP_NO_SOCKET_HEADERS)
		#if defined(_WIN32)
			#include <ws2tcpip.h>
		#else
			typedef int SOCKET;
		#endif
	#endif
#endif

// Other default settings
#define BRP_MIN_BUFSIZE          0x80  // minimum values of *_bufsize (see 'brp_setup_session')
#define BRP_MIN_CMD_TIMEOUT      50    // minimum value for command timeouts
#define BRP_MAX_FRAME_OVERHEAD   7	   // additional BRPFrame Bytes
#define BRP_MAX_HANDLES          32	   // the max handles( public for ftob)
#define BRP_STAT_SIZE            1	   // size in byte of the status

// Return codes
#define BRP_OK                      0
#define BRP_ERR_STATUS           0x01  // the reader returned a statuscode != 0
#define BRP_ERR_BUSY             0x02  // the reader is working up a command
#define BRP_ERR_IDLE             0x03  // the reader is waiting for a command
#define BRP_ERR_TIMEOUT          0x04  // the response/alivemsg timed out
#define BRP_ERR_CORRUPTED_FRAME  0x05  // the reader sent a corrupted frame
#define BRP_ERR_UNEXPECTED_FRAME 0x06  // the reader sent a frame during idle state
#define BRP_ERR_GENERAL_IO       0x07  // the underlying port generated an error
#define BRP_ERR_BUFFER_OVERFLOW  0x08  // the reader sends more than max_resp_len bytes or
									   // the application tries to send more than send_bufsize
									   // bytes (see brp_setup_session)
#define BRP_ERR_NO_MORE_HANDLES	 0x09  // there are no free brp handles
#define BRP_ERR_INSUFFICIENT_MEM 0x0A  // there is not enough memory to create a new BRP Handle
#define BRP_ERR_WRONG_HANDLE	 0x0B  // the handle specified is not present
#define BRP_ERR_WRONG_PARAMETERS 0x0C  // the parameters of a command were not right
#define BRP_ERR_RS485_NO_RESPONSE 0x0D // the rs485 device is not connected or has a invalid address
#define BRP_ERR_CRYPTO           0x0E  // invalid crypto key / encrypted command/response is invalid

// Possible modes
#define BRP_MODE_DEFAULT         0x00  // no special mode
#define BRP_MODE_CONTINUOUS      0x02  // run in continous mode
#define BRP_MODE_CONTINOUS		 0x02  // is here due to typing error
#define BRP_MODE_REPEAT          0x01  // run in repeat mode

// Global definitions
#define BRP_TRUE                 0x01  // the systemwide true
#define BRP_FALSE                0x00  // the systemwide false

// Possible checksum algorithms
#define BRP_CHKSUM_NONE          0x00
#define BRP_CHKSUM_BCC8          0x01
#define BRP_CHKSUM_CRC16         0x02
#define BRP_CHKSUM_BCC16         0x03

// These can be taken for analyzing the response status
#define BRP_RESP_IS_STATUS       0x80
#define BRP_RESP_IS_HWERROR      0x40
#define BRP_RESP_BCC16           0x30
#define BRP_RESP_CRC16           0x20
#define BRP_RESP_BCC8            0x10
#define BRP_RESP_NO_CHKSUM       0x00
#define BRP_RESP_LENGTH          0x08
#define BRP_RESP_DEVCODE         0x04
#define BRP_RESP_CONTMODE        0x02
#define BRP_RESP_REPMODE         0x01

#define BRP_RESP_CHKSUMS         0x30

// Standard timeouts
#define BRP_TIMEOUT_SHORT        50    // use it for all static cmds without card interaction
#define BRP_TIMEOUT_DEFAULT      100   // use it for all static cmds with card interaction
#define BRP_TIMEOUT_LONG         500   // use it for timeout for commands with variable length
#define BRP_TIMEOUT_EXTRA_LONG   4000  // use it for constant long operating commands whose timeout is not defined length dependent.
#define BRP_TIMEOUT_CHAR         20    // use it for timeout for commands with variable length for each char
#define BRP_TIMEOUT_VAR(bytes)   (BRP_TIMEOUT_LONG + (BRP_TIMEOUT_CHAR * bytes))
									   // makro used for variable timeouts

// The standard alive timeout
#define BRP_ALIVE_DEFAULT        OSWRAP_NO_TIMEOUT
									   // a standard of 1000 ms = 1 second

// Default protocol parameters
#define BRP_DEFAULT_CHKSUM         BRP_CHKSUM_NONE
#define BRP_DEFAULT_ALIVETIMEOUT   OSWRAP_NO_TIMEOUT
#define BRP_DEFAULT_TOTAL_BUFSIZE  BRP_MIN_BUFSIZE
#define BRP_DEFAULT_SEND_BUFSIZE   BRP_MIN_BUFSIZE
#define BRP_DEFAULT_RECV_BUFSIZE   BRP_MIN_BUFSIZE
#define BRP_DEFAULT_DEVCODE_MAP    NULL


// authentication modes (see brp_open_crypto_session())
#define BRP_AM_SESSIONKEY    0x10   // generate a session key for encryption
#define BRP_AM_MAC           0x20   // append mac to data
#define BRP_AM_ENCRYPTED     0x40   // encrypt data
#define BRP_AM_CONTINUOUSIV  0x80   // use a continuous IV to avoid replay attacks




#if defined(BRP_SDK_COMPATIBILITY)

// creates a session from a brp_lib protocol. The Ownership keeps to the caller
// => the session will not be destroyed closed when running brp_close_session()
int brp_open_brplib_session(int *handle, brp_protocol brplib_protocol);

#endif

//opens a serial based brp session and returns the sessionhandle in 'handle'
int brp_open_serial_session(int *handle, int com_port, ser_baudrate baudrate, ser_parity parity );


// THIS IS LEGACY AND SHOULD NOT BE USED ANY MORE...
int brp_open_usb_session( int *handle, dword productID );


// should open a session to an hid device.
// if device name is NULL, it opens any available baltech (!) device (should only be used if 
// there is definitely only one baltech reader)
int brp_open_hid_session( int *handle, char * device_name );


// should open a session to an pcsc reader device.
// If reader_name is NULL, the an arbitrary BALTECH-PCSC reader will be opened.
int brp_open_pcsc_session( int *handle, char * reader_name );


// should open a session to an pcsc reader. instead of a readername the handle
// of an already opened device has to be specified. Please notice that the
// handle cannot be used until the session is closed again.
int brp_open_pcsc_handle_session( int *handle, long hSCardHandle);


// open a connection to a rs485 device. The command tests the specified
// comport for being already opened. If not it is opened. Furthermore
// the brp_net layer is used to manage the tokens and the rs485 layer
// to build the pakets transmitted over the bus.
int brp_open_rs485_session( int *handle, int com_port, ser_baudrate baudrate, ser_parity parity, int device_address );

// Open a connection to an TCP device with the specified IP address and port.
// port can be set to 0 in order to use the Baltech default port
// turn_around_timeout is the maximal time in milliseconds the commad blocks and tries to open a TCP connection.
// For all further commands of this session this timeout is added to the brp timeout to involve latency caused by 
// the TCP communication. 
// If turn_around_timeout is set to -1 a default value is used
int brp_open_tcp_session( int *handle, char * addr, unsigned short port , int turn_around_timeout);

// Open a connection to an TCP device using an connected socket handle 
// (in case of server mode: handle with accepted connect request)
// The turn_arount_timeout us used for further communication (see brp_open_tcp_session)
// Note: The socket_handle is set to non-blocking mode
int brp_open_tcp_handle_session( int *handle ,SOCKET socket_handle ,int turn_around_timeout);

//this command creates an encrypted channel
int brp_open_crypto_session(int *handle, int base_handle, int auth_mode_and_sec_level, byte * key);



//setup the given ('handle') brp session. the following parameters are needed:
// alive_timeout:   if a command is running in continous/repeat mode, and the
//                  reader is configured for alive messages, you can specify
//                  the maximum time between two alive messages
// interbyte_timeout: for character (non-block) devices this specifies the
//                  maximum time between two bytes
// checksum:        one of the BRP_CHKSUM_* values
// total_bufsize:   the maximum size of command parameter plus command response
// send_bufsize:    the maximum size of command parameter
// recv_bufsize:    the maximum size of command respose
// dev_code_map:    this optional parameter (may be NULL) is a table with 8
//                  entries. every entry is a devicecode, which can be
//                  shortcutted by a short command frame (without device code)
//                  the position in the table specifies the corresponding
//                  short-protocol device codes (three most significant bits
//                  of cmdcode)
// return codes:    if reader is busy these functions
int brp_set_checksum(int handle, int checksum);
int brp_set_alive_timeout(int handle, int alive_timeout);
int brp_set_interbyte_timeout(int handle, int interbyte_timeout);
int brp_set_bufsize(int handle, int total_bufsize, int send_bufsize, int recv_bufsize);
int brp_get_bufsize( int handle, int *total_bufsize, int *send_bufsize, int *recv_bufsize);


#if defined(BRP_SDK_COMPATIBILITY)

// retrieves the underlying brp_lib protocol assigned to a handle.
// ownership keeps with the BrpDriver library => the returned handle must never
// be passed to brp_destroy()
brp_protocol brp_get_brplib_protocol(int handle);

#endif


//free the given session handle
int brp_close_session(int handle);


//works up all data traffic until 'timeout' is over or a valid/invalid
//command response is received. this command can be run if the reader is idle
//AND if the reader is busy. it is optional to use this command, but we
//recommened to run it, since it enables the host to detect protocol errors
//during idle/busy state. if this command returns BRP_OK/BRP_ERR_STATUS you
//have to call 'brp_get_response'
int brp_run_session( int handle, int usertimeout );


//run a specific brp command on the reader
int brp_send_command(int handle, int mode,
	byte devcode, byte cmdcode, byte *param, int param_len, int timeout);

// extend the timeout of the next command by the specified amount of ms
int brp_extend_next_command_timeout( int handle, unsigned int ms_time );

//check if there is a response and read it. resp/resp_len will hold the
//response buffer, which can be limited by max_resp_len.
//resp_len maybe NULL
//resp maybe NULL
int brp_get_response(int handle, byte * resp, int * resp_len, int max_resp_len );

//get the status of the response. status will hold a status code
//if the reader failed to execute the command. The device code is the one received
//from the reader. With these two values you can specify the exact error that occurred.
//status maybe NULL
int brp_get_response_status(int handle, int * status );

//breaks any command running in continous or repeat mode
int brp_break_command(int handle);


//this command can be used for simple commands without continous mode
int brp_exec_command(int handle,
	byte devcode, byte cmdcode, byte *param, int param_len, int timeout,
	int * status, byte * resp, int * resp_len, int max_resp_len);

// returns version of driver
const char * brp_get_driver_version(void);


#if defined(__cplusplus)
}
#endif

#endif
