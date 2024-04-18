/*
 * buzzer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Youmna
 */
#include "buzzer.h"
#include "gpio.h"
 void Buzzer_init()
 {
	 GPIO_setupPinDirection( BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT );
	Buzzer_off();

 }
 void Buzzer_on(void)
 {
	 GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
 }
 void Buzzer_off(void)
 {
	 GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
 }
