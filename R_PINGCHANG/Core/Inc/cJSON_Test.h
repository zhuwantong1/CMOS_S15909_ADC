//
// Created by zhu on 2024/1/29.
//
#include "cJSON.h"
#ifndef H750_CJSON_CJSON_TEST_H
#define H750_CJSON_CJSON_TEST_H
struct paramstruct {
    int temperature;
    int pn;
    int sn;
    int production_date;
    int manufacturer;
    int Device_Pixel_Length;
    uint8_t Min_Integration_Time;//积分时间最小3ms
    uint8_t Max_Integration_Time;//积分时间最大100ms
    uint8_t Set_Integration_Time;//积分时间最大100ms
    uint8_t Average_Number;
    int pixel_segment_1;
    int pixel_segment_2;  //segment_2最大为2048
    uint8_t mul_int_max;
};

void cjson(uint8_t g_usart_json_string[]);
void parseNestedObject(cJSON *nestedObject);
struct paramstruct *GetParametesptr();
#endif //H750_CJSON_CJSON_TEST_H
