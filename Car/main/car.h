#ifndef CAR_H
#define CAR_H

#include "radio_control.h"
#include "motor.h"
#include "servo.h"
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

void Car_Init();
void Car_Task(void *pvParameters);
void Drive(float forward, float right);
void Toggle_PWM();
void Oscillate_PWM();

#endif // CAR_H