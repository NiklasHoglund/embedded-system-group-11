#include <stdio.h>
#include <stdlib.h>

int dec2bin(int dec);

int main() {
	system("cls");
	dec2bin(1200);
}

//Converts a decimal into binary
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
