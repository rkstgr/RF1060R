/**
 * @file
 * @anchor CardEmu
 * This command group allows to emulate an ISO 14443-3 card.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_CARDEMU_H__
#define __BRP_BALTECH_API_CMDS_CARDEMU_H__
#include "../typedefs.h"
/**
 * @anchor CardEmu_CardemuErrNoTag
 * No tag error.
 */
#define BRP_CardEmu_CardemuErrNoTag BRP_ERR_STATUS(0x4700, 0x01)
/**
 * @anchor CardEmu_CardemuErrCollision
 * Collision occurred (status value will be stored with bit position of collision
 * in high nibble).
 */
#define BRP_CardEmu_CardemuErrCollision BRP_ERR_STATUS(0x4700, 0x02)
/**
 * @anchor CardEmu_CardemuErrHf
 * General HF error.
 */
#define BRP_CardEmu_CardemuErrHf BRP_ERR_STATUS(0x4700, 0x04)
/**
 * @anchor CardEmu_CardemuErrFrame
 * Bit error, parity error or frame error (start /stop bit).
 */
#define BRP_CardEmu_CardemuErrFrame BRP_ERR_STATUS(0x4700, 0x07)
/**
 * @anchor CardEmu_CardemuErrCrc
 * CRC checksum error.
 */
#define BRP_CardEmu_CardemuErrCrc BRP_ERR_STATUS(0x4700, 0x08)
/**
 * @anchor CardEmu_CardemuErrCom
 * Communication error uC - reader chip.
 */
#define BRP_CardEmu_CardemuErrCom BRP_ERR_STATUS(0x4700, 0x10)
/**
 * @anchor CardEmu_CardemuErrBuflen
 * Remaining data in FIFO / FIFO overflow.
 */
#define BRP_CardEmu_CardemuErrBuflen BRP_ERR_STATUS(0x4700, 0x11)
/**
 * @anchor CardEmu_CardemuErrTimeout
 * Timeout occurred while waiting for card / APDU command.
 */
#define BRP_CardEmu_CardemuErrTimeout BRP_ERR_STATUS(0x4700, 0x3F)
/**
 * @anchor CardEmu_GetMaxFrameSize
 * This command returns the maximum size of a single ISO14443-3 frame that may be
 * sent/received via [CardEmu.StartEmu](@ref CardEmu_StartEmu) or
 * [CardEmu.TransparentCmd](@ref CardEmu_TransparentCmd).
 * 
 * @param[in] protocol used to execute the command
 * @param[out] MaxFrameSize Maximum size of a single frame.
 */
brp_errcode brp_CardEmu_GetMaxFrameSize(brp_protocol protocol, unsigned* MaxFrameSize);
/**
 * @anchor CardEmu_StartEmu
 * Switch to Passive mode and wait for a ISO1443-3a Request/Anticoll/Select
 * sequence and receive the first frame.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Snr Serial number of card to emulate (first Byte has to be 0x08).
 * @param[in] ATQA Attention: When transferred via HF, the ATQA is sent LSB (instead of the MSB order used here).
 * @param[in] SAK Select Acknowledge (SAK), according to the ISO 14443-3 (Type A) standard.
 * @param[in] Timeout Maximum time to wait for a Request.
 * @param[out] FirstCmd First ISO14443-3 command sent from the remote reader.
 * @param[out] FirstCmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 * @deprecated This command may be removed in future!
 */
brp_errcode brp_CardEmu_StartEmu(brp_protocol protocol, brp_buf Snr, unsigned ATQA, unsigned SAK, unsigned Timeout, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool);
/**
 * @anchor CardEmu_TransparentCmd
 * Sends a response to the command returned by
 * [CardEmu.StartEmu](@ref CardEmu_StartEmu) or to the command returned by the last
 * [CardEmu.TransparentCmd](@ref CardEmu_TransparentCmd).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Rsp Response that should be sent to the remote reader as reply to the last command.
 * @param[in] Rsp_len 
 * @param[in] Timeout Maximum time to wait for a Request.
 * @param[out] Cmd Next ISO14443-3 command received from the remote reader.
 * @param[out] Cmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_CardEmu_TransparentCmd(brp_protocol protocol, brp_buf Rsp, size_t Rsp_len, unsigned Timeout, brp_buf* Cmd, size_t* Cmd_len, brp_mempool *mempool);
/**
 * @anchor CardEmu_GetExternalHfStatus
 * Returns _true_ if an external HF field is detected.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ExtFieldStat 
 */
brp_errcode brp_CardEmu_GetExternalHfStatus(brp_protocol protocol, unsigned* ExtFieldStat);
/**
 * @anchor CardEmu_StartNfc
 * Switch to Passive mode and wait for an NFC powerup sequence
 * 
 * @param[in] protocol used to execute the command
 * @param[in] NfcAPassiv enables NFC-A passive mode - command terninates after receiving the RATS command.
 * @param[in] Snr 4 byte serial number of card to emulate.
 * @param[in] ATQA Attention: When transferred via HF, the ATQA is sent LSB (instead of the MSB order used here).
 * @param[in] SAK Select Acknowledge (SAK), according to the ISO 14443-3 (Type A) standard.
 * @param[in] Timeout Maximum time to wait for a Request.
 * @param[out] FirstCmd First ISO14443 command sent from the remote reader.
 * @param[out] FirstCmd_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_CardEmu_StartNfc(brp_protocol protocol, bool NfcAPassiv, brp_buf Snr, unsigned ATQA, unsigned SAK, unsigned Timeout, brp_buf* FirstCmd, size_t* FirstCmd_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
