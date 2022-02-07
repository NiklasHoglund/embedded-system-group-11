// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 3
// Submission code: B11BBBBB

// Include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Define the size of bytes 
#define MAX 20

// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[20]; // yyyymmddnnnc
} PERSON;

// Function declarations

// PERSON input_record(void);

void write_new_file(PERSON* inrecord);
// Creates a new file and writes the first hardcoded record

// helpful links for ALL syntaxes https://www.programiz.com/c-programming/c-file-input-output , https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-170
void write_new_file(PERSON* inrecord) {
    // Intializations
    errno_t err;
    PERSON ppost; // PERSON class
    FILE* fptr; //  pointer to file that will get created

    // Opens and create new file with name of database.bin 
    err = fopen_s(&fptr, "C:\database.bin", "wb");

    // If statement to notify us if the file was created successfully or not
    if (err == 0)
    {
        printf("The file is created\n");
    }
    else
    {
        printf("The file is not created\n");
    }

    // Used strncpy for the hardcoded first person record
    //Copying the characters then fwrite to send it to the binary file with its assigned value and place (pointing to certain memory to write)
    strncpy_s(ppost.firstname, 6, "Matt\n", 5);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, 9, "Murdock\n", 8);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, 14, "200010016475\n", 13);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    // Good practice to close the pointer to avoid data loss
    fclose(fptr);

    fptr = NULL;
}

void printfile();
// Prints out all persons data in the binary file
void printfile() {
    // Intializations
    FILE* fptr;	//  pointer to file that will get created
    errno_t err;
    PERSON ppost; // PERSON class

    // Opens the binary file "rb"
    err = fopen_s(&fptr, "database.bin", "rb");

    // If statement to make sure the file exists
    if (err == 0) {
        // While loop to iterate over the binary file content 
        while (fread(&ppost, sizeof(PERSON), 1, fptr) == 1) {
            // Printing out the person(s) records
            printf("%s", ppost.firstname);
            printf("%s", ppost.famname);
            printf("%s", ppost.pers_number);

        }
    }
    // In case of file inexistent
    else {
        printf("\n Can not open file");
    }
    // Good practice to close the pointer to avoid data loss
    fclose(fptr);
}
// link where we got idea for this terminate string func : https://www.delftstack.com/howto/c/trim-string-in-c/
char* trimString(char* str)
{
    char* end; // Initialization pointer

    while (isspace((unsigned char)*str)) str++;

    // if statement to check there is no empty space by the parameter
    if (*str == 0)
        return str; // prints out normally when there is no empty space char (Null)


    end = str + strlen(str) - 1;
    // To keep looping if there is empty space
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // terminate the string char , by butting \0 at the end of the statement

    // returns the value(s) back
    return str;
}

void search_by_firstname(char* name);
// Prints out the person asked for in the list
void search_by_firstname(char* name) {
    // Intializations
    FILE* fptr;	//  pointer to file that will get created
    errno_t err;
    PERSON ppost; // PERSON class
    char firstname[20];

    // Asks for the user's input for the firstname to search the binary file 
    printf("Enter first name of person: ");
    scanf_s("\n%s", &firstname, 20);

    // Opens the binary file to read
    err = fopen_s(&fptr, "database.bin", "rb");
    int x;
    // If statement to make sure the binary file exists
    if (err == 0) {

        // While loop to iterate only if it reads correct char ( no null - empty space )
        while (fread(&ppost, sizeof(PERSON), 1, fptr)) {

            // Calling the trim function with the firstname
            trimString(ppost.firstname);
            x = strcmp(ppost.firstname, firstname);

            // If statement to make sure the user's first name input matches with the binary file content
            if (strcmp(ppost.firstname, firstname) == 0) {
                // Prints out the firstname record
                printf("Found first name : %s\n", ppost.firstname);
                printf("Found family name : %s", ppost.famname);
                printf("Found personal number : %s\n", ppost.pers_number);
            }
            //  printf("Failed %s", ppost.firstname);

        }
    }
    // Good practice to close the pointer to avoid data loss
    fclose(fptr);
}

void append_file(PERSON* inrecord);
// appends a new person's record to the binary file
void append_file(PERSON* inrecord) {

    // Intializations
    FILE* fptr;	//  pointer to file that will get created
    errno_t err;
    PERSON ppost; // PERSON class
    char firstname[20];
    char famname[20];
    char pernum[20];

    // Asks the user to input his firstname , family name and personal number
    printf("Add new person to database.\nFirst name: ");
    scanf_s("\n%s", &firstname, 20);

    printf("\nFamily name: ");
    scanf_s("\n%s", &famname, 20);

    printf("\nPersonal number: ");
    scanf_s("\n%s", &pernum, 20);


    // Opens the binary file to append ( add ) person's record
    err = fopen_s(&fptr, "C:\database.bin", "ab");

    // If statement to make sure the file exists
    if (err == 0)
    {
        printf("\nNew user has been added\n"); // when the user's record request is appended successfully
    }
    else
    {
        printf("\nThe file is not created\n");
    }

    //  Allocating the new person's record ( for firstname , famname and pers_number ) to the binary file
    char* newfirstname = malloc(strlen(firstname) + 2);
    strcpy_s(newfirstname, 20, firstname);
    // strcat to add empty line to look better
    strcat_s(newfirstname, 20, "\n");
    strncpy_s(ppost.firstname, MAX, newfirstname, 20);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);


    char* newfamname = malloc(strlen(famname) + 2);
    strcpy_s(newfamname, 20, famname);
    strcat_s(newfamname, 20, "\n");
    strncpy_s(ppost.famname, MAX, newfamname, 20);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);


    char* newpernum = malloc(strlen(pernum) + 2);
    strcpy_s(newpernum, 20, pernum);
    strcat_s(newpernum, 20, "\n");
    strncpy_s(ppost.pers_number, MAX, newpernum, 20);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    // Good practice to close the pointer to avoid data loss
    fclose(fptr);
}

// Main function where we call the other methods
int main(void) {
    // Initilizations
    int choice;
    // Display the Main program menu 
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

            // calls the fucntion ,creates a new binary file and delete the old one
            write_new_file(NULL);

        }
        else if (choice == 2) {

            // calls the fucntion ,add new person database to the binary file
            append_file(NULL);

        }
        else if (choice == 3) {

            // calls the fucntion , search by the first name of the person to show all persons info with that name
            search_by_firstname(NULL);

        }
        else if (choice == 4) {

            // calls the fucntion , displays the whole binary file content
            printfile();
        }
        else if (choice == 5) {
            // exits the system
            exit(0);
        }
        else {
            // breaks while loop if the user enters wrong input
            break;
        }
    }
    return(0);
}