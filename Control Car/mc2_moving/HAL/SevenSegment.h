#ifndef SevenSegment.h
#define SevenSegment.h

#include "../LIB/std_types.h"
#define SevenSegmentMode 7
#define COMMON_CATHOD

#if((SevenSegmentMode != 4) && (SevenSegmentMode != 7))

#error "Number of Data bits should be equal to 4 or 7"

#endif
#define SevenSegment_PORT_ID				 PORTC_ID
#ifdef  COMMON_CATHOD

#define COMMON_CATHOD_PORT_ID  			 PORTD_ID
#define COMMON_CATHOD_PIN_ID 			 PIN6_ID

#endif

#ifdef  COMMON_ANOD

#define COMMON_ANOD_PORT_ID				 PORTD_ID
#define COMMON_ANOD_PIN_ID				 PIN6_ID

#endif

#if (SevenSegmentMode == 4)

#define SevenSegment_PIN1_ID                 PIN0_ID
#define SevenSegment_PIN2_ID                 PIN1_ID
#define SevenSegment_PIN3_ID                 PIN2_ID
#define SevenSegment_PIN4_ID                 PIN3_ID

#elif (SevenSegmentMode == 7)


#define SevenSegment_PIN1_ID                 PIN1_ID
#define SevenSegment_PIN2_ID                 PIN2_ID
#define SevenSegment_PIN3_ID                 PIN3_ID
#define SevenSegment_PIN4_ID                 PIN4_ID
#define SevenSegment_PIN5_ID                 PIN5_ID
#define SevenSegment_PIN6_ID                 PIN6_ID
#define SevenSegment_PIN7_ID                 PIN7_ID

#endif

void Display_SevenSegment(unsigned char value);
void INIT_SevenSegment_Display();
#endif

