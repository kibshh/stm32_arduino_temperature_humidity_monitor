#ifndef DRIVERS__INC_GPIO_H_
#define DRIVERS__INC_GPIO_H_

#include "../../_Drivers_/Inc/general.h"

#define MODER_INPUT           0
#define MODER_OUTPUT          1
#define MODER_ALT_FN          2
#define MODER_ANALOG          3

#define OTYPER_PUSH_PULL      0
#define OTYPER_OPEN_DRAIN     1

#define OSPEEDR_LOW           0
#define OSPEEDR_MEDIUM        1
#define OSPEEDR_FAST          2
#define OSPEEDR_VERY_FAST     3

#define PUPDR_NOPUPD          0
#define PUPDR_PULLUP          1
#define PUPDR_PULLDOWN        2

#define GPIO_PORTA            0
#define GPIO_PORTB            1
#define GPIO_PORTC            2
#define GPIO_PORTD            3
#define GPIO_PORTE            4
#define GPIO_PORTH            5


typedef struct
{
	uint8_t port;
	uint8_t pin_number;
	uint8_t mode;
	uint8_t otype;
	uint8_t ospeed;
	uint8_t pupd;
	uint8_t alt_fun;
}gpio_settings;

void gpio_init(gpio_settings *pin);
uint8_t get_input(uint8_t port, uint8_t pin);
void set_output(uint8_t port, uint8_t pin, uint8_t value);
void toggle_output(uint8_t port, uint8_t pin);


#endif /* DRIVERS__INC_GPIO_H_ */
