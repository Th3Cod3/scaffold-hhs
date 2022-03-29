#include <avr/io.h>
#include "encoder.h"

uint8_t encoder_read(Encoder encoder)
{
    static uint8_t lastState = 0;
    uint8_t state = bit_is_set(encoder.portA, encoder.pinA);
    uint8_t isTrigger = lastState != state;
    lastState = state;

    return isTrigger;
}

/*
 * init a single pulse encoder
 */
void encoder_init(Encoder encoder)
{
    *encoder.ddrA |= _BV(encoder.pinA);     // INPUT
    *encoder.portA |= _BV(encoder.pinLimit); // PULLUP
}
