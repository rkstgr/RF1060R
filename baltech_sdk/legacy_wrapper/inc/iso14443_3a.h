
#if ! defined(__BALTECH_DRIVER_ISO14443_3A_COMMANDS__)
#define __BALTECH_DRIVER_ISO14443_3A_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// the devcode for FTOB
#define ISO14443_3A_DEV_CODE		0x13

// define cmd_codes for the requests to the reader
#define ISO14443_3A_REQUEST						0x02
#define ISO14443_3A_SELECT						0x03
#define ISO14443_3A_HALT						0x04
#define ISO14443_3A_REQUEST_ATS					0x05
#define ISO14443_3A_PERFORM_PPS					0x06
#define ISO14443_3A_SET_TRANSPARENT_SETTING		0x21
#define ISO14443_3A_GET_TRANSPARENT_SETTING		0x22
#define ISO14443_3A_TRANSPARENT_CMD_14A			0x20

// define stati coming from the reader
#define ISO14443_3A_ERR_NOTAG				0x1301
#define ISO14443_3A_ERR_COLLISION			0x1302
#define ISO14443_3A_ERR_AUTH				0x1303
#define ISO14443_3A_ERR_HF					0x1304
#define ISO14443_3A_ERR_FRAMING				0x1307
#define ISO14443_3A_ERR_CRC					0x1308
#define ISO14443_3A_ERR_COM					0x1310
#define ISO14443_3A_ERR_EEPROM				0x1321
#define ISO14443_3A_ERR_CARD_NOT_SUPPORTED	0x1322

// special datatypes used due to the complexity of the iso command code

// Request *****************************************
// Answer to request of type A (used within request)
#define ISO14443_3A_REQ_ALL_TRUE	0x01
#define ISO14443_3A_REQ_ALL_FALSE	0x00

#define ISO14443_3A_UID_MASK	0xC0
#define ISO14443_3A_UID_4_BYTE	0x00
#define ISO14443_3A_UID_7_BYTE	0x01
#define ISO14443_3A_UID_10_BYTE	0x02

#define ISO14443_3A_COLL_MASK	0x1F
#define ISO14443_3A_NO_COLL		0x00
typedef struct {
	unsigned char UIDsize; // size of the unique identifier (4 byte - 10 byte)
	unsigned char Coll; // did a collision occure ( Coll != 0x00 )
} iso14443_3a_ATQA;

// Select ******************************************
// The request structure for the select command
#define ISO14443_3A_SERIAL_LEN		10

#define ISO14443_3A_CASCLEV_COMPLETE	0x00
#define ISO14443_3A_CASCLEV_0_TO_3		0x01
#define ISO14443_3A_CASCLEV_3_TO_6		0x02
#define ISO14443_3A_CASCLEV_6_TO_9		0x03
typedef struct {
	unsigned char CascLev; // cascading level of anticoll sequence
	unsigned char BitCount; // valid bits in PreSelString(count from beginnning)
	unsigned char PreSelSer[ISO14443_3A_SERIAL_LEN]; // Part of preselected UID
} iso14443_3a_Select_request;

#define ISO14443_3A_COMP_MASK	0x20
#define ISO14443_3A_CASC_MASK	0x04
// The SAK Select Acknowldge
typedef struct {
	bool Comp;
	bool Casc;
	unsigned char SerLen;
	unsigned char Serial[ISO14443_3A_SERIAL_LEN];
} iso14443_3a_SAK;

// RequestATS ***************************************
// RATSParam Request structure for request part of command
#define ISO14443_3A_FSDI_16_BYTE	0x00
#define ISO14443_3A_FSDI_24_BYTE	0x01
#define ISO14443_3A_FSDI_32_BYTE	0x02
#define ISO14443_3A_FSDI_40_BYTE	0x03
#define ISO14443_3A_FSDI_48_BYTE	0x04
#define ISO14443_3A_FSDI_64_BYTE	0x05
#define ISO14443_3A_FSDI_96_BYTE	0x06
#define ISO14443_3A_FSDI_128_BYTE	0x07
#define ISO14443_3A_FSDI_256_BYTE	0x08
#define ISO14443_3A_FSDI_DEFAULT_BYTE	ISO14443_3A_FSDI_64_BYTE

#define ISO14443_3A_CID_DISABLED	0x00
typedef struct {
	unsigned char FSDI; // Frame size used by reader (to send) reader
	unsigned char CID; // Channel ID for the selected PICC
} iso14443_3a_RATSParam;

#define ISO14443_3A_APP_INFO_MAX_LEN	27
// ATS Answer to selection
#define ISO14443_3A_FSCI_16_BYTE	0x00
#define ISO14443_3A_FSCI_24_BYTE	0x01
#define ISO14443_3A_FSCI_32_BYTE	0x02
#define ISO14443_3A_FSCI_40_BYTE	0x03
#define ISO14443_3A_FSCI_48_BYTE	0x04
#define ISO14443_3A_FSCI_64_BYTE	0x05
#define ISO14443_3A_FSCI_96_BYTE	0x06
#define ISO14443_3A_FSCI_128_BYTE	0x07
#define ISO14443_3A_FSCI_256_BYTE	0x08
#define ISO14443_3A_FSCI_DEFAULT_BYTE	ISO14443_3A_FSCI_64_BYTE

#define ISO14443_3A_TC_VALID_MASK	0x40
#define ISO14443_3A_TB_VALID_MASK	0x20
#define ISO14443_3A_TA_VALID_MASK	0x10

#define ISO14443_3A_FSCI_MASK		0x0F

#define ISO14443_3A_EQDSDR_MASK		0x80
#define ISO14443_3A_DS8_MASK		0x40
#define ISO14443_3A_DS4_MASK		0x20
#define ISO14443_3A_DS2_MASK		0x10
#define ISO14443_3A_DR8_MASK		0x04
#define ISO14443_3A_DR4_MASK		0x02
#define ISO14443_3A_DR2_MASK		0x01

#define ISO14443_3A_FWI_MASK		0xF0
#define ISO14443_3A_SFGI_MASK		0x0F

#define ISO14443_3A_CID_MASK		0x02
#define ISO14443_3A_NAD_MASK		0x01
typedef struct {
	unsigned char TL; // length of the AppInfo[+ T0][+ TA][+ TB][ + TC]

	bool T0_valid; // are T0_* values valid
	bool TC_valid; // are TC_* values valid
	bool TB_valid; // are TB_* values valid
	bool TA_valid; // are TA_* values valid

	unsigned char T0_FSCI; // Frame size used by card (send to reader)

	bool TA_EqDSDR;	// have DS and DR to be the same during one exchange
	bool TA_DS8; // if set card supports 848 kBit/s sending to reader
	bool TA_DS4; // if set card supports 424 kBit/s sending to reader
	bool TA_DS2; // if set card supports 212 kBit/s sending to reader
	bool TA_DR8; // if set card supports 848 kBit/s receiving from reader
	bool TA_DR4; // if set card supports 424 kBit/s receiving from reader
	bool TA_DR2; // if set card supports 212 kBit/s receiving from reader

	unsigned char TB_FWI; // Frame waiting time (256 * 16 / 13,56 MHz ) *2^FWI
							// range: 0x00 - 0x0E
	unsigned char TB_SFGI; // Start up guard time (see TB_FWI)

	bool TC_CID; // does the card support Channel IDs
	bool TC_NAD; // does the card node address

	unsigned char AppInfo[ISO14443_3A_APP_INFO_MAX_LEN]; // application info
} iso14443_3a_ATS;

// PerformPPS **********************************************
// the request data for the perform pps
#define ISO14443_3A_848_KBAUD		0x03
#define ISO14443_3A_424_KBAUD		0x02
#define ISO14443_3A_212_KBAUD		0x01
#define ISO14443_3A_DEFAULT_KBAUD	0x00
typedef struct {
	unsigned char CID; // the Channel ID the card should answer to
	unsigned char DSI; // the baudrate the card should send with
	unsigned char DRI; // the baudrate the card sgould receive with
} iso14443_3a_PPS_request;

// Transparent *********************************************
// The tag type
typedef struct {
	unsigned char TagID; // ID of an Tag
	unsigned char TagValue; // the value of the Tag
} iso14443_3a_tag;

// Transparent command
#define ISO14443_3A_ENPARTX		0x20
#define ISO14443_3A_ENBITMODE	0x10
#define ISO14443_3A_ENCRCRX		0x08
#define ISO14443_3A_ENCRCTX		0x04
#define ISO14443_3A_PARITYMODE	0x02
#define ISO14443_3A_ENPARITY	0x01

typedef struct {
	bool EnParTx; //should parity be generated when sending to card
	bool EnBitMode; // should bits used instead of bytes during anticollision
	bool EnCRCRX; // should the receiced data (from card) be CRC checked
	bool EnCRCTX; // should the data tailed by CRC
	bool ParityMode; // should parity be even (false) or odd (true)
	bool EnParity; // should parity be generated and checked

	short Len; // The length of data in byte (or bit if EnBitMode set)
	short Timeout; // The max time waiting for last byte from card

	bool DSI_DRI_valid; // should the Bitrate being used
	unsigned char DSI; // The baudrate to send from card to reader
	unsigned char DRI; // The baudrate to receive from reader

	unsigned char * Data; // The pointer to the data
} iso14443_3a_Transparent_request;

typedef struct {
	short Len; // the length of the data
	short CollPos; // The first bit where collision occured (only availible if
					// EnBitMode set
	short max_len; // this is needed not to produce an overflow
	unsigned char * Data; // The data that has been received
} iso14443_3a_Transparent_response;

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************

// ReqAll: select tags only in idle mode (false) or in halt mode, too (true)
int iso14443_3a_request( int Handle, bool ReqAll, iso14443_3a_ATQA * ATQA,
				int *Status );

int iso14443_3a_select( int Handle, iso14443_3a_Select_request * request,
				iso14443_3a_SAK * SAK, int *Status );

int iso14443_3a_halt( int Handle, int *Status );

int iso14443_3a_request_ats( int Handle, iso14443_3a_RATSParam * RATSParam,
				iso14443_3a_ATS * ATS, int *Status );

int iso14443_3a_perform_pps( int Handle, iso14443_3a_PPS_request * request,
				int *Status );

// only one tag can be set
int iso14443_3a_set_transparent_setting( int Handle, iso14443_3a_tag * tag,
				int *Status );

// only one tag can be set
int iso14443_3a_get_transparent_setting( int Handle, iso14443_3a_tag * tag,
				int *Status );

int iso14443_3a_transparent_cmd( int Handle, iso14443_3a_Transparent_request * request,
				iso14443_3a_Transparent_response * response, int *Status );

// this command initializes the stated structure with default values
void iso14443_3a_init_Select_request( iso14443_3a_Select_request * structure );

// this command initializes the stated structure with default values
void iso14443_3a_init_RATSParam( iso14443_3a_RATSParam * structure );

// this command initializes the stated structure with default values
void iso14443_3a_init_PPS_request( iso14443_3a_PPS_request * structure );

// this command initializes the stated structure with default values
void iso14443_3a_init_Transparent_request( iso14443_3a_Transparent_request * structure );

#if defined(__cplusplus)
}
#endif

#endif