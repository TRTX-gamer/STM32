/**
 * @file	oledconf.h
 * @brief 	OLED相关驱动配置文件
 *          根据实际设备配置，硬件IIC，SPI相关配置在CORE中
 * @author 	TRTX-gamer      https://github.com/TRTX-gamer；
 *          突然吐血    https://space.bilibili.com/12890038;
 * @version 1.00
 * @date 	2022年9月17号15点22分
 */

#ifndef __OLEDCONF_H
#define __OLEDCONF_H

/* OLED 设备IC选择 */
#define OLED_SSD1306_SSD1315 0 // 设备IC为1306或1315，我的设备是单色
#define OLED_SSD1351 1         // 设备IC为1351，我的设备是RGB

/* OLED 驱动接口定义 */
#define OLED_SOFT 0 // 软件模拟通信
#define OLED_HARD 1 // 硬件通信

#define OLED_IIC_INTERFACE 0 // iic 接口
#define OLED_SPI_INTERFACE 1 // spi 接口

/* OLED 具体选择 */
#define _OLED_DRIVER_IC_TYPE OLED_SSD1306_SSD1315 // 改SSD种类
#define _SOFT_OR_HARE OLED_HARD                   // 改是否软件模拟
#define _DRIVE_INTERFACE_TYPE OLED_SPI_INTERFACE  // 改接口类型

/* OLED 的通信地址 */
#define OLED_ADDRESS 0x78

/* OLED 的宽度和高度 */
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

/* OLED IIC延时时间 */
#define OledDrv_IICDelay_Time 0

#endif // __OLEDCONF_H
