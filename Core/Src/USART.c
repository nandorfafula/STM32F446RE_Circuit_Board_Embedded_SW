#include "USART.h"

uint8_t temp = 0;
uint8_t RxStringBuffer = 2;

HAL_StatusTypeDef UART_SendString(float angle)
{
	intAngle = angle;
	sprintf(buffer, "%d", intAngle);

	char txBuffer[255];
	uint16_t length = 0;
    while(*(buffer+length) && length<255)
    {
    	*(txBuffer+length) = *(buffer+length);
    	length++;
    }
	return HAL_UART_Transmit(&huart2, (uint8_t*)txBuffer, length, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart2)
	{
		temp++;
		//HAL_UART_Receive(&huart2, &RxStringBuffer, 1, 10);
		HAL_UART_Receive_IT(&huart2, &RxStringBuffer, 1);

		if(RxStringBuffer == 0x31)
		{
			if(TIM2->CCR1 <= 14000){
				TIM2->CCR1 += 2000;
			}
		}
		else if(RxStringBuffer == 0x30)
		{
			if(TIM2->CCR1 >= 2005){
				TIM2->CCR1 -= 2000;
			}
		}
		RxStringBuffer = 2;
	}
}
