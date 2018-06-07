#ifndef _BLUE_H
#define _BLUE_H

#include "stm32f4xx.h"
#include "usart.h"

void BLUETOOTH_Init();
void u_sent_str(u8* str,u8 len);
void u_sent_num(u32 num);
#endif