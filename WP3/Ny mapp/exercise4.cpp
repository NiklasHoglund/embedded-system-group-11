// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 4
// Submission code: CCCCCC11

#include <Keypad.h>

const byte rows = 4; //our four rows from keypad
const byte columns = 4; //our four columns from keypad

// Declaring the constants byte's values by rows & columns
char keyMap[rows][columns] =
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[rows] = {11,10,9,8}; //attaching with row pinouts from the keypad
byte colPins[columns] = {7,6,5,4}; //attaching with col pinouts from the keypad

// Initialize object class of our keypad
Keypad KP= Keypad(makeKeymap(keyMap), rowPins, colPins, rows, columns);

// Starts the system
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char keyP = KP.getKey();// Read the key input pressed from keypad
  
  // If statement to print out only the clicked button from the keypad
  if (keyP){
    delay(50);
    Serial.print("Key Clicked on : ");
    // Display the pressed keys
    Serial.println(keyP);
    delay(50);
  }
}
