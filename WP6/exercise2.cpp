// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 6
// Exercise 2
// Submission code: 

// Initializations
const int signalPin = 7;
const int negPin = 9;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
 // Start connection
  Serial.begin(9600);
  pinMode(negPin, OUTPUT);
}

void loop() {
 // establish variables for duration of the ping,
 // and the distance result in inches and centimeters:
  long duration, cm;

 // The PING :is triggered by a HIGH pulse of 2 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, LOW);
  delayMicroseconds(2);
  digitalWrite(signalPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(signalPin, LOW);

 // The same pin is used to read the signal from the PING))): a HIGH
 // pulse whose duration is the time (in microseconds) from the sending
 // of the ping to the reception of its echo off of an object.
  pinMode(signalPin, INPUT);
  duration = pulseIn(signalPin, HIGH);

  // Convert time into  distance
  cm = microsecondsToCentimeters(duration);

  // Print the distance
  Serial.print("Distance between target : ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Turn on the LED if the object is too close:
  if(cm < 100) {
    digitalWrite(negPin, HIGH);
  }
  else {
    digitalWrite(negPin, LOW);
  }
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
