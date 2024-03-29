/*
 * uart.h
 *
 *  Created on: 2021-4-22
 *      Author: Administrator
 */

#ifndef UART_SDS011_H_
#define UART_SDS011_H_

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
	 float pm25_DATA;
	 float pm10_DATA;
	unsigned int receive_flag;
	unsigned int receive_count;
	unsigned char receive_buffer[BUFFER_SIZE];
	int (* send_byte)(unsigned char data);
	void (* send_string)(unsigned int len, unsigned char *str);
	int (* init5)(void);
	unsigned int (* baudrate)(unsigned int baudrate);
}UART_SDS011_T;

extern UART_SDS011_T uart_sds011;	//声明为外部变量，可全局使用




#endif /* UART_H_ */
