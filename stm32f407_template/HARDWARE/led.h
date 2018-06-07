#include "stm32f4xx.h"

#ifndef _LED_H
#define _LED_H


#define LED1_PORT GPIOF
#define LED1_PIN GPIO_Pin_9
#define LED2_PORT GPIOF
#define LED2_PIN GPIO_Pin_10

void LED_init();

#define LED1_ON() \
    {GPIO_ResetBits(LED1_PORT,LED1_PIN);}

#define LED2_ON() \
    {GPIO_ResetBits(LED2_PORT,LED2_PIN);}

#define LED2_OFF() \
    {GPIO_SetBits(LED2_PORT,LED2_PIN);}

#define LED1_OFF() \
    {GPIO_SetBits(LED1_PORT,LED1_PIN);}

#endif