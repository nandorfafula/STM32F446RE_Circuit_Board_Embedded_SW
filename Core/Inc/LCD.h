#include "main.h"

char fontdata[];

void LCD_Clear(void);
void LCD_Draw_Bubble_Tube(float acceleration_mg[]);
void LCD_Init(void);
void LCD_Write(uint8_t cs_s, uint8_t d_i, uint8_t g_data);
void LCD_Write_Char(char cPlace,char cX,char cY);
void LCD_WriteString(const char* string,char Y, char X);
void LCDWriteActualAngle(float acceleration_mg[]);
void MicrosecDelay (uint16_t us);
void Count_Angle(float acceleration_mg[]);
