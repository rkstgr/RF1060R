/**
 * @file
 * @anchor Felica
 * These are FeliCa card low-level commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_FELICA_H__
#define __BRP_BALTECH_API_CMDS_FELICA_H__
#include "../typedefs.h"
/**
 * @anchor Felica_ErrFelicaNoTag
 * No PICC in HF field.
 */
#define BRP_Felica_ErrFelicaNoTag BRP_ERR_STATUS(0x1C00, 0x01)
/**
 * @anchor Felica_ErrFelicaHf
 * PICC-reader communication error.
 */
#define BRP_Felica_ErrFelicaHf BRP_ERR_STATUS(0x1C00, 0x04)
/**
 * @anchor Felica_ErrFelicaFrame
 * Bit error, parity error or frame error.
 */
#define BRP_Felica_ErrFelicaFrame BRP_ERR_STATUS(0x1C00, 0x07)
/**
 * @anchor Felica_ErrFelicaCom
 * Communication error uC - reader chip.
 */
#define BRP_Felica_ErrFelicaCom BRP_ERR_STATUS(0x1C00, 0x10)
/**
 * @anchor Felica_ErrFelicaCardNotSupported
 * Reader chip does not support cardtype-selected baud rate.
 */
#define BRP_Felica_ErrFelicaCardNotSupported BRP_ERR_STATUS(0x1C00, 0x22)
/**
 * @anchor Felica_ErrFelicaHwNotSupported
 * Command not supported by hardware.
 */
#define BRP_Felica_ErrFelicaHwNotSupported BRP_ERR_STATUS(0x1C00, 0x23)
/**
 * @anchor Felica_GenericCmd
 * Generic command for FeliCa.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FastBaud Baudrate PCD-PICC.
 * @param[in] Cmd Command to card.
 * @param[in] Param Parameter of command.
 * @param[in] Param_len 
 * @param[in] Timeout Timeout send PCD and receive PICC.
 * @param[out] Resp Response of command.
 * @param[out] Resp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Felica_GenericCmd(brp_protocol protocol, brp_Felica_GenericCmd_FastBaud FastBaud, unsigned Cmd, brp_buf Param, size_t Param_len, unsigned Timeout, brp_buf* Resp, size_t* Resp_len, brp_mempool *mempool);
/**
 * @anchor Felica_SetUID2
 * Sets UID2 used by generic command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] UID2 Parameter of command.
 */
brp_errcode brp_Felica_SetUID2(brp_protocol protocol, brp_buf UID2);
/**
 * @anchor Felica_Request
 * Polls for tags with number of time slots, returns NFCID2 list of detected tags
 * (maximum 16 / length 8).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FastBaud Baudrate PCD-PICC.
 * @param[in] SystemCode Application ID for PICC preselection, All:0xFFFF.
 * @param[in] RequestCode RequestCode.
 * @param[out] ColFlag True if collision occurs.
 * @param[out] Labels 
 * @param[out] Labels_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Felica_Request(brp_protocol protocol, brp_Felica_Request_FastBaud FastBaud, unsigned SystemCode, unsigned RequestCode, unsigned* ColFlag, brp_Felica_Request_Labels_Entry** Labels, size_t* Labels_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
