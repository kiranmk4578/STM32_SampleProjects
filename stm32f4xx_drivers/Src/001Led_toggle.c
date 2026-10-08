/*
 * 001Led_toggle.c
 *
 *  Created on: Sep 18, 2026
 *      Author: KIRANA M K
 */

#include "stm32f407xx.h"


void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed;                                        // Create a GPIO handle for the LED
	GpioLed.pGPIOx = GPIOD;                                       // Select GPIO port D or assign GPIOD base address
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;       // Configure GPIO pin number 12
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;          // Configure pin as output
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;       // Configure GPIO speed as fast
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;      // Configure output type as push-pull
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;    // Disable internal pull-up and pull-down resistors

	GPIO_PeripheralClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

	return 0;
}
