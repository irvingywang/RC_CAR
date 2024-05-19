#include <stdint.h>
#include "stm32f4xx_hal.h"
#ifndef MOTOR_H
#define MOTOR_H
typedef struct
{
    /* data */
    float speed;
    uint8_t direction;
    uint16_t pwm;
} motor_t;

void motor_init();
void motor_set_pwm(motor_t *motor, uint16_t pwm);

#endif // MOTOR_H