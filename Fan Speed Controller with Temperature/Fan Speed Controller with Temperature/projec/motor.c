/*
 * motor.c
 *
 *  Created on: Oct 8, 2022
 *      Author: youssef adel
 */
#include "motor.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */
#include "gpio.h"
void direction()
{
	GPIO_setupPinDirection(Motor_IN1_PORT_ID ,Motor_IN1_PIN_ID,PIN_OUTPUT );
	GPIO_setupPinDirection(Motor_IN2_PORT_ID ,Motor_IN2_PIN_ID,PIN_OUTPUT );
#ifdef CW
	{
		GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_LOW);
	}
#else
	{
		GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_HIGH);
	}
#endif
}
void changeSpeed(unsigned char temp)
{
	direction();
	PWM_Timer0_Start(temp*100/120);

}



