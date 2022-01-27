// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialization variables

void bin2hex(long int input);

// Main program section

int main(int argc) {
    long int bin = argc;
    printf("\n");
    bin2hex(bin);

    return 0;
}

// Converts binary to hexadecimal
// https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
void bin2hex(long int input) {

    long int binaryval, hexadecimalval = 0, i = 1, remainder; // Initialize and declare variables
    binaryval = input;
    printf("Enter the binary number: ");

    // recieve the user input
    scanf_s("%ld", &binaryval);

    // logic math behind converting bin to hex
    while (binaryval != 0) { // While the binaryval isn't 0
        remainder = binaryval % 10; // Set the remainder variable to binaryval divided by 10 using the modulus operator
        hexadecimalval = hexadecimalval + remainder * i; // To the hexadecimalval variable, add itself plus the remainder * i 
        i = i * 2; // Double the i variable
        binaryval = binaryval / 10; // Divide binaryval variable by 10
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);
}