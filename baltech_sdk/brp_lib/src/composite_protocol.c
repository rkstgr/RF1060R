#include "brp_lib/frames.h"
#include "brp_lib/composite_protocol.h"
#include "brp_lib/brp_protocol.h"
#include "brp_lib/monitor_protocol.h"


static bool copy_frame(brp_frame dst_frame, brp_frame src_frame)
{
	brp_frame_reader src_frame_rdr;
	brp_frame_read_start(&src_frame_rdr, src_frame);
	brp_frame_read_frm_rest(&src_frame_rdr, dst_frame);
	return brp_frame_read_eof(&src_frame_rdr);
}


static brp_protocol find_upper_layer(
	brp_protocol comp_protocol, brp_layer_id search_layer_id)
{
	brp_protocol upper_protocol = comp_protocol;
	while (upper_protocol->base_protocol != NULL)
	{
		if (upper_protocol->base_protocol->layer_id == search_layer_id)
			return upper_protocol;
		if (upper_protocol->base_protocol->protocol_id == BRP_PROTID_COMPOSITE)
			break;
		upper_protocol = upper_protocol->base_protocol;
	}
	return NULL;
}


static brp_protocol find_layer(
	brp_protocol comp_protocol, brp_layer_id search_layer_id)
{
	brp_protocol upper_prot = find_upper_layer(comp_protocol, search_layer_id);
	if (upper_prot == NULL)
		return NULL;
	else
		return upper_prot->base_protocol;
}


static brp_errcode close_all(brp_protocol protocol)
{
	brp_errcode cur_errcode, errcode = BRP_OK;
	brp_protocol close_protocol = protocol->base_protocol;
	while (close_protocol != NULL)
	{
		if (close_protocol->protocol_id == BRP_PROTID_COMPOSITE)
			break;
		
		cur_errcode = brp_close(close_protocol);
		if (cur_errcode != BRP_OK)
			errcode = cur_errcode;
		
		close_protocol = close_protocol->base_protocol;
	}
	return errcode;
}


static brp_errcode open_all(brp_protocol protocol)
{
	brp_errcode errcode;
	brp_protocol iter_protocol = find_layer(protocol, BRP_LAYERID_IO);
	if (iter_protocol == NULL)
		return BRP_ERR_CLOSED;
	if (iter_protocol->protocol_id == BRP_PROTID_COMPOSITE
			&&  !iter_protocol->opened)
		return BRP_ERR_CLOSED;
	while (iter_protocol != protocol)
	{
		errcode = brp_open(iter_protocol);
		if (errcode != BRP_OK)
		{
			close_all(protocol);
			return errcode;
		}
		iter_protocol = find_upper_layer(protocol, iter_protocol->layer_id);
	}

	return BRP_OK;
}


static brp_errcode redirect_send_frame(brp_protocol protocol)
{
	brp_errcode errcode;
	if (protocol->base_protocol == NULL)
		return BRP_ERR_NOT_IMPLEMENTED;
	if(!copy_frame(&protocol->base_protocol->send_frame, &protocol->send_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	errcode = brp_send_frame(protocol->base_protocol);
	return errcode;
}


static brp_errcode redirect_recv_any_frame(
	brp_protocol protocol, brp_time timeout)
{
	brp_errcode errcode;
	if (protocol->base_protocol == NULL)
		return BRP_ERR_NOT_IMPLEMENTED;
	errcode = brp_recv_any_frame(protocol->base_protocol, timeout);
	if(!copy_frame(&protocol->recv_frame, &protocol->base_protocol->recv_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	return errcode;
}


static brp_errcode redirect_recv_frame(
	brp_protocol protocol, brp_time timeout,
	brp_cb_fmt_spec_t fmt_spec, void * context)
{
	brp_errcode errcode;
	if (protocol->base_protocol == NULL)
		return BRP_ERR_NOT_IMPLEMENTED;
	errcode = brp_recv_frame(
		protocol->base_protocol, timeout, fmt_spec, context);
	if(!copy_frame(&protocol->recv_frame, &protocol->base_protocol->recv_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	return errcode;
}


static brp_errcode redirect_flush(brp_protocol protocol)
{
	if (protocol->base_protocol == NULL)
		return BRP_ERR_NOT_IMPLEMENTED;
	return brp_flush(protocol->base_protocol);
}


static brp_errcode redirect_destroy(brp_protocol protocol)
{
	brp_errcode cur_errcode, errcode = BRP_OK;
	brp_protocol saved_base_protocol = protocol->base_protocol;
	brp_protocol_free(protocol);
	protocol = saved_base_protocol;

	while (protocol != NULL)
	{
		if (protocol->protocol_id == BRP_PROTID_COMPOSITE)
			break;
		
		saved_base_protocol = protocol->base_protocol;
		cur_errcode = brp_destroy(protocol);
		if (errcode == BRP_OK)
			errcode = cur_errcode;
		protocol = saved_base_protocol;
	}

	return errcode;
}


brp_protocol brp_create(void)
{
	brp_protocol comp_protocol = brp_create_composite();
	brp_add_layer(comp_protocol, BRP_LAYERID_BRP);
	brp_add_layer(comp_protocol, BRP_LAYERID_CRYPTO);
	brp_add_layer(comp_protocol, BRP_LAYERID_MONITOR);
	
	brp_set_layer(comp_protocol, BRP_LAYERID_BRP, brp_create_brp());
	brp_set_layer(comp_protocol, BRP_LAYERID_MONITOR, brp_create_monitor());
	
	return comp_protocol;
}


static brp_protocol create_dummy_layer(int layer_id)
{
	brp_protocol protocol = malloc(sizeof(struct brp_protocol_t));
	if (protocol == NULL)
		return NULL;

	memset(protocol, 0, sizeof(*protocol));
	protocol->protocol_id = BRP_PROTID_DUMMY;
	protocol->layer_id = layer_id;
	protocol->cb_send_frame = (brp_cb_generic_t) redirect_send_frame;
	protocol->cb_recv_any_frame =
		(brp_cb_recv_any_frame_t) redirect_recv_any_frame;
	protocol->cb_recv_frame = (brp_cb_recv_frame_t) redirect_recv_frame;
	protocol->cb_flush = (brp_cb_generic_t) redirect_flush;
	protocol->cb_destroy = (brp_cb_generic_t) brp_protocol_free;

	return protocol;
}


brp_protocol require_protocol(
	brp_protocol protocol, int protocol_id, brp_layer_id layer_id)
{
	if (protocol == NULL)
		return NULL;
	else if (protocol->protocol_id == protocol_id)
		return protocol;
	else if (protocol->protocol_id == BRP_PROTID_COMPOSITE)
		return brp_get_layer(protocol, layer_id);
	else
		return NULL;
}


brp_protocol brp_create_composite(void)
{
	brp_protocol protocol = malloc(sizeof(struct brp_protocol_t));
	if (protocol == NULL)
		return NULL;

	memset(protocol, 0, sizeof(*protocol));
	protocol->protocol_id = BRP_PROTID_COMPOSITE;
	protocol->cb_open = (brp_cb_generic_t) open_all;
	protocol->cb_close = (brp_cb_generic_t) close_all;
	protocol->cb_send_frame = (brp_cb_generic_t) redirect_send_frame;
	protocol->cb_recv_any_frame =
		(brp_cb_recv_any_frame_t) redirect_recv_any_frame;
	protocol->cb_recv_frame = (brp_cb_recv_frame_t) redirect_recv_frame;
	protocol->cb_flush = (brp_cb_generic_t) redirect_flush;
	protocol->cb_destroy = (brp_cb_generic_t) redirect_destroy;

	protocol->base_protocol = create_dummy_layer(BRP_LAYERID_IO);
	if (protocol->base_protocol == NULL)
	{
		free(protocol);
		return NULL;
	}

	return protocol;
}


brp_protocol brp_get_layer(brp_protocol comp_protocol, int search_layer_id)
{
	brp_protocol found_prot;

	if (comp_protocol == NULL)
		return NULL;

	found_prot = find_layer(comp_protocol, search_layer_id);
	if (found_prot == NULL)
		return NULL;
	else if (found_prot->protocol_id == BRP_PROTID_DUMMY)
		return NULL;
	else
		return found_prot;
}


brp_errcode brp_add_layer(brp_protocol composite_protocol, int layer_id)
{
	brp_protocol new_dummy;
	if (composite_protocol == NULL)
		return BRP_ERR_INVALID_API_CALL;

	if (find_layer(composite_protocol, layer_id) != NULL)
		return BRP_ERR_EXISTING_LAYER;

	new_dummy = create_dummy_layer(layer_id);
	new_dummy->base_protocol = composite_protocol->base_protocol;
	composite_protocol->base_protocol = new_dummy;

	return BRP_OK;
}


brp_errcode brp_set_layer(
	brp_protocol comp_protocol, int layer_id, brp_protocol layer_protocol)
{
	brp_protocol existing_protocol, upper_protocol, lower_protocol;
	brp_errcode errcode;

	if (layer_protocol == NULL  ||  comp_protocol == NULL)
		return BRP_ERR_INVALID_API_CALL;

	if (comp_protocol->protocol_id != BRP_PROTID_COMPOSITE)
		return BRP_ERR_INVALID_API_CALL;

	if (layer_protocol->protocol_id == BRP_PROTID_COMPOSITE)
	{
		if (layer_id != BRP_LAYERID_IO)
			return BRP_ERR_INVALID_API_CALL;
	}
	else
	{
		if (layer_protocol->opened)
			return BRP_ERR_INVALID_API_CALL;
	}
	
	upper_protocol = find_upper_layer(comp_protocol, layer_id);
	if (upper_protocol == NULL)
	{
		// mark protocol for appending
		upper_protocol = comp_protocol;
		existing_protocol = NULL;
		lower_protocol = upper_protocol->base_protocol;
	}
	else
	{
		existing_protocol = upper_protocol->base_protocol;
		lower_protocol = existing_protocol->base_protocol;
	}

	// open new protocol if necessary
	if (layer_id != BRP_LAYERID_IO)
		layer_protocol->base_protocol = lower_protocol;
	if (comp_protocol->opened)
	{
		errcode = brp_open(layer_protocol);
		if (errcode != BRP_OK)
		{
			if (layer_id != BRP_LAYERID_IO)
				layer_protocol->base_protocol = NULL;
			return errcode;
		}
	}

	if (existing_protocol != NULL)
	{
		if (existing_protocol->protocol_id != BRP_PROTID_COMPOSITE)
		{
			brp_close(existing_protocol);
			existing_protocol->base_protocol = NULL;
			brp_destroy(existing_protocol);
		}
	}

	// final operations to insert new protocol
	upper_protocol->base_protocol = layer_protocol;
	layer_protocol->layer_id = layer_id;

	return BRP_OK;
}


brp_protocol brp_detach_layer(brp_protocol composite_protocol, int layer_id)
{
	brp_protocol upper_protocol, detach_protocol, dummy_layer, cprot;

	if (composite_protocol == NULL)
		return NULL;

	upper_protocol = find_upper_layer(composite_protocol, layer_id);
	if (upper_protocol == NULL)
		return NULL;
	detach_protocol = upper_protocol->base_protocol;

	dummy_layer = create_dummy_layer(layer_id);
	if (dummy_layer == NULL)
		return NULL;
	
	cprot = (layer_id == BRP_LAYERID_IO) ? composite_protocol : detach_protocol;
	if (brp_close(cprot) != BRP_OK)
	{
		brp_destroy(dummy_layer);
		return NULL;
	}

	// replace by new protocol
	upper_protocol->base_protocol = dummy_layer;
	dummy_layer->base_protocol = detach_protocol->base_protocol;
	detach_protocol->base_protocol = NULL;

	return detach_protocol;
}


brp_errcode brp_set_io(brp_protocol protocol, brp_protocol io_protocol)
{
	brp_errcode errcode =  brp_set_layer(protocol, BRP_LAYERID_IO, io_protocol);
	if (errcode != BRP_OK)
		brp_destroy(io_protocol);
	return errcode;
}


brp_errcode brp_set_crypto(
	brp_protocol protocol, brp_protocol crypto_protocol)
{
	brp_errcode errcode =  brp_set_layer(
			protocol, BRP_LAYERID_CRYPTO, crypto_protocol);
	if (errcode != BRP_OK)
		brp_destroy(crypto_protocol);
	return errcode;
}


brp_errcode brp_suppress_monitoring(brp_protocol protocol)
{
	brp_protocol mon_protocol = brp_detach_layer(protocol, BRP_LAYERID_MONITOR);
	if (mon_protocol == NULL)
		return BRP_ERR_INVALID_API_CALL;
	else
		return brp_destroy(mon_protocol);
}
