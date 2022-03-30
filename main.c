#include <avr/io.h>
#include <avr/interrupt.h>
#include "lib/dcmotor.h"
#include "lib/inputs.h"
#include "lib/debug.h"

int main(void)
{

    Led ledRed = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pin = PB1, // pin D9
        .type = LED_TYPE_GROUND
    };
    Led ledGreen = {
        .pDdr = &DDRB,
        .pPort = &PORTB,
        .pin = PB0, // pin D8
        .type = LED_TYPE_GROUND
    };
    Led ledYellow1 = {
        .pDdr = &DDRD,
        .pPort = &PORTD,
        .pin = PD7, // pin D7
        .type = LED_TYPE_GROUND
    };
    Led ledYellow2 = {
        .pDdr = &DDRD,
        .pPort = &PORTD,
        .pin = PD6, // pin D6
        .type = LED_TYPE_GROUND
    };
    Led ledYellow3 = {
        .pDdr = &DDRD,
        .pPort = &PORTD,
        .pin = PD5, // pin D5
        .type = LED_TYPE_GROUND
    };

    input_initLed(ledRed);
    input_initLed(ledGreen);
    input_initLed(ledYellow1);
    input_initLed(ledYellow2);
    input_initLed(ledYellow3);

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

    dcmotor_init(motor1);
    dcmotor_init(motor2);

    while (1)
    {
        dcmotor_instruction(motor1, DCMOTOR_FORWARD);
        dcmotor_instruction(motor2, DCMOTOR_FORWARD);
        input_ledMode(ledYellow2, LED_LOW);
        input_ledMode(ledRed, LED_HIGH);
        _delay_ms(1000);
        input_ledMode(ledRed, LED_LOW);
        input_ledMode(ledGreen, LED_HIGH);
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        dcmotor_instruction(motor2, DCMOTOR_STOP);
        _delay_ms(1000);
        input_ledMode(ledGreen, LED_LOW);
        input_ledMode(ledYellow1, LED_HIGH);
        dcmotor_instruction(motor1, DCMOTOR_BACKWARD);
        dcmotor_instruction(motor2, DCMOTOR_BACKWARD);
        _delay_ms(1000);
        input_ledMode(ledYellow1, LED_LOW);
        input_ledMode(ledYellow2, LED_HIGH);
        dcmotor_instruction(motor1, DCMOTOR_STOP);
        dcmotor_instruction(motor2, DCMOTOR_STOP);
        _delay_ms(1000);
    }
}
