// (C) Ahmed Yasser/ Axel Broberg/ Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
    int encryptValue = atoi(argv[1]);
    while (1) {
        char word[25];
        printf("Enter something to encrypt: ");
        scanf_s("%s", word, 24);
        for (int i = 0; i < strlen(word); i++)
        {
            int x = word[i];
            x = x + encryptValue;
            word[i] = (char)x;
        }
        printf("Encrypted word: %s\n", word);
        system("pause");
    }
}