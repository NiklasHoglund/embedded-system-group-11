// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 4
// Exercise 3
// Submission code:

#include <Adafruit_NeoPixel.h>

// How many NeoPixels that are are attached to the Arduino
#define LED_COUNT 12
//  pin which on the Arduino is connected to the NeoPixels
#define LED_PIN    8

// Initialization variables

int temp = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB);
void setup()
{
  pinMode(A0, INPUT); 
  pinMode(7, OUTPUT);
  pixels.begin();
  pixels.setBrightness(100);
  pixels.show();
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(7, LOW);
  pixels.clear(); 
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // Math to map the temperature
  Serial.println("Temp: ");
  Serial.println(temp);	
 
  if(temp <= -30){
  	pixels.setPixelColor(0, pixels.Color(0,118,189));
    pixels.show();
    delay(42);
  }
  else if(temp <= -20){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.show();
    delay(42);
     }
  else if(temp <= -10){
  	pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
    pixels.show();
    delay(42);
     }
  else if(temp <= 0){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
    pixels.show();
    delay(42);
  }
 else if(temp <= 10){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.show();
    delay(42); 
 }
   else if(temp <= 20){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.show();
    delay(42); 
 }
   else if(temp <= 30){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
    pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.show();
    delay(42); 
 }
   else if(temp <= 40){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.setPixelColor(7, pixels.Color(255,255,0));
    pixels.show();
    delay(42); 
 }
  else if(temp <= 50){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.setPixelColor(7, pixels.Color(255,255,0));
    pixels.setPixelColor(8, pixels.Color(255,0,0));
    pixels.show();
    delay(42); 
 }
  else if(temp <= 60){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.setPixelColor(7, pixels.Color(255,255,0));
    pixels.setPixelColor(8, pixels.Color(255,0,0));
    pixels.setPixelColor(9, pixels.Color(255,0,0));

    pixels.show();
    delay(42); 
 }
  else if(temp <= 70){
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.setPixelColor(7, pixels.Color(255,255,0));
    pixels.setPixelColor(8, pixels.Color(255,0,0));
    pixels.setPixelColor(9, pixels.Color(255,0,0));
    pixels.setPixelColor(10, pixels.Color(255,0,0));
    pixels.show();
    delay(42); 
 }
  else {
    pixels.setPixelColor(0, pixels.Color(0,118,189));
  	pixels.setPixelColor(1, pixels.Color(0,118,189));
    pixels.setPixelColor(2, pixels.Color(0,118,189));
  	pixels.setPixelColor(3, pixels.Color(0,118,189));
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
    pixels.setPixelColor(5, pixels.Color(255,255,0));
    pixels.setPixelColor(6, pixels.Color(255,255,0));
    pixels.setPixelColor(7, pixels.Color(255,255,0));
    pixels.setPixelColor(8, pixels.Color(255,0,0));
    pixels.setPixelColor(9, pixels.Color(255,0,0));
    pixels.setPixelColor(10, pixels.Color(255,0,0));
    pixels.setPixelColor(11, pixels.Color(255,0,0));
    pixels.show();
    if (temp >= 100){
    	digitalWrite(7, HIGH);
    }
    delay(42); 
 }
   
   
   /*
   for(int i = 0; i < LED_COUNT; i++){
    pixels.setPixelColor(i, pixels.Color(0,118,189));
    pixels.show();
    delay(42);
  }
    for(int i = 0; i < LED_COUNT; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(42);
  }
  */
  
}
