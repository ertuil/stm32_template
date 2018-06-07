#include "stm32f4xx.h"

#ifndef _KEY_H
#define _KEY_H

#define ENABLE_KEY_WP 1

#define KEY1_PORT GPIOE
#define KEY2_PORT GPIOE
#define KEP_WP_PORT GPIOA

#define KEY1_PIN GPIO_Pin_3
#define KEY2_PIN GPIO_Pin_4
#define KEY_WP_PIN GPIO_Pin_0



void KEY_Init();

#define READ_KEY1() GPIO_ReadInputDataBit(KEY1_PORT,KEY1_PIN)
#define READ_KEY2() GPIO_ReadInputDataBit(KEY2_PORT,KEY2_PIN)
#define READ_KEY_WP() GPIO_ReadInputDataBit(KEP_WP_PORT,KEY_WP_PIN)

#define IS_KEY1_ON() (READ_KEY1() == 0x00)
#define IS_KEY2_ON() (READ_KEY2() == 0x00)
#define IS_KEY_WP_ON() (READ_KEY_WP() == 0x01)


#endif