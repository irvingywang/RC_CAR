#include "controller.h"
// UART Rx
controller_t controller_g;


void controller_init()
{
    // Initialize controller
    controller_g.x = 0;
    controller_g.y = 0;
}

void controller_read()
{
    // Read controller from UART RX
}


