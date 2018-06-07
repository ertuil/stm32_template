#include "bluetooth.h"

void BLUETOOTH_Init(){
    uart_init(9600);
}

void u_sent_str(u8* str,u8 len){
    u8 ii = 0;
    for(;ii < len; ++ii){
        USART_SendData(USART1, str[ii]);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
    }
}

void u_sent_num(u32 num){
    u8 ii = 0;
    s8 jj;
    u8 data[256];
    while(num){
        data[ii++] = num % 10 + 48;
        num /= 10;
    }
    for(jj = ii-1;jj >= 0;--jj){
        USART_SendData(USART1, data[jj]);
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
    }
}

void 