// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 2
// Submission code: CCCCCC11

// Initialize variables 
int tempLow = 0;
int tempHigh = 0;
int temp = 0;
int light = 0;

void setup()
{
  // Initialize pin (output) and analogs (inputs)
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  // start system
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  // setting up variables to limit the threshold of turning too cold and too hot 
  // according to the assigment
  tempLow = -12;
  tempHigh = 21;
// math logic 
  
 
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // Math to map the temperature
  light = map(analogRead(A1), 0, 1023, 0, 255); // Math to map the light values
  light = light - 1; // Offsetting the temperature
  light = light * 0.6; // Multiply by 0.6 to make it a value between 1-100
 
  
  // just for debugging to print out the current temp and light
  Serial.println("Light: ");
  Serial.println(light);
  Serial.println("Temp: ");
  Serial.println(temp);

  // If statements to handle the conditions we wanted as requested
  if (light == 0) {
      if (temp < -12) {
          digitalWrite(4, LOW); // BLUE
          digitalWrite(3, LOW); // RED
          digitalWrite(2, HIGH); // GREEN
      }
      else if (temp >= -12) {
          digitalWrite(4, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(2, LOW);
      }
  }
  else if (light > 0 && light <= 20) {
      if (temp <= -12) {
          digitalWrite(4, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(2, LOW);
      }
      else if (temp > -12 && temp < 0) {
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
      }
      else if (temp > 0) {
          digitalWrite(4, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(2, LOW);
      }
  }
  else if (light >= 21 && light <= 60) {
      if (temp <= 0) {
          digitalWrite(4, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(2, LOW);
      }
      else if (temp > 0 && temp < 20) {
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
      }
      else if (temp > 20) {
          digitalWrite(4, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(2, LOW);
      }
  }
  else if (light >= 61) {
      if (temp < 21) {
          digitalWrite(4, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(2, LOW);
      }
      else if (temp >= 21) {
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
      }
  }



  delay(1000); // Delay a little bit to improve simulation performance
}
