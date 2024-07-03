
#if ! defined(__BALTECH_DRIVER_ISO15693_COMMANDS__)
#define __BALTECH_DRIVER_ISO15693_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif

#include "compiler.h"
#include "brp.h"

// the devcode for FTOB
#define ISO15693_DEV_CODE			0x20

// define cmd_codes for the requests to the reader
#define ISO15693_SET_PARAM				0x00
#define ISO15693_GET_PARAM				0x01
#define ISO15693_GET_UID_LIST			0x02
#define ISO15693_SET_MODE				0x03
#define ISO15693_STAY_QUIET				0x04
#define ISO15693_READ_BLOCK				0x05
#define ISO15693_WRITE_BLOCK			0x06
#define ISO15693_LOCK_BLOCK				0x07
#define ISO15693_RESET_TO_READY			0x08
#define ISO15693_WRITE_AFI				0x09
#define ISO15693_LOCK_AFI				0x0A
#define ISO15693_WRITE_DSFID			0x0B
#define ISO15693_LOCK_DSFID				0x0C
#define ISO15693_GET_SYSTEM_INFO		0x0D
#define ISO15693_GET_SECURITY_STATUS	0x0E
#define ISO15693_CUSTOM_CMD				0x0F
#define ISO15693_TRANSPARENT_CMD		0x20

#define ISO15693_MYD_AUTHENTICATE		0x28
#define ISO15693_MYD_READ				0x29
#define ISO15693_MYD_WRITE				0x2A

// define stati coming from the reader
#define ISO15693_ERR_NOTAG					0x2001
#define ISO15693_ERR_COLLISION				0x2002
#define ISO15693_ERR_HF						0x2004
#define ISO15693_ERR_KEY_MEM				0x2008
#define ISO15693_ERR_AUTH					0x2009
#define ISO15693_ERR_REREAD					0x200A
#define ISO15693_ERR_VALUE					0x200B
#define ISO15693_ERR_MYDCRYPT_NOT_INSTALLED			0x200C
#define ISO15693_ERR_COM					0x2010
#define ISO15693_ERR_CMD					0x2020
#define ISO15693_ERR_PARAM_NOT_SUPPORTED	0x2023
#define ISO15693_ERR_MEM					0x2024
#define ISO15693_ERR_LABEL_BLOCKSIZE		0x2025

// define the stati coming from the labels
#define ISO15693_LBL_ERR_OK				0x00
#define ISO15693_LBL_ERR_CMD_NOT_SUPPORTED		0x01
#define ISO15693_LBL_ERR_CMD_INVALID_FORMAT		0x02
#define ISO15693_LBL_ERR_CMD_INVALID_OPTION		0x03
#define ISO15693_LBL_ERR_UNSPECIFIED			0x0F
#define ISO15693_LBL_ERR_BLK_DOESNOT_EXIST		0x10
#define ISO15693_LBL_ERR_BLK_ALREADY_LOCKED		0x11
#define ISO15693_LBL_ERR_BLK_WRITE_LOCKED_BLK		0x12
#define ISO15693_LBL_ERR_BLK_WRITE_ERR			0x13
#define ISO15693_LBL_ERR_BLK_LOCK_ERR			0x14

// ****************************************
// all these function are using the brp_exec_command
// all function return an integer. Please reffer to the brp.h to
// determine the different answers possible.
// ****************************************

typedef struct {
	bool TenthModIndex;
	bool TxMode1of4;
	bool HighDataRate;
	bool DualSubcarrier;
} iso15693_SetParam_request;

#define ISO15693_PARAM_TENTH_MOD_INDEX	0x08
#define ISO15693_PARAM_TX_MODE_1_OF_4	0x04
#define ISO15693_PARAM_HIGH_DATA_RATE	0x02
#define ISO15693_PARAM_DUAL_SUBCARRIER	0x01

void iso15693_init_SetParam_request( iso15693_SetParam_request * structure );

int iso15693_set_param( int Handle, iso15693_SetParam_request * request,
				int *Status );

typedef iso15693_SetParam_request iso15693_GetParam_response;

int iso15693_get_param( int Handle, iso15693_GetParam_response * response,
				int *Status );

typedef struct {
	bool EnAFI;
	bool NextBlock;
	bool AutoQuiet;
	bool DSFID;
	bool Slot16;

	unsigned char AFI;
} iso15693_GetUIDList_request;

void iso15693_init_GetUIDList_request( iso15693_GetUIDList_request * structure );

#define ISO15693_UID_SIZE	8

#define ISO15693_GETUID_EN_AFI		0x10
#define ISO15693_GETUID_NEXT_BLOCK  0x08
#define ISO15693_GETUID_AUTO_QUIET	0x04
#define ISO15693_GETUID_DSFID		0x02
#define ISO15693_GETUID_16SLOTS		0x01

typedef struct {
	unsigned char UID[ISO15693_UID_SIZE];
	unsigned char DSFID;
} iso15693_UID;

int iso15693_get_uid_list( int Handle, iso15693_GetUIDList_request * request,
				bool * more, int * count, iso15693_UID * labels, unsigned int max_count,
				int *Status );

#define ISO15693_MODE_UNADDRESSED	0x00
#define ISO15693_MODE_ADDRESSED		0x01
#define ISO15693_MODE_SELECTED		0x02

int iso15693_set_mode( int Handle, byte mode, unsigned char *UID,
				int *Status );

int iso15693_stay_quiet( int Handle,
				int *Status );

int iso15693_read_block( int Handle, byte block_id, byte block_num, bool en_block_sec,
			byte * label_stat, byte * block_len, byte data[], byte block_sec_stat[],
			byte max_block_len, int *Status );

int iso15693_write_block( int Handle, byte block_id, byte block_num,
			byte block_len, byte data[],
			byte * label_stat, int *Status );

int iso15693_lock_block( int Handle, byte block_id,
				byte * label_stat, int *Status );

int iso15693_reset_to_ready( int Handle,
				byte * label_stat, int *Status );

int iso15693_write_afi( int Handle, byte afi,
				byte * label_stat, int *Status );

int iso15693_lock_afi( int Handle,
				byte * label_stat, int *Status );

int iso15693_write_dsfid( int Handle, byte dsfid,
				byte * label_stat, int *Status );

int iso15693_lock_dsfid( int Handle,
				byte * label_stat, int *Status );

typedef struct {
	bool EnICRef;
	bool EnMemSize;
	bool EnAFI;
	bool EnDSFID;

	unsigned char SNR[8];
	byte DSFID;
	byte AFI;
	byte BlockSize;
	byte BlockNum;
	byte ICRef;
} iso15693_SystemInformation;

#define ISO15693_INFO_ICREF		0x08
#define ISO15693_INFO_MEM_SIZE	0x04
#define ISO15693_INFO_AFI		0x02
#define ISO15693_INFO_DSFID		0x01

int iso15693_get_system_information( int Handle, iso15693_SystemInformation * info,
				byte * label_stat, int *Status );

int iso15693_get_security_status( int Handle, byte block_id, byte block_num,
				byte * block_stat,
				byte * label_stat, int *Status );

typedef struct {
	byte Cmd;
	bool Opt;
	byte MFC;
	byte TO;
} iso15693_CustomCmd_settings;

int iso15693_custom_command( int Handle, iso15693_CustomCmd_settings *settings,
				int len, byte  * data, int * resp_len, byte * resp, int max_resp_len,
				byte * label_stat, int *Status );

void iso15693_init_CustomCmd_settings( iso15693_CustomCmd_settings * structure );

typedef struct {
	bool EnRxWait;
	bool EnCRCRX;
	bool EnCRCTX;
	int Timeout;
} iso15693_TransparentCmd_settings;

#define ISO15693_CRCTX		0x04
#define ISO15693_CRCRX		0x08
#define ISO15693_ENRXWAIT	0x10

int iso15693_transparent_cmd( int Handle, iso15693_TransparentCmd_settings* settings,
				int len, byte * data, int * resp_len, byte* resp, int max_resp_len,
				byte * label_stat, int *Status );

void iso15693_init_TransparentCmd_settings( iso15693_TransparentCmd_settings * structure );

typedef struct {
	unsigned char KeyAddress;

	bool EnDivKey;
        unsigned char DivKey[8];

	bool EnKey;
	unsigned char ValueID;
	unsigned char Key[16];

	bool EnDivData;
	unsigned char DivData[8];
} iso15693_MydAuthenticate_settings;

#define ISO15693_ENDIV		0x01
#define ISO15693_ENKEY		0x02
#define ISO15693_ENDATA		0x04

int iso15693_myd_authenticate( int Handle, iso15693_MydAuthenticate_settings* settings,
				byte * label_stat, int *Status );

void iso15693_init_MydAuthenticate_settings( iso15693_MydAuthenticate_settings* structure );

#define ISO15693_MYD_PAGE_MAX_LEN	10

#define ISO15693_ENSECURE		0x01
#define ISO15693_ENRESTRICTED	0x02

typedef struct {
	bool EnSecure;
	bool EnRestricted;
	int PageAddress;
} iso15693_MydRead_settings;

int iso15693_myd_read( int Handle, iso15693_MydRead_settings* settings,
				int * len, unsigned char * data, byte * label_stat, int *Status );

void iso15693_init_MydRead_settings( iso15693_MydRead_settings* structure );

#define ISO15693_ENPREPARE		0x04
#define ISO15693_ENSINGLE_BYTE	0x08
#define ISO15693_ENREREAD		0x20

typedef struct {
	bool EnSecure;
	bool EnRestricted;
	bool EnPrepare;
	bool EnSingleByte;
	bool EnReread;

	int PageAddress;

	int ByteAddress;

	int Len;

	unsigned char Data[ISO15693_MYD_PAGE_MAX_LEN];
} iso15693_MydWrite_request;

int iso15693_myd_write( int Handle, iso15693_MydWrite_request* request,
				byte* label_stat, int *Status );

void iso15693_init_MydWrite_request( iso15693_MydWrite_request* structure );

#if defined(__cplusplus)
}
#endif

#endif