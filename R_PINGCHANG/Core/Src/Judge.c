//
// Created by zhu on 2024/1/31.
//

#include "Judge.h"
#include "cJSON_Test.h"

extern int Average_Number;
extern uint8_t delay_ms;
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
    if(ParamStructPtr->Set_Integration_Time!=0){
        delay_ms = ParamStructPtr->Set_Integration_Time;
        printf("Set_Integration_Time: %d\r\n",delay_ms);
    }
    if(ParamStructPtr->Average_Number!=0)
    {
        Average_Number=ParamStructPtr->Average_Number;
        printf("Average_Number: %d\r\n",Average_Number);
    }



}