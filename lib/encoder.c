#include <avr/io.h>
#include <avr/interrupt.h>
#include "encoder.h"
#include "dcmotor.h"

void encoder_count(EncoderInterrupt encoder, uint8_t direction)
{
    encoder.state = basic_readButton(encoder.encoder)
                        ? ENCODER_STATE_HIGH
                        : ENCODER_STATE_LOW;

    if (encoder.lastState != encoder.state && encoder.state == ENCODER_STATE_HIGH)
    {
        if (direction == DCMOTOR_FORWARD)
        {
            encoder.counter++;
        }
        else if (direction == DCMOTOR_FORWARD)
        {
            encoder.counter--;
        }
    }

    encoder.lastState = encoder.state;
}

/*
 * init a single pulse encoder
 */
void encoder_init(EncoderInterrupt encoder)
{
    basic_initButton(encoder.encoder);
    *encoder.pPcmsk |= _BV(encoder.pcmsk);
    PCICR |= _BV(encoder.pcie);
    PCIFR |= _BV(encoder.pcif);
    sei();
}
