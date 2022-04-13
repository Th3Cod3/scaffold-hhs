#include <avr/io.h>
#include <avr/interrupt.h>
#include "lib/dcmotor.h"
#include "lib/encoder.h"
#include "lib/basicio.h"
#include "lib/debug.h"

EncoderInterrupt rightMotorEncoder = {
    .pPcmsk = &PCMSK0,
    .pcmsk = PCINT4,
    .pcie = PCIE0,
    .pcif = PCIF0,
    .encoder = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pPin = &PINC,
        .pin = PC0, // pin A0
        .type = LED_TYPE_GROUND,
    },
};

EncoderInterrupt leftMotorEncoder = {
    .pPcmsk = &PCMSK0,
    .pcmsk = PCINT3,
    .pcie = PCIE0,
    .pcif = PCIF0,
    .encoder = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pPin = &PINC,
        .pin = PC1, // pin A1
        .type = LED_TYPE_GROUND,
    },
};

Output ledRed = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB1, // pin D9
    .type = LED_TYPE_GROUND,
};

Output ledYellow1 = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB0, // pin D8
    .type = LED_TYPE_GROUND,
};

Output ledYellow2 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD7, // pin D7
    .type = LED_TYPE_GROUND,
};

Output ledYellow3 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD6, // pin D6
    .type = LED_TYPE_GROUND,
};

Output ledGreen = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD5, // pin D5
    .type = LED_TYPE_GROUND,
};

Input upButton = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD4, // pin D4
    .type = BUTTON_TYPE_PULLUP,
};

Input downButton = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pPin = &PINB,
    .pin = PB5, // pin D13
    .type = BUTTON_TYPE_PULLUP,
};

Input emergencyButton = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pPin = &PINB,
    .pin = PB2, // pin D10
    .type = BUTTON_TYPE_PULLUP,
};

Input rightButton = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD3, // pin D3
    .type = BUTTON_TYPE_PULLUP,
};

Input leftButton = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD2, // pin D2
    .type = BUTTON_TYPE_PULLUP,
};

DcMotor rightMotor = {
    .pinA = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pin = PC2, // pin A2
        .type = LED_TYPE_GROUND,
    },
    .pinB = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pin = PC3, // pin A3
        .type = LED_TYPE_GROUND,
    },
    .limit = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pPin = &PINB,
        .pin = PB4, // pin D12
        .type = BUTTON_TYPE_PULLUP,
    },
};

DcMotor leftMotor = {
    .pinA = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pin = PC4, // pin A4
        .type = LED_TYPE_GROUND,
    },
    .pinB = {
        .pDdr = &DDRC,
        .pPort = &PORTC,
        .pin = PC5, // pin A5
        .type = LED_TYPE_GROUND,
    },
    .limit = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pPin = &PINB,
        .pin = PB3, // pin D11
        .type = BUTTON_TYPE_PULLUP,
    },
};

ISR(PCINT0_vect)
{
    encoder_count(rightMotorEncoder, 1);
    encoder_count(leftMotorEncoder, 1);
}

int main(void)
{
    basic_initOutput(ledRed);
    basic_initOutput(ledGreen);
    basic_initOutput(ledYellow1);
    basic_initOutput(ledYellow2);
    basic_initOutput(ledYellow3);
    basic_initInput(upButton);
    basic_initInput(downButton);
    basic_initInput(emergencyButton);
    basic_initInput(rightButton);
    basic_initInput(leftButton);
    encoder_init(rightMotorEncoder);
    encoder_init(leftMotorEncoder);

    dcmotor_init(rightMotor);
    dcmotor_init(leftMotor);

    while (1)
    {

    }
}
