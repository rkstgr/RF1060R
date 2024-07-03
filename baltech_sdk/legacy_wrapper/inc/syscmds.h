
#if ! defined(__SYSTEM_COMMANDS__)
#define __SYSTEM_COMMANDS__

#if defined(__cplusplus)
extern "C" {
#endif


#include "compiler.h"
#include "oswrapper.h"
#include "brp.h"

// the device code for the system commands
#define SYSCMD_DEV_CODE		0x00

// the defines for the system commands
#define SYSCMD_GET_BUFFER_SIZE		0x00
#define SYSCMD_HF_RESET				0x01
#define SYSCMD_RESET				0x03
#define SYSCMD_GET_INFO				0x04
#define SYSCMD_GET_BOOT_STATUS		0x05
#define SYSCMD_GET_PORT	        	0x06
#define SYSCMD_SET_PORT 		0x07
#define SYSCMD_CFG_GET_VALUE		0x08
#define SYSCMD_CFG_SET_VALUE		0x09
#define SYSCMD_CFG_DEL_VALUES		0x0A
#define SYSCMD_CFG_GET_KEY_LIST		0x0B
#define SYSCMD_CFG_GET_VALUE_LIST	0x0C
#define SYSCMD_CFG_WRITE_TLV_SECTOR	0x0D
#define SYSCMD_CONFIG_PORT		0x0E
#define SYSCMD_POWER_DOWN		0x11
#define SYSCMD_SET_PROTOCOL		0x12
#define SYSCMD_CFG_LOAD_BLOCK		0x16



// the maximal size of one block in cfg requests
#define SYSCMD_CFG_MAX_BLOCK_SIZE	127

// the defines for all possible errors from a system command
#define SYSCMD_ERR_CONF_FULL			0x0001
#define SYSCMD_ERR_CONF_EEPROM			0x0002
#define SYSCMD_ERR_CONF_NOTFOUND		0x0003
#define SYSCMD_ERR_INVALID_TLVSECTOR	0x0004
#define SYSCMD_ERR_CONF_ACCESS_DENIED	0x0005

//this command autoinitializes the reader
//(that is protocol buffer sizes/alive_timeouts/devcode_maps)
int syscmd_auto_setup( int Handle,
	int * Status );


//get the size of all buffers
//Handle:			The handle that is used for communication
//MaxSendSize:		The size of the send buffer. Can be NULL
//MaxRecvSize:		The size of the receive buffer. Can be NULL
//TotalSize:		The sum of all buffers. Can be NULL
//Status:			The Status of the command. Can be NULL
int syscmd_get_buffer_size( int Handle,
	word * MaxSendSize, word * MaxRecvSize, word * TotalSize,
	int * Status );


//reboot reader
int syscmd_reset( int Handle,
	int * Status );


//get firmwarestring
#define SYSCMD_FWS_LEN              41
int syscmd_get_info( int Handle, char * fws,
	int * Status );


//get boot status
int syscmd_get_boot_status( int Handle, dword * boot_status,
	int * Status );


//get boot status
int syscmd_get_port( int Handle, word * port_mask,
	int * Status );


//get boot status
int syscmd_set_port( int Handle, word port_mask,
	int * Status );


//reset HF
int syscmd_hf_reset( int Handle, byte off_time,
	int * Status );


//get configuration value
int syscmd_cfg_get_value( int Handle,
	word key, byte value, byte data[], int * len, int max_len,
	int * Status );


//set configuration value
int syscmd_cfg_set_value( int Handle,
	word key, byte value, byte data[], int len,
	int * Status );


//delete configuration value(s)
int syscmd_cfg_del_values( int Handle, word key, byte value,
	int * Status );


//get keylist
int syscmd_cfg_get_key_list( int Handle, word keys[],
	int * key_count, int max_key_count,
	int * Status );


//get valuelist
int syscmd_cfg_get_value_list( int Handle, word key, byte values[],
	int * value_count, int max_value_count,
	int * Status );


//write TLV sector
int syscmd_cfg_write_tlv_sector( int Handle,
	byte tlv_data[], int len,
	int * Status );


//configure IO Ports
int syscmd_config_port( int Handle,
	word is_out_mask, word def_mask,
	int * Status );


//send reader to sleep mode
int syscmd_power_down( int Handle,
	int * Status );


#define SYSCMD_PROTOCOL_RXTX		0x01
#define SYSCMD_PROTOCOL_T3964R		0x02
#define SYSCMD_PROTOCOL_BRP		0x03
#define SYSCMD_PROTOCOL_DEBUG_INTERFACE	0x09
#define SYSCMD_PROTOCOL_RAW_SERIAL	0x23

#define SYSCMD_PROTOCOL_BRP_NET		0x04
#define SYSCMD_PROTOCOL_WIEGAND		0x20
#define SYSCMD_PROTOCOL_MAGSTRIPE	0x21
#define SYSCMD_PROTOCOL_CLOCKDATA	0x22

#define SYSCMD_PROTOCOL_HID		0x05


//set protocol to be used
int syscmd_set_protocol( int Handle,
	unsigned char protocol_id,
	int * Status );

// load a configuration block
int syscmd_cfg_load_block( int Handle,
	int version, byte block_data[], int len, int * Status );

#if defined(__cplusplus)
}
#endif

#endif

