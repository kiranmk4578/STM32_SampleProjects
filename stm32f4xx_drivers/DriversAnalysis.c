

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

<< by 1 position( 2<<1 = 4 because left shifting is doubling the value or multiplying by 2 that is --> 2*2 => 4 ) 
//Thus in the binary we should have value 4
                                                     8 4 2 1
//In binary: |0000 0000|0000 0000|0000 0000|0 0 0 0  0 1 0 0|

<< by 2nd position( 2<<2 = 8) that is --> 4*2 => 8 
                                                     8 4 2 1
//In binary: |0000 0000|0000 0000|0000 0000|0 0 0 0  1 0 0 0|

//Now store this value in 32bit variable temp(because MODER register is 32bit size)
// copy the value in temp to MODER register 

