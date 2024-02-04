//
// Created by zhu on 2024/1/31.
//

#ifndef H750_CJSON_COMMUNICATION_STRUCT_H
#define H750_CJSON_COMMUNICATION_STRUCT_H

#ifndef COMMUNICATION_STRUCT_H
#define COMMUNICATION_STRUCT_H

// Define your communication structures here
// For example:
/*
如果发送和接受的数据结构一样，那么就定义一个结构体
struct MyComan_struct //对应的命令结构体 小驼峰命名法+struct
{
    uint8_t Command;
    uint16_t LenthofIn;
};



如果发送和接受的数据结构不一样，那么就分开定义
struct MyComan_Send_struct //对应的命令结构体 小驼峰命名法+Send_struct
{
    uint8_t Command;
    uint16_t LenthofIn;

};

struct MyComan_Recv_struct //对应的命令结构体 小驼峰命名法+Recv_struct
{
    uint8_t Command;
    uint16_t LenthofOut;

};



*/


#endif // COMMUNICATION_STRUCT_H


#endif //H750_CJSON_COMMUNICATION_STRUCT_H
