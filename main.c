#include <avr/io.h>
#include <avr/interrupt.h>
#include "lib/dcmotor.h"
#include "lib/debug.h"

int main(void)
{
    DcMotor motor1, motor2;

    // motor1{
    //     .pDdrA = &DDRC,
    //     .pDdrB = &DDRC,
    //     .pPortA = &PORTC,
    //     .pPortB = &PORTC,
    //     .pinA = PC0,
    //     .pinB = PC1,
    //     .pDdrLimitA = &DDRC,
    //     .pPortLimitA = &PORTC,
    //     .pPinLimitA = &PINC,
    //     .limitA = PC2,
    // };

    // motor2{
    //     .pDdrA = &DDRC,
    //     .pDdrB = &DDRC,
    //     .pPortA = &PORTC,
    //     .pPortB = &PORTC,
    //     .pinA = PC0,
    //     .pinB = PC1,
    //     .pDdrLimitA = &DDRC,
    //     .pPortLimitA = &PORTC,
    //     .pPinLimitA = &PINC,
    //     .limitA = PC2,
    // };

    // dcmotor_init(motor1);
    // dcmotor_init(motor2);

    while (1)
    {

    }
}
