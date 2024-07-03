/**
 * @file
 * Implements a "Probe" Protocol, that logs all transferred data to a file.
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */

#ifndef __MONITOR_PROTOCOL_H__
#define __MONITOR_PROTOCOL_H__


#include "protocol.h"


#if !defined(BRP_LOG_DIR_PREFIX)
	#define BRP_LOG_DIR_PREFIX    "brp-logs-"
#endif


/**
 * Creates a new Monitor protocol layer.
 *
 * This protocol layer will log all actions executed to a file and forward them
 * one-to-one to the underlying protocol.
 *
 * @return A BRP protocol on success or NULL on failure.
 */
BRP_LIB brp_protocol brp_create_monitor(void);


#endif //__MONITOR_PROTOCOL_H__

/** @} */ // end of defgroup brp_lib
