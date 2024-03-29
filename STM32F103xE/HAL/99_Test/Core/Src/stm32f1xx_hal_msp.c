/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32f1xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_tim2_ch2_ch4;

extern DMA_HandleTypeDef hdma_tim2_ch1;

extern DMA_HandleTypeDef hdma_tim2_ch3;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                    /**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /** NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  */
  // __HAL_AFIO_REMAP_SWJ_NOJTAG();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief TIM_Base MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base)
{
  if(htim_base->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 DMA Init */
    /* TIM2_CH2_CH4 Init */
    hdma_tim2_ch2_ch4.Instance = DMA1_Channel7;
    hdma_tim2_ch2_ch4.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_tim2_ch2_ch4.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_tim2_ch2_ch4.Init.MemInc = DMA_MINC_ENABLE;
    hdma_tim2_ch2_ch4.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_tim2_ch2_ch4.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_tim2_ch2_ch4.Init.Mode = DMA_CIRCULAR;
    hdma_tim2_ch2_ch4.Init.Priority = DMA_PRIORITY_MEDIUM;
    if (HAL_DMA_Init(&hdma_tim2_ch2_ch4) != HAL_OK)
    {
      Error_Handler();
    }

    /* Several peripheral DMA handle pointers point to the same DMA handle.
     Be aware that there is only one channel to perform all the requested DMAs. */
    __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC2],hdma_tim2_ch2_ch4);
    // __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC4],hdma_tim2_ch2_ch4);

    // /* TIM2_CH1 Init */
    // hdma_tim2_ch1.Instance = DMA1_Channel5;
    // hdma_tim2_ch1.Init.Direction = DMA_MEMORY_TO_PERIPH;
    // hdma_tim2_ch1.Init.PeriphInc = DMA_PINC_DISABLE;
    // hdma_tim2_ch1.Init.MemInc = DMA_MINC_ENABLE;
    // hdma_tim2_ch1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    // hdma_tim2_ch1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    // hdma_tim2_ch1.Init.Mode = DMA_NORMAL;
    // hdma_tim2_ch1.Init.Priority = DMA_PRIORITY_LOW;
    // if (HAL_DMA_Init(&hdma_tim2_ch1) != HAL_OK)
    // {
    //   Error_Handler();
    // }

    // __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC1],hdma_tim2_ch1);

    // /* TIM2_CH3 Init */
    // hdma_tim2_ch3.Instance = DMA1_Channel1;
    // hdma_tim2_ch3.Init.Direction = DMA_MEMORY_TO_PERIPH;
    // hdma_tim2_ch3.Init.PeriphInc = DMA_PINC_DISABLE;
    // hdma_tim2_ch3.Init.MemInc = DMA_MINC_ENABLE;
    // hdma_tim2_ch3.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    // hdma_tim2_ch3.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    // hdma_tim2_ch3.Init.Mode = DMA_NORMAL;
    // hdma_tim2_ch3.Init.Priority = DMA_PRIORITY_LOW;
    // if (HAL_DMA_Init(&hdma_tim2_ch3) != HAL_OK)
    // {
    //   Error_Handler();
    // }

    // __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC3],hdma_tim2_ch3);

  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }

}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspPostInit 0 */

  /* USER CODE END TIM2_MspPostInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM2 GPIO Configuration
    PA0-WKUP     ------> TIM2_CH1
    PA1     ------> TIM2_CH2
    PA2     ------> TIM2_CH3
    PA3     ------> TIM2_CH4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM2_MspPostInit 1 */

  /* USER CODE END TIM2_MspPostInit 1 */
  }

}
/**
* @brief TIM_Base MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
// void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base)
// {
//   if(htim_base->Instance==TIM2)
//   {
//   /* USER CODE BEGIN TIM2_MspDeInit 0 */

//   /* USER CODE END TIM2_MspDeInit 0 */
//     /* Peripheral clock disable */
//     __HAL_RCC_TIM2_CLK_DISABLE();

//     /* TIM2 DMA DeInit */
//     HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC2]);
//     HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC4]);
//     HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC1]);
//     HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC3]);
//   /* USER CODE BEGIN TIM2_MspDeInit 1 */

//   /* USER CODE END TIM2_MspDeInit 1 */
//   }

// }

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
