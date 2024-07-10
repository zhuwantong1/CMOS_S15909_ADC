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
char Device_Pixel_Length[10];
uint8_t  Min_Integration_Time = 10;
uint8_t  Max_Integration_Time = 100;

void Printf_Pn_Number() {
    strcpy(pn_number, "IRIS_ZHU_01");
    printf("PN: %s\r\n", pn_number);
}
void Printf_Sn_Number() {
    strcpy(sn_number, "Sensor_1");
    printf("SN: %s\r\n", sn_number);
}
void Printf_Product_Time() {
    strcpy(Product_Time, "20240131");
    printf("Production Date: %s\r\n", Product_Time);
}
void  Printf_Manufacturer() {
    strcpy(Manufacturer, "Iris");
    printf("Manufacturer: %s\r\n", Manufacturer);
}
void  Printf_Device_Pixel_Length() {
    strcpy(Device_Pixel_Length, "512");
    printf("Device pixel length: %s\r\n", Device_Pixel_Length);
}
void  Printf_Min_Integration_Time() {
    printf("Min Integration Time: %d\r\n", Min_Integration_Time);
}
void  Printf_Max_Integration_Time() {
    printf("Max Integration Time: %d\r\n", Max_Integration_Time);
}