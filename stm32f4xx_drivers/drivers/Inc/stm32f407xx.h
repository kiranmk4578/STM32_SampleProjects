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

/******************************START: Processor Specific Details ***************************
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0   ((__vo uint32_t*)0xE000E100)  // Interrupt Set-Enable Register 0 → enables IRQs 0–31
#define NVIC_ISER1   ((__vo uint32_t*)0xE000E104)  // Interrupt Set-Enable Register 1 → enables IRQs 32–63
#define NVIC_ISER2   ((__vo uint32_t*)0xE000E108)  // Interrupt Set-Enable Register 2 → enables IRQs 64–95

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */

#define NVIC_ICER0   ((__vo uint32_t*)0xE000E180)  // Interrupt Clear-Enable Register 0 → disables IRQs 0–31
#define NVIC_ICER1   ((__vo uint32_t*)0xE000E184)  // Interrupt Clear-Enable Register 1 → disables IRQs 32–63
#define NVIC_ICER2   ((__vo uint32_t*)0xE000E188)  // Interrupt Clear-Enable Register 2 → disables IRQs 64–95

/*
 * ARM Cortex Mx Processor Priority register Addresses
 */
#define NVIC_PR_BASE_ADDR   ((__vo uint32_t*)0xE000E400) //Base address of NVIC Interrupt Priority Registers (IPR

/* Number of implemented priority bits per IRQ field (upper 4 bits only) and this value is specific to microcontroller(for eg for TI it is 3) */
#define NO_PR_BITS_IMPLEMENTED 4


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
	__vo uint32_t OTYPER;    // 0x04: Output type (push-pull or open-drain)
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

typedef struct
{
    __vo uint32_t IMR;    // 0x00 : Interrupt Mask Register
    __vo uint32_t EMR;    // 0x04 : Event Mask Register
    __vo uint32_t RTSR;   // 0x08 : Rising Trigger Selection Register
    __vo uint32_t FTSR;   // 0x0C : Falling Trigger Selection Register
    __vo uint32_t SWIER;  // 0x10 : Software Interrupt/Event Register
    __vo uint32_t PR;     // 0x14 : Pending Register

} EXTI_RegDef_t;


typedef struct
{
    __vo uint32_t MEMRMP;     // 0x00 : Memory remap register
    __vo uint32_t PMC;        // 0x04 : Peripheral mode configuration
    __vo uint32_t EXTICR[4];  // 0x08–0x14 : External interrupt configuration registers
    uint32_t RESERVED[2];     // 0x18–0x1C : Two reserved slots (each 4 bytes)
    __vo uint32_t CMPCR;      // 0x20 : Compensation cell control register

} SYSCFG_RegDef_t;

typedef struct
{
	__vo uint32_t CR1;       // 0x00: Control register 1
	__vo uint32_t CR2;       // 0x04: Control register 2
    __vo uint32_t SR;          // 0x08: Status register
    __vo uint32_t DR;          // 0x0C: Data register
    __vo uint32_t CRCPR;       // 0x10: CRC polynomial register
    __vo uint32_t RXCRCR;      // 0x14: RX CRC register
    __vo uint32_t TXCRCR;      // 0x18: TX CRC register
    __vo uint32_t I2SCFGR;     // 0x1C: I2S configuration register
    __vo uint32_t I2SPR;       // 0x20: I2S prescaler register

} SPI_RegDef_t;


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

#define EXTI 			((EXTI_RegDef_t*)EXTI_BASEADDR) // Pointer to EXTI_RegDef_t structure, pointing to the EXTI base address.

#define SYSCFG			((SYSCFG_RegDef_t*)SYSCFG_BASEADDR) // Pointer to SYSCFG_RegDef_t structure, pointing to the SYSCFG base address.

#define SPI1    		((SPI_RegDef_t*)SPI1_BASEADDR)  // Pointer to the SPI1 peripheral register structure
#define SPI2    		((SPI_RegDef_t*)SPI2_BASEADDR)  // Pointer to the SPI2 peripheral register structure
#define SPI3    		((SPI_RegDef_t*)SPI3_BASEADDR)  // Pointer to the SPI3 peripheral register structure
/*
* Clock Enable Macros for GPIOx peripherals
*/

#define GPIOA_PCLK_EN() 	( RCC->AHB1ENR |= (1 << 0) ) // Enable clock for GPIOA peripheral
#define GPIOB_PCLK_EN() 	( RCC->AHB1ENR |= (1 << 1) ) // Enable clock for GPIOB peripheral
#define GPIOC_PCLK_EN() 	( RCC->AHB1ENR |= (1 << 2) ) // Enable clock for GPIOC peripheral
#define GPIOD_PCLK_EN() 	( RCC->AHB1ENR |= (1 << 3) ) // Enable clock for GPIOD peripheral
#define GPIOE_PCLK_EN() 	( RCC->AHB1ENR |= (1 << 4) ) // Enable clock for GPIOE peripheral

/*
* Clock Enable Macros for I2Cx peripherals
*/
#define I2C1_PCLK_EN() 	( RCC->APB1ENR |= (1 << 21) ) // Enable clock for I2C1 peripheral
#define I2C2_PCLK_EN() 	( RCC->APB1ENR |= (1 << 22) ) // Enable clock for I2C2 peripheral
#define I2C3_PCLK_EN() 	( RCC->APB1ENR |= (1 << 23) ) // Enable clock for I2C3 peripheral


/*
* Clock Enable Macros for SPIx peripherals
*/

#define SPI2_PCLK_EN() 	( RCC->APB1ENR |= (1 << 14) ) // Enable clock for SPI2 peripheral
#define SPI3_PCLK_EN() 	( RCC->APB1ENR |= (1 << 15) ) // Enable clock for SPI3 peripheral
#define SPI1_PCLK_EN() 	( RCC->APB2ENR |= (1 << 12) ) // Enable clock for SPI1 peripheral

/*
* Clock Enable Macros for USARTx peripherals
*/

#define USART2_PCLK_EN() 	( RCC->APB1ENR |= (1 << 17) ) // Enable clock for USART2 peripheral
#define USART3_PCLK_EN() 	( RCC->APB1ENR |= (1 << 18) ) // Enable clock for USART3 peripheral

#define USART1_PCLK_EN() 	( RCC->APB2ENR |= (1 << 4) ) // Enable clock for USART1 peripheral
#define USART6_PCLK_EN() 	( RCC->APB2ENR |= (1 << 5) ) // Enable clock for USART6 peripheral

/*
* Clock Enable Macros for SYSCFG peripherals
*/

#define SYSCFG_PCLK_EN() 	( RCC->APB2ENR |= (1 << 14) ) // Enable clock for SYSCFG peripheral


/*************************************************************************************************/

/*
* Clock Disable Macros for GPIOx peripherals
*/

#define GPIOA_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 0) )   // Disable GPIOA clock
#define GPIOB_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 1) )   // Disable GPIOB clock
#define GPIOC_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 2) )   // Disable GPIOC clock
#define GPIOD_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 3) )   // Disable GPIOD clock
#define GPIOE_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 4) )   // Disable GPIOE clock

/*
* Clock Disable Macros for I2Cx peripherals
*/
#define I2C1_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 21) ) //  Disable clock for I2C1 peripheral
#define I2C2_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 22) ) //  Disable clock for I2C2 peripheral
#define I2C3_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 23) ) //  Disable clock for I2C3 peripheral

/*
* Clock Disable Macros for SPIx peripherals
*/

#define SPI2_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 14) ) // Disable clock for SPI2 peripheral
#define SPI3_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 15) ) // Disable clock for SPI3 peripheral

#define SPI1_PCLK_DI() 	( RCC->APB2ENR &= ~(1 << 12) ) // Disable clock for SPI1 peripheral

/*
* Clock Disable Macros for USARTx peripherals
*/

#define USART2_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 17) ) // Disable clock for USART2 peripheral
#define USART3_PCLK_DI() 	( RCC->APB1ENR &= ~(1 << 18) ) // Disable clock for USART3 peripheral

#define USART1_PCLK_DI() 	( RCC->APB2ENR &= ~(1 << 4) ) // Disable clock for USART1 peripheral
#define USART6_PCLK_DI() 	( RCC->APB2ENR &= ~(1 << 5) ) // Disable clock for USART6 peripheral

/*
* Clock Disable Macros for SYSCFG peripherals
*/

#define SYSCFG_PCLK_DI() 	( RCC->APB2ENR &= ~(1 << 14) ) // Disable clock for SYSCFG peripheral

/*
* MACROs to reset GPIOx peripherals
*/
#define GPIOA_REGISTER_RESET()		do{ ( RCC->AHB1RSTR |= (1 << 0)); RCC->AHB1RSTR &= ~(1 << 0); }while(0)//reset registers of GPIOA peripheral
#define GPIOB_REGISTER_RESET()		do{ ( RCC->AHB1RSTR |= (1 << 1)); RCC->AHB1RSTR &= ~(1 << 1); }while(0)//reset registers of GPIOB peripheral
#define GPIOC_REGISTER_RESET()		do{ ( RCC->AHB1RSTR |= (1 << 2)); RCC->AHB1RSTR &= ~(1 << 2); }while(0)//reset registers of GPIOC peripheral
#define GPIOD_REGISTER_RESET()		do{ ( RCC->AHB1RSTR |= (1 << 3)); RCC->AHB1RSTR &= ~(1 << 3); }while(0)//reset registers of GPIOD peripheral
#define GPIOE_REGISTER_RESET()		do{ ( RCC->AHB1RSTR |= (1 << 4)); RCC->AHB1RSTR &= ~(1 << 4); }while(0)//reset registers of GPIOE peripheral

#define SPI1_REGISTER_RESET()    do{ (RCC->APB2RSTR |=  (1 << 12)); RCC->APB2RSTR &= ~(1 << 12); }while(0)// Reset registers of SPI1 peripheral

#define SPI2_REGISTER_RESET()    do{ (RCC->APB1RSTR |=  (1 << 14)); RCC->APB1RSTR &= ~(1 << 14); }while(0) // Reset registers of SPI2 peripheral
#define SPI3_REGISTER_RESET()    do{ (RCC->APB1RSTR |=  (1 << 15)); RCC->APB1RSTR &= ~(1 << 15); }while(0) // Reset registers of SPI3 peripheral
/*
 Macro to convert GPIO base address into numeric code
 Uses chained ternary operators:
 - If x == GPIOA → return 0
 - If x == GPIOB → return 1
 - If x == GPIOC → return 2
 - If x == GPIOD → return 3
 - If x == GPIOE → return 4
*/
#define GPIO_BASEADDR_TO_CODE(x)	  ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
										(x == GPIOE)?4:0 )

//some generic MACROs

#define ENABLE          1   	// Enable state
#define DISABLE         0   	// Disable state
#define SET             ENABLE  // Alias for enable
#define RESET           DISABLE // Alias for disable
#define GPIO_PIN_SET    1   	// GPIO pin logic high
#define GPIO_PIN_RESET  0   	// GPIO pin logic low
#define FLAG_RESET      RESET
#define FLAG_SET 		SET

/*IRQ(Interrupt Request) Numbers of STM32F407X MCU
• NOTE: update these macros with valid values according to your
• TODO: You may complete this list for other peripherals
*/
#define IRQ_NO_EXTI0        6   // Interrupt request number for EXTI line 0
#define IRQ_NO_EXTI1        7   // Interrupt request number for EXTI line 1
#define IRQ_NO_EXTI2        8   // Interrupt request number for EXTI line 2
#define IRQ_NO_EXTI3        9   // Interrupt request number for EXTI line 3
#define IRQ_NO_EXTI4        10  // Interrupt request number for EXTI line 4
#define IRQ_NO_EXTI9_5      23  // Shared IRQ number for EXTI lines 5 to 9
#define IRQ_NO_EXTI15_10    40  // Shared IRQ number for EXTI lines 10 to 15


// NVIC interrupt priority levels (0 = highest, larger = lower priority)
#define NVIC_IRQ_PRI0   0   // Priority level for IRQ 0
#define NVIC_IRQ_PRI1   1   // Priority level for IRQ 1
#define NVIC_IRQ_PRI2   2   // Priority level for IRQ 2
#define NVIC_IRQ_PRI3   3   // Priority level for IRQ 3
#define NVIC_IRQ_PRI4   4   // Priority level for IRQ 4
#define NVIC_IRQ_PRI5   5   // Priority level for IRQ 5
#define NVIC_IRQ_PRI6   6   // Priority level for IRQ 6
#define NVIC_IRQ_PRI7   7   // Priority level for IRQ 7
#define NVIC_IRQ_PRI8   8   // Priority level for IRQ 8
#define NVIC_IRQ_PRI9   9   // Priority level for IRQ 9
#define NVIC_IRQ_PRI10  10  // Priority level for IRQ 10
#define NVIC_IRQ_PRI11  11  // Priority level for IRQ 11
#define NVIC_IRQ_PRI12  12  // Priority level for IRQ 12
#define NVIC_IRQ_PRI13  13  // Priority level for IRQ 13
#define NVIC_IRQ_PRI14  14  // Priority level for IRQ 14
#define NVIC_IRQ_PRI15  15  // Priority level for IRQ 15

/***************************************************************************
 *Bit position definitions of SPI peripheral
 ***************************************************************************/
// Bit positions of SPI_CR1 register
#define SPI_CR1_CPHA        0   // Bit 0: Clock phase
#define SPI_CR1_CPOL        1   // Bit 1: Clock polarity
#define SPI_CR1_MSTR        2   // Bit 2: Master selection
#define SPI_CR1_BR          3   // Bits 3-5: Baud rate control
#define SPI_CR1_SSM         9   // Bit 9: Software slave management
#define SPI_CR1_RXONLY      10  // Bit 10: Receive-only mode
#define SPI_CR1_DFF         11  // Bit 11: Data frame format
#define SPI_CR1_BIDIOE      14  // Bit 14: Output enable in bidirectional mode
#define SPI_CR1_BIDIMODE    15  // Bit 15: Bidirectional data mode enable

// Bit positions of SPI_CR2 register
#define SPI_CR2_RXDMAEN    0   // Bit 0: RX buffer DMA enable
#define SPI_CR2_TXDMAEN    1   // Bit 1: TX buffer DMA enable
#define SPI_CR2_SSOE       2   // Bit 2: SS output enable
#define SPI_CR2_ERRIE      5   // Bit 5: Error interrupt enable
#define SPI_CR2_RXNEIE     6   // Bit 6: RX buffer not empty interrupt enable
#define SPI_CR2_TXEIE      7   // Bit 7: TX buffer empty interrupt enable

/*
 * SPI Status Register (SPI_SR) Bit Positions
 */
#define SPI_SR_RXNE       0   // Bit 0: Receive buffer not empty
#define SPI_SR_TXE        1   // Bit 1: Transmit buffer empty
#define SPI_SR_CHSIDE     2   // Bit 2: Channel side
#define SPI_SR_UDR        3   // Bit 3: Underrun flag
#define SPI_SR_CRCERR     4   // Bit 4: CRC error flag
#define SPI_SR_MODF       5   // Bit 5: Mode fault flag
#define SPI_SR_OVR        6   // Bit 6: Overrun flag
#define SPI_SR_BSY        7   // Bit 7: Busy flag
#define SPI_SR_FRE        8   // Bit 8: Frame format error



#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"




#endif /* INC_STM32F407XX_H_ */
