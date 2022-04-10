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
} Led;

typedef struct
{
    volatile uint8_t *pDdr;
    volatile uint8_t *pPin;
    volatile uint8_t *pPort;
    uint8_t pin;
    uint8_t type;
} Button;

void input_ledMode(Led led, uint8_t mode);
void input_initLed(Led led);
void input_initButton(Button button);
uint8_t input_readButton(Button button);

#endif
