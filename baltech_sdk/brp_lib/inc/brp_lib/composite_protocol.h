/**
 * @file
 * A composite protocol is a container object, that provides a single protocol
 * object for handling a stack of multiple sub-protocols at once.
 *
 * This means all sub-protocols are opened/closed when the composite is
 * opened/closed. Furthermore they are destroyed when the composite is
 * destroyed.
 *
 * **ATTENTION**: This means that a protocol added to a container
 * must not be destroyed manually (except it is unlinked by
 * brp_detach_layer()!
 *
 * A composite is organized in layers, which are identified by unique
 * integers (see BRP_LAYERID_..., like #BRP_LAYERID_IO).
 * The order of the layer is fix and is usually defined by the order
 * of calling brp_add_layer() (or brp_set_layer(), which does an implicit
 * brp_add_layer() if a layer is unknown yet). Via brp_set_layer() you can
 * assign a protocol to a layer. When running a command / sending a frame,
 * it will be internally routed from the topmost protocol to the
 * bottom protocol.
 *
 * The I/O layer may be a composite protocol on its own. In this case it is
 * not part of the containing composite protocol stack. This means:
 * - Closing the containing composite does **not** close the contained composite
 * - Destroying the containing composite does **not** destroy (or close) the
 *   contained composite.
 * - Opening the containing composite when the contained composite is closed
 *   results in a #BRP_ERR_CLOSED
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */

#ifndef __COMPOSITE_PROTOCOL_H__
#define __COMPOSITE_PROTOCOL_H__


#include "protocol.h"


/**
 * Creates an empty composite protocol.
 * Composite protocols are used to manage a protocol stack by a single protocol
 * handle.
 *
 * @return NULL on error, otherwise the created protocol
 */
BRP_LIB brp_protocol brp_create_composite(void);


/**
 * This is equivalent to the following call:
 *
 * @code
 * brp_protocol composite_prot = brp_create_composite();
 * brp_protocol brp_prot = brp_create_brp();
 * brp_add_layer(composite_prot, BRP_LAYERID_IO);
 * brp_set_layer(composite_prot, BRP_LAYERID_BRP, brp_prot);
 * brp_add_layer(composite_prot, BRP_LAYERID_CRYPTO);
 * @endcode
 */
BRP_LIB brp_protocol brp_create(void);


/**
 * Adds a protocol layer without assigning a protocol to it.
 *
 * If the specified protocol layer was already added #BRP_ERR_EXISTING_LAYER
 * be returned, otherwise the layer will be added at the top of the
 * protocol stack.
 *
 * To assign a specific protocol to the new layer use brp_set_layer().
 */
BRP_LIB brp_errcode brp_add_layer
(
	brp_protocol composite_protocol,  ///< composite where layer shall be
	                                  ///  retrieved
	brp_layer_id layer_id             ///< identification of layer (see
	                                  ///  BRP_LAYERID_*,
	                                  ///  i.e. #BRP_LAYERID_BRP)
);


/**
 * Adds/replaces a protocol layer to a composite protocol.
 *
 * Attention: when adding a protocol to a composite protocol, the composite
 * protocol takes ownership of layer_protocol. Thus layer_protocol must not
 * be freed manually except it is removed from the composite again by
 * brp_detach_layer().
 *
 * If the layer specified by ID is already in use, the previous protocol for
 * this layer will be destroyed and the new layer_protocol will inserted
 * exactly at the same layer as the destroyed protocol (=replace it).
 *
 * If the layer ID is not part of the composite protocol yet,
 * it will be added implicitly at the top of the protocol stack
 * (see brp_add_layer()).
 *
 * If the composite protocol is already opened, the layer protocol will be
 * opened implicitely before being added. In contrary it is invalid to set
 * an already opened layer protocol!
 *
 * @attention: If the @em layer_protocol is a composite on its own, the
 * @em composite_protocol will not take over ownership. This means you have
 * to destroy layer_protocol on your own after composite_protocol was destroyed.
 * Furthermore layer_protocol will not be automaticially opened/closed in this
 * case.
 */
BRP_LIB brp_errcode brp_set_layer
(
	brp_protocol composite_protocol,  ///< composite where layer shall be added
	brp_layer_id layer_id,            ///< identification of layer (see
	                                  ///  BRP_LAYERID_*,
	                                  ///  i.e. #BRP_LAYERID_BRP)
	brp_protocol layer_protocol       ///< new layer protocol. Must not be NULL!
);


/**
 * Retrieves a protocol layer from a composite protocol.
 *
 * @returns
 * the protocol with is identified by layer_id or NULL if not found.
 */
BRP_LIB brp_protocol brp_get_layer
(
	brp_protocol composite_protocol,  ///< composite where layer shall be
	                                  ///  retrieved
	brp_layer_id layer_id             ///< identification of layer (see
	                                  ///  BRP_LAYERID_*,
	                                  ///  i.e. #BRP_LAYERID_BRP)
);


/**
 * Removes a protocol from a composite protocol stack without destroying.
 *
 * After calling this function, the application is responsible for destroying
 * the returned protocol object (expect it was NULL)!
 *
 * This function ensures, that the detached protocol will be closed. All other
 * layers will be kept open, except the closed protocol was the I/O layer.
 * In the latter case the other protocols will be closed, too.
 *
 * The protocol layer will
 * keep intact, so that you can insert another protocol at exactly the same
 * position, later when specifing the same layer_id.
 *
 * @returns
 * The protocol previously attached to the specified layer ID. If the layer ID
 * is not used yet, or set to NULL, NULL will be returned.
 */
BRP_LIB brp_protocol brp_detach_layer
(
	brp_protocol composite_protocol,   ///< composite protocol to where layer
	                                   ///  shall be removed from
	brp_layer_id layer_id              ///< identification of layer (see
	                                   ///  BRP_LAYERID_*,
	                                   ///  i.e. #BRP_LAYERID_BRP) which
	                                   ///  protocol shall be detached
);


/**
 * Assigns an I/O protocol to a composite protocol (protocol stack).
 *
 * This is similar to the following call:
 *
 *     brp_set_layer(protocol, BRP_LAYERID_IO, io_protocol).
 *
 * Attention: In contrary to brp_set_layer 'io_protocol' will be destroyed
 * if this call fails for some reason
 * (brp_destroy() must not be called in this case)!
 */
BRP_LIB brp_errcode brp_set_io
(
	brp_protocol protocol,    ///< the composite protocol, which I/O shall
	                          ///  be set.
	brp_protocol io_protocol  ///< the new I/O protocol of the composite prot.
);


/**
 * Assigns a crypto protocol to a composite protocol (protocol stack).
 *
 * This is similar to the following call:
 *
 *     brp_set_layer(protocol, BRP_LAYERID_CRYPTO, crypto_protocol).
 *
 * Attention: In contrary to brp_set_layer, 'crypto_protocol' will be destroyed
 * if this call fails for some reason
 * (brp_destroy() must not be called in this case)!
 */
BRP_LIB brp_errcode brp_set_crypto
(
	brp_protocol composite_protocol, ///< the composite protocol, where a crypto layer shall be added to
	brp_protocol crypto_protocol  ///< the crypto protocol that shall be layered
	                              ///  on top of 'protocol'.
);


/**
 * Disables the <a href="https://docs.baltech.de/developers/analyze-communication.html" target="_blank">monitoring feature</a>
 * of this library.
 *
 * This is primarily needed to ensure that sensitive information exchanged
 * between application and reader can't even be seen by the local user.
 *
 * @attention: Please note that even if the communication between
 * application and reader is encrypted, the monitor always logs plain text data.
 *
 * @return #BRP_OK on success or #BRP_ERR_INVALID_API_CALL if protocol is not
 * a composite or monitor was already disabed.
 */
BRP_LIB brp_errcode brp_suppress_monitoring(brp_protocol protocol);


/**
 * @cond INTERNAL
 */

/**
 * Retrieve a reference to a specific protocol ID, no matter if the passed
 * protocol is a composite protocol which contains the specified protocol ID,
 * or if it is the protocol ID on its own.
 */
brp_protocol require_protocol
(
	brp_protocol protocol,
	int protocol_id,
	brp_layer_id layer_id
);


/**
 * @endcond
 */


#endif

/** @} */ // end of defgroup brp_lib
