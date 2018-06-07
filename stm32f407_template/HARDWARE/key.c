#include "key.h"

void KEY_Init(){
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    GPIO_InitStructure.GPIO_Pin = KEY1_PIN|KEY2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    #ifdef ENABLE_KEY_WP
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//WK_UP 对应引脚 PA0 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;//下拉 
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化 GPIOA0
    #endif
}