#include "servo.h"

void Servo_Init(servo_t *servo, TIM_HandleTypeDef *htim, uint32_t channel)
{
    // Initialize the servo
    servo->htim = htim;
    servo->channel = channel;
    servo->degrees = 0;

    // Start PWM
    HAL_TIM_PWM_Start(htim, channel);
}

void Servo_Set_Angle(servo_t *servo, float degrees) // degrees is -135 to 135
{
    // Check range
    if (degrees > SERVO_MAX_DEGREES)
    {
        degrees = SERVO_MAX_DEGREES;
    }

    if (degrees < SERVO_MIN_DEGREES)
    {
        degrees = SERVO_MIN_DEGREES;
    }

    servo->degrees = degrees;

    // Map -135 to 135 to 0 to 270
    float mapped_degrees = degrees + 135.0f;

    // Convert degrees to pulse width
    uint32_t pulse = (uint32_t)(SERVO_MIN_PULSE + (mapped_degrees / 270.0f) * (SERVO_MAX_PULSE - SERVO_MIN_PULSE));

    // Set the duty cycle
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, pulse);
}
