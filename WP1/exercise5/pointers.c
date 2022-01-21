// Try to modify and run it and check out
// the output in the terminal below
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of array 
#define MAX 10

// largest value in array 
#define MAXNUMBER 20

// set a random number in each slot in array 
void create_random(int* tab);
// testing purposes 
void printarray(int* tab, int size);
// calculate frequency of each number 
void count_frequency(int* tab, int* freq);
// Draw a histogram to represent frequency
void draw_histogram(int* freq);

int main() {
    // array to hold the random numbers
    int* table = (int*)malloc(MAX * sizeof(int));
    create_random(table);
    //printarray (table, MAX); // to test only
    // create an array and intialize each slot with 0 
    int* frequency = (int*)calloc(MAXNUMBER, sizeof(int));
    count_frequency(table, frequency);
    //printarray(frequency, MAXNUMBER); // to test only
    draw_histogram(frequency);
    return 0;
}

void create_random(int* tab) {

    srand(time(0));
    // loop on array to calculate random number
    for (int i = 0; i < MAX; i++) {

        // MAXNUMBER + 1 to be able to include the possibility 
        // of having max number in array
        tab[i] = rand() % (MAXNUMBER + 1);
    }
}

void printarray(int* tab, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

void count_frequency(int* tab, int* freq) {

    // loop on array to calculate frequency
    for (int i = 0; i < MAX; i++) {

        freq[tab[i]]++;
    }
}

void draw_histogram(int* freq) {

    for (int i = 0; i < MAXNUMBER; i++) {

        if (freq[i] != 0) {
            printf("%d ", i);

            for (int j = 0; j < freq[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}