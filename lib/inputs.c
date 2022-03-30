#include <avr/io.h>
#include "inputs.h"

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
