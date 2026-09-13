/*
 * stm32f407xx.h
 *
 *  Created on: Sep 11, 2026
 *      Author: KIRANA M K
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_


#include<stdint.h>
#define __vo volatile
// Base addresses of Memory sections
#define FLASH_BASEADDR						0x08000000U // Base address of internal Flash memory
#define SRAM1_BASEADDR 						0x20000000U // Base address of main internal SRAM1 (112 KB)
#define SRAM2_BASEADDR 						0x2001C000U // Base address of auxiliary internal SRAM2 (16 KB, follows SRAM1)
#define SRAM 								SRAM1_BASEADDR // Generic SRAM alias (points to start of SRAM1 by default)
#define ROM_BASEADDR 						0x1FFF0000U // Base address of system memory (ROM, contains bootloader)

/*
* AHBx and APBx Bus Peripheral base addresses
*/

#define PERIPH_BASEADDR        				0x40000000U  		  // Base address for all peripheral registers
#define APB1PERIPH_BASEADDR    				PERIPH_BASEADDR // Base address for APB1 bus peripherals (USART2–5, TIM2–7, I2C1–3, etc.)
#define APB2PERIPH_BASEADDR   				0x40010000U  		// Base address for APB2 bus peripherals (USART1, TIM1, ADC1–3, SPI1, etc.)
#define AHB1PERIPH_BASEADDR    				0x40020000U  		// Base address for AHB1 bus peripherals (GPIOA–I, RCC, DMA1/2, etc.)
#define AHB2PERIPH_BASEADDR    				0x50000000U  		// Base address for AHB2 bus peripherals (USB OTG FS, RNG, etc.)

/*
* Base addresses of peripherals which are hanging on AHB1 bus
* TODO : Complete for all other peripherals
*/

#define GPIOA_BASEADDR   					(AHB1PERIPH_BASEADDR + 0x0000)  // Base address of GPIO Port A
#define GPIOB_BASEADDR   					(AHB1PERIPH_BASEADDR + 0x0400)  // Base address of GPIO Port B
#define GPIOC_BASEADDR   					(AHB1PERIPH_BASEADDR + 0x0800)  // Base address of GPIO Port C
#define GPIOD_BASEADDR   					(AHB1PERIPH_BASEADDR + 0x0C00)  // Base address of GPIO Port D
#define GPIOE_BASEADDR   					(AHB1PERIPH_BASEADDR + 0x1000)  // Base address of GPIO Port E

#define RCC_BASEADDR 						(AHB1PERIPH_BASEADDR + 0x3800)  // Base address of RCC register

/*
* Base addresses of peripherals which are hanging on APB1 bus
* TODO : Complete for all other peripherals
*/

#define I2C1_BASEADDR   					APB1PERIPH_BASEADDR + 0x5400)  // Base address of I2C1 peripheral
#define I2C2_BASEADDR   					(APB1PERIPH_BASEADDR + 0x5800)  // Base address of I2C2 peripheral
#define I2C3_BASEADDR   					(APB1PERIPH_BASEADDR + 0x5C00)  // Base address of I2C3 peripheral

#define SPI2_BASEADDR   					(APB1PERIPH_BASEADDR + 0x3800)  // Base address of SPI2 peripheral
#define SPI3_BASEADDR   					(APB1PERIPH_BASEADDR + 0x3C00)  // Base address of SPI3 peripheral

#define USART2_BASEADDR 					(APB1PERIPH_BASEADDR + 0x4400)  // Base address of USART2 peripheral
#define USART3_BASEADDR 					(APB1PERIPH_BASEADDR + 0x4800)  // Base address of USART3 peripheral

#define UART4_BASEADDR 						(APB1PERIPH_BASEADDR + 0x4C00)  // Base address of UART4 peripheral
#define UART5_BASEADDR 						(APB1PERIPH_BASEADDR + 0x5000)  // Base address of UART5 peripheral

/*
* Base addresses of peripherals which are hanging on APB2 bus
* TODO : Complete for all other peripherals
*/

#define EXTI_BASEADDR   (APB2PERIPH_BASEADDR + 0x3C00)  // Base address of EXTI (External Interrupt/Event Controller)
#define SPI1_BASEADDR   (APB2PERIPH_BASEADDR + 0x3000)  // Base address of SPI1 (Serial Peripheral Interface 1)
#define USART1_BASEADDR (APB2PERIPH_BASEADDR + 0x1000)  // Base address of USART1 (Universal Synchronous/Asynchronous Receiver/Transmitter 1)
#define USART6_BASEADDR (APB2PERIPH_BASEADDR + 0x1400)  // Base address of USART6 (Universal Synchronous/Asynchronous Receiver/Transmitter 6)
#define SYSCFG_BASEADDR (APB2PERIPH_BASEADDR + 0x3800)  // Base address of SYSCFG (System Configuration Controller)


// SPI1 register definitions
#define SPI1_CR1        (SPI1_BASEADDR + 0x00)  // Control Register 1
#define SPI1_CR2        (SPI1_BASEADDR + 0x04)  // Control Register 2
#define SPI1_SR         (SPI1_BASEADDR + 0x08)  // Status Register
#define SPI1_DR         (SPI1_BASEADDR + 0x0C)  // Data Register
#define SPI1_CRCPR      (SPI1_BASEADDR + 0x10)  // CRC Polynomial Register
#define SPI1_RXCRCR     (SPI1_BASEADDR + 0x14)  // RX CRC Register
#define SPI1_TXCRCR     (SPI1_BASEADDR + 0x18)  // TX CRC Register
#define SPI1_I2SCFGR    (SPI1_BASEADDR + 0x1C)  // I2S Configuration Register
#define SPI1_I2SPR      (SPI1_BASEADDR + 0x20)  // I2S Prescaler Register



/*************peripheral register definition structures***************/

/*Note : Registers of a peripheral are specific to mcu
* For example : Number of Registers of SPI peripheral of STM32F4x family of MCUs may be different(more or less)
* Compared to number of registers of SPI peripheral of STM32Lx or STM32F0x family of MCUs
* Please check your Device RM
*/

typedef struct{

	__vo uint32_t MODER;     // 0x00: Pin mode (input, output, alt, analog)
	__vo int32_t OTYPER;    // 0x04: Output type (push-pull or open-drain)
	__vo uint32_t OSPEEDR;   // 0x08: Output speed (low, medium, high, very high)
	__vo uint32_t PUPDR;     // 0x0C: Pull-up / Pull-down configuration
	__vo uint32_t IDR;       // 0x10: Input data register (read pin state)
	__vo uint32_t ODR;       // 0x14: Output data register (write pin state)
	__vo uint32_t BSRR;      // 0x18: Bit set/reset register (atomic set/reset)
	__vo uint32_t LCKR;      // 0x1C: Configuration lock register (lock settings)
	__vo uint32_t AFR[2];    // 0x20-0x24: Alternate function registers (AFR[0]=pins 0-7(Low register), AFR[1]=pins 8-15(High register))

} GPIO_RegDef_t;

typedef struct{

    __vo uint32_t  CR;          // 0x00: Clock control register
    __vo uint32_t  PLLCFGR;     // 0x04: PLL configuration register
    __vo uint32_t  CFGR;        // 0x08: Clock configuration register
    __vo uint32_t  CIR;         // 0x0C: Clock interrupt register
    __vo uint32_t  AHB1RSTR;    // 0x10: AHB1 peripheral reset register
    __vo uint32_t  AHB2RSTR;    // 0x14: AHB2 peripheral reset register
    __vo uint32_t  AHB3RSTR;    // 0x18: AHB3 peripheral reset register
    uint32_t  RESERVED0;        // 0x1C: Reserved
    __vo uint32_t  APB1RSTR;    // 0x20: APB1 peripheral reset register
    __vo uint32_t  APB2RSTR;    // 0x24: APB2 peripheral reset register
    uint32_t  RESERVED1[2];     // 0x28–0x2C: Reserved
    __vo uint32_t  AHB1ENR;     // 0x30: AHB1 peripheral clock enable register
    __vo uint32_t  AHB2ENR;     // 0x34: AHB2 peripheral clock enable register
    __vo uint32_t  AHB3ENR;     // 0x38: AHB3 peripheral clock enable register
    uint32_t  RESERVED2;        // 0x3C: Reserved
    __vo uint32_t  APB1ENR;     // 0x40: APB1 peripheral clock enable register
    __vo uint32_t  APB2ENR;     // 0x44: APB2 peripheral clock enable register
    uint32_t  RESERVED3[2];     // 0x48–0x4C: Reserved
    __vo uint32_t  AHB1LPENR;   // 0x50: AHB1 low power enable register
    __vo uint32_t  AHB2LPENR;   // 0x54: AHB2 low power enable register
    __vo uint32_t  AHB3LPENR;   // 0x58: AHB3 low power enable register
    uint32_t  RESERVED4;        // 0x5C: Reserved
    __vo uint32_t  APB1LPENR;   // 0x60: APB1 low power enable register
    __vo uint32_t  APB2LPENR;   // 0x64: APB2 low power enable register
    uint32_t  RESERVED5[2];     // 0x68–0x6C: Reserved
    __vo uint32_t  BDCR;        // 0x70: Backup domain control register
    uint32_t  RESERVED6[2];     // 0x74–0x78: Reserved
    __vo uint32_t  SSCGR;       // 0x80: Spread spectrum clock generation register
    __vo uint32_t  PLLI2SCFGR;  // 0x84: PLLI2S configuration register
    __vo uint32_t  PLLSAICFGR;  // 0x88: PLLSAI configuration register
    __vo uint32_t  DCKCFGR;     // 0x8C: Dedicated clock configuration register

} RCC_RegDef_t;



/*
 * peripheral definitions (Peripheral base addresses type casted to xxx_RegDef_t)
 * Or base addresses are type casted to GPIO_RegDef_t *  structure pointer type
 */

#define GPIOA 			((GPIO_RegDef_t*)GPIOA_BASEADDR) // Pointer(address) of data type GPIO_RegDef_t* to GPIOA register base address
#define GPIOB 			((GPIO_RegDef_t*)GPIOB_BASEADDR) // Pointer(address) of data type GPIO_RegDef_t* to GPIOB register base address
#define GPIOC 			((GPIO_RegDef_t*)GPIOC_BASEADDR) // Pointer(address) of data type GPIO_RegDef_t* to GPIOC register base address
#define GPIOD 			((GPIO_RegDef_t*)GPIOD_BASEADDR) // Pointer(address) of data type GPIO_RegDef_t* to GPIOD register base address
#define GPIOE 			((GPIO_RegDef_t*)GPIOE_BASEADDR) // Pointer(address) of data type GPIO_RegDef_t* to GPIOE register base address

#define RCC 			((RCC_RegDef_t*)RCC_BASEADDR) // Pointer(address) of data type RCC_RegDef_t* to RCC register base address
















#endif /* INC_STM32F407XX_H_ */
