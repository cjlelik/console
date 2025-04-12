#include "button.h"


void BUTTON_GetState(BUTTONS_TypeDef *button)
{
	_BUTTON_PROCESSING(BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin, &button->Left);
	_BUTTON_PROCESSING(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin, &button->Right);
	_BUTTON_PROCESSING(BUTTON_UP_GPIO_Port, BUTTON_UP_Pin, &button->Up);
	_BUTTON_PROCESSING(BUTTON_DOWN_GPIO_Port, BUTTON_DOWN_Pin, &button->Down);

	_BUTTON_PROCESSING(BUTTON_A_GPIO_Port, BUTTON_A_Pin, &button->A);
	_BUTTON_PROCESSING(BUTTON_B_GPIO_Port, BUTTON_B_Pin, &button->B);
	_BUTTON_PROCESSING(BUTTON_C_GPIO_Port, BUTTON_C_Pin, &button->C);
}
void _BUTTON_PROCESSING(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, button_Typedef *button)
{
	if(gpio_port->IDR & gpio_pin)
	{//Нажата кнопка

		if(button->value == 255){return;}
		if(button->timer++ == 0){button->state = 1; button->value = 1;}
		if(button->timer > button_delay)
		{
			button->timer = button->value++;
			button->state = 1;
		}
	}
	else
	{//Отпущена кнопка
		button->value = 0;
		button->state = 0;
		button->timer = 0;
	}
}
void BUTTON_SetValue(uint16_t add, uint16_t sub, uint16_t min, uint16_t max, uint16_t *value)
{
	static uint16_t old_add = 0, old_sub = 0;
	if(add > 0)
	{
		*value += add - old_add;
		old_add = add;
		if(*value > max){*value = min;}
	}
	else{old_add = 0;}
	if(sub > 0)
	{
		*value -= sub - old_sub;
		old_sub = sub;
		if(*value > max){*value = max;}
	}
	else{old_sub =0;}
}

uint8_t Button_A_GetState(void)
{
	static uint8_t state = 0, trig = 0;
	if(BUTTON_A_GPIO_Port->IDR & BUTTON_A_Pin)
	{
		if(!state)
		{
			state = 1;
			trig ^= 0b01;
		}
	}
	else
	{
		state = 0;
	}
	return trig;
}
