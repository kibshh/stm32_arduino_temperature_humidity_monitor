#ifndef DRIVERS__INC_USART_H_
#define DRIVERS__INC_USART_H_

#include "../../_Drivers_/Inc/general.h"

void usart_init();
void usart_send_byte(uint8_t data);
// ****NEEDS TESTING****void usart_send_data(uint8_t *tx_buffer, uint32_t data_len);
// ****NEEDS TESTING****void usart_receive_byte(uint8_t *data)
// ****NEEDS TESTING****void usart_receive_data(uint8_t *rx_buffer, uint32_t data_len)
void usart_disable();
void usart_enable();

#endif /* DRIVERS__INC_USART_H_ */
