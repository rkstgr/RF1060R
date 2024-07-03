/**
 * @file
 * @anchor I2c
 * This command group enables to access the I2C interface.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_I2C_H__
#define __BRP_BALTECH_API_CMDS_I2C_H__
#include "../typedefs.h"
/**
 * @anchor I2c_ErrI2CRead
 * Error reading from I2C interface.
 */
#define BRP_I2c_ErrI2CRead BRP_ERR_STATUS(0x0800, 0x01)
/**
 * @anchor I2c_ErrI2CWrite
 * Error writing to I2C interface.
 */
#define BRP_I2c_ErrI2CWrite BRP_ERR_STATUS(0x0800, 0x02)
/**
 * @anchor I2c_SetSpeed
 * Set speed of I2C interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] FastMode True if I2C fastmode (400kbit) should be enabled, otherwise normal speed (100kbit) is activated.
 */
brp_errcode brp_I2c_SetSpeed(brp_protocol protocol, bool FastMode);
/**
 * @anchor I2c_Read
 * Read data from I2C interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address I2C device address.
 * @param[in] ReadLen Number of bytes to read.
 * @param[out] ReadData Data read from I2C interface.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_I2c_Read(brp_protocol protocol, unsigned Address, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
/**
 * @anchor I2c_Write
 * Write data to I2C interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address I2C device address.
 * @param[in] WriteData Data to write to I2C interface.
 * @param[in] WriteData_len 
 */
brp_errcode brp_I2c_Write(brp_protocol protocol, unsigned Address, brp_buf WriteData, size_t WriteData_len);
/**
 * @anchor I2c_TxRx
 * Write data and directly after that read from I2C interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address I2C device address.
 * @param[in] CmdData Command Data to write before reading (e.g. start address).
 * @param[in] CmdData_len 
 * @param[in] ReadLen Number of bytes to read.
 * @param[out] ReadData Data read from I2C interface.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_I2c_TxRx(brp_protocol protocol, unsigned Address, brp_buf CmdData, size_t CmdData_len, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
