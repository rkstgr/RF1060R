
#if ! defined(__BALTECH_DRIVER_ISO14443_4_COMMANDS__)
#define __BALTECH_DRIVER_ISO14443_4_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// the devcode for FTOB
#define ISO14443_4_DEV_CODE		0x16

// define cmd_codes for the requests to the reader
#define ISO14443_4_SETUP			0x00
#define ISO14443_4_EXCHANGE_APDU	0x01
#define ISO14443_4_DESELECT			0x02

// define stati coming from the reader
#define ISO14443_4_ERR_NOTAG		0x1601
#define ISO14443_4_ERR_COLLISION	0x1602
#define ISO14443_4_ERR_HF			0x1604
#define ISO14443_4_ERR_COM			0x1610
#define ISO14443_4_ERR_CMD			0x1623

// SetupAPDU **************************************

#define ISO14443_4_FSCI_16_BYTE	0x00
#define ISO14443_4_FSCI_24_BYTE	0x01
#define ISO14443_4_FSCI_32_BYTE	0x02
#define ISO14443_4_FSCI_40_BYTE	0x03
#define ISO14443_4_FSCI_48_BYTE	0x04
#define ISO14443_4_FSCI_64_BYTE	0x05
#define ISO14443_4_FSCI_96_BYTE	0x06
#define ISO14443_4_FSCI_128_BYTE	0x07
#define ISO14443_4_FSCI_256_BYTE	0x08
#define ISO14443_4_FSCI_DEFAULT_BYTE	ISO14443_4_FSCI_64_BYTE

#define ISO14443_4_848_KBAUD		0x03
#define ISO14443_4_424_KBAUD		0x02
#define ISO14443_4_212_KBAUD		0x01
#define ISO14443_4_DEFAULT_KBAUD	0x00

#define ISO14443_4_ENDEFAULT		0x08
#define ISO14443_4_USEB				0x04
#define ISO14443_4_ENNAD			0x02
#define ISO14443_4_ENCID			0x01

typedef struct {
	bool EnDefault; // FrameParam and Bitrate defaults will be used if true
	bool UseB; // should isoB (true) oder isoA (false) mode be used
	bool EnNAD; // should node address be used
	bool EnCID; // should channel id be used

	unsigned char CID; // value will be used if EnCID enabled
	unsigned char NAD; // value will be used if EnNAD enabled

	unsigned char FSCI; // Frame size used by card (send to reader)
	unsigned char FWI; // Frame waiting time (256 * 16 / 13,56 MHz ) *2^FWI
						// range: 0x00 - 0x0E

	unsigned char DSI; // the baudrate the card should send with
	unsigned char DRI; // the baudrate the card sgould receive with
} iso14443_4_SetupAPDU_request;

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************

int iso14443_4_setup_apdu( int Handle,
				iso14443_4_SetupAPDU_request * request, int *Status );

// param: data that should be transferred to the card
// param_len: The length of param
// resp: The buffer for the answer of card
// resp_len: The length of resp
// resp_max_len: The max number of bytes that can be transfered to resp.
int iso14443_4_exchange_apdu( int Handle, unsigned char * param,
				int param_len, unsigned char * resp, int *resp_len,
				int resp_max_len, int *Status );

int iso14443_4_deselect( int Handle, int *Status );

// this command initializes the stated structure with default values
void iso14443_4_init_SetupAPDU_request( iso14443_4_SetupAPDU_request * structure );

#if defined(__cplusplus)
}
#endif

#endif