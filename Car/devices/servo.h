#ifndef SERVO_H
#define SERVO_H

#include "stm32l4xx_hal.h"
#include <stdint.h>

#define SERVO_MIN_DEGREES -90.0f
#define SERVO_MAX_DEGREES 90.0f

typedef struct
{
    /* data */
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    float degrees;
} servo_t;

void Servo_Init(servo_t *servo, TIM_HandleTypeDef *htim, uint32_t channel);
void Servo_Set_Angle(servo_t *servo, float degrees);

#endif // SERVO_H