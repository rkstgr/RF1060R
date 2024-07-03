/**
 * @file
 * @anchor UsbHost
 * This command group provides direct access to the USB host functionality of the
 * uC.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_USBHOST_H__
#define __BRP_BALTECH_API_CMDS_USBHOST_H__
#include "../typedefs.h"
/**
 * @anchor UsbHost_UsbhstErrNotconnected
 * No device connected.
 */
#define BRP_UsbHost_UsbhstErrNotconnected BRP_ERR_STATUS(0x4400, 0x01)
/**
 * @anchor UsbHost_UsbhstErrTimeout
 * Device did not respond within Timeout.
 */
#define BRP_UsbHost_UsbhstErrTimeout BRP_ERR_STATUS(0x4400, 0x02)
/**
 * @anchor UsbHost_UsbhstErrNack
 * Device responded only with NACK within Timeout.
 */
#define BRP_UsbHost_UsbhstErrNack BRP_ERR_STATUS(0x4400, 0x03)
/**
 * @anchor UsbHost_UsbhstErrStall
 * Device responded with STALL.
 */
#define BRP_UsbHost_UsbhstErrStall BRP_ERR_STATUS(0x4400, 0x04)
/**
 * @anchor UsbHost_UsbhstErrTransfer
 * Error on transferring data (CRC, Invalid PID, ...).
 */
#define BRP_UsbHost_UsbhstErrTransfer BRP_ERR_STATUS(0x4400, 0x05)
/**
 * @anchor UsbHost_UsbhstErrUnexpectedPkt
 * Device sent unexpected data.
 */
#define BRP_UsbHost_UsbhstErrUnexpectedPkt BRP_ERR_STATUS(0x4400, 0x06)
/**
 * @anchor UsbHost_UsbhstErrBufferoverflow
 * Received too much data.
 */
#define BRP_UsbHost_UsbhstErrBufferoverflow BRP_ERR_STATUS(0x4400, 0x07)
/**
 * @anchor UsbHost_UsbhstErrSetupPipes
 * Failure on setting up pipes.
 */
#define BRP_UsbHost_UsbhstErrSetupPipes BRP_ERR_STATUS(0x4400, 0x20)
/**
 * @anchor UsbHost_Enable
 * Enable/Disable the USB-Host-Interface of the uC.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable Enable/Disable the USB interface.
 */
brp_errcode brp_UsbHost_Enable(brp_protocol protocol, bool Enable);
/**
 * @anchor UsbHost_IsConnected
 * Check if a device is connected.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Connected _true_ if a device is connected.
 */
brp_errcode brp_UsbHost_IsConnected(brp_protocol protocol, bool* Connected);
/**
 * @anchor UsbHost_SetupPipes
 * Setup all Pipes Definitions (uC's internal configuration).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Pipes 
 * @param[in] Pipes_len 
 */
brp_errcode brp_UsbHost_SetupPipes(brp_protocol protocol, brp_UsbHost_SetupPipes_Pipes_Entry* Pipes, size_t Pipes_len);
/**
 * @anchor UsbHost_SetAddr
 * Set Address of device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Sets the address the uC shall use when accessing the device.
 */
brp_errcode brp_UsbHost_SetAddr(brp_protocol protocol, unsigned Address);
/**
 * @anchor UsbHost_Reset
 * Send a Reset via USB interface, Remove all Pipes Definitions and reset address
 * of device to 0.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_UsbHost_Reset(brp_protocol protocol);
/**
 * @anchor UsbHost_TransRawSetup
 * Transfers a raw SETUP packet. Has to be combined with a call of
 * [UsbHost.TransSetupIn](@ref UsbHost_TransSetupIn) or
 * [UsbHost.TransSetupOut](@ref UsbHost_TransSetupOut).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SetupData Data to transfer in SETUP stage.
 * @param[in] PipeNo Number of pipe.
 * @param[in] Timeout Timeout for transaction.
 */
brp_errcode brp_UsbHost_TransRawSetup(brp_protocol protocol, brp_buf SetupData, unsigned PipeNo, unsigned Timeout);
/**
 * @anchor UsbHost_TransSetupIn
 * Transfers a SETUP transaction with a IN DATA stage.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SetupData Data to transfer in SETUP stage.
 * @param[in] PipeNo Number of pipe.
 * @param[in] Timeout Timeout for transaction.
 * @param[out] InData Resulting data.
 * @param[out] InData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_UsbHost_TransSetupIn(brp_protocol protocol, brp_buf SetupData, unsigned PipeNo, unsigned Timeout, brp_buf* InData, size_t* InData_len, brp_mempool *mempool);
/**
 * @anchor UsbHost_TransSetupOut
 * Transfers a SETUP transaction with a OUT DATA stage.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SetupData Data to transfer in SETUP Stage.
 * @param[in] OutData Data to send.
 * @param[in] OutData_len 
 * @param[in] PipeNo Number of pipe.
 * @param[in] Timeout Timeout for transaction.
 */
brp_errcode brp_UsbHost_TransSetupOut(brp_protocol protocol, brp_buf SetupData, brp_buf OutData, size_t OutData_len, unsigned PipeNo, unsigned Timeout);
/**
 * @anchor UsbHost_TransIn
 * Transfers an IN transaction.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PipeNo Number of pipe.
 * @param[in] Timeout Timeout for transaction.
 * @param[out] InData Resulting data.
 * @param[out] InData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_UsbHost_TransIn(brp_protocol protocol, unsigned PipeNo, unsigned Timeout, brp_buf* InData, size_t* InData_len, brp_mempool *mempool);
/**
 * @anchor UsbHost_TransOut
 * Transfers an OUT transaction.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] OutData Data to send.
 * @param[in] OutData_len 
 * @param[in] PipeNo Number of pipe.
 * @param[in] Continue Set to true if this transaction shall be continued.
 * @param[in] Timeout Timeout for transaction.
 */
brp_errcode brp_UsbHost_TransOut(brp_protocol protocol, brp_buf OutData, size_t OutData_len, unsigned PipeNo, bool Continue, unsigned Timeout);
/**
 * @anchor UsbHost_Suspend
 * Send a Suspend via USB interface.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_UsbHost_Suspend(brp_protocol protocol);
/**
 * @anchor UsbHost_Resume
 * Send a Resume via USB interface.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_UsbHost_Resume(brp_protocol protocol);
#endif
/**
 * @}
 */
