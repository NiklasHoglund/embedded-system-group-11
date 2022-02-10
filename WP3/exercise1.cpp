// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 1
// Submission code: CCCCCC11

void setup()
{
  // Initialize pins
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
}

void loop()
{
  // Setting on pin 0 and 1 to high = ON  
  // Note : pin 0 LED only works when Push Button clicked it
	digitalWrite(0, HIGH);
	digitalWrite(1, HIGH);
  // Delay
	delay(500); // Wait for 500 millisecond(s)
  // Turns off yellow LED
	digitalWrite(1, LOW);
  // Delay
	delay(500); // Wait for 500 millisecond(s)
  // Then loops all over again
}
