/*
 * timer.c
 *
 *  Created on: Oct 22, 2022
 *      Author: youssef
 */
#include "timer.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "common_macros.h"


static void (*Timer1_CALLBACK_Fptr) (void)=NULL;

ISR(TIMER1_OVF_vect)
{
	if(Timer1_CALLBACK_Fptr != NULL)
	{
		(*Timer1_CALLBACK_Fptr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(Timer1_CALLBACK_Fptr != NULL)
	{
		(*Timer1_CALLBACK_Fptr)();
	}
}


void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);
	TCCR1B = Config_Ptr->prescaler;
	TCNT1 = Config_Ptr->initial_value;
	if((Config_Ptr->mode) == TIMER1_NORMAL_MODE)
	{
		SET_BIT(TIMSK,TOIE1);
		SET_BIT(TIFR,TOV1);
	}
	else if((Config_Ptr->mode) == TIMER1_COMPARE_MODE)
	{
		SET_BIT(TCCR1B,WGM12);
		OCR1A=Config_Ptr->compare_value;
		SET_BIT(TIMSK,OCIE1A);
		SET_BIT(TIFR,OCF1A);
	}
}
void Timer1_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 =  0;
	CLEAR_BIT(TIMSK,TOIE1);
	CLEAR_BIT(TIFR,TOV1);
	OCR1A = 0;
	CLEAR_BIT(TIMSK,OCIE1A);
	CLEAR_BIT(TIFR,OCF1A);
	Timer1_CALLBACK_Fptr = NULL;
}
/* timer to count second*/
uint8 g_tick;
void delay(uint32 seconds){

	g_tick = 0;
	uint32 tick = seconds;
	Timer1_setCallBack(&timer_tick);
	while(g_tick  < tick);
	Timer1_deInit();
}
void timer_tick(void){
	g_tick++;
}
void Timer1_setCallBack(void(*a_ptr)(void))
{
	Timer1_CALLBACK_Fptr = a_ptr;
}
