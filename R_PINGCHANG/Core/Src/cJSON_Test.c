
#include <stdio.h>
#include "cJSON_Test.h"
#include "stdbool.h"
struct paramstruct Parameters;      //声明结构体对象
extern  bool Printf_Flag ;
void cjson(uint8_t g_usart_json_string[])
{
    const char * json_string = g_usart_json_string;
    printf("JSON string: %s\r\n", json_string);
    cJSON *json = cJSON_Parse(json_string);
    if (json != NULL) {
        // 获取 JSON 对象中的值
        cJSON *temperature = cJSON_GetObjectItem(json, "temperature");
        // char * name 是结构体指针，通过name->valuestring访问结构体中成员的字符串
        cJSON *pn  = cJSON_GetObjectItem(json, "pn");
        cJSON *sn  = cJSON_GetObjectItem(json, "sn");
        cJSON *production_date   = cJSON_GetObjectItem(json, "production_date");
        cJSON *manufacturer = cJSON_GetObjectItem(json, "manufacturer");
        cJSON *Device_Pixel_Length = cJSON_GetObjectItem(json, "device_pixel_length");
        cJSON *Min_Integration_Time = cJSON_GetObjectItem(json, "min_in_time");
        cJSON *Max_Integration_Time = cJSON_GetObjectItem(json, "max_in_time");
        cJSON *Set_Integration_Time = cJSON_GetObjectItem(json, "set_integration_time");
        cJSON *Average_Number = cJSON_GetObjectItem(json, "average_number");
        cJSON *pixel_segment_1 = cJSON_GetObjectItem(json, "segment_1");
        cJSON *pixel_segment_2 = cJSON_GetObjectItem(json, "segment_2");
        cJSON *mul_int_max =  cJSON_GetObjectItem(json, "mul_max");
        if (temperature != NULL && pn != NULL && sn != NULL&& production_date != NULL
            && manufacturer != NULL&&Device_Pixel_Length!=NULL&&Min_Integration_Time!=NULL&&Max_Integration_Time!=NULL
            && Set_Integration_Time!=NULL&& Average_Number!=NULL&&pixel_segment_1!=NULL&&pixel_segment_2!=NULL&&mul_int_max!=NULL)//
        {
            // 打印解析结果
//            printf("Temperature: %d\n", temperature->valueint);
//            printf("Pn:%d\n", pn  ->valueint);
//            printf("Sn:%d\n", sn  ->valueint);
//            printf("Production_date:%d\n", production_date  ->valueint);
//            printf("Manufacturer:%d\n", manufacturer ->valueint);
//            printf("Device_Pixel_Length:%d\n", Device_Pixel_Length ->valueint);
//            printf("Set_Integration_Time:%d\n", Set_Integration_Time ->valueint);

            Parameters.sn = sn ->valueint;
            Parameters.pn = pn->valueint;
            Parameters.temperature = temperature->valueint;
            Parameters.production_date = production_date->valueint;
            Parameters.manufacturer = manufacturer->valueint;
            Parameters.Device_Pixel_Length = Device_Pixel_Length->valueint;
            Parameters.Min_Integration_Time = Min_Integration_Time->valueint;
            Parameters.Max_Integration_Time = Max_Integration_Time->valueint;
            Parameters.Set_Integration_Time = Set_Integration_Time->valueint;
            Parameters.Average_Number = Average_Number->valueint;
            Parameters.pixel_segment_1 = pixel_segment_1->valueint;
            Parameters.pixel_segment_2 = pixel_segment_2->valueint;
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