/**
 * @file
 * @anchor Lic
 * This command group contains commands related to license management.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_LIC_H__
#define __BRP_BALTECH_API_CMDS_LIC_H__
#include "../typedefs.h"
/**
 * @anchor Lic_ErrNoLicCard
 * No valid LicenseCard detected.
 */
#define BRP_Lic_ErrNoLicCard BRP_ERR_STATUS(0x0B00, 0x01)
/**
 * @anchor Lic_ErrAccess
 * Card cannot be accessed (e.g. card was removed too early).
 */
#define BRP_Lic_ErrAccess BRP_ERR_STATUS(0x0B00, 0x02)
/**
 * @anchor Lic_ErrNotSupported
 * The license type of the presented LicenseCard isn't supported by the reader
 * hardware or firmware.  
 * _Example:_ Readers without 125 kHz interface don't support LicenseCards
 * containing [Prox licenses](https://docs.baltech.de/installation/deploy-
 * license.html).
 */
#define BRP_Lic_ErrNotSupported BRP_ERR_STATUS(0x0B00, 0x03)
/**
 * @anchor Lic_ErrAlreadyActive
 * A license of this type is already activated on the reader.
 */
#define BRP_Lic_ErrAlreadyActive BRP_ERR_STATUS(0x0B00, 0x04)
/**
 * @anchor Lic_ErrNoFreeLicense
 * The LicenseCard contains no free license.
 */
#define BRP_Lic_ErrNoFreeLicense BRP_ERR_STATUS(0x0B00, 0x05)
/**
 * @anchor Lic_ErrActivation
 * The license couldn't be activated on the reader.  
 * 
 * **Please[ get in touch](https://docs.baltech.de/support/contact-support.html)
 * with us.**
 */
#define BRP_Lic_ErrActivation BRP_ERR_STATUS(0x0B00, 0x06)
/**
 * @anchor Lic_GetLicenses
 * This command retrieves a bit mask of the licenses that are activated on the
 * reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LicenseBitMask License bit mask
 */
brp_errcode brp_Lic_GetLicenses(brp_protocol protocol, brp_LicenseBitMask* LicenseBitMask);
/**
 * @anchor Lic_ReadLicCard
 * This command reads and evaluates a LicenseCard.
 * 
 * A license is debited from the card and activated on the reader if the
 * following applies:
 * 
 *   * The presented card is a valid LicenseCard.
 *   * This license type is supported by the reader.
 *   * A license of this type is not yet activated on the reader.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Lic_ReadLicCard(brp_protocol protocol);
#endif
/**
 * @}
 */
