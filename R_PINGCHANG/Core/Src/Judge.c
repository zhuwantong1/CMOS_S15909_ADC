//
// Created by zhu on 2024/1/31.
//

#include "Judge.h"

void Judge(){
    struct paramstruct *ParamStructPtr;
    ParamStructPtr = GetParametesptr();
    //IRIS_Protocol_Pack(0x10,1040, uint8_t *BufferIn, uint8_t *PackData);
    if(ParamStructPtr->pn == 1 ){
        Printf_Pn_Number();
    }
    if(ParamStructPtr->sn == 1){
        Printf_Sn_Number();
    }
    if(ParamStructPtr->production_date ==1){
        Printf_Product_Time();
    }
    if(ParamStructPtr->manufacturer ==1){
        Printf_Manufacturer();
    }
    if(ParamStructPtr->Device_Pixel_Length ==1){
        Printf_Device_Pixel_Length();
    }
    if(ParamStructPtr->temperature==1){
        printf("Temperature:%.1f\r\n",Get_Temperature());
    }
    if(ParamStructPtr->Set_Integration_Time!=0){
        Control_St(ParamStructPtr->Set_Integration_Time);
    }


}