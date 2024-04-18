/*
 * timer.h
 *
 *  Created on: Oct 22, 2022
 *      Author: merna
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "std_types.h"


typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_COMPARE_MODE=4
}Timer1_Modes;

typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALAR,
	PRESCALAR_CLK8,
	PRESCALAR_CLK64,
	PRESCALAR_CLK256,
	PRESCALAR_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING

}Timer1_PRESCALAR;

typedef struct
{
	uint16 initial_value;
	uint16 compare_value; // it will be used in compare mode only.
	Timer1_Modes mode;
	Timer1_PRESCALAR prescaler;
}Timer1_ConfigType;


/***               PROTOTYPE             ***/

void Timer1_init(const Timer1_ConfigType * Config_Ptr);
void Timer1_deInit(void);
void delay(uint32 seconds);
void Timer1_setCallBack(void(*a_ptr)(void));
void timer_tick(void);

#endif /* TIMER_H_ */
