
#if ! defined(__BALTECH_DRIVER_ISO14443_3B_COMMANDS__)
#define __BALTECH_DRIVER_ISO14443_3B_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// the devcode for FTOB
#define ISO14443_3B_DEV_CODE		0x14

// define cmd_codes for the requests to the reader
#define ISO14443_3B_REQUEST						0x02
#define ISO14443_3B_ATTRIB						0x03
#define ISO14443_3B_HALT						0x04
#define ISO14443_3B_SET_TRANSPARENT_SETTING		0x21
#define ISO14443_3B_GET_TRANSPARENT_SETTING		0x22
#define ISO14443_3B_TRANSPARENT_CMD_14B			0x20

// define stati coming from the reader
#define ISO14443_3B_ERR_NOTAG				0x1401
#define ISO14443_3B_ERR_COLLISION			0x1402
#define ISO14443_3B_ERR_AUTH				0x1403
#define ISO14443_3B_ERR_HF					0x1404
#define ISO14443_3B_ERR_FRAME				0x1407
#define ISO14443_3B_ERR_CRC					0x1408
#define ISO14443_3B_ERR_COM					0x1410
#define ISO14443_3B_ERR_CARD_NOT_SUPPORTED	0x1422
#define ISO14443_3B_ERR_MEM					0x1423

// Request ******************************************
#define ISO14443_3B_TIMESLOTS_1		0x00
#define ISO14443_3B_TIMESLOTS_2		0x01
#define ISO14443_3B_TIMESLOTS_4		0x02
#define ISO14443_3B_TIMESLOTS_8		0x03
#define ISO14443_3B_TIMESLOTS_16	0x04

#define ISO14443_3B_REQALL			0x08
typedef struct {
	bool ReqAll; // request only cards in idle state (false) or halt state, too
	unsigned char TimeSlots; // The timeslots used within the request
	unsigned char AFI; // The application family ID the card should have
} iso14443_3b_Request_request;

#define ISO14443_3B_FSCI_16_BYTE	0x00
#define ISO14443_3B_FSCI_24_BYTE	0x01
#define ISO14443_3B_FSCI_32_BYTE	0x02
#define ISO14443_3B_FSCI_40_BYTE	0x03
#define ISO14443_3B_FSCI_48_BYTE	0x04
#define ISO14443_3B_FSCI_64_BYTE	0x05
#define ISO14443_3B_FSCI_96_BYTE	0x06
#define ISO14443_3B_FSCI_128_BYTE	0x07
#define ISO14443_3B_FSCI_256_BYTE	0x08
#define ISO14443_3B_FSCI_DEFAULT_BYTE	ISO14443_3B_FSCI_64_BYTE

#define ISO14443_3B_PROT_TYPE_NO_ISO_4	0x00
#define ISO14443_3B_PROT_TYPE_ISO_4		0x01

#define ISO14443_3B_PROT_TYPE_MASK	0x0F

#define ISO14443_3B_FSCI_MASK		0xF0

#define ISO14443_3B_EQDSDR_MASK		0x80
#define ISO14443_3B_DS8_MASK		0x40
#define ISO14443_3B_DS4_MASK		0x20
#define ISO14443_3B_DS2_MASK		0x10
#define ISO14443_3B_DR8_MASK		0x04
#define ISO14443_3B_DR4_MASK		0x02
#define ISO14443_3B_DR2_MASK		0x01

#define ISO14443_3B_FWI_MASK		0xF0

#define ISO14443_3B_CID_MASK		0x01
#define ISO14443_3B_NAD_MASK		0x02
typedef struct {
	unsigned char PUPI[4]; // Pseudo unique picc identifier
	unsigned char AppData[4]; // The applications on this card

	bool EqDSDR;	// have DS and DR to be the same during one exchange
	bool DS8; // if set card supports 848 kBit/s sending to reader
	bool DS4; // if set card supports 424 kBit/s sending to reader
	bool DS2; // if set card supports 212 kBit/s sending to reader
	bool DR8; // if set card supports 848 kBit/s receiving from reader
	bool DR4; // if set card supports 424 kBit/s receiving from reader
	bool DR2; // if set card supports 212 kBit/s receiving from reader

	unsigned char FSCI; // Frame size used by card

	unsigned char ProtType; // Protocoll type of tag

	unsigned char FWI; // Frame waiting time (256 * 16 / 13,56MHz * 2^FWI)

	bool CID; // Does the card support channel ids

	bool NAD; // does the card support node adresses
} iso14443_3b_Request_response;

#define ISO14443_3B_TR0_DELAY_64		0x00
#define ISO14443_3B_TR0_DELAY_48		0x01
#define ISO14443_3B_TR0_DELAY_16		0x02
#define ISO14443_3B_TR0_DELAY_DEFAULT	ISO14443_3B_TR0_DELAY_64

#define ISO14443_3B_TR1_DELAY_80		0x00
#define ISO14443_3B_TR1_DELAY_64		0x01
#define ISO14443_3B_TR1_DELAY_16		0x02
#define ISO14443_3B_TR1_DELAY_DEFAULT	ISO14443_3B_TR1_DELAY_80

#define ISO14443_3B_848_KBAUD		0x03
#define ISO14443_3B_424_KBAUD		0x02
#define ISO14443_3B_212_KBAUD		0x01
#define ISO14443_3B_DEFAULT_KBAUD	0x00

#define ISO14443_3B_FSDI_16_BYTE	0x00
#define ISO14443_3B_FSDI_24_BYTE	0x01
#define ISO14443_3B_FSDI_32_BYTE	0x02
#define ISO14443_3B_FSDI_40_BYTE	0x03
#define ISO14443_3B_FSDI_48_BYTE	0x04
#define ISO14443_3B_FSDI_64_BYTE	0x05
#define ISO14443_3B_FSDI_96_BYTE	0x06
#define ISO14443_3B_FSDI_128_BYTE	0x07
#define ISO14443_3B_FSDI_256_BYTE	0x08
#define ISO14443_3B_FSDI_DEFAULT_BYTE	ISO14443_3B_FSDI_64_BYTE

#define ISO14443_3B_CID_DISABLED	0x00

#define ISO14443_3B_EOF				0x08
#define ISO14443_3B_SOF				0x04

#define ISO14443_3B_ATTRIB_RFU		0x01

#define ISO14443_3B_MODE_HLR		0x04
#define ISO14443_3B_MODE_MBLI		0x02
#define ISO14443_3B_MODE_CID		0x01
typedef struct {
	unsigned char PUPI[4]; // The pseudo unique picc number
	unsigned char TR0; // minimum delay before responding
	unsigned char TR1; // minimum delay between modulation and start of transfer

	bool _EOF; // reader requires end of frame break (false) or optional (true)
	bool _SOF; // reader requires start of frame break (false) or optional (true)

	unsigned char DSI; // the baudrate the card should send with
	unsigned char DRI; // the baudrate the card sgould receive with

	unsigned char FSDI; // Frame size used by reader (to send) reader

	unsigned char CID; // Channel ID for the selected PICC

	bool EnHLR; // should there be a high layer response
	bool EnMBLI; // should there be maximum buffer length information
	bool EnCID; // should there be a CID in the response
} iso14443_3b_Attrib_request;

#define ISO14443_3B_HLR_MAX_LEN	256
typedef struct {
	unsigned char CID; // the CID of the tag

	unsigned char MBLI; // the max buffer length of the PICC

	unsigned char Length; // the length of the high level layer data

	unsigned char * HLR; // the pointer to the buiffer of response.
} iso14443_3b_Attrib_response;

// Transparent *********************************************
// The tag type
typedef struct {
	unsigned char TagID; // ID of an Tag
	unsigned char TagValue; // the value of the Tag
} iso14443_3b_tag;

#define ISO14443_3B_ENCRCRX		0x02
#define ISO14443_3B_ENCRCTX		0x01

// Transparent command
typedef struct {
	bool EnCRCRX; // should the receiced data (from card) be CRC checked
	bool EnCRCTX; // should the data tailed by CRC

	short Len; // The length of data in byte (or bit if EnBitMode set)
	short Timeout; // The max time waiting for last byte from card

	bool DSI_DRI_valid; // should the Bitrate being used
	unsigned char DSI; // The baudrate to send from card to reader
	unsigned char DRI; // The baudrate to receive from reader

	unsigned char * Data; // The pointer to the data
} iso14443_3b_Transparent_request;

typedef struct {
	short Len; // the length of the data
	short CollPos; // The first bit where collision occured (only availible if
					// EnBitMode set
	short max_len; // this is needed not to produce an overflow
	unsigned char * Data; // The data that has been received
} iso14443_3b_Transparent_response;

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************

int iso14443_3b_request( int Handle, iso14443_3b_Request_request * request,
				iso14443_3b_Request_response * response, int *response_count,
				int response_max_count, int *Status );

// in iso14443_3b_attrib the response can be NULL
int iso14443_3b_attrib( int Handle, iso14443_3b_Attrib_request * request,
				iso14443_3b_Attrib_response * response, int * Status );

int iso14443_3b_halt( int Handle, unsigned char * PUPI, int *Status );

// only one tag can be set
int iso14443_3b_set_transparent_setting( int Handle, iso14443_3b_tag * tag,
				int * Status );

// only one tag can be set
int iso14443_3b_get_transparent_setting( int Handle, iso14443_3b_tag * tag,
				int * Status );

int iso14443_3b_transparent_cmd( int Handle, iso14443_3b_Transparent_request * request,
				iso14443_3b_Transparent_response * response, int * Status );

// this command initializes the stated structure with default values
void iso14443_3b_init_Request_request( iso14443_3b_Request_request * structure );

// this command initializes the stated structure with default values
void iso14443_3b_init_Attrib_request( iso14443_3b_Attrib_request * structure );

// this command initializes the stated structure with default values
void iso14443_3b_init_Transparent_request( iso14443_3b_Transparent_request * structure );

#if defined(__cplusplus)
}
#endif

#endif