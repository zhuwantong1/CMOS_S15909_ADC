//
// Created by zhu on 2024/1/29.
//
#include "cJSON.h"
#include "stdbool.h"
#ifndef H750_CJSON_CJSON_TEST_H
#define H750_CJSON_CJSON_TEST_H
struct paramstruct {
    char * command;
    uint16_t Set_Integration_Time;//����ʱ�����100ms
    uint8_t Average_Number;
    int pixel_segment_1;
    int pixel_segment_2;  //segment_2���Ϊ2048
    uint8_t mul_int_max;
};

void cjson(uint8_t g_usart_json_string[]);
void parseNestedObject(cJSON *nestedObject);
struct paramstruct *GetParametesptr();
#endif //H750_CJSON_CJSON_TEST_H
