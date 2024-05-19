#include "car.h"
#include "drivetrain.h"
#include "radio_control.h"

void car_init()
{
    // Initialize the car
    drivetrain_init();
    radio_control_init();
}

void car_loop()
{
    // Loop the car
    drivetrain_loop();
    radio_control_loop();
}
