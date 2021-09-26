/*
 * uart.c
 *
 *  Created on: 2021-4-22
 *      Author: Administrator
 */

/*--------------------------------------------------------------------------------------
 *  Include
 *-------------------------------------------------------------------------------------*/
#include "sys/alt_irq.h"
#include <stdlib.h>
#include <stdio.h>
#include "../inc/uart_so2.h"
#include "../inc/sopc.h"

/*--------------------------------------------------------------------------------------
 *  Function Prototype
 *------------------------------------------------------------------------------------*/
static int uart_send_byte(unsigned char data);
static void uart_send_string(unsigned int len, unsigned char *str);
static int uart_init(void);
static void uart_so2_ISR(void);
static int set_baudrate(unsigned int baudrate);

/*--------------------------------------------------------------------------------------
 *  Struct initialize
 *------------------------------------------------------------------------------------*/
UART_SO2_T uart_so2={
	.SO2_DATA=0,
	.tem_DATA=0,
	.hum_DATA=0,
	.receive_flag=0,
    .receive_count=0,
    .send_byte=uart_send_byte,
    .send_string=uart_send_string,
    .init=uart_init,
    .baudrate=set_baudrate
    };

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  uart_send_byte
 *  Description:
 * =====================================================================================
 */
int uart_send_byte(unsigned char data)
{
	UART_SO2->TXDATA.BITS.TRANSMIT_DATA = data;
    while(!UART_SO2->STATUS.BITS.TRDY);

    return 0;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  uart_send_string
 *  Description:
 * =====================================================================================
 */
void uart_send_string(unsigned int len, unsigned char *str)
{
    while(len--)
    {
        uart_send_byte(*str++);
    }
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  uart_init
 *  Description:
 * =====================================================================================
 */
int uart_init(void)
{

	set_baudrate(9600);	//查阅SO2传感器数据手册里面的通信协议
	//主动上传
	//主动读取气体浓度值
	//unsigned char buffer[]={0xFF, 0x01, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78};
    unsigned char buffer1[]={0xFF, 0x01, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78};
    uart_so2.send_string(sizeof(buffer1),buffer1);
    UART_SO2->CONTROL.BITS.IRRDY=1;
    UART_SO2->STATUS.WORD=0;

    //alt_irq_register(UART_IRQ, NULL, uart_ISR);
    alt_ic_isr_register(UART_SO2_IRQ_INTERRUPT_CONTROLLER_ID,UART_SO2_IRQ,uart_so2_ISR,NULL,0x0);

    return 0;

}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  uart_ISR
 *  Description:
 * =====================================================================================
 */
static void uart_so2_ISR(void)
{
	while(!(UART_SO2->STATUS.BITS.RRDY));

	uart_so2.receive_buffer[uart_so2.receive_count++] = UART_SO2->RXDATA.BITS.RECEIVE_DATA;

	if(uart_so2.receive_buffer[0] != 0xFF){
		uart_so2.receive_count = 0;
		uart_so2.receive_buffer[0] = 0;
	}

	if(uart_so2.receive_count == 13){
		if(uart_so2.receive_buffer[1] == 0x87){
			uart_so2.SO2_DATA = (float)(uart_so2.receive_buffer[2]*256+uart_so2.receive_buffer[3])/1000;
			uart_so2.tem_DATA = (float)((uart_so2.receive_buffer[8])<<8|uart_so2.receive_buffer[9])/100;
			uart_so2.hum_DATA = (float)((uart_so2.receive_buffer[10])<<8|uart_so2.receive_buffer[11])/100;
			uart_so2.receive_flag=1;
		}
		uart_so2.receive_count=0;
	}
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  set_baudrate
 *  Description:
 * =====================================================================================
 */
int set_baudrate(unsigned int baudrate)
{
	UART_SO2->DIVISOR.WORD=(unsigned int)(ALT_CPU_FREQ/baudrate+0.5);
	return 0;
}






