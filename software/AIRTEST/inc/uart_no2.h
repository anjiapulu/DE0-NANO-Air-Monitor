/*
 * uart.h
 *
 *  Created on: 2021-4-22
 *      Author: Administrator
 */

#ifndef UART_NO2_H_
#define UART_NO2_H_

/*-----------------------------------------------------------------------------
 *  Include
 *-----------------------------------------------------------------------------*/
#include "../inc/sopc.h"

/*-----------------------------------------------------------------------------
 *  Define
 *-----------------------------------------------------------------------------*/
#define BUFFER_SIZE 200

/*------------------------------------------------------------------------------
 *  Struct
 *-----------------------------------------------------------------------------*/
typedef struct{
	 float NO2_DATA;
	unsigned int receive_flag;
	unsigned int receive_count;
	unsigned char receive_buffer[BUFFER_SIZE];
	int (* send_byte)(unsigned char data);
	void (* send_string)(unsigned int len, unsigned char *str);
	int (* init3)(void);
	unsigned int (* baudrate)(unsigned int baudrate);
}UART_NO2_T;

extern UART_NO2_T uart_no2;	//声明为外部变量，可全局使用




#endif /* UART_H_ */
