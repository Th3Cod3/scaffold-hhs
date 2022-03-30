#ifndef INPUTS_H
#define INPUTS_H

#include <inttypes.h>

#define LED_TYPE_GROUND 0
#define LED_TYPE_VCC 1

#define LED_LOW 0
#define LED_HIGH 1

typedef struct
{
    volatile uint8_t *pDdr;
    volatile uint8_t *pPort;
    uint8_t pin;
    uint8_t type;
} Led;

void input_ledMode(Led led, uint8_t mode);

#endif
