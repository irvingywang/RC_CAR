#ifndef MOTOR_H
#define MOTOR_H

struct motor
{
    /* data */
    float speed;
    //uint8_t direction;
};

void motor_init();

#endif // MOTOR_H