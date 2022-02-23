int light;
int lightPercentage;
int analogTempPin = A0;

#include <math.h>
/*Code to convert the sensor reading to degrees celsius was used from example code at
http://arduino-sensor.org/sensor-kits/arduino-ky-013-temperature-sensor-module/ */
double Thermistor(int RawADC) {
    double Temp;
    Temp = log(((10240000 / RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
    Temp = Temp - 273.15;// Convert Kelvin to Celcius
    return Temp;
}

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    // start system
    Serial.begin(9600);
}

void loop() {
    int valueFromPin = analogRead(analogTempPin);
    double temp = Thermistor(valueFromPin);
    light = analogRead(A1);

    Serial.print("Reading of light: ");
    Serial.println(light);
    lightPercentage = map(light, 0, 1023, 100, 0);
    Serial.print(lightPercentage);
    Serial.println("%");
    Serial.println("Temp: ");
    Serial.println(temp);

    // If statements to handle the conditions we wanted as requested
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