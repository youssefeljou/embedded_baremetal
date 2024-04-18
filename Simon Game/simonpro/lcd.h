/*
 * lcd.h
 *
 *  Created on: Oct 3, 2022
 *      Author: merna
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
/*  DEFINATION */
#define LCD_DATA_BITS_MODE 8

#if(LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8)
#error"ERROR"
#endif

/* lcd ports and pins */

#define LCD_RS_PORT_ID                 PORTA_ID
#define LCD_RS_PIN_ID                  PIN7_ID

#define LCD_E_PORT_ID                  PORTA_ID
#define LCD_E_PIN_ID                   PIN5_ID

#define LCD_RW_PORT_ID                  PORTA_ID
#define LCD_RW_PIN_ID                   PIN6_ID

#define LCD_DATA_PORT_ID               PORTB_ID

#if(LCD_DATA_BITS_MODE == 4)
#define LCD_DB4_PIN_ID                 PIN4_ID
#define LCD_DB5_PIN_ID                 PIN5_ID
#define LCD_DB6_PIN_ID                 PIN6_ID
#define LCD_DB7_PIN_ID                 PIN7_ID

#endif

/* LCD Commands */

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/* function prototype */
void LCD_init(void);
void LCD_SendCommand(uint8 command);
void LCD_DisplayChar(uint8 data);
void LCD_DisplayString(const char *Str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);
void LCD_clearScreen(void);

#endif /* LCD_H_ */
