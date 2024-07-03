/**
 * @file
 * @anchor Legic
 * This command group provides access to the _LEGIC_ card system. LEGIC cards can
 * be distinguished into two generations: the state-of-the-art LEGIC advant
 * technology, which is based on ISO 14443 and ISO 15693 standards, and the still
 * widely-used predecessor LEGIC prime technology. Both are supported.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_LEGIC_H__
#define __BRP_BALTECH_API_CMDS_LEGIC_H__
#include "../typedefs.h"
/**
 * @anchor Legic_ErrCommunication
 * Communication error.
 * 
 * Command could not be executed successfully due to a error in the communication
 * of the reader controller with the LEGIC chip (e.g. checksum error, internal
 * timeout error). It is recommended to repeat the command.
 */
#define BRP_Legic_ErrCommunication BRP_ERR_STATUS(0x1E00, 0x01)
/**
 * @anchor Legic_ErrNotInitialized
 * LEGIC support is not initialized yet.
 * 
 * After powering up, the LEGIC chip normally needs several 100 milliseconds
 * until it is ready to execute commands. As long as the reader returns this
 * status code the command needs to be repeated.
 * 
 * If the LEGIC chip is still not available 3.5 seconds after the reader has
 * powered up, usually due to a hardware defect, the _Rf13MHzLegic_ boot status
 * of the Baltech reader will be set (The Baltech reader boot status can be read
 * using the [Sys.GetBootStatus](@ref Sys_GetBootStatus) command).
 */
#define BRP_Legic_ErrNotInitialized BRP_ERR_STATUS(0x1E00, 0x02)
/**
 * @anchor Legic_ErrNotAssembled
 * No LEGIC reader chip is assembled on this hardware.
 * 
 * This reader device doesn't support LEGIC. Please check the model number.
 */
#define BRP_Legic_ErrNotAssembled BRP_ERR_STATUS(0x1E00, 0x03)
/**
 * @anchor Legic_TransparentCommand4000
 * Transparent command to directly access the LEGIC reader chip modules from the
 * 4000 series, e.g. the SM-4200 or SM-4500.
 * 
 * Every command which is defined in the LEGIC documentation for the SM-4x00 chip
 * may be executed using this pass-through command.
 * 
 * For the direct communication with the SM-4x00 LEGIC defines a protocol frame
 * that consists of the following fields (refer also to LEGIC documentation):
 * 
 * LEN  |  CMD  |  DATA[]  |  CRC   
 * ---|---|---|---  
 *   
 * The reader firmware handles this frame protocol internally by calculating and
 * appending the LEN and CRC fields automatically. The host application only
 * specifies the fields CMD and DATA in the transparent command parameters.
 * 
 * The protocol frame for the response consists of the following fields:
 * 
 * LEN  |  CMD  |  STAT  |  DATA[]  |  CRC   
 * ---|---|---|---|---  
 *   
 * Similar to the command frame protocol also the response frame protocol is
 * handled by the reader firmware. It verifies the CRC checksum and removes the
 * LEN, CMD and CRC fields. Only STAT and DATA are returned to the host.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCode Command code of command to be executed.  This parameter equals the parameter CMD in the LEGIC documentation.
 * @param[in] CmdParams Command specific parameter bytes.  This parameter contains all command related parameters also referred to as DATA. Please don't mix the preceding length value up with the LEN field in the LEGIC documentation!
 * @param[in] CmdParams_len 
 * @param[in] Timeout Command execution timeout in ms.  The parameter specifies the maximum time the device should wait for a response from the SM4x00 before it interrupts command execution and returns a status message. The required value is not specified exactly by LEGIC. It depends on the particular command and its parameters. In case the reader returns the BRP status code Lga.ErrCommunication the selected timeout might be too small.
 * @param[out] Status The received SM4x00 specific status code.  This response parameter equals the parameter STAT in the LEGIC documentation.
 * @param[out] Resp The received command response bytes.  Please don't mix the preceding length value up with the LEN field in the LEGIC documentation!
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Legic_TransparentCommand4000(brp_protocol protocol, unsigned CmdCode, brp_buf CmdParams, size_t CmdParams_len, unsigned Timeout, unsigned* Status, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
