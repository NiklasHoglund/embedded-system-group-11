// (C) Ahmed Yasser, Axel Broberg, Niklas Höglund , group: 11 (2022)
// Work package 2
// Exercise 1
// Submission code: 

#include <stdio.h> 
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
/* move:  means that the robot takes one step in the current direction. 
turn:  means that the robot turns 90 degrees clockwise. */

int main(int argc, char* argv[]) {
    ROBOT robot;
    char moveCommands[100]; 

    while (1) {
        robot.dir = 'N';
        printf("Add the x position you want to start with between %d - %d.\n", MIN_COORDINATE_START, MAX_COORDINATE_START);
        scanf_s("%d", &robot.xpos);
        printf("Add the y position you want to start with between %d - %d.\n", MIN_COORDINATE_START, MAX_COORDINATE_START);
        scanf_s("%d", &robot.ypos);
        printf("STARTING POSITION x:%d y:%d Facing %c\n", robot.xpos, robot.ypos, robot.dir);
        printf("How do you want your robot to move? Use m to move forward and t to turn.\n");
        scanf_s("%s", moveCommands, 100);
        movement(&robot, moveCommands);
    }
}

void move(ROBOT *robot) {
    if (robot->dir == 'N') {
        robot->xpos++; 
    }else if (robot->dir == 'E') {
        robot->ypos++; 
    }else if (robot->dir == 'S'){
        robot->xpos--;
    }else if (robot->dir == 'W') {
        robot->ypos--;
    }
}

void turn(ROBOT *robot) {
    
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

void movement(ROBOT *robot, char *moveCommands) {
    int i; 
    int length = strlen(moveCommands);
    for (i = 0; i<length ; i++) {
        if (moveCommands[i] == 'm') {
            printf("Moving forward from x:%d y:%d" ,robot->xpos, robot->ypos);
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