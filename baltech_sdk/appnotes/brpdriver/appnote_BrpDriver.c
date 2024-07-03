/* This file demonstrates how to the legacy_wrapper (BrpDriver.dll)
 */

#include "brp.h"
#include "syscmds.h"
#include "serial.h"
#include <stdio.h>


#define COM_PORT        2     //COM3 on windows, ttyS3 on Linux
#define KEY             { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, \
                          0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF }
#define SECURITY_LEVEL  1


bool get_info(int handle)
{
	int status;
	char data[41];
	int err_val = syscmd_get_info(handle, data, &status);
	if (err_val != BRP_OK)
	{
		printf("GetInfo Failed: %X (Status: %04X)\n", err_val, status);
		return false;
	}
	else
	{
		printf("Get Info Result: %s\n", data);
		return true;
	}
}


bool get_port(int handle)
{
	int status;
	word port_mask;
	int err_val = syscmd_get_port(handle, &port_mask, &status);
	if (err_val != BRP_OK)
	{
		printf("Failed to read ports: %X (Status: %04X)\n", err_val, status);
		return false;
	}
	else
	{
		printf("Port state: %04X\n", port_mask);
		return true;
	}
}


int main(int argc, char* argv[])
{
	byte crypto_key[] = KEY;
	int handle, crypto_handle;
	int err_val;

	printf("BrpDriver DLL Version: %s\n", brp_get_driver_version());
	
	// connect to reader
	err_val = brp_open_serial_session(
			&handle, COM_PORT, ser_baud_115200, ser_par_none);
	if (err_val != BRP_OK)
	{
		printf("Open Failed: %i\n", err_val);
		return -1;
	}
	else
		printf("Device opened!\n");

	if (! get_info(handle))
		return -1;
	
	// create secure channel and retrieve configvalue if possible
	err_val = brp_open_crypto_session(&crypto_handle, handle,
			BRP_AM_SESSIONKEY|BRP_AM_ENCRYPTED|SECURITY_LEVEL, crypto_key);
	if (err_val != BRP_OK)
		printf("Failed to open crypto session: %i\n", err_val);
	else
	{
		printf("Successfully created encrypted connection\n");
		if (! get_port(crypto_handle))
			return -1;
		brp_close_session(crypto_handle);
	}
	
	if (! get_info(handle))   // retry AFTER crypto session
		return -1;
	
	brp_close_session(handle);
	return -1;
}
