#include <avr/io.h>
#include <avr/interrupt.h>
#include "lib/dcmotor.h"
#include "lib/basicio.h"
#include "lib/debug.h"
Led ledRed = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB1, // pin D9
    .type = LED_TYPE_GROUND,
};

Led ledGreen = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB0, // pin D8
    .type = LED_TYPE_GROUND,
};

Led ledYellow1 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD7, // pin D7
    .type = LED_TYPE_GROUND,
};

Led ledYellow2 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD6, // pin D6
    .type = LED_TYPE_GROUND,
};

Led ledYellow3 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD5, // pin D5
    .type = LED_TYPE_GROUND,
};

Button upButton = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD4, // pin D4
    .type = BUTTON_TYPE_PULLUP,
};

Button downButton = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pPin = &PINB,
    .pin = PB5, // pin D13
    .type = BUTTON_TYPE_PULLUP,
};

Button emergencyButton = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pPin = &PINB,
    .pin = PB2, // pin D10
    .type = BUTTON_TYPE_PULLUP,
};

Button selectButton1 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD3, // pin D3
    .type = BUTTON_TYPE_PULLUP,
};

Button selectButton2 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD2, // pin D2
    .type = BUTTON_TYPE_PULLUP,
};

DcMotor motor1 = {
    .pDdrA = &DDRC,
    .pDdrB = &DDRC,
    .pPortA = &PORTC,
    .pPortB = &PORTC,
    .pinA = PC2, // pin A2
    .pinB = PC3, // pin A3
    .pDdrLimitA = &DDRC,
    .pPortLimitA = &PORTC,
    .pPinLimitA = &PINC,
    .limitA = PC0, // pin A0
};

DcMotor motor2 = {
    .pDdrA = &DDRC,
    .pDdrB = &DDRC,
    .pPortA = &PORTC,
    .pPortB = &PORTC,
    .pinA = PC4, // pin A4
    .pinB = PC5, // pin A5
    .pDdrLimitA = &DDRC,
    .pPortLimitA = &PORTC,
    .pPinLimitA = &PINC,
    .limitA = PC1, // pin A1
};

void test()
{
    if (input_readButton(emergencyButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        input_ledMode(ledYellow1, LED_HIGH);
        input_ledMode(ledRed, LED_LOW);
        input_ledMode(ledGreen, LED_LOW);
    }
    else if (input_readButton(upButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_FORWARD);
        input_ledMode(ledRed, LED_LOW);
        input_ledMode(ledGreen, LED_HIGH);
    }
    else if (input_readButton(downButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_BACKWARD);
        input_ledMode(ledRed, LED_HIGH);
        input_ledMode(ledGreen, LED_LOW);
    }
    else
    {
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        input_ledMode(ledRed, LED_LOW);
        input_ledMode(ledGreen, LED_LOW);
        input_ledMode(ledYellow1, LED_LOW);
    }
}

int main(void)
{

    input_initLed(ledRed);
    input_initLed(ledGreen);
    input_initLed(ledYellow1);
    input_initLed(ledYellow2);
    input_initLed(ledYellow3);
    input_initButton(upButton);
    input_initButton(downButton);
    input_initButton(emergencyButton);
    input_initButton(selectButton1);
    input_initButton(selectButton2);

    dcmotor_init(motor1);
    dcmotor_init(motor2);

    while (1)
    {
        test();
    }
}
