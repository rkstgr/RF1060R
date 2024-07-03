#include "syscmds.h"
#include "brp.h"
#include <string.h>

int syscmd_auto_setup( int Handle,
	int * Status ) {
    int return_val;
	word total_bufsize;
    word send_bufsize;
    word recv_bufsize;

    return_val = syscmd_get_buffer_size( Handle,
    	&send_bufsize, &recv_bufsize, &total_bufsize,
        Status );

    if ( return_val != BRP_OK )
    	return( return_val );

    return( brp_set_bufsize( Handle,
	(int) total_bufsize, (int) send_bufsize, (int) recv_bufsize) );
}
// ************************************************************


int syscmd_get_buffer_size( int Handle,
	word * MaxSendSize, word * MaxRecvSize, word * TotalSize,
	int * Status ) {
	byte resp[6];
    int return_val;

	return_val = brp_exec_command ( Handle,
    							SYSCMD_DEV_CODE,
                                SYSCMD_GET_BUFFER_SIZE,
                                NULL,
                                0,
                                BRP_TIMEOUT_SHORT,
								Status,
                                resp,
                                NULL,
                                6 );
    if ( return_val == BRP_OK ) {
	    *MaxSendSize = (word) resp[0];
	    *MaxSendSize = *MaxSendSize << 8;
	    *MaxSendSize = *MaxSendSize + resp[1];
	    *MaxRecvSize = (word) resp[2];
	    *MaxRecvSize = *MaxRecvSize << 8;
	    *MaxRecvSize = *MaxRecvSize + resp[3];
	    *TotalSize = (word) resp[4];
	    *TotalSize = *TotalSize << 8;
	    *TotalSize = *TotalSize + resp[5];
    }

    return( return_val );
}
// ************************************************************


//reboot reader
int syscmd_reset( int Handle,
	int * Status ) {
	return( brp_exec_command ( Handle,
    							SYSCMD_DEV_CODE,
                                SYSCMD_RESET,
                                NULL,
                                0,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 ) );
}
// ************************************************************


//get firmwarestring
int syscmd_get_info( int Handle, char * fws,
	int * Status )
{
	return( brp_exec_command ( Handle,
								SYSCMD_DEV_CODE,
								SYSCMD_GET_INFO,
								NULL,
								0,
								BRP_TIMEOUT_DEFAULT,
								Status,
							   (unsigned char*) fws,
								NULL,
								SYSCMD_FWS_LEN ) );
}
// ************************************************************


//get boot status
int syscmd_get_boot_status( int Handle, dword * boot_status,
	int * Status ) {
    int return_val;
    byte resp[4];

	return_val = brp_exec_command ( Handle,
    							SYSCMD_DEV_CODE,
                                SYSCMD_GET_BOOT_STATUS,
								NULL,
                                0,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                resp,
                                NULL,
                                4 );
	if ( return_val == BRP_OK ) {
	    *boot_status = (dword) resp[0];
	    *boot_status = *boot_status << 8;
	    *boot_status = *boot_status + resp[1];
	    *boot_status = *boot_status << 8;
	    *boot_status = *boot_status + resp[2];
	    *boot_status = *boot_status << 8;
	    *boot_status = *boot_status + resp[3];
    }

    return( return_val );
}
// ************************************************************

//get boot status
int syscmd_get_port( int Handle, word * port_mask,
	int * Status ) {
    int return_val;
    byte resp[2];

	return_val = brp_exec_command ( Handle,
        			SYSCMD_DEV_CODE,
                                SYSCMD_GET_PORT,
        			NULL,
                                0,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                resp,
                                NULL,
                                2 );
	if ( return_val == BRP_OK ) {
	    *port_mask = (word) resp[0];
	    *port_mask = *port_mask << 8;
	    *port_mask = *port_mask + resp[1];
    }

    return( return_val );
}
// ************************************************************


//get boot status
int syscmd_set_port( int Handle, word port_mask,
	int * Status ) {
    int return_val;
    byte data[2];

    data[0] = (byte) (port_mask >> 8);
    data[1] = (byte) port_mask;

	return_val = brp_exec_command ( Handle,
        			SYSCMD_DEV_CODE,
                                SYSCMD_SET_PORT,
        			data,
                                2,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 );

    return( return_val );
}
// ************************************************************


//reset HF
int syscmd_hf_reset( int Handle, byte off_time,
	int * Status ) {

	return( brp_exec_command ( Handle,
    							SYSCMD_DEV_CODE,
                                SYSCMD_HF_RESET,
                                &off_time,
                                1,
								off_time + BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 ) );
}
// ************************************************************


//get configuration value
int syscmd_cfg_get_value( int Handle,
	word key, byte value, byte data[], int * len, int max_len,
	int * Status ) {
    int return_val;
    byte param[3];
    int mylen;
    byte *resp;

    resp = (byte*) malloc( 1 + max_len );
    if ( resp == NULL )
    	return ( BRP_ERR_INSUFFICIENT_MEM );

    param[0] = (byte) ( key >> 8 );
    param[1] = (byte) key;
    param[2] = value;

	return_val = brp_exec_command ( Handle,
    							SYSCMD_DEV_CODE,
                                SYSCMD_CFG_GET_VALUE,
                                param,
                                3,
                                BRP_TIMEOUT_VAR( max_len ),
                                Status,
                                resp,
                                &mylen,
                                max_len + 1);
    if ( return_val == BRP_OK ) {
	    if ( resp[0] < max_len + 1 ) {
			memcpy( data, resp + 1, (int) resp[0] );
		    *len = resp[0];
	    } else
	    	return_val = BRP_ERR_BUFFER_OVERFLOW;
    }

    free ( resp );
    return( return_val );
}
// ************************************************************


//set configuration value
int syscmd_cfg_set_value( int Handle,
	word key, byte value, byte data[], int len,
	int * Status ) {
	int return_val;
	byte *param;

	param = (byte*) malloc( 4 + SYSCMD_CFG_MAX_BLOCK_SIZE );
	if ( param == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	param[0] = (byte) ( key >> 8 );
	param[1] = (byte) key;
	param[2] = value;
	param[3] = (byte) len;
	memcpy( param + 4, data, len );

	return_val = brp_exec_command ( Handle,
								SYSCMD_DEV_CODE,
								SYSCMD_CFG_SET_VALUE,
								param,
								len + 4,
								BRP_TIMEOUT_VAR( len ),
								Status,
								NULL,
								NULL,
                                0 );

    free ( param );
    return( return_val );
}
// ************************************************************


//delete configuration value(s)
int syscmd_cfg_del_values( int Handle, word key, byte value,
	int * Status ) {
	byte param[3];

	param[0] = (byte) ( key >> 8 );
	param[1] = (byte) key;
	param[2] = value;

	return( brp_exec_command ( Handle,
								SYSCMD_DEV_CODE,
								SYSCMD_CFG_DEL_VALUES,
								param,
								3,
								BRP_TIMEOUT_LONG,
								Status,
								NULL,
								NULL,
								0 ) );
}
// ************************************************************


//get keylist
int syscmd_cfg_get_key_list( int Handle, word keys[],
	int * key_count, int max_key_count,
	int * Status ) {
	int return_val;
	byte *resp;
	int len;

	resp = (byte*) malloc( max_key_count * 2 + 1 );
	if ( resp == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	return_val = brp_exec_command ( Handle,
								SYSCMD_DEV_CODE,
								SYSCMD_CFG_GET_KEY_LIST,
								NULL,
								0,
								BRP_TIMEOUT_VAR( max_key_count * 2 ),
								Status,
								resp,
								&len,
								max_key_count * 2 );
	if ( return_val == BRP_OK ) {
		if ( len <= max_key_count * 2 + 1 ) {
			memcpy( keys, resp + 1, (int) ( resp[0] * 2 ) );
			*key_count = resp[0];
		} else
			return_val = BRP_ERR_BUFFER_OVERFLOW;
	}

	free ( resp );
	return( return_val );
}
// ************************************************************


//get valuelist
int syscmd_cfg_get_value_list( int Handle, word key, byte values[],
	int * value_count, int max_value_count,
	int * Status ) {
	int return_val;
	int len;
	byte *resp;
	byte param[2];

	resp = (byte*) malloc( max_value_count + 1 );
	if ( resp == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	param[0] = (byte) ( key >> 8 );
	param[1] = (byte) key;

	return_val = brp_exec_command ( Handle,
								SYSCMD_DEV_CODE,
								SYSCMD_CFG_GET_VALUE_LIST,
								param,
								2,
								BRP_TIMEOUT_VAR( max_value_count ),
								Status,
								resp,
								&len,
								max_value_count );
	if ( return_val == BRP_OK ) {
		if ( len <= max_value_count + 1 ) {
			memcpy( values, resp + 1, (int) resp[0] );
		    *value_count = resp[0];
	    } else
	    	return_val = BRP_ERR_BUFFER_OVERFLOW;
    }

    free ( resp );
    return( return_val );
}
// ************************************************************


int syscmd_cfg_write_tlv_sector( int Handle,
	byte tlv_data[], int len,
	int * Status ) {
	int return_val;

	return_val = brp_exec_command ( Handle,
					SYSCMD_DEV_CODE,
					SYSCMD_CFG_WRITE_TLV_SECTOR,
					tlv_data,
					len,
					BRP_TIMEOUT_VAR( len ),
					Status,
					NULL,
					NULL,
					0 );
	return( return_val );
}


int syscmd_config_port( int Handle,
	word is_out_mask, word def_mask,
	int * Status ) {
	byte param[4];

	param[0] = (byte) (is_out_mask >> 8);
	param[1] = (byte) is_out_mask;
	param[2] = (byte) (def_mask >> 8);
	param[3] = (byte) def_mask;
	return( brp_exec_command ( Handle,
				SYSCMD_DEV_CODE,
                                SYSCMD_CONFIG_PORT,
                                param,
                                4,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 ) );
}


int syscmd_power_down( int Handle,
	int * Status ) {
	return( brp_exec_command ( Handle,
				SYSCMD_DEV_CODE,
                                SYSCMD_POWER_DOWN,
                                NULL,
                                0,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 ) );
}


int syscmd_set_protocol( int Handle,
	unsigned char protocol_id,
	int * Status ) {
	return( brp_exec_command ( Handle,
				SYSCMD_DEV_CODE,
                                SYSCMD_SET_PROTOCOL,
                                &protocol_id,
                                1,
                                BRP_TIMEOUT_SHORT,
                                Status,
                                NULL,
                                NULL,
                                0 ) );

}

int syscmd_cfg_load_block( int Handle,
	int version, byte block_data[], int len, int * Status ) {
    int return_val;
	byte *param;
    param = (byte*) malloc( 2 + len); 
	if ( param == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	param[0] = (byte) version;
	param[1] = (byte) len;
	memcpy( param + 2, block_data, len );

	return_val = ( brp_exec_command ( Handle,
				SYSCMD_DEV_CODE,
                                SYSCMD_CFG_LOAD_BLOCK,
                                param,
								len+2,
                                BRP_TIMEOUT_EXTRA_LONG,
                                Status,
                                NULL,
                                NULL,
                                0 ) );
	free ( param );
    return( return_val );
}

