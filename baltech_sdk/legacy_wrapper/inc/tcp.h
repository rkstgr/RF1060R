
#if ! defined(__TCP_INTERFACE__)
#define __TCP_INTERFACE__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"

#define TCP_OK                  0            //no error
#define TCP_NETWORK_SYSTEM_NOT_AVAILABLE 5   //socket communication not available on this system
#define TCP_TOO_MANY_SOCKET_APPLICATIONS 6   //too many socket communications on this system
#define TCP_INIT_ERROR 7                     // Error on socket initialisation other than 
											 //           TCP_NETWORK_SYSTEM_NOT_AVAILABLE or
											 //           TCP_TOO_MANY_SOCKET_APPLICATIONS

#define TCP_ERR_OPEN            1            //cannot open port
									         //(in use/TCP_MAX_SOCOCKETS exceeded/...)
#define TCP_ERR_TIMEOUT			2			//block timeout occured
#define TCP_ERR_IO              3			//general io error
#define TCP_ERR_HANDLE          4			//invalid port handle


//maximum number of TCP sockets which may opened at the same time.
#define TCP_MAX_SOCKETS         32

#define TCP_DEFAULT_PORT 2939


	// Establish an TCP socket connection with the given destination.
// The turn_around_timeout is used as timeout to establish the socket connection AND
// as ADDITIONAL timeout for further "tcp_read" commands of this session.
// Possible result codes are 
//  * TCP_OK
//	* TCP_ERR_OPEN.
//  * TCP_NETWORK_SYSTEM_NOT_AVAILABLE
//  * TCP_TOO_MANY_SOCKET_APPLICATIONS
//  * TCP_INIT_ERROR
int tcp_open(int * handle, const char * addr, unsigned short port, int turn_around_timeout );

// registers an already connected socket to a TCP handle and sets the
// according parameters in the handle list.
// The socket is set to non-blocking mode
int tcp_bind_connected_socket(int * handle, SOCKET socket, int turn_around_timeout );

// Waits up to block_timeout milliseconds to receive a UDP packet. At most max_len bytes will be
// copied to the block response buffer. The actual length of the received frame is signaled by len.
int tcp_read(int handle, byte * block, int *len, int max_len, int block_timeout);


// Sends len characters from block as one TCP packet.
int tcp_write(int handle, byte *block, int len);


// Close connection
int tcp_close(int handle);

#if defined(__cplusplus)
}
#endif


#endif
 