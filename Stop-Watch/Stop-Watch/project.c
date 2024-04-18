/*
 * ex_6.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Youmna
 */



#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned char num= 0;
unsigned char FLAG = 0;
unsigned char sec1 = 0;
unsigned char sec2 = 0;
unsigned char min1 = 0;
unsigned char min2 = 0;
unsigned char hour1= 0;
unsigned char hour2= 0;
ISR(INT0_vect)
{

	sec1 = 0;
	sec2 = 0;
	min1 = 0;
	min2 = 0;
	hour1= 0;
	hour2= 0;
}
ISR(INT1_vect)
{
	TCCR1A &= ~(1<<FOC1A);
	TCCR1B &= ~(1<<CS10) & ~(1<<CS12);
}
ISR(INT2_vect)
{
	TCCR1A |= (1<<FOC1A);
	TCCR1B |= (1<<CS10) | (1<<CS12);
}
ISR(TIMER1_COMPA_vect)
{
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
	_delay_ms(2);
	PORTA=(PORTA & 0XC0) |(1<<PIN1) ;
	PORTC =(PORTC & 0XF0) |(0X0F & sec2);
	_delay_ms(2);
	PORTA=(PORTA & 0XC0) |(1<<PIN2) ;
	PORTC =(PORTC & 0XF0) |(0X0F & min1);
	_delay_ms(2);
	PORTA=(PORTA & 0XC0) |(1<<PIN3) ;
	PORTC =(PORTC & 0XF0) |(0X0F & min2);
	_delay_ms(2);
	PORTA=(PORTA & 0XC0) |(1<<PIN4) ;
	PORTC =(PORTC & 0XF0) |(0X0F & hour1);
	_delay_ms(2);
	PORTA=(PORTA & 0XC0) |(1<<PIN5) ;
	PORTC =(PORTC & 0XF0) |(0X0F & hour2);
	_delay_ms(2);
}
void Timer1_CTC(void)
{
	TCNT1 = 0;
	OCR1A = 976;
	TIMSK |= (1<<OCIE1A);
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);

}
void INT0_Init(void)
{
	DDRD  &= ~(1<<PD2);   // Configure INT0 as input pin
	PORTD |=(1<<PD2);     //PULL UP
	MCUCR |= (1<<ISC01) ;   // Trigger INT0 with the falling edge
	GICR  |= (1<<INT0);    // Enable external interrupt pin INT0
}
void INT1_Init(void)
{
	DDRD  &= ~(1<<PD3);   // Configure INT1 as input pin
	MCUCR |= (1<<ISC10)| (1<<ISC11);   // Trigger INT1 with the raising edge
	GICR  |= (1<<INT1);    // Enable external interrupt pin INT1
}
void INT2_Init(void)
{
	DDRB   &= ~(1<<PB2);   // Configure INT2 as input pin
	PORTB |=(1<<PB2);      //PULL UP
	MCUCSR|=(1<<ISC2);    // Trigger INT1 with the falling edge
	GICR  |= (1<<INT2);    // Enable external interrupt pin INT2
}
int main(void)
{
	INT0_Init();
	INT1_Init();
	INT2_Init();
	Timer1_CTC();
	SREG |= (1<<7);

	DDRC = 0x0F;
	PORTC &= 0xF0;
	DDRA =0X3F;
	PORTA &=0xC0;


	_delay_ms(30);
	while(1)
	{
		if(FLAG==0)
		{
			display_seven_sagement();
		}

	}
}
