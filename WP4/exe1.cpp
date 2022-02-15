const int led_pin = PB5;

// Counter and compare values
const uint16_t tl_load = 0;
const uint16_t tl_comp = 31250;

// Temperature variables
const int a = 0;
const int b = 10;
const int c = 20;
const int d = 30;
const int e = 40;
const int f = 50;

int temp = 0;

void tempUpdate(int temp);

void setup() {
    Serial.begin(9600);

    // Set to output
    DDRB |= (1 << led_pin);

    //Reset Timer1 Control Reg A
    TCCR1A = 0;

    // Set to prescaler of 256
    TCCR1B |= (1 << CS12);
    TCCR1B &= ~(1 << CS11);
    TCCR1B &= ~(1 << CS10);

    // Reset Timer1 and set compare value
    TCNT1 = tl_load;
    OCR1A = tl_comp;

    // Enable timer1 compare interrupt
    TIMSK1 = (1 << OCIE1A);

    // Enable global interrupts
    sei();
}

void loop() {
    delay(500);
}

// Create interrupt service routine
ISR(TIMER1_COMPA_vect) {
    // Reset timer1 to 0
    TCNT1 = tl_load;

    temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    tempUpdate(temp);

    Serial.println(temp);
}

void tempUpdate(int temp) {
    if (temp > a && temp <= b) {  //Between 0 and 10 turn on 1 LED
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, LOW); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp > b && temp <= c) { //Between 11 and 20 turn on 2 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp > c && temp <= d) { //Between 21 and 30 turn on 3 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp > d && temp <= e) { //Between 31 and 40 turn on 4 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, HIGH);// BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp > e && temp <= f) { // Between 41 and 50 turn on all 5 LEDS
        digitalWrite(6, HIGH); // YELLOW
        digitalWrite(5, HIGH); // BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH); //GREEN
    }
    else {  //  Close all if it does not satisfy our req
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, LOW); // RED
        digitalWrite(2, LOW); //GREEN
    }
}