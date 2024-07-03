/* This file demonstrates how to access a baltech reader via BRP protocol over
 * USB/HID interface.
 *
 * It is implemented as single threaded console application that opens any
 * connected baltech reader and gets the firmware string of the reader.
 *
 * ATTENTION: To make this sample working on linux, you need to install
 *            /appnotes/usb_hid/baltech_linux_usb_hid.rules
 *            (see the comments in this file)
 */
 
 
#include <stdio.h>
#include <baltech_api.h>


static void exit_on_error(brp_errcode errcode, char *errormessage,
						  brp_protocol dev)
{
	if (errcode != BRP_OK)
	{
		char * errname = brp_map_errcode(errcode);
		if (errname == NULL)
			fprintf(stderr, "%s [brp_errcode:%08X]\n", errormessage, errcode);
		else
			fprintf(stderr, "%s [%s]\n", errormessage, errname);
		brp_destroy(dev);
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char *argv[])
{
	brp_errcode errcode;
	char * fws;
	
	brp_protocol dev = brp_create();
	errcode = brp_set_io(dev, brp_create_usb_hid(0));
	exit_on_error(errcode, "failed to create USB/HID protocol", dev);
	
	errcode = brp_open(dev);
	exit_on_error(errcode, "failed to connect to USB/HID device", dev);
	
	errcode = brp_Sys_GetInfo(dev, &fws, NULL);
	exit_on_error(errcode, "failed to retrieve Firmwarestring", dev);
	printf("firmware: %s\n", fws);
	
	brp_close(dev);  //not necessary; done implicitly by following brp_destroy()
	brp_destroy(dev);
	return EXIT_SUCCESS;
}
