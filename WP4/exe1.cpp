// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 4
// Exercise 1
// Submission code:

// Initialize variables 
int temp = 0;

int temp1 = 0;
int temp2 = 10;
int temp3 = 11;
int temp4 = 20;
int temp5 = 21;
int temp6 = 30;
int temp7 = 31;
int temp8 = 40;
int temp9 = 41;
int temp10 = 50;

void setup()
{
    // Initialize pins (output) and analogs (inputs)
    pinMode(A0, INPUT);
    // start system
    Serial.begin(9600);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    // setting up variables to limit the threshold of turning too cold and too hot 
    // according to the assigment
  // math logic 


    temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // Math to map the temperature

    // just for debugging to print out the current temp
    Serial.println("Temp: ");
    Serial.println(temp);


    if (temp >= temp1 && temp <= temp2) {  //Between 0 and 10 turn on 1 LED
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, LOW); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp >= temp3 && temp <= temp4) { //Between 11 and 20 turn on 2 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp >= temp5 && temp <= temp6) { //Between 21 and 30 turn on 3 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp >= temp7 && temp <= temp8) { //Between 31 and 40 turn on 4 LEDS
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, HIGH);// BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH);//GREEN
    }
    else if (temp >= temp9 && temp <= temp10) { // Between 41 and 50 turn on all 5 LEDS
        digitalWrite(6, HIGH); // YELLOW
        digitalWrite(5, HIGH); // BLUE
        digitalWrite(4, HIGH); // WHITE
        digitalWrite(3, HIGH); // RED
        digitalWrite(2, HIGH); //GREEN
    }
    else {  //  Close all if it does not satisfy our req
        digitalWrite(6, LOW); // YELLOW
        digitalWrite(5, LOW); // BLUE
        digitalWrite(4, LOW); // WHITE
        digitalWrite(3, LOW); // RED
        digitalWrite(2, LOW); //GREEN
    }



    delay(1000); // Delay a little bit to improve simulation performance
}