// M2-port main.h shim. Lives inside MyFile/Inc on the f103-port branch.
//
// The MyFile/ sources (i2c_ex.c, mymotorbdc.c, etc.) all #include "main.h"
// expecting the F030 CubeMX-generated main.h that declared global state
// like i2c_address, i_in_value, encoder_ab_mode, plus helper prototypes
// like micros() and flash_data_write_back().
//
// In the consuming motor-spin/stm32-target-m5 project there is also an
// Inc/main.h with the project's own minimal definitions (M5_I2C_ADDR,
// LD2_PORT, LD2_PIN, Error_Handler). To avoid touching that M1 file,
// this MyFile main.h is layered ahead of it on the include path and
// provides a superset of both. M1's symbols are re-exported below.
//
// M3 will rationalize this by moving the project main.h into MyFile/
// once the M5 application code is the primary serving I2C.

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

// --- M1 project re-exports (kept in sync with stm32-target-m5/Inc/main.h) ---
void Error_Handler(void);

#define M5_I2C_ADDR 0x24
#define LD2_PORT GPIOA
#define LD2_PIN  GPIO_PIN_5

// --- M5 application-level constants ---
#define ADC_CHANNEL_NUMS                2
#define ADC_SAMPLES_NUMS                ADC_CHANNEL_NUMS * 20

// --- M5 application-level globals (defined in m5_stubs.c for M2) ---
extern uint8_t i2c_address[1];
extern float i_in_value;
extern __IO uint8_t  usAdcValue8[ADC_CHANNEL_NUMS];
extern __IO uint16_t usAdcValue16[ADC_CHANNEL_NUMS];
extern volatile uint8_t flag_jump_bootloader;
extern uint8_t encoder_ab_mode;
extern uint8_t soft_start_stop_switch;

// --- M5 helper prototypes (stubbed in m5_stubs.c for M2) ---
void i2c_address_write_to_flash(void);
void user_i2c_init(void);
void init_flash_data(void);
void flash_data_write_back(void);
uint32_t micros(void);
void set_ab_mode(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
