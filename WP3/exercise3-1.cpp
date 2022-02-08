// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 3
// Exercise 3-1
// Submission code:

char matrix[4][4] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    pinMode(11, OUTPUT);
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
    for (int i = 8; i < 12; i++) {

        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(8, HIGH);

        digitalWrite(i, LOW);

        for (int k = 4; k < 8; k++) {
            if (digitalRead(k) == LOW) {
                Serial.println(matrix[i - 8][k - 4]);
            }
            delay(15);
        }

        digitalWrite(i, HIGH);
        delay(15);
    }

}