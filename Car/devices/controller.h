#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

typedef struct controller {
    /*Controller data*/
    uint16_t x;
    uint16_t y;
} controller_t;

void controller_init();
void controller_read();


#endif // CONTROLLER_H