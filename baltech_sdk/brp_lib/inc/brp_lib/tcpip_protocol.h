/**
 * @file
 * This is the adapter for network sockets to access to TCP/IP devices.
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */


#ifndef __TCP_CHANNEL_H__
#define __TCP_CHANNEL_H__


#include "protocol.h"


/**
 * @cond INTERNAL
 */

#if ! defined(BRP_NO_SOCKET_HEADERS)
	/**
	 * This are the includes for providing the socket API. They try to
	 * provide macros for hiding differences between windows and posix
	 * platforms.
	 *
	 * If the including C file did already include the corresponding files,
	 * it is recommended to define BRP_NO_SOCKET_HEADERS to avoid duplicate
	 * definitions.
	 */
	#if defined(_WIN32)
		#include <ws2tcpip.h>
		typedef int socklen_t;
		// this is only required for MingW < 10 (as definition is missing)
		// https://github.com/mirror/mingw-w64/commit/5fe3a72687f0629b68333fa438f4389db790651b
		#if defined(__GNUC__) && !defined(InetNtopA)
			PCSTR WSAAPI inet_ntop(INT Family, PVOID pAddr, PSTR pStringBuf,
					               size_t StringBufSize);
		#endif
	#else
		#include <unistd.h>
		#include <sys/socket.h>
		#include <netdb.h>
		#include <sys/ioctl.h>
		#include <arpa/inet.h>
		#define closesocket           close
		#define ioctlsocket           ioctl
		#define INVALID_SOCKET        (-1)
		#define SOCKET_ERROR          (-1)
		#define SD_BOTH               SHUT_RDWR
		#define NO_ERROR              0
		typedef int SOCKET;
	#endif
#endif

/**
 * @endcond
 */


/**
 * If a TCP/IP connection is created without specifying a portnr,
 * this default value is used as portnr.
 *
 * Must be changed only if source code of tcpip_protocol.c is recompiled.
 */
#if ! defined(BRP_DEFAULT_TCP_PORT)
	#define BRP_DEFAULT_TCP_PORT   2939
#endif


/**
 * This is the default time that will be assumed as worst case for a single
 * roundtrip.
 *
 * It will be added to every brp_recv_*() - timeout.
 * This is necessary as network connection may be slow and thus cause some
 * extra network specific (command independant) extra timeout.
 *
 * Furthermore brp_open() will stop if after this timeout no response was
 * received.
 *
 * This value can be varied via brp_set_tcpip_roundtrip_timeout().
 */
#define BRP_DEFAULT_TCPIP_ROUNDTRIP_TIMEOUT    1500


/**
 * Creates a TCP/IP protocol from an IP address.
 *
 * On opening this protocol, it will connect to the given IP address.
 *
 * @return a protocol, that can be used for sessions or NULL, if out of memory.
 */
BRP_LIB brp_protocol brp_create_tcpip
(
	char * ipaddr   ///< IP address to connect to. May have an optional port
	                ///  number 'ppp' if #BRP_DEFAULT_TCP_PORT is not
	                ///  appropriate: xx.xx.xx.xx:ppp
);


/**
 * Creates a TCP/IP protocol from an OS-level socket that was created
 * by the user of the BRP library.
 *
 * This is usually be used to implement server side BRP connections (where the
 * reader is the client and connects to this appplication).
 *
 * Attention: If a protocol is created this way, brp_get_tcpip_ipaddr() will
 * return NULL.
 *
 * @return a TCP/IP protocol, that can be used for sessions or NULL,
 * if out of memory.
 */
BRP_LIB brp_protocol brp_create_tcpip_by_socket
(
#if defined(_WIN32)
	SOCKET socket  ///< any socket handle that was created and opened by the
	               ///  Berkeley style socket interface.
#else
	int socket  ///< any file handle that represents a TCP connection
#endif
);


/**
 * Retrieves the ipaddr set in brp_create_tcpip().
 *
 * @return NULL, if *protocol* was not created via brp_create_tcpip
 */
BRP_LIB char * brp_get_tcpip_ipaddr
(
	brp_protocol protocol
);


/**
 * If the value of #BRP_DEFAULT_TCPIP_ROUNDTRIP_TIMEOUT is not appropriate it
 * can be finetuned for specific protocol instances via this function.
 */
BRP_LIB brp_errcode brp_set_tcpip_roundtrip_timeout
(
	brp_protocol protocol,    ///< protocol to modify roundtrip timeout
	brp_time timeout          ///< extra timeout in milliseconds.
);


/**
 * Retrieves the value of the roundtrip timeout set by the last
 * brp_set_tcpip_roundtrip_timeout().
 *
 * @return -1 if 'protocol' is invalid or not a TCP/IP protocol otherwise the
 * value roundtrip timeout.
 */
BRP_LIB brp_time brp_get_tcpip_roundtrip_timeout
(
	brp_protocol protocol     ///< protocol to get roundtrip timeout from
);


#endif

/** @} */ // end of defgroup brp_lib
