#ifndef __MYMOTORENCODER_H
#define __MYMOTORENCODER_H
#include "stm32f1xx_hal.h"
#include "main.h"  // M2-port: brings in encoder_ab_mode etc.

#define ENC_M1 0
#define ENC_M2 1
#define ENC_M3 2
#define ENC_M4 3

//#define INVERT_ENC_M1 0
//#define INVERT_ENC_M2 0
//#define INVERT_ENC_M3 0
//#define INVERT_ENC_M4 0


void InitMotorEncoder(void);
int32_t GetEncoderPos(uint8_t port);
void SetEncoderPos(uint8_t port,int32_t pos);
void ResetEncoderPos(uint8_t port);
void InterruptMotorEncoder(void);

#endif
