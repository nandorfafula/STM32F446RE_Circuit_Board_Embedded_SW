#include "LCD.h"

//Size: 5x7
char fontdata[] = {
                         0x00, 0x00, 0x00, 0x00, 0x00, // SPACE	0
                         0x00, 0x00, 0x5F, 0x00, 0x00, // !		1
                         0x00, 0x03, 0x00, 0x03, 0x00, // "		2
                         0x14, 0x3E, 0x14, 0x3E, 0x14, // #		3
                         0x24, 0x2A, 0x7F, 0x2A, 0x12, // $		4
                         0x43, 0x33, 0x08, 0x66, 0x61, // %		5
                         0x36, 0x49, 0x55, 0x22, 0x50, // &		6
                         0x00, 0x05, 0x03, 0x00, 0x00, // '		7
                         0x00, 0x1C, 0x22, 0x41, 0x00, // (		8
                         0x00, 0x41, 0x22, 0x1C, 0x00, // )		9
                         0x14, 0x08, 0x3E, 0x08, 0x14, // *		10
                         0x08, 0x08, 0x3E, 0x08, 0x08, // +		11
                         0x00, 0x50, 0x30, 0x00, 0x00, // ,		12
                         0x08, 0x08, 0x08, 0x08, 0x08, // -		13
                         0x00, 0x60, 0x60, 0x00, 0x00, // .		14
                         0x20, 0x10, 0x08, 0x04, 0x02, // /		15
                         0x3E, 0x51, 0x49, 0x45, 0x3E, // 0		16
                         0x00, 0x04, 0x02, 0x7F, 0x00, // 1		17
                         0x42, 0x61, 0x51, 0x49, 0x46, // 2		18
                         0x22, 0x41, 0x49, 0x49, 0x36, // 3		19
                         0x18, 0x14, 0x12, 0x7F, 0x10, // 4		20
                         0x27, 0x45, 0x45, 0x45, 0x39, // 5		21
                         0x3E, 0x49, 0x49, 0x49, 0x32, // 6		22
                         0x01, 0x01, 0x71, 0x09, 0x07, // 7		23
                         0x36, 0x49, 0x49, 0x49, 0x36, // 8		24
                         0x26, 0x49, 0x49, 0x49, 0x3E, // 9		25
                         0x00, 0x36, 0x36, 0x00, 0x00, // :		26
                         0x00, 0x56, 0x36, 0x00, 0x00, // ;		27
                         0x08, 0x14, 0x22, 0x41, 0x00, // <		28
                         0x14, 0x14, 0x14, 0x14, 0x14, // =		29
                         0x00, 0x41, 0x22, 0x14, 0x08, // >		30
                         0x02, 0x01, 0x51, 0x09, 0x06, // ?		31
                         0x3E, 0x41, 0x59, 0x55, 0x5E, // @		32
                         0x7E, 0x09, 0x09, 0x09, 0x7E, // A		33
                         0x7F, 0x49, 0x49, 0x49, 0x36, // B		34
                         0x3E, 0x41, 0x41, 0x41, 0x22, // C		35
                         0x7F, 0x41, 0x41, 0x41, 0x3E, // D		36
                         0x7F, 0x49, 0x49, 0x49, 0x41, // E		37
                         0x7F, 0x09, 0x09, 0x09, 0x01, // F		38
                         0x3E, 0x41, 0x41, 0x49, 0x3A, // G		39
                         0x7F, 0x08, 0x08, 0x08, 0x7F, // H		40
                         0x00, 0x41, 0x7F, 0x41, 0x00, // I		41
                         0x30, 0x40, 0x40, 0x40, 0x3F, // J		42
                         0x7F, 0x08, 0x14, 0x22, 0x41, // K		43
                         0x7F, 0x40, 0x40, 0x40, 0x40, // L		44
                         0x7F, 0x02, 0x0C, 0x02, 0x7F, // M		45
                         0x7F, 0x02, 0x04, 0x08, 0x7F, // N		46
                         0x3E, 0x41, 0x41, 0x41, 0x3E, // O		47
                         0x7F, 0x09, 0x09, 0x09, 0x06, // P		48
                         0x1E, 0x21, 0x21, 0x21, 0x5E, // Q		49
                         0x7F, 0x09, 0x09, 0x09, 0x76, // R		50
                         0x26, 0x49, 0x49, 0x49, 0x32, // S		51
                         0x01, 0x01, 0x7F, 0x01, 0x01, // T		52
                         0x3F, 0x40, 0x40, 0x40, 0x3F, // U		53
                         0x1F, 0x20, 0x40, 0x20, 0x1F, // V		54
                         0x7F, 0x20, 0x10, 0x20, 0x7F, // W		55
                         0x41, 0x22, 0x1C, 0x22, 0x41, // X		56
                         0x07, 0x08, 0x70, 0x08, 0x07, // Y		57
                         0x61, 0x51, 0x49, 0x45, 0x43, // Z		58
                         0x00, 0x7F, 0x41, 0x00, 0x00, // [		59
                         0x02, 0x04, 0x08, 0x10, 0x20, // slash 60
                         0x00, 0x00, 0x41, 0x7F, 0x00, // ]		61
                         0x04, 0x02, 0x01, 0x02, 0x04, // ^		62
                         0x40, 0x40, 0x40, 0x40, 0x40, // _		63
                         0x00, 0x01, 0x02, 0x04, 0x00, // `		64
                         0x20, 0x54, 0x54, 0x54, 0x78, // a		65
                         0x7F, 0x44, 0x44, 0x44, 0x38, // b		66
                         0x38, 0x44, 0x44, 0x44, 0x44, // c		67
                         0x38, 0x44, 0x44, 0x44, 0x7F, // d		68
                         0x38, 0x54, 0x54, 0x54, 0x18, // e		69
                         0x04, 0x04, 0x7E, 0x05, 0x05, // f		70
                         0x08, 0x54, 0x54, 0x54, 0x3C, // g		71
                         0x7F, 0x08, 0x04, 0x04, 0x78, // h		72
                         0x00, 0x44, 0x7D, 0x40, 0x00, // i		73
                         0x20, 0x40, 0x44, 0x3D, 0x00, // j		74
                         0x7F, 0x10, 0x28, 0x44, 0x00, // k		75
                         0x00, 0x41, 0x7F, 0x40, 0x00, // l		76
                         0x7C, 0x04, 0x78, 0x04, 0x78, // m		77
                         0x7C, 0x08, 0x04, 0x04, 0x78, // n		78
                         0x38, 0x44, 0x44, 0x44, 0x38, // o		79
                         0x7C, 0x14, 0x14, 0x14, 0x08, // p		80
                         0x08, 0x14, 0x14, 0x14, 0x7C, // q		81
                         0x00, 0x7C, 0x08, 0x04, 0x04, // r		82
                         0x48, 0x54, 0x54, 0x54, 0x20, // s		83
                         0x04, 0x04, 0x3F, 0x44, 0x44, // t		84
                         0x3C, 0x40, 0x40, 0x20, 0x7C, // u		85
                         0x1C, 0x20, 0x40, 0x20, 0x1C, // v		86
                         0x3C, 0x40, 0x30, 0x40, 0x3C, // w		87
                         0x44, 0x28, 0x10, 0x28, 0x44, // x		88
                         0x0C, 0x50, 0x50, 0x50, 0x3C, // y		89
                         0x44, 0x64, 0x54, 0x4C, 0x44, // z		90
                         0x00, 0x08, 0x36, 0x41, 0x41, // {		91
                         0x00, 0x00, 0x7F, 0x00, 0x00, // |		92
                         0x41, 0x41, 0x36, 0x08, 0x00, // }		93
                         0x02, 0x01, 0x02, 0x04, 0x02, // ~		94
						 0x38, 0x54, 0x56, 0x55, 0x18, // é		95
						 0x38, 0x44, 0x46, 0x45, 0x38, // ó		96
						 0x38, 0x42, 0x41, 0x42, 0x39, // û		97
						 };

/*This function writes to the LCD display.*/
void LCD_Write(uint8_t cs_s, uint8_t d_i, uint8_t g_data)
{
	switch(cs_s)
	{
	case 1:
		HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_SET);
		break;
	}
	switch(d_i)
	{
	case 0:
		HAL_GPIO_WritePin(LCD_DI_GPIO_Port, LCD_DI_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(LCD_DI_GPIO_Port, LCD_DI_Pin, GPIO_PIN_SET);
		break;
	}

	HAL_GPIO_WritePin(LCD_DB7_GPIO_Port, LCD_DB7_Pin, g_data & 0x80);
	HAL_GPIO_WritePin(LCD_DB6_GPIO_Port, LCD_DB6_Pin, g_data & 0x40);
	HAL_GPIO_WritePin(LCD_DB5_GPIO_Port, LCD_DB5_Pin, g_data & 0x20);
	HAL_GPIO_WritePin(LCD_DB4_GPIO_Port, LCD_DB4_Pin, g_data & 0x10);
	HAL_GPIO_WritePin(LCD_DB3_GPIO_Port, LCD_DB3_Pin, g_data & 0x08);
	HAL_GPIO_WritePin(LCD_DB2_GPIO_Port, LCD_DB2_Pin, g_data & 0x04);
	HAL_GPIO_WritePin(LCD_DB1_GPIO_Port, LCD_DB1_Pin, g_data & 0x02);
	HAL_GPIO_WritePin(LCD_DB0_GPIO_Port, LCD_DB0_Pin, g_data & 0x01);

	MicrosecDelay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	MicrosecDelay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	MicrosecDelay(1);
	HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_RESET);
}

/*Clear the LCD display*/
void LCD_Clear(void)
{
	uint8_t x,y;
	for(x=0;x<8;x++)
	{
		LCD_Write(3,0,0x40);
		LCD_Write(3,0,(0xB8|x));
		for(y=0;y<64;y++){LCD_Write(3,1,0x00);}
	}
}

/*Initialize the LCD display*/
void LCD_Init(void)
{
	// Set everything into starting position
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_OE_GPIO_Port, LCD_OE_Pin, GPIO_PIN_RESET);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	TIM2->CCR1 = 16000;

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);

	MicrosecDelay(1);
	LCD_Write(3,0,0x3F);
	LCD_Write(3,0,0xC0);
	LCD_Clear();
}

/*Display the application on the LCD*/
void LCD_Draw_Bubble_Tube(float acceleration_mg[])
{
	Count_Angle(acceleration_mg);
	uint8_t x,y;
	for(x=2;x<=5;x++)
	{
		LCD_Write(3,0,0x40);
		LCD_Write(3,0,(0xB8|x));
		if(x == 2){
			for(y=0;y<64;y++){LCD_Write(3,1,0x80);}
		}
		else if(x == 3 || x == 4){
			for(y=0;y<64;y++){LCD_Write(3,1,0xFF);}
		}
		else{
			for(y=0;y<64;y++){LCD_Write(3,1,0x01);}
		}
	}

	if(angle <= 90 && angle >= -90){
		int16_t shiftBubble = 0;
		shiftBubble = (angle / degreePerPixel);
		shiftBubble = shiftBubble + 64;
		if(shiftBubble <= 56){
			for(x=3;x<=4;x++)
			{
				LCD_Write(1,0,0x40|shiftBubble);
				LCD_Write(1,0,(0xB8|x));
				for(y=0;y<8;y++){LCD_Write(1,1,0x00);}
			}
		}
		else if(shiftBubble > 64){
			if(shiftBubble>121){
				for(x=3;x<=4;x++)
				{
					LCD_Write(2,0,0x40|(shiftBubble-65));
					LCD_Write(2,0,(0xB8|x));
					for(y=0;y<1;y++){LCD_Write(2,1,0x00);}
				}
			}
			else{
				for(x=3;x<=4;x++)
				{
					LCD_Write(2,0,0x40|(shiftBubble-65));
					LCD_Write(2,0,(0xB8|x));
					for(y=0;y<8;y++){LCD_Write(2,1,0x00);}
				}
			}
		}
		else if(shiftBubble > 56 && shiftBubble <= 64){
			for(x=3;x<=4;x++)
			{
				LCD_Write(1,0,0x40|shiftBubble);
				LCD_Write(1,0,(0xB8|x));
				for(y=shiftBubble;y<64;y++){LCD_Write(1,1,0x00);}
			}
			for(x=3;x<=4;x++)
			{
				LCD_Write(2,0,0x40);
				LCD_Write(2,0,(0xB8|x));
				for(y=0;y<(8-(63-shiftBubble));y++){LCD_Write(2,1,0x00);}
			}
		}
	}
	else if(angle < -90){
		for(x=3;x<=4;x++)
		{
			LCD_Write(1,0,0x40);
			LCD_Write(1,0,(0xB8|x));
			for(y=0;y<8;y++){LCD_Write(1,1,0x00);}
		}
	}
	else if(angle > 90){
		for(x=3;x<=4;x++)
		{
			LCD_Write(2,0,0x40|56);
			LCD_Write(2,0,(0xB8|x));
			for(y=0;y<8;y++){LCD_Write(2,1,0x00);}
		}
	}
}

void LCD_Write_Char(char cPlace,char cX,char cY)
{
	char i=0;
	char chip=1;
	if(cY>=64)
	{
		chip=2;
		cY-=64;
	}
	LCD_Write(chip,0,(0x40|cY));
	LCD_Write(chip,0,(0xB8|cX));
	for (i=0;i<5;i++)
	{
	  if (cY+i >= 64)
	  {
		  chip=2;
		  LCD_Write(chip,0,(0x40|(cY+i-64)));
		  LCD_Write(chip,0,(0xB8|cX));
	  }
	  LCD_Write(chip,1,fontdata[cPlace*5+i]);
	}
}

void LCD_WriteString(const char* string,char Y, char X)
{
	char temp = 0;
	int i=0;
	while(string[i]!='\0')
	{
		temp = string[i];
		LCD_Write_Char(temp-32,X,Y+6*i);
		i++;
	}
}

void LCDWriteActualAngle(float acceleration_mg[]){
	Count_Angle(acceleration_mg);
	sprintf(angleMessage, "Angle: %f", angle);
	LCD_WriteString(angleMessage,15,0);

	//To avoid the vibration
	HAL_Delay(5);
}

/*This function creates 'us' microsec delay*/
void MicrosecDelay (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim4,0);
	HAL_TIM_Base_Start(&htim4);
	while (__HAL_TIM_GET_COUNTER(&htim4) < us){}
}

void Count_Angle(float acceleration_mg[]){
	angle = acceleration_mg[1] / (1000/90) * (-1)- 4.05;
}
