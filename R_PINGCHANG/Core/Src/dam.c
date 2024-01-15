#include "dma.h"
#include "usart.h"


DMA_HandleTypeDef  UART1TxDMA_Handler;      //DMA句柄

void MYDMA_Config(DMA_Stream_TypeDef *DMA_Streamx)
{ 
		if((uint32_t)DMA_Streamx>(uint32_t)DMA2)//得到当前stream是属于DMA2还是DMA1
		{
					__HAL_RCC_DMA2_CLK_ENABLE();//DMA2时钟使能	
		}
		else 
		{
					__HAL_RCC_DMA1_CLK_ENABLE();//DMA1时钟使能 
		}
    
    __HAL_LINKDMA(&huart1,hdmatx,UART1TxDMA_Handler);    //将DMA与USART1联系起来(发送DMA)
    
    //Tx DMA配置
    UART1TxDMA_Handler.Instance=DMA_Streamx;                            //数据流选择
	  UART1TxDMA_Handler.Init.Request=DMA_REQUEST_USART1_TX;				      //USART1发送DMA
    UART1TxDMA_Handler.Init.Direction=DMA_MEMORY_TO_PERIPH;             //存储器到外设
    UART1TxDMA_Handler.Init.PeriphInc=DMA_PINC_DISABLE;                 //外设非增量模式
    UART1TxDMA_Handler.Init.MemInc=DMA_MINC_ENABLE;                     //存储器增量模式
    UART1TxDMA_Handler.Init.PeriphDataAlignment=DMA_PDATAALIGN_BYTE;    //外设数据长度:8位
    UART1TxDMA_Handler.Init.MemDataAlignment=DMA_MDATAALIGN_BYTE;       //存储器数据长度:8位
    UART1TxDMA_Handler.Init.Mode=DMA_CIRCULAR;                            //外设流控模式
    UART1TxDMA_Handler.Init.Priority=DMA_PRIORITY_MEDIUM;               //中等优先级
    UART1TxDMA_Handler.Init.FIFOMode=DMA_FIFOMODE_DISABLE;              
    UART1TxDMA_Handler.Init.FIFOThreshold=DMA_FIFO_THRESHOLD_FULL;      
    UART1TxDMA_Handler.Init.MemBurst=DMA_MBURST_SINGLE;                 //存储器突发单次传输
    UART1TxDMA_Handler.Init.PeriphBurst=DMA_PBURST_SINGLE;              //外设突发单次传输
    
    HAL_DMA_DeInit(&UART1TxDMA_Handler);   
    HAL_DMA_Init(&UART1TxDMA_Handler);
} 























 
 
