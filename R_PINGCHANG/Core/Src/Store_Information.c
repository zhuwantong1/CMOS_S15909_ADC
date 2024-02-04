//
// Created by zhu on 2024/1/31.
//

#include "Store_Information.h"
#include <string.h>
#include <stdio.h>

char pn_number[12]; // 11 字节存储 pn 号，再加一个字节用于存放字符串结束符 '\0'
char sn_number[9];
char Product_Time[9];
char Manufacturer[7];
char Device_Pixel_Length[4];
uint8_t  Set_Integration_Time = 1;

void Printf_Pn_Number() {
    strcpy(pn_number, "IRIS_ZHU_01");
    printf("%s\n", pn_number);
}
void Printf_Sn_Number() {
    strcpy(sn_number, "Sensor_1");
    printf("%s\n", sn_number);
}
void Printf_Product_Time() {
    strcpy(Product_Time, "20240131");
    printf("%s\n", Product_Time);
}
void  Printf_Manufacturer() {
    strcpy(Manufacturer, "Iris");
    printf("%s\n", Manufacturer);
}
void  Printf_Device_Pixel_Length() {
    strcpy(Device_Pixel_Length, "512");
    printf("%s\n", Device_Pixel_Length);
}