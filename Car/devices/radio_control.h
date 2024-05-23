#ifndef RADIO_CONTROL_H
#define RADIO_CONTROL_H

#include "stm32f4xx_hal.h"
#include <stdint.h>
#define HEADER_BYTE 0xAA
#define CE_PIN GPIO_PIN_0  // Chip enable, PB0
#define CSN_PIN GPIO_PIN_1 // Chip select not, PB1

typedef struct controller
{
    /*Controller data*/
    uint16_t x;
    uint16_t y;
} controller_t;

void radio_control_init();
void read_packet();

#endif // RADIO_CONTROL_H