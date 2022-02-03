// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 4
// Submission code: 

#include <stdio.h> // print,scan and getchar
#include <string.h> //used in the for loop to iterate through movement commands with strlen

int check_values(int nr, int x);

int main(int argc, char* argv[])
{
	unsigned int byte = 0; // Create an unsigned char byte to hold the value to pass
	if (argc > 6 || argc < 6) { // Checks whether there are too many or too few arguments
		printf("Error, too many or too few arguments");
	}
	else if (!check_values(atoi(argv[1]), 1)) { // Checks if the argument passed is too big or too small for the byte
		printf("Argument 1 is out of bounds");
	}
	else if (!check_values(atoi(argv[2]), 7)) {
		printf("Argument 2 is out of bounds");
	}
	else if (!check_values(atoi(argv[3]), 3)) {
		printf("Argument 3 is out of bounds");
	}
	else if (!check_values(atoi(argv[4]), 1)) {
		printf("Argument 4 is out of bounds");
	}
	else if (!check_values(atoi(argv[5]), 1)) {
		printf("Argument 5 is out of bounds");
	}
	else { 

		byte += atoi(argv[5]); // Add argv[5] to the end of the unsigned char
		byte += atoi(argv[4]) << 1; // Set argv[4] 1 index to the left of the end
		byte += atoi(argv[3]) << 2; // Set argv[3] 2 index to the left of the end
		byte += atoi(argv[2]) << 4; // Set argv[2] 4 index to the left of the end
		byte += atoi(argv[1]) << 7; // Set argv[1] 7 index to the left of the end
		
		printf("\nByte: %X\n", byte); // Print byte in hexadecimal format
		printf("\nByte: %d\n", byte); // Print byte in hexadecimal format
	}

}

// Function to check if nr is in the range of 0 - x
int check_values(int nr, int x) {
	for (int i = x; i > -1; i--) // Loops x amount of times
	{
		if (i == nr) { // If i is nr (if nr is allowed in the range 0 - x) return 1
			return 1;
		}
	}
	return 0; // Else return 0
}
