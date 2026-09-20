/*
 * 001Led_toggle.c
 *
 *  Created on: Sep 18, 2026
 *      Author: KIRANA M K
 */

#include "stm32f407xx.h"

#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;

	// This is LED gpio configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeripheralClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

	//This is button gpio configuration
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeripheralClockControl(GPIOA,ENABLE);

	GPIO_Init(&GpioBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED) //this fn returns HIGH when button pressed then we toggle LED
		{
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		}
	}

	return 0;
}
