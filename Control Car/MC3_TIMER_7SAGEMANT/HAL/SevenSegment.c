/*

 *  Author: youssef adel
 */

#include "SevenSegment.h"

#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/common_macros.h"
#include "../MCAL/gpio.h"

void INIT_SevenSegment_Display()
{
#ifdef COMMON_CATHOD

	GPIO_setupPinDirection(COMMON_CATHOD_PORT_ID,COMMON_CATHOD_PIN_ID,PIN_OUTPUT);     // configure pin 6 in PORTC as output pin
	GPIO_writePin(COMMON_CATHOD_PORT_ID, COMMON_CATHOD_PIN_ID, LOGIC_LOW);// Set pin 6 in PORTC with value 1 to enable the BJT NPN transistor to connect the first 7-segment common to the ground(common cathode)
#endif
#ifdef	COMMON_ANOD
	GPIO_setupPinDirection(COMMON_ANOD_PORT_ID,COMMON_ANOD_PIN_ID,PIN_OUTPUT);     // configure pin 6 in PORTC as output pin
	GPIO_writePin(COMMON_ANOD_PORT_ID, COMMON_ANOD_PIN_ID, LOGIC_HIGH);// Set pin 6 in PORTC with value 1 to enable the BJT NPN transistor to connect the first 7-segment common to the ground(common cathode)
#endif
#if (SevenSegmentMode == 4)
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, PIN_OUTPUT);
#elif (SevenSegmentMode == 7)
	// configure pins as output from PA1 --> PA7
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, PIN_OUTPUT);
#endif
}
void Display_SevenSegment(unsigned char value)
{

#if (SevenSegmentMode == 4)

	switch(value)
	{
	case 0:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 3:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 4:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 5:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 6:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 7:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		break;
	case 8:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		break;
	case 9:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		break;
	}


#elif (SevenSegmentMode == 7)
#ifdef COMMON_CATHOD
	switch(value)
	{
	case 0:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 3:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 4:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 5:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 6:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 7:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
		break;
	case 8:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	case 9:
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
		GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
		break;
	}

#endif
#ifdef COMMON_ANOD
	switch(value)
		{
		case 0:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
			break;
		case 1:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
			break;
		case 2:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 3:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 4:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 5:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 6:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 7:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_HIGH);
			break;
		case 8:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		case 9:
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN2_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN3_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN4_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN5_ID, LOGIC_HIGH);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN6_ID, LOGIC_LOW);
			GPIO_writePin(SevenSegment_PORT_ID, SevenSegment_PIN7_ID, LOGIC_LOW);
			break;
		}

#endif

#endif
}

