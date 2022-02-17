// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 4
// Exercise 2
// Submission code: DD11DDDD

#include <Servo.h>

int position = 0;

int i = 0;
bool rise = false;
int x = 0;
int seconds = 0;

Servo servo1;

const int led_pin = PB5;

// Counter and compare values
const uint16_t tl_load = 0;
const uint16_t tl_comp = 65535;

void moveServo();

void setup() {
    servo1.attach(5, 500, 2500);
    Serial.begin(9600);

    // Set to output
    DDRB |= (1 << led_pin);
    //Reset Timer2 Control Reg A
    TCCR2A = 0;

    // Set to prescaler of 256
    TCCR2B |= (1 << CS22);
    TCCR2B &= ~(1 << CS21);
    TCCR2B &= ~(1 << CS20);

    // Reset Timer2 and set compare value
    TCNT2 = tl_load;
    OCR2A = tl_comp;

    // Enable timer2 compare interrupt
    TIMSK2 = (1 << OCIE2A);

    // Enable global interrupts
    sei();
}

void loop() {
    if (x > 999) {
        moveServo();
        x = 0;
        seconds = seconds + 1;
        Serial.println(seconds);
    }
}

// Create interrupt service routine
ISR(TIMER2_COMPA_vect) {
    // Reset timer2 to 0
    TCNT2 = tl_load;
    x = x + 1;
}

void moveServo() {
    if (i == 179) {
        i = 0;
    }

    i = i + 3;
    servo1.write(i);

}
