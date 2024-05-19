#include "drivetrain.h"

kinematics_t kinematics_g;
drivetrain_t drivetrain_g;

void drivetrain_init()
{
    // Initialize the drivetrain
}

void drivetrain_loop()
{
    // Loop the drivetrain
    drivetrain_g.left_motor.speed = kinematics_g.speed;
    drivetrain_g.right_motor.speed = kinematics_g.speed;
}