// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 1
// Submission code: 

#include <stdio.h> // print,scan and getchar
#include <string.h> //used in the for loop to iterate through movement commands with strlen

int check_values(int nr, int x);

int main(int argc, char* argv[])
{
	unsigned char byte = 0;
	if (argc > 6 || argc < 6) {
		printf("Error, too many or too few arguments");
	}
	else if (!check_values(atoi(argv[1]), 1)) {
		printf("Argument 1 is out of bounds");
	}
	else if (!check_values(atoi(argv[2]), 4)) {
		printf("Argument 2 is out of bounds");
	}
	else if (!check_values(atoi(argv[3]), 2)) {
		printf("Argument 3 is out of bounds");
	}
	else if (!check_values(atoi(argv[4]), 1)) {
		printf("Argument 4 is out of bounds");
	}
	else if (!check_values(atoi(argv[5]), 1)) {
		printf("Argument 5 is out of bounds");
	}
	
	
	byte = byte + atoi(argv[1]) << 7;
	byte = byte + atoi(argv[2]) << 4;
	byte = byte + atoi(argv[3]) << 2;
	byte = byte + atoi(argv[4]) << 1;
	byte = byte + atoi(argv[5]);

	printf("\nByte: %X\n", (unsigned char)byte);
}

int check_values(int nr, int x) {
	for (int i = x; i > 0; i--)
	{
		if (i == nr) {
			return 1;
		}
	}
	return 0;
}





/*else if (argv[1] != 0 && argv[1] != 1) {
		printf("Argument 1 needs to be 1 or 0");
	}
	else if (argv[2] != 0 && argv[2] != 1) {
		printf("Argument 2 needs to be 1 or 0");
	}
	else if (argv[3] != 0 && argv[3] != 1 && argv[3] != 2) {
		printf("Argument 3 needs to be 2, 1 or 0");
	}
	else if (argv[4] != 0 && argv[4] != 1 && argv[4] != 2 && argv[4] != 3 && argv[4] != 4) {
		printf("Argument 4 needs to be 4, 3, 2, 1 or 0");
	}
	else if (argv[5] != 0 && argv[5] != 1) {
		printf("Argument 5 needs to be 1 or 0");
	}*/