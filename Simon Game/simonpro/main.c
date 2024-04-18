/*
 * main.c
 *
 *  Created on: Oct 22, 2022
 *      Author: merna
 */

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
#include "gpio.h"
#include "common_macros.h"
#include "interrupt.h"

float32 g_temp,g_temp2;
uint8 i=0,max=0,v=1;
uint16 time=600;

void check(void);
void loop1(void);
void setup(void);
void start(void);

int main(void)
{
	INT0_Init();              // Enable external INT0
	LCD_init();
	setup();
	start();
	loop1();
	while(1)
	{

	}
}
void setup(void)
{
	DDRD  &= (~(1<<PD2) & ~(1<<PD4) & ~(1<<PD5) & ~(1<<PD6) & ~(1<<PD7));
	DDRC  = DDRC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);  // Configure pin PC0 in PORTC as output pin
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3); // Set Value of PIN 0 in PORTC to 1 at the beginning (LED OFF)
}
void start(void)
{
	LCD_init();
	LCD_displayStringRowColumn(0, 5, "WELCOME");
	PORTC = PORTC & ~(1<<PC0) & ~(1<<PC1) & ~(1<<PC2) & ~(1<<PC3); // Set Value of PIN  in PORTC to 0 at the beginning (LED on)
	_delay_ms(500);
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);_delay_ms(500);
	PORTC = PORTC & ~(1<<PC0) & ~(1<<PC1) & ~(1<<PC2) & ~(1<<PC3); // Set Value of PIN  in PORTC to 0 at the beginning (LED on)
	_delay_ms(500);
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);_delay_ms(500);
	PORTC = PORTC & ~(1<<PC0) & ~(1<<PC1) & ~(1<<PC2) & ~(1<<PC3); // Set Value of PIN  in PORTC to 0 at the beginning (LED on)
	_delay_ms(500);
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);
	LCD_clearScreen();
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);_delay_ms(500); // Set Value of PIN 0 in PORTC to 1 at the beginning (LED OFF)*/

}

/* External INT0 Interrupt Service Routine
 * Every time we press a button it change temp2 value to check
 * */
ISR(INT0_vect)
{
	if(PIND & (1<<PD4))
	{
		PORTC &= ~(1<<PC0);
		g_temp2+=1;

	}
	else if(PIND & (1<<PD5))
	{
		PORTC &= ~(1<<PC1);
		g_temp2/=2;
	}
	else if(PIND & (1<<PD6))
	{
		PORTC &= ~(1<<PC2);
		g_temp2-=3;
	}
	else if(PIND & (1<<PD7))
	{
		PORTC &= ~(1<<PC3);
		g_temp2*=4;
	}
	_delay_ms(250);
	PORTC = PORTC | (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3); // Set Value of PIN 0 in PORTC to 1 at the beginning (LED OFF)
	check();
}
/*
 * Description :
 * Function that turn on led in a random
 * max decide after how many loops we check if it right or wrong
 * temp check if it right or wrong
 * we decrease time by 10ms every time the answer is correct
 */
void loop1() {

	for (int var = 0; var < 4; var++) {
		int ran = (rand()%5);
		if(ran == 1) {
			CLEAR_BIT(PORTC,PIN0);
			_delay_ms(time);
			SET_BIT(PORTC,PIN0);
			g_temp+=1;
			max++;
		}
		if(ran == 2) {
			CLEAR_BIT(PORTC,PIN1);
			_delay_ms(time);
			SET_BIT(PORTC,PIN1);
			g_temp/=2;
			max++;
		}
		if(ran == 3) {
			CLEAR_BIT(PORTC,PIN2);
			_delay_ms(time);
			SET_BIT(PORTC,PIN2);
			g_temp-=3;
			max++;
		}
		if(ran == 4) {
			CLEAR_BIT(PORTC,PIN3);
			_delay_ms(time);
			SET_BIT(PORTC,PIN3);
			g_temp*=4;
			max++;
		}
	}
	if(time==0)
	{
		time=600;
		LCD_displayStringRowColumn(0, 4, "CONGRATS");
		LCD_displayStringRowColumn(1, 0, "You finished OOH");
		i=0;
		_delay_ms(2000);
		start();
	}
	time-=20;
}
/*
 * Description :
 * Function that check if it right or wrong
 * temp2 change its value every time we press a button
 * when v = max we enter the loop and check if we turn on the same leds as in the function loop1
 * if yes correct and we return temp,tem2=0 to start again
 * else game over we return temp,tem2=0 to start again and we return time=1000
 */
void check(void)
{
	while(v == max) {
		max=0;
		v=0;
		if(g_temp==g_temp2)
		{
			LCD_DisplayString("correct");
			i++;
			LCD_displayStringRowColumn(1, 0, "score");
			LCD_moveCursor(1, 6);
			LCD_intgerToString(i);
			_delay_ms(750);
			LCD_clearScreen();
			g_temp=0;
			g_temp2=0;
			loop1();
		}
		else
		{
			LCD_DisplayString("game over");
			LCD_displayStringRowColumn(1, 0, "score");
			LCD_moveCursor(1, 6);
			LCD_intgerToString(i);
			i=0;
			_delay_ms(500);
			LCD_clearScreen();
			LCD_DisplayString("Start a new game");
			_delay_ms(1000);
			LCD_clearScreen();
			time=1000;
			g_temp=0;
			g_temp2=0;
			loop1();
		}
	}
	v++;
}
