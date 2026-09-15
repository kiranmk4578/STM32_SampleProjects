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






