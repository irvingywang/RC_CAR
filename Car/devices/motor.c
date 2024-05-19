#include "motor.h"

void motor_init()
{
    // Initialize motor

    GPIO_InitTypeDef GPIO_InitStruct = {0};
}

void motor_set_pwm(motor_t *motor, uint16_t pwm)
{
    // Set the PWM of the motor
    motor->pwm = pwm;
}