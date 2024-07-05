//
// Created by zhu on 2024/1/31.
//



#include <stdint.h>
#include "Communication_struct.h"



/**
  ******************************************************************************
  * @file           : IRIS_Method.h
  * @author         : xin
  * @brief          : None
  * @attention      : None
  * @date           : 2024/2/1
  ******************************************************************************
  */

//
// Created by xin on 2024/2/1.
//

#ifndef IRIS_COMMUNICATION_PROTOCOL_IRIS_METHOD_H
#define IRIS_COMMUNICATION_PROTOCOL_IRIS_METHOD_H

#define ERROR_NOT_ENOUGH_DATA -200
#define ERROR_HEADER -300
#define ERROR_COMMAND -400
#define ERROR_INPUT -500
#define ERROR_CRC -600


// 成功返回打包后的数据长度
// -1: Error
// 成功返回打包后的数据长度
int32_t IRIS_Protocol_Pack(uint8_t Command,uint16_t LenthofIn, uint8_t *BufferIn, uint8_t *PackData);

// 解包函数 PackData 是接收到的数据 LenthofIn 是数据长度 Command 是命令 BufferOut 是输出
// 下位机使用的打包函数 Command 是输出
// 成功返回解包后的数据长度
// 0: 该命令返回无参数
// 错误返回ERRor
// 成功返回解包后的数据长度
int32_t IRIS_STM32_Protocol_Unpack(uint8_t *PackData, uint16_t LenthofIn, uint8_t *Command, uint8_t *BufferOut);

// 解包函数 PackData 是接收到的数据 LenthofIn 是数据长度 Command 是命令输入 BufferOut 是输出 上位机使用
// 成功返回解包后的数据长度
// 0: 该命令返回无参数
// 错误返回ERRor
// 成功返回解包后的数据长度
int32_t IRIS_Protocol_Unpack(uint8_t *PackData, uint16_t LenthofIn, uint8_t Command, uint8_t *BufferOut);

// 定义裁切命令
// 成功返回裁切后的数据长度
// -1: Error
int32_t IRIS_Cut_Befor_Header(uint8_t *PackData, uint16_t LenthofIn );

// 检查数据是否有效
// 有效返回值1
// 错误返回ERRor
int32_t IRIS_Check_Data_Valid(uint8_t *PackData, uint16_t LenthofIn );


// 返回CRC校验值
uint16_t IRIS_calcCRC(const void *pBuffer, uint16_t bufferSize);

#endif //IRIS_COMMUNICATION_PROTOCOL_IRIS_METHOD_H

