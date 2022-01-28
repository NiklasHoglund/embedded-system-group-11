// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)


// Include section
#include <stdio.h>

// Main program section

int main() {
    int input; // Initialization of the integer input that will be given by the user
    char stringQ[] = "Enter a new number between 1 - 5:\n"; // Initialization of the array char that will be used in the loop

    printf("Enter a number between 1-5\n");
    // Do-While loop to scan the user's input will stay in the loop until the user input number outside of the range of 1 - 5
    do {
        // scanf_s to read the user's input (integer)
        scanf_s("%d", &input);
        if (input == 1) {
            // if the input is 1 , prints out this sentence
            printf("If Cinderellas shoe fit perfectly, then why did it fall off?\n%s", stringQ);
        }
        if (input == 2) {
            // if the input is 2 , prints out this sentence
            printf("Papercut: A trees final moment of revenge.\n%s", stringQ);
        }
        if (input == 3) {
            // if the input is 3 , prints out this sentence
            printf("I dont need a hair stylist, my pillow gives me a new hairstyle every morning.\n%s", stringQ);
        }
        if (input == 4) {
            // if the input is 4 , prints out this sentence
            printf("If we should not eat at night, why is there a light in the fridge?\n%s", stringQ);
        }
        if (input == 5) {
            // if the input is 5 , prints out this sentence
            printf("I believe we should all pay our tax bill with a smile. I tried, but they wanted cash.\n%s", stringQ);
        }
 
    } while (input >= 1 && input <= 5);
    // Breaks when its out of the given range

    // Displays msg to inform the user about the invalid input and closes the program
    printf("Invalid input closing program");
    return 0;
}