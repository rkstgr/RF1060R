/* This file demonstrates how to send a UDP introspection packet to a
 * network device connected to the reader's Device port (usually a PC).
 * The reader will read this packet and try to connect to the BRP server.
 *
 * For more details, see docs.baltech.de/udp-intro.html
 *
 * This app note expects the following:

 * - A BRP server is running somewhere in the network.
 *   For testing, you can use the app note "tcp_server".
 *
 * - 2 command line arguments:
 *   1. The IP address/DNS name of the PC (or other network device) connected
 *      to the reader's Device port
 *   2. The IP address/DNS name of the PC on which the BRP server is running.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdint.h>

#ifdef _WIN32
	/* Header files for Windows */
	#include <winsock.h>
	#include <io.h>
#else
	/* Header files for UNIX/Linux */
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#define SOCKET_ERROR -1
#endif

#ifndef _WIN32
	typedef int SOCKET;
	#define closesocket(sock)  close(sock)
#endif

/* TCP port of BRP server to connect */
#define BRPSERVER_PORT     2939

static void failure(char *errormessage)
{
	fprintf(stderr, "%s\n", errormessage);
	exit(EXIT_FAILURE);
}


static void init_ip_stack(void)
{
#ifdef _WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD (1, 1);
	if (WSAStartup (wVersionRequested, &wsaData) != 0)
		failure("Failed to initialize Winsock.");
	printf("Winsock has been initialized.\n");
#endif
}


static void ipaddr_str_to_bin(const char * ipaddr_str,
		void * ipaddr_bin, char *errmsg)
{
	struct hostent * host;
	host = gethostbyname(ipaddr_str);
	if(host == NULL)
		failure(errmsg);
	memcpy(ipaddr_bin, host->h_addr_list[0], 4);
}


int main(int argc, char *argv[])
{
	init_ip_stack();
	
	// Retrieved about the server
	SOCKET sock;
	char udp_introspec_msg[7];
	struct sockaddr_in addr;
	
	if (argc != 3)
		failure("Make sure to enter the following command line arguments:\n"
				" 1. The IP address/DNS name of the PC (or other network device) "
				"connected to the reader's Device port\n"
				" 2. The IP address/DNS name of the PC on which the BRP server "
				"is running");
	
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock == SOCKET_ERROR)
		failure("Failed to create socket.");
	
	// Retrieve
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2939);
	ipaddr_str_to_bin(argv[1], &addr.sin_addr,
			"Invalid IP address/DNS name of device connected to reader's Device port.");
	
	udp_introspec_msg[0] = 1;   // Format version of packet
	ipaddr_str_to_bin(argv[2], &udp_introspec_msg[1],
			"Invalid IP address/DNS Name of PC on which BRP server is running.");
	udp_introspec_msg[5] = (unsigned char) (BRPSERVER_PORT >> 8);
	udp_introspec_msg[6] = (unsigned char) (BRPSERVER_PORT);
	if (sendto(sock, udp_introspec_msg, sizeof(udp_introspec_msg), 0,
			(struct sockaddr *) &addr, sizeof(addr)) == SOCKET_ERROR)
		failure("Failed to send UDP packet.");
	
	closesocket(sock);
	
	printf("UDP paket has been sent.\n");
	return 0;
}
