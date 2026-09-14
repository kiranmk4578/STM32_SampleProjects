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
void GPIO_PeripheralClockControl(void);


/*
 * Init and De-Init
 */
void GPIO_Init(void);
void GPIO_DeInit(void);


/*
 * Data read and write
 */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);

















