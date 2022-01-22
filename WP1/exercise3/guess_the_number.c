// (C) Ahmed Yasser/ Axel Broberg/ Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

// Include section
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


// Main program section

// Program purpose to demonstrate a simple fun guessing a number game 

//Method that is called in the int main 
void guessGame(int number)
{
    int randomNumber, guess, numberGuess = 0; // Initialization of Random number / Guess number by the user / Number of guesses
    int choice; // Initialization of choice where the user chooses to continue or end program after guessing right

    //program logic

    srand(time()); // To make sure it randomize the Random number every time the program starts
    // Random number syntax
    randomNumber = rand() % number;

    // Display the range of numbers where the user enters between it
    printf("Guess a number between"" 1 and %d\n", number);

    // Do-While loops until the user guesses the random number correctly
    do {
        // Limit to the number of times the user can guess (100 times)
        if (numberGuess > 100) {
            break;
        }
        // User's input a number , while loop here makes sure the scanned input is an integer not char , to avoid crashing and assures integer is entered
        while (scanf_s("%d", &guess) != 1) {
            // Asks the user to enter an integer
            printf("Please enter a valid integer\n");
            while ((getchar()) != '\n');
        }
        // If statement to make sure the user's input is only between 1 - 100
        if (guess > 100 || guess < 1) {
            // Asks the user to enter number in range of 1 - 100
            printf("Enter a valid integer in range of 1 to 100 :");
        }
        // When the user's guess is above the correct number
        else if (guess > randomNumber) {
            printf("Go with Lower number ""\n");

            // counts as an attempt to reach the random number
            numberGuess++;
        }

        // When the user's guess is below the correct number
        else if (randomNumber > guess) {
            printf("Go with Higher number""\n");

            // counts as an attempt to reach the random number
            numberGuess++;
        }
        // Displays number of times user guessed until he reached the correct guess
        else {
            // Result
            printf("You got the"" guessed number in %d ""attempts !\n \n",
                numberGuess);
            // Asks the user if they want to proceed with new round or end the program
            printf("Do you want a new round or finish?\n");
            printf("1: for new round\n");
            printf("2: to finish\n");

            // reads the user's input by the choice variable 
            scanf_s("%d", &choice);

            // if statement to see if the input is  1 to proceed with new round and loops again from up
            if (choice == 1) {
                // Initialization of new random number
                randomNumber = rand() % number;
                printf("Guess a number between"" 1 and %d\n", number);
                // Resets the number of guesses
                numberGuess = 1;
            }
            // if the input is 2 it will close the program
            else {
                printf("Finished");
            }
        }

    } while (guess != randomNumber);
}


int main() {
    // Parameter sent to the guess method clarifying the limit range for the number (1 - 100 )
    int number = 100;
    // calls the guess method
    guessGame(number);

    return 0;
}