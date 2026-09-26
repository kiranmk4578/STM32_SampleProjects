
//MODE register
31   30 | 29   28 | 27   26 | 25   24 | 23   22 | 21   20 | 19   18 | 17   16 |
MODER15 | MODER14 | MODER13 | MODER12 | MODER11 | MODER10 | MODER9  | MODER8  |

15   14 | 13   12 | 11   10 | 9    8  | 7    6   | 5    4  | 3    2   | 1    0  |
MODER7  | MODER6  | MODER5  | MODER4  | MODER3   | MODER2  | MODER1   | MODER0  |

-> 2bits per pin(For eg MODER0 is set mode of Pin0, MODER1 is for Pin1 etc) 
00(Dec 0): Input (reset state)
01(Dec 1): General purpose output mode
10(Dec 2: Alternate function mode
11(Dec 3): Analog mode
 
// These 2 are from user application --> GPIO_PinConfig.GPIO_PinMode and GPIO_PinConfig.GPIO_PinNumber
// 2bits per each pin is used in MODE register hence we are multiplying with 2 in below equation 

temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );

//Eg1: Mode 2 and pin 0 (set pin 0 in mode 2)
temp = 2 << (2 * 0) ); // temp is 32bit register  
temp = 2 << 0 // 2 left shift by 0th position
												 8 4 2 1
//In binary: |0000 0000|0000 0000|0000 0000|0000 0 0 1 0|


//Eg2: Mode 2(Alt fn mode) and pin 1(set pin 1 in mode 2)
 
temp = 2 << (2 * 1) ); // temp is 32bit register  
temp = 2 << 2 // 2 left shift by 2th position

<< by 1 position( 2<<1 = 4 because left shifting is doubling the value or multiplying by 2 that is --> 2*2 => 4 ) /*use this method because it is easy to understand and perform
and write the results */
//Thus in the binary we should have value 4
                                                     8 4 2 1
//In binary: |0000 0000|0000 0000|0000 0000|0 0 0 0  0 1 0 0|   -- before this we had this data(2 or 01 is in original poisition or 0th positon) --> |0 0 0 0  0 0 1 0|

<< by 2nd position( 2<<2 = 8) that is --> 4*2 => 8 
                                                     8 4 2 1
//In binary: |0000 0000|0000 0000|0000 0000|0 0 0 0  1 0 0 0|

// Now store this value in 32bit variable temp(because MODER register is 32bit size)
// copy the value in temp to MODER register 
pGPIOHandle->pGPIOx->MODER |= temp 
/* this will set pin 1 in ALT Fn mode while retaining the other pins status or values of other bits in
the MODER register as we have used the bitwise OR operator. but bitwise OR does not work if the bit is 
already 1 as it won't make it 0(or if we use bitwise OR we should make sure the bit on which we are performing bit manipulation 
are already reset or 0) 

// Hence we should use one more instruction to clear the bits on which we are going to perform bit manipulation before using 
bitwise OR. 
For eg: pGPIOHandle->pGPIOx->MODER &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // Register &= ~(1 << pos);




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