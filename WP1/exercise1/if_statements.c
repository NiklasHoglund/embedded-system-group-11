// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
#include <stdio.h>

int main() {
    int input;
    char stringQ[] = "Enter a new number between 1 - 5:\n";

    printf("Enter a number between 1-5\n");
    do {
        scanf_s("%d", &input);
        if (input == 1) {
            printf("You picked the number 1\n%s", stringQ);
        }
        if (input == 2) {
            printf("You picked the number 2\n%s", stringQ);
        }
        if (input == 3) {
            printf("You picked the number 3\n%s", stringQ);
        }
        if (input == 4) {
            printf("You picked the number 4\n%s", stringQ);
        }
        if (input == 5) {
            printf("You picked the number 5\n%s", stringQ);
        }
 
    } while (input >= 1 && input <= 5);
    printf("Invalid input closing program");
    return 0;
}