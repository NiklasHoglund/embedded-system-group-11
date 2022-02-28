// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 5
// Exercise 1
// Submission code: EEE11EEE
void setup()
{
	// Initialize pins
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
}

void loop()
{
	//Digital pins to high
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	delay(500);
	//Digital pin to low
	digitalWrite(7, LOW);
	delay(1000);
}