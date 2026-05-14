// M2-port stub: see tim.h for context. The original F030 firmware used
// the ADC in DMA mode for current sense; on F103 we punt for now.
#ifndef __ADC_H_M5_PORT
#define __ADC_H_M5_PORT

#include "stm32f1xx_hal.h"

extern ADC_HandleTypeDef hadc;

void MX_ADC_Init(void);

#endif
