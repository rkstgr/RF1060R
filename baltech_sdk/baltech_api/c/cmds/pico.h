/**
 * @file
 * @anchor Pico
 * Picopass card commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_PICO_H__
#define __BRP_BALTECH_API_CMDS_PICO_H__
#include "../typedefs.h"
/**
 * @anchor Pico_ErrNoTag
 * No PICC
 */
#define BRP_Pico_ErrNoTag BRP_ERR_STATUS(0x1A00, 0x01)
/**
 * @anchor Pico_ErrCollision
 * Collision occurred (value will be ordered with bit position of collision in
 * high nibble!)
 */
#define BRP_Pico_ErrCollision BRP_ERR_STATUS(0x1A00, 0x02)
/**
 * @anchor Pico_ErrHf
 * General HF error
 */
#define BRP_Pico_ErrHf BRP_ERR_STATUS(0x1A00, 0x04)
/**
 * @anchor Pico_ErrFrame
 * Bit error, parity error or frame error (start/stop-bit)
 */
#define BRP_Pico_ErrFrame BRP_ERR_STATUS(0x1A00, 0x07)
/**
 * @anchor Pico_ErrCrc
 * CRC checksum error
 */
#define BRP_Pico_ErrCrc BRP_ERR_STATUS(0x1A00, 0x08)
/**
 * @anchor Pico_ErrCom
 * Communication error UC - reader chip
 */
#define BRP_Pico_ErrCom BRP_ERR_STATUS(0x1A00, 0x10)
/**
 * @anchor Pico_ErrCardNotSupported
 * Reader chip does not support card type
 */
#define BRP_Pico_ErrCardNotSupported BRP_ERR_STATUS(0x1A00, 0x22)
/**
 * @anchor Pico_ErrHwNotSupported
 * Command not supported by hardware
 */
#define BRP_Pico_ErrHwNotSupported BRP_ERR_STATUS(0x1A00, 0x23)
/**
 * @anchor Pico_SetHfMode
 * Specify HF communication mode that should be used by the commands in this
 * command-set.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] HfMode 
 */
brp_errcode brp_Pico_SetHfMode(brp_protocol protocol, unsigned HfMode);
/**
 * @anchor Pico_RequestAnticoll
 * Request PICCs and perform anticollision.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ASNB Anticollision serial number of PICC
 * @param[out] ASNB_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Pico_RequestAnticoll(brp_protocol protocol, brp_buf* ASNB, size_t* ASNB_len, brp_mempool *mempool);
/**
 * @anchor Pico_Select
 * Select PICC.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ASNB Anticollision serial number of PICC
 * @param[in] ASNB_len 
 * @param[out] Serial Effective serial number of PICC
 * @param[out] Serial_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Pico_Select(brp_protocol protocol, brp_buf ASNB, size_t ASNB_len, brp_buf* Serial, size_t* Serial_len, brp_mempool *mempool);
/**
 * @anchor Pico_Halt
 * Set PICC to halt mode.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Pico_Halt(brp_protocol protocol);
/**
 * @anchor Pico_SelectBookPage
 * Selects book and page of a selected picopass label
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Book 
 * @param[in] Page 
 * @param[out] Page1 
 * @param[out] Page1_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Pico_SelectBookPage(brp_protocol protocol, unsigned Book, unsigned Page, brp_buf* Page1, size_t* Page1_len, brp_mempool *mempool);
/**
 * @anchor Pico_Authenticate
 * Authenticates a previously selected picopass label
 * 
 * @param[in] protocol used to execute the command
 * @param[in] IsDebitKey 
 * @param[in] KeyIdx 
 */
brp_errcode brp_Pico_Authenticate(brp_protocol protocol, bool IsDebitKey, unsigned KeyIdx);
/**
 * @anchor Pico_Read
 * Reads a picopass label
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageAdr 
 * @param[in] PageNr 
 * @param[out] PageData 
 * @param[out] PageData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Pico_Read(brp_protocol protocol, unsigned PageAdr, unsigned PageNr, brp_buf* PageData, size_t* PageData_len, brp_mempool *mempool);
/**
 * @anchor Pico_Write
 * Writes to picopass label
 * 
 * @param[in] protocol used to execute the command
 * @param[in] PageAdr 
 * @param[in] PageData 
 * @param[in] PageData_len 
 */
brp_errcode brp_Pico_Write(brp_protocol protocol, unsigned PageAdr, brp_buf PageData, size_t PageData_len);
#endif
/**
 * @}
 */
