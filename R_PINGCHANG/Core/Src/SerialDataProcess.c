//
// Created by zhu on 2024/1/29.
//
#include <stdbool.h>
#include "usart.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "cJSON_Test.h"
#include "SerialDataProcess.h"
#include "Communication_Protocol.h"
extern  bool Printf_Flag ;
uint8_t  cjson_buf[200];
void SerialDataProcess()
{
    uint8_t len;
    if (g_usart_rx_sta & 0x8000)        /* 接收到了数据 */
    {
        len = g_usart_rx_sta & 0x3FFF;  /* 获取有效数据长度 */
        g_usart_rx_buf[len] = '\0';     /* 末尾插入结束符 */
//        printf("接收到的JSON命令: ");
//        printf(" %s\r\n",g_usart_rx_buf);

        IRIS_Cut_Befor_Header(g_usart_rx_buf,len);
        IRIS_Protocol_Unpack(g_usart_rx_buf, len, 0x00, cjson_buf);
        cjson(cjson_buf);
//

        g_usart_rx_sta = 0;
        memset(g_usart_rx_buf, 0, sizeof(g_usart_rx_buf));
        memset(cjson_buf, 0, sizeof(cjson_buf));
    }else
    {
        Printf_Flag = false;
    }


}
