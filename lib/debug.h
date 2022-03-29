#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_EN
#include <util/delay.h>
#define DEBUG_PIN PORTB7
#define DEBUG_SIGNAL(delay)  \
    DDRB |= _BV(DEBUG_PIN);  \
    PORTB ^= _BV(DEBUG_PIN); \
    _delay_us((int)(delay)); \
    PORTB ^= _BV(DEBUG_PIN);
#else
#define DEBUG_SIGNAL(delay)
#endif

#endif