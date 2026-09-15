/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Sep 14, 2026
 *      Author: KIRANA M K
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h" //contains MCU specific data

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */


/*
 * This the configuration structure for a GPIO pin
 */

typedef struct
{
    uint8_t GPIO_PinNumber;       // Pin number (0–15 for GPIOx)
    uint8_t GPIO_PinMode;         // Mode: Input, Output, Alt Function, Analog
    uint8_t GPIO_PinSpeed;        // Speed: Low, Medium, High, Very High
    uint8_t GPIO_PinPuPdControl;  // Pull-up / Pull-down configuration
    uint8_t GPIO_PinOPType;       // Output type: Push-pull or Open-drain
    uint8_t GPIO_PinAltFunMode;   // Alternate function mode (AF0–AF15)

} GPIO_PinConfig_t;



/*
* This is a Handle structure for a GPIO pin
*/

typedef struct
{
	GPIO_RegDef_t *pGPIOx; 			// This holds the base address of the GPIO port(A,B,C etc) to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;   // This variable holds the pin configuration settings

}GPIO_Handle_t;


/**************************************************************************************************************************
 * 								APIs supported by this driver
 *			For more information about the APIs check the function definitions
 **************************************************************************************************************************/

/*
 * Peripheral Clock setup
 */
// Enable or disable the clock for a given GPIO port
void GPIO_PeripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);


/*
 * Init and De-Init
 */
// Configure a GPIO pin with the given settings
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

// Reset all registers of the given GPIO port
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * Data read and write
 */
// Read the logic value (0/1) from a specific pin
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// Read the 16bit input value of the entire port
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

// Write a logic value (0/1) to a specific pin
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

// Write a 16bit value to all pins of the port
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

// Flip the current output state of a specific pin
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ Configuration and ISR handling
 */

// Configure NVIC interrupt number, priority, and enable/disable
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);

// Handle interrupt event for the given GPIO pin
void GPIO_IRQHandling(uint8_t PinNumber);


















