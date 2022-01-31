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

    // Open for read (will fail if file "crt_fopen_s.c" does not exist)  
    err = fopen_s(&fptr, "C:\database.bin", "wb");
    if (err == 0)
    {
        printf("The file 'crt_fopen_s.c' was opened\n");
    }
    else
    {
        printf("The file 'crt_fopen_s.c' was not opened\n");
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
void search_by_firstname(char* name); // Prints out the person if // in list

void append_file(PERSON* inrecord); // appends a new person to the file

int main(void) {
    int choice;
    int n;

    while (1) {
        printf("Welcome to your database, Choose an option from below : \n \n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n \n");

        scanf_s("%d", &choice);
        if (choice == 1) {

            write_new_file(NULL);

        }
        else if (choice == 2) {


        }
        else if (choice == 3) {


        }
        else if (choice == 4) {


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