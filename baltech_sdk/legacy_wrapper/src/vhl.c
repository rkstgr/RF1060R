#include "vhl.h"
#include <string.h>

#define VHL_EXTRA_TIMEOUT       2500



int vhl_select( int Handle,
				word CardTypeMask,
				bool Reselect,
				bool AllowConfig,
				byte * CardType,
				int * Status )
{
    byte param[4];

	// build the parameters
    param[0] = (byte) ( CardTypeMask >> 8 );
    param[1] = (byte) CardTypeMask;

    if ( Reselect == true ) {
    	param[2] = BRP_TRUE;
    } 
	else {
    	param[2] = BRP_FALSE;
    }

    if ( AllowConfig == true ) {
     	param[3] = BRP_TRUE;
    } 
	else {
     	param[3] = BRP_FALSE;
    }

	return ( brp_exec_command ( Handle,
    							VHL_DEV_CODE,
                                VHL_SELECT,
                                param,
                                4,
                                BRP_TIMEOUT_LONG + VHL_EXTRA_TIMEOUT,
                                Status,
                                CardType,
                                NULL,
                                1 ) );
}


int vhl_get_snr( int Handle,
				 byte * Snr,
				 byte * Length,
				 int * Status )
{
	int IntLength;
	int ErrCode = brp_exec_command ( Handle,
									 VHL_DEV_CODE,
									 VHL_GET_SNR,
									 NULL,
									 0,
									 BRP_TIMEOUT_DEFAULT,
									 Status,
									 Snr,
									 &IntLength,
									 16 );
	if (Length != NULL) *Length = (byte)IntLength;

	return (ErrCode);
}


int vhl_read( int Handle,
			  byte VHLFile,
			  word Address,
			  word Length,
			  byte * Data,
			  int * Status )
{
	int max_len;
    byte param[5];

    max_len = (int) Length;

	// build the parameters
    param[0] = VHLFile;
    param[1] = (byte) ( Address >> 8 );
    param[2] = (byte) Address;
    param[3] = (byte) ( Length >> 8 );
    param[4] = (byte) Length;

	return ( brp_exec_command ( Handle,
    							VHL_DEV_CODE,
                                VHL_READ,
                                param,
                                5,
                                BRP_TIMEOUT_VAR( Length ) + VHL_EXTRA_TIMEOUT,
                                Status,
                                Data,
                                (int*) &Length,
                                max_len ) );
}


int vhl_write( int Handle,
			   byte VHLFile,
			   word Address,
			   word Length,
			   byte * Data,
			   int * Status )
{
	int return_val;
	byte * param;

	// alloc the mem for param from the heap
	param = (byte*) malloc( Length + 5 );
	if ( param == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	// build the parameters
	param[0] = VHLFile;
	param[1] = (byte) ( Address >> 8 );
	param[2] = (byte) Address;
	param[3] = (byte) ( Length >> 8 );
	param[4] = (byte) Length;
	// ATTENTION: This part is not good in Microcontrollers. This shoul be
	// opimized
	memcpy( param + 5, Data, Length );

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_WRITE,
									param,
									Length + 5,
									BRP_TIMEOUT_VAR( Length + 5 ) + VHL_EXTRA_TIMEOUT,
									Status,
									NULL,
									NULL,
									0 );
	free( param );
	return( return_val );
}


int vhl_setup_mifare( int Handle,
					  byte Mode,
					  byte * Key,
					  int * Status )
{
	int len;
    int return_val;
    byte param[7];

	// alloc the mem for param from the heap and specify the len
    if ( Mode == VHL_MIF_USE_MYKEY ) {
        len = 7;
	} 
	else {
    	len = 1;
	}

	// build the parameters
    param[0] = Mode;
    // ATTENTION: This part is not good in Microcontrollers. This shoul be
    // opimized
    if ( Mode == VHL_MIF_USE_MYKEY )
	    memcpy( param + 1, Key, 6 );

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_SETUP_MIFARE,
									param,
									len,
									BRP_TIMEOUT_DEFAULT,
									Status,
									NULL,
									NULL,
									0 );

    return( return_val );
}


int vhl_setup_legic( int Handle,
					 byte StampLen,
					 byte * Stamp,
					 int * Status )
{
	int len;
    int return_val;
    byte * param;

	// alloc the mem for param from the heap and specify the len
    if ( StampLen > 0 ) {
	    param = (byte*) malloc( StampLen + 1 );
	    if ( param == NULL )
	    	return ( BRP_ERR_INSUFFICIENT_MEM );
        len = StampLen + 1;
    } 
	else {
	    param = (byte*) malloc( 2 );
	    if ( param == NULL )
	    	return ( BRP_ERR_INSUFFICIENT_MEM );
    	len = 2;
    }

	// build the parameters
    param[0] = StampLen;
    // ATTENTION: This part is not good in Microcontrollers. This should be
    // opimized
    if ( len > 0 )
	    memcpy( param + 1, Stamp, len - 1 );

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_SETUP_MIFARE,
									param,
									len,
									BRP_TIMEOUT_DEFAULT,
									Status,
									NULL,
									NULL,
									0 );
    free( param );
    return( return_val );
}

int vhl_is_selected( int Handle,
					 int * Status )
{
	return( brp_exec_command ( Handle,
							   VHL_DEV_CODE,
							   VHL_IS_SELECTED,
							   NULL,
							   0,
							   BRP_TIMEOUT_LONG + VHL_EXTRA_TIMEOUT,
							   Status,
							   NULL,
							   NULL,
							   0 ) );
}


int vhl_get_atr( int Handle,
				 byte * len,
				 unsigned char * atr,
				 int * Status ) 
{
	unsigned char Data[VHL_ATR_MAX_LEN + 1];
	int data_len;
	int return_val;

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_GET_ATR,
									NULL,
									0,
									BRP_TIMEOUT_SHORT,
									Status,
									Data,
									&data_len,
									VHL_ATR_MAX_LEN + 1 );

	if ( return_val == BRP_OK ) {
		*len = Data[0];
		memcpy( atr, Data + 1, *len );
	}

	return( return_val );
}


int vhl_exchange_apdu( int Handle,
					   byte card_type,
					   word buf_len,
					   unsigned char * buf,
					   word * resp_len,
					   unsigned char * resp,
					   word resp_max_len,
					   int * Status )
{
	int return_val;
	byte * Data;

	// alloc the mem for param from the heap and specify the len
	if ( buf_len > resp_max_len ) {
		Data = (byte*) malloc( buf_len + 3 );
	}
	else {
		Data = (byte*) malloc( resp_max_len + 3 );
	}
	if ( Data == NULL )
		return ( BRP_ERR_INSUFFICIENT_MEM );

	Data[0] = card_type;
	Data[1] = (byte)(buf_len >> 8);
	Data[2] = (byte)buf_len;

	memcpy( Data + 3, buf, buf_len );

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_EXCHANGE_APDU,
									Data,
									buf_len + 3,
									BRP_TIMEOUT_VAR( buf_len + resp_max_len + 450 ),
									Status,
									Data,
									(int *) resp_len,
									resp_max_len + 2 );

	if ( return_val == BRP_OK ) {
		*resp_len = *resp_len - 2;
		memcpy( resp, Data + 2, *resp_len );
	}
	free( Data );
    return( return_val );
}


int vhl_setup( int Handle,
			   byte card_type,
			   void * lv_struct,
			   int * Status )
{
	int return_val;
	byte * Data;
	int len;
	int param_count;

	len = 2; // for the card_type and the parameter count

	switch( card_type ) {
		vhl_setup_mifare_classic * mif_struct;
		vhl_setup_legic_prime * leg_struct;
		vhl_setup_iso15693 * iso15_struct;
		vhl_setup_raw * raw_struct;

	case VHL_CT_ISO14443A:
		mif_struct = (vhl_setup_mifare_classic *) lv_struct;
		len = len + 6; // for the key
		len = len + 1; // for 'as key a' flag
		if ( mif_struct->use_mad_id == true ) {
			len = len + 2; // for MAD key
			param_count = 3; // for three length bytes
			len = len + param_count;
			Data = (byte*) malloc( len );
			if ( Data == NULL ) {
				return ( BRP_ERR_INSUFFICIENT_MEM );
			}
			Data[11] = 2; // length of mad_id
			memcpy( Data + 12, mif_struct->mad_id, 2 );
		}
		else {
			param_count = 2; // for two length bytes
			len = len + param_count;
			Data = (byte*) malloc( len );
			if ( Data == NULL ) {
				return ( BRP_ERR_INSUFFICIENT_MEM );
			}
		}
		Data[0] = card_type;
		Data[1] = (unsigned char) param_count;
		Data[2] = 6; // length of key
		memcpy( Data + 3, mif_struct->key, 6 );
		Data[9] = 1; // length of flag 'as key a'
		if ( mif_struct->as_key_a == true ) {
			Data[10] = BRP_TRUE;
		}
		else {
			Data[10] = BRP_FALSE;
		}
		break;

	case VHL_CT_LEGIC:
		leg_struct = (vhl_setup_legic_prime *) lv_struct;
		Data = (byte*) malloc( 3 + leg_struct->seg_len + 2 ); // length: see below
		if ( Data == NULL ) {
			return ( BRP_ERR_INSUFFICIENT_MEM );
		}
		len = len + leg_struct->seg_len;
		len = len + 1; // for en_stamp flag;
		param_count = 2; // for two length bytes
		len = len + param_count;
		Data[0] = card_type;
		Data[1] = (unsigned char) param_count;
		Data[2] = leg_struct->seg_len;
		memcpy( Data + 3, leg_struct->seg, leg_struct->seg_len );
		Data[3 + leg_struct->seg_len + 1] = 1; // the length of en_stamp flag
		if ( leg_struct->en_stamp == true ) {
			Data[3 + leg_struct->seg_len + 2] = BRP_TRUE;
		} 
		else {
			Data[3 + leg_struct->seg_len + 2] = BRP_FALSE;
		}
		break;

	case VHL_CT_ISO15693:
		iso15_struct = (vhl_setup_iso15693 *) lv_struct;
		Data = (byte*) malloc( 6 ); // length: see below
		if ( Data == NULL ) {
			return ( BRP_ERR_INSUFFICIENT_MEM );
		}
		len = len + 1; // for the first_block
		len = len + 1; // for the block_count
		param_count = 2; // for two parameters
		len = len + param_count;
		Data[0] = card_type;
		Data[1] = (unsigned char) param_count;
		Data[2] = 1; // the length of first_block
		Data[3] = iso15_struct->first_block;
		Data[4] = 1; // the length of block_count
		Data[5] = iso15_struct->block_count;
		break;

	default:
		raw_struct = (vhl_setup_raw *) lv_struct;
		Data = (byte*) malloc( raw_struct->len );
		if ( Data == NULL ) {
			return ( BRP_ERR_INSUFFICIENT_MEM );
		}
		memcpy( Data, raw_struct->data_pointer, raw_struct->len );
		len = raw_struct->len;
		break;
	}

	return_val = brp_exec_command ( Handle,
									VHL_DEV_CODE,
									VHL_SETUP,
									Data,
									len,
									BRP_TIMEOUT_VAR( len ),
									Status,
									NULL,
									NULL,
									0 );

	free( Data );
	return( return_val );
}

void vhl_init_setup_mifare_classic( vhl_setup_mifare_classic * lv_struct ) {
 	lv_struct->key[0] = 0x00;
 	lv_struct->key[1] = 0x00;
 	lv_struct->key[2] = 0x00;
 	lv_struct->key[3] = 0x00;
 	lv_struct->key[4] = 0x00;
 	lv_struct->key[5] = 0x00;
	lv_struct->as_key_a = true;
	lv_struct->use_mad_id = false;
}

void vhl_init_setup_legic_prime( vhl_setup_legic_prime * lv_struct ) {
	lv_struct->seg_len = 1;
	lv_struct->seg[0] = 0x01;
	lv_struct->en_stamp = false;
}

void vhl_init_setup_iso15693( vhl_setup_iso15693 * lv_struct ) {
	lv_struct->first_block = 0x00;
	lv_struct->block_count = 0xFF;
}

void vhl_init_setup_raw( vhl_setup_raw * lv_struct ) {
	lv_struct->len = 0;
}


