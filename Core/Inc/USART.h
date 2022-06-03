#include "main.h"

uint8_t temp;
uint8_t RxStringBuffer;

HAL_StatusTypeDef UART_SendString(float angle);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
