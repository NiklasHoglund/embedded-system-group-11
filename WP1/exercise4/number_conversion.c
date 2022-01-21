#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dec2bin(int dec);

void bin2hex(long int input);

int main() {
	long int bin = 00001111;
	system("cls");
	bin2hex(bin);
}

// Converts a decimal into binary
// https://www.javatpoint.com/c-program-to-convert-decimal-to-binary
int dec2bin(int dec) {
	int a[16], i, k, binMod = 0;

	for (i = 0; dec > 0; i++) {
		a[i] = dec % 2;
		dec = dec / 2;
	}

	binMod = 8 - (i % 8);
	for (k = 0; k < binMod; k++) {
		printf("%d", 0);
	}

	for (i = i - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	return a;
}

// Converts binary to hexadecimal
// https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
void bin2hex(long int input) {
	
	long int binaryval, hexadecimalval = 0, i = 1, remainder;
	binaryval = input;
	while (binaryval != 0) {
		remainder = binaryval % 10;
		hexadecimalval = hexadecimalval + remainder * i;
		i = i * 2;
		binaryval = binaryval / 10;
	}
	printf("Equivalent hexadecimal value: %lX", hexadecimalval);
	return 0;
	/*long int hexadecimalval = 0, i = 1, remainder;
	while (binaryval != 0)
	{
		remainder = binaryval % 10;
		hexadecimalval = hexadecimalval + remainder * i;
		i = i * 2;
		binaryval = binaryval / 10;
	}
	printf("Equivalent hexadecimal value: %lX", hexadecimalval);
	return hexadecimalval;*/

}