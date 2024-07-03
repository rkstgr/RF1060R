/**
 * @file
 * @anchor TTF
 * Command to read 125kHz TTF (tag talks first) cards.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_TTF_H__
#define __BRP_BALTECH_API_CMDS_TTF_H__
#include "../typedefs.h"
/**
 * @anchor TTF_ErrTtfNoTag
 * No tag error.
 */
#define BRP_TTF_ErrTtfNoTag BRP_ERR_STATUS(0x3400, 0x01)
/**
 * @anchor TTF_ErrTtfRxdata
 * Wrong length or wrong data.
 */
#define BRP_TTF_ErrTtfRxdata BRP_ERR_STATUS(0x3400, 0x03)
/**
 * @anchor TTF_ErrTtfParam
 * Wrong cmd param.
 */
#define BRP_TTF_ErrTtfParam BRP_ERR_STATUS(0x3400, 0x07)
/**
 * @anchor TTF_ErrTtfOvTo
 * ISR buffer overflow during receive.
 */
#define BRP_TTF_ErrTtfOvTo BRP_ERR_STATUS(0x3400, 0x08)
/**
 * @anchor TTF_ErrTtfHfreqctrl
 * Another task requested control over HF via hf_request_control.
 */
#define BRP_TTF_ErrTtfHfreqctrl BRP_ERR_STATUS(0x3400, 0x09)
/**
 * @anchor TTF_ErrTtfHw
 * Platform ID missing or hardware error.
 */
#define BRP_TTF_ErrTtfHw BRP_ERR_STATUS(0x3400, 0x0A)
/**
 * @anchor TTF_ErrTtfHwNotSupported
 * Hardware not supported.
 */
#define BRP_TTF_ErrTtfHwNotSupported BRP_ERR_STATUS(0x3400, 0x0C)
/**
 * @anchor TTF_ReadByteStream
 * Returns raw data of the 125 kHz HF interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ResetDataPtr Resets data pointer and starts sampling.
 * @param[in] SamplingTime For ID-engine X: If different from 0, this parameter starts new sampling.   For ID-engine Z: Dummy value
 * @param[in] Rxlen Number of Bytes to receive.
 * @param[in] RxMod Decoder settings - for ID-engine Z use SMPL.
 * @param[out] Data 
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_TTF_ReadByteStream(brp_protocol protocol, bool ResetDataPtr, unsigned SamplingTime, unsigned Rxlen, brp_TTF_ReadByteStream_RxMod RxMod, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor TTF_IdteckRead
 * Returns data of idteck tags (read only tag).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Data Idteck data.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_TTF_IdteckRead(brp_protocol protocol, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
