// (C) Ahmed Yasser/ Axel Broberg/ Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)


// Include section
#include <stdio.h>
#include <stdlib.h>

#define TERMINATING "\nEOF Detected, Ending Program "
// Main program section

int main(int argc, char* argv[]) {
    // Get the value that characters should be "shifted" by in the ASCII-code table
    int encryptValue = atoi(argv[1]);
    // While loop to make the program re-run
    do {
        // A character array which will hold the word the user wants to encrypt
        char word[25];
        printf("Enter something to encrypt: ");
        //Reads n characters (size of our word array at max) from stream using the stdin argument that is standard input stream for taking input. 
        fgets(word, sizeof(word), stdin);
        // For loop that runs once for every character in the word
        for (int i = 0; i < strlen(word); i++){

            int upper_case = (65 <= word[i] && word[i] <= 90);
            int lower_case = (97 <= word[i] && word[i] <= 122);
            int asciiValue = 0;

            // Convert letter in word at index i to an integer
            int x = word[i];
            //if the letter at index i's integer value is in the span of the upper case letters.
            if (word[i] = upper_case) {
                //if the ascii code plus encrypt input from user is higer than highest ascii nr for upper case
                if (x + encryptValue > 90) {
                    //if the encryption goes over the ascii code for Z we return to the start of the alphabet instead of getting other symbols than letters. 
                    x = x + encryptValue - 26;
                    asciiValue = x;
                }
                else {
                    // if the ascii value + the encryption value does not go over the ascii code for Z we check what new ascii value it should have. 
                    asciiValue = x + encryptValue;
                }
            }
            //if the letter at index i's integer value is in the span of the lower case letters.
            else if (word[i] = lower_case) {
                //if the ascii code plus encrypt input from user is higer than highest ascii nr for lower case
                if (x + encryptValue > 122) {
                    /*if the ascii value + the encryption value goes over the ascii code for z we do - 26 on the current ascii value
                    so that it will always result in a lower case letter and not a symbol from the ascii table.*/
                    x = x + encryptValue - 26;
                    asciiValue = x;
                }
                else {
                    // if the ascii value + the encryption value does not go over the ascii code for z we check what new ascii value it should have. 
                    asciiValue = x + encryptValue;
                }
            }
            // Replace the letter at index i with the variable x type-casted to a char
            word[i] = (char)asciiValue;
        }
        //If the input != EOF it will print the encrypted word. If the input is EOF it will end the do while loop and terminate the program. 
        if (!feof(stdin)){ 
            printf("Encrypted word: %s\n", word);
        }
    } while (!feof(stdin));
    
    printf("%s", TERMINATING);
    return 0; 
}