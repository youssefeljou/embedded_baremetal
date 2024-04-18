/*
 * main.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Youmna
 */
#include <util/delay.h>
#include "lcd.h"
#include "common_macros.h"
#include "std_types.h"
#include <avr/io.h>
#include "ultra_sonic.h"

int main()
{



	SREG |= (1<<7);

	LCD_init();
	Ultrasonic_init();


	uint8 str="Distance =    cm";
	LCD_displayString(str);



	while(1)
	{

		if (Ultrasonic_readDistance()>100)
		{

			LCD_moveCursor(0,10);
			LCD_intgerToString(Ultrasonic_readDistance());
			_delay_ms(100);

		}

		else
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(Ultrasonic_readDistance());
			_delay_ms(100);
			LCD_displayCharacter(' ');
		}


	}



}
