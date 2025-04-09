#ifndef _uc1601s_
#define _uc1601s_

#include "xprintf.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#define LCD_X 132
#define LCD_Y 64

//���������� ��������---------------------------------
#define LCD_SPI SPI1

#define LCD_CS_PIN GPIO_PIN_4
#define	LCD_CS_PORT GPIOA

#define LCD_SCK_PIN GPIO_PIN_5
#define LCD_SCK_PORT GPIOA

#define LCD_MOSI_PIN GPIO_Pin_7
#define LCD_MOSI_PORT GPIOA

#define LCD_RES_PIN GPIO_PIN_4
#define LCD_RES_PORT GPIOC

#define LCD_CD_PIN GPIO_PIN_6
#define LCD_CD_PORT GPIOA

#define LCD_LED_PIN GPIO_PIN_3
#define LCD_LED_PORT GPIOA
//--------------------------------------------------
#define LCD_LED_ON LCD_LED_PORT->BSRR |= LCD_LED_PIN << 16
#define LCD_LED_OFF LCD_LED_PORT->BSRR |= LCD_LED_PIN

#define LCD_RESET_L LCD_RES_PORT->BSRR |= LCD_RES_PIN << 16
#define LCD_RESET_H LCD_RES_PORT->BSRR |= LCD_RES_PIN

#define LCD_COMMAND LCD_CD_PORT->BSRR |= LCD_CD_PIN << 16
#define LCD_DATA 	LCD_CD_PORT->BSRR |= LCD_CD_PIN

#define LCD_CS_L 	LCD_CS_PORT->BSRR |= LCD_CS_PIN << 16
#define LCD_CS_H 	LCD_CS_PORT->BSRR |= LCD_CS_PIN

	
#define LCD_Color_White	0x00
#define LCD_Color_Black	0xFF

void SPI_SEND_BYTE(uint8_t data);

void LcdPortInit(void);
void LcdInit(void);
void LcdLed(uint8_t value);
void Delay(void);
void DMA1_Init(void);
void LcdSendCom(uint8_t command);
void LcdSendData(uint8_t data);

void LcdGraphicsRedraw(void);
void LCD_SET_BYTE(void);
void LcdGraphicsRedrawDMA(void);
void LcdGraphicsClear(uint8_t LCD_Color);
void LcdLed(uint8_t value);
void LcdDrawPixel(uint8_t x, uint8_t y, uint8_t color);
uint8_t Lcd_GetPixel(uint8_t x, uint8_t y);
void LcdDrawLine(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint8_t color);								//������ ����� �� ����������� x y
void LcdDrawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t color);						//������ ������� �� ����������� x y
void LcdDrawShadeRect(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);
void LcdDrawCircle(uint8_t x0, uint8_t y0, uint8_t radius, uint8_t color);
void LcdSizePutChar(char ch,uint16_t x, uint16_t y, uint8_t pixel_width, uint8_t pixel_height, uint8_t color);
void LcdSizePutStr(const char *pString, uint16_t  x, uint16_t  y, uint8_t pixel_width, uint8_t pixel_height, uint8_t color);
void LcdDrawGraph(uint8_t pos_x, uint8_t pos_y, uint8_t lenght_pix, uint8_t height_pix, uint16_t *buff, uint16_t size_buff, uint8_t color);
void LcdDrawLogGraph(uint8_t pos_x, uint8_t pos_y, uint8_t lenght_pix, uint8_t height_pix, uint8_t value,  uint8_t color);
#endif
