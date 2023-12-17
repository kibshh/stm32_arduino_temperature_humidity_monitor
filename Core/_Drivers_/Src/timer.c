#include "../../_Drivers_/Inc/timer.h"

volatile uint32_t time_passed = 0;

void timer_init()
{
	RCC->APB2ENR |= (1 << 17);
	TIM10->PSC &= ~0xFFFF;
	TIM10->PSC |= 41;
	TIM10->CR1 &= ~(1 << 1);
	TIM10->CR1 |= (1 << 2);
	TIM10->ARR &= ~0xFFFF;
	TIM10->ARR |= 1;

	TIM10->CR1 |= (1 << 0);
	TIM10->DIER |= 1;
	NVIC->ISER[0] |= (1 << 25);
}

void timer_delay(uint32_t microseconds)
{
	uint32_t starting_time = time_passed;
	while(time_passed < starting_time + microseconds);
}

void TIM1_UP_TIM10_IRQHandler(void)
{
	if(TIM10->SR & 1)
	{
		TIM10->SR &= ~(1);
		time_passed++;
	}
}


