/*
 * Control_ECU.c
 *
 *  Created on: Nov 5, 2022
 *      Author: youssef
 */


#include "external_eeprom.h"
#include "gpio.h"
#include "util/delay.h"
#include "twi.h"
#include "timer.h"
#include "buzzer.h"
#include "motor.h"
#include<avr\io.h>
#include "uart.h"
#include "common_macros.h"
#include "pwm.h"
#include "std_types.h"


#define READY 0X01
#define RIGHT 0X02
#define WRONG 0X03
#define OPEN_DOOR 0X04
#define PASSWORD_CHANGE 0X05
#define CHANGE_DONE 0X06

uint8 password1[5];
uint8 password2[5];
uint8 password[5];
uint8 i=0;
uint8 flag=0,state;
void eeprom_write(uint8*_defaultPassword)
{
	uint8 i=0;
	uint16 address=0x0311;
	for(i=0;i<=4;i++)
	{

		EEPROM_writeByte(address,_defaultPassword[i]);
		address++;
	}
}
void eeprom_read()
{
	uint8 i=0;
	uint16 address=0x0311;
	for(i=0;i<=4;i++)
	{
		EEPROM_readByte(address,&password[i] );

		_delay_ms(10);
		address++;

	}
}
void receivepassword(uint8 *password)
{
	int i;
	for(i=0;i<=4; i++)
	{

		password[i]=UART_recieveByte();

	}
}
void check_password(uint8 *password1,uint8 * password2)
{
	for (i = 0; i < 5; i++)
	{
		if (password1[i]!=password2[i])
		{
			flag=1;
			break;

		}
	}
	if (flag==1)
	{
		flag=0;
		UART_sendByte(WRONG);
	}
	else
	{
		UART_sendByte(RIGHT);
	}

}
int main (void)
{
	SREG |= (1<<7);
	UART_ConfigType Config = {data_8_bit,Enabled_Even,Stop_1_bit,9600};
	UART_init(&Config);
	TWI_ConfigType configr = { 400000, 0x01 };
	TWI_init(&configr);
	motor_init();

	Buzzer_init();
	while(1)
	{
		UART_sendByte(READY);
		receivepassword(password1);
		eeprom_write(password1);
		UART_sendByte(READY);
		receivepassword(password2);
		check_password(password1, password2);
		eeprom_read();

		if (UART_recieveByte()==OPEN_DOOR)
		{
			UART_sendByte(READY);
			receivepassword(password2);

			_delay_ms(10);
			check_password( password2,password1);
			changeSpeed(100);
			rotate_cw();

			_delay_ms(15000);
			UART_sendByte(READY);

			motor_init();

			_delay_ms(3000);
			UART_sendByte(RIGHT);
			changeSpeed(100);
			rotate_acw();
			_delay_ms(15000);
			motor_init();
		}
		else if(UART_recieveByte()==PASSWORD_CHANGE)
		{
			UART_sendByte(READY);
			receivepassword(password1);
			eeprom_write(password1);
			UART_sendByte(READY);
			receivepassword(password2);
			check_password(password1, password2);
			eeprom_read();
			UART_sendByte(CHANGE_DONE);
		}
		else if (UART_recieveByte()==WRONG)
		{
			Buzzer_on();
		}

	}
}
