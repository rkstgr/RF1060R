/**
 * @file
 * This file provides a I/O protocol object for accessing RS232 Ports/CDC based
 * USB devices.
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */

#ifndef __RS232_PROTOCOL_H__
#define __RS232_PROTOCOL_H__


#include "protocol.h"


/**
 * Creates a protocol object for RS232/CDC interfaces from the device name.
 *
 * Please note that the device name is operating system dependend:
 *
 * - Windows: It is a consecutively numbered filename starting with
 *            ``\\.\COM1`` (or alternatively ``COM1``).
 * - Linux: It is a consecutively numbered filename starting either with
 *          ``/dev/ttyS0`` (in case the reader is connected to the build-in
 *          RS232 interface of the PC) or ``/dev/ttyACM0`` (in case the
 *          reader is connected via USB/CDC). The short filename is
 *          like ``ttyS0``/``ttyACM0``.
 * - macOS: only USB/CDC is supported. the device name is like
 *          ``/dev/tty.usbmodem12345678``, where the last 8 digits
 *          correspond to the readers serialnumber. The short filename
 *          is like ``tty.usbmodem12345678``
 *
 * @param dev_name: the full (or short) device name of the serial interface.
 * @param baudrate: i.e. 9600 or 115200
 * @param parity: has to be 'N', 'E' or 'O'
 * @return a protocol, that can be used for sessions or NULL, if out of memory.
 */
BRP_LIB brp_protocol brp_create_rs232(char * dev_name, unsigned baudrate,
	char parity);


#endif

/** @} */ // end of defgroup brp_lib
