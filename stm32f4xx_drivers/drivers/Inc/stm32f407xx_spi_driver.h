/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Oct 2, 2026
 *      Author: KIRANA M K
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "stm32f407xx.h" //contains MCU specific data

/*
 * SPI Configuration Structure : Stores the configuration settings required provided by application/user
 * to initialize SPI.
 */
typedef struct
{
    uint8_t SPI_DeviceMode;     // Possible values from @SPI_DEVICE_MODE
    uint8_t SPI_BusConfig;      // Possible values from @SPI_BUS_CONFIG
    uint8_t SPI_SclkSpeed;      // Possible values from @SPI_SCLK_SPEED
    uint8_t SPI_DFF;            // Possible values from @SPI_DFF
    uint8_t SPI_CPOL;           // Possible values from @SPI_CPOL
    uint8_t SPI_CPHA;           // Possible values from @SPI_CPHA
    uint8_t SPI_SSM;            // Possible values from @SPI_SSM

} SPI_Config_t;

/*
 * Stores the SPI peripheral address and its configuration settings.
 */
typedef struct
{
    SPI_RegDef_t *pSPIx;      // Points to the selected SPI peripheral (SPI1, SPI2, SPI3, etc.)
    SPI_Config_t SPIConfig;  // Holds SPI settings such as mode, speed, bus configuration, CPOL, CPHA, etc. passed by application.

} SPI_Handle_t;










#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
