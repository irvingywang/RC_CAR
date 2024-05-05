#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "motor.h"

struct drivetrain
{
    struct motor left_motor;
    struct motor right_motor;
};

void drivetrain_init();

#endif // DRIVETRAIN_H