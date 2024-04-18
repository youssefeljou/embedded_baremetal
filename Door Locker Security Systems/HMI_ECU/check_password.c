/*
 * check_first_password.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Youmna
 */
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h> /* For the delay functions */
#include "std_types.h"
#include "check_password.h"
uint8 _1stpassword[5];
uint8 _2ndpassword[5];
uint8 state;//check 1st time
uint8 state2;//check 2nd time
uint8 state3,key,flag1,flag2;
static uint8 count;
void getFirstPassword(uint8 *password)
{
	uint8 key,i=0;
	while(key!='+')
	{
		key=KEYPAD_getPressedKey();
		_delay_ms(400);
		if (key>=0&&key<=9)
		{
			LCD_moveCursor(1, i);
			LCD_displayCharacter('*');
			password[i]=key;
			i++;
		}
	}
}
void getPassword()
{
	LCD_displayStringRowColumn(0, 0, "plz enter pass");
	getFirstPassword(_1stpassword);
	while(UART_recieveByte()!=READY){}
	sendpassword(_1stpassword);
	LCD_displayStringRowColumn(1, 0, "       ");
	reEnter();
	while(UART_recieveByte()!=READY){}
	sendpassword(_2ndpassword);



}
void mainOptions()
{
	LCD_displayStringRowColumn(0, 0, "+ : Open Door");
	LCD_displayStringRowColumn(1, 0, "- : Change Pass");
	while(key!='+'||key!='-')
	{


		key=KEYPAD_getPressedKey();
		_delay_ms(400);

		if (key=='+')
		{
			UART_sendByte(OPEN_DOOR);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0," enter password");
			getFirstPassword(_1stpassword);
			while(UART_recieveByte()!=READY){}
			sendpassword(_1stpassword);
			state2=UART_recieveByte();

			if(state2==RIGHT)
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0, 0, "Door is unlocking");
				flag2 = UART_recieveByte();
				while(UART_recieveByte()!=READY){}

				flag2 = UART_recieveByte();
				while(UART_recieveByte()!=RIGHT){}

				LCD_displayStringRowColumn(0, 0, "Door is locking");

			}
			else
			{
				count=0;
				count++;
				if (count==3)
				{

					LCD_displayStringRowColumn(0, 0, "error");
					UART_sendByte(WRONG);
				}
			}



		}
		else if(key=='-')
		{
			UART_sendByte(PASSWORD_CHANGE);
			LCD_clearScreen();
			getPassword();
			state=UART_recieveByte();
			if(state==CHANGE_DONE)
			{
				LCD_displayStringRowColumn(0,0," change done");

			}



		}


	}
}
void reEnter()
{
	LCD_displayStringRowColumn(0, 0, "plz re-enter pass");
	getFirstPassword(_2ndpassword);
}




void sendpassword(uint8 *password)
{
	int i;
	for(i=0;i<=4; i++)
	{
		UART_sendByte(password[i]);

	}
}
