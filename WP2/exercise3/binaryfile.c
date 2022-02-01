// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 3
// Submission code: 

// Include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

// -----typedefs -------
typedef struct  {
    char firstname[20];
    char famname[20];
    char pers_number[20]; // yyyymmddnnnc
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

    strncpy_s(ppost.firstname, MAX, "Matt\n", 5);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, MAX, "Murdock\n", 8);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, MAX, "200010016475\n", 13);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    fclose(fptr);
}

void printfile(void); // Prints out all persons in the file

void printfile(void) {
    FILE* fptr;	// file which we will create
    errno_t err;
    PERSON ppost;
// location to my file
// let's use the same file as before to check how the reading looks like
    char* fileName = "C:\database.bin";

    // open the file to read
    // Note! to read binary file we need to change the modifier - rb instead of just r
    err = fopen_s(&fptr, fileName, "rb");

    // a good practice when working with files is to check
    // that the file pointer is correct, i.e. the file was opened
    // in the way we wanted
    if (err == NULL)
    {
        // if the file was opened (see the flag)
        // we can do something with it
        // here I chose to read a string from the file

        char cValToRead = '0';	// value to read, initialized with 0 just to reserve some space

        fread(&cValToRead,				// where we store the value
            sizeof(cValToRead),		// the size of the single element
            1,						// how many elements we should read
            fptr);			// where we should read them from (file)

      // and print the result on the console
        printf("%c \n", cValToRead);

        // now, version with the buffer
        char* pstrBuffer;

        // reserve a place in memory for MAX characters
        pstrBuffer = malloc(MAX * sizeof(char));

        // now, let's make it fail safe wrt memory
        // and check if the memory was actually allocated
        if (pstrBuffer != NULL)
        {
            // read the number of elements to the buffer
            fread(pstrBuffer,
                sizeof(char),
                MAX - 1,
                fptr);

            // end of string in order to avoid printing random memory content
            pstrBuffer[MAX - 1] = '\0';

            // let's print them and see what happens
            printf("%s \n", pstrBuffer);

            // don't forget to free the memory
            free(pstrBuffer);
        }
        else // the memory could not be allocated
        {
            printf("Error - memory could not be allocated!");
        }

        // and please remember to close the file
        // if we do not close the file, the data may be lost
        fclose(fptr);
    }
    else	// if the file was not opened, e.g. does not exists
    {
        printf("Error opening file %s.", fileName);
    }

}


void search_by_firstname(char* name); // Prints out the person if // in list
void search_by_firstname(char* name);

void append_file(PERSON* inrecord); // appends a new person to the file

void append_file(PERSON* inrecord) {
    errno_t err;
    PERSON ppost;
    FILE* fptr;

    // Open for read  
    err = fopen_s(&fptr, "C:\database.bin", "ab");
    if (err == 0)
    {
        printf("New user has been addedn\n");
    }
    else
    {
        printf("The file is not created\n");
    }

    strncpy_s(ppost.firstname, MAX, "\nFrank\n", 6);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, MAX, "Castle\n", 7);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, MAX, "20050101112\n", 13);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    fclose(fptr);
}


int main(void) {
    // Initilizations
    int choice;
    //Main program menu 
    while (1) {
        printf("\nWelcome to your database, Choose an option from below : \n \n");
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
            append_file(NULL);

        }
        else if (choice == 3) {


        }
        else if (choice == 4) {
            printfile();
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