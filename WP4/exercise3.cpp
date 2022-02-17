// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 4
// Exercise 3
// Submission code: Group 11: DD11DDDD

#include <Adafruit_NeoPixel.h> 	//Library for Neopixel ring by Adafruit

#define LED_COUNT 12 	// How many NeoPixels that are are attached to the Arduino
#define LED_PIN    8	//  pin which on the Arduino is connected to the NeoPixels

int temp; 				//Variable for the temperature

/*
Our Neopixel object, we specify, number of LEDs in the ring,
Arduino pin number which will drive the NeoPixel data in &
the pixel type used.
*/
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB);

void setup()
{
    pinMode(A0, INPUT); 			//set analog pin 0 to input
    pinMode(7, OUTPUT); 			//set digital pin to output
    pixels.begin(); 				//starts Neopixel ring
    pixels.setBrightness(100); 	//set the brightness of the addressable LEDs
    Serial.begin(9600); 			//establish serial communication
}
void loop()
{
    digitalWrite(7, LOW); //set RED led to low
    pixels.clear(); 		//set all pixel colors to "off" 
    temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // Math to map the temperature
    Serial.println("Temp: ");
    Serial.println(temp);

    /*Checks the temperature and sets the right color for the LED for every 10°C increase
    or decrease.
    If the temperature is <=-30 it just sets the color for one LED in the ring and one more
    LEDs color is set for every 10 degree increase.*/
    if (temp <= -30) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));

    }
    else if (temp <= -20) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));

    }
    else if (temp <= -10) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
    }
    else if (temp <= 0) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));

    }
    else if (temp <= 10) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));

    }
    else if (temp <= 20) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));

    }
    else if (temp <= 30) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));

    }
    else if (temp <= 40) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 255, 0));

    }
    else if (temp <= 50) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 255, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));

    }
    else if (temp <= 60) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 255, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));
        pixels.setPixelColor(9, pixels.Color(255, 0, 0));

    }
    else if (temp <= 70) {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 255, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));
        pixels.setPixelColor(9, pixels.Color(255, 0, 0));
        pixels.setPixelColor(10, pixels.Color(255, 0, 0));

    }
    /* When the temperature is over 70°C all LEDs are used and the
       regular red LED turns on to indicate we reached the rings capacity.*/
    else {
        pixels.setPixelColor(0, pixels.Color(0, 118, 189));
        pixels.setPixelColor(1, pixels.Color(0, 118, 189));
        pixels.setPixelColor(2, pixels.Color(0, 118, 189));
        pixels.setPixelColor(3, pixels.Color(0, 118, 189));
        pixels.setPixelColor(4, pixels.Color(255, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 255, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));
        pixels.setPixelColor(9, pixels.Color(255, 0, 0));
        pixels.setPixelColor(10, pixels.Color(255, 0, 0));
        pixels.setPixelColor(11, pixels.Color(255, 0, 0));
        digitalWrite(7, HIGH); // turn on the standard red LED 
    }

    pixels.show(); // "pushing" the pixel color data we have set to the the ring. 
    delay(40); //40ms before next temp check and loop

}
