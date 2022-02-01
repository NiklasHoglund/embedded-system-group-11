// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 3
// Submission code: 

// Include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct  {
    char firstname[10];
    char famname[10];
    char pers_number[10]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON* inrecord); // Creates a file and// writes the first record

void write_new_file(PERSON* inrecord) {
    errno_t err;
    PERSON ppost;
    FILE* fptr;

    // Open for read  
    err = fopen_s(&fptr, "C:\database.bin", "wb");
    if (err == 0)
    {
        printf("The file is created\n");
    }
    else
    {
        printf("The file is not created\n");
    }
    char* s = "Ahmed";
    strncpy_s(ppost.firstname, 10, "Ahmed", 5);
    fwrite(&ppost.firstname, sizeof(s), 1, fptr);

    strncpy_s(ppost.famname, 10, "Yasser", 5);
    strncpy_s(ppost.pers_number, 10, "20011013", 4);

    fwrite(&ppost, sizeof(ppost), 1, fptr);

    fclose(fptr);

}
void printfile(void); // Prints out all persons in the file
void printfile() {

    FILE* fptr;

    char filename[100], c;

    printf("Enter the filename to open \n");
    scanf_s("%s", filename);

    // Open file
    fptr = fopen_s(&fptr ,filename, "wb");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
}


void search_by_firstname(char* name); // Prints out the person if // in list

void append_file(PERSON* inrecord); // appends a new person to the file

int main(void) {
    // Initilizations
    int choice;
    int n;

    //Main program menu 
    while (1) {
        printf("Welcome to your database, Choose an option from below : \n \n");
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file.\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n \n");

        // reads user input to execute the requested task
        scanf_s("%d", &choice);

        // if statement according to the user's input, so it will display whats requested
        if (choice == 1) {

            write_new_file(NULL);

        }
        else if (choice == 2) {


        }
        else if (choice == 3) {


        }
        else if (choice == 4) {

            printfile(NULL);
        }
        else if (choice == 5) {
            exit(0);
        }
        else {
            break;
        }
    }


    return(0);
}