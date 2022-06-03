/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lsm6dsl_read_data_polling.h"
#include<stdlib.h>
#include "math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LCD.h"
#include "BTN.h"
#include "ComplementaryFilter.h"
#include "USART.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;
UART_HandleTypeDef huart2;
uint8_t BTN1_State;
uint8_t BTN2_State;
uint8_t BTN1_PrevState;
uint8_t BTN2_PrevState;
float startTime;
float endTime;
float diffTime;
uint64_t sysClockFreq;
float angle;
int8_t intAngle;
char angleMessage[32];
float sysTickTimeNanosec;
float degreePerPixel;
char buffer[2];
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LCD_DB0_Pin GPIO_PIN_0
#define LCD_DB0_GPIO_Port GPIOC
#define LCD_DB1_Pin GPIO_PIN_1
#define LCD_DB1_GPIO_Port GPIOC
#define LCD_DB2_Pin GPIO_PIN_2
#define LCD_DB2_GPIO_Port GPIOC
#define LCD_DB3_Pin GPIO_PIN_3
#define LCD_DB3_GPIO_Port GPIOC
#define LCD_BL_PWM_OUTPUT_Pin GPIO_PIN_0
#define LCD_BL_PWM_OUTPUT_GPIO_Port GPIOA
#define MKI178_CS_Pin GPIO_PIN_4
#define MKI178_CS_GPIO_Port GPIOA
#define MKI178_SCK_Pin GPIO_PIN_5
#define MKI178_SCK_GPIO_Port GPIOA
#define MKI178_MISO_Pin GPIO_PIN_6
#define MKI178_MISO_GPIO_Port GPIOA
#define MKI178_MOSI_Pin GPIO_PIN_7
#define MKI178_MOSI_GPIO_Port GPIOA
#define LCD_DB4_Pin GPIO_PIN_4
#define LCD_DB4_GPIO_Port GPIOC
#define LCD_DB5_Pin GPIO_PIN_5
#define LCD_DB5_GPIO_Port GPIOC
#define MKI178_INT1_Pin GPIO_PIN_1
#define MKI178_INT1_GPIO_Port GPIOB
#define MKI178_INT2_Pin GPIO_PIN_2
#define MKI178_INT2_GPIO_Port GPIOB
#define LCD_DB6_Pin GPIO_PIN_6
#define LCD_DB6_GPIO_Port GPIOC
#define LCD_DB7_Pin GPIO_PIN_7
#define LCD_DB7_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_8
#define LCD_RST_GPIO_Port GPIOC
#define LCD_RW_Pin GPIO_PIN_9
#define LCD_RW_GPIO_Port GPIOC
#define LCD_CS1_Pin GPIO_PIN_8
#define LCD_CS1_GPIO_Port GPIOA
#define LCD_CS2_Pin GPIO_PIN_9
#define LCD_CS2_GPIO_Port GPIOA
#define LCD_E_Pin GPIO_PIN_10
#define LCD_E_GPIO_Port GPIOA
#define LCD_DI_Pin GPIO_PIN_11
#define LCD_DI_GPIO_Port GPIOA
#define LCD_OE_Pin GPIO_PIN_12
#define LCD_OE_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LCD_BL_PWM_Pin GPIO_PIN_10
#define LCD_BL_PWM_GPIO_Port GPIOC
#define BTN1_Pin GPIO_PIN_11
#define BTN1_GPIO_Port GPIOC
#define BTN2_Pin GPIO_PIN_12
#define BTN2_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
