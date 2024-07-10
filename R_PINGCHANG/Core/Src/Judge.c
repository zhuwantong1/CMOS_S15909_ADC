//
// Created by zhu on 2024/1/31.
//

#include "Judge.h"
#include "cJSON_Test.h"

extern volatile int Average_Number;
extern volatile uint8_t delay_ms;
extern volatile int Segment_1;
extern volatile int Segment_2;
void Judge(){
    struct paramstruct *ParamStructPtr;
    ParamStructPtr = GetParametesptr();
    //IRIS_Protocol_Pack(0x10,1040, uint8_t *BufferIn, uint8_t *PackData);
    if(ParamStructPtr->pn == 1 )
    {
        Printf_Pn_Number();
    }
    if(ParamStructPtr->sn == 1)
    {
        Printf_Sn_Number();
    }
    if(ParamStructPtr->production_date ==1)
    {
        Printf_Product_Time();
    }
    if(ParamStructPtr->manufacturer ==1)
    {
        Printf_Manufacturer();
    }
    if(ParamStructPtr->Device_Pixel_Length ==1)
    {
        Printf_Device_Pixel_Length();
    }
    if(ParamStructPtr->temperature==1)
    {
        printf("Temperature:%.1f\r\n",Get_Temperature());
    }
    if(ParamStructPtr->Min_Integration_Time==1)
    {
        Printf_Min_Integration_Time();
    }
    if(ParamStructPtr->Max_Integration_Time==1)
    {
        Printf_Max_Integration_Time();
    }
    if(ParamStructPtr->Set_Integration_Time!=0){
        if(ParamStructPtr->Set_Integration_Time<10)
        {
            delay_ms=10;
        }
        else if(ParamStructPtr->Set_Integration_Time>100)
        {
            delay_ms=100;
        }
        else
        {
            delay_ms = ParamStructPtr->Set_Integration_Time;
        }
        printf("Set_Integration_Time: %d\r\n",delay_ms);
    }
    if(ParamStructPtr->Average_Number!=0)
    {
        Average_Number=ParamStructPtr->Average_Number;
        printf("Average_Number: %d\r\n",Average_Number);
    }
    if(ParamStructPtr->pixel_segment_1>=0&&ParamStructPtr ->pixel_segment_2>=0)
    {
        if(ParamStructPtr->pixel_segment_2>512)
        {
            ParamStructPtr->pixel_segment_2=512;
        }
        Segment_1 = ParamStructPtr -> pixel_segment_1;
        Segment_2 = ParamStructPtr -> pixel_segment_2;
        printf("Segment_1: %d\r\n",Segment_1);
        printf("Segment_2: %d\r\n",Segment_2);

    }



}