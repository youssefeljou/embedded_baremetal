/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : youssef adel
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
#include <avr/io.h>
#include "pwm.h"

int main(void)
{
	ADC_ConfigType config = {INTERNAL , F_CPU8 };
	uint8 temp=0;
	LCD_init(); /* initialize LCD driver */
	ADC_init (&config);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp = C");

	while(1)
	{


		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		if (temp<30)
		{

			LCD_moveCursor(0,7);
			LCD_displayString("off");
			changeSpeed(0);
		}
		else if (temp>=30)
		{

			LCD_moveCursor(0,7);
			LCD_displayString("on");
			LCD_displayCharacter(' ');
			if (temp>120)
			{
				changeSpeed(120);
			}
			else
			{
				changeSpeed(temp);
			}



		}


		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}

		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1,7);
		LCD_intgerToString(temp);
	}
}

