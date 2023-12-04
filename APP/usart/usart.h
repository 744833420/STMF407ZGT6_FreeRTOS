#ifndef __USART_H
#define __USART_H
#include "stdio.h"
#include "stm32f4xx_conf.h"
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//串口1初始化
//STM32F4工程-库函数版本
//淘宝店铺：http://mcudev.taobao.com
//********************************************************************************

//////////////////////////////////////////////////////////////////////////////////
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收

extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u16 USART_RX_STA;         		//接收状态标记

extern u8 len;


//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
#endif


