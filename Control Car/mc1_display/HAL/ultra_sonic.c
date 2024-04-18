/*
 * ultra_sonic.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Youmna
 */
#include "ultra_sonic.h"

#include <util/delay.h>
#include "../MCAL/timers.h"
#include <avr/io.h>

#include "../LIB/common_macros.h" /* For GET_BIT Macro */
#include "../MCAL/gpio.h"
float64 distance=0;
uint8 g_edgeCount = 0;
uint16 g_timeHigh=0;

void Ultrasonic_edgeProcessing(void)
{

	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_timeHigh = TIMER1_ICU_GetTCNT1();
		Icu_setEdgeDetectionType(RISING);
		g_edgeCount=0;
	}

}

void Ultrasonic_init(void)
{
	/* Create configuration structure for ICU driver */
	Timer1_ConfigType Icu_Config_ultrasonic = {timer1_PRESCALAR_CLK8,RISING};
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	TIMER1_ICU_Enable(&Icu_Config_ultrasonic);
	GPIO_setupPinDirection(TRIG_PORT_ID, TRIG_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(TRIG_PORT_ID, TRIG_PIN_ID,LOGIC_LOW);

}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIG_PORT_ID, TRIG_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIG_PORT_ID, TRIG_PIN_ID,LOGIC_LOW);
}
 uint16 Ultrasonic_readDistance(void)
 {
	 Ultrasonic_Trigger();
	 /*Calculation (distance in cm)
Sound velocity = 340.00 m/s = 34000 cm/s
The distance of Object (in cm) = 340000∗Time
2
 = 17000 * Time

Now, here we have selected an internal 8MHz oscillator frequency for ATmega16, with
Prescaler F_CPU/8 for timer frequency. Then time to execute 1 instruction is 1 us.
So, the timer gets incremented after 1 us time elapse.
= 17000 x (TIMER value) x 1 x 10^-6 cm
= 0.017 x (TIMER value) cm
= (TIMER value) / 58.8 cm
Note TIMER VALUE is the pulse width time calculated by the ICU
*/

	 distance=(float)g_timeHigh/57.5;
	 return distance;
 }
