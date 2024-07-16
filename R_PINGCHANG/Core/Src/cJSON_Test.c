
#include <stdio.h>
#include "cJSON_Test.h"
#include "stdbool.h"
#include <string.h>

struct paramstruct Parameters;      //声明结构体对象
extern  bool Printf_Flag ;
void cjson(uint8_t g_usart_json_string[])
{
    const char * json_string = g_usart_json_string;
    //printf("JSON string: %s\r\n", json_string);
    cJSON *json = cJSON_Parse(json_string);
    if (json != NULL) {
        // 获取 JSON 对象中的值
        cJSON *command = cJSON_GetObjectItem(json, "command");
        // char * name 是结构体指针，通过name->valuestring访问结构体中成员的字符串
        cJSON *Set_Integration_Time = cJSON_GetObjectItem(json, "integration_time");
        cJSON *Average_Number = cJSON_GetObjectItem(json, "average_number");
        cJSON *parameter = cJSON_GetObjectItemCaseSensitive(json, "pixel_segment");
        cJSON *mul_int_max =  cJSON_GetObjectItem(json, "mul_max");
        if (cJSON_IsObject(parameter)) {
            cJSON *pixel_segment_1 = cJSON_GetObjectItemCaseSensitive(parameter, "pixel_segment_1");
            if (cJSON_IsNumber(pixel_segment_1)) {
                Parameters.pixel_segment_1 = pixel_segment_1->valueint;
            }
            cJSON *pixel_segment_2 = cJSON_GetObjectItemCaseSensitive(parameter, "pixel_segment_2");
            if (cJSON_IsNumber(pixel_segment_2)) {
                Parameters.pixel_segment_2 = pixel_segment_2->valueint;
            }
        }
        if (command != NULL)
        {
            // 打印解析结果
//            printf("Temperature: %d\n", temperature->valueint);
//            printf("Pn:%d\n", pn  ->valueint);
//            printf("Sn:%d\n", sn  ->valueint);
//            printf("Production_date:%d\n", production_date  ->valueint);
//            printf("Manufacturer:%d\n", manufacturer ->valueint);
//            printf("Device_Pixel_Length:%d\n", Device_Pixel_Length ->valueint);
//            printf("Set_Integration_Time:%d\n", Set_Integration_Time ->valueint);
            strcpy(Parameters.command, command->valuestring);
            Parameters.Set_Integration_Time = Set_Integration_Time->valueint;
            Parameters.Average_Number = Average_Number->valueint;
            Parameters.mul_int_max =  mul_int_max->valueint;
        }



        Printf_Flag= true;
        // 释放 cJSON 对象
        cJSON_Delete(json);
    } else {
// 处理解析错误
        printf("JSON parsing error JSON parsing error JSON parsing error JSON parsing error.\n");
        Printf_Flag = false;

    }
}


struct paramstruct *GetParametesptr()
{
    return &Parameters;
}