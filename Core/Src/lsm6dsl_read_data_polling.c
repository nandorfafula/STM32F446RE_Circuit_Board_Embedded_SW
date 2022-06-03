#include "lsm6dsl_read_data_polling.h"

/* Private variables ---------------------------------------------------------*/
int16_t data_raw_acceleration[3];
int16_t data_raw_angular_rate[3];
int16_t data_raw_temperature;
float acceleration_mg[3];
float angular_rate_mdps[3];
float temperature_degC;
uint8_t whoamI, rst;
uint8_t tx_buffer[TX_BUF_DIM];
stmdev_ctx_t dev_ctx;
/* Extern variables ----------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/*
 *   WARNING:
 *   Functions declare in this section are defined at the end of this file
 *   and are strictly related to the hardware platform used.
 *
 */

void lsm6dsl_init(void)
{
/* Initialize mems driver interface */
  dev_ctx.write_reg = platform_write;
  dev_ctx.read_reg = platform_read;
  dev_ctx.handle = &SENSOR_BUS;
  /* Init test platform */
  platform_init();
  /* Wait sensor boot time */
  platform_delay(BOOT_TIME);
  /* Check device ID */
  whoamI = 0;
  lsm6dsl_device_id_get(&dev_ctx, &whoamI);

  if ( whoamI != LSM6DSL_ID )
	while (1); /*manage here device not found */

  /* Restore default configuration */
  lsm6dsl_reset_set(&dev_ctx, PROPERTY_ENABLE);

  do {
	lsm6dsl_reset_get(&dev_ctx, &rst);
  } while (rst);

  /* Enable Block Data Update */
  lsm6dsl_block_data_update_set(&dev_ctx, PROPERTY_ENABLE);
  /* Set Output Data Rate */
  lsm6dsl_xl_data_rate_set(&dev_ctx, LSM6DSL_XL_ODR_104Hz);
  lsm6dsl_gy_data_rate_set(&dev_ctx, LSM6DSL_GY_ODR_104Hz);
  /* Set full scale */
  lsm6dsl_xl_full_scale_set(&dev_ctx, LSM6DSL_2g);
  lsm6dsl_gy_full_scale_set(&dev_ctx, LSM6DSL_2000dps);
  /* Configure filtering chain(No aux interface) */
  /* Accelerometer - analog filter */
  lsm6dsl_xl_filter_analog_set(&dev_ctx, LSM6DSL_XL_ANA_BW_400Hz);
  /* Accelerometer - LPF1 path ( LPF2 not used )*/
  //lsm6dsl_xl_lp1_bandwidth_set(&dev_ctx, LSM6DSL_XL_LP1_ODR_DIV_4);
  /* Accelerometer - LPF1 + LPF2 path */
  lsm6dsl_xl_lp2_bandwidth_set(&dev_ctx, LSM6DSL_XL_LOW_NOISE_LP_ODR_DIV_100);
  /* Accelerometer - High Pass / Slope path */
  //lsm6dsl_xl_reference_mode_set(&dev_ctx, PROPERTY_DISABLE);
  //lsm6dsl_xl_hp_bandwidth_set(&dev_ctx, LSM6DSL_XL_HP_ODR_DIV_100);
  /* Gyroscope - filtering chain */
  lsm6dsl_gy_band_pass_set(&dev_ctx, LSM6DSL_HP_65mHz_LP1_NORMAL);
}

/* Main Example --------------------------------------------------------------*/
void lsm6dsl_read_data_polling(void)
{
  /* Read samples in polling mode (no int) */
    /* Read output only if new value is available */
    lsm6dsl_reg_t reg;
    lsm6dsl_status_reg_get(&dev_ctx, &reg.status_reg);

    if (reg.status_reg.xlda) {
      /* Read magnetic field data */
      memset(data_raw_acceleration, 0x00, 3 * sizeof(int16_t));
      lsm6dsl_acceleration_raw_get(&dev_ctx, data_raw_acceleration);
      acceleration_mg[0] = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration[0]);
      acceleration_mg[1] = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration[1]);
      acceleration_mg[2] = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration[2]);
//      sprintf((char *)tx_buffer,
//              "Acceleration [mg]:%4.2f\t%4.2f\t%4.2f\r\n",
//              acceleration_mg[0], acceleration_mg[1], acceleration_mg[2]);
//      tx_com( tx_buffer, strlen( (char const *)tx_buffer ) );
    }

    if (reg.status_reg.gda) {
      /* Read magnetic field data */
      memset(data_raw_angular_rate, 0x00, 3 * sizeof(int16_t));
      lsm6dsl_angular_rate_raw_get(&dev_ctx, data_raw_angular_rate);
      angular_rate_mdps[0] = lsm6dsl_from_fs2000dps_to_mdps(data_raw_angular_rate[0]);
      angular_rate_mdps[1] = lsm6dsl_from_fs2000dps_to_mdps(data_raw_angular_rate[1]);
      angular_rate_mdps[2] = lsm6dsl_from_fs2000dps_to_mdps(data_raw_angular_rate[2]);
//      sprintf((char *)tx_buffer,
//              "Angular rate [mdps]:%4.2f\t%4.2f\t%4.2f\r\n",
//              angular_rate_mdps[0], angular_rate_mdps[1], angular_rate_mdps[2]);
//      tx_com( tx_buffer, strlen( (char const *)tx_buffer ) );
    }

    if (reg.status_reg.tda) {
      /* Read temperature data */
      memset(&data_raw_temperature, 0x00, sizeof(int16_t));
      lsm6dsl_temperature_raw_get(&dev_ctx, &data_raw_temperature);
      temperature_degC = lsm6dsl_from_lsb_to_celsius(
                           data_raw_temperature );
      sprintf((char *)tx_buffer, "Temperature [degC]:%6.2f\r\n",
              temperature_degC );
      tx_com( tx_buffer, strlen( (char const *)tx_buffer ) );
    }
}


/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len)
{
  HAL_GPIO_WritePin(MKI178_CS_GPIO_Port, MKI178_CS_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, &reg, 1, 1000);
  HAL_SPI_Transmit(&hspi1, (uint8_t*) bufp, len, 1000);
  HAL_GPIO_WritePin(MKI178_CS_GPIO_Port, MKI178_CS_Pin, GPIO_PIN_SET);
  return 0;
}

/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
  reg |= 0x80;
  HAL_GPIO_WritePin(MKI178_CS_GPIO_Port, MKI178_CS_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, &reg, 1, 1000);
  HAL_SPI_Receive(&hspi1, bufp, len, 1000);
  HAL_GPIO_WritePin(MKI178_CS_GPIO_Port, MKI178_CS_Pin, GPIO_PIN_SET);
  return 0;
}

/*
 * @brief  Send buffer to console (platform dependent)
 *
 * @param  tx_buffer     buffer to transmit
 * @param  len           number of byte to send
 *
 */
void tx_com(uint8_t *tx_buffer, uint16_t len)
{
//  HAL_UART_Transmit(&huart2, tx_buffer, len, 1000);
}

/*
 * @brief  platform specific delay (platform dependent)
 *
 * @param  ms        delay in ms
 *
 */
void platform_delay(uint32_t ms)
{
  HAL_Delay(ms);
}

/*
 * @brief  platform specific initialization (platform dependent)
 */
void platform_init(void)
{
}
