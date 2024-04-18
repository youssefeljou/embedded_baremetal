/*
 * mc2.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Youmna
 */
#include "../LIB/std_types.h"
#include "../LIB/common_macros.h"
#include "../MCAL/gpio.h"
#include "../MCAL/GIE.h"
#include "../MCAL/timers.h"
#include "avr/delay.h"
#include "avr/io.h"
#include "../MCAL/spi.h"
#include "avr/interrupt.h"
uint8 num  = 0;
uint8 sec1 = 0;
uint8 sec2 = 0;
uint8 min1 = 0;
uint8 min2 = 0;
uint8 hour1= 0;
uint8 hour2= 0;
#define F_CPU 8000000UL
#define forward		0
#define backword	1
uint8 count_speed=0;
uint16 counter=0;
uint8 flag=0;
uint8 flag2=0;
uint8 direction=0;
ISR(TIMER1_COMPA_vect)
{
	/*
	 if(Timer1_CALLBACK_Fptr != NULL_PTR)
	{
		(*Timer1_CALLBACK_Fptr)();
	}
	 */
	sec1++;
	if(sec1==10)
	{
		sec1 = 0;
		sec2++;

		if(sec2==6)
		{
			sec2=0;
			min1++;
			if(min1==10)
			{
				min1=0;
				min2++;
				if(min2==6)
				{
					min2=0;
					hour1++;
					if(hour1==10)
					{
						hour1=0;
						hour2++;

					}
				}
			}
		}
	}
}
void display_seven_sagement()
{

	PORTA=(PORTA & 0XC0) |(1<<PIN0) ;
	PORTC =(PORTC & 0XF0) |(0X0F & sec1);
	_delay_us(200);
	PORTA=(PORTA & 0XC0) |(1<<PIN1) ;
	PORTC =(PORTC & 0XF0) |(0X0F & sec2);
	_delay_us(200);
	PORTA=(PORTA & 0XC0) |(1<<PIN2) ;
	PORTC =(PORTC & 0XF0) |(0X0F & min1);
	_delay_us(200);
	PORTA=(PORTA & 0XC0) |(1<<PIN3) ;
	PORTC =(PORTC & 0XF0) |(0X0F & min2);
	_delay_us(200);
	PORTA=(PORTA & 0XC0) |(1<<PIN4) ;
	PORTC =(PORTC & 0XF0) |(0X0F & hour1);
	_delay_us(200);
	PORTA=(PORTA & 0XC0) |(1<<PIN5) ;
	PORTC =(PORTC & 0XF0) |(0X0F & hour2);
	_delay_us(200);
}
ISR(TIMER2_COMP_vect)
{

	display_seven_sagement();
	if (flag==0)
	{
		TCCR1A &= ~(1<<FOC1A);
		TCCR1B &= ~(1<<CS10) & ~(1<<CS12);
	}
	else
	{
		TCCR1A |= (1<<FOC1A);
		TCCR1B |= (1<<CS10) | (1<<CS12);
	}


}
void Timer1_CTC(void)
{
	TCNT1 = 0;
	OCR1A = 976;
	TIMSK |= (1<<OCIE1A);
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);

}


int main()
{
	Timer0_ConfigType config0={0,250,TIMER0_COMPARE_MODE,timer0_PRESCALAR_CLK64};
	//Timer1_ConfigType config1={0,976,0,TIMER1_COMPARE_OCR1A,timer1_PRESCALAR_CLK8};
	Timer2_ConfigType config2={0,253,TIMER2_COMPARE_MODE,timer2_PRESCALAR_CLK256};
	GPIO_setupPinDirection(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN3_ID, PIN_OUTPUT);
	GPIO_writePin(PORTC_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, PIN2_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, PIN3_ID, LOGIC_LOW);
	GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN4_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN5_ID, PIN_OUTPUT);
	GPIO_writePin(PORTA_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN1_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN2_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN3_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN4_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN5_ID, LOGIC_LOW);
	GIE_Enabled();
	TIMER0_init(&config0);
	delay0(20);
	SPI_initSlave();
	TIMER2_init(&config2);
	//TIMER1_init(&config1);
	/* Initialize the SPI driver as Slave */
	Timer1_CTC();

	while(1)
	{
			flag = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}
	return 0;
}
