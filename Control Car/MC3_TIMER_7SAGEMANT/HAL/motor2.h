/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dcMotor.h
 *
 * Description: Header file for DC Motor driver
 *
 * Author:youssef adel
 *
 *******************************************************************************/
#include "../LIB/std_types.h"

#ifndef MOTOR2_H_
#define MOTOR2_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* DC Motor HW Ports and Pins Ids */

#define Motor_IN1_PORT_ID      PORTD_ID
#define Motor_IN1_PIN_ID       PIN4_ID

#define Motor_IN2_PORT_ID      PORTD_ID
#define Motor_IN2_PIN_ID       PIN5_ID




/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void motor2_init();
void changeSpeed2(unsigned char x);
void rotate2_cw();
void rotate2_acw();
void motor2_stop();
/*
* Description :
* The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor
* based on the state input state value.
*  Send the required duty cycle to the PWM driver based on the required speed value.
*/



#endif /* DCMOTOR_H_ */
