/*
 * main.c
 *
 *  Created on: Nov 4, 2022
 *      Author: youssef
 */


#include "lcd.h"
#include "keypad.h"
#include <util/delay.h> /* For the delay functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uart.h"
#include "check_password.h"

extern state;
int main(void)
{
	UART_ConfigType Config = {data_8_bit,Enabled_Even,Stop_1_bit,9600 };
	UART_init(&Config);
	LCD_init();
	while(1)
	{

		getPassword();
		state=UART_recieveByte();
		if (state ==RIGHT)
		{
			mainOptions();
		}
		else if(state ==WRONG)
		{
			getPassword();
		}
	}
	return 0;
}
