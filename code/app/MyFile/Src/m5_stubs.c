// M2-port stubs: every symbol that M5's MyFile/ sources reference but
// that historically lived in CubeMX-generated files (main.c, tim.c,
// adc.c, dma.c, gpio.c, i2c.c) under code/app/Src/ on the F030 build.
//
// For M2 we only need these to satisfy the linker — none of the M5
// MyFile entry points are actually called from main yet (the M1
// register-table slave is still serving I2C). M3 will replace this
// file with real F103-targeted peripheral init and bring MyFile online.

#include "main.h"          // brings in stm32f1xx_hal.h via project Inc/main.h
#include "tim.h"
#include "adc.h"
#include "dma.h"
#include "i2c_ex.h"
#include <stdint.h>

// --- peripheral handles ---
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
ADC_HandleTypeDef hadc;

// --- M5 global state expected by MyFile sources ---
// These mirror the definitions in code/app/Src/main.c on the F030 firmware.
uint8_t i2c_address[1] = { 0x24 };
float i_in_value = 0.0f;
__IO uint8_t  usAdcValue8[ADC_CHANNEL_NUMS]  = { 0 };
__IO uint16_t usAdcValue16[ADC_CHANNEL_NUMS] = { 0 };
volatile uint8_t flag_jump_bootloader = 0;
uint8_t encoder_ab_mode = 0;
uint8_t soft_start_stop_switch = 0;

// --- MX_*_Init stubs (no-op; real init in M3) ---
void MX_TIM1_Init(void)  { /* M2 stub */ }
void MX_TIM3_Init(void)  { /* M2 stub */ }
void MX_ADC_Init(void)   { /* M2 stub */ }
void MX_DMA_Init(void)   { /* M2 stub */ }

// --- helpers expected by MyFile ---

// micros() — microsecond timer used by mymotorbdc.c's ramp logic. The
// F030 firmware drove this off TIM14; for M2 we just scale HAL_GetTick
// to keep the math compiling. Not accurate to a microsecond, but no
// caller is exercised in M2.
uint32_t micros(void)
{
    return HAL_GetTick() * 1000U;
}

// set_ab_mode() — on F030 this reconfigured the EXTI edge polarity
// for the encoder pins after encoder_ab_mode toggled. M2 has no
// encoder wiring yet, so this is a no-op.
void set_ab_mode(void) { /* M2 stub */ }

// user_i2c_init() — F030 wrapper that re-runs MX_I2C2_Init() with the
// (possibly flash-loaded) i2c_address. M2 leaves the M1 slave init
// alone; if a caller hits this it just rebinds the existing handle.
void user_i2c_init(void) { /* M2 stub */ }

// flash_data_write_back() — F030 used this to persist i2c_address /
// encoder_ab_mode / soft_start_stop_switch to the EEPROM-emulation
// region. flash.c is stubbed for M2, so this is also a no-op.
void flash_data_write_back(void) { /* M2 stub */ }

// init_flash_data() — F030 boot-time loader from flash. M2: noop.
void init_flash_data(void) { /* M2 stub */ }

// i2c_address_write_to_flash() — same story as flash_data_write_back.
void i2c_address_write_to_flash(void) { /* M2 stub */ }

// i2c2_set_send_data — declared in code/app/Inc/i2c.h on the F030
// firmware; defined in i2c_ex.c. Both a forward decl in main.h's
// extern style and the i2c_ex.c definition exist already, so we
// don't need to re-define it here. This stub file intentionally
// avoids touching the I2C callback path.
