void setup()
{
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
}

void loop()
{
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	delay(500);
	digitalWrite(7, LOW);
	delay(1000);
}