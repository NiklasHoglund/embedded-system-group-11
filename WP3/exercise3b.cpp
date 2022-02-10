// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 3-1
// Submission code:

char matrix[4][4] = { // Matrix for the keypad
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600); // Turn on the serial port
    pinMode(11, OUTPUT); // Set ports to output & input
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, INPUT);
    pinMode(6, INPUT);
    pinMode(5, INPUT);
    pinMode(4, INPUT);
}

void loop()
{
    for (int i = 8; i < 12; i++) { // For loop to check the rows

        digitalWrite(11, HIGH); // Turn on port 8-11
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(8, HIGH);

        digitalWrite(i, LOW); // Turn off the row (port i) that we're iterating through

        for (int k = 4; k < 8; k++) { // For loop to check the columns
            if (digitalRead(k) == LOW) { // If the column that the button pressed is on is low
                Serial.println(matrix[i - 8][k - 4]); // Print the char from the matrix that is pressed
            }
            delay(15);
        }

        digitalWrite(i, HIGH); // Reset the row (port i) to high
        delay(15);
    }

}