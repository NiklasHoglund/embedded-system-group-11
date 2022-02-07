// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 1
// Submission code: 

void setup()
{
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
}

void loop()
{
	digitalWrite(0, HIGH);
	digitalWrite(1, HIGH);
	delay(500); // Wait for 500 millisecond(s)
	digitalWrite(1, LOW);
	delay(500); // Wait for 500 millisecond(s)
}
