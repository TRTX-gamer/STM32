#ifndef _USART_H
#define _USART_H
#include "sys.h"
#include "stdio.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
// ALIENTEK STM32F407开发板
//串口1初始化
//正点原子@ALIENTEK
//技术论坛:www.openedv.csom
//修改日期:2017/4/6
//版本：V1.0
//版权所有，盗版必究。
// Copyright(C) 正点原子 2009-2019
// All rights reserved
//********************************************************************************
// V1.0修改说明
//////////////////////////////////////////////////////////////////////////////////
#define USART_REC_LEN 11 //定义最大接收字节数 11
#define EN_USART1_RX 1    //使能（1）/禁止（0）串口1接收
#define EN_USART6_RX 1    //使能（1）/禁止（0）串口1接收

extern UART_HandleTypeDef UART1_Handler; // UART句柄
extern UART_HandleTypeDef UART6_Handler; // UART句柄
extern u8 USART_RX_BUF[USART_REC_LEN];   //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u16 USART_RX_STA;                 //接收状态标记
extern double TargetSpeed_1; // 目标速度
extern double TargetSpeed_2; // 目标速度

//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
void uart6_init(u32 bound);

#endif
