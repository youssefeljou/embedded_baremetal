/*
 * check_password.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Youmna
 */

#ifndef CHECK_PASSWORD_H_
#define CHECK_PASSWORD_H_
void getFirstPassword(uint8 *password);
void getPassword();
void mainOptions();
void reEnter();

void sendpassword(uint8 *password);


#define READY 0x01
#define RIGHT 0x02
#define WRONG 0x03
#define OPEN_DOOR 0x04
#define PASSWORD_CHANGE 0x05
#define CHANGE_DONE 0X06


#endif /* CHECK_PASSWORD_H_ */
