#ifndef BASICIO_H
#define BASICIO_H

#include <inttypes.h>

#define LED_TYPE_GROUND 0
#define LED_TYPE_VCC 1

#define BUTTON_TYPE_PULLDOWN 0
#define BUTTON_TYPE_PULLUP 1

#define LED_LOW 0
#define LED_HIGH 1

typedef struct
{
    volatile uint8_t *pDdr;
    volatile uint8_t *pPort;
    uint8_t pin;
    uint8_t type;
} Output;

typedef struct
{
    volatile uint8_t *pDdr;
    volatile uint8_t *pPin;
    volatile uint8_t *pPort;
    uint8_t pin;
    uint8_t type;
} Input;

void basic_ledMode(Output led, uint8_t mode);
void basic_initLed(Output led);
void basic_initButton(Input button);
uint8_t basic_readButton(Input button);

#endif
