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

/*
 * @SPI_DEVICE_MODE
 */
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * @SPI_BUS_CONFIG
 */
#define SPI_BUS_CONFIG_FD				1	// Full Duplex communication
#define SPI_BUS_CONFIG_HD				2   // Half Duplex communication
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	3

/*
 * @SPI_SCLK_SPEED
 */
#define SPI_SCLK_SPEED_DIV2       0   // SPI clock speed = Fpclk / 2
#define SPI_SCLK_SPEED_DIV4       1   // SPI clock speed = Fpclk / 4
#define SPI_SCLK_SPEED_DIV8       2   // SPI clock speed = Fpclk / 8
#define SPI_SCLK_SPEED_DIV16      3   // SPI clock speed = Fpclk / 16
#define SPI_SCLK_SPEED_DIV32      4   // SPI clock speed = Fpclk / 32
#define SPI_SCLK_SPEED_DIV64      5   // SPI clock speed = Fpclk / 64
#define SPI_SCLK_SPEED_DIV128     6   // SPI clock speed = Fpclk / 128
#define SPI_SCLK_SPEED_DIV256     7   // SPI clock speed = Fpclk / 256

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS     0   // SPI data frame format = 8 bits(Default format)
#define SPI_DFF_16BITS    1   // SPI data frame format = 16 bits

/*
 * @SPI_CPOL
 */
#define SPI_CPOL_HIGH    1   // Clock polarity = High when SPI is idle
#define SPI_CPOL_LOW     0   // Clock polarity = Low when SPI is idle

/*
 * @SPI_CPHA
 */
#define SPI_CPHA_HIGH    1   // Data is captured on the second clock edge
#define SPI_CPHA_LOW     0   // Data is captured on the first clock edge

/*
 * @SPI_SSM
 */
#define SPI_SSM_EN       1   // Hardware slave management enable
#define SPI_SSM_DI       0   // Software slave management disable


/**************************************************************************************************************************
 * 								APIs supported by this driver
 *			For more information about the APIs check the function definitions
 **************************************************************************************************************************/

/*
 * Peripheral Clock Setup
 */

// Enable or disable the peripheral clock for the selected SPI
void SPI_PeripheralClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Initialization and De-initialization
 */

// Configure the selected SPI peripheral using the settings in the handle
void SPI_Init(SPI_Handle_t *pSPIHandle);

// Reset the registers of the selected SPI peripheral to their reset values
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data send and Receive
 */
 void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
 void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */
 // Configure NVIC interrupt number, priority, and enable/disable
 void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);

 // Configure NVIC priority for the given IRQ number
 void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);

 // Handle interrupt event for the given SPI
 void SPI_IRQHandling(SPI_Handle_t *pHandle);


/*
 * Other Peripheral Control APIs
 */










#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
