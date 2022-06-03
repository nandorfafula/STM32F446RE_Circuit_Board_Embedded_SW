#include "BTN.h"

void BTNControl(void)
{
	BTN1_State = !(HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin));
	if(BTN1_State && !BTN1_PrevState){
		HAL_Delay(2);
		if(BTN1_State){
			if(TIM2->CCR1 >= 2005){
				TIM2->CCR1 -= 2000;
			}
		}
		BTN1_PrevState = 1u;
	}
	if(!BTN1_State){
		BTN1_PrevState = 0u;
	}

	BTN2_State = !(HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin));
	if(BTN2_State && !BTN2_PrevState){
		HAL_Delay(2);
		if(BTN2_State){
			if(TIM2->CCR1 <= 14000){
				TIM2->CCR1 += 2000;
			}
		}
		BTN2_PrevState = 1u;
	}
	if(!BTN2_State){
		BTN2_PrevState = 0u;
	}
}
