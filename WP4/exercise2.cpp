// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 4
// Exercise 2
// Submission code:

#include <Servo.h>

int position = 0;

int i = 0;
bool rise = false;

Servo servo1;

const int led_pin = PB5;

// Counter and compare values
const uint16_t tl_load = 0;
const uint16_t tl_comp = 65535;

void moveServo();

void setup() {
    servo1.attach(A0, 500, 2500);
    Serial.begin(9600);

    // Set to output
    // Port B Data Direction Register
    DDRB |= (1 << led_pin);

    //Reset Timer0 Control Reg A
    // Timer/Counter Control Register 0A
    TCCR0A = 0;

    // Set to prescaler of 256
    // Timer/Counter Control Register 0B
    TCCR0B |= (1 << CS12);
    TCCR0B &= ~(1 << CS11);
    TCCR0B &= ~(1 << CS10);

    // Reset Timer0 and set compare value
    // Timer/Counter 0
    TCNT0 = tl_load;
    // Timer/Counter 0 Output Compare Register A
    OCR0A = tl_comp;

    // Enable timer0 compare interrupt
    // Timer/Counter Interrupt Mask Register
    // Timer/Counter0 Output Compare Match A Interrupt Enable
    TIMSK0 = (1 << OCIE0A);

    // Enable global interrupts
    sei();
}

void loop() {
}

// Create interrupt service routine
ISR(TIMER0_COMPA_vect) {
    // Reset timer1 to 0
    TCNT0 = tl_load;

    moveServo();
}

void moveServo() {
    // If timer is at max value, reset to 0
    if (i == 180) {
        i = 0;
    }

    // Increment timer value
    i++;

    // Set servo value
    servo1.write(i);

    // If statement to make sure that the same clock value isn't printed three times in a row
    if (servo1.read() % 3 == 0) {
        Serial.println(servo1.read() / 3);
    }
}
