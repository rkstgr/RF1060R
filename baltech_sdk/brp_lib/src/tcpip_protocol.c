#include "brp_lib/tcpip_protocol.h"
#include "brp_lib/composite_protocol.h"
#include "brp_lib/platform.h"

#include "stdio.h"


typedef struct tcpip_protocol_t
{
	struct brp_protocol_t p;
	char * ipaddr;
	SOCKET sock;
	brp_time roundtrip_timeout;
} * tcpip_protocol;


#if defined(__APPLE__)
	#define TVSEC_TYPE   int
#else
	#define TVSEC_TYPE   long
#endif


static SOCKET connect_addr(struct addrinfo *addr, brp_time timeout)
{
	struct timeval Timeout;
	unsigned long fionbio_mode;
	int err;
	SOCKET sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
	if (sock == INVALID_SOCKET)
		return INVALID_SOCKET;

	//set the socket to non-blocking
	fionbio_mode = 1;
	if (ioctlsocket(sock, FIONBIO, &fionbio_mode) != NO_ERROR)
	{
		closesocket(sock);
		return INVALID_SOCKET;
	}
	
	err = connect(sock, addr->ai_addr, (int) addr->ai_addrlen);
	if (err != NO_ERROR)
	{
		// check if the socket is ready
		fd_set Write, Err;
		FD_ZERO(&Write);
		FD_ZERO(&Err);
		FD_SET(sock, &Write);
		FD_SET(sock, &Err);
		Timeout.tv_sec = (TVSEC_TYPE) (timeout / 1000);
		Timeout.tv_usec = (TVSEC_TYPE) ((timeout % 1000) * 1000);
		select((int)(sock + 1), NULL, &Write, &Err, &Timeout);
		if (!FD_ISSET(sock, &Write))
		{
			closesocket(sock);
			return INVALID_SOCKET;
		}
	}
	
	//set the socket to blocking again
	fionbio_mode = 0;
	if (ioctlsocket(sock, FIONBIO, &fionbio_mode) != NO_ERROR)
	{
		closesocket(sock);
		return INVALID_SOCKET;
	}

	return sock;
}


static struct addrinfo * get_addrinfo_list(tcpip_protocol protocol)
{
	struct addrinfo *addrs = NULL, hints;
	char * colon_ptr;
	int sockerr;

	if (protocol->ipaddr == NULL)  //created by brp_create_tcpip_by_socket()?
		return BRP_OK;

	// search only for TCP/IP connections
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// find ':' character, which splits of the port address (i.e. "1.2.3.4:999")
	colon_ptr = protocol->ipaddr;
	while (*colon_ptr != ':'  &&  *colon_ptr != '\0')
		colon_ptr++;

	if (*colon_ptr == ':')
	{
		*colon_ptr = '\0';   // split strings temporary if portnr is attached
		sockerr = getaddrinfo(protocol->ipaddr, colon_ptr+1, &hints, &addrs);
		*colon_ptr = ':';
	}
	else
	{
		char def_port_str[10];
		sprintf(def_port_str, "%d", BRP_DEFAULT_TCP_PORT);
		sockerr = getaddrinfo(protocol->ipaddr, def_port_str, &hints, &addrs);
	}

	if (sockerr != NO_ERROR)
		return NULL;
	else
		return addrs;
}


static brp_errcode cb_open(tcpip_protocol protocol)
{
	struct addrinfo *addrs = NULL, *addr_iter;

	if (protocol->ipaddr == NULL)
		return BRP_OK;
	
	// Attempt to connect to addresses until one succeeds
	addrs = get_addrinfo_list(protocol);
	for(addr_iter = addrs; addr_iter != NULL; addr_iter = addr_iter->ai_next)
	{
		protocol->sock = connect_addr(addr_iter, protocol->roundtrip_timeout);
		if (protocol->sock != INVALID_SOCKET)
		{
			freeaddrinfo(addrs);
			return BRP_OK;
		}
	}
	if (addrs != NULL)
		freeaddrinfo(addrs);

	return BRP_ERR_OPEN_IO;
}


static brp_errcode cb_send_frame(tcpip_protocol protocol)
{
	brp_time start_timestamp = brp_get_time();
	int act_send_len = (int) send(
		protocol->sock,
		(char*) protocol->p.send_frame.ptr,
		(int) protocol->p.send_frame.act_size, 0);
	if (act_send_len == protocol->p.send_frame.act_size)
	{
		brp_time now = brp_get_time();
		protocol->p.recv_delay += (now - start_timestamp);
		return BRP_OK;
	}
	else
		return BRP_ERR_WRITE_IO;
}


static brp_errcode wait_frame(tcpip_protocol protocol, brp_time timeout)
{
	struct timeval select_timeout;

	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(protocol->sock, &fds);

	select_timeout.tv_sec = (TVSEC_TYPE) (timeout / 1000);
	select_timeout.tv_usec = (TVSEC_TYPE) ((timeout % 1000) * 1000);

	switch (select((int) (protocol->sock+1), &fds, NULL, NULL, &select_timeout))
	{
		case 1:
			return BRP_OK;
		case 0:
			return BRP_ERR_TIMEOUT;
		default:
			return BRP_ERR_WAIT_IO;
	}
}


static brp_errcode cb_recv_frame(
		tcpip_protocol protocol, brp_time timeout,
		brp_cb_fmt_spec_t fmt_spec, void *ctx)
{
	size_t request_len;
	brp_time now, start_timestamp = brp_get_time();
	brp_errcode errcode;
	errcode = wait_frame(protocol, timeout + protocol->roundtrip_timeout);
	if (errcode != BRP_OK)
		return errcode;

	while ((request_len = fmt_spec(&protocol->p.recv_frame, ctx)) > 0)
	{
		size_t act_len;
		brp_buf buf = brp_frame_write_buf(&protocol->p.recv_frame, request_len);
		if (buf == NULL)
			return BRP_ERR_OUT_OF_MEMORY;

		act_len = recv(protocol->sock, (char*) buf, (int) request_len, 0);
		if (act_len == SOCKET_ERROR)
			return BRP_ERR_READ_IO;
		else if (act_len < request_len)
		{
			protocol->p.recv_frame.act_size -= (request_len - act_len);
			return BRP_ERR_PAYLOAD_FORMAT;
		}
	}

	now = brp_get_time();
	protocol->p.recv_delay = min(now - start_timestamp, timeout);

	return BRP_OK;
}


static brp_errcode cb_get_id(tcpip_protocol protocol,
	char * * intf_name, brp_frame instance_id)
{
	char * inst_id_buf;
	struct sockaddr_in sockaddr;
	
	if (protocol->ipaddr == NULL)
	{
		socklen_t act_sockaddr_len = sizeof(sockaddr);
		if (getsockname(protocol->sock, (struct sockaddr*) &sockaddr,
				&act_sockaddr_len) != 0)
			return BRP_ERR_OPEN_IO;
		if (act_sockaddr_len != sizeof(sockaddr))
			return BRP_ERR_OPEN_IO;
	}
	else
	{
		struct addrinfo * addrs;
		addrs = get_addrinfo_list(protocol);
		if (addrs == NULL)
			return BRP_ERR_OPEN_IO;
		memcpy(&sockaddr, addrs->ai_addr, sizeof(sockaddr));
		freeaddrinfo(addrs);
	}
	
	brp_frame_write_start(instance_id);
	inst_id_buf = (char*) brp_frame_write_buf(instance_id, INET_ADDRSTRLEN);
	if (inst_id_buf == NULL)
		return BRP_ERR_OUT_OF_MEMORY;
	if (! inet_ntop(AF_INET, &sockaddr.sin_addr, inst_id_buf, INET_ADDRSTRLEN))
		return BRP_ERR_OPEN_IO;
	instance_id->act_size = strlen(inst_id_buf) + 1;
	*intf_name = "TCP/IP";
	return BRP_OK;
}


static brp_errcode cb_flush(tcpip_protocol protocol)
{
	unsigned char dummy_buffer[0x100];
	int recv_len;

	while (1)
	{
		brp_errcode errcode = wait_frame(protocol, 0);
		switch (errcode)
		{
			case BRP_OK:          break;
			case BRP_ERR_TIMEOUT: return BRP_OK;
			default:              return errcode;
		}

		recv_len = (int) recv(protocol->sock, (char*) dummy_buffer,
		                      sizeof(dummy_buffer), 0);
		if (recv_len == SOCKET_ERROR  ||  recv_len == 0)
			return BRP_ERR_READ_IO;
	}
}


static brp_errcode cb_close(tcpip_protocol protocol)
{
	if (protocol->ipaddr != NULL) //NOT created by brp_create_tcpip_by_socket()?
	{
		int err_sd = shutdown(protocol->sock, SD_BOTH);
		int err_cs = closesocket(protocol->sock);
		protocol->sock = INVALID_SOCKET;
		if (err_sd != NO_ERROR  ||  err_cs != NO_ERROR)
			return BRP_ERR_CLOSE_IO;
	}
	return BRP_OK;
}


static brp_errcode cb_destroy(tcpip_protocol protocol)
{
	if (protocol->ipaddr != NULL)
		free(protocol->ipaddr);
	brp_protocol_free(&protocol->p);
	return BRP_OK;
}


static tcpip_protocol create_protocol_struct(char * ipaddr, SOCKET sock)
{
	tcpip_protocol new_protocol =
		malloc(sizeof(struct tcpip_protocol_t));
	if (new_protocol == NULL)
		return NULL;

	memset(new_protocol, 0, sizeof(*new_protocol));

	brp_frame_init(&new_protocol->p.recv_frame);
	brp_frame_init(&new_protocol->p.send_frame);
	
	new_protocol->p.protocol_id = BRP_PROTID_TCPIP;
	new_protocol->p.cb_destroy = (brp_cb_generic_t) cb_destroy;
	new_protocol->p.cb_open = (brp_cb_generic_t) cb_open;
	new_protocol->p.cb_close = (brp_cb_generic_t) cb_close;
	new_protocol->p.cb_send_frame = (brp_cb_generic_t) cb_send_frame;
	new_protocol->p.cb_recv_frame = (brp_cb_recv_frame_t) cb_recv_frame;
	new_protocol->p.cb_get_id = (brp_cb_get_id_t) cb_get_id;
	new_protocol->p.cb_flush = (brp_cb_generic_t) cb_flush;
	new_protocol->sock = sock;
	new_protocol->ipaddr = NULL;
	new_protocol->roundtrip_timeout = BRP_DEFAULT_TCPIP_ROUNDTRIP_TIMEOUT;

	if (ipaddr != NULL)
	{
		int ipaddr_len = (int) (strlen(ipaddr) + 1);

		new_protocol->ipaddr = malloc(ipaddr_len);
		if (new_protocol->ipaddr == NULL)
		{
			free(new_protocol);
			return NULL;
		}

		memcpy(new_protocol->ipaddr, ipaddr, ipaddr_len);
	}

	return new_protocol;
}


brp_protocol brp_create_tcpip(char * ipaddr)
{
	tcpip_protocol new_protocol;
#if defined(_WIN32)
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
		return NULL;
#endif

	if (ipaddr == NULL)
		return NULL;

	new_protocol = create_protocol_struct(ipaddr, INVALID_SOCKET);
	if (new_protocol == NULL)
		return NULL;

	return (brp_protocol) new_protocol;
}


brp_protocol brp_create_tcpip_by_socket(SOCKET socket)
{
	if (socket == INVALID_SOCKET)
		return NULL;

	return (brp_protocol) create_protocol_struct(NULL, socket);
}


char * brp_get_tcpip_ipaddr(brp_protocol protocol)
{
	tcpip_protocol tcpip_prot = (tcpip_protocol) require_protocol(
		protocol, BRP_PROTID_TCPIP, BRP_LAYERID_IO);
	if (tcpip_prot == NULL)
		return NULL;
	else
		return tcpip_prot->ipaddr;
}


brp_errcode brp_set_tcpip_roundtrip_timeout(brp_protocol protocol,
                                            brp_time timeout)
{
	tcpip_protocol tcpip_prot = (tcpip_protocol) require_protocol(
		protocol, BRP_PROTID_TCPIP, BRP_LAYERID_IO);
	if (tcpip_prot == NULL)
		return BRP_ERR_INVALID_API_CALL;
	else
	{
		tcpip_prot->roundtrip_timeout = timeout;
		return BRP_OK;
	}
}


brp_time brp_get_tcpip_roundtrip_timeout(brp_protocol protocol)
{
	tcpip_protocol tcpip_prot = (tcpip_protocol) require_protocol(
		protocol, BRP_PROTID_TCPIP, BRP_LAYERID_IO);
	if (tcpip_prot == NULL)
		return BRP_INFINITE;
	else
		return tcpip_prot->roundtrip_timeout;
}
