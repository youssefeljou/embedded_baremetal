/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[2][20]={"EMBEDED","SYSTEM"};
	printf("str[0] =%s\n",str[0]);
	printf("str[1] =%s\n",str[1]);
	printf("str[1][3] =%c\n",str[1][3]);
	return EXIT_SUCCESS;
}
