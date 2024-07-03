
#if ! defined(__MIFARE_COMMANDS__)
#define __MIFARE_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif


#include "compiler.h"
#include "oswrapper.h"
#include "brp.h"

// the device code for the system commands
#define MIFCMD_DEV_CODE		0x10

// the defines for the system commands
#define MIFCMD_E2_LOAD_KEY			0x00	// Write a set of keys to the reader's EEPROM.
#define MIFCMD_REQUEST				0x01	// Request cards in the field of the antenna.
#define MIFCMD_ANTICOLL				0x02	// Perform anticollision sequence.
#define MIFCMD_SELECT				0x03	// Select card for further communication.
#define MIFCMD_AUTH_E2				0x04	// Authenticate a certain sector using a key from the reader's EEPROM.
#define MIFCMD_AUTH_USER			0x05	// Authenticate a certain sector using a key directly specified as parameter.
#define MIFCMD_READ					0x06	// Read data from selected card.
#define MIFCMD_WRITE				0x07	// Write data to selected card.
#define MIFCMD_CHANGE_VALUE			0x08	// Perform increment or decrement  calculation on a certain values sector (standard mifare card)
#define MIFCMD_CHANGE_VALUE_BACKUP	0x09	// Perform increment or decrement calculation on a certain value sector (mifare pro/light card).
#define MIFCMD_TRANSFER_BLOCK		0x0A	// Make calculated increment/decrement operation persistent.
#define MIFCMD_HALT					0x0B	// Set selected card to halt state.

// the defines for all possible errors from a system command
#define MIFCMD_ERR_OK			0x1000	// Communication successful
#define MIFCMD_ERR_NOTAG		0x1001	// No card in field
#define MIFCMD_ERR_CRC			0x1002	// CRC checksum error
#define MIFCMD_ERR_AUTH   		0x1004	// The authentication of a card has failed
#define MIFCMD_ERR_PARITY		0x1005	// The parity is wrong configured
#define MIFCMD_ERR_CODE			0x1006	// The command code does not fit
#define MIFCMD_ERR_SERNR		0x1008	// The serial number was wrong
#define MIFCMD_ERR_KEY			0x1009	// Loading key in EEPROM of reader failed
#define MIFCMD_ERR_NOTAUTH		0x100a	// No authentication took place before
#define MIFCMD_ERR_BITCOUNT		0x100b	// HF data transition error. The received bits were not enough or to much
#define MIFCMD_ERR_BYTECOUNT	0x100c	// HF data transition error. The received bytes were not enough or to much
#define MIFCMD_ERR_WRITE		0x100f	// A write request could not be fulfilled
#define MIFCMD_ERR_INCR			0x1010	// A increment could not be fulfilled
#define MIFCMD_ERR_DECR			0x1011	// A decrement could not be fulfilled
#define MIFCMD_ERR_READ			0x1012	// A read could request could not be fulfilled
#define MIFCMD_ERR_OVFL			0x1014	// Within a decrement or increment a overflow occurred
#define MIFCMD_ERR_FRAMING		0x1015	// The frame has been deprecated cause of errors within
#define MIFCMD_ERR_UNKNOWNCMD	0x1017	// The specified command is unknown
#define MIFCMD_ERR_COLL			0x1018	// There occurred an error within the anticollision
#define MIFCMD_ERR_RESET		0x1019	// RC 500 cmd register could not been accessed
#define MIFCMD_ERR_INTERFACE	0x101a	// Error while accessing the bus to the interface
#define MIFCMD_ERR_TIMEOUT		0x101b	// The timeout has been reached
#define MIFCMD_ERR_NOTYIMPL		0x101d	// This functionality is not implemented right now
#define MIFCMD_ERR_VAL			0x101e	// An increment or decrement could not be changed

//request for cards
//Handle:			The handle that is used for communication
//Mode:				The mode of the request (either IDLE or ALL)
#define	MIFCMD_REQ_IDLE		0x00 // only attend to cards in idle state
#define MIFCMD_REQ_ALL		0x01 // attend to all cards
//ATRQ:				Please refer to the documentation of Mifare. Can be NULL
//Status:			The Status of the command. Can be NULL
int mifcmd_request( int Handle,
	byte Mode, word* ATRQ,
	int * Status );

//anticollision
//Handle:			The handle that is used for communication
//BitCount			The count of bits in the Serial that should be considered
//Serial:			The Serial number of the card after anticoll. BitCount
//					bits of this variable are considered for the Anticoll.
//Status:			The Status of the command. Can be NULL
int mifcmd_anticoll( int Handle,
	byte BitCount, dword* Serial,
	int * Status );

//select
//Handle:			The handle that is used for communication
//Serial:			The serial number of the card to be selected
//Size:				The size of the card. Can be NULL
//Status:			The Status of the command. Can be NULL
int mifcmd_select( int Handle,
	dword Serial, byte* Size,
	int * Status );

//Authentication via user provided key
//Handle:			The handle that is used for communication
//AuthMode:			The type of key that should be used
#define MIFCMD_KEY_A	0x60 // for key A
#define MIFCMD_KEY_B	0x61 // for key B
//Block: 			The number of the block that should be athenticated
//Key:				The key for authentication 6 bytes are required.
//Status:			The Status of the command. Can be NULL
int mifcmd_auth_user( int Handle,
	byte AuthMode, byte Block, byte* Key,
	int * Status );

//read
//Handle:			The handle that is used for communication
//Block:			The number of the block that is read out
//Content:			The data will be stored in content (16 bytes are required)
//Status:			The Status of the command. Can be NULL
int mifcmd_read( int Handle,
	byte Block, byte* Content,
	int * Status );

//write
//Handle:			The handle that is used for communication
//Block:			The number of the block that is read out
//Content:			The data will be stored in content (16 bytes are required)
//Status:			The Status of the command. Can be NULL
int mifcmd_write( int Handle,
	byte Block, byte* Content,
	int * Status );

#if defined(__cplusplus)
}
#endif

#endif

