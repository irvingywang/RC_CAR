#ifndef RADIO_CONTROL_H
#define RADIO_CONTROL_H

#include "stm32l4xx_hal.h"
#include <stdint.h>

#define HEADER_BYTE 0xAA
#define GPIO_PORT GPIOA
#define CE_PIN GPIO_PIN_11  // Chip enable, PA11
#define CSN_PIN GPIO_PIN_12 // Chip select not, PA12

typedef struct controller
{
    /*Controller data*/
    uint16_t x;
    uint16_t y;
} controller_t;

void Radio_Control_Init();
void Radio_Control_Task();

#endif // RADIO_CONTROL_H