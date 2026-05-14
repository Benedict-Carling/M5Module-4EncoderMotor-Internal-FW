// M2-port stub: peripheral handle declarations for the M5 MyFile sources.
// On the original F030 firmware these came from CubeMX-generated tim.h /
// tim.c. For M2 we just declare the externs so MyFile compiles; the
// actual handle definitions and MX_*_Init functions live in m5_stubs.c.
//
// This file lives inside MyFile/Inc on the f103-port branch; it is NOT
// intended to override any equivalently-named header in the consuming
// project. M5+ milestones may replace it with a real CubeMX-style wrapper.
#ifndef __TIM_H_M5_PORT
#define __TIM_H_M5_PORT

#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void MX_TIM1_Init(void);
void MX_TIM3_Init(void);

#endif
