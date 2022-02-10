// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 2-2
// Submission code:

float voltage = 0;
float temp = 0;

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
	pinMode(A0, INPUT);
}

void loop()
{
	voltage = analogRead(A0) * 5.0; // Convert to volt
	voltage /= 1024.0; // Convert to volt

	// Convert from 10mv per degree with 500 mv offse
	temp = (voltage - 0.5) * 100;

	Serial.print(temp); Serial.println(" degrees C");

	delay(500); // Wait for 500 millisecond(s)
}