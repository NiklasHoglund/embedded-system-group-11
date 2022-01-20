// (C) Ahmed Yasser/ Axel Broberg/ Niklas HÃ¶glund , group: 11 (2022)
// Work package 1
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void guessGame(int number)
{
    int randomNumber, guess, numberGuess = 0;
    int choice;

    // random number function
    srand(time());
    randomNumber = rand() % number;

    printf("Guess a number between"" 1 and %d\n", number);
    // Do-While loop until the user guesses the number correctly
    do {

        if (numberGuess > 100) {
            break;
        }
        // User's input
        while (scanf_s("%d", &guess) != 1) {
            printf("Please enter a valid integer\n");
            while ((getchar()) != '\n');
        }
        // When the user's guess is above the correct number
        if (guess > 100 || guess < 1) {
            printf("Enter a valid integer in range of 1 to 100 :");
        }
        else if (guess > randomNumber) {
            printf("Go with Lower number ""\n");
            numberGuess++;
        }

        // When the user's guess is below the correct number
        else if (randomNumber > guess) {
            printf("Go with Higher number""\n");
            numberGuess++;
        }
        // Displays number of times user guessed until he reached the correct guess
        else {
            printf("You got the"" guessed number in %d ""attempts !\n \n",
                numberGuess);

            printf("Do you want a new round or finish?\n");
            printf("1: for new round\n");
            printf("2: to finish\n");
            scanf_s("%d", &choice);

            if (choice == 1) {
                randomNumber = rand() % number;
                printf("Guess a number between"" 1 and %d\n", number);
                numberGuess = 1;
            }
            else {
                printf("Finished");
            }
        }

    } while (guess != randomNumber);
}


int main() {
    int number = 100;
    // calls the guess method
    guessGame(number);

    return 0;
}