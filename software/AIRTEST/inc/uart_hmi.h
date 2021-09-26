/*
 * uart.h
 *
 *  Created on: 2021-4-22
 *      Author: Administrator
 */

#ifndef UART_HMI_H_
#define UART_HMI_H_

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
typedef struct
{
	int (* send_byte)(unsigned char data);
	void (* send_string)(unsigned int len,unsigned char *str);
	int (* init6)(void);
	unsigned int (*baudrate)(unsigned int baudrate);
	void (*datachange)(unsigned char change);
}UART_HMI_T;

extern UART_HMI_T uart_hmi;	//����Ϊ�ⲿ��������ȫ��ʹ��




#endif /* UART_H_ */