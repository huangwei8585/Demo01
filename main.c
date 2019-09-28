/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 文件名  ： main.c
* 作者    ： Huangwei
* 版本    ： V1.0.0
* 时间    ： 2019/9/26
* 简要    ： 主函数  
********************************************************************
* 副本
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/* 头文件 ----------------------------------------------------------------*/
#include <ioCC2530.h>


#define LED1 P1_0     // P1_0定义为P1.0
#define LED2 P1_1     // P1_1定义为P1.1
#define LED3 P1_4     //P1_4定义为P1.4

unsigned int temp = 0;


/* 函数 ------------------------------------------------------------------*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：delay
* 参数：unsigned int time
* 返回：void
* 作者：Huangwei
* 描述：延时函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



void delay(unsigned int time)
{
    unsigned int i = 0;
    unsigned int j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 475; j++)
        {
             asm("NOP");
             asm("NOP");
             asm("NOP");
        }
    }
  
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：main
* 参数：void
* 返回：void
* 作者：Huangwei
* 描述：主函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


void main(void)
{
   P1SEL =~0x13;          //进行寄存器的初始化设置为IO口
   P1DIR |=0x13;           //设置为输出口
   P1SEL &=~0x13;         //点亮LED1 LED2 LED3
   while(1)               //进入死循环
   {
      LED1 =!LED1;
     delay(1000);
     LED2 =!LED2;
     delay(1000);
     LED3 =!LED3;
     delay(1000);
   }
 }
   

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：delay
* 参数：void
* 返回：void
* 作者：Huangwei
* 描述：延迟一秒
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/