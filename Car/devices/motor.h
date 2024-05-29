#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

typedef struct
{
    /* data */
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    float output; // 0 to 1
    uint8_t direction;
} motor_t;

void Motor_Init(motor_t *motor, TIM_HandleTypeDef *htim, uint32_t channel);
void Motor_Set_Output(motor_t *motor, float output);
void Arm_ESC_Task(void *pvParameters);

#endif // MOTOR_H