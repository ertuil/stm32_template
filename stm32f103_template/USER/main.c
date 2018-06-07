//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//重新整理By：Brotherzhao@lab117-USTC
//////////////////////////////////////////////////////////////////////////////////	 
//原作者：正点原子@ALIENTEK
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

#include "sys.h"
#include "stdio.h"
#include "delay.h"
#include "led.h"



//使用keil_v5，必须在mian.c加入这个函数
void assert_failed(uint8_t* file, uint32_t line)
{
 printf("Wrong parameters value: file %s on line %d\r\n", file, line);
 while(1);
}


int cycle=0;


//main函数
 int main(void)
 {		
 	 //初始化系统代码以及初始化所有外设代码
	 //以及一些只需要运行一次的代码
	 
	 
	 delay_init();//delay初始化
     LED_Init();//LED初始化
	 
	 
	while(1){
	//用户代码
	//需要反复执行的对优先级不敏感的代码	
		
		LED1_ON();//点亮LED1
		LED2_ON();//熄灭LED2
		delay_ms(500);
	    LED1_OFF();//熄灭LED1
	    LED2_OFF();//点亮LED2
		delay_ms(500);
		cycle++;
		if(cycle==100)
		{
			cycle=0;
		}
	}
 }
 

