/**
 * @file
 * @anchor BlePeriph
 * **This command group is not available in our standard firmware. If you want us
 * to activate this functionality for you, please[ get in
 * touch](https://docs.baltech.de/support/contact-support.html) with us.**
 * 
 * With this command group, you can implement your own BLE peripheral protocol,
 * i.e. your own BLE service (with its own characteristics), which will be
 * advertised by the reader.
 * 
 * Before BLE can be activated via [BlePeriph.Enable](@ref BlePeriph_Enable), you
 * have to define your service via
 * [BlePeriph.DefineService](@ref BlePeriph_DefineService). This will create an
 * internal database of characteristics that can be accessed from the BRP host
 * with the commands [BlePeriph.SetCharacteristic](@ref BlePeriph_SetCharacteristic)
 * and [BlePeriph.GetCharacteristic](@ref BlePeriph_GetCharacteristic).
 * 
 * As soon as BLE is activated via [BlePeriph.Enable](@ref BlePeriph_Enable) and a
 * BLE Central connects to your reader, it also has access to this internal
 * database of characteristcs. If it connects to the reader or modifies a
 * characteristic, you'll be informed via
 * [BlePeriph.GetEvents](@ref BlePeriph_GetEvents).
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_BLEPERIPH_H__
#define __BRP_BALTECH_API_CMDS_BLEPERIPH_H__
#include "../typedefs.h"
/**
 * @anchor BlePeriph_ErrNotInactive
 * Must not call _BlePeriph.DefineService_ after calling
 * [BlePeriph.Enable(true)](@ref BlePeriph_Enable)
 */
#define BRP_BlePeriph_ErrNotInactive BRP_ERR_STATUS(0x4B00, 0x01)
/**
 * @anchor BlePeriph_DefineService
 * This command registers a new BLE service. When a BLE Central tries to discover
 * services, this service will be amongst the available ones.
 * 
 * **This method has to be called when BLE is disabled, i.e. before calling[
 * BlePeriph.Enable(true)](@ref BlePeriph_Enable) .**
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ServiceUUID Specifies the UUID (16 or 128 bits) of the BLE service
 * @param[in] ServiceUUID_len 
 * @param[in] Characteristics List of characteristics
 * @param[in] Characteristics_len 
 */
brp_errcode brp_BlePeriph_DefineService(brp_protocol protocol, brp_buf ServiceUUID, size_t ServiceUUID_len, brp_BlePeriph_DefineService_Characteristics_Entry* Characteristics, size_t Characteristics_len);
/**
 * @anchor BlePeriph_Enable
 * This command starts/stops the advertisement of the reader as a BLE Peripheral,
 * so you can react to connect and all other kinds of requests.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Activate 
 */
brp_errcode brp_BlePeriph_Enable(brp_protocol protocol, bool Activate);
/**
 * @anchor BlePeriph_SetDeviceName
 * This command sets the device name which should be advertized by the reader.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] DeviceName Specifies the Device Name.
 * @param[in] DeviceName_len 
 */
brp_errcode brp_BlePeriph_SetDeviceName(brp_protocol protocol, brp_buf DeviceName, size_t DeviceName_len);
/**
 * @anchor BlePeriph_SetCharacteristic
 * This command changes the value of a characteristic. All future reads from the
 * Central or [BlePeriph.GetCharacteristic](@ref BlePeriph_GetCharacteristic) from
 * the BRP host will return the new value. If the Central has registered a
 * notification/indication for this characteristic, the reader will
 * automaticially send a corresponding message to the Central.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CharacteristicNdx The index of the characteristic to modify in the _Characteristics_ array passed to [BlePeriph.DefineService](@ref BlePeriph_DefineService).
 * @param[in] NewValue 
 * @param[in] NewValue_len 
 */
brp_errcode brp_BlePeriph_SetCharacteristic(brp_protocol protocol, unsigned CharacteristicNdx, brp_buf NewValue, size_t NewValue_len);
/**
 * @anchor BlePeriph_GetCharacteristic
 * This command retrieves the current value of a characteristic. A characteristic
 * will be initialized to _00 00 ... 00_ when calling
 * [BlePeriph.Enable](@ref BlePeriph_Enable) and will be modified by either the BRP
 * host ([BlePeriph.SetCharacteristic](@ref BlePeriph_SetCharacteristic)) or the BLE
 * Central (via a write to the characteristic).
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CharacteristicNdx The index of the characteristic to be retrieved in the _Characteristics_ array passed to [BlePeriph.DefineService](@ref BlePeriph_DefineService)
 * @param[out] CurrentValue 
 * @param[out] CurrentValue_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_BlePeriph_GetCharacteristic(brp_protocol protocol, unsigned CharacteristicNdx, brp_buf* CurrentValue, size_t* CurrentValue_len, brp_mempool *mempool);
/**
 * @anchor BlePeriph_GetEvents
 * This command returns all events that have occurred since the last call of
 * _BlePeriph.GetEvents_. Events that have taken place twice (e.g. _Write_ to the
 * same characteristic) will occur only once in the returned array.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Events 
 * @param[out] Events_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_BlePeriph_GetEvents(brp_protocol protocol, brp_BlePeriph_GetEvents_Events_Entry** Events, size_t* Events_len, brp_mempool *mempool);
/**
 * @anchor BlePeriph_GetRSSI
 * This command returns the RSSI value of the connected BLE Central.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] AbsRSSI The absolute value of the RSSI. As the RSSI value is usually negative, the corresponding positive value will be returned.
 */
brp_errcode brp_BlePeriph_GetRSSI(brp_protocol protocol, unsigned* AbsRSSI);
#endif
/**
 * @}
 */
