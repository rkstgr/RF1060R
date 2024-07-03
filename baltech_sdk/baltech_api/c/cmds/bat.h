/**
 * @file
 * @anchor Bat
 * This command group allows to run multiple commands in a single batch.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_BAT_H__
#define __BRP_BALTECH_API_CMDS_BAT_H__
#include "../typedefs.h"
/**
 * @anchor Bat_ErrSkipped
 * This command was skipped, since condition bits did not match.
 */
#define BRP_Bat_ErrSkipped BRP_ERR_STATUS(0x4600, 0x90)
/**
 * @anchor Bat_Run
 * Run a batch of BRP commands Via condition bits, it is possible to run sub-
 * commands selectively. When this command is started, all condition bits are
 * reset to 0. Currently, there are no commands that support setting condition
 * bits!
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SubCmds 
 * @param[in] SubCmds_len 
 * @param[out] Rsps 
 * @param[out] Rsps_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Bat_Run(brp_protocol protocol, brp_Bat_Run_SubCmds_Entry* SubCmds, size_t SubCmds_len, brp_Bat_Run_Rsps_Entry** Rsps, size_t* Rsps_len, brp_mempool *mempool);
/**
 * @anchor Bat_CheckStatus
 * This command checks the status of the last action-sub-command (i.e. sub-
 * command that did not start with "Check..."). Depending on the result it sets
 * (or clears, if _Invert_ is _true_) a condition bit.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CondBitNdx Has to be a value between 0 and 15, that identifies the condition bit that shall be updated.
 * @param[in] StatusCodes 
 * @param[in] StatusCodes_len 
 * @param[in] Invert if True, the status code must not one of the codes in _StatusCode_.
 */
brp_errcode brp_Bat_CheckStatus(brp_protocol protocol, unsigned CondBitNdx, unsigned* StatusCodes, size_t StatusCodes_len, bool Invert);
/**
 * @anchor Bat_CheckAny
 * This command checks if one or more of a list of condition bits is set.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CondBitNdx Has to be a value between 0 and 15 that identifies the condition bit that shall be updated.
 * @param[in] CondBits This bit mask identifies all bits that must be checked (at least one of them has to be true).
 * @param[in] Invert If _true_ , inverts the effect of the bits of the _CondBits_ variable.
 */
brp_errcode brp_Bat_CheckAny(brp_protocol protocol, unsigned CondBitNdx, unsigned CondBits, bool Invert);
/**
 * @anchor Bat_CheckTemplate
 * This command checks if the result of the last action-sub-command (i.e. sub-
 * command that did not start with "Check...") matches a template. Depending on
 * the result it sets (or clears, if _Invert_ is _true_) a condition bit.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CondBitNdx Has to be a value between 0 and 15, that identifies the condition bit that shall be updated.
 * @param[in] Template This is a Byte sequence that has to match the response of the last action command.
 * @param[in] Template_len 
 * @param[in] FieldBitLens Every even entry specifies an amount of bits, that are relevant and have to match to _Template_. Every odd entry specifies an amount of bits that may be ignored. For instance, 8, 16, 8, 16 means that out of a 6 Byte response, only Bytes 0 and 3 are relevant and have to match _Template_.  If the amount of entries is even, the rest has to match exactly to the rest of the template. If the amount of entries is odd, the rest is irrelevant. The bits within a single Byte are interpreted MSB (i.e. bit 0 of 0x80 is 1, bits 1-7 of 0x80 are 0).
 * @param[in] FieldBitLens_len 
 * @param[in] Invert if _true_ , the result is inverted.
 */
brp_errcode brp_Bat_CheckTemplate(brp_protocol protocol, unsigned CondBitNdx, brp_buf Template, size_t Template_len, unsigned* FieldBitLens, size_t FieldBitLens_len, bool Invert);
/**
 * @anchor Bat_Delay
 * Delays execution for a specified amount of ms. This command must only be
 * executed within a batch command. Batch commands including the Bat.Delay
 * command cannot be cancelled by sending data to the reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DelayTime Time to delay in ms.
 */
brp_errcode brp_Bat_Delay(brp_protocol protocol, unsigned DelayTime);
#endif
/**
 * @}
 */
