// (C) Ahmed Yasser/ Axel Broberg/ Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)


// Include section
#include <stdio.h>
#include <stdlib.h>

// Main program section

void main(int argc, char* argv[]) {
    // Get the value that characters should be "shifted" by in the ASCII-code table
    int encryptValue = atoi(argv[1]);

    // While loop to make the program re-run
    while (1) {
        // A character array which will hold the word the user wants to encrypt
        char word[25];
        printf("Enter something to encrypt: ");
        // Scanf_s to let user input their word
        scanf_s("%s", word, 24);
        // For loop that runs once for every character in the word
        for (int i = 0; i < strlen(word); i++)
        {
            // Convert letter in word at index i to an integer
            int x = word[i];
            // Add the encrypt value that the character should be shifted by to the variable x
            x = x + encryptValue;
            // Replace the letter at index i with the variable x type-casted to a char
            word[i] = (char)x;
        }
        // Print the encrypted word
        printf("Encrypted word: %s\n", word);
        // Clears the scanf_s buffer so it doesn't use the same value as before
        while ((getchar()) != '\n');
    }
}