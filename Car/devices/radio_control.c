#include "radio_control.h"

controller_t controller_g;
GPIO_InitTypeDef GPIO_InitStruct = {0};

void radio_control_init()
{
    // Initialize controller
    controller_g.x = 0;
    controller_g.y = 0;

    //__HAL_RCC_GPIOB_CLK_ENABLE();

    // Init CE and CSN pins
    GPIO_InitStruct.Pin = CE_PIN | CSN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // TODO Check if these are correct
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    // HAL_GPIO_Init(GPIOB, &GPIO_InitStruct); // TODO GPIOB not defined?
}

void read_packet()
{
    // Read controller from UART RX
    // Update controller_g
}

void radio_control_loop()
{
    // Loop the radio control
    read_packet();
}
