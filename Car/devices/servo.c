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

void Servo_Set_Angle(servo_t *servo, float degrees) // degrees is -90 to 90
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

    //
}
