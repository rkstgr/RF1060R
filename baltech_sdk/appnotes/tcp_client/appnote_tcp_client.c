/* This file demonstrates how to access a BALTECH reader via BRP protocol over
 * the TCP/IP interface.
 *
 * It's implemented as a single-threaded console application that opens a
 * connection to a BALTECH reader. As a command line argument, it expects
 * the reader's IP address.
 *
 * You can find out the IP address using BALTECH ID-engine Explorer
 * (download it from our website as part of BALTECH ToolSuite).
 *
 * 1. Connect the reader to your PC.
 * 2. Open BALTECH ID-engine Explorer.
 * 3. Wait for the reader to appear in the reader selection popup.
 * Here, you'll see the reader's IP address.
 *
 * Important:
 * This app note opens an unencrypted connection to the reader.
 * To add encryption, please use setup_new_crypto_session() as shown in the
 * app note "tcp_server". This is needed to run further commands, e.g.
 * VHL.Read or VHL.Write as shown in the app note "vhl".
 *
 * If you want to try out VHL commands without encryption, transfer the configuration
 * "00000-0000-1044-01_Ethernet_Demo.balcfg" to your reader.
 * This configuration disables all security features.
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
	char * ip_addr;
	char * fws;
	
	if (argc == 1)
	{
		fprintf(stderr, "Enter the reader's IP address as an argument.");
		exit(EXIT_FAILURE);
	}
	ip_addr = argv[1];
	
	brp_protocol dev = brp_create();
	errcode = brp_set_io(dev, brp_create_tcpip(ip_addr));
	exit_on_error(errcode, "Failed to create TCP/IP protocol.", dev);
	
	errcode = brp_open(dev);
	exit_on_error(errcode, "Failed to connect to TCP/IP reader.", dev);
	
	errcode = brp_Sys_GetInfo(dev, &fws, NULL);
	exit_on_error(errcode, "Failed to retrieve firmware string.", dev);
	printf("Unencrypted connection established.");
	printf("Firmware and serial number: %s\n", fws);
	
	brp_close(dev);  //Not necessary; done implicitly by the following command brp_destroy().
	brp_destroy(dev);
	return EXIT_SUCCESS;
}
