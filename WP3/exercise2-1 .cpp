// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 2
// Submission code:

int tempLow = 0;
int tempHigh = 0;
int temp = 0;
int light = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  tempLow = -12;
  tempHigh = 21;

  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  light = map(analogRead(A1), 0, 1023, 0, 255);
  light = light - 1;
  light = light * 0.6;
  Serial.println("Light: ");
  Serial.println(light);
  Serial.println("Temp: ");
  Serial.println(temp);


  if (temp < tempLow+1 && light == 0) { // Turn on blue for temp
      digitalWrite(4, HIGH); // BLUE
      digitalWrite(3, LOW); // RED
      digitalWrite(2, LOW); // GREEN
  } else if (temp >= tempHigh+1 && light > 60) { // Turn on red for temp
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
  } else {
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
  }



  delay(1000); // Delay a little bit to improve simulation performance
}
