#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "motor.h"

typedef struct
{
    motor_t left_motor;
    motor_t right_motor;
} drivetrain_t;

typedef struct
{
    float speed;
    float theta;
} kinematics_t;

void drivetrain_init();
void drivetrain_loop();

#endif // DRIVETRAIN_H