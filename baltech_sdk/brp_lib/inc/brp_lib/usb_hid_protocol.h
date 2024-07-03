/**
 * @file
 * This is the adapter for USB devices that are connected via the
 * Human Interface Device (HID) Protocol.
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */


#ifndef __USBHID_CHANNEL_H__
#define __USBHID_CHANNEL_H__


#include "protocol.h"


/**
 * Creates an (USB) HID protocol object from the connected baltech device with
 * serialnumber 'snr'.
 *
 * Please note that this function succeeds no matter if a matching reader is
 * connected or not (If no matching reader is connected brp_open() will fail).
 *
 * If 'snr' is 0 the serialnumber will be detected automaticially. If more
 * than one device is connected to the PC #BRP_ERR_OPEN_IO is returned.
 * When closing the device and reopen it again, the library will guarantee that
 * the same device is connected. If the device was disconnected between
 * brp_close() and brp_open() an #BRP_ERR_OPEN_IO error is returned.
 *
 * @return a protocol object, that can be used for brp_set_io().
 * NULL, if out of memory.
 */
BRP_LIB brp_protocol brp_create_usb_hid(long long snr);


#endif

/** @} */ // end of defgroup brp_lib
