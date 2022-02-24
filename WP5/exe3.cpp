// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 5
// Exercise 3
// Submission code: EEE11EEE

//Variables
int light;
int lightPercentage;
int analogTempPin = A0;
int analogLightPin = A1;

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

void setup() {
    // Initialize pins
    pinMode(A0, INPUT); //Pin Where the Analog Temperature Sensor is connected to
    pinMode(A1, INPUT); //Pin Where the Light Dependent Resistor is connected to
    pinMode(2, OUTPUT); //GREEN
    pinMode(3, OUTPUT); //RED
    pinMode(4, OUTPUT); //BLUE
    // start serial communication
    Serial.begin(9600);
}

void loop() {
    //Reading sensor value from analog pin A0
    int valueFromPin = analogRead(analogTempPin);
    double temp = Thermistor(valueFromPin);
    //Reading sensor value from analog pin A1
    light = analogRead(analogLightPin);

    Serial.print("Reading of light: ");
    Serial.println(light);
    lightPercentage = map(light, 0, 1023, 100, 0);  //Changing the reading value from 0-1023 to percentage 0-100
    Serial.print(lightPercentage);                  //Showing the light reading in percentage and printing
    Serial.println("%");
    Serial.println("Temp: ");                       //Printing the temperature converted to degrees Celsius from sensor reading
    Serial.println(temp);

    // If statements to handle the conditions we wanted as stated in the exercise
    if (lightPercentage == 0) {
        if (temp < -12) {
            digitalWrite(4, LOW); // BLUE
            digitalWrite(3, LOW); // RED
            digitalWrite(2, HIGH); // GREEN
        }
        else if (temp >= -12) {
            digitalWrite(4, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(2, LOW);
        }
    }
    else if (lightPercentage > 0 && lightPercentage <= 20) {
        if (temp <= -12) {
            digitalWrite(4, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
        }
        else if (temp > -12 && temp < 0) {
            digitalWrite(4, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, HIGH);
        }
        else if (temp > 0) {
            digitalWrite(4, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(2, LOW);
        }
    }
    else if (lightPercentage > 20 && lightPercentage <= 60) {
        if (temp <= 0) {
            digitalWrite(4, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
        }
        else if (temp > 0 && temp < 20) {
            digitalWrite(4, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, HIGH);
        }
        else if (temp > 20) {
            digitalWrite(4, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(2, LOW);
        }
    }
    else if (lightPercentage > 60) {
        if (temp < 21) {
            digitalWrite(4, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
        }
        else if (temp >= 21) {
            digitalWrite(4, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, HIGH);
        }
    }

    delay(1000); // Delay a little bit to improve simulation performance
}