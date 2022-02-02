// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 1
// Submission code: 

#include <stdio.h> // print,scan and getchar
#include <string.h> //used in the for loop to iterate through movement commands with strlen

int check_values(int nr, int x);


void print_byte_as_bits(char val);

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
	else {
		byte += atoi(argv[5]);
		byte += atoi(argv[4]) << 1;
		byte += atoi(argv[3]) << 2;
		byte += atoi(argv[2]) << 4;
		byte += atoi(argv[1]) << 7;

		printf("\nByte: %X\n", byte);
	}

}

int check_values(int nr, int x) {
	for (int i = x; i > -1; i--)
	{
		if (i == nr) {
			return 1;
		}
	}
	return 0;
}

void print_byte_as_bits(char val)
{
	for (int i = 7; 0 <= i; i--)
	{
		printf("%c", (val & (1 << i)) ? '1' : '0');
	}
}