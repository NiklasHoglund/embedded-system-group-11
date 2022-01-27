#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialization variables

// Main program section

int main(int argc) {

    system("cls");
    dec2bin(argc);
    printf("\n");
}

// Converts a decimal into binary
// https://www.javatpoint.com/c-program-to-convert-decimal-to-binary
int dec2bin(int dec) {
    int a[16], i, k, binMod = 0; // Initialize and declare variables

    // For loop that runs while dec is larger than 0
    for (i = 0; dec > 0; i++) {
        a[i] = dec % 2; // Divide the decimal number by 2 with the modulus operator
        dec = dec / 2; // Divide the decimal number by 2 with the division operator
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
