/*
 * timer0_ctc.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Youmna
 */

#ifndef TIMER0_H
#define TIMER0_H
#include "../LIB/std_types.h"
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PWM_PHASE_COTROL=1,
	TIMER0_COMPARE_MODE=2,
	TIMER0_FAST_PWM_MODE=3
}Timer0_Modes;

typedef enum
{
	timer0_NO_CLK_SRC,
	timer0_NO_PRESCALAR,
	timer0_PRESCALAR_CLK8,
	timer0_PRESCALAR_CLK64,
	timer0_PRESCALAR_CLK256,
	timer0_PRESCALAR_CLK1024,
	timer0_EXT_CLK_FALLING,
	timer0_EXT_CLK_RISING

}Timer0_PRESCALAR;

typedef struct
{
	uint16 initial_value;
	uint16 compare_value; // it will be used in compare mode only.
	Timer0_Modes mode;
	Timer0_PRESCALAR prescaler;
}Timer0_ConfigType;

//configuration
#define TCCR0_FOC0      7//disable pwm enable compare
#define TCCR0_WGM00		6//WAVEFORM GENERATION MODE BIT0
#define TCCR0_COM01     5//clear or set OC) compare match
#define TCCR0_COM00     4//clear or set OC) compare match
#define TCCR0_WGM01		3//WAVEFORM GENERATION MODE BIT1
#define TCCR0_CS02		2//PRESCALLER BIT2
#define TCCR0_CS01		1//PRESCALLER BIT1
#define TCCR0_CS00		0//PRESCALLER BIT20

#define TIMER0_OC0_MODE 0

#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1
#define OK				1
#define NOT_OK			0

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_COMPARE_OCR1A=4,
	TIMER1_PWM_Phase_Correct_ICR1=10,
	TIMER1_PWM_Phase_Correct_OCR1A=11,
	TIMER1_COMPARE_ICR1=12,
	TIMER1_FAST_PWM_ICR1=14,
	TIMER1_FAST_PWM_OCR1A=15,

}Timer1_Modes;

typedef enum
{
	timer1_NO_CLK_SRC,
	timer1_NO_PRESCALAR,
	timer1_PRESCALAR_CLK8,
	timer1_PRESCALAR_CLK64,
	timer1_PRESCALAR_CLK256,
	timer1_PRESCALAR_CLK1024,
	timer1_EXT_CLK_FALLING,
	timer1_EXT_CLK_RISING

}Timer1_PRESCALAR;

typedef struct
{
	uint16 initial_value;
	uint16 compare_value_A; // it will be used in compare mode only.
	uint16 compare_value_B; // it will be used in compare mode only.
	Timer1_Modes mode;
	Timer1_PRESCALAR prescaler;
}Timer1_ConfigType;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Timer1_PRESCALAR clock;
	Icu_EdgeType edge;
}Icu_ConfigType;


#define OCIE1A
#define OCIE1B
#define TICIE1
//********************************************config***************************************
//***		choose mode of timer	***//
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4
//***	ENABLE OR DISABLE PWM		***//
#define TCCR1A_FOC1B		2//
#define TCCR1A_FOC1A		3//
//****	NORMAL OR COMPARE MODE	ENABLE AND DISABLE OC1A/OC1B  PINS		***//
#define TCCR1A_COM1B0		4
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1A1		7


#define TIMSK_TOIE0			0
#define TIMSK_OCIE0			1
#define TIMSK_TOIE1			2
#define TIMSK_OCIE1B		3
#define TIMSK_OCIE1A		4
#define TIMSK_TICIE1		5
#define TIMSK_TOIE2			6
#define TIMSK_OCIE1			7


#define FALLINH				0
#define RISING				1




typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PWM_PHASE_COTROL=1,
	TIMER2_COMPARE_MODE=2,
	TIMER2_FAST_PWM_MODE=3
}Timer2_Modes;

typedef enum
{
	timer2_NO_CLK_SRC,
	timer2_NO_PRESCALAR,
	timer2_PRESCALAR_CLK8,
	timer2_PRESCALAR_CLK64,
	timer2_PRESCALAR_CLK256,
	timer2_PRESCALAR_CLK1024,
	timer2_EXT_CLK_FALLING,
	timer2_EXT_CLK_RISING

}Timer2_PRESCALAR;

typedef struct
{
	uint16 initial_value;
	uint16 compare_value; // it will be used in compare mode only.
	Timer2_Modes mode;
	Timer2_PRESCALAR prescaler;
}Timer2_ConfigType;


//configuration
#define TCCR2_FOC02      7//disable pwm enable compare
#define TCCR2_WGM20		 6//WAVEFORM GENERATION MODE BIT0
#define TCCR2_COM21      5//clear or set OC) compare match
#define TCCR2_COM20      4//clear or set OC) compare match
#define TCCR2_WGM21		 3//WAVEFORM GENERATION MODE BIT1
#define TCCR2_CS22		 2//PRESCALLER BIT2
#define TCCR2_CS21		 1//PRESCALLER BIT1
#define TCCR2_CS20		 0//PRESCALLER BIT20


#define TIMSK_TOIE0			0
#define TIMSK_OCIE0			1
#define TIMSK_TOIE1			2
#define TIMSK_OCIE1B		3
#define TIMSK_OCIE1A		4
#define TIMSK_TICIE1		5
#define TIMSK_TOIE2			6
#define TIMSK_OCIE2			7


#define TIMSK_TOIE0		 0
#define TIMSK_OCIE0		 1
#define OK				 1
#define NOT_OK			 0


//PROTOTYPES TIMER_0

void TIMER0_init(const Timer0_ConfigType * Config_Ptr);
void TIMER0_deInit(void);
void delay0(uint32 seconds);
void TIMER0_tick(void);
void TIMER0_setCallBack(void(*Copy_pvCallBackFunc)(void));
void PWM_TIMER0_Start(uint8 duty_cycle);


/***               PROTOTYPE TIMER_1            ***/

void TIMER1_init(const Timer1_ConfigType * Config_Ptr);
void TIMER1_deInit(void);
void delay1(uint32 seconds);
void TIMER1_setCallBack(void(*a_ptr)(void));
void TIMER1_tick(void);
void TIMER1_ICU_Enable(const Icu_ConfigType * Config_Ptr);
void TIMER1_ICU_Disable(void);
uint16 TIMER1_ICU_GetTCNT1(void);
void TIMER1_ICU_SetTCNT1(uint16 new_tcnt1);
void TIMER1_clearTimerValue(void);
//dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
//period = ((g_timePeriodPlusHigh - g_timeHigh) / 1000);
//freq = 1000000 / (g_timePeriodPlusHigh - g_timeHigh);
//void APP_edgeProcessing(void);



/***               PROTOTYPE TIMER_2            ***/



void TIMER2_init(const Timer2_ConfigType * Config_Ptr);
void TIMER2_deInit(void);
void delay2(uint32 seconds);
void TIMER2_tick(void);
void TIMER2_setCallBack(void(*Copy_pvCallBackFunc)(void));
void PWM_TIMER2_Start(uint8 duty_cycle);
#endif
