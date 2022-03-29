#ifndef ENCODER_H
#define ENCODER_H

#include <inttypes.h>

#define ENCODER_STATE_UNKNOWN 0
#define ENCODER_STATE_NONE 1
#define ENCODER_STATE_HIGH 2
#define ENCODER_STATE_LOW 3

typedef struct
{
    volatile uint8_t *pDdrA;
    volatile uint8_t *pPortA;
    volatile uint8_t *pPinA;
    uint8_t pinA;
} Encoder;

uint8_t encoder_read(Encoder encoder);

void encoder_init(Encoder encoder);

#endif
