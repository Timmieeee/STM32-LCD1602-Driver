#ifndef __LCD1602DRIVER_H
#define __LCD1602DRIVER_H

#include "main.h"


/* PINS ASSIGNMENT DEFINED BY USER */
#define RS_Pin 			GPIO_PIN_5
#define RS_GPIO_Port 	GPIOA
#define RW_Pin 			GPIO_PIN_6
#define RW_GPIO_Port 	GPIOA
#define EN_Pin 			GPIO_PIN_7
#define EN_GPIO_Port 	GPIOA
#define DB0_Pin 		GPIO_PIN_15
#define DB0_GPIO_Port 	GPIOA
#define DB1_Pin 		GPIO_PIN_3
#define DB1_GPIO_Port 	GPIOB
#define DB2_Pin 		GPIO_PIN_4
#define DB2_GPIO_Port 	GPIOB
#define DB3_Pin 		GPIO_PIN_5
#define DB3_GPIO_Port 	GPIOB
#define DB4_Pin 		GPIO_PIN_6
#define DB4_GPIO_Port 	GPIOB
#define DB5_Pin 		GPIO_PIN_7
#define DB5_GPIO_Port 	GPIOB
#define DB6_Pin 		GPIO_PIN_8
#define DB6_GPIO_Port 	GPIOB
#define DB7_Pin 		GPIO_PIN_9
#define DB7_GPIO_Port 	GPIOB
/* END PINS ASSIGNMENT */


/* COMMAND DEFINITION */
#define AC_UP			1
#define AC_DOWN			0
#define GRAPH_MOV		1
#define GRAPH_STILL		0
#define SCREEN_ON		1
#define SCREEN_OFF		0
#define CURSOR_ON		1
#define CURSOR_OFF		0
#define FLICKER_ON		1
#define FLICKER_OFF		0
#define SCREEN_MOV		1
#define CURSOR_MOV		0
#define RIGHT			1
#define LEFT			0
#define BITWID_8		1
#define BITWID_4		0
#define LINE_2			1
#define LINE_1			0
#define SIZE5X10		1
#define SIZE5X7			0
/* END COMMAND DEFINITION */


/* COMMAND STATUS DEFINITION */
#define COMMAND_FAIL	0
#define COMMAND_SUCCEED	1
/* END COMMAND STATUS DEFINITION */


/* FUNCTION PACKAGE */
void LCD_WriteCom(unsigned char input);
void LCD_WriteData(unsigned char input);
void LCD_Clear(void);
void LCD_Return(void);
void LCD_SetInputMode(_Bool ACMode, _Bool GraphMode);
void LCD_SetDisplayMode(_Bool Screen, _Bool Cursor, _Bool Flicker);
void LCD_Movement(_Bool Object, _Bool Direction);
void LCD_SetFunction(_Bool BitWidth, _Bool LineNum, _Bool CharacterSize);
_Bool LCD_SetCGRAM(unsigned char address);
_Bool LCD_SetDDRAM(unsigned char address);
void LCD_Init(_Bool BitWidth, _Bool LineNum, _Bool CharacterSize, _Bool ACMode, _Bool GraphMode);
void LCD_AutoInit(void);
/* END FUNCTION PACKAGE */


#endif	//__LCD1602DRIVER_H
