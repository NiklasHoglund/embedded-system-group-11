// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 2
// Submission code:

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
  // It will turn on the Blue LED  when Temp is lower than -12 and light is = 0
  if (temp < tempLow+1 && light == 0) { // Turn on blue for temp
      digitalWrite(4, HIGH); // BLUE
      digitalWrite(3, LOW); // RED
      digitalWrite(2, LOW); // GREEN
  } 
  //  It will turn on the Red LED when temp is higher than 21 and light above 60
  else if (temp >= tempHigh+1 && light > 60) { // Turn on red for temp
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
  } else {
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH); // Turn on Green
  }



  delay(1000); // Delay a little bit to improve simulation performance
}
