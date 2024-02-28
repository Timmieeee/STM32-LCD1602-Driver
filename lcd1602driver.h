#ifndef __LCD1602DRIVER_H
#define __LCD1602DRIVER_H

#include "main.h"


/* PINS ASSIGNMENT DEFINED BY USER */
#define RS_Pin 			***USERDEFINITION***
#define RS_GPIO_Port 	***USERDEFINITION***
#define RW_Pin 			***USERDEFINITION***
#define RW_GPIO_Port 	***USERDEFINITION***
#define EN_Pin 			***USERDEFINITION***
#define EN_GPIO_Port 	***USERDEFINITION***
#define DB0_Pin 		***USERDEFINITION***
#define DB0_GPIO_Port 	***USERDEFINITION***
#define DB1_Pin 		***USERDEFINITION***
#define DB1_GPIO_Port 	***USERDEFINITION***
#define DB2_Pin 		***USERDEFINITION***
#define DB2_GPIO_Port 	***USERDEFINITION***
#define DB3_Pin 		***USERDEFINITION***
#define DB3_GPIO_Port 	***USERDEFINITION***
#define DB4_Pin 		***USERDEFINITION***
#define DB4_GPIO_Port 	***USERDEFINITION***
#define DB5_Pin 		***USERDEFINITION***
#define DB5_GPIO_Port 	***USERDEFINITION***
#define DB6_Pin 		***USERDEFINITION***
#define DB6_GPIO_Port 	***USERDEFINITION***
#define DB7_Pin 		***USERDEFINITION***
#define DB7_GPIO_Port 	***USERDEFINITION***
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
