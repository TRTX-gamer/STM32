/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "timer.h"
#include "bspencoder.h"
#include "infraredtobe.h"

  extern double Encoder_1; // 当前1速度
  extern double Encoder_2; // 当前2速度
  extern double Encoder_3; // 当前3速度
  extern double Encoder_4; // 当前4速度

  void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
