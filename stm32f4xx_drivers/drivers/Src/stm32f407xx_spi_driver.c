/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Oct 2, 2026
 *      Author: KIRANA M K
 */

#include "stm32f407xx_spi_driver.h" //contains driver specific data


/***************************************************************************************
 * @fn        - SPI_PeripheralClockControl
 *
 * @brief     - Enables or disables the peripheral clock for the selected SPI
 *
 * @param[in] - pSPIx  : Pointer to the selected SPI peripheral register structure
 * @param[in] - EnorDi : Enable or disable the SPI peripheral clock
 *
 * @return    - none
 *
 * @Note      - Used to control the clock for SPI1, SPI2, or SPI3
 ***************************************************************************************/
void SPI_PeripheralClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}

}


/***************************************************************************************
 * @fn        - SPI_Init
 *
 * @brief     - Initializes the selected SPI peripheral with the given configuration
 *
 * @param[in] - pSPIHandle : Pointer to the SPI handle containing peripheral address
 *                           and configuration settings
 *
 * @return    - none
 *
 * @Note      - The SPI configuration is provided through the SPI handle structure
 ***************************************************************************************/
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	// first lets configure the SPI_CR1 register
	uint32_t tempreg = 0;

	//1. configure the device mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	//2. Configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//bidi mode should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
	}else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//bidi mode should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);


	}else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI mode should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
		//RXONLY bit must be set
		tempreg |= ~(1 << SPI_CR1_RXONLY);
	}

	//3. Configure the clock speed(baud rate)
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4. Configure Data frame format
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//5. Configure CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	//6. Configure CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	//7.  Configure SSM
	tempreg |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;

	//Copy the configurations into SPI_CR1 register
	pSPIHandle->pSPIx->CR1 = tempreg;

	// Lets configure the SPI_CR2 register
	//clear tempreg
	tempreg = 0;

	// 8. Configure RX DMA
	tempreg |= pSPIHandle->SPIConfig.SPI_RXDMAEN << SPI_CR2_RXDMAEN;

	// 9. Configure TX DMA
	tempreg |= pSPIHandle->SPIConfig.SPI_TXDMAEN << SPI_CR2_TXDMAEN;

	// 10. Configure SS output enable
	tempreg |= pSPIHandle->SPIConfig.SPI_SSOE << SPI_CR2_SSOE;

	// 11. Configure error interrupt
	tempreg |= pSPIHandle->SPIConfig.SPI_ERRIE << SPI_CR2_ERRIE;

	// 12. Configure RXNE interrupt
	tempreg |= pSPIHandle->SPIConfig.SPI_RXNEIE << SPI_CR2_RXNEIE;

	// 13. Configure TXE interrupt
	tempreg |= pSPIHandle->SPIConfig.SPI_TXEIE << SPI_CR2_TXEIE;

	// Copy the configurations into SPI_CR2 register
	pSPIHandle->pSPIx->CR2 = tempreg;

}

/***************************************************************************************
 * @fn        - SPI_DeInit
 *
 * @brief     - Resets the selected SPI peripheral registers to their reset values
 *
 * @param[in] - pSPIx : Pointer to the selected SPI peripheral register structure
 *
 * @return    - none
 *
 * @Note      - Used to de-initialize SPI1, SPI2, or SPI3
 ***************************************************************************************/
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if(pSPIx == SPI1)
	{
		SPI1_REGISTER_RESET();
	}
	else if(pSPIx == SPI2)
	{
		SPI2_REGISTER_RESET();
	}
	else if(pSPIx == SPI3)
	{
		SPI3_REGISTER_RESET();
	}

}


/***************************************************************************************
 * @fn        - SPI_SendData
 *
 * @brief     - Transmits data through the selected SPI peripheral
 *
 * @param[in] - pSPIx     : Pointer to the selected SPI peripheral register structure
 * @param[in] - pTxBuffer : Pointer to the transmit data buffer
 * @param[in] - Len       : Number of bytes to transmit
 *
 * @return    - none
 *
 * @Note      - Used for transmitting data in SPI communication
 ***************************************************************************************/
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{

}


/***************************************************************************************
 * @fn        - SPI_ReceiveData
 *
 * @brief     - Receives data from the selected SPI peripheral
 *
 * @param[in] - pSPIx     : Pointer to the selected SPI peripheral register structure
 * @param[in] - pRxBuffer : Pointer to the receive data buffer
 * @param[in] - Len       : Number of bytes to receive
 *
 * @return    - none
 *
 * @Note      - Used for receiving data in SPI communication
 ***************************************************************************************/
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}


/***************************************************************************************
 * @fn        - SPI_IRQInterruptConfig
 *
 * @brief     - Enables or disables the SPI interrupt in the NVIC
 *
 * @param[in] - IRQNumber : NVIC interrupt request number
 * @param[in] - EnorDi    : Enable or disable the interrupt
 *
 * @return    - none
 *
 * @Note      - Used to configure the NVIC interrupt for the selected SPI interrupt
 ***************************************************************************************/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}


/***************************************************************************************
 * @fn        - SPI_IRQPriorityConfig
 *
 * @brief     - Configures the NVIC priority for the given SPI interrupt
 *
 * @param[in] - IRQNumber   : NVIC interrupt request number
 * @param[in] - IRQPriority : Priority value for the given IRQ
 *
 * @return    - none
 *
 * @Note      - Used to set the interrupt priority of the selected SPI interrupt
 ***************************************************************************************/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{

}


/***************************************************************************************
 * @fn        - SPI_IRQHandling
 *
 * @brief     - Handles the interrupt events generated by the selected SPI peripheral
 *
 * @param[in] - pHandle : Pointer to the SPI handle containing peripheral address
 *                         and configuration settings
 *
 * @return    - none
 *
 * @Note      - Called from the SPI ISR to handle SPI interrupt events
 ***************************************************************************************/
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}










