#ifndef __W25QXX_H
#define __W25QXX_H

#include "sys.h"
#include "delay.h"
#include "spi.h"

// W25X系列/Q系列芯片列表
// W25Q80  ID  0XEF13
// W25Q16  ID  0XEF14
// W25Q32  ID  0XEF15
// W25Q64  ID  0XEF16
// W25Q128 ID  0XEF17
// W25Q256 ID  0XEF18
#define W25Q80 0XEF13
#define W25Q16 0XEF14
#define W25Q32 0XEF15
#define W25Q64 0XEF16
#define W25Q128 0XEF17
#define W25Q256 0XEF18

#define NM25Q80 0X5213
#define NM25Q16 0X5214
#define NM25Q32 0X5215
#define NM25Q64 0X5216
#define NM25Q128 0X5217
#define NM25Q256 0X5218

#define W25QXX_SPI_Handle (&hspi3)

/* 片选管脚定义 */
#define W25QXX_CS_GPIO_Port GPIOB
#define W25QXX_CS_GPIO_Port_Clk_Enable() __HAL_RCC_GPIOB_CLK_ENABLE()
#define W25QXX_CS_Pin GPIO_PIN_14

#define W25QXX_CS_L() HAL_GPIO_WritePin(W25QXX_CS_GPIO_Port, W25QXX_CS_Pin, GPIO_PIN_RESET)
#define W25QXX_CS_H() HAL_GPIO_WritePin(W25QXX_CS_GPIO_Port, W25QXX_CS_Pin, GPIO_PIN_SET)

extern uint16_t W25QXX_TYPE;
extern uint32_t W25QXX_SIZE;
extern uint8_t W25QXX_UID[8];

//////////////////////////////////////////////////////////////////////////////////
// 指令表
#define W25X_WriteEnable 0x06
#define W25X_WriteDisable 0x04
#define W25X_ReadStatusReg 0x05
#define W25X_ReadStatusReg2 0x35
#define W25X_ReadStatusReg3 0x15
#define W25X_WriteStatusReg 0x01
#define W25X_WriteStatusReg2 0x31
#define W25X_WriteStatusReg3 0x11
#define W25X_ReadData 0x03
#define W25X_FastReadData 0x0B
#define W25X_FastReadDual 0x3B
#define W25X_PageProgram 0x02
#define W25X_BlockErase 0xD8
#define W25X_SectorErase 0x20
#define W25X_ChipErase 0xC7
#define W25X_PowerDown 0xB9
#define W25X_ReleasePowerDown 0xAB
#define W25X_DeviceID 0xAB
#define W25X_ManufactDeviceID 0x90
#define W25X_JedecDeviceID 0x9F
#define W25X_Enable4ByteAddr 0xB7
#define W25X_Exit4ByteAddr 0xE9

uint8_t W25QXX_SPI_ReadWriteByte(uint8_t TxData);
int W25QXX_Init(void);
void W25QXX_ReadUniqueID(uint8_t UID[8]);
uint16_t W25QXX_ReadID(void);                    // 读取FLASH ID
uint8_t W25QXX_ReadSR(uint8_t regno);            // 读取状态寄存器
void W25QXX_4ByteAddr_Enable(void);              // 使能4字节地址模式
void W25QXX_Write_SR(uint8_t regno, uint8_t sr); // 写状态寄存器
void W25QXX_Write_Enable(void);                  // 写使能
void W25QXX_Write_Disable(void);                 // 写保护
void W25QXX_Write_NoCheck(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void W25QXX_Read(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);    // 读取flash
void W25QXX_Write(uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite); // 写入flash
void W25QXX_Erase_Chip(void);                                                     // 整片擦除
void W25QXX_Erase_Sector(uint32_t Dst_Addr);                                      // 扇区擦除
void W25QXX_Wait_Busy(void);                                                      // 等待空闲
void W25QXX_PowerDown(void);                                                      // 进入掉电模式
void W25QXX_WAKEUP(void);                                                         // 唤醒
uint32_t W25QXX_ReadCapacity(void);

#endif