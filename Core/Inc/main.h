/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "uc1601s.h"
#include "button.h"
#include "led_light.h"
#include "menu.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOA
#define LCD_CD_Pin GPIO_PIN_6
#define LCD_CD_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_4
#define LCD_RESET_GPIO_Port GPIOC
#define BUTTON_RIGHT_SHIFT_Pin GPIO_PIN_5
#define BUTTON_RIGHT_SHIFT_GPIO_Port GPIOC
#define BUTTON_C_Pin GPIO_PIN_0
#define BUTTON_C_GPIO_Port GPIOB
#define BUTTON_B_Pin GPIO_PIN_1
#define BUTTON_B_GPIO_Port GPIOB
#define BUTTON_A_Pin GPIO_PIN_2
#define BUTTON_A_GPIO_Port GPIOB
#define BUTTON_DOWN_Pin GPIO_PIN_3
#define BUTTON_DOWN_GPIO_Port GPIOB
#define BUTTON_LEFT_Pin GPIO_PIN_4
#define BUTTON_LEFT_GPIO_Port GPIOB
#define BUTTON_RIGHT_Pin GPIO_PIN_5
#define BUTTON_RIGHT_GPIO_Port GPIOB
#define BUTTON_UP_Pin GPIO_PIN_8
#define BUTTON_UP_GPIO_Port GPIOB
#define BUTTON_LEFT_SHIFT_Pin GPIO_PIN_9
#define BUTTON_LEFT_SHIFT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
