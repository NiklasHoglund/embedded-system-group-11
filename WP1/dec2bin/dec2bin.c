// (C) Ahmed Yasser/ Axel Broberg/ Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 4_2
// Submission code: 11AAAAAA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main program section
int main(int argc, char* argv[]) {
    system("cls");


    if (!atoi(argv[1])) {
        // Checks if its a valid input
        printf("%s", "Invalid input");
    }
    else if (strcmp("-h", argv[1]) == 0) {
        printf("%s", "Please enter a decimal number to convert into binary.");
    }
    else {
        dec2bin(atoi(argv[1]));
    }

    printf("\n");
}

// Converts a decimal into binary
// https://www.javatpoint.com/c-program-to-convert-decimal-to-binary
int dec2bin(int dec) {
    int a[32], i, k, binMod = 0; // Initialize and declare variables

    // For loop that runs while dec is larger than 0
    for (i = 0; dec > 0; i++) {
        a[i] = dec % 2; // Divide the decimal number by 2 with the modulus operator
        dec = dec / 2; // Divide the decimal number by 2 with the division operator
    }

    // For loop for checking if any number in the array isn't 1 or 0
    for (int j = 0; j < sizeof(a); j++)
    {
        if (a[j] == NULL) { // If index in the array is empty
            break;
        }
        if (a[j] != 0) { // If index in the array is 0
            if (a[j] != 1) { // If index in the array is 1
                printf("%s", "Conversion unsuccessful");
                return 2;
            }
        }
    }

    binMod = 8 - (i % 8); // Get the amount of 0 needed to format the output in an 8-bit format
    for (k = 0; k < binMod; k++) { // For loop that runs binMod times
        printf("%d", 0); // Prints 0
    }

    for (i = i - 1; i >= 0; i--) { // For loop that runs the same amount of times that the first for loop ran but backwards
        printf("%d", a[i]); // Print number in array at index i
    }

    return a; // Return array a
}
