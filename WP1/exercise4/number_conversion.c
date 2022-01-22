// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialization variables
int dec2bin(int dec);

void bin2hex(long int input);

// Main program section

int main() {
	long int bin = 00001111;
	system("cls");
	bin2hex(bin);
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

// Converts binary to hexadecimal
// https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
void bin2hex(long int input) {
	
	long int binaryval, hexadecimalval = 0, i = 1, remainder; // Initialize and declare variables
	binaryval = input; //Set variable binaryval to input
	while (binaryval != 0) { // While the binaryval isn't 0
		remainder = binaryval % 10; // Set the remainder variable to binaryval divided by 10 using the modulus operator
		hexadecimalval = hexadecimalval + remainder * i; // To the hexadecimalval variable, add itself plus the remainder * i 
		i = i * 2; // Double the i variable
		binaryval = binaryval / 10; // Divide binaryval variable by 10
	}
	printf("Equivalent hexadecimal value: %lX", hexadecimalval);
	return 0;
}
