#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"

typedef struct{
	uint8_t value;
	uint8_t timer;
}button_Typedef;

typedef struct {
	button_Typedef Left;
	button_Typedef Right;
	button_Typedef Up;
	button_Typedef Down;
	button_Typedef A;
	button_Typedef B;
	button_Typedef C;
	button_Typedef Shift_Left;
	button_Typedef Shift_Right;
}BUTTONS_TypeDef;

void BUTTON_GetState(BUTTONS_TypeDef *button);
void _BUTTON_PROCESSING(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, button_Typedef *button);
void BUTTON_SetValue(uint16_t add, uint16_t sub, uint16_t min, uint16_t max, uint16_t *value);
uint8_t Button_A_GetState(void);

#endif /* BUTTON_H_ */
