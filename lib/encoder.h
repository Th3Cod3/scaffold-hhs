#ifndef ENCODER_H
#define ENCODER_H

#include <inttypes.h>
#include "basicio.h"

#define ENCODER_STATE_UNKNOWN 0
#define ENCODER_STATE_NONE 1
#define ENCODER_STATE_HIGH 2
#define ENCODER_STATE_LOW 3

typedef struct
{
    unsigned long counter;
    volatile uint8_t *pPcmsk;
    uint8_t pcmsk;
    uint8_t pcie;
    uint8_t pcif;
    uint8_t state;
    uint8_t lastState;
    Input encoder;
} EncoderInterrupt;

void encoder_count(EncoderInterrupt encoder, uint8_t direction);

void encoder_init(EncoderInterrupt encoder);

#endif