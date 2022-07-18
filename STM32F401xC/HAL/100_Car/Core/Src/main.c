/**
 * @file	07_OLED_PWM
 * @brief 	OLED显示管脚的PWM频率
 *          GND    电源地
 *          VCC  接5V或3.3v电源
 *          D0   接（SCL）,可在oled.h里更改
 *          D1   接（SDA）,可在oled.h里更改
 *          RES  PD2（SPI模块改成IIC模块需要接此引脚，IIC模块用户请忽略）
 * @author 	TRTX-gamer
 * @version 1.00
 * @date 	2022年7月14号15点23分
 */

#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "timer.h"
#include "bspencoder.h"
#include "oled.h"
#include "led.h"

u16 pwmval_1 = 350; // 定时器PWM占空比设置
u16 pwmval_2 = 350; // 定时器PWM占空比设置
int Encoder_1;		// 外部变量，当前1速度
int Encoder_2;		// 外部变量，当前2速度
int MotorRun;		// 0: stop, 1: run
int TargetSpeed;	// 外部变量，目标速度

/**
 * @brief	主函数,程序入口
 * @param 	none
 * @arg		none
 * @note  	初始化函数后利用定时器5PWM发生器实现4路PWM发生器
 * @retval	int
 */
int main(void)
{

	u16 arr = 500 - 1;
	u16 psc = 84 - 1;
	u32 freq = 84 / (psc + 1) / (arr + 1) * 1000;

	HAL_Init();
	Stm32_Clock_Init(168, 25, 2, 4);
	delay_init(84); //初始化延时函数
	LED_Init();		//初始化LED
	OLED_Init();
	TIM2_Init(10000 - 1, 84 - 1);	   // 100Hz刷新OLED
	TIM5_PWM_Init(arr, psc, 0B1111);   // 2kHz，50%，4路,84M/84=1M的计数频率，自动重装载为500，那么PWM频率为1M/500=2kHZ
	Encoder_Init();					   // 初始化电机编码器
	TIM_SetTIM5Compare_n(pwmval_1, 2); //修改比较值，修改占空比
	TIM_SetTIM5Compare_n(pwmval_2, 3); //修改比较值，修改占空比
	OLED_Display();					   //显示初始化信息
	while (1)
	{
	}
}