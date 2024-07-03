
#if ! defined(__BALTECH_DRIVER_VHL_COMANDS__)
#define __BALTECH_DRIVER_VHL_COMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// ****************************************
// the devcode for VHL
#define VHL_DEV_CODE		0x01

// define cmd_codes for the requests to the reader
#define VHL_SELECT			0x00
#define VHL_GET_SNR			0x01
#define VHL_READ			0x02
#define VHL_WRITE			0x03
#define VHL_IS_SELECTED		0x04
#define VHL_GET_ATR			0x05
#define VHL_EXCHANGE_APDU	0x06
#define VHL_SETUP			0x07
#define VHL_SETUP_MIFARE    0x08
#define VHL_SETUP_LEGIC		0x09

// define stati coming from the reader
#define VHL_ERR_NOTAG			0x0101
#define VHL_ERR_CARD_NOT_SELECTED	0x0102
#define VHL_ERR_HF			0x0103
#define VHL_ERR_CONFIG_ERR		0x0104
#define VHL_ERR_AUTH			0x0105
#define VHL_ERR_READ			0x0106
#define VHL_ERR_WRITE			0x0107
#define VHL_ERR_CONFCARD_READ		0x0108
#define VHL_ERR_INVALID_CARD_FAMILY	0x0109
#define VHL_ERR_NOT_SUPPORTED		0x010A


// define card families for select command
#define VHL_CF_NONE                      0x00
#define VHL_CF_ISO14443A                 0x10
#define VHL_CF_LEGIC                     0x20
#define VHL_CF_ISO15693                  0x30
#define VHL_CF_ISO14443B                 0x40


// define card types for select command
#define VHL_CT_NONE                      0x00

#define VHL_CT_ISO14443A                 0x10
#define VHL_CT_GEN_ISO14443A_NOLEV4      0x11 // generic, any serial number, no ISO14443-4 support
#define VHL_CT_GEN_ISO14443A_LEV4        0x12 // generic any serial number, ISO14443-4 support
#define VHL_CT_MIFARE_ULTRA              0x13 // mifare ultra, 7 bytes serial number, no ISO14443-4 support
#define VHL_CT_MIFARE_DES                0x14 // mifare DESFire, 7 bytes serial number, ISO14443-4 support
#define VHL_CT_INFINEON_SLE55            0x15 // Infineon SLE 55Rxx
#define VHL_CT_INFINEON_SLE66A           0x16 // Infineon SLE 66CLxxxP

#define VHL_CT_LEGIC                     0x20

#define VHL_CT_ISO15693			0x30

#define VHL_CT_GEN_ISO14443B_NOLEV4      0x40 // generic ISO14B without ISO14443-4 support (if exact type could not be detected)
#define VHL_CT_GEN_ISO14443B_LEV4        0x41 // generic ISO14B with ISO14443-4 support (if exact type could not be detected)
#define VHL_CT_INFINEON_SLE66B           0x42 // Infineon SLE 66CLxxxP

#define VHL_CT_PICOPASS			0x50

//this macro converts a cardtype into the corresponding bitmask
//#define VHL_CT2BITMASK(ct)               ((uint)1 << ((ct>>4) - 1))
#define VHL_ANYCTMASK                    0xFFFF
#define VHL_SUBTYPE(ct)                  (ct & 0x0F)
#define VHL_MAINTYPE(ct)                 (ct & 0xF0)

// error codes for VHL commands
#define VHL_OK                           0x00
#define VHL_NOTAGERR                     0x01 // card lost
#define VHL_CARD_NOT_SELECTED            0x02 // command impossible, because no card selected
#define VHL_HFERR                        0x03 // data may be corrupted, card lost
#define VHL_CONFIGERR                    0x04 // vhl file in configuration has invalid structure, card stays selected
#define VHL_AUTHERR                      0x05 // card stays selected
#define VHL_READERR                      0x06 // communication sequence ok, but reading failed, card stays selected
#define VHL_WRITEERR                     0x07 // communication sequence ok, but writing failed, card stays selected

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************
// vhl_select:
// Handle:			The handle that should be used for this request
// CardTypeMask:	for each cardtype you can enable a bit here. All Types
//					enabled will be included in the search for selectable cards.
// Reselect:		Should cards that have been selected once be reselected
//					while they are still in range.
// AllowConfig:		Set to true if Configcards should reconfigure the reader.
// CardType[1 Byte]:The answer of the reader. The cardtype of the card currently
//					selected. Can be NULL.
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_select( int Handle,
				word CardTypeMask, bool Reselect, bool AllowConfig,
				byte * CardType,
				int * Status );

// vhl_get_snr
// Handle:			The handle that should be used for this request
// Srn[16 Byte]:	The answer of the reader. The serial number of the currently
//					selected card. It can be up to 16 Bytes long
// Length[1 Byte]:	The length of the serial number
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_get_snr( int Handle,
				byte * Snr, byte * Length,
				int * Status );

// vhl_read
// Handle:			The handle that should be used for this request
// VHLFile:			The number of the VHL File that should be used for access
// Address:			The start address of the data that should be received
// Length:			The number of bytes that should be received starting at
//					address
// Data[? Byte]:	The data you requested will be written here. It can
//					as long as Length (max 65535 Byte), however it is up to you
//					how many bytes there will be received
// DataLen[2 Byte]: The number of bytes stored in Data
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_read( int Handle,
				byte VHLFile, word Address, word Length,
				byte * Data,
				int * Status );

// vhl_write
// Handle:			The handle that should be used for this request
// VHLFile:			The number of the VHL File that should be used for access
// Address:			The start address the data should be written to
// Length:			The number of bytes you want to write. Should be equal to
//					number of bytes in Data. ATTENTION: The length needs to be
//					less or equal to the send buffer size of the reader MINUS 5!
// Data:			The buffer that stores the data you want to transfere to the
//					reader
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_write( int Handle,
				byte VHLFile, word Address, word Length, byte * Data,
				int * Status );

// vhl_setup_mifare
// two important defines for this request:
// Handle:			The handle that should be used for this request
// Mode:			The mode according to the command set.
// Key:				The key you want to use. If not NULL mode will be set to
//					VHL_MIF_USE_MYKEY
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
#define VHL_MIF_USE_KEYB	0x01
#define VHL_MIF_USE_MYKEY	0x02
int vhl_setup_mifare( int Handle,
				byte Mode, byte * Key,
				int * Status );

// vhl_setup_legic
// Handle:			The handle that should be used for this request
// StampLen:		The len of the following stamp. If 0 the following byte
//					should be a segment id.
// Stamp[max 7 Byte]: The stamp with a number of bytes according to StampLen
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_setup_legic( int Handle,
				byte StampLen, byte * Stamp,
				int * Status );

// vhl_is_selected
// Handle:			The handle that should be used for this request
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_is_selected( int Handle,
				int * Status );

// vhl_get_atr
// Handle:			The handle that should be used for this request
// len:				The length of the atr
// atr:				The ATR itself
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
#define VHL_ATR_MAX_LEN		20
int vhl_get_atr( int Handle,
				byte * len,
                                unsigned char * atr,
				int * Status );

// vhl_exchange_apdu
// Handle:			The handle that should be used for this request
// card_type:			The cardtype. Is 0x00 if the automatically
//				detected should be used.
// buf_len			The number of bytes in buf
// buf				The data to be transmitted
// resp_len			The number of bytes in resp
// resp				The data coming from the card
// resp_max_len			The maximal number of bytes resp can hold.
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_exchange_apdu( int Handle,
				byte card_type,
                                word buf_len,
                                unsigned char * buf,
                                word * resp_len,
                                unsigned char * resp,
                                word resp_max_len,
				int * Status );

typedef struct {
	unsigned char key[6];
        bool as_key_a;
        bool use_mad_id;
        unsigned char mad_id[2];
} vhl_setup_mifare_classic;

typedef struct {
	unsigned char seg_len;
	unsigned char seg[7];
        bool en_stamp;
} vhl_setup_legic_prime;

typedef struct {
	unsigned char first_block;
        unsigned char block_count;
} vhl_setup_iso15693;

typedef struct {
 	int len;
        unsigned char * data_pointer;
} vhl_setup_raw;

void vhl_init_setup_mifare_classic( vhl_setup_mifare_classic * lv_struct );
void vhl_init_setup_legic_prime( vhl_setup_legic_prime * lv_struct );
void vhl_init_setup_iso15693( vhl_setup_iso15693 * lv_struct );
void vhl_init_setup_raw( vhl_setup_raw * lv_struct );

// vhl_setup
// Handle:			The handle that should be used for this request
// card_type:			The cardtype. Is 0x00 if the automatically
//				detected should be used.
// lv_struct:			One of the above declared LV structures
// Status[1 Byte]:  The status of the reader layer. Can be NULL.
int vhl_setup( int Handle,
		byte card_type,
                void * lv_struct,
		int * Status );

#if defined(__cplusplus)
}
#endif

#endif