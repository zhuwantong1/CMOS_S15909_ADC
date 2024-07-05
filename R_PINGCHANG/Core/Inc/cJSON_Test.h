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
    uint8_t Set_Integration_Time;//积分时间最大100ms
    uint8_t Average_Number;
};

void cjson(uint8_t g_usart_json_string[]);
void parseNestedObject(cJSON *nestedObject);
struct paramstruct *GetParametesptr();
#endif //H750_CJSON_CJSON_TEST_H
