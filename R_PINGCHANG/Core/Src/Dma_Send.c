//
// Created by zhu on 2024/2/4.
//

#include "Dma_Send.h"
#include "cJSON_Test.h"
static uint8_t  temp[1040];
static uint16_t temp16[512];
static uint32_t temp16_2[512];

volatile int Average_Number=10;
volatile int mul_int_max = 1;
volatile int G_Clk_Rise_Number = 0;
volatile int G_Hamamatsu_Trigger_Rise_Number_U8 = 0;
volatile int G_Hamamatsu_Trigger_Rise_Number=0;


int index_count = 0;
int needreset1=0;
int needreset2=1;
int thisneedtransfor=1;
uint8_t delay_ms=3;
extern struct paramstruct Parameters;

void  DMA_Send(){

    if(G_Clk_Rise_Number>=2080)
    {
        __disable_irq();
        needreset1=1;
    }
    if(G_Hamamatsu_Trigger_Rise_Number>=512&&thisneedtransfor)
    {
        __disable_irq();
        thisneedtransfor=0;
        if(mul_int==mul_int_max)
        {
            for(int i=0;i<512;i++)
            {
                temp16_2[i] += adc_ans[i];//将采集到的16位数据放在temp16_2中
            }
        }

            //这里使用index_count%Average_Number==0，会出bug，用下面的方法不会出现，问题还没找到原因
        if	(index_count==Average_Number)//如果没有到达50次平均那就接着采集，达到50次之后再取平均值，dma发送
        {
            for(int i=0;i<512;i++)
            {
                temp16[i]=temp16_2[i]/Average_Number;
                temp16_2[i]=0;
            }
            temp[0]=0xff;
            temp[1]=0xff;
            /****    void *memcpy(void *dest, const void *src, size_t n);    *****/
            memcpy(temp+2,temp16,1024);
            HAL_UART_Transmit_DMA(&huart1,temp,1026);
            index_count = 0;
        }
        needreset2=1;
        if(mul_int==mul_int_max)
        {
            index_count++;
        }
        else
        {
            index_count=index_count;
        }
//        index_count++;
        __enable_irq();
//        RCCdelay_us(2);
        HAL_Delay(delay_ms);

    }
    if(mul_int>mul_int_max)
    {
        mul_int=0;
    }
    if(needreset1==1&&needreset2==1)
    {
        __disable_irq();
        mul_int++;
        G_Clk_Rise_Number=0;
        G_Hamamatsu_Trigger_Rise_Number_U8=0;
        G_Hamamatsu_Trigger_Rise_Number=0;

        __enable_irq();
        needreset1=0;
        needreset2=0;
        thisneedtransfor=1;
    }

}
