/**
 * @file
 * @anchor Lga
 * **This command group is legacy! For new developments please use[ Legic command
 * group](@ref Legic) instead.**
 * 
 * Originally this command group provided low-level access to the first LEGIC
 * advant compatible reader chip generation, the SC-2560. Due to the
 * discontinuation of this chip in the year 2014 the support of the command group
 * has been limited to the transparent command, which not only allows direct
 * access to the former SC-2560, but also to the follow-up reader chip generation
 * SM-4x00.
 * 
 * Please consult the official LEGIC documentation for the available command
 * codes and parameters.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_LGA_H__
#define __BRP_BALTECH_API_CMDS_LGA_H__
#include "../typedefs.h"
/**
 * @anchor Lga_ErrNotag
 * No LEGIC Advant/Prime card found in the reader's HF field or communication
 * with card lost.
 */
#define BRP_Lga_ErrNotag BRP_ERR_STATUS(0x1200, 0x01)
/**
 * @anchor Lga_ErrLegic
 * The LEGIC reader chip returned an error code.
 * 
 * The LEGIC reader reported an error that occurred during command execution. The
 * actual LEGIC status code appears in the response parameter.
 */
#define BRP_Lga_ErrLegic BRP_ERR_STATUS(0x1200, 0x02)
/**
 * @anchor Lga_ErrCommunication
 * Communication error.
 * 
 * Command could not be executed successfully due to a error in the communication
 * of the reader controller with the LEGIC chip (e.g. checksum error, internal
 * timeout error). It is recommended to repeat the command.
 */
#define BRP_Lga_ErrCommunication BRP_ERR_STATUS(0x1200, 0x03)
/**
 * @anchor Lga_ErrNotInitialized
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
#define BRP_Lga_ErrNotInitialized BRP_ERR_STATUS(0x1200, 0x04)
/**
 * @anchor Lga_ErrNotAssembled
 * No LEGIC reader chip is assembled on this hardware.
 * 
 * This reader device doesn't support LEGIC. Please check the model number.
 */
#define BRP_Lga_ErrNotAssembled BRP_ERR_STATUS(0x1200, 0x05)
/**
 * @anchor Lga_TransparentCommand
 * Transparent command to directly access the Legic reader chip module.
 * 
 * Every command which is defined in the LEGIC documentation for the SC-2560
 * module or the SM-4x00 chip may be executed using this pass-through command.
 * 
 * For the direct communication with the reader chips SC-2560 or SM-4x00 LEGIC
 * defines a protocol frame that consists of the following fields (refer also to
 * LEGIC documentation):
 * 
 * NUMBER OF BYTES/LEN  |  CMD  |  DATA[]  |  LRC/CRC   
 * ---|---|---|---  
 *   
 * The reader firmware handles this frame protocol internally by calculating and
 * appending the NUMBER OF BYTES/LEN and LRC/CRC fields automatically. The host
 * application only specifies the fields CMD and DATA in the transparent command
 * parameters.
 * 
 * The protocol frame for the response consists of the following fields:
 * 
 * NUMBER OF BYTES/LEN  |  CMD  |  STAT  |  DATA[]  |  LRC/CRC   
 * ---|---|---|---|---  
 *   
 * Similar to the command frame protocol also the response frame protocol is
 * handled by the reader firmware. It verifies the CRC checksum and removes the
 * NUMBER OF BYTES/LEN, CMD and LRC/CRC fields. Only STAT and DATA are returned
 * to the host.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCode Reader chip specific command code.  This parameter equals the parameter CMD in the LEGIC documentation.
 * @param[in] CmdParams Command specific parameter bytes.  This parameter contains all command related parameters also referred to as DATA. Please don't mix the preceding length value up with the LEN/NUMBER OF BYTES field in the LEGIC documentation!
 * @param[in] CmdParams_len 
 * @param[in] Timeout Command execution timeout in ms.  The parameter specifies the maximum time the device should wait for a response from the reader chip before it interrupts command execution and returns a status message. Required value is not specified exactly by LEGIC. It depends on the particular command and its parameters. In case the reader returns the BRP status code Lga.ErrCommunication the selected timeout might be too small.
 * @param[out] Status The received reader chip specific status code.  This response parameter equals the parameter STAT in the LEGIC documentation.  This field is only available in the response frame if the returned BRP status code equals 0x00 or Lga.ErrLegic!
 * @param[out] Resp The received command response bytes.  Please don't mix the preceding length value up with the LEN/NUMBER OF BYTES field in the LEGIC documentation!  This parameter is only available in the response frame if the returned BRP status code equals 0x00!
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_Lga_TransparentCommand(brp_protocol protocol, unsigned CmdCode, brp_buf CmdParams, size_t CmdParams_len, unsigned Timeout, unsigned* Status, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
