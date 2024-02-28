#include "lcd1602driver.h"

_Bool LineNumCnt = 0;

/** Write a byte command to LCD1602
 * */
void LCD_WriteCom(unsigned char input)
{
	HAL_Delay(5);
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (input>>0)&0x1);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (input>>1)&0x1);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (input>>2)&0x1);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (input>>3)&0x1);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (input>>4)&0x1);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (input>>5)&0x1);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (input>>6)&0x1);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (input>>7)&0x1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
}


/** Write a byte data to LCD1602
 * */
void LCD_WriteData(unsigned char input)
{
	HAL_Delay(5);
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (input>>0)&0x1);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (input>>1)&0x1);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (input>>2)&0x1);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (input>>3)&0x1);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (input>>4)&0x1);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (input>>5)&0x1);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (input>>6)&0x1);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (input>>7)&0x1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
}


/** Clear the screen, including DDRAM and AC
 * */
void LCD_Clear(void)
{
	LCD_WriteCom(0x01);
}


/** Set cursor and graph HOME, AC = 0
 * */
void LCD_Return(void)
{
	LCD_WriteCom(0x02);
}


/** Set input mode
 * 	ACMode: set AC counter mode
 * 		AC_UP: 		AC++ after a data is being read or written.
 * 		AC_DOWN: 	AC-- after a data is being read or written.
 * 	GraphMode: set Graph mode
 * 		GRAPH_MOVE:		Graph moves after a data is being read or written.
 * 		GRAPH_STILL:	Graph remains still after a data is being read or written.
 * */
void LCD_SetInputMode(_Bool ACMode, _Bool GraphMode)
{
	LCD_WriteCom(0x04 + 2*(unsigned char)ACMode + (unsigned char)GraphMode);
}


/** Set display mode
 * 	Screen: SCREEN_ON, SCREEN_OFF
 * 	Cursor: CURSOR_ON, CURSOR_OFF
 * 	Flicker: FLICKER_ON, FLICKER_OFF
 * */
void LCD_SetDisplayMode(_Bool Screen, _Bool Cursor, _Bool Flicker)
{
	LCD_WriteCom(0x08 + 4*(unsigned char)Screen + 2*(unsigned char)Cursor + (unsigned char)Flicker);
}


/** Set movement of cursor or graph
 * 	Object: SCREEN_MOV, CURSOR_MOV
 * 	Direction: RIGHT, LEFT
 */
void LCD_Movement(_Bool Object, _Bool Direction)
{
	LCD_WriteCom(0x10 + 8*(unsigned char)Object + 4*(unsigned char)Direction);
}


/**	Set LCD functioning mode
 *  BitWidth: define the width of data interface
 *  	BITWID_8: Width = 8.
 *  	BITWID_4: Width = 4.
 * 	LineNum: define the number of lines enabled
 * 		LINE_2: 2 lines allowed.
 * 		LINE_1: 1 lines allowed.
 * 	CharacterSize: define the size of each display block
 * 		SIZE5X10: 5x10.
 * 		SIZE5X7: 5x7.
 */
void LCD_SetFunction(_Bool BitWidth, _Bool LineNum, _Bool CharacterSize)
{
	LineNumCnt = LineNum;
	LCD_WriteCom(0x20 + 16*(unsigned char)BitWidth + 8*(unsigned char)LineNum + 4*(unsigned char)CharacterSize);
}


/** Set the address of CGRAM
 *  A5 ~ A0 = 0 ~ 3FH
 */
_Bool LCD_SetCGRAM(unsigned char address)
{
	if (address >0x3f)
	{
		return COMMAND_FAIL;
	}
	else
	{
		LCD_WriteCom(0x40 + address);
		return COMMAND_SUCCEED;
	}
}


/** Set the address of DDRAM
 *  2 lines output mode: A6 ~ A0 = 0 ~ 2FH(line 1)	40 ~ 67H(line 2)
 *  1 line output mode: A6 ~ A0 = 0 ~ 4FH
 */
_Bool LCD_SetDDRAM(unsigned char address)
{
	if (LineNumCnt)
	{
		if ((address > 0x2f && address < 0x40) || address > 0x67)
		{
			return COMMAND_FAIL;
		}
		else
		{
			LCD_WriteCom(0x80 + address);
			return COMMAND_SUCCEED;
		}
	}
	else
	{
		if (address > 0x4f)
		{
			return COMMAND_FAIL;
		}
		else
		{
			LCD_WriteCom(0x80 + address);
			return COMMAND_SUCCEED;
		}
	}
}


/** Manual initialization of LCD1602
 */
void LCD_Init(_Bool BitWidth, _Bool LineNum, _Bool CharacterSize, _Bool ACMode, _Bool GraphMode)
{
	LCD_SetFunction(BitWidth, LineNum, CharacterSize);
	LCD_SetDisplayMode(SCREEN_ON, CURSOR_OFF, FLICKER_OFF);
	LCD_SetInputMode(ACMode, GraphMode);
	LCD_Clear();
}


/** Auto initialization of LCD1602
 *  BitWidth 		= 		BITWID_8
 *  LineNum  		= 		LINE_2
 *  CharacterSize 	= 		SIZE5X7
 *  ACMode 			= 		AC_UP
 *  GraphMode 		= 		GRAPH_MOV
 */
void LCD_AutoInit(void)
{
	LCD_WriteCom(0x38);
	LCD_WriteCom(0x0C);
	LCD_WriteCom(0x06);
	LCD_WriteCom(0x01);
}
