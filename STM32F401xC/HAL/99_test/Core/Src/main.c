/**
 * @file	05_PWM_2
 * @brief 	两路PWM发生器
 * @author 	TRTX-gamer
 * @version 1.00
 * @date 	2022年7月12号21点37分
 */

#include "delay.h"
#include "sys.h"
#include "led.h"
#include "timer.h"
#include "stm32f4xx.h"

// static u32 time_frequence = 0;
// static u32 time_arr = 0;
// static u32 time_psc = 0;

/**
 * @brief	主函数,程序入口
 * @param 	none
 * @arg		none
 * @note  	初始化函数后利用定时器PWM发生器实现两路PWM发生器
 * @retval	int
 */
int main(void)
{
	u8 dir = 1;
	u16 led0pwmval = 0;

	HAL_Init(); //初始化HAL库
	Stm32_Clock_Init(168, 25, 2, 4);
	delay_init(84); //初始化延时函数
	// LED_Init();						 //初始化LED
	// TIM3_Init(5000 - 1, 84 - 1);	 //定时器3初始化，周期为500ms
	TIM5_PWM_Init(500 - 1, 84 - 1); // 84M/84=1M的计数频率，自动重装载为500，那么PWM频率为1M/500=2kHZ

	while (1)
	{
		delay_ms(10);
		if (dir)
			led0pwmval++; // dir==1 led0pwmval递增
		else
			led0pwmval--; // dir==0 led0pwmval递减
		if (led0pwmval == 500)
			dir = 0; // led0pwmval到达300后，方向为递减
		if (led0pwmval == 0)
			dir = 1;					  // led0pwmval递减到0后，方向改为递增
		TIM_SetTIM5Compare_1(led0pwmval); //修改比较值，修改占空比
	}
}