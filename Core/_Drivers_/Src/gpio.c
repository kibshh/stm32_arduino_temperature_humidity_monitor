#include "../../_Drivers_/Inc/gpio.h"

void gpio_init(gpio_settings *pin)
{
	uint8_t port = pin->port;
	uint8_t pnum = pin->pin_number;

	switch(port)
	{
	case GPIO_PORTA:
		RCC->AHB1ENR |= (1 << 0);
		GPIOA->MODER &= ~(3 << 2*pnum);
		GPIOA->MODER |= (pin->mode << 2*pnum);
		GPIOA->OTYPER &= ~(1 << pnum);
		GPIOA->OTYPER |= (pin->otype << pnum);
		GPIOA->OSPEEDR &= ~(3 << 2*pnum);
		GPIOA->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOA->PUPDR &= ~(3 << 2*pnum);
		GPIOA->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOA->AFR[0] &= ~(0xF << 4*pnum);
				GPIOA->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOA->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOA->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	case GPIO_PORTB:
		RCC->AHB1ENR |= (1 << 1);
		GPIOB->MODER &= ~(3 << 2*pnum);
		GPIOB->MODER |= (pin->mode << 2*pnum);
		GPIOB->OTYPER &= ~(1 << pnum);
		GPIOB->OTYPER |= (pin->otype << pnum);
		GPIOB->OSPEEDR &= ~(3 << 2*pnum);
		GPIOB->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOB->PUPDR &= ~(3 << 2*pnum);
		GPIOB->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOB->AFR[0] &= ~(0xF << 4*pnum);
				GPIOB->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOB->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOB->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	case GPIO_PORTC:
		RCC->AHB1ENR |= (1 << 2);
		GPIOC->MODER &= ~(3 << 2*pnum);
		GPIOC->MODER |= (pin->mode << 2*pnum);
		GPIOC->OTYPER &= ~(1 << pnum);
		GPIOC->OTYPER |= (pin->otype << pnum);
		GPIOC->OSPEEDR &= ~(3 << 2*pnum);
		GPIOC->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOC->PUPDR &= ~(3 << 2*pnum);
		GPIOC->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOC->AFR[0] &= ~(0xF << 4*pnum);
				GPIOC->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOC->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOC->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	case GPIO_PORTD:
		RCC->AHB1ENR |= (1 << 3);
		GPIOD->MODER &= ~(3 << 2*pnum);
		GPIOD->MODER |= (pin->mode << 2*pnum);
		GPIOD->OTYPER &= ~(1 << pnum);
		GPIOD->OTYPER |= (pin->otype << pnum);
		GPIOD->OSPEEDR &= ~(3 << 2*pnum);
		GPIOD->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOD->PUPDR &= ~(3 << 2*pnum);
		GPIOD->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOD->AFR[0] &= ~(0xF << 4*pnum);
				GPIOD->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOD->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOD->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	case GPIO_PORTE:
		RCC->AHB1ENR |= (1 << 4);
		GPIOE->MODER &= ~(3 << 2*pnum);
		GPIOE->MODER |= (pin->mode << 2*pnum);
		GPIOE->OTYPER &= ~(1 << pnum);
		GPIOE->OTYPER |= (pin->otype << pnum);
		GPIOE->OSPEEDR &= ~(3 << 2*pnum);
		GPIOE->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOE->PUPDR &= ~(3 << 2*pnum);
		GPIOE->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOE->AFR[0] &= ~(0xF << 4*pnum);
				GPIOE->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOE->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOE->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	case GPIO_PORTH:
		RCC->AHB1ENR |= (1 << 7);
		GPIOH->MODER &= ~(3 << 2*pnum);
		GPIOH->MODER |= (pin->mode << 2*pnum);
		GPIOH->OTYPER &= ~(1 << pnum);
		GPIOH->OTYPER |= (pin->otype << pnum);
		GPIOH->OSPEEDR &= ~(3 << 2*pnum);
		GPIOH->OSPEEDR |= (pin->ospeed << 2*pnum);
		GPIOH->PUPDR &= ~(3 << 2*pnum);
		GPIOH->PUPDR |= (pin->pupd << 2*pnum);
		if(pin->mode == MODER_ALT_FN)
		{
			if(pnum <= 7)
			{
				GPIOH->AFR[0] &= ~(0xF << 4*pnum);
				GPIOH->AFR[0] |= (pin->alt_fun << 4*pnum);
			}
			else
			{
				uint8_t pnum2 = pnum % 8;
				GPIOH->AFR[1] &= ~(0xF << 4*pnum2);
				GPIOH->AFR[1] |= (pin->alt_fun << 4*pnum2);
			}
		}
		break;
	}
}

uint8_t get_input(uint8_t port, uint8_t pin)
{
	if(port == GPIO_PORTA)
	{
		if((GPIOA->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if(port == GPIO_PORTB)
	{
		if((GPIOB->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if(port == GPIO_PORTC)
	{
		if((GPIOC->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if(port == GPIO_PORTD)
	{
		if((GPIOD->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if(port == GPIO_PORTE)
	{
		if((GPIOE->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if(port == GPIO_PORTH)
	{
		if((GPIOH->IDR >> pin) & 1)
		{
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void set_output(uint8_t port, uint8_t pin, uint8_t value)
{
	if(port == GPIO_PORTA)
	{
		if(value == 1)
			GPIOA->ODR |= (1 << pin);
		else
			GPIOA->ODR &= ~(1 << pin);
	}
	else if(port == GPIO_PORTB)
	{
		if(value == 1)
			GPIOB->ODR |= (1 << pin);
		else
			GPIOB->ODR &= ~(1 << pin);
	}
	else if(port == GPIO_PORTC)
	{
		if(value == 1)
			GPIOC->ODR |= (1 << pin);
		else
			GPIOC->ODR &= ~(1 << pin);
	}
	else if(port == GPIO_PORTD)
	{
		if(value == 1)
			GPIOD->ODR |= (1 << pin);
		else
			GPIOD->ODR &= ~(1 << pin);
	}
	else if(port == GPIO_PORTE)
	{
		if(value == 1)
			GPIOE->ODR |= (1 << pin);
		else
			GPIOE->ODR &= ~(1 << pin);
	}
	else if(port == GPIO_PORTH)
	{
		if(value == 1)
			GPIOH->ODR |= (1 << pin);
		else
			GPIOH->ODR &= ~(1 << pin);
	}
}

void toggle_output(uint8_t port, uint8_t pin)
{
	if(port == GPIO_PORTA)
	{
		GPIOA->ODR ^= (1 << pin);
	}
	else if(port == GPIO_PORTB)
	{
		GPIOB->ODR ^= (1 << pin);
	}
	else if(port == GPIO_PORTC)
	{
		GPIOC->ODR ^= (1 << pin);
	}
	else if(port == GPIO_PORTD)
	{
		GPIOD->ODR ^= (1 << pin);
	}
	else if(port == GPIO_PORTE)
	{
		GPIOE->ODR ^= (1 << pin);
	}
	else if(port == GPIO_PORTH)
	{
		GPIOH->ODR ^= (1 << pin);
	}
}
