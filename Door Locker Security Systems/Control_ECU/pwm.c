/*
 * pwm.c
 *
 *  Created on: Oct 10, 2022
 *      Author: youssef adel
 */
#include "motor.h"
#include "pwm.h"
#include "common_macros.h"
#include "gpio.h"
#include "avr/io.h"
#include <avr/interrupt.h> /* For ICU ISR */

void PWM_Timer0_Start(uint8 duty_cycle)
{
	uint8 timer_value=((uint16)(duty_cycle*255)/100);
	CLEAR_BIT(TCCR0,TCNT0);

	SET_BIT(TCCR0,WGM00);//to activate fast pwm mode
	SET_BIT(TCCR0,WGM01);

	SET_BIT(TCCR0,COM01); //non inverting mode


	SET_BIT(TCCR0,CS01); //pre scaler/8
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	OCR0=timer_value;

}

