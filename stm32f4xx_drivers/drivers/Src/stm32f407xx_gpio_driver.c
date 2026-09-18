/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Sep 14, 2026
 *      Author: KIRANA M K
 */

#include "stm32f407xx_gpio_driver.h" //contains driver specific data

/*
 * Peripheral Clock setup
 */

/***************************************************************
 * @fn        - GPIO_PeripheralClockControl
 *
 * @brief     - Enables or disables the clock for a given GPIO port
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 * @param[in] - EnorDi : ENABLE or DISABLE macro
 *
 * @return    - none
 *
 * @Note      - Must be called before accessing GPIO registers
 ***************************************************************/
void GPIO_PeripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	}else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}

	}
}


/*
 * Init and De-Init
 */

/***************************************************************
 * @fn        - GPIO_Init
 *
 * @brief     - Configures a GPIO pin with the given settings
 *
 * @param[in] - pGPIOHandle : Pointer to GPIO handle structure
 *
 * @return    - none
 *
 * @Note      - Call PeripheralClockControl before initialization
 ***************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0; //temp. register

	//1. configure the mode of gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->MODER &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing 2 specific bits used
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		//this part will code later, this is interrupt mode
	}

	//2. configure the speed
		temp = 0;
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//clearing 2 specific bits used
		pGPIOHandle->pGPIOx->OSPEEDR |= temp;
		temp = 0;

	//3. configure the pull up/pull down settings
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->PUPDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//clearing 2 specific bits used
		pGPIOHandle->pGPIOx->PUPDR |= temp;

	//4. configure the output type
		temp = 0;
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->OTYPER &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//clearing 1 specific bit used
		pGPIOHandle->pGPIOx->OTYPER |= temp;

	//5. configure the alt functionality
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN)
		{
			    // Configure the alternate function registers
			    uint8_t temp1, temp2;

			    // Each AFR register covers 8 pins (AFR[0] for pins 0–7, AFR[1] for pins 8–15)
			    temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
			    temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
			    pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); //clearing 4 specific bits
			    pGPIOHandle->pGPIOx->AFR[temp1] |=(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2 ) );
		 }


}

/***************************************************************
 * @fn        - GPIO_DeInit
 *
 * @brief     - Resets all registers of the given GPIO port
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 *
 * @return    - none
 *
 * @Note      - Restores port to default reset state
 ***************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REGISTER_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOA_REGISTER_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOA_REGISTER_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOA_REGISTER_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOA_REGISTER_RESET();
	}


}


/*
 * Data read and write
 */

/***************************************************************
 * @fn        - GPIO_ReadFromInputPin
 *
 * @brief     - Reads logic level (0/1) from a specific GPIO pin
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 * @param[in] - PinNumber : Pin number to read
 *
 * @return    - uint8_t : Pin value (0 or 1)
 *
 * @Note      - none
 ***************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001 );
	return value;
}

/***************************************************************
 * @fn        - GPIO_ReadFromInputPort
 *
 * @brief     - Reads the 16-bit input value of the entire GPIO port
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 *
 * @return    - uint16_t : Port value (all pin states)
 *
 * @Note      - Each bit corresponds to a pin number (0–15)
 ***************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}

/***************************************************************
 * @fn        - GPIO_WriteToOutputPin
 *
 * @brief     - Writes logic level (0/1) to a specific GPIO pin
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 * @param[in] - PinNumber : Pin number to write
 * @param[in] - Value : Desired output (0 or 1)
 *
 * @return    - none
 *
 * @Note      - none
 ***************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		// write 0 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR &= ~(1 << PinNumber);

	}
}

/***************************************************************
 * @fn        - GPIO_WriteToOutputPort
 *
 * @brief     - Writes a 16-bit value to all pins of the GPIO port
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 * @param[in] - Value : 16-bit value to write
 *
 * @return    - none
 *
 * @Note      - Updates all pins simultaneously
 ***************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value; // Write the 16-bit value to the GPIO Output Data Register also only 16bit of ODR is used for PORT or 16GPIO pins per GPIO PORT.
}

/***************************************************************
 * @fn        - GPIO_ToggleOutputPin
 *
 * @brief     - Flips the current output state of a specific GPIO pin
 *
 * @param[in] - pGPIOx : Base address of the GPIO port
 * @param[in] - PinNumber : Pin number to toggle
 *
 * @return    - none
 *
 * @Note      - Useful for LED blinking or toggling signals
 ***************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}


/*
 * IRQ Configuration and ISR handling
 */

/***************************************************************
 * @fn        - GPIO_IRQConfig
 *
 * @brief     - Configures NVIC interrupt number, priority, and enable/disable
 *
 * @param[in] - IRQNumber : Interrupt number to configure
 * @param[in] - IRQPriority : Priority level of the interrupt
 * @param[in] - EnorDi : ENABLE or DISABLE macro
 *
 * @return    - none
 *
 * @Note      - Must be configured before enabling GPIO interrupts
 ***************************************************************/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/***************************************************************
 * @fn        - GPIO_IRQHandling
 *
 * @brief     - Handles interrupt event for the given GPIO pin
 *
 * @param[in] - PinNumber : Pin number that triggered the interrupt
 *
 * @return    - none
 *
 * @Note      - Clears the interrupt flag inside EXTI
 ***************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{

}






