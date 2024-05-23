#include "car.h"

extern TIM_HandleTypeDef htim2;

extern controller_t controller_g;
motor_t front_left, back_left, front_right, back_right;

void Car_Init()
{
    // Initialize the car
    Radio_Control_Init();

    Motor_Init(&front_left, &htim2, TIM_CHANNEL_1);
    Motor_Init(&back_left, &htim2, TIM_CHANNEL_2);
    Motor_Init(&front_right, &htim2, TIM_CHANNEL_3);
    Motor_Init(&back_right, &htim2, TIM_CHANNEL_4);

    // Create FreeRTOS task
    xTaskCreate(Radio_Control_Task, "Radio_Control_Task", 128, NULL, 1, NULL);
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
        Toggle_PWM();

        vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 second
    }
}

void Drive(float forward, float right)
{
    // Calculate motor output
    float front_left_output = forward + right;
    float back_left_output = forward - right;
    float front_right_output = forward - right;
    float back_right_output = forward + right;

    // Set motor output
    Motor_Set_Output(&front_left, front_left_output);
    Motor_Set_Output(&back_left, back_left_output);
    Motor_Set_Output(&front_right, front_right_output);
    Motor_Set_Output(&back_right, back_right_output);
}

void Toggle_PWM()
{
    // testing pwm with led
    static uint8_t motor_on = 0;
    motor_on ^= 1;
    if (motor_on)
    {
        Motor_Set_Output(&front_left, 1.0f);
        Motor_Set_Output(&back_left, 1.0f);
        Motor_Set_Output(&front_right, 1.0f);
        Motor_Set_Output(&back_right, 1.0f);
    }
    else
    {
        Motor_Set_Output(&front_left, 0.0f);
        Motor_Set_Output(&back_left, 0.0f);
        Motor_Set_Output(&front_right, 0.0f);
        Motor_Set_Output(&back_right, 0.0f);
    }
}