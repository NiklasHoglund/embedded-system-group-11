// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 1
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the size of array 
#define MAX 100

// Defining the largest value in an array 
#define MAXNUMBER 20

// Main program section

//Got few ideas about histogram from here , https://www.geeksforgeeks.org/program-make-histogram-array/ , https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

// Set a random number in each slot in array  , fill *tab with these numbers
void create_random(int* tab);

// Calculate frequency of each number count by creating a table , from *tab random numbers
void count_frequency(int* tab, int* freq);

// Draw a histogram to represent frequency count table
void draw_histogram(int* freq);

int main(void) {
    // using malloc and calloc for dynamic array allocation

    // array to hold the random numbers // malloc returns pointer types , (int*) highlights the type cast that convert pointer type to int*
    int* table = (int*)malloc(MAX * sizeof(int));

    // calling create random  function in main , to create random number in array , also by filling *tab with the "table"
    create_random(table);

    // create an array and intialize each slot with 0 // calloc to allocate multiple memory sizes in the array
    int* frequency = (int*)calloc(MAXNUMBER, sizeof(int));
    count_frequency(table, frequency);

    // calling draw histogram function to represent the frequency
    draw_histogram(frequency);

    return 0;
}

void create_random(int* tab) {
    // To make sure its random 
    srand(time(0));
    // loop on array to calculate random number
    for (int i = 0; i < MAX; i++) {

        // MAXNUMBER + 1 to be able to include the possibility 
        // of having max number in array
        tab[i] = rand() % (MAXNUMBER + 1);
    }
}

void count_frequency(int* tab, int* freq) {

    // for loop on array to calculate frequency , until it reaches the limit assigned 
    for (int i = 0; i < MAX; i++) {
        // increment freq 
        freq[tab[i]]++;
    }
}

void draw_histogram(int* freq) {

    // for loop to create histogram of the frequency count according to the MAXNUMBER limit
    for (int i = 0; i < MAXNUMBER; i++) {
        // if statement to make sure that numbers with no frequencies does not show
        if (freq[i] != 0) {
            // prints number from the array that have frequency ( replication )
            printf("%d ", i);
            // for loop to go through every element in the array that have freq
            for (int j = 0; j < freq[i]; j++) {
                // indicate how many similar number in the array *
                printf("*");
            }
            // space line 
            printf("\n");
        }
    }
}