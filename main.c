#include <avr/io.h>
#include <avr/interrupt.h>
#include "lib/dcmotor.h"
#include "lib/encoder.h"
#include "lib/basicio.h"
#include "lib/debug.h"

EncoderInterrupt motor1Encoder = {
    .pPcmsk = &PCMSK0,
    .pcmsk = PCINT4,
    .pcie = PCIE0,
    .pcif = PCIF0,
    .encoder = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pin = PB4, // pin D12
        .type = BUTTON_TYPE_PULLUP
    }
};

EncoderInterrupt motor2Encoder = {
    .pPcmsk = &PCMSK0,
    .pcmsk = PCINT3,
    .pcie = PCIE0,
    .pcif = PCIF0,
    .encoder = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pin = PB3, // pin D12
        .type = BUTTON_TYPE_PULLUP
    }
};

Output ledRed = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB1, // pin D9
    .type = LED_TYPE_GROUND,
};

Output ledGreen = {
    .pDdr = &DDRB,
    .pPort = &PORTB,
    .pin = PB0, // pin D8
    .type = LED_TYPE_GROUND,
};

Output ledYellow1 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD7, // pin D7
    .type = LED_TYPE_GROUND,
};

Output ledYellow2 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pin = PD6, // pin D6
    .type = LED_TYPE_GROUND,
};

Output ledYellow3 = {
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

Input selectButton1 = {
    .pDdr = &DDRD,
    .pPort = &PORTD,
    .pPin = &PIND,
    .pin = PD3, // pin D3
    .type = BUTTON_TYPE_PULLUP,
};

Input selectButton2 = {
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

ISR(PCINT0_vect) {
    encoder_count(motor1Encoder, 1);
    encoder_count(motor2Encoder, 1);
}

void test()
{
    if (basic_readButton(emergencyButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        basic_ledMode(ledYellow1, LED_HIGH);
        basic_ledMode(ledRed, LED_LOW);
        basic_ledMode(ledGreen, LED_LOW);
    }
    else if (basic_readButton(upButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_FORWARD);
        basic_ledMode(ledRed, LED_LOW);
        basic_ledMode(ledGreen, LED_HIGH);
    }
    else if (basic_readButton(downButton))
    {
        dcmotor_instruction(motor1, DCMOTOR_BACKWARD);
        basic_ledMode(ledRed, LED_HIGH);
        basic_ledMode(ledGreen, LED_LOW);
    }
    else
    {
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        basic_ledMode(ledRed, LED_LOW);
        basic_ledMode(ledGreen, LED_LOW);
        basic_ledMode(ledYellow1, LED_LOW);
    }
}

int main(void)
{

    basic_initLed(ledRed);
    basic_initLed(ledGreen);
    basic_initLed(ledYellow1);
    basic_initLed(ledYellow2);
    basic_initLed(ledYellow3);
    basic_initButton(upButton);
    basic_initButton(downButton);
    basic_initButton(emergencyButton);
    basic_initButton(selectButton1);
    basic_initButton(selectButton2);

    dcmotor_init(motor1);
    dcmotor_init(motor2);

    while (1)
    {
        test();
    }
}
