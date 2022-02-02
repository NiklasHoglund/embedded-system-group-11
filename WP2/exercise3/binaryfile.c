// (C) Ahmed Yasser, Axel Broberg, Niklas H�glund , group: 11 (2022)
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
// PERSON input_record(void); // Reads a person�s record.

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
    
    strncpy_s(ppost.firstname, 6, "Matt\n", 5); // play around MAX
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, 9, "Murdock\n", 8);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, 14, "200010016475\n", 13);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    fclose(fptr);

    fptr = NULL;
}

void printfile(); // Prints out all persons in the file

void printfile() {
    FILE* fptr;	// file which we will create
    errno_t err;
    PERSON ppost;

    err = fopen_s(&fptr, "database.bin", "rb");
    if (err == 0) {
        
        while(fread(&ppost, sizeof(PERSON), 1, fptr) == 1) {
                printf("%s", ppost.firstname);
                printf("%s", ppost.famname);
                printf("%s", ppost.pers_number);

            }
    }
    else {
        printf("\n Can not open file");
        exit(1);
    }
    
    fclose(fptr);
}
 // link were we got ideas for this terminate string func : https://www.delftstack.com/howto/c/trim-string-in-c/
char* trimString(char* str)
{
    char* end; // Initialization

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)
        return str; // prints out normally

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // terminate the string char

    return str;
}

void search_by_firstname(char* name); // Prints out the person if // in list
void search_by_firstname(char* name) {
    FILE* fptr;	// file which we will create
    errno_t err;
    PERSON ppost;
    char firstname[20];

    printf("Enter first name of person: ");
    scanf_s("\n%s", &firstname, 20);

    err = fopen_s(&fptr, "database.bin", "rb");
    int x;

    if (err == 0) {

        while (fread(&ppost, sizeof(PERSON), 1, fptr)) {
            trimString(ppost.firstname);
            x = strcmp(ppost.firstname, firstname);

            if (strcmp(ppost.firstname, firstname) == 0) {
                printf("Found first name : %s\n", ppost.firstname);
                printf("Found family name : %s", ppost.famname);
                printf("Found personal number : %s\n", ppost.pers_number);
            }
          //  printf("Failed %s", ppost.firstname);

            
        }
    }



}


void append_file(PERSON* inrecord); // appends a new person to the file

void append_file(PERSON* inrecord) {
    errno_t err;
    PERSON ppost;
    FILE* fptr;

    char firstname[20];
    char famname[20];
    char pernum[20];

    printf("Add new person to database.\nFirst name: ");
    scanf_s("\n%s", &firstname, 20);

    printf("\nFamily name: ");
    scanf_s("\n%s", &famname, 20);

    printf("\nPersonal number: ");
    scanf_s("\n%s", &pernum, 20);


    // Open for read  
    err = fopen_s(&fptr, "C:\database.bin", "ab");
    if (err == 0)
    {
        printf("\nNew user has been added\n");
    }
    else
    {
        printf("\nThe file is not created\n");
    }

    char* newfirstname = malloc(strlen(firstname) + 2);
    strcpy_s(newfirstname, 20, firstname);
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