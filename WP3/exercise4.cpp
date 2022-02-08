// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 4
// Submission code:

#include <Keypad.h>

const byte rows = 4; //four rows
const byte columns = 4; //four columns

char keys[rows][columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[columns] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//Createobject class of keypad
Keypad ourKeyPad = Keypad( makeKeymap(keys), rowPins, colPins, rows, columns );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char keyP = ourKeyPad.getKey();// Read the key pressed from keypad
  
  // Print if key pressed
  if (keyP){
    Serial.print("Key Clicked on : ");
    // Display the pressed keys
    Serial.println(keyP);
  }
}
