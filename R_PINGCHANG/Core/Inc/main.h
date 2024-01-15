/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern volatile int G_Clk_Rise_Number;
extern volatile int G_Hamamatsu_Trigger_Rise_Number_U8;
extern volatile int G_Hamamatsu_Trigger_Rise_Number;
extern volatile int mul_int ;
extern volatile int mul_int_max;


extern uint16_t adc_ans[540];
extern uint8_t adc_ans_u8[2080];
void RCCdelay_us(uint32_t udelay);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA
#define ST_Pin GPIO_PIN_2
#define ST_GPIO_Port GPIOA
#define EX_INT_Pin GPIO_PIN_6
#define EX_INT_GPIO_Port GPIOA
#define INT_Pin GPIO_PIN_7
#define INT_GPIO_Port GPIOA
#define CLM_Pin GPIO_PIN_4
#define CLM_GPIO_Port GPIOC
#define RST_Pin GPIO_PIN_5
#define RST_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
