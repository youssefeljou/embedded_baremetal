/*
 * GIE.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Menna
 */
#include "../LIB/std_types.h"
#include "../LIB/common_macros.h" /* To use the macros like SET_BIT */
#include"GIE.h"
#include<avr/io.h>
void GIE_Enabled(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_Disabled(void)
{
	CLEAR_BIT(SREG,SREG_I);
}
