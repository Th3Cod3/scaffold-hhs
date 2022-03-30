#include <avr/io.h>
#include "encoder.h"

uint8_t encoder_read(Encoder encoder)
{
    static uint8_t lastState = 0;
    uint8_t state = bit_is_set(encoder.pPortA, encoder.pinA);
    uint8_t isTrigger = lastState != state;
    lastState = state;

    return isTrigger;
}

/*
 * init a single pulse encoder
 */
void encoder_init(Encoder encoder)
{
    *encoder.pDdrA |= _BV(encoder.pinA);     // INPUT
}
