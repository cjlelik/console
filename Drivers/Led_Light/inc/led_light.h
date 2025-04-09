#ifndef LED_LIGHT_H_
#define LED_LIGHT_H_

#define LED_LIGHT_WARM_PORT GPIOC
#define LED_LIGHT_WARM_PIN GPIO_Pin_8

#define LED_LIGHT_COLD_PORT GPIOC
#define LED_LIGHT_COLD_PIN GPIO_Pin_9

#define LED_MAX_VALUE 160

void LedLightInit(void);
void LedLightSet(uint8_t warm, uint8_t cold);

#endif /* LED_LIGHT_H_ */
