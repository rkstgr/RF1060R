/**
 * @file
 * @anchor Crypto
 * This command group regroups the commands needed to use the integrated _crypto-
 * engine_ of the Baltech reader.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_CRYPTO_H__
#define __BRP_BALTECH_API_CMDS_CRYPTO_H__
#include "../typedefs.h"
/**
 * @anchor Crypto_CrptErrInvalidBlock
 * Encrypted block format is invalid.
 */
#define BRP_Crypto_CrptErrInvalidBlock BRP_ERR_STATUS(0x0200, 0x01)
/**
 * @anchor Crypto_CrptErrAuth
 * Internal key cannot be accessed for the specified action due to the access
 * condition flags settings.
 */
#define BRP_Crypto_CrptErrAuth BRP_ERR_STATUS(0x0200, 0x02)
/**
 * @anchor Crypto_CrptErrKeyNotFound
 * Specified key not available in the internal key list.
 */
#define BRP_Crypto_CrptErrKeyNotFound BRP_ERR_STATUS(0x0200, 0x03)
/**
 * @anchor Crypto_CrptErrWriteConfigkey
 * Configuration key cannot be stored in the reader's configuration.
 */
#define BRP_Crypto_CrptErrWriteConfigkey BRP_ERR_STATUS(0x0200, 0x04)
/**
 * @anchor Crypto_CrptErrInvalidKey
 * No valid configuration card key. Since no key is present, the reader is forced
 * to work unencrypted.
 * 
 * **This status code is not supported by Crypto.Encrypt/Crypto.Decrypt commands
 * due to legacy reasons.**
 */
#define BRP_Crypto_CrptErrInvalidKey BRP_ERR_STATUS(0x0200, 0x05)
/**
 * @anchor Crypto_EncryptBlock
 * This command encrypts an 8-Byte data block given in the _Block_ parameter
 * using the SkipJack algorithm. If _KeyIndex_ is set to 0x00, _KeyValue_ will be
 * used as encryption key. Otherwise, _KeyIndex_ is interpreted as the index of
 * the corresponding entry in the internal key list. _KeyIndex_ = 0x01 denotes
 * configuration value 0x81, _KeyIndex_ = 0x02 denotes configuration value 0x82,
 * etc.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of key to use to encrypt data. _KeyIndex_ must be set to 0x00 if a user- defined key, specified in the _KeyValue_ parameter, should be used for encryption.
 * @param[in] KeyValue If _KeyIndex_ is set to 0x00, this value specifies a user-defined encryption key.
 * @param[in] Block Data block to encrypt.
 * @param[out] EncryptedBlock Encrypted data block.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Crypto_EncryptBlock(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf Block, brp_buf* EncryptedBlock, brp_mempool *mempool);
/**
 * @anchor Crypto_DecryptBlock
 * This command decrypts an 8-Byte data block given in the _Block_ parameter
 * using the SkipJack algorithm. If _KeyIndex_ is set to 0x00, _KeyValue_ will be
 * used as encryption key. Otherwise, _KeyIndex_ is interpreted as the index of
 * the corresponding entry in the internal key list. _KeyIndex_ = 0x01 denotes
 * configuration value 0x81, _KeyIndex_ = 0x02 denotes configuration value 0x82,
 * etc.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of key to use to decrypt data. _KeyIndex_ must be set to 0x00 if a user- defined key, specified in the _KeyValue_ parameter, should be used for decryption.
 * @param[in] KeyValue If _KeyIndex_ is set to 0x00, this value specifies a user-defined decryption key.
 * @param[in] Block Data block to decrypt.
 * @param[out] UnencryptedBlock Unencrypted data block after decryption.
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Crypto_DecryptBlock(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf Block, brp_buf* UnencryptedBlock, brp_mempool *mempool);
/**
 * @anchor Crypto_EncryptBuffer
 * This command encrypts a variable length buffer given in the _Buffer_ parameter
 * using the SkipJack algorithm. If _KeyIndex_ is set to 0x00, _KeyValue_ will be
 * used as encryption key. Otherwise, _KeyIndex_ is interpreted as the index of
 * the corresponding entry in the internal key list. _KeyIndex_ = 0x01 denotes
 * configuration value 0x81, _KeyIndex_ = 0x02 denotes configuration value 0x82,
 * etc.
 * 
 * The value returned in the _InitialVector_ variable is necessary for CBC
 * encryption. If large amounts of data must be encrypted, this command has to be
 * called more than once. In this case, the returned _InitialVector_ variable of
 * call _i_ of the command has to be specified as the _InitialVector_ parameter
 * of call _i+1_.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of key to use to encrypt data. _KeyIndex_ must be set to 0x00 if a user- defined key, specified in the _KeyValue_ parameter, should be used for encryption.
 * @param[in] KeyValue If _KeyIndex_ is set to 0x00, this value specifies a user-defined encryption key.
 * @param[in] InitialVector Initial vector (IV) used for encryption.
 * @param[in] Buffer Data buffer to encrypt.
 * @param[in] Buffer_len 
 * @param[out] NextInitialVector Initial vector to be used as _InitialVector_ parameter in the next call of this command.
 * @param[out] EncryptedBuffer Buffer after encryption.
 * @param[out] EncryptedBuffer_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Crypto_EncryptBuffer(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf InitialVector, brp_buf Buffer, size_t Buffer_len, brp_buf* NextInitialVector, brp_buf* EncryptedBuffer, size_t* EncryptedBuffer_len, brp_mempool *mempool);
/**
 * @anchor Crypto_DecryptBuffer
 * This command decrypts a variable length buffer given in the _Buffer_ parameter
 * using the SkipJack algorithm. If _KeyIndex_ is set to 0x00, _KeyValue_ will be
 * used as encryption key. Otherwise, _KeyIndex_ is interpreted as the index of
 * the corresponding entry in the internal key list. _KeyIndex_ = 0x01 denotes
 * configuration value 0x81, _KeyIndex_ = 0x02 denotes configuration value 0x82,
 * etc.
 * 
 * The value returned in the _InitialVector_ variable is necessary for CBC
 * encryption. If large amounts of data must be encrypted, this command has to be
 * called more than once. In this case, the returned _InitialVector_ variable of
 * call _i_ of the command has to be specified as the _InitialVector_ parameter
 * of call _i+1_.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of key to use to decrypt data. _KeyIndex_ must be set to 0x00 if a user- defined key, specified in the _KeyValue_ parameter, should be used for decryption.
 * @param[in] KeyValue If _KeyIndex_ is set to 0x00, this value specifies a user-defined decryption key.
 * @param[in] InitialVector Initial vector (IV) used for decryption.
 * @param[in] Buffer Data buffer to decrypt.
 * @param[in] Buffer_len 
 * @param[out] NextInitialVector Initial vector to be used as _InitialVector_ parameter in the next call of this command.
 * @param[out] UnencryptedBuffer Unencrypted buffer after decryption.
 * @param[out] UnencryptedBuffer_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Crypto_DecryptBuffer(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, brp_buf InitialVector, brp_buf Buffer, size_t Buffer_len, brp_buf* NextInitialVector, brp_buf* UnencryptedBuffer, size_t* UnencryptedBuffer_len, brp_mempool *mempool);
/**
 * @anchor Crypto_BalKeyEncryptBuffer
 * This command is a special version of the
 * [Crypto.EncryptBuffer](@ref Crypto_EncryptBuffer) command which always uses a
 * customer key to encrypt a buffer of data and inserts a Crypto-Key at a desired
 * position before encryption.
 * 
 * The key to insert has to be specified in the _EmbeddedKeyIndex_ parameter. In
 * this case, the 10 Byte Key will, on the one hand, replace the data at the
 * _EmbeddedKeyPos_ position, and on the other hand, replace the last two Bytes
 * by a CRC (16-bit, 8404B, MSB encoded) that is generated on the data contained
 * in _Buffer_.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyVersion 2: use SkipJack Key, 3: Use AES Key.
 * @param[in] EmbeddedKeyIndex Index of the embedded key to insert in the data (value != 0x00). No key is inserted when this parameter is set to 0x00.
 * @param[in] EmbeddedKeyPos If an embedded key is specified, this value specifies the position where to include the key.
 * @param[in] Buffer Data buffer to encrypt.
 * @param[in] Buffer_len 
 * @param[in] InitialVector Initial vector (IV) used for encryption.
 * @param[in] InitialVector_len 
 * @param[out] EncryptedBuffer Buffer after encryption.
 * @param[out] EncryptedBuffer_len 
 * @param[out] NextInitialVector Initial vector to be used as _InitialVector_ parameter in the next call of this command.
 * @param[out] NextInitialVector_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Crypto_BalKeyEncryptBuffer(brp_protocol protocol, unsigned KeyVersion, unsigned EmbeddedKeyIndex, unsigned EmbeddedKeyPos, brp_buf Buffer, size_t Buffer_len, brp_buf InitialVector, size_t InitialVector_len, brp_buf* EncryptedBuffer, size_t* EncryptedBuffer_len, brp_buf* NextInitialVector, size_t* NextInitialVector_len, brp_mempool *mempool);
/**
 * @anchor Crypto_GetKeySig
 * Returns a signature of the ConfigurationKey to identify the MasterCard needed
 * for this reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of key to get the signature from. _KeyIndex_ must be set to 0x00 if a user-defined key, specified in the _KeyValue_ parameter, should be used instead.
 * @param[in] KeyValue If _KeyIndex_ is set to 0x00, this value specifies the key to get the signature from.
 * @param[out] KeySignature Unique signature of the desired ConfigurationKey.
 */
brp_errcode brp_Crypto_GetKeySig(brp_protocol protocol, unsigned KeyIndex, brp_buf KeyValue, unsigned* KeySignature);
/**
 * @anchor Crypto_CopyConfigKey
 * Copies the configuration card key 0x0202/0x85
 * (_Device/Run/ConfigCardEncryptKey_) to the _Custom/Crypto/Key[x]_ area of the
 * Baltech reader's configuration, where _x_ is the index of the target key,
 * specified in the _KeyIndex_ parameter.
 * 
 * When a key does not exist, a Baltech standard key is used instead.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] KeyIndex Index of custom key configuration value in which the configuration card key should be copied. This value must be != 0x00.
 * @param[in] ForceDefaultKey If _true_ , the Baltech standard key will be copied even if a custom key is defined.
 */
brp_errcode brp_Crypto_CopyConfigKey(brp_protocol protocol, unsigned KeyIndex, bool ForceDefaultKey);
#endif
/**
 * @}
 */
