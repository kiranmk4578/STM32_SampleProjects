/*
 * 001Led_toggle.c
 *
 *  Created on: Sep 18, 2026
 *      Author: KIRANA M K
 */

#include "stm32f407xx.h"
#include <string.h>


#define HIGH 1
#define LOW	 0
#define BTN_PRESSED LOW

void delay(void)
{
	// ~200 ms delay is introduced when system clock is 16 MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GpioBtn,0,sizeof(GpioBtn));

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
	GpioBtn.pGPIOx = GPIOD;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	// we have not initialized GPIO_PinOPType
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeripheralClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioBtn);


	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

	while(1);

}

void EXTI9_5_IRQHandler(void)
{
	delay(); //200ms
	GPIO_IRQHandling(GPIO_PIN_NO_5); //clear the pending event from the EXTI line
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
}
