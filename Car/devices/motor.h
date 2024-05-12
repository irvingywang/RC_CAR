#include <stdint.h>
#include "stm32f4xx_hal.h"
#ifndef MOTOR_H
#define MOTOR_H

struct motor
{
    /* data */
    uint16_t pwm;
    float speed;
    uint8_t direction;
};

void motor_init();

#endif // MOTOR_H