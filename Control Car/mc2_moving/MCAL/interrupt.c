#include "interrupt.h"
#include "../LIB/common_macros.h"
#include "gpio.h"
#define INT0_Rising
#define INT1_Rising
#define INT2_Rising
void INT0_Init(void)
{
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);//config interrupt as input
	GICR  |= (1<<INT0);                  //enable interrupt
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
#ifdef  INT0_Rising

	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
#else
	MCUCR |= (1<<ISC00);
	MCUCR &= ~(1<<ISC01);
#endif
}

void INT1_Init(void)
{
	GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_INPUT);//config interrupt as input
	GICR  |= (1<<INT1);//enable interrupt
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
#ifdef  INT1_Rising

	MCUCR |= (1<<ISC11) | (1<<ISC10);   // Trigger INT0 with the raising edge
#else
	MCUCR |= (1<<ISC11);
	MCUCR &= ~(1<<ISC10);
#endif
}
void INT2_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_INPUT);//config interrupt as input
	GICR  |= (1<<INT2);//enable interrupt
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
#ifdef  INT2_Rising

	MCUCSR |= (1<<ISC2);  // Trigger INT0 with the raising edge
#else
	MCUCSR &= ~(1<<ISC2);
#endif
}
