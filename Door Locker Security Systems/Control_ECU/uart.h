/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	data_5_bit,data_6_bit,data_7_bit,data_8_bit
}Data_Bits;

typedef enum
{
	Disabled,Reserved,Enabled_Even,Enabled_odd
}Parity_Mode;
typedef enum
{
	Stop_1_bit,Stop_2_bit
}Stop_Bits;
typedef struct
{
	Data_Bits    DATA;
	Parity_Mode  PARITY;
	Stop_Bits   STOP;
	uint32 Baud_Rate  ;
}UART_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 /*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1.insert the required parity value
 * 2.insert the required Stop value.
 * 3.insert the required data value.
 * 4.insert the required Baud Rate.
 */

void UART_init(const UART_ConfigType * Config_Ptr);


/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
