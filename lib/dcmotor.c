/*
dcmotor lib 0x01

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.

Modify by Yefri Gonzalez (Th3Cod3)
*/

#include <avr/io.h>
#include "dcmotor.h"

void dcmotor_instruction(DcMotor motor, char instruction)
{
    if (dcmotor_end_limit(motor) && instruction != DCMOTOR_STOP){
        return dcmotor_instruction(motor, DCMOTOR_STOP);
    }

    switch (instruction)
    {
    case DCMOTOR_FORWARD:
        *motor.pPortA |= _BV(motor.pinA);
        *motor.pPortB &= ~_BV(motor.pinB);
        return;

    case DCMOTOR_BACKWARD:
        *motor.pPortA &= ~_BV(motor.pinA);
        *motor.pPortB |= _BV(motor.pinB);
        return;

    case DCMOTOR_STOP:
        *motor.pPortA &= ~_BV(motor.pinA);
        *motor.pPortB &= ~_BV(motor.pinB);
        return;
    }
}

/*
 * init a motor
 */
void dcmotor_init(DcMotor motor)
{
    *motor.pDdrA |= _BV(motor.pinA);         // OUTPUT
    *motor.pDdrB |= _BV(motor.pinB);         // OUTPUT
    *motor.pDdrLimitA &= ~_BV(motor.limitA); // INPUT
    *motor.pPortLimitA |= _BV(motor.limitA); // PULLUP
    dcmotor_instruction(motor, DCMOTOR_STOP);
}

uint8_t dcmotor_end_limit(DcMotor motor)
{
    return !(*motor.pPinLimitA & _BV(motor.limitA));
}
