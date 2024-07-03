/**
 * @file
 * @anchor Dbg
 * This is a command group for getting debug logs.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_DBG_H__
#define __BRP_BALTECH_API_CMDS_DBG_H__
#include "../typedefs.h"
/**
 * @anchor Dbg_DbgErrBusy
 * Still processing last command.
 */
#define BRP_Dbg_DbgErrBusy BRP_ERR_STATUS(0xF300, 0x01)
/**
 * @anchor Dbg_ReadLogs
 * Get next available block of debug data.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LogData 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Dbg_ReadLogs(brp_protocol protocol, char** LogData, brp_mempool *mempool);
/**
 * @anchor Dbg_RunCmd
 * Run a command by emulating the corresponding keypress in
 * DebugCommandInterface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Cmd Command to emulate.
 */
brp_errcode brp_Dbg_RunCmd(brp_protocol protocol, char* Cmd);
#endif
/**
 * @}
 */
