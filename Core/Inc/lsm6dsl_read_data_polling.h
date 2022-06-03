#define SENSOR_BUS hspi1

/* Includes ------------------------------------------------------------------*/
#include "lsm6dsl_reg.h"
#include <string.h>
#include <stdio.h>

#include "stm32f4xx_hal.h"
//#include "usart.h"
//#include "gpio.h"
//#include "i2c.h"
#include "main.h"

/* Private macro -------------------------------------------------------------*/
#define TX_BUF_DIM          1000
#define    BOOT_TIME          30 //ms

extern SPI_HandleTypeDef hspi1;

extern int16_t data_raw_acceleration[3];
int16_t data_raw_angular_rate[3];
int16_t data_raw_temperature;
float acceleration_mg[3];
float angular_rate_mdps[3];
float temperature_degC;
uint8_t whoamI, rst;
uint8_t tx_buffer[TX_BUF_DIM];

extern stmdev_ctx_t dev_ctx;

void lsm6dsl_read_data_polling(void);
int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
void tx_com( uint8_t *tx_buffer, uint16_t len );
void platform_delay(uint32_t ms);
void platform_init(void);

