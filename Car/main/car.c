#include "car.h"

extern TIM_HandleTypeDef htim1, htim2;

extern controller_t controller_g;
motor_t motor;
servo_t steering;

void Car_Init()
{
    // Initialize the car
    Radio_Control_Init();

    Motor_Init(&motor, &htim1, TIM_CHANNEL_1);

    Servo_Init(&steering, &htim2, TIM_CHANNEL_1);

    // Create FreeRTOS task
    // xTaskCreate(Radio_Control_Task, "Radio_Control_Task", 128, NULL, 1, NULL);
    xTaskCreate(Car_Task, "Car_Task", 128, NULL, 1, NULL);
}

void Car_Task(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        // TODO read controller data

        // set motor output
        // Drive(controller_g.x, controller_g.y); not floats yet
        // Motor_Set_Output(&motor, 0.0f);
        // Oscillate_PWM();
        Toggle_PWM();

        vTaskDelay(pdMS_TO_TICKS(3000)); // delay in ms
    }
}

void Drive(float forward, float right)
{
    Motor_Set_Output(&motor, forward);
    Servo_Set_Angle(&steering, right);
}

void Toggle_PWM()
{
    // testing pwm with led
    static uint8_t motor_on = 0;
    motor_on ^= 1;
    if (motor_on)
    {
        Motor_Set_Output(&motor, 1.0f);

        Servo_Set_Angle(&steering, 135.0f);
    }
    else
    {
        Motor_Set_Output(&motor, 0.0f);
        Servo_Set_Angle(&steering, 0.0f);
    }
}

void Oscillate_PWM()
{
    static uint8_t increasing = 1;
    static float pwm_value = 0.0f;
    static float ramp_coeff = 0.05f;
    while (1)
    {
        if (increasing)
        {
            pwm_value += (1.0f - pwm_value) * ramp_coeff;
            if (pwm_value >= 0.99f)
            {
                pwm_value = 1.0f;
                increasing = 0;
            }
        }
        else
        {
            pwm_value -= pwm_value * ramp_coeff;
            if (pwm_value <= 0.1f)
            {
                pwm_value = 0.0f;
                increasing = 1;
            }
        }

        Motor_Set_Output(&motor, pwm_value);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
