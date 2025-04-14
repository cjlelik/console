/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
char vbuff[64], vbuff1[32];
uint32_t c=0;
BUTTONS_TypeDef buttons;
uint16_t led_value =0;
/* USER CODE END Variables */
osThreadId MainTaskHandle;
osThreadId PeripheryHandle;
osThreadId Task03Handle;
osSemaphoreId button_aHandle;
osSemaphoreId button_bHandle;
osSemaphoreId button_cHandle;
osSemaphoreId button_upHandle;
osSemaphoreId button_downHandle;
osSemaphoreId button_leftHandle;
osSemaphoreId button_rightHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void Peryphery(void const * argument);
void Menu(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of button_a */
  osSemaphoreDef(button_a);
  button_aHandle = osSemaphoreCreate(osSemaphore(button_a), 255);

  /* definition and creation of button_b */
  osSemaphoreDef(button_b);
  button_bHandle = osSemaphoreCreate(osSemaphore(button_b), 255);

  /* definition and creation of button_c */
  osSemaphoreDef(button_c);
  button_cHandle = osSemaphoreCreate(osSemaphore(button_c), 255);

  /* definition and creation of button_up */
  osSemaphoreDef(button_up);
  button_upHandle = osSemaphoreCreate(osSemaphore(button_up), 255);

  /* definition and creation of button_down */
  osSemaphoreDef(button_down);
  button_downHandle = osSemaphoreCreate(osSemaphore(button_down), 255);

  /* definition and creation of button_left */
  osSemaphoreDef(button_left);
  button_leftHandle = osSemaphoreCreate(osSemaphore(button_left), 255);

  /* definition and creation of button_right */
  osSemaphoreDef(button_right);
  button_rightHandle = osSemaphoreCreate(osSemaphore(button_right), 255);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of MainTask */
  osThreadDef(MainTask, StartDefaultTask, osPriorityNormal, 0, 512);
  MainTaskHandle = osThreadCreate(osThread(MainTask), NULL);

  /* definition and creation of Periphery */
  osThreadDef(Periphery, Peryphery, osPriorityNormal, 0, 512);
  PeripheryHandle = osThreadCreate(osThread(Periphery), NULL);

  /* definition and creation of Task03 */
  osThreadDef(Task03, Menu, osPriorityIdle, 0, 512);
  Task03Handle = osThreadCreate(osThread(Task03), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */

  /* Infinite loop */
  for(;;)
  {
	  xsprintf(vbuff, "c=%d", c++);
	  LcdSizePutStr(vbuff, 0*5*1, 0*7*2, 1, 2, LCD_Color_Black);

		BUTTON_SetValue(buttons.A.value, buttons.C.value, 0, 160, &led_value);
		if(buttons.B.value){led_value = 0;}
		LedLightSet(led_value, led_value);

		osDelay(50);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Peryphery */
/**
* @brief Function implementing the Periphery thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Peryphery */
void Peryphery(void const * argument)
{
  /* USER CODE BEGIN Peryphery */
	uint8_t led_pwm = 0, dir = 1;
  /* Infinite loop */
  for(;;)
  {
	LcdGraphicsRedrawDMA();
	BUTTON_GetState(&buttons);
	if(led_pwm == 255){dir=0;}
	if(led_pwm == 0){dir=1;}
	if(dir == 1){led_pwm+=3;}else{led_pwm-=3;}
	TIM2->CCR4 = led_pwm;
	osDelay(40);
  }
  /* USER CODE END Peryphery */
}

/* USER CODE BEGIN Header_Menu */
/**
* @brief Function implementing the Task03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Menu */
void Menu(void const * argument)
{
  /* USER CODE BEGIN Menu */
	MenuInit();
  /* Infinite loop */
  for(;;)
  {
	if(buttons.Down.state){buttons.Down.state = 0; MenuDown();}
	if(buttons.Up.state){buttons.Up.state = 0; MenuUp();}
	if(buttons.Left.state){buttons.Left.state = 0; MenuLeft();}
	if(buttons.Right.state){buttons.Right.state = 0; MenuRight();}

	xsprintf(vbuff, "%-12S %-03D", MenuGetItem()->Text, MenuGetItem()->Value);
	LcdSizePutStr(vbuff, 0, 1*8*2, 1, 2, LCD_Color_Black);
    osDelay(40);
  }
  /* USER CODE END Menu */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
