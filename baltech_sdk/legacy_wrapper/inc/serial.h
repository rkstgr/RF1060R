
#if ! defined(__SERIAL_INTERFACE__)
#define __SERIAL_INTERFACE__

#if defined(__cplusplus)
extern "C" {
#endif


#include "compiler.h"

#define SER_OK                  0   //no error
#define SER_ERR_OPEN            1   //cannot open port
									//(in use/SER_MAX_OPEN_PORTS exceeded/...)
#define SER_ERR_BLOCK_TIMEOUT   2   //block timeout occured
#define SER_ERR_IO              3   //general io error
#define SER_ERR_HANDLE          4   //invalid port handle


//maximum number of ports, which may opened at the same time.
#define SER_MAX_OPENED_PORTS    32


typedef enum {
	ser_baud_300,
	ser_baud_600,
	ser_baud_1200,
	ser_baud_2400,
	ser_baud_4800,
	ser_baud_9600,
	ser_baud_14400,
	ser_baud_19200,
	ser_baud_28800,
	ser_baud_38400,
	ser_baud_57600,
	ser_baud_115200,
	ser_baud_576000,
	ser_baud_921600,
	ser_baud_500000,
} ser_baudrate;

typedef enum {
	ser_par_none,
	ser_par_odd,
	ser_par_even,
} ser_parity;


//opens the specified port with the given interbyte_timeout. possible result
//codes are SER_OK or SER_ERR_OPEN. on successfull operation, the
//port is enabled and the initial settings are: ser_baud_9600, ser_par_none.
int ser_open(int * handle, int port);


//change settings of serial line. attention: this command must not be executed
//while another task is running a pending read or write.
//
int ser_setup(int handle, ser_baudrate baudrate, ser_parity parity, bool rts_enabled, bool force_two_stopbits);


//setup interbyte-timeout
int ser_set_timeout(int handle, int byte_timeout);


//waits up to block_timeout to receive a character. after the first character
//was received, this methods receives up to 'max_len' characters as long as the
//distance between two characters is shorter than 'interbyte_timeout'
//(see ser_open). the result is stored in 'block' (its len is stored in 'len')
int ser_read(int handle, byte *block, int *len, int max_len, int block_timeout);


//sends 'len' characters from 'block'.
int ser_write(int handle, byte *block, int len);


//close 'handle'
int ser_close(int handle);

#if defined(__cplusplus)
}
#endif


#endif