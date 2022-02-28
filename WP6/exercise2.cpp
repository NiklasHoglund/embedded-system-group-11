// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 6
// Exercise 2
// Submission code: 1111111F

// Initializations
const int signalPin = 7;
const int negPin = 9;

#define LED1 5
#define LED2 4
#define LED3 3
#define LED4 2

void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    // Start connection
    Serial.begin(9600);
    pinMode(negPin, OUTPUT);
}

void loop() {
    // variables for duration of the ping,distance result in centimeters:
    long duration, cm;
  
    // Logic
    // triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse
    pinMode(signalPin, OUTPUT);
    digitalWrite(signalPin, LOW);
    delayMicroseconds(2);
    digitalWrite(signalPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(signalPin, LOW);

    pinMode(signalPin, INPUT);
    duration = pulseIn(signalPin, HIGH);

    // Convert time into distance
    cm = microsecondsToCentimeters(duration);

    // Print the distance just for debugging
    Serial.print("Distance between object : ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();

    // Turn on the LED if the object is too close:
    if(cm <= 200 && cm > 125) { // 1 LED ON
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(negPin, HIGH);
        tone(negPin, 50);
    } else if (cm <= 125 && cm > 75) { // 2 LED ON
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(negPin, HIGH);
        tone(negPin, 75);
    } else if (cm <= 75 && cm > 50) { // 3 LED ON
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, LOW);
        digitalWrite(negPin, HIGH);
        tone(negPin, 100);
    } else if (cm <= 50 && cm > 25) { // 4 LED ON
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(negPin, HIGH);
        tone(negPin, 150); // Makes the tone more annoying
    } else if (cm <= 25) { // Periodically turn all LEDs ON and OFF
        digitalWrite(negPin, HIGH);
        tone(negPin, 200);

        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        delay(1000);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        delay(1000);

    } else if (cm > 200) {
        digitalWrite(negPin, LOW); // Sound sleep
    }

    delay(100);
}

long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s
// Logic to find distance of the object ( take half )
    return microseconds / 29 / 2;
}
