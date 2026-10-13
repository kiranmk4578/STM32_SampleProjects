/*
 * 006Spi_tx_testing.c
 *
 *  Created on: Oct 6, 2026
 *      Author: KIRANA M K
 */

/*	PA7 --> SPI1 MOSI
	PA6 --> SPI1 MISO
	PA5 --> SPI1 SCLK
	PA4 --> SPI1 NSS
	ALT function mode : 5
*/

#include "stm32f407xx.h"
#include <string.h>

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i++);
}

void SPI1_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;

	//memset(&SPIPins,0,sizeof(SPIPins));

	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	// SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_Init(&SPIPins);

	// MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
	GPIO_Init(&SPIPins);

	// MISO
	// SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	// GPIO_Init(&SPIPins);

	// NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	GPIO_Init(&SPIPins);
}

void SPI1_Inits(void)
{
	SPI_Handle_t SPI1Handle;

	SPI1Handle.pSPIx = SPI1; // Initializing the base address of SPI1

	SPI1Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;

	SPI1Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;

	// SPI1 clock = APB2 clock / 8
	// If APB2 = 16 MHz, SCLK = 2 MHz
	SPI1Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;

	SPI1Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;

	SPI1Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW; // Default configuration

	SPI1Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW; // Default configuration

	SPI1Handle.SPIConfig.SPI_SSM = SPI_SSM_DI; // Hardware slave management enabled

	SPI_Init(&SPI1Handle);
}

void GPIO_ButtonInit(void)
{
	GPIO_Handle_t GpioBtn;

	//This is button gpio configuration
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioBtn);
}

int main(void)
{
	char user_data[] = "Hello world";

	//This is button gpio configuration
	GPIO_ButtonInit();

	// Initialize GPIO pins to behave as SPI1 pins
 	SPI1_GPIOInits();

	// Initialize SPI1 peripheral parameters
	SPI1_Inits();

	/*
	* making SSOE 1 does NSS output enable.
	* The NSS pin is automatically managed by the hardware.
	* i.e when SPE=1 , NSS will be pulled to low
	* and NSS pin will be high when SPE=0
	*/
	SPI_SSOEConfig(SPI1, ENABLE);

	while(1)
	{
		// Read the button press status
		while( !(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)) );

		//Delay to avoid debouncing issue
		delay();

		// Enable SPI1 peripheral
		SPI_PeripheralControl(SPI1, ENABLE);

		//first send length information to SLAVE
		uint8_t dataLen = strlen(user_data);
		SPI_SendData(SPI1, &dataLen, 1);

		// Send data through SPI1
		SPI_SendData(SPI1, (uint8_t*)user_data, strlen(user_data));

		//Lets confirm SPI is not BUSY
		while( SPI_GetFlagStatus(SPI1, SPI_BSY_FLAG) );

		// Disable SPI1 peripheral
		SPI_PeripheralControl(SPI1, DISABLE);
	}

	return 0;
}
