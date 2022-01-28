// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdbool.h>

// Initialize functions
int bin2hex();
bool ifBinary(int num); 

// Main program section
int main() {
    printf("\n");
    printf("%X", bin2hex());
    return 0;
}

// Converts binary to hexadecimal
// https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
int bin2hex() {

    long int binaryval, hexadecimalval = 0, x = 1, i = 1, remainder; // Initialize and declare variables

    printf("Enter the binary number: ");
    // recieve the user input
    scanf_s("%ld", &binaryval);
    
    // Check if variable is binary
    if (!ifBinary(binaryval)) {
        printf("%s", "This is not a binary value.\n");
        return 0;
    } 

    // logic math behind converting bin to hex
    while (binaryval != 0) { // While the binaryval isn't 0
        remainder = binaryval % 10; // Set the remainder variable to binaryval divided by 10 using the modulus operator
        hexadecimalval = hexadecimalval + remainder * i; // To the hexadecimalval variable, add itself plus the remainder * i 
        i = i * 2; // Double the i variable
        binaryval = binaryval / 10; // Divide binaryval variable by 10
    }

    return hexadecimalval;  
}

// Function for checking if integer is in binary format
bool ifBinary(int num) {
    int j = 0; // Remainder variable
    while (num  > 0) // While num is still a number
    {
        j = num % 10; // Get remainder
        if ((j != 0) && (j != 1)) // Check if it's 0 or 1
        {
            return(false);
            break;
        }
        num = num / 10; // Divide by 10 to access the next digit
        if (num == 0)
        {
            return(true);
        }
    }
}