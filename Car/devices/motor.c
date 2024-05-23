#include "motor.h"

void Motor_Init(motor_t *motor, TIM_HandleTypeDef *htim, uint32_t channel)
{
    // Initialize the motor
    motor->htim = htim;
    motor->channel = channel;
    motor->output = 0;
    motor->direction = 0; // not used for now

    // Start PWM
    HAL_TIM_PWM_Start(htim, channel);
}

void Motor_Set_Output(motor_t *motor, float output) // output is 0 to 1
{
    // Check range
    if (output > 1.0f)
    {
        output = 1.0f;
    }

    if (output < 0.0f)
    {
        output = 0.0f;
    }

    motor->output = output;

    // Set the duty cycle
    uint32_t dutyCycle = (uint32_t)(output * motor->htim->Init.Period);
    __HAL_TIM_SET_COMPARE(motor->htim, motor->channel, dutyCycle);
}
