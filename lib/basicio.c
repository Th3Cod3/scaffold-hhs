#include <avr/io.h>
#include "basicio.h"

void basic_ledMode(Output led, uint8_t mode)
{
    if (mode == LED_HIGH && led.type == LED_TYPE_GROUND) {
        *led.pPort |= _BV(led.pin);
    } else if (mode == LED_HIGH && led.type == LED_TYPE_VCC) {
        *led.pPort &= ~_BV(led.pin);
    } else if (mode == LED_LOW && led.type == LED_TYPE_GROUND) {
        *led.pPort &= ~_BV(led.pin);
    } else if (mode == LED_LOW && led.type == LED_TYPE_VCC) {
        *led.pPort |= _BV(led.pin);
    }
}

void basic_initLed(Output led)
{
    *led.pDdr |= _BV(led.pin); // INPUT
}

void basic_initButton(Input button) {
    *button.pDdr &= ~_BV(button.pin); // INPUT

    if (button.type == BUTTON_TYPE_PULLUP) {
        *button.pPort |= _BV(button.pin); // PULLUP
    } else if (button.type == BUTTON_TYPE_PULLDOWN) {
        *button.pPort &= ~_BV(button.pin); // PULLDOWN
    }
}

uint8_t basic_readButton(Input button) {
    if (button.type == BUTTON_TYPE_PULLUP) {
        return !(*button.pPin & _BV(button.pin));
    }

    return (*button.pPin & _BV(button.pin));
}
