// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 1
// Submission code: 

#include <stdio.h> // print,scan and getchar
#include <string.h> //used in the for loop to iterate through movement commands with strlen

#define MIN_COORDINATE_START 0
#define MAX_COORDINATE_START 99

enum DIRECTION { N, E, S, W };

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *);
void turn(ROBOT *); 
void movement(ROBOT *, char *);

int main(int argc, char* argv[]) {
    ROBOT robot;
    char moveCommands[100];
    char quit; 
    while (1) {                                             /*When the user input Q before an iteration of the program the loop breaks and it exits*/
        printf("To quit the robot program enter: Q\nTo execute the program hit enter on your keyboard.");
        quit = getchar();                                   /*Wait for user input if they want to quit or steer the robot*/

        if (quit == 'Q') {                                  /*When the user wants exit the program we break the loop to quit the program any other input the program executes*/
               break;
        }else{
            robot.dir = 'N';                                /*Sets the robot starting position facing north and asks questions about starting position on a X-Y axis between the startubg values 0-99 for x and y*/
            printf("Add the x position you want to start with between %d - %d.\n", MIN_COORDINATE_START, MAX_COORDINATE_START);
            scanf_s("%d", &robot.xpos);
            printf("Add the y position you want to start with between %d - %d.\n", MIN_COORDINATE_START, MAX_COORDINATE_START);
            scanf_s("%d", &robot.ypos);
            printf("STARTING POSITION x:%d y:%d Facing %c\n", robot.xpos, robot.ypos, robot.dir);
            printf("How do you want your robot to move? Use m to move forward and t to turn.\n");
            scanf_s("%s", moveCommands, 100);
            movement(&robot, moveCommands);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);    /*When we hit enter in the first getchar to see if we want to quit or exercute the program it creates a \n in the buffer so we need this 
                                                            while to clear the buffer so that it does not skip the user input when asking the question about quiting or running the program*/
        }
    }
    return 0; 
}


void move(ROBOT *robot) {                                   /*Moving Function. Increments the x or y axis value based on current axis position and what direction the robot is facing so that it can move */
    if (robot->dir == 'N') {
        robot->ypos++; 
    }else if (robot->dir == 'E') {
        robot->xpos++; 
    }else if (robot->dir == 'S'){
        robot->ypos--;
    }else if (robot->dir == 'W') {
        robot->xpos--;
    }
}

void turn(ROBOT *robot) {                                   /*Turning Function. Changes to the direction 90 degrees to its right based on the direction the robot is currently facing if the function is 
                                                            called from the movement function.*/
    if (robot->dir == 'N') {
        robot->dir = 'E';
    }else if (robot->dir == 'E'){
        robot->dir = 'S';
    }else if (robot->dir == 'S'){
        robot->dir = 'W';
    }else if (robot->dir == 'W'){
        robot->dir = 'N';
    }
}

void movement(ROBOT *robot, char *moveCommands) {           /*Movement Function. Decides what to do based on every character it encounters in the char string received from the user at the start of the 
                                                            program how they want the robot to move from its starting position. For loop to go through every character in the moveCommands string */
    int i; 
    int length = strlen(moveCommands);
    for (i = 0; i<length ; i++) {
        if (moveCommands[i] == 'm') {
            printf("Moving from x:%d y:%d" ,robot->xpos, robot->ypos);
            move(robot, moveCommands); 
            printf(" to x:%d y:%d \n", robot->xpos, robot->ypos);
        }else if(moveCommands[i] == 't') {
            turn(robot, moveCommands); 
            printf("Turned to %c\n", robot->dir);
        }
        else {
            printf("Wrong Input Robot Ignoring Command\n");
        }
    }
}