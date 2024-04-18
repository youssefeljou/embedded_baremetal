/*
 * motor.c
 *
 *  Created on: Oct 8, 2022
 *      Author: youssef adel
 */
#include "motor2.h"

#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */

#include "../LIB/common_macros.h" /* To use the macros like SET_BIT */
#include "../MCAL/gpio.h"

void motor2_init()
{
	GPIO_setupPinDirection(Motor_IN1_PORT_ID ,Motor_IN1_PIN_ID,PIN_OUTPUT );
	GPIO_setupPinDirection(Motor_IN2_PORT_ID ,Motor_IN2_PIN_ID,PIN_OUTPUT );

	GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_LOW);

}
void changeSpeed2(unsigned char x)
{

	PWM_TIMER2_Start(x);

}
void rotate2_cw()
{
	GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_LOW);
}
void rotate2_acw()
{
	GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_HIGH);
}
void motor2_stop()
{
	GPIO_writePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(Motor_IN2_PORT_ID,  Motor_IN2_PIN_ID, LOGIC_LOW);
}

