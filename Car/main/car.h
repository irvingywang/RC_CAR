#ifndef CAR_H
#define CAR_H

#include "radio_control.h"
#include "motor.h"
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

void car_init();
void Car_Task(void *pvParameters);

#endif // CAR_H