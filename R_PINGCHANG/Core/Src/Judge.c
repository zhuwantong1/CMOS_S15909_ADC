//
// Created by zhu on 2024/1/31.
//

#include "Judge.h"
#include "cJSON_Test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "Dma_Send.h"
#include "Communication_Protocol.h"
#include "stdbool.h"
#include "tim.h"

#define Device_Pixel_Length        512
#define Manufacturer               "Iris"
#define Product_Time               20240131
#define Sn                         "Sensor_1"
#define Pn                         "IRIS_ZHU_01"
#define temperature                23.65

extern volatile int Average_Number;
extern volatile uint16_t delay_ms;
extern volatile int Segment_1;
extern volatile int Segment_2;
extern bool set_high;
//extern volatile int G_Clk_Rise_Number;
//extern volatile int G_Hamamatsu_Trigger_Rise_Number;


//char *segment_p1;
//char *segment_p2;
//char segment_info[40];
uint8_t segment_all[200];
uint length = 0;

bool dma_state = false;
uint8_t  Min_Integration_Time = 10;
uint8_t  Max_Integration_Time = 100;

void Judge(){
    struct paramstruct *ParamStructPtr;
    ParamStructPtr = GetParametesptr();
    //IRIS_Protocol_Pack(0x10,1040, uint8_t *BufferIn, uint8_t *PackData);
    if(strcmp(ParamStructPtr->command,"get_temperature") == 0&&dma_state)
    {
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "get_temperature");
        cJSON_AddNumberToObject(root, "temperature", temperature);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"get_dev_info") == 0&&dma_state)
    {
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "get_dev_info");
        cJSON_AddStringToObject(root, "sn", Sn);
        cJSON_AddStringToObject(root, "pn", Pn);
        cJSON_AddNumberToObject(root, "product_time", Product_Time);
        cJSON_AddStringToObject(root, "Manufacturer", Manufacturer);
        cJSON_AddNumberToObject(root, "device_pixel_length", Device_Pixel_Length);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }

    if(strcmp(ParamStructPtr->command,"get_min_integration_time") ==0&&dma_state)
    {
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "get_min_integration_time");
        cJSON_AddNumberToObject(root, "min_integration_time", Min_Integration_Time);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"get_max_integration_time") ==0&&dma_state)
    {
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "get_max_integration_time");
        cJSON_AddNumberToObject(root, "max_integration_time", Max_Integration_Time);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"set_integration_time") ==0&&dma_state)
    {
        if(ParamStructPtr->Set_Integration_Time<10)
        {
            delay_ms=10;
        }
        else if(ParamStructPtr->Set_Integration_Time>5000)
        {
            delay_ms=5000;
        }
        else
        {
            delay_ms = ParamStructPtr->Set_Integration_Time;
        }
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_integration_time");
        cJSON_AddNumberToObject(root, "integration_time", delay_ms);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"set_average_number") ==0&&dma_state)
    {
        if(ParamStructPtr->Average_Number<2)
        {
            Average_Number=2;
        }
        else
        {
            Average_Number=ParamStructPtr->Average_Number;
        }
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_average_number");
        cJSON_AddNumberToObject(root, "average_number", Average_Number);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"set_pixel_segment") ==0&&dma_state)
    {
        if(ParamStructPtr->pixel_segment_2>512)
        {
            ParamStructPtr->pixel_segment_2=512;
        }
        Segment_1 = ParamStructPtr -> pixel_segment_1;
        Segment_2 = ParamStructPtr -> pixel_segment_2;
//        * segment_p1 =  Segment_1;
//        * segment_p2 =  Segment_2;
//        strcpy(segment_info,"segment_1:");
//        sprintf(segment_p1, "%d", Segment_1);
//        strcat(segment_info, (const char *) segment_p1);
//        strcat(segment_info,"segment_2:");
//        sprintf(segment_p2, "%d", Segment_2);
//        strcat(segment_info, (const char *) segment_p2);
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_pixel_segment");
        cJSON_AddNumberToObject(root, "segment_1", Segment_1);
        cJSON_AddNumberToObject(root, "segment_2", Segment_2);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
//        length = sizeof(segment_info) / sizeof(segment_info[0]);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
    }
    if(strcmp(ParamStructPtr->command,"set_mul_max") ==0&&dma_state)
    {
        if(ParamStructPtr ->mul_int_max>50)
        {
            mul_int_max = 50;
        }
        else
        {
            mul_int_max= ParamStructPtr ->mul_int_max;
        }
        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_mul_max");
        cJSON_AddNumberToObject(root, "mul_max", mul_int_max);
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);

    }
    /**进行DMA的管控**/
    if(strcmp(ParamStructPtr->command,"set_dma_open") ==0&&dma_state)
    {

        HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);              // 启用捕获中断
        HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);              // 启用捕获中断
        G_Hamamatsu_Trigger_Rise_Number=0;
        G_Clk_Rise_Number=0;

        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_dma_open");;
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
        dma_state = false;
    }
    if(strcmp(ParamStructPtr->command,"set_dma_close") ==0&&!dma_state)
    {
        __disable_irq();
        HAL_TIM_IC_Stop_IT(&htim3, TIM_CHANNEL_1);
        HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_1);
        G_Hamamatsu_Trigger_Rise_Number=0;
        G_Clk_Rise_Number=0;
        __enable_irq();

        cJSON *root = cJSON_CreateObject(); // 创建一个 JSON 对象
        cJSON_AddStringToObject(root, "command", "set_dma_close");
        char *json_string = cJSON_Print(root); // 将 JSON 对象转换为字符串
        length = strlen(json_string);
        IRIS_Protocol_Pack(0x00,length,(uint8_t*)json_string,segment_all);
        HAL_UART_Transmit(&huart1,segment_all,sizeof(segment_all) / sizeof(segment_all[0]),100);
        memset(segment_all, 0, sizeof(segment_all));
        free(json_string);
        cJSON_Delete(root);
        dma_state = true;
    }
}