#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <inttypes.h>

#define DCMOTOR_STOP 0
#define DCMOTOR_FORWARD 1
#define DCMOTOR_BACKWARD 2

typedef struct
{
    volatile uint8_t *pDdrA;
    volatile uint8_t *pDdrB;
    volatile uint8_t *pPortA;
    volatile uint8_t *pPortB;
    uint8_t pinA;
    uint8_t pinB;
    volatile uint8_t *pDdrLimitA;
    volatile uint8_t *pPortLimitA;
    volatile uint8_t *pPinLimitA;
    uint8_t limitA;
} DcMotor;

extern void dcmotor_instruction(DcMotor motor, char instruction);
extern uint8_t dcmotor_end_limit(DcMotor motor);
extern void dcmotor_init(DcMotor motor);

#endif
