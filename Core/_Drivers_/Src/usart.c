#include "../../_Drivers_/Inc/usart.h"

void usart_init()
{
	RCC->APB2ENR |= (1 << 4); //clock enable

	USART1->CR1 |= (1 << 13); //usart enable

	USART1->CR1 &= ~(1 << 12); //8 bits data format
	USART1->CR1 &= ~(1 << 15); //oversampling by 16
	USART1->CR1 &= ~(1 << 10); //parity control disabled

	USART1->BRR &= ~0xFFFF; //setting baud rate on 9600
	USART1->BRR |= 14;
	USART1->BRR |= (546 << 4);

	USART1->CR1 |= (1 << 3); //transmitter enable
}

void usart_send_byte(uint8_t data)
{
	while(!(USART1->SR & (1 << 7))); //waits for the TXE bit to be 1
	USART1->DR = data; //write the data into data register
	while(!((USART1->SR) & (1 << 6))); //waits for the transmission complete bit
}

/* ****NEEDS TESTING****
void usart_send_data(uint8_t *tx_buffer, uint32_t data_len)
{
	while(data_len > 0)
	{
		while(!(USART1->SR & (1 << 7))); //waits for the TXE bit to be 1
		USART1->DR = *tx_buffer; //write the data into data register
		tx_buffer++; //increment to the next byte
		data_len--;
	}
	while(!((USART1->SR) & (1 << 6))); //waits for the transmission complete bit
}*/

/* ****NEEDS TESTING****
void usart_receive_byte(uint8_t *data)
{
	while(!(USART1->SR & (1 << 5))); //waits for the RXNE bit to be 1
	*data = USART1->DR; //read the data from data register
	while(!((USART1->SR) & (1 << 6))); //waits for the transmission complete bit
}*/

/* ****NEEDS TESTING****
void usart_receive_data(uint8_t *rx_buffer, uint32_t data_len)
{
	while(data_len > 0)
	{
		while(!(USART1->SR & (1 << 5))); //waits for the RXNE bit to be 1
		*data = USART1->DR; //read the data from data register
		rx_buffer++; //increment to the next byte
		data_len--;
	}
	while(!((USART1->SR) & (1 << 6))); //waits for the transmission complete bit
}*/

void usart_disable()
{
	USART1->CR1 &= ~(1 << 13); //disable the usart
}

void usart_enable()
{
	USART1->CR1 |= (1 << 13); //enable the usart
}
