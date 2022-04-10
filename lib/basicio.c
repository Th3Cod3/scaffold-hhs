#include <avr/io.h>
#include "basicio.h"

void input_ledMode(Led led, uint8_t mode)
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

void input_initLed(Led led)
{
    *led.pDdr |= _BV(led.pin); // INPUT
}

void input_initButton(Button button) {
    *button.pDdr &= ~_BV(button.pin); // INPUT

    if (button.type == BUTTON_TYPE_PULLUP) {
        *button.pPort |= _BV(button.pin); // PULLUP
    } else if (button.type == BUTTON_TYPE_PULLDOWN) {
        *button.pPort &= ~_BV(button.pin); // PULLDOWN
    }
}

uint8_t input_readButton(Button button) {
    if (button.type == BUTTON_TYPE_PULLUP) {
        return !(*button.pPin & _BV(button.pin));
    }

    return (*button.pPin & _BV(button.pin));
}
