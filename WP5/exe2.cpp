// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 5
// Exercise 2
// Submission code: EEE11EEE

//Variables
int temp;
int analogPin = A0;
//Variables for the leds temperature range 
int temp1 = 0;
int temp2 = 26;
int temp3 = 28;
int temp4 = 30;
int temp5 = 32;
int temp6 = 50;

#include <math.h>
/*Code to convert the sensor reading to degrees celsius that was used from example code at
http://arduino-sensor.org/sensor-kits/arduino-ky-013-temperature-sensor-module/ */
double Thermistor(int RawADC) {
    double Temp;
    Temp = log(((10240000 / RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
    Temp = Temp - 273.15;// Convert Kelvin to Celcius
    return Temp;
}

void setup()
{
    // Initialize pins
    pinMode(A0, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    // start serial communication
    Serial.begin(9600);
}

void loop()
{
    //Reading sensor value from analog pin A0
    int valueFromPin = analogRead(analogPin);
    //Converting to degrees Celsius
    double temp = Thermistor(valueFromPin);
    Serial.println(temp);
    // if the temp variable is between temperature range
    if (temp >= temp1 && temp <= temp2) {  //Between 0 and 26 turn on 1 LED
        digitalWrite(6, LOW); // FIFTH 
        digitalWrite(5, LOW); // FOURTH
        digitalWrite(4, LOW); // THIRD
        digitalWrite(3, LOW); // SECOND
        digitalWrite(2, HIGH);//FIRST

    }
    else if (temp >= temp2 && temp <= temp3) { // Between 26 and 28 turn on two leds
        digitalWrite(6, LOW);  // FIFTH 
        digitalWrite(5, LOW);  // FOURTH
        digitalWrite(4, LOW);  // THIRD
        digitalWrite(3, HIGH); //SECOND
        digitalWrite(2, HIGH); //FIRST
    }
    else if (temp >= temp3 && temp <= temp4) { // Between 28 and 30 turn on three leds
        digitalWrite(6, LOW);  // FIFTH 
        digitalWrite(5, LOW);  // FOURTH
        digitalWrite(4, HIGH); // THIRD
        digitalWrite(3, HIGH); //SECOND
        digitalWrite(2, HIGH); //FIRST
    }
    else if (temp >= temp4 && temp <= temp5) { // Between 30 and 32 turn on four leds
        digitalWrite(6, LOW);  // FIFTH 
        digitalWrite(5, HIGH); // FOURTH
        digitalWrite(4, HIGH); // THIRD
        digitalWrite(3, HIGH); //SECOND
        digitalWrite(2, HIGH); //FIRST
    }
    else if (temp >= temp5 && temp <= temp6) { // Between 32 and 50 turn on five leds
        digitalWrite(6, HIGH); // FIFTH 
        digitalWrite(5, HIGH); // FOURTH
        digitalWrite(4, HIGH); // THIRD
        digitalWrite(3, HIGH); //SECOND
        digitalWrite(2, HIGH); //FIRST
    }

    else {  //  Close all if it does not satisfy our req
        digitalWrite(6, LOW); // FIFTH
        digitalWrite(5, LOW); // FOURTH
        digitalWrite(4, LOW); // THIRD
        digitalWrite(3, LOW); //SECOND
        digitalWrite(2, LOW); //FIRST
    }

    delay(1000);
}