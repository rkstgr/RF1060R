/**
 * @file
 * @anchor Sec
 * This command group regroups the commands needed for Advanced Encryption
 * Standard (AES)-based protocol encryption, and to access the reader's internal
 * security system. These mechanisms enable to protect the reader-host
 * communication.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_SEC_H__
#define __BRP_BALTECH_API_CMDS_SEC_H__
#include "../typedefs.h"
/**
 * @anchor Sec_ErrCrypto
 * Invalid key used for encryption/MACing, MAC address invalid, or decrypted data
 * invalid.
 */
#define BRP_Sec_ErrCrypto BRP_ERR_STATUS(0x0700, 0x01)
/**
 * @anchor Sec_ErrTunnel
 * It is not possible to tunnel this command.
 */
#define BRP_Sec_ErrTunnel BRP_ERR_STATUS(0x0700, 0x02)
/**
 * @anchor Sec_GetAcMask
 * This command retrieves the Access Condition Mask of a specified security
 * level.
 * 
 * The Access Condition Mask can be set using the command
 * [Sec.SetAcMask](@ref Sec_SetAcMask) or by loading a reader configuration file
 * which defines the respective configuration values
 * __Device/HostSecurity/AccessConditionMask__.
 * 
 * **In case of security level 0 (plain access) the actual Access Condition Mask
 * that is applied by the reader may deviate from the value which is returned by
 * this command. Refer to[ Sec.GetCurAcMask](@ref Sec_GetCurAcMask) .**
 * 
 * **It is _not_ possible to deny the retrieval of the Access Condition Mask via
 * the "Encryption and Authorization" settings in the configuration. This means
 * that this command will never return the ERR_ACCESS_DENIED status code.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecLevel Security Level to get the Access Condition Mask from. Must be between 0 and 3. If this value is 0xFF, the Access Condition Mask of the current Security Level will be returned.
 * @param[out] AcMask Access Condition Mask of the Security Level specified in the _SecurityLevel_ parameter. Every Feature in this list can be disabled by not setting the corresponding bit.
 */
brp_errcode brp_Sec_GetAcMask(brp_protocol protocol, unsigned SecLevel, brp_HostSecurityAccessConditionBits* AcMask);
/**
 * @anchor Sec_SetAcMask
 * This command sets the Access Condition Mask of the security level specified in
 * the _SecurityLevel_ parameter to the _AcMask_ value.
 * 
 * Alternatively Access Condition Masks may also be set via reader configuration,
 * refer to
 * __Device/HostSecurity/AccessConditionMask__.
 * 
 * **The Access Condition Mask of security level 3 is by definition 0xFFFFFFFF.
 * It can not be restricted.**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecLevel Security Level which needs to be modified (must be between 0 and 3). If this value is 0xFF, the Access Condition Mask of the current Security Level will be modified.
 * @param[in] AcMask New Access Condition Mask. It is not possible to delete the FactoryReset bit with this bitmask (see [Sec.LockReset](@ref Sec_LockReset)) Every Feature in this list can be disabled by not setting the corresponding bit.
 */
brp_errcode brp_Sec_SetAcMask(brp_protocol protocol, unsigned SecLevel, brp_HostSecurityAccessConditionBits AcMask);
/**
 * @anchor Sec_SetKey
 * Sets a key and the appropriate Authorization Mode bits for a specified
 * Security Level.
 * 
 * Please note that if _DeriveKey_ is not 0, Sec.SetKey will not use the _Key_
 * parameter as a new key value for the authentication of security level
 * _SecLevel_ directly. Instead, it encrypts the key specified in _DeriveKey_
 * with the key specified in _Key_ (via AES), and uses this encrypted key as a
 * new key value for the authentication of security level _SecLevel_.
 * 
 * If one or more of the _SessionKey_ , _MACed_ , _Encrypted_ or _ContinuousIV_
 * bits are set, it is not possible to authenticate without the corresponding
 * authentication mode setting.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ContinuousIV If _true_ , encryption/MACing will use Cipher Block Chaining (CBC). In this case, a continuous initial vector (IV) will be used.  If this bit is not set, CBC is not used, i.e. the IV will be reset to all zeros (00 00 ... 00) before every command or response is encrypted/MACed.
 * @param[in] Encrypted Requires that commands running in this security level always have to be encrypted.  **This flag cannot be set at the same time as the _MACed_ flag.**
 * @param[in] MACed Requires that commands running in this security level always have to be MACed.  **This flag cannot be set at the same time as the _Encrypted_ flag.**
 * @param[in] SessionKey Requires a two-phase authentication to be able to enter a security level. This two-phase authentication process needs to be performed using the [Sec.AuthPhase1](@ref Sec_AuthPhase1) and [Sec.AuthPhase2](@ref Sec_AuthPhase2) commands.
 * @param[in] DeriveKey This value specifies a key which will be encrypted by the _Key_ value and used as authentication key for security level _SecLevel_. If this parameter is 0, the authentication key is directly set by the _Key_ parameter.
 * @param[in] SecLevel The security level for which the key has to be set.
 * @param[in] Key Key/Password for authentication of security level _SecLevel_.
 */
brp_errcode brp_Sec_SetKey(brp_protocol protocol, unsigned ContinuousIV, unsigned Encrypted, unsigned MACed, unsigned SessionKey, unsigned DeriveKey, unsigned SecLevel, brp_buf Key);
/**
 * @anchor Sec_AuthPhase1
 * This command initiates a 2-phase authentication. The 2-phase authentication is
 * required for entering a security level, if its Authorization Mode enforces a
 * session key.
 * 
 * In the first phase of the 2-phase authentication, the host sends a random
 * number (_RndA_) to the reader. The reader encrypts this number two times,
 * using AES128 encryption, with the key of the Security Level specified in
 * _SecLevel_ , and sends the result back to the host as _EncRndA_. The host then
 * has to check if the reader encrypted the number correctly. If this is the
 * case, the reader returns the OK status code and the
 * [Sec.AuthPhase2](@ref Sec_AuthPhase2) command can be called to initiate the
 * second phase of the 2-phase authentication procedure.
 * 
 * If _EncRndA_ is invalid, the reader is configured with an invalid key,
 * different from the one expected by the host. In this case, an error status
 * code is returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecLevel The Security Level which needs to be authenticated.
 * @param[in] RndA Random number to be encrypted by reader.
 * @param[out] EncRndA A version of _RndA_ twice encrypted by the reader using the key of the Security Level specified by _SecLevel_.
 * @param[out] RndB A second random number (generated by reader).
 * @param[out] ContinuousIV Requires a contionous IV to avoid replay attacks.
 * @param[out] Encrypted Requires that commands running in this security level always have to be encrypted.  **This flag cannot be set at the same time as the _MACed_ flag.**
 * @param[out] MACed Requires that commands running in this security level always have to be MACed.  **This flag cannot be set at the same time as the _Encrypted_ flag.**
 * @param[out] SessionKey Requires a two-phase authentication to be able to enter a security level. This two-phase authentication process needs to be performed using the Sec.AuthPhase1 and [Sec.AuthPhase2](@ref Sec_AuthPhase2) commands.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Sec_AuthPhase1(brp_protocol protocol, unsigned SecLevel, brp_buf RndA, brp_buf* EncRndA, brp_buf* RndB, bool* ContinuousIV, bool* Encrypted, bool* MACed, bool* SessionKey, brp_mempool *mempool);
/**
 * @anchor Sec_AuthPhase2
 * This command finishes the 2-phase authentication procedure started by the
 * [Sec.AuthPhase1](@ref Sec_AuthPhase1) command. The host has to encrypt the
 * parameter _RndB_ returned by [Sec.AuthPhase1](@ref Sec_AuthPhase1) two times,
 * using AES128 encryption, with the key of the Security Level specified by the
 * _SecLevel_ parameter of [Sec.AuthPhase1](@ref Sec_AuthPhase1). The host then
 * sends the result back to the reader as _EncRndB_.
 * 
 * If _RndB_ was encrypted correctly, the reader returns the OK status code and
 * enters the security level specified in [Sec.AuthPhase1](@ref Sec_AuthPhase1) as
 * parameter _SecLevel_. Depending on the Authentication Mode, the reader enters
 * this Security Level permanently (all subsequent commands are executed in this
 * Security Level) or temporarily (only encrypted/MACed commands are executed in
 * this Security Level). To ensure that the reader enters the Security Level
 * temporarily, one of the _Encrypted_ /_MACed_ flags of the Authentication Mode
 * has to be set. Please refer to the [Sec.SetKey](@ref Sec_SetKey) command for
 * details.
 * 
 * Additionally, the Sec.AuthPhase2 command generates a session key by encrypting
 * the _RndA_ parameter of [Sec.AuthPhase1](@ref Sec_AuthPhase1) and the _RndB_
 * value returned by [Sec.AuthPhase1](@ref Sec_AuthPhase1), _each only once_. The
 * resulting 16 Byte session key is the result of the encryption of the
 * concatenated _RndA_ (first 8 Bytes) and _RndB_ (last 8 Bytes).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] EncRndB _RndB_ value returned by [Sec.AuthPhase1](@ref Sec_AuthPhase1) encrypted twice by the key of Security Level specified by the _SecLevel_ variable of [Sec.AuthPhase1](@ref Sec_AuthPhase1).
 */
brp_errcode brp_Sec_AuthPhase2(brp_protocol protocol, brp_buf EncRndB);
/**
 * @anchor Sec_Tunnel
 * This command enables to send a specific command, called the _tunnelled_
 * command, to the reader (and to receive its response) in an encrypted and/or
 * MACed fashion.
 * 
 * Depending on the values of the _AuthModeAndSecLevel_ bit mask, the tunnelled
 * command will either be encrypted, MACed or both. The structure of the
 * _TunnelledCmd_ parameter and of the _TunnelledResp_ response vary depending on
 * the encryption/MACing behaviour:
 * 
 *   * _Encrypted only_ : 
 *     * The data has to be padded to the next 16 Byte boundary by appending "00"-Bytes. 
 *     * The initial vector (IV) has to be reset to all zeros (00 00 ... 00) if if the _ContinuousIV_ flag is not set. If _ContinuousIV_ is set, Cipher Block Chaining (CBC) will be used in the encryption process. In this case, the result from the last block encryption will be used as IV. 
 * 
 *     * The padded data is encrypted using AES128 in CBC mode. The key for encryption is either the key assigned to the currently selected Security Level or, if the _SessionKey_ flag is set, the session key derived from the values _RndA_ and _RndB_ of the [Sec.AuthPhase1](@ref Sec_AuthPhase1) command: 
 * 
 * _SessionKey = encrypt(RndA[0..7] + RndB[8..15])_
 * 
 *   * _Encrypted and MACed_ : Same as the _encrypted only_ variant, but a number of padding Bytes (at least 8) are appended to the encrypted data before transmission. The receiver always has to check whether the padding Bytes have the 0x00 value. If not, the frame is considered invalid. 
 *   * _MACed only_ : The encryption process is applied to the data which has to be MACed, but unlike in the _encryption only_ mode, the data is not modified. The first 8 Bytes of the hash value resulting from the encryption process (normally used as an IV for the next data block) are simply appended to the original data block to get the MACed data block. 
 * 
 * **This command must not be used in BRP _Repeat Mode_ .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ContinuousIV If _true_ , encryption/MACing will use a continuous IV for CBC mode will be used. That means the state of the IV after the first command will be used as the IV for the second command and so on.  If this bit is not set, the IV will be reset to zeros (00 00 ... 00) before every command or response is encrypted/MACed.
 * @param[in] Encrypted Requires that commands running in this security level always have to be encrypted.
 * @param[in] MACed Requires that commands running in this security level always have to be MACed.
 * @param[in] SessionKey If _true_ , a session key needs to be used instead of a fixed key. A session key can be generated using the 2-phase authentication process triggered by the [Sec.AuthPhase1](@ref Sec_AuthPhase1) and [Sec.AuthPhase2](@ref Sec_AuthPhase2) commands.
 * @param[in] SecLevel The Security Level (0-3), which should be entered when executing the tunnelled command.
 * @param[in] TunnelledCmd Encrypted and/or MACed command. This variable has the following data structure (before encryption):    * _Byte 0 (DeviceCode):_ Device code of the command to tunnel.    * _Byte 1 (CommandCode):_ Command code of the command to tunnel.    * _Byte 2-3 (ParamLen):_ Length of the parameter block of the command to tunnel.   **Unlike standard BRP frames, this parameter is MSB encoded.**    * _Byte 4-x (Param):_ Parameter block of the command to tunnel.    * _Byte x-n (PadByteAndMac):_ Depending on the Authorization Mode flags, these Bytes are either zero-padding bytes (always 0) or a MAC.
 * @param[in] TunnelledCmd_len 
 * @param[out] TunnelledResp Encrypted/MACed response of command. This variable has the following data structure (before encryption):    * _Byte 0 (StatusCode):_ The status code of the command which was tunnelled.    * _Byte 1-2 (RespLen):_ The length of the response block of the command which was tunnelled   **Unlike standard BRP frames, this parameter is MSB encoded.**    * _Byte 3-x (Resp):_ Response block of the command which was tunnelled.    * _Byte x-n (PadByteAndMac):_ Depending on the Authorization Mode flags, these Bytes are either zero-padding bytes (always 0) or a MAC.
 * @param[out] TunnelledResp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Sec_Tunnel(brp_protocol protocol, bool ContinuousIV, bool Encrypted, bool MACed, bool SessionKey, unsigned SecLevel, brp_buf TunnelledCmd, size_t TunnelledCmd_len, brp_buf* TunnelledResp, size_t* TunnelledResp_len, brp_mempool *mempool);
/**
 * @anchor Sec_Reset
 * This command resets the Baltech ID engine's security system. After its
 * execution, all security features will be disabled and the whole memory (i.e.
 * the whole configuration) will be deleted.
 * 
 * Unless a [Sec.LockReset](@ref Sec_LockReset) was executed beforehand, this
 * command runs in every security level. If available, factory settings as well
 * as "Encryption and Authorization" settings are restored.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Sec_Reset(brp_protocol protocol);
/**
 * @anchor Sec_LockReset
 * This command prevents, that a [Sys.FactoryReset](@ref Sys_FactoryReset)
 * is run for the Security Level specified in the _SecLevel_ command. See also
 * [Sec.SetAcMask](@ref Sec_SetAcMask).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SecLevel Security Level which should be locked against the [Sys.Reset](@ref Sys_Reset) command. A value of 0xFF indicates the current Security Level.
 */
brp_errcode brp_Sec_LockReset(brp_protocol protocol, unsigned SecLevel);
/**
 * @anchor Sec_GetCurAcMask
 * This command retrieves the Access Condition Mask, which is applied by the
 * reader in the current context (i.e. security level, protocol).
 * 
 * If this command is executed in security level 1-3 the actual Access Condition
 * Mask is defined by the value which has been set for the particular security
 * level before via [Sec.SetAcMask](@ref Sec_SetAcMask) command respectively the
 * configuration value
 * __Device/HostSecurity/AccessConditionMask__.
 * In this case this command is identical to [Sec.GetAcMask](@ref Sec_GetAcMask) for
 * the respective security level.
 * 
 * In case of security level 0 (plain access) the applied Access Condition Mask
 * is determined by the protocol-specific Access Condition Mask (
 * __Protocols/AccessConditionsBitsStd__,
 * __Protocols/AccessConditionsBitsAlt__).
 * If this value is not available for the particular protocol the reader uses the
 * value that has been set with [Sec.SetAcMask](@ref Sec_SetAcMask) respectively
 * [Device/HostSecurity/AccessConditionMask[0]](../cfg/base.xml#Device.HostSecurity.AccessConditionMask)
 * before in combination (bitwise AND) with a hard-coded default value as
 * fallback; in most cases this default value corresponds to all access rights -
 * for BRP over TCP it is zero.
 * 
 * **It is _not_ possible to deny the retrieval of the Access Condition Mask via
 * the "Encryption and Authorization" settings in the configuration. This means
 * that this command will never return the ERR_ACCESS_DENIED status code.**
 * 
 * @param[in] protocol used to execute the command
 * @param[out] AcMask Current Access Condition Mask. Every Feature in this list can be disabled by not setting the corresponding bit.
 */
brp_errcode brp_Sec_GetCurAcMask(brp_protocol protocol, brp_HostSecurityAccessConditionBits* AcMask);
#endif
/**
 * @}
 */
