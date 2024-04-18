/*
 * buzzer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Youmna
 */

#ifndef BUZZER_H_
#define BUZZER_H_


#define BUZZER_PORT_ID      PORTB_ID
#define BUZZER_PIN_ID       PIN0_ID

 void Buzzer_init();
 void Buzzer_on(void);
 void Buzzer_off(void);
#endif /* BUZZER_H_ */
