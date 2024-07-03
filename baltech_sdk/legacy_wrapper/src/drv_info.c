#include "stdio.h"
#include <string.h>

#include "ftob.h"
#include "brp.h"
#include "iso14443_3a.h"
#include "iso14443_3b.h"
#include "iso14443_4.h"
#include "iso15693.h"
#include "mifcmds.h"
#include "syscmds.h"
#include "vhl.h"
#include "release.h"

void info_get_version( int *Major, int *Minor, int *Release)
{
	*Major = RELEASE_MAJOR_NR;
	*Minor = RELEASE_MINOR_NR;
	*Release = RELEASE_BUILD_NR;
}

char* info_get_error_desc( int Error, char* description ) {
	switch( Error ) {
		// error number				| Description text
		case BRP_OK: 					return( strcpy( description, "No error occured! Everthing worked out well!\0") );
		case BRP_ERR_STATUS:			return( strcpy( description, "Reader returned a status! Read out the status for further info!\0") );
		case BRP_ERR_IDLE:				return( strcpy( description, "The driver is waiting for a command!\0") );
		case BRP_ERR_BUSY:				return( strcpy( description, "The driver is processing a command!\0") );
		case BRP_ERR_TIMEOUT:			return( strcpy( description, "The reader did not respond within the given or standard timeout!\0") );
		case BRP_ERR_CORRUPTED_FRAME:	return( strcpy( description, "The reader returned some bytes but no BRP frame\0") );
		case BRP_ERR_UNEXPECTED_FRAME:	return( strcpy( description, "The reader returned a frame but nothing was expected\0") );
		case BRP_ERR_GENERAL_IO:		return( strcpy( description, "Something with the interface (Serial, USB) is wrong\0") );
		case BRP_ERR_BUFFER_OVERFLOW:	return( strcpy( description, "The buffer of the driver or the max length given along is too small!\0") );
		case BRP_ERR_NO_MORE_HANDLES:	return( strcpy( description, "There too many handles open!\0") );
		case BRP_ERR_INSUFFICIENT_MEM:	return( strcpy( description, "There is not enough host memory to create a new handle!\0") );
		case BRP_ERR_WRONG_HANDLE:		return( strcpy( description, "The specified handle has no connection!\0") );
		case BRP_ERR_WRONG_PARAMETERS:	return( strcpy( description, "The parameters of the last command were did not fit to it!\0") );
		default:					return( strcpy( description, "No description available! Read documentation!\0") );
	}
}

char* info_get_status_desc( int Status, char* description ) {
	unsigned char low_byte;
	switch( Status ) {
		case SYSCMD_ERR_CONF_FULL: 			return( strcpy( description, "No more memory available for configuration values!\0") );
		case SYSCMD_ERR_CONF_EEPROM: 		return( strcpy( description, "There occured an error reading or writing to the configuration EEPROM!\0") );
		case SYSCMD_ERR_CONF_NOTFOUND:		return( strcpy( description, "The configuration value specified was not found in the reader!\0") );
		case SYSCMD_ERR_INVALID_TLVSECTOR: 	return( strcpy( description, "The TLV sector is invalid!\0") );
		case SYSCMD_ERR_CONF_ACCESS_DENIED: return( strcpy( description, "The value requested cannot be read out!\0") );

		case MIFCMD_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case MIFCMD_ERR_CRC: 				return( strcpy( description, "The CRC checksum is not right!\0") );
		case MIFCMD_ERR_AUTH: 				return( strcpy( description, "Authentication of a block has failed!\0") );
		case MIFCMD_ERR_PARITY:				return( strcpy( description, "The parity is configured wrong!\0") );
		case MIFCMD_ERR_CODE: 				return( strcpy( description, "The command code is not known!\0") );
		case MIFCMD_ERR_SERNR: 				return( strcpy( description, "The serial number is wrong!\0") );
		case MIFCMD_ERR_KEY: 				return( strcpy( description, "Loading key in EEPROM failed!\0") );
		case MIFCMD_ERR_NOTAUTH:			return( strcpy( description, "An authentication did not take place before!\0") );
		case MIFCMD_ERR_BITCOUNT:			return( strcpy( description, "HF data transistion error! Bitcount not right!\0") );
		case MIFCMD_ERR_BYTECOUNT:			return( strcpy( description, "HF data transistion error! Bytecount not right!\0") );
		case MIFCMD_ERR_WRITE: 				return( strcpy( description, "Writing to card failed!\0") );
		case MIFCMD_ERR_INCR: 				return( strcpy( description, "Incrementing data on card failed!\0") );
		case MIFCMD_ERR_DECR: 				return( strcpy( description, "Decrementing data on card failed!\0") );
		case MIFCMD_ERR_READ: 				return( strcpy( description, "Reading from card failed!\0") );
		case MIFCMD_ERR_OVFL: 				return( strcpy( description, "Overflow occured during increment or decrement!\0") );
		case MIFCMD_ERR_FRAMING:			return( strcpy( description, "Transmitting a frame failed!\0") );
		case MIFCMD_ERR_UNKNOWNCMD: 		return( strcpy( description, "The command is not known!\0") );
		case MIFCMD_ERR_COLL: 				return( strcpy( description, "A collision occured during anticoll!\0") );
		case MIFCMD_ERR_RESET: 				return( strcpy( description, "RC500 register could not be accessed!\0") );
		case MIFCMD_ERR_INTERFACE: 		 	return( strcpy( description, "Error while accessing the bus to the interface!\0") );
		case MIFCMD_ERR_TIMEOUT:			return( strcpy( description, "A timeout in the mifare layer has been reached!\0") );
		case MIFCMD_ERR_NOTYIMPL: 			return( strcpy( description, "The command is not implemented yet!\0") );
		case MIFCMD_ERR_VAL: 				return( strcpy( description, "An increment or decrement didn't change the value!\0") );

		case FTOB_ERR_INVALID_FILENAME: 	return( strcpy( description, "There is no file of that name!\0") );
		case FTOB_ERR_ACCESS_DENIED: 		return( strcpy( description, "Error while trying to access the file!\0") );
		case FTOB_ERR_WRITE_BLOCK:			return( strcpy( description, "Writing data to file failed!\0") );
		case FTOB_ERR_READ_BLOCK: 			return( strcpy( description, "Reading data from file failed!\0") );
		case FTOB_ERR_NO_FILE_ACTIVE: 		return( strcpy( description, "There is no file opened!\0") );
		case FTOB_ERR_OUT_OF_MEMORY:		return( strcpy( description, "Reader has no more memory!\0") );

		case ISO14443_3A_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case ISO14443_3A_ERR_COLLISION: 			return( strcpy( description, "A collision occured during request!\0") );
		case ISO14443_3A_ERR_AUTH: 					return( strcpy( description, "Not authenticated for access!\0") );
		case ISO14443_3A_ERR_HF: 					return( strcpy( description, "Datatransfere over the HF failed!\0") );
		case ISO14443_3A_ERR_FRAMING: 				return( strcpy( description, "Transmission of frame failed!\0") );
		case ISO14443_3A_ERR_CRC: 					return( strcpy( description, "The CRC checksum was wrong!\0") );
		case ISO14443_3A_ERR_COM: 					return( strcpy( description, "Error while communicating to the reader chip!\0") );
		case ISO14443_3A_ERR_EEPROM: 				return( strcpy( description, "Error while accessing the reader chip EEPROM!\0") );
		case ISO14443_3A_ERR_CARD_NOT_SUPPORTED:	return( strcpy( description, "This card is not supported!\0") );

		case ISO14443_3B_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case ISO14443_3B_ERR_COLLISION: 			return( strcpy( description, "A collision occured during request!\0") );
		case ISO14443_3B_ERR_AUTH: 					return( strcpy( description, "Not authenticated for access!\0") );
		case ISO14443_3B_ERR_HF: 					return( strcpy( description, "Datatransfere over the HF failed!\0") );
		case ISO14443_3B_ERR_FRAME: 				return( strcpy( description, "Transmission of frame failed!\0") );
		case ISO14443_3B_ERR_CRC: 					return( strcpy( description, "The CRC checksum was wrong!\0") );
		case ISO14443_3B_ERR_COM: 					return( strcpy( description, "Error while communicating to the reader chip!\0") );
		case ISO14443_3B_ERR_CARD_NOT_SUPPORTED:	return( strcpy( description, "This card is not supported!\0") );
		case ISO14443_3B_ERR_MEM: 					return( strcpy( description, "Accessing the memory failed!\0") );

		case ISO14443_4_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case ISO14443_4_ERR_COLLISION: 			return( strcpy( description, "A collision occured during request!\0") );
		case ISO14443_4_ERR_HF: 				return( strcpy( description, "Datatransfere over the HF failed!\0") );
		case ISO14443_4_ERR_COM: 				return( strcpy( description, "Error while communicating to the reader chip!\0") );
		case ISO14443_4_ERR_CMD: 				return( strcpy( description, "Command not supported or parameters wrong!\0") );

		case ISO15693_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case ISO15693_ERR_COLLISION: 			return( strcpy( description, "A collision occured during request!\0") );
		case ISO15693_ERR_HF: 					return( strcpy( description, "Datatransfere over the HF failed!\0") );
		case ISO15693_ERR_COM: 					return( strcpy( description, "Error while communicating to the reader chip!\0") );
		case ISO15693_ERR_CMD: 					return( strcpy( description, "Command not supported or parameters wrong!\0") );
		case ISO15693_ERR_PARAM_NOT_SUPPORTED: 	return( strcpy( description, "Specified parameter value not supported!\0") );
		case ISO15693_ERR_MEM:	 				return( strcpy( description, "Accessing the memory failed!\0") );
                case ISO15693_ERR_LABEL_BLOCKSIZE:                      return( strcpy( description, "The blocks requested are not equal in size.\0") );

		case VHL_ERR_NOTAG: 				return( strcpy( description, "There has been detected no card!\0") );
		case VHL_ERR_CARD_NOT_SELECTED: 	return( strcpy( description, "There is no card selected!\0") );
		case VHL_ERR_HF: 					return( strcpy( description, "Datatransfere over the HF failed!\0") );
		case VHL_ERR_CONFIG_ERR: 			return( strcpy( description, "Using the configuration for last request failed!\0") );
		case VHL_ERR_AUTH: 					return( strcpy( description, "Authenticating the specified part of memory on label failed!\0") );
		case VHL_ERR_READ: 					return( strcpy( description, "Reading data from label failed!\0") );
		case VHL_ERR_WRITE: 				return( strcpy( description, "Writing data to label failed!\0") );
		case VHL_ERR_CONFCARD_READ: 		return( strcpy( description, "There has been detected a configuration card and read out!\0") );
		default:
			low_byte = (unsigned char) Status;
			switch( low_byte ) {
				case 0x40:					return( strcpy( description, "BRP Error: Reader is working! Please wait!\0") );
				case 0x41:					return( strcpy( description, "BRP Error: Unsufficient memory and/or unsupported parameter(s) or command!\0") );
				case 0x81:					return( strcpy( description, "BRP Error: Host exceeded character waiting time!\0") );
				case 0x82:					return( strcpy( description, "BRP Error: Invalid command frame received from host!!\0") );
				case 0x84:					return( strcpy( description, "BRP Error: The checksum did not match!\0") );
				default:					return( strcpy( description, "No description available! Read the documentation!\0") );
			}
	}
}


