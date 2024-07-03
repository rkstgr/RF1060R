/**
 * @file
 * @anchor DHWCtrl
 * Low level hardware commands. These are usually commands to test the hardware
 * and have very low level access to the AVR peripherals.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_DHWCTRL_H__
#define __BRP_BALTECH_API_CMDS_DHWCTRL_H__
#include "../typedefs.h"
/**
 * @anchor DHWCtrl_ErrUnknownPort
 * This port is not available on this hardware platform.
 */
#define BRP_DHWCtrl_ErrUnknownPort BRP_ERR_STATUS(0xE000, 0x01)
/**
 * @anchor DHWCtrl_ErrMarshall
 * The structure of a StartupRun-block is wrong or the command
 * [DHWCtrl.GetStartupRun](@ref DHWCtrl_GetStartupRun) has not properly been called.
 */
#define BRP_DHWCtrl_ErrMarshall BRP_ERR_STATUS(0xE000, 0x02)
/**
 * @anchor DHWCtrl_ErrNoStartupRun
 * There was no StartupRun-block, or the
 * [DHWCtrl.GetStartupRun](@ref DHWCtrl_GetStartupRun) command was not executed.
 */
#define BRP_DHWCtrl_ErrNoStartupRun BRP_ERR_STATUS(0xE000, 0x03)
/**
 * @anchor DHWCtrl_ErrNoPowermgr
 * The Power Manager was unable to take the module into suspend mode.
 */
#define BRP_DHWCtrl_ErrNoPowermgr BRP_ERR_STATUS(0xE000, 0x04)
/**
 * @anchor DHWCtrl_ErrNoProdloader
 * No production loader is present in the reader's flash memory.
 */
#define BRP_DHWCtrl_ErrNoProdloader BRP_ERR_STATUS(0xE000, 0x05)
/**
 * @anchor DHWCtrl_ErrPfid2NotAvailable
 * No PlatformID2 available.
 */
#define BRP_DHWCtrl_ErrPfid2NotAvailable BRP_ERR_STATUS(0xE000, 0x06)
/**
 * @anchor DHWCtrl_ErrEepIndex
 * Specified EEPROM address and amount of Bytes to write are not compatible.
 */
#define BRP_DHWCtrl_ErrEepIndex BRP_ERR_STATUS(0xE000, 0x11)
/**
 * @anchor DHWCtrl_ErrEepVerify
 * Data written to EEPROM could not be verified.
 */
#define BRP_DHWCtrl_ErrEepVerify BRP_ERR_STATUS(0xE000, 0x12)
/**
 * @anchor DHWCtrl_ErrEepTimeout
 * Data could not be written within timeout.
 */
#define BRP_DHWCtrl_ErrEepTimeout BRP_ERR_STATUS(0xE000, 0x13)
/**
 * @anchor DHWCtrl_ErrDataflash
 * Dataflash could not be found.
 */
#define BRP_DHWCtrl_ErrDataflash BRP_ERR_STATUS(0xE000, 0x20)
/**
 * @anchor DHWCtrl_ErrDataflashTimeout
 * Timeout occurred.
 */
#define BRP_DHWCtrl_ErrDataflashTimeout BRP_ERR_STATUS(0xE000, 0x21)
/**
 * @anchor DHWCtrl_ErrDataflashVerify
 * Verification failed after writing data.
 */
#define BRP_DHWCtrl_ErrDataflashVerify BRP_ERR_STATUS(0xE000, 0x22)
/**
 * @anchor DHWCtrl_ErrDataflashParam
 * Parameter(s)/address(es) are not valid.
 */
#define BRP_DHWCtrl_ErrDataflashParam BRP_ERR_STATUS(0xE000, 0x23)
/**
 * @anchor DHWCtrl_ErrDataflashSpi
 * Communication via SPI interface failed.
 */
#define BRP_DHWCtrl_ErrDataflashSpi BRP_ERR_STATUS(0xE000, 0x24)
/**
 * @anchor DHWCtrl_ErrDataflashFlash
 * Flash device behaves in an unspecified manner.
 */
#define BRP_DHWCtrl_ErrDataflashFlash BRP_ERR_STATUS(0xE000, 0x25)
/**
 * @anchor DHWCtrl_ErrAvrProgSpi
 * SPI programming instruction couldn't be executed successfully.
 */
#define BRP_DHWCtrl_ErrAvrProgSpi BRP_ERR_STATUS(0xE000, 0x30)
/**
 * @anchor DHWCtrl_ErrAvrProgPdi
 * PDI operation couldn't be executed successfully.
 */
#define BRP_DHWCtrl_ErrAvrProgPdi BRP_ERR_STATUS(0xE000, 0x31)
/**
 * @anchor DHWCtrl_ErrNicNoData
 * No data was received by NIC.
 */
#define BRP_DHWCtrl_ErrNicNoData BRP_ERR_STATUS(0xE000, 0x50)
/**
 * @anchor DHWCtrl_ErrNicBufferFlow
 * Received data was to big for buffer.
 */
#define BRP_DHWCtrl_ErrNicBufferFlow BRP_ERR_STATUS(0xE000, 0x51)
/**
 * @anchor DHWCtrl_PortConfig
 * Configures a port.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port Number of port to access.
 * @param[in] Mode There are four modes possible:    * OUTPUT_LOW - 0: The port is pushed to low level.    * OUTPUT_HIGH - 1: The port is pushed to high level.    * INPUT_TRISTATE - 2: The port is in very high resistance mode.    * INPUT_PULLUP - 3: The port drives a positive voltage over a resistor
 */
brp_errcode brp_DHWCtrl_PortConfig(brp_protocol protocol, unsigned Port, unsigned Mode);
/**
 * @anchor DHWCtrl_PortGet
 * Reads the current input of a port.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port Number of port to access.
 * @param[out] Level The read level.
 */
brp_errcode brp_DHWCtrl_PortGet(brp_protocol protocol, unsigned Port, bool* Level);
/**
 * @anchor DHWCtrl_PortSet
 * Sets the state of a port.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port Number of port to access.
 * @param[in] Level Level of the port.
 */
brp_errcode brp_DHWCtrl_PortSet(brp_protocol protocol, unsigned Port, bool Level);
/**
 * @anchor DHWCtrl_PortWait
 * Waits until a port has reached the specified level, or until timeout.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port Port to monitor.
 * @param[in] Level Level which must be reached by _Port_.
 * @param[in] Timeout Timeout value in milliseconds. 0xFFFF means no timeout.
 * @param[out] ReactionTime The time in milliseconds until _Port_ reached desired _Level_ value. 0xFFFF is returned when the timeout value is reached. 0xFFFE is otherwise the maximum value.
 */
brp_errcode brp_DHWCtrl_PortWait(brp_protocol protocol, unsigned Port, bool Level, unsigned Timeout, unsigned* ReactionTime);
/**
 * @anchor DHWCtrl_GetResetCause
 * Returns the cause of the microcontroller's last reset.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ResetCause 
 */
brp_errcode brp_DHWCtrl_GetResetCause(brp_protocol protocol, unsigned* ResetCause);
/**
 * @anchor DHWCtrl_APortMeasure
 * The selected ADC Clock is MCU Clock / 128 (i.e. 13.56 Mhz / 128)
 * 
 * After 13 ADC Clock Ticks the first sample will measured. 13 ADC Clock Ticks
 * are needed for one sample:
 * 
 * (1 / 13.56 Mhz) * 128 * 13 = 0.123 ms
 * 
 * So we have each 0.123ms one sample. As reference voltage the AVR internal
 * 2.56V is used, the results are 10 bit values, so to get the voltage in Volt
 * use the following formula:
 * 
 * Vin = float(result) / 1024 * 2.56V = float(result) / 400V
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port Measured port (same variable as in [DHWCtrl.PortGet](@ref DHWCtrl_PortGet))
 * @param[in] Count Count of taken measurements.
 * @param[out] Voltages 
 * @param[out] Voltages_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_APortMeasure(brp_protocol protocol, unsigned Port, unsigned Count, unsigned** Voltages, size_t* Voltages_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_SRAMTest
 * Tests the external SRAM.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SramSize Size of SRAM in Bytes
 * @param[out] Success Indicates that the SRAM Test was successfully run.
 */
brp_errcode brp_DHWCtrl_SRAMTest(brp_protocol protocol, unsigned SramSize, bool* Success);
/**
 * @anchor DHWCtrl_SetBaudrate
 * Changes the baudrate. This command should not be called over BRP.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] NewBaudrate The Baudrate specifies the performance of an UART based interface in bits per second.  **For the old-style 8bit format, which omits the least significant digit, this format is not supported any more. Configurations using this format cannot be opened.**
 */
brp_errcode brp_DHWCtrl_SetBaudrate(brp_protocol protocol, brp_Baudrate NewBaudrate);
/**
 * @anchor DHWCtrl_MirrorData
 * Sends the exact same data back.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Data 
 * @param[in] Data_len 
 * @param[out] MirroredData 
 * @param[out] MirroredData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_MirrorData(brp_protocol protocol, brp_buf Data, size_t Data_len, brp_buf* MirroredData, size_t* MirroredData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_DispEnable
 * Enables the Display.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable 
 */
brp_errcode brp_DHWCtrl_DispEnable(brp_protocol protocol, bool Enable);
/**
 * @anchor DHWCtrl_DispBacklight
 * Enables the Baltech reader display's backlight.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Backlight 
 */
brp_errcode brp_DHWCtrl_DispBacklight(brp_protocol protocol, bool Backlight);
/**
 * @anchor DHWCtrl_DispColor
 * Set the drawing color
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Color Either 0 for white or 0xff for black.
 */
brp_errcode brp_DHWCtrl_DispColor(brp_protocol protocol, unsigned Color);
/**
 * @anchor DHWCtrl_DispContrast
 * Changes the display contrast.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Contrast 
 */
brp_errcode brp_DHWCtrl_DispContrast(brp_protocol protocol, unsigned Contrast);
/**
 * @anchor DHWCtrl_DispBox
 * Draws a filled box.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] X 
 * @param[in] Y 
 * @param[in] Width 
 * @param[in] Height 
 */
brp_errcode brp_DHWCtrl_DispBox(brp_protocol protocol, unsigned X, unsigned Y, unsigned Width, unsigned Height);
/**
 * @anchor DHWCtrl_Ser2Ctrl
 * Enable/Disable and setup the reader's 2nd UART interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] InterfaceID 
 * @param[in] Enable 
 * @param[in] NewBaudrate The Baudrate specifies the performance of an UART based interface in bits per second.  **For the old-style 8bit format, which omits the least significant digit, this format is not supported any more. Configurations using this format cannot be opened.**
 * @param[in] NewParity Specifies the Parity-bit mode which is used for UART protocols.
 * @param[in] Stopbits Number of stop bits.
 */
brp_errcode brp_DHWCtrl_Ser2Ctrl(brp_protocol protocol, unsigned InterfaceID, bool Enable, brp_Baudrate NewBaudrate, brp_Parity NewParity, unsigned Stopbits);
/**
 * @anchor DHWCtrl_Ser2WriteRead
 * Write/Read data to/from the reader's 2nd UART interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] MaxReadCount Number of Bytes to read via the reader's 2nd UART interface.
 * @param[in] Timeout Number of milliseconds to wait for Bytes.
 * @param[in] WriteData Data to write to the reader's 2nd UART interface.
 * @param[in] WriteData_len 
 * @param[out] ReadData Data read from the reader's 2nd UART interface.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_Ser2WriteRead(brp_protocol protocol, unsigned MaxReadCount, unsigned Timeout, brp_buf WriteData, size_t WriteData_len, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_Ser2Flush
 * Wait until output to 2nd UART interface is sent out.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_Ser2Flush(brp_protocol protocol);
/**
 * @anchor DHWCtrl_Delay1ms
 * Sleeps for some milliseconds.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Delay Number of milliseconds to sleep.
 */
brp_errcode brp_DHWCtrl_Delay1ms(brp_protocol protocol, unsigned Delay);
/**
 * @anchor DHWCtrl_Delay10us
 * Sleeps for some microseconds.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Delay Number of 10s of microseconds to sleep.
 */
brp_errcode brp_DHWCtrl_Delay10us(brp_protocol protocol, unsigned Delay);
/**
 * @anchor DHWCtrl_PowermgrSuspend
 * Takes the board into suspend mode, i.e. energy saving mode.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Delay Time to sleep in milliseconds.
 * @param[in] KeyboardWakeup If _true_ , the keyboard can wake up the board.
 */
brp_errcode brp_DHWCtrl_PowermgrSuspend(brp_protocol protocol, unsigned Delay, bool KeyboardWakeup);
/**
 * @anchor DHWCtrl_ScanMatrix
 * Writes a bitmask to the 573, which is used for keyboard scanning.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Bitmask The bitmask which should be written to Matrixrows
 */
brp_errcode brp_DHWCtrl_ScanMatrix(brp_protocol protocol, unsigned Bitmask);
/**
 * @anchor DHWCtrl_GetReaderChipType
 * Returns the RC reader chip type.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ChipType 
 */
brp_errcode brp_DHWCtrl_GetReaderChipType(brp_protocol protocol, brp_DHWCtrl_GetReaderChipType_ChipType* ChipType);
/**
 * @anchor DHWCtrl_SelectAntenna
 * Switch external antenna.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Ant Antenna that should be activated (0 or 1)
 */
brp_errcode brp_DHWCtrl_SelectAntenna(brp_protocol protocol, unsigned Ant);
/**
 * @anchor DHWCtrl_GetSamType
 * Returns the RC reader chip type
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ChipType 
 */
brp_errcode brp_DHWCtrl_GetSamType(brp_protocol protocol, brp_DHWCtrl_GetSamType_ChipType* ChipType);
/**
 * @anchor DHWCtrl_HfAcquire
 * Acquire specific HF Subsystem.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ModuleId HF subsystem to activate
 */
brp_errcode brp_DHWCtrl_HfAcquire(brp_protocol protocol, brp_DHWCtrl_HfAcquire_ModuleId ModuleId);
/**
 * @anchor DHWCtrl_EepromWrite
 * Writes data to an arbitrary address in the EEPROM.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Address Address of block to write.
 * @param[in] Data Data to write into the EEPROM.
 * @param[in] Data_len 
 */
brp_errcode brp_DHWCtrl_EepromWrite(brp_protocol protocol, unsigned Address, brp_buf Data, size_t Data_len);
/**
 * @anchor DHWCtrl_DataflashGetSize
 * Retrieves the flash size.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Device Flash device number.
 * @param[out] PageCount Number of pages.
 * @param[out] PageSize Size of a page.
 */
brp_errcode brp_DHWCtrl_DataflashGetSize(brp_protocol protocol, unsigned Device, unsigned* PageCount, unsigned* PageSize);
/**
 * @anchor DHWCtrl_DataflashErasePages
 * Erase a group of pages.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Device Flash device number.
 * @param[in] StartPage Number of first page to erase.
 * @param[in] Len Number of pages to erase.
 */
brp_errcode brp_DHWCtrl_DataflashErasePages(brp_protocol protocol, unsigned Device, unsigned StartPage, unsigned Len);
/**
 * @anchor DHWCtrl_DataflashRead
 * Read data within a certain page.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Device Flash device number.
 * @param[in] Page Number of first page to erase.
 * @param[in] StartAdr Start address relative to page.
 * @param[in] Len Number of Bytes to read.
 * @param[out] Data Data read from the Dataflash.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_DataflashRead(brp_protocol protocol, unsigned Device, unsigned Page, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_DataflashWrite
 * Write data to a certain page.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Device Flash device number.
 * @param[in] Mode Writing mode.
 * @param[in] Page Number of page to write to.
 * @param[in] StartAdr Start address relative to page.
 * @param[in] Data Data to write to the Dataflash.
 * @param[in] Data_len 
 */
brp_errcode brp_DHWCtrl_DataflashWrite(brp_protocol protocol, unsigned Device, unsigned Mode, unsigned Page, unsigned StartAdr, brp_buf Data, size_t Data_len);
/**
 * @anchor DHWCtrl_EepromRead
 * Reads data from the EEPROM.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Address of block to read from.
 * @param[in] Len Number of Bytes to read.
 * @param[out] Data Data read from the EEPROM.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_EepromRead(brp_protocol protocol, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_SecurityAndConfigReset
 * Reset configuration incl. "Encryption and Authorization" settings.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_SecurityAndConfigReset(brp_protocol protocol);
/**
 * @anchor DHWCtrl_PulseGenerate
 * Generates a pulse of specified frequency on a certain pin.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port The number of the pin to access.
 * @param[in] Frequency The desired pulse frequency in kHz. Set to 0 to switch pulse off.
 */
brp_errcode brp_DHWCtrl_PulseGenerate(brp_protocol protocol, unsigned Port, unsigned Frequency);
/**
 * @anchor DHWCtrl_InitSer2
 * Initializes the serial2 module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitSer2(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitRtc
 * Initializes the rtc module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitRtc(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitLcdDrv
 * Initializes the display module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitLcdDrv(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitRc
 * Initializes the rc module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitRc(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitMf
 * Initializes the Mifare module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitMf(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitIso14A
 * Initializes the ISO14443A module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitIso14A(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitIso14B
 * Initializes the ISO14443B module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitIso14B(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitIso15
 * Initializes the ISO15693 module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitIso15(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitLg
 * Initializes the Legic module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitLg(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitLga
 * Initializes the Legic Advant module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitLga(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitDf
 * Initializes the dataflash module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitDf(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitRc125
 * Initializes the RC125 module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitRc125(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitCc
 * Initializes the TDA8007 or CCUART module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitCc(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitUsbHost
 * Initializes the USB-Host module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitUsbHost(brp_protocol protocol);
/**
 * @anchor DHWCtrl_InitNic
 * Initializes the Network Interface (NIC) module.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitNic(brp_protocol protocol);
/**
 * @anchor DHWCtrl_BohEnable
 * Enables the BRP over HID interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable True if the interface should be enabled.
 * @param[in] Bug6WorkaroundEnabled Enable the workaround for BUG6.
 */
brp_errcode brp_DHWCtrl_BohEnable(brp_protocol protocol, bool Enable, bool Bug6WorkaroundEnabled);
/**
 * @anchor DHWCtrl_NicEnable
 * Enables the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable 
 */
brp_errcode brp_DHWCtrl_NicEnable(brp_protocol protocol, bool Enable);
/**
 * @anchor DHWCtrl_NicGetChipType
 * Returns the chip type of the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] ChipType The Chip type characterizing byte stream (DM9006: 0x 0A 46 90 06 02).
 * @param[out] ChipType_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_NicGetChipType(brp_protocol protocol, brp_buf* ChipType, size_t* ChipType_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_NicGetLinkStatus
 * Retrieve the Link status of the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LinkStatus Link status: Bit0 = Port0, Bit1 = Port1; Bit is set if port is linked.
 */
brp_errcode brp_DHWCtrl_NicGetLinkStatus(brp_protocol protocol, unsigned* LinkStatus);
/**
 * @anchor DHWCtrl_NicSend
 * Sends a frame via the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SendData Ethernet frame to send via NIC.
 * @param[in] SendData_len 
 */
brp_errcode brp_DHWCtrl_NicSend(brp_protocol protocol, brp_buf SendData, size_t SendData_len);
/**
 * @anchor DHWCtrl_NicReceive
 * Receives a frame from the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Timeout Max. time in ms to wait for reception.
 * @param[out] RecvData The received frame without ethernet CRC.
 * @param[out] RecvData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_NicReceive(brp_protocol protocol, unsigned Timeout, brp_buf* RecvData, size_t* RecvData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_NicSetMAC
 * Set the MAC address of the Network Interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] MAC MAC address.
 */
brp_errcode brp_DHWCtrl_NicSetMAC(brp_protocol protocol, brp_buf MAC);
/**
 * @anchor DHWCtrl_ApspiSetSpeed
 * Set the speed of SPI programming mode.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Speed SPI speed in kbit/s.
 */
brp_errcode brp_DHWCtrl_ApspiSetSpeed(brp_protocol protocol, unsigned Speed);
/**
 * @anchor DHWCtrl_ApspiEnable
 * Enables/disables the SPI programming mode of a connected slave AVR.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable True if the programming mode should be enabled.
 */
brp_errcode brp_DHWCtrl_ApspiEnable(brp_protocol protocol, bool Enable);
/**
 * @anchor DHWCtrl_ApspiSingleSend
 * Send a single SPI programming instruction.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCode command code of instruction.
 * @param[in] Address target address of instruction.
 * @param[in] CmdData data byte of instruction.
 * @param[in] Delay Delay to assert before next command in milliseconds.
 */
brp_errcode brp_DHWCtrl_ApspiSingleSend(brp_protocol protocol, unsigned CmdCode, unsigned Address, unsigned CmdData, unsigned Delay);
/**
 * @anchor DHWCtrl_ApspiSingleRecv
 * Send a single SPI programming instruction and receive one data byte.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCode command code of instruction.
 * @param[in] Address target address of instruction.
 * @param[out] CmdData data Byte received.
 */
brp_errcode brp_DHWCtrl_ApspiSingleRecv(brp_protocol protocol, unsigned CmdCode, unsigned Address, unsigned* CmdData);
/**
 * @anchor DHWCtrl_ApspiAlternateSend
 * Send alternately SPI programming instructions. First CmdCodeA with address adr
 * and the first byte in the data buffer, then CmdCodeB with the same address and
 * the second byte in the buffer is sent. After that the address will be
 * incremented. This is repeated as long as data bytes are in the buffer.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCodeA command code of first instruction.
 * @param[in] CmdCodeB command code of second instruction.
 * @param[in] Address start address.
 * @param[in] CmdData collection of all data bytes to send.
 * @param[in] CmdData_len 
 * @param[in] Delay Delay to assert before next command in milliseconds.
 */
brp_errcode brp_DHWCtrl_ApspiAlternateSend(brp_protocol protocol, unsigned CmdCodeA, unsigned CmdCodeB, unsigned Address, brp_buf CmdData, size_t CmdData_len, unsigned Delay);
/**
 * @anchor DHWCtrl_ApspiAlternateRecv
 * Send alternately SPI programming instructions and receive data bytes. Works
 * similar to ApspiAlternateSend.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CmdCodeA command code of first instruction.
 * @param[in] CmdCodeB command code of second instruction.
 * @param[in] Address start address.
 * @param[in] CmdDataLen Number of data Bytes that should be retrieved.
 * @param[out] CmdData collection of all data Bytes received.
 * @param[out] CmdData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_ApspiAlternateRecv(brp_protocol protocol, unsigned CmdCodeA, unsigned CmdCodeB, unsigned Address, unsigned CmdDataLen, brp_buf* CmdData, size_t* CmdData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_PdiEnable
 * Enables/disables the PDI programming mode of a connected target AVR.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Enable True if the programming mode should be enabled.
 */
brp_errcode brp_DHWCtrl_PdiEnable(brp_protocol protocol, bool Enable);
/**
 * @anchor DHWCtrl_PdiEraseDevice
 * Erases the target chip device.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_PdiEraseDevice(brp_protocol protocol);
/**
 * @anchor DHWCtrl_PdiReadFlash
 * Read flash memory from target device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] ReadLen number of bytes to read
 * @param[out] ReadData Data Bytes read from device.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_PdiReadFlash(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_PdiEraseFlashPage
 * Erase flash page.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr page address.
 */
brp_errcode brp_DHWCtrl_PdiEraseFlashPage(brp_protocol protocol, unsigned Adr);
/**
 * @anchor DHWCtrl_PdiWriteFlashPage
 * Write to internal flash page buffer.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] WriteData Data Bytes to be written.
 * @param[in] WriteData_len 
 */
brp_errcode brp_DHWCtrl_PdiWriteFlashPage(brp_protocol protocol, unsigned Adr, brp_buf WriteData, size_t WriteData_len);
/**
 * @anchor DHWCtrl_PdiProgramFlashPage
 * Program flash page. Page must be written with PdiWriteFlashPage before.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr page address.
 */
brp_errcode brp_DHWCtrl_PdiProgramFlashPage(brp_protocol protocol, unsigned Adr);
/**
 * @anchor DHWCtrl_PdiReadEeprom
 * Read eeprom memory from target device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] ReadLen number of bytes to read
 * @param[out] ReadData Data Bytes read from device.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_PdiReadEeprom(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_PdiProgramEepromPage
 * Write an eeprom page to target device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] WriteData Data Bytes to be written.
 * @param[in] WriteData_len 
 */
brp_errcode brp_DHWCtrl_PdiProgramEepromPage(brp_protocol protocol, unsigned Adr, brp_buf WriteData, size_t WriteData_len);
/**
 * @anchor DHWCtrl_PdiReadFuses
 * Read fuse memory from target device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] ReadLen number of bytes to read
 * @param[out] ReadData Data Bytes read from device.
 * @param[out] ReadData_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_PdiReadFuses(brp_protocol protocol, unsigned Adr, unsigned ReadLen, brp_buf* ReadData, size_t* ReadData_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_PdiWriteFuse
 * Write a fuse byte to target device.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Adr start address.
 * @param[in] Fuse Fuse content to be written.
 */
brp_errcode brp_DHWCtrl_PdiWriteFuse(brp_protocol protocol, unsigned Adr, unsigned Fuse);
/**
 * @anchor DHWCtrl_FlashGetPageSize
 * Retrieves the page size of the program flash.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] PageSize Size of a page.
 */
brp_errcode brp_DHWCtrl_FlashGetPageSize(brp_protocol protocol, unsigned* PageSize);
/**
 * @anchor DHWCtrl_FlashErasePage
 * Erases one or several consecutive program flash pages.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Address of first page to erase. Has to be a multiple of the page size.
 * @param[in] Len Number of Bytes to erase. Should be always a multiple of the page size.
 */
brp_errcode brp_DHWCtrl_FlashErasePage(brp_protocol protocol, unsigned StartAdr, unsigned Len);
/**
 * @anchor DHWCtrl_FlashRead
 * Read data from program flash.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Start address of the data to read.
 * @param[in] Len Number of Bytes to read.
 * @param[out] Data Data read from the program flash.
 * @param[out] Data_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_FlashRead(brp_protocol protocol, unsigned StartAdr, unsigned Len, brp_buf* Data, size_t* Data_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_FlashWritePage
 * Write to a temporary page buffer. Can be executed several times until the page
 * buffer is filled.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Start address the data should be written to.
 * @param[in] Data Data to write to the page buffer.
 * @param[in] Data_len 
 */
brp_errcode brp_DHWCtrl_FlashWritePage(brp_protocol protocol, unsigned StartAdr, brp_buf Data, size_t Data_len);
/**
 * @anchor DHWCtrl_FlashProgramPage
 * Program a page to program flash. The data has to be written to the temporary
 * page buffer with FlashWritePage before.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] StartAdr Start address of the page that should be programmed. Has to be a multiple of the page size.
 */
brp_errcode brp_DHWCtrl_FlashProgramPage(brp_protocol protocol, unsigned StartAdr);
/**
 * @anchor DHWCtrl_RegisterRead
 * Read processor register.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RegAdr Address of register to read.
 * @param[out] RegValue Value of register.
 */
brp_errcode brp_DHWCtrl_RegisterRead(brp_protocol protocol, unsigned RegAdr, unsigned* RegValue);
/**
 * @anchor DHWCtrl_RegisterWrite
 * Write processor register.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] RegAdr Address of register to write.
 * @param[in] RegValue Value of register to write.
 */
brp_errcode brp_DHWCtrl_RegisterWrite(brp_protocol protocol, unsigned RegAdr, unsigned RegValue);
/**
 * @anchor DHWCtrl_AesWrapKey
 * Wraps an AES key for secure storage
 * 
 * @param[in] protocol used to execute the command
 * @param[in] WrappedKeyNr 
 * @param[in] Key Key to use for wrapping
 * @param[in] Key_len 
 * @param[out] WrappedKey Wrapped key
 * @param[out] WrappedKey_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_AesWrapKey(brp_protocol protocol, brp_DHWCtrl_AesWrapKey_WrappedKeyNr WrappedKeyNr, brp_buf Key, size_t Key_len, brp_buf* WrappedKey, size_t* WrappedKey_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_AesEncrypt
 * Encrypts a block
 * 
 * @param[in] protocol used to execute the command
 * @param[in] WrappedKeyNr 
 * @param[in] Block Block to encrypt
 * @param[in] Block_len 
 * @param[in] Key Key to use for encryption
 * @param[in] Key_len 
 * @param[out] EncBlock Encrypted block
 * @param[out] EncBlock_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_AesEncrypt(brp_protocol protocol, brp_DHWCtrl_AesEncrypt_WrappedKeyNr WrappedKeyNr, brp_buf Block, size_t Block_len, brp_buf Key, size_t Key_len, brp_buf* EncBlock, size_t* EncBlock_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_AesDecrypt
 * Decrypts a block
 * 
 * @param[in] protocol used to execute the command
 * @param[in] WrappedKeyNr 
 * @param[in] EncBlock Encrypted block to decrypt
 * @param[in] EncBlock_len 
 * @param[in] Key Key to use for decryption
 * @param[in] Key_len 
 * @param[out] Block Decrypted block
 * @param[out] Block_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_AesDecrypt(brp_protocol protocol, brp_DHWCtrl_AesDecrypt_WrappedKeyNr WrappedKeyNr, brp_buf EncBlock, size_t EncBlock_len, brp_buf Key, size_t Key_len, brp_buf* Block, size_t* Block_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_GetPlatformId2
 * This command retrieves the PlatformId2. A list of all supported
 * HardwareComponents is returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] HWCIdLst 
 * @param[out] HWCIdLst_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_GetPlatformId2(brp_protocol protocol, unsigned** HWCIdLst, size_t* HWCIdLst_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_GetProdLoader
 * Returns the baudrate Byte of the production-loader.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] LoaderBaudrate 
 */
brp_errcode brp_DHWCtrl_GetProdLoader(brp_protocol protocol, unsigned* LoaderBaudrate);
/**
 * @anchor DHWCtrl_StartProdLoader
 * Starts the production-loader.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_StartProdLoader(brp_protocol protocol);
/**
 * @anchor DHWCtrl_Run
 * Executes a list of commands. The commands are stored sequentially in the
 * buffer. Every command has as a header the command code and the length of the
 * following parameters. Both are given in bytes. It is possible to execute every
 * DHWCtrl command through this interface.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] CommandList Commands to execute.
 * @param[in] CommandList_len 
 * @param[out] Status 
 * @param[out] Response Collection of all answers.
 * @param[out] Response_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_Run(brp_protocol protocol, brp_buf CommandList, size_t CommandList_len, unsigned* Status, brp_buf* Response, size_t* Response_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_GetStartupRun
 * Returns the result of the execution of DHWCtrl-commands at the startup.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Status 
 * @param[out] Response Collection of all answers.
 * @param[out] Response_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_GetStartupRun(brp_protocol protocol, unsigned* Status, brp_buf* Response, size_t* Response_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_InitBgm
 * Initializes the Bluetooth BGM12X chip.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_InitBgm(brp_protocol protocol);
/**
 * @anchor DHWCtrl_BgmExec
 * Execute a Bgm12X API command.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Cmd Command data Bytes to be sent.
 * @param[in] Cmd_len 
 * @param[in] Timeout Maximum time to wait for receiving a response.
 * @param[out] Rsp Received data Bytes.
 * @param[out] Rsp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_BgmExec(brp_protocol protocol, brp_buf Cmd, size_t Cmd_len, unsigned Timeout, brp_buf* Rsp, size_t* Rsp_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_Sm4x00BootloaderStart
 * Start SM4x00 Bootloader.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] BootloaderString Received Bootloader TLV string.
 * @param[out] BootloaderString_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_Sm4x00BootloaderStart(brp_protocol protocol, brp_buf* BootloaderString, size_t* BootloaderString_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_Sm4x00EraseFlash
 * Erase SM4x00 Flash. Must be issued directly after
 * DHWCtrl.Sm4x00BootloaderStart. Erasing lasts about 20-30 seconds. Use
 * DHWCtrl.Sm4x00WaitForFlashErase to find out when it has been finished.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_DHWCtrl_Sm4x00EraseFlash(brp_protocol protocol);
/**
 * @anchor DHWCtrl_Sm4x00WaitForFlashErase
 * Check if flash erasing has been finished.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Timeout 
 * @param[out] EraseResponse Received response from SM4x00 if erasing has finished. Response is empty if erasing is still in progress after Timeout expired.
 * @param[out] EraseResponse_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_Sm4x00WaitForFlashErase(brp_protocol protocol, unsigned Timeout, brp_buf* EraseResponse, size_t* EraseResponse_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_Sm4x00ProgramBlock
 * Program one 128 byte block of SM4x00 firmware.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] IsLast Flag that signals if this is last block.
 * @param[in] FwBlock Firmware block to be programmed.
 * @param[in] FwBlock_len 
 * @param[out] ProgramResponse Received response from SM4x00.
 * @param[out] ProgramResponse_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_Sm4x00ProgramBlock(brp_protocol protocol, bool IsLast, brp_buf FwBlock, size_t FwBlock_len, brp_buf* ProgramResponse, size_t* ProgramResponse_len, brp_mempool *mempool);
/**
 * @anchor DHWCtrl_BgmRead
 * Read from Bgm12X.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Timeout Maximum time to wait for receiving data.
 * @param[out] Rsp Received data Bytes.
 * @param[out] Rsp_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_DHWCtrl_BgmRead(brp_protocol protocol, unsigned Timeout, brp_buf* Rsp, size_t* Rsp_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
