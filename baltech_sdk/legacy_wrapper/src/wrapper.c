#include "brp_lib.h"
#include "brp.h"
#include "stdio.h"


static brp_protocol handles[BRP_MAX_HANDLES] = { NULL };
static brp_errcode last_errcode[BRP_MAX_HANDLES];
static bool owned[BRP_MAX_HANDLES];


static int map_errcode(brp_errcode errcode)
{
	switch (errcode)
	{
		case BRP_OK:
			return BRP_OK;
		case BRP_ERR_OUT_OF_MEMORY:
			return BRP_ERR_INSUFFICIENT_MEM;
		case BRP_ERR_BUSY_:
			return BRP_ERR_BUSY;
		case BRP_ERR_UNEXPECTED_FRAME_:
			return BRP_ERR_UNEXPECTED_FRAME;
		case BRP_ERR_INVALID_API_CALL:
			return BRP_ERR_WRONG_PARAMETERS;
		case BRP_ERR_UNSUPPORTED_COMMAND:
		case BRP_ERR_COMMAND_DENIED:
			return BRP_ERR_STATUS;
		default:
			// map errcode by group
			if (errcode & BRP_ERRGRP_LIB_OS)
				return BRP_ERR_GENERAL_IO;
			else if (errcode & BRP_ERRGRP_COMM_TIMEOUT)
				return BRP_ERR_TIMEOUT;
			else if (errcode & BRP_ERRGRP_COMM_FRAMEFORMAT)
				return BRP_ERR_CORRUPTED_FRAME;
			else if (errcode & BRP_ERRGRP_COMM_ACCESSDENIED)
				return BRP_ERR_CRYPTO;
			else if (errcode & BRP_ERRGRP_DEVICE)
				return BRP_ERR_STATUS;
			else
				return BRP_ERR_GENERAL_IO;
	}
}


static brp_time map_timeout(int timeout)
{
	if (timeout == (int) OSWRAP_NO_TIMEOUT)
		return BRP_INFINITE;
	else
		return (brp_time) timeout;
}


static brp_protocol * search_free_handle(int *handle)
{
	for (*handle = 0; *handle < BRP_MAX_HANDLES; (*handle)++)
		if (handles[*handle] == NULL)
		{
			last_errcode[*handle] = BRP_OK;
			owned[*handle] = true;
			return handles + *handle;
		}
	*handle = -1;
	return NULL;
}


static brp_protocol map_handle(int handle)
{
	if (handle > BRP_MAX_HANDLES)
		return NULL;
	return handles[handle];
}


#if defined(_WIN32)
	static bool com_port_to_str(int com_port, char * com_port_str)
	{
		sprintf(com_port_str, "\\\\.\\COM%i", 1 + com_port);
		return true;
	}
#else
	static bool com_port_to_str(int com_port, char * com_port_str)
	{
		if (com_port >= 10000)
			sprintf(com_port_str, "/dev/ttyACM%i", com_port);
		else
			sprintf(com_port_str, "/dev/ttyS%i", com_port);
		return true;
	}
#endif


int brp_open_serial_session(
		int *handle, int com_port, ser_baudrate baudrate, ser_parity parity)
{
	brp_errcode errcode;
	char com_port_str[0x10];
	brp_protocol * dev;
	int baudrate_int;
	char parity_chr;

	if (! com_port_to_str(com_port, com_port_str))
		return BRP_ERR_WRONG_PARAMETERS;
	
	switch (baudrate)
	{
		case ser_baud_300: baudrate_int = 300; break;
		case ser_baud_600: baudrate_int = 600; break;
		case ser_baud_1200: baudrate_int = 1200; break;
		case ser_baud_2400: baudrate_int = 2400; break;
		case ser_baud_4800: baudrate_int = 4800; break;
		case ser_baud_9600: baudrate_int = 9600; break;
		case ser_baud_14400: baudrate_int = 14400; break;
		case ser_baud_19200: baudrate_int = 19200; break;
		case ser_baud_28800: baudrate_int = 28800; break;
		case ser_baud_38400: baudrate_int = 38400; break;
		case ser_baud_57600: baudrate_int = 57600; break;
		case ser_baud_115200: baudrate_int = 115200; break;
		case ser_baud_576000: baudrate_int = 576000; break;
		case ser_baud_921600: baudrate_int = 921600; break;
		case ser_baud_500000: baudrate_int = 500000; break;
		default: return BRP_ERR_WRONG_PARAMETERS;
	}
	
	switch (parity)
	{
		case ser_par_none: parity_chr = 'N'; break;
		case ser_par_odd: parity_chr = 'O'; break;
		case ser_par_even: parity_chr = 'E'; break;
		default: return BRP_ERR_WRONG_PARAMETERS;
	}
	
	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brp_create();
	if (*dev == NULL)
		return BRP_ERR_INSUFFICIENT_MEM;
	brp_set_io(*dev, brp_create_rs232(com_port_str, baudrate_int, parity_chr));
	errcode = brp_open(*dev);
	if (errcode != BRP_OK)
	{
		brp_destroy(*dev);
		*dev = NULL;
		return map_errcode(errcode);
	}
	
	return BRP_OK;
}


int brp_open_brplib_session(int *handle, brp_protocol brplib_protocol)
{
	brp_protocol *dev;
	
	if (brplib_protocol == NULL)
		return BRP_ERR_WRONG_PARAMETERS;
	
	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brplib_protocol;
	owned[*handle] = false;
	
	return BRP_OK;
}

int brp_open_usb_session( int *handle, dword productID )
{
	// not supported any more
	*handle = -1;
	return BRP_ERR_GENERAL_IO;
}


int brp_open_hid_session( int *handle, char * device_name )
{
	brp_errcode errcode;
	brp_protocol * dev;
	long long snr;

	if (device_name == NULL)
		snr = 0;
	else
	{
		char * device_name_end;
		snr = strtoll(device_name, &device_name_end, 10);
		if (device_name_end - device_name != strlen(device_name))
			return BRP_ERR_WRONG_PARAMETERS;
	}
	
	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brp_create();
	if (*dev == NULL)
		return BRP_ERR_INSUFFICIENT_MEM;
	brp_set_io(*dev, brp_create_usb_hid(snr));
	errcode = brp_open(*dev);
	if (errcode != BRP_OK)
	{
		brp_destroy(*dev);
		*dev = NULL;
		return map_errcode(errcode);
	}
	
	return BRP_OK;
}


int brp_open_pcsc_session( int *handle, char * reader_name )
{
	// not supported any more
	*handle = -1;
	return BRP_ERR_GENERAL_IO;
}


int brp_open_pcsc_handle_session( int *handle, long hSCardHandle)
{
	// not supported any more
	*handle = -1;
	return BRP_ERR_GENERAL_IO;
}


int brp_open_rs485_session( int *handle, int com_port, ser_baudrate baudrate,
		ser_parity parity, int device_address )
{
	// not supported any more
	*handle = -1;
	return BRP_ERR_GENERAL_IO;
}


int brp_open_tcp_session( int *handle, char * addr, unsigned short port ,
		int turn_around_timeout)
{
	brp_errcode errcode;
	brp_protocol * dev, tcp_prot;

	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brp_create();
	if (*dev == NULL)
		return BRP_ERR_INSUFFICIENT_MEM;
	tcp_prot = brp_create_tcpip(addr);
	brp_set_tcpip_roundtrip_timeout(tcp_prot, turn_around_timeout);
	brp_set_io(*dev, tcp_prot);
	errcode = brp_open(*dev);
	if (errcode != BRP_OK)
	{
		brp_destroy(*dev);
		*dev = NULL;
		return map_errcode(errcode);
	}
	
	return BRP_OK;
}


int brp_open_tcp_handle_session( int *handle ,SOCKET socket_handle,
		int turn_around_timeout)
{
	brp_errcode errcode;
	brp_protocol * dev, tcp_prot;

	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brp_create();
	if (*dev == NULL)
		return BRP_ERR_INSUFFICIENT_MEM;
	tcp_prot = brp_create_tcpip_by_socket(socket_handle);
	brp_set_tcpip_roundtrip_timeout(tcp_prot, turn_around_timeout);
	brp_set_io(*dev, tcp_prot);
	errcode = brp_open(*dev);
	if (errcode != BRP_OK)
	{
		brp_destroy(*dev);
		*dev = NULL;
		return map_errcode(errcode);
	}
	
	return BRP_OK;
}


int brp_open_crypto_session(int *handle, int base_handle,
		int auth_mode_and_sec_level, byte * key)
{
	brp_errcode errcode;
	brp_protocol * dev;
	int sec_level = auth_mode_and_sec_level & 0x0F;
	int sec_mode = 0;
	if (auth_mode_and_sec_level & BRP_AM_ENCRYPTED)
		sec_mode = BRP_SECMODE_STD;
	else
		sec_mode = BRP_SECMODE_PLAIN;
	if (! (auth_mode_and_sec_level & BRP_AM_SESSIONKEY)  &&
	    ! (auth_mode_and_sec_level & BRP_AM_CONTINUOUSIV) )
		sec_mode |= BRP_SECMODE_STATELESS;

	dev = search_free_handle(handle);
	if (dev == NULL)
		return BRP_ERR_NO_MORE_HANDLES;
	
	*dev = brp_create_composite();
	if (*dev == NULL)
		return BRP_ERR_INSUFFICIENT_MEM;
	brp_add_layer(*dev, BRP_LAYERID_IO);
	brp_add_layer(*dev, BRP_LAYERID_CRYPTO);
	brp_set_io(*dev, brp_get_brplib_protocol(base_handle));
	brp_set_crypto(*dev, brp_create_secure_channel(sec_level, key, sec_mode));
	errcode = brp_open(*dev);
	if (errcode != BRP_OK)
	{
		brp_destroy(*dev);
		*dev = NULL;
		return map_errcode(errcode);
	}
	
	return BRP_OK;
}


int brp_set_checksum(int handle, int checksum)
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	return BRP_OK;
}


int brp_set_alive_timeout(int handle, int alive_timeout)
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	return BRP_OK;
}


int brp_set_interbyte_timeout(int handle, int interbyte_timeout)
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	return BRP_OK;
}


int brp_set_bufsize(int handle, int total_bufsize, int send_bufsize,
		int recv_bufsize)
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	return BRP_OK;
}


int brp_get_bufsize( int handle, int *total_bufsize, int *send_bufsize,
		int *recv_bufsize)
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	*total_bufsize = BRP_DEFAULT_TOTAL_BUFSIZE;
	*send_bufsize = BRP_DEFAULT_SEND_BUFSIZE;
	*recv_bufsize = BRP_DEFAULT_RECV_BUFSIZE;
	return BRP_OK;
}


brp_protocol brp_get_brplib_protocol(int handle)
{
	return map_handle(handle);
}


//free the given session handle
int brp_close_session(int handle)
{
	brp_errcode errcode;
	brp_protocol dev = map_handle(handle);
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;
	if (owned[handle])
		errcode = brp_destroy(dev);
	else
		errcode = BRP_OK;
	handles[handle] = NULL;
	return map_errcode(errcode);
}


int brp_run_session( int handle, int usertimeout )
{
	brp_protocol dev = map_handle(handle);
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;
	last_errcode[handle] = brp_recv_any_frame(
			handles[handle],
			map_timeout(usertimeout));
	if (last_errcode[handle] == BRP_ERR_TIMEOUT_)
		return BRP_ERR_BUSY;
	else
		return map_errcode(last_errcode[handle]);
}


int brp_send_command(int handle, int mode,
	byte devcode, byte cmdcode, byte *param, int param_len, int timeout)
{
	int mapped_mode;
	brp_errcode errcode;
	brp_protocol dev = map_handle(handle);
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;
	switch (mode)
	{
		case BRP_MODE_CONTINUOUS: mapped_mode = BRP_MODE_CONTINUOUS_; break;
		case BRP_MODE_REPEAT:     mapped_mode = BRP_MODE_REPEAT_; break;
		default:                  mapped_mode = BRP_MODE_STD; break;
	}
	errcode = brp_send_cmd(
			dev,
			(devcode << 8) | cmdcode,
			param,
			param_len,
			map_timeout(timeout),
			mapped_mode);
	last_errcode[handle] = BRP_ERR_TIMEOUT_;
	return map_errcode(errcode);
}


int brp_extend_next_command_timeout( int handle, unsigned int ms_time )
{
	if (map_handle(handle) == NULL)
		return BRP_ERR_WRONG_HANDLE;
	else
		return BRP_ERR_WRONG_PARAMETERS;
}


static int finish_running_cmd(int handle)
{
	brp_protocol dev = map_handle(handle);
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;

	if (last_errcode[handle] == BRP_ERR_TIMEOUT_)
		last_errcode[handle] = brp_recv_any_frame(dev, BRP_INFINITE);
	
	if (last_errcode[handle] == BRP_ERR_INVALID_API_CALL)
		return BRP_ERR_BUSY;
	else
		return map_errcode(last_errcode[handle]);
}


int brp_get_response(int handle, byte * resp, int * resp_len, int max_resp_len )
{
	int err_val;
	brp_frame_reader frm_rdr;
	size_t resp_len_size_t;
	
	err_val = finish_running_cmd(handle);
	if (err_val != BRP_OK)
	{
		if (resp_len != NULL)
			*resp_len = 0;
		return err_val;
	}

	if ( resp == NULL )
		max_resp_len = 0;

	brp_frame_reader_start(&frm_rdr, &handles[handle]->recv_frame);
	brp_frame_read_var(&frm_rdr, resp, max_resp_len, &resp_len_size_t);
	if (brp_frame_read_err(&frm_rdr))
		return BRP_ERR_FRAMEFORMAT;
	if (! brp_frame_read_eof(&frm_rdr))
		return BRP_ERR_BUFFER_OVERFLOW;

	if (resp_len != NULL)
		*resp_len = (int) resp_len_size_t;
	return BRP_OK;
}


int brp_get_response_status(int handle, int * status )
{
	brp_protocol dev = map_handle(handle);
	int err_val;
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;
	err_val = map_errcode(last_errcode[handle]);
	if (status != NULL)
	{
		if (err_val != BRP_ERR_STATUS)
			*status = BRP_OK;
		else if (last_errcode[handle] == BRP_ERR_UNSUPPORTED_COMMAND)
			*status = 0x0041;
		else if (last_errcode[handle] == BRP_ERR_COMMAND_DENIED)
			*status = 0x0042;
		else
			*status = (int) (last_errcode[handle] & 0xFFFFu);
	}
	return err_val;
}


int brp_break_command(int handle)
{
	brp_protocol dev = map_handle(handle);
	if (dev == NULL)
		return BRP_ERR_WRONG_HANDLE;
	return map_errcode(brp_break_cmd(dev));
}


int brp_exec_command(int handle,
	byte devcode, byte cmdcode, byte *param, int param_len, int timeout,
	int * status, byte * resp, int * resp_len, int max_resp_len)
{
	int err_val;

	if (status != NULL)
		*status = 0;
	
	err_val = brp_send_command(handle, BRP_MODE_DEFAULT,
							   devcode, cmdcode, param, param_len, timeout);
	if (err_val != BRP_OK)
		return err_val;
	
	err_val = brp_run_session(handle, OSWRAP_NO_TIMEOUT);
	if (err_val == BRP_OK)
		brp_get_response(handle, resp, resp_len, max_resp_len);
	else if (resp_len != NULL)
		*resp_len = 0;
	return brp_get_response_status(handle, status);
}


const char * brp_get_driver_version(void)
{
	return brp_get_version();
}
