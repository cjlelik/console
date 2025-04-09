#include "main.h"

void LedLightInit(void)
{

}

void LedLightSet(uint8_t warm, uint8_t cold)
{
	if(warm > LED_MAX_VALUE)
	{
		warm = LED_MAX_VALUE;
	}
	if(cold > LED_MAX_VALUE)
	{
		cold = LED_MAX_VALUE;
	}
	TIM3->CCR3 = warm;
	TIM3->CCR4 = cold;
}

