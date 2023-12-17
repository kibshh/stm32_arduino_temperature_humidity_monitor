#include "dht11.h"

void dht11_setup()
{
	//EXTERNAL 5K PULLUP RESISTOR IS NEEDED FOR DATA LINE
	gpio_settings dht_pin;
	dht_pin.mode = MODER_OUTPUT;
	dht_pin.ospeed = OSPEEDR_VERY_FAST;
	dht_pin.otype = OTYPER_OPEN_DRAIN;
	dht_pin.pupd = PUPDR_NOPUPD;
	dht_pin.pin_number = 5;
	dht_pin.port = GPIO_PORTB;
	gpio_init(&dht_pin);
	timer_init();
}

void dht11_send_start_signal()
{
	GPIOB->MODER &= ~(3 << 10);
	GPIOB->MODER |= (1 << 10);
	set_output(GPIO_PORTB, 5, 0);
	timer_delay(18000);
	GPIOB->MODER &= ~(3 << 10);
}

uint8_t validate_sensor()
{
	timer_delay(40);
	if(!get_input(GPIO_PORTB, 5))
	{
		timer_delay(80);
		if(get_input(GPIO_PORTB, 5))
		{
			while(get_input(GPIO_PORTB, 5));
			return 1;
		}
	}
	return 0;
}

uint8_t dht11_read() //THIS NEEDS TO BE EXECUTED 5 TIMES - 40 BITS
{
	uint8_t data = 0;
	for(int i=0; i<8; i++)
	{
		while(!get_input(GPIO_PORTB, 5));
		timer_delay(40);
		if(get_input(GPIO_PORTB, 5))
		{
			data |= (1 << (7-i));
		}
		else
		{
			data &= ~(1 << (7-i));
		}
		while(get_input(GPIO_PORTB, 5));
	}
	return data;
}
