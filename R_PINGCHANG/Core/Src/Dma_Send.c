//
// Created by zhu on 2024/2/4.
//

#include "Dma_Send.h"
static uint8_t  temp[1040];
static uint16_t temp16[512];
static uint32_t temp16_2[512];

int Average_Number=50;
volatile int mul_int_max = 0;
volatile int G_Clk_Rise_Number = 0;
volatile int G_Hamamatsu_Trigger_Rise_Number_U8 = 0;
volatile int G_Hamamatsu_Trigger_Rise_Number=0;


int index_count = 0;
int needreset1=0;
int needreset2=1;
int thisneedtransfor=1;
void  DMA_Send(){
    if(G_Clk_Rise_Number>=2080)
    {
        needreset1=1;
    }
    if(G_Hamamatsu_Trigger_Rise_Number>=512&&thisneedtransfor)
    {
        thisneedtransfor=0;
        for(int i=0;i<512;i++)
        {
            temp16_2[i]+=adc_ans[i];
        }

        if	(index_count%Average_Number==0)
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
        }
        needreset2=1;
        index_count++;
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
