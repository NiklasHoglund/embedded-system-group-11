#pragma warning(disable : 4996)
// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 1
// Submission code: 

#include <stdio.h> // print,scan and getchar
#include <stdlib.h>
#include <string.h> //used in the for loop to iterate through movement commands with strlen

int main(int argc, char* argv[])
{
    char engine_on, gear_pos, key_pos, brake1, brake2; // Char values used for printing

    char hexa[3] = { argv[1][0], argv[1][1] }, bin[9] = ""; // Char array hexa which holds the argument passed
                                                            // Char array bin to hold the binary number extracted from the hex number

    for (int i = 0; hexa[i] != '\0'; i++) // For loop which loops once for each character in the hex number
    {
        switch (hexa[i]) // Switch case used for converting the hex letters to binary. It concats the binary into the bin array
        {
        case '0':
            strcat(bin, "0000");
            break;
        case '1':
            strcat(bin, "0001");
            break;
        case '2':
            strcat(bin, "0010");
            break;
        case '3':
            strcat(bin, "0011");
            break;
        case '4':
            strcat(bin, "0100");
            break;
        case '5':
            strcat(bin, "0101");
            break;
        case '6':
            strcat(bin, "0110");
            break;
        case '7':
            strcat(bin, "0111");
            break;
        case '8':
            strcat(bin, "1000");
            break;
        case '9':
            strcat(bin, "1001");
            break;
        case 'a':
        case 'A':
            strcat(bin, "1010");
            break;
        case 'b':
        case 'B':
            strcat(bin, "1011");
            break;
        case 'c':
        case 'C':
            strcat(bin, "1100");
            break;
        case 'd':
        case 'D':
            strcat(bin, "1101");
            break;
        case 'e':
        case 'E':
            strcat(bin, "1110");
            break;
        case 'f':
        case 'F':
            strcat(bin, "1111");
            break;
        default:
            printf("Invalid hexadecimal input.");
        }
    }

    engine_on = bin[0]; // Set the engine_on variable to bin[0]

    if (bin[1] == '1') { // If statement for checking which bit out of the 3 is on for gear_pos
        gear_pos = '3';
    } else if (bin[2] == '1') {
        gear_pos = '2';
    }
    else if(bin[3] == '1') {
        gear_pos = '1';
    }
    else {
        gear_pos = '0';
    }
    
    if (bin[4] == '1') { // If statement for checking which bit out of the 2 is on for key_pos
        key_pos = '2';
    }
    else if (bin[5] == '1') {
        key_pos = '1';
    }
    else {
        key_pos = '0';
    }

    brake1 = bin[6]; // Set the brake1 variable to bin[6]
    brake2 = bin[7]; // Set the brake2 variable to bin[7]


    // Print the variables

    printf("\nengine_on: %c", engine_on);
    printf("\ngear_pos: %c", gear_pos);
    printf("\nkey_pos: %c", key_pos);
    printf("\nbrake1: %c", brake1);
    printf("\nbrake2: %c", brake2);

}

