
#ifndef LQ12864_H_
#define LQ12864_H_


#include <stdio.h>
#include <sys/unistd.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include "../driver/code.h"

/*--------------------------------------------------------------------------------------
 *  Define
 *-------------------------------------------------------------------------------------*/
#define   OUT     1
#define   IN      0

#define high 1
#define low 0

#define	Brightness	0xCF
#define X_WIDTH 	128
#define Y_WIDTH 	64


void OLED_WrDat(unsigned char IIC_Data);
void OLED_WrCmd(unsigned char IIC_Command);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char bmp_dat);
void OLED_CLS(void);
void OLED_Init(void);
void OLED_P8x16Str(unsigned char x, unsigned char y,unsigned char ch[]);
void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char N);


/**********************************************
//IIC Start
**********************************************/
void IIC_Start()
{
   IOWR_ALTERA_AVALON_PIO_DIRECTION(SDA_BASE, OUT);
   IOWR_ALTERA_AVALON_PIO_DATA(SDA_BASE, 1);
   IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 1);
   usleep(10);
   IOWR_ALTERA_AVALON_PIO_DATA(SDA_BASE, 0);
   usleep(5);
}



/**********************************************
//IIC Stop
**********************************************/
void IIC_Stop()
{
	IOWR_ALTERA_AVALON_PIO_DIRECTION(SDA_BASE, OUT);
	IOWR_ALTERA_AVALON_PIO_DATA(SDA_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 0);
	usleep(10);
	IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 1);
	usleep(5);
	IOWR_ALTERA_AVALON_PIO_DATA(SDA_BASE, 1);
	usleep(10);
}


/*
 * ===  FUNCTION  ===================================================
 *         Name:  ack
 *  Description:  IIC应答
 * =================================================================
 */
void ack(void)
{
	alt_u8 tmp;

	IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_DIRECTION(SDA_BASE, IN);
	usleep(10);
	IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 1);
	usleep(5);
	tmp = IORD_ALTERA_AVALON_PIO_DATA(SDA_BASE);
	usleep(5);
	IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 0);
	usleep(10);
	while(tmp);
}

/**********************************************
// 通过I2C总线写一个字节
**********************************************/
void Write_IIC_Byte(alt_u8 IIC_Byte)
{
	alt_u8 i, tmp;

	IOWR_ALTERA_AVALON_PIO_DIRECTION(SDA_BASE, OUT);

	for(i=0; i<8; i++){
		IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 0);
		usleep(5);
		tmp = (IIC_Byte & 0x80) ? 1 : 0;
		IIC_Byte <<= 1;
		IOWR_ALTERA_AVALON_PIO_DATA(SDA_BASE, tmp);
		usleep(5);
		IOWR_ALTERA_AVALON_PIO_DATA(SCL_BASE, 1);
		usleep(10);
	}
}


/*********************OLED写数据************************************/
void OLED_WrDat(unsigned char IIC_Data)
{
	IIC_Start();
	Write_IIC_Byte(0x78);
	ack();
	Write_IIC_Byte(0x40);			//write data
	ack();
	Write_IIC_Byte(IIC_Data);
	ack();
	IIC_Stop();
}
/*********************OLED写操作************************************/
void OLED_WrCmd(unsigned char IIC_Command)
{
	IIC_Start();
	Write_IIC_Byte(0x78);            //Slave address,SA0=0
	ack();
	Write_IIC_Byte(0x00);			//write command
	ack();
	Write_IIC_Byte(IIC_Command);
	ack();
	IIC_Stop();
}
/*********************OLED 设置坐标************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y)
{
	OLED_WrCmd(0xb0+y);
	OLED_WrCmd(((x&0xf0)>>4)|0x10);
	OLED_WrCmd((x&0x0f)|0x01);
}
/*********************OLED图片设置************************************/
void OLED_Fill(unsigned char bmp_dat)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(bmp_dat);
	}
}
/*********************OLED复位************************************/
void OLED_CLS(void)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(0);
	}
}
/*********************OLED初始化************************************/
void OLED_Init(void)
{
//	delay(500);//初始化之前的延时很重要！
	usleep(500000);
	OLED_WrCmd(0xae);//--turn off oled panel
	OLED_WrCmd(0x00);//---set low column address
	OLED_WrCmd(0x10);//---set high column address
	OLED_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WrCmd(0x81);//--set contrast control register
	OLED_WrCmd(Brightness); // Set SEG Output Current Brightness
	OLED_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	OLED_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	OLED_WrCmd(0xa6);//--set normal display
	OLED_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
	OLED_WrCmd(0x3f);//--1/64 duty
	OLED_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WrCmd(0x00);//-not offset
	OLED_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
	OLED_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WrCmd(0xd9);//--set pre-charge period
	OLED_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WrCmd(0xda);//--set com pins hardware configuration
	OLED_WrCmd(0x12);
	OLED_WrCmd(0xdb);//--set vcomh
	OLED_WrCmd(0x40);//Set VCOM Deselect Level
	OLED_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WrCmd(0x02);//
	OLED_WrCmd(0x8d);//--set Charge Pump enable/disable
	OLED_WrCmd(0x14);//--set(0x10) disable
	OLED_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
	OLED_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7)
	OLED_WrCmd(0xaf);//--turn on oled panel
	OLED_Fill(0x00); //初始清屏
	OLED_Set_Pos(0,0);

}
/***************功能描述：显示6*8一组标准ASCII字符串	显示的坐标（x,y），y为页范围0～7****************/
/*
static void OLED_P6x8Str(unsigned char x, unsigned char y,unsigned char ch[])
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{
		c =ch[j]-32;
		if(x>126){x=0;y++;}
		OLED_Set_Pos(x,y);
		for(i=0;i<6;i++)
		OLED_WrDat(F6x8[c][i]);
		x+=6;
		j++;
	}
}*/
/*******************功能描述：显示8*16一组标准ASCII字符串	 显示的坐标（x,y），y为页范围0～7****************/

void OLED_P8x16Str(unsigned char x, unsigned char y,unsigned char ch[])
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{
		c =ch[j]-32;
		if(x>120){x=0;y++;}
		OLED_Set_Pos(x,y);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[c*16+i]);
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[c*16+i+8]);
		x+=8;
		j++;
	}
}
/*****************功能描述：显示16*16点阵  显示的坐标（x,y），y为页范围0～7****************************/

void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char N)
{
	unsigned char wm=0;
	unsigned int adder=32*N;
	OLED_Set_Pos(x , y);
	for(wm = 0;wm < 16;wm++)
	{
		OLED_WrDat(F16x16[adder]);
		adder += 1;
	}
	OLED_Set_Pos(x,y + 1);
	for(wm = 0;wm < 16;wm++)
	{
		OLED_WrDat(F16x16[adder]);
		adder += 1;
	}
}
/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
/*static void Draw_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {
	    	OLED_WrDat(BMP[j++]);
	    }
	}
}
*/



#endif /* LQ12864_H_ */
