/* This file demonstrates how to establish a secure channel to a baltech
 * reader.
 *
 * All communication done with the "dev" object is encrypted by a AES128
 * session key that will be renegotiated on every run. The underlying device
 * has to be a USB reader (see /appnote/usb_hod on trouble) which is has to
 * be configured with a matching key. In this case you have to load the
 * configuration
 */
 
 
#include <stdio.h>
#include <baltech_api.h>


// THESE parameters have to match the configuration of the reader.
// Please load the .bec file in this
#define KEY             { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, \
                          0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF }
#define SECURITY_LEVEL  1
#define SECURITY_MODE   BRP_SECMODE_STD


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


static void load_key(brp_sec_key key)
{
	static brp_sec_key hardcoded_key = KEY;
	memcpy(key, hardcoded_key, BRP_AES_KEY_SIZE);
}


static void wipe_key(brp_sec_key key)
{
	memset(key, 0, BRP_AES_KEY_SIZE);
}


int main(int argc, char *argv[])
{
	brp_errcode errcode;
	brp_sec_key key;
	char * fws;
	
	brp_protocol dev = brp_create();
	
	errcode = brp_set_io(dev, brp_create_usb_hid(0));
	exit_on_error(errcode, "failed to create encrypted protocol", dev);
	
	// WIPE KEY AFTER call to brp_create_secure_channel().
	// This important to avoid that key stays in RAM. In this case it is
	// meaningless, at the key is hardcoded and thus cannot be really deleted...
	load_key(key);
	errcode = brp_set_crypto(dev,
			brp_create_secure_channel(SECURITY_LEVEL, key, SECURITY_MODE));
	wipe_key(key);
	exit_on_error(errcode, "failed to create encrypted protocol", dev);
	
	errcode = brp_open(dev);
	exit_on_error(errcode, "failed to connect to USB/HID device", dev);
	
	errcode = brp_Sys_GetInfo(dev, &fws, NULL);
	exit_on_error(errcode, "failed to retrieve Firmwarestring", dev);
	printf("firmware: %s\n", fws);
	
	brp_close(dev);  //not necessary; done implicitly by following brp_destroy()
	brp_destroy(dev);
	return EXIT_SUCCESS;
}
