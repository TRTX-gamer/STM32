/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    adc.h
 * @brief   This file contains all the function prototypes for
 *          the adc.c file
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
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define ADC_Sec 128

    extern u16 adcx[2][ADC_Sec];

    extern ADC_HandleTypeDef hadc1;
    extern DMA_HandleTypeDef hdma_adc1;

    /* USER CODE BEGIN Private defines */

    /* USER CODE END Private defines */

    void MX_ADC1_Init(void);

    /* USER CODE BEGIN Prototypes */

    u16 Get_Adc(u32 ch);
    u16 Get_Adc_Average(u32 ch, u8 times);
    u16 Get_Adc_Average_DMA(void);

    /* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */
