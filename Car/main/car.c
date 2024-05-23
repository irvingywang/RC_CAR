#include "car.h"

motor_t motor1;
extern TIM_HandleTypeDef htim2;

void car_init()
{
    // Initialize the car
    radio_control_init();

    motor_init(&motor1, &htim2, TIM_CHANNEL_1);

    // Create FreeRTOS task
    xTaskCreate(Car_Task, "Car_Task", 128, &motor1, 1, NULL);
}

void Car_Task(void *pvParameters)
{
    motor_t *motor = (motor_t *)pvParameters;

    while (1)
    {
        // TODO read controller data

        // set motor output
        // motor_set_output(motor, 0.5f);

        // testing pwm with led
        static uint8_t motor_on = 0; // 0: off, 1: on
        motor_on ^= 1;
        if (motor_on)
        {
            motor_set_output(motor, 1.0f);
        }
        else
        {
            motor_set_output(motor, 0.0f);
        }

        vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 second
    }
}