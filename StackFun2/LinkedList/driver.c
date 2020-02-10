
#include <stdbool.h>
#include <stdio.h>
#include "stack_ll.h"



const int MAX = 25;
int currMax = 0;

int main(int argc, char *argv[]) {
    int firstIteration = 0;

    char *world[MAX];
    char *fName = argv[1];
    int rows = 0;
    int cols = 0;
    createWorld(fName, world, MAX, &rows, &cols);
    //printf("Number of Rows: %d Cols: %d \n", rows, cols);
    int userRow = 0;
    int userCol = 0;
    char color = '0';
//    printf("\n TEST \n");
//    printf("\n");

    promptUser(&userRow, &userCol, &color);
    printf("Row: %d Col: %d Color: %c \n", userRow, userCol, color);

    Stack312 *myStack = (Stack312 *) malloc(sizeof(Stack312));
    makeStack(myStack);
    char oldColor = world[userRow][userCol];
//    printf("Made stack - ready to go \n");

    while (userRow != -1 && userCol != -1) {
        updateWorld(world, rows, cols, userRow, userCol, oldColor, color, myStack);
        showWorld(world, rows, cols);
        promptUser(&userRow, &userCol, &color);
        oldColor = world[userRow][userCol];
        //printf("Row: %d Col: %d Color: %c \n", userRow, userCol, color);
    }

    /**
     * TODO: STEPS
     * 1. create world
     * 3. ask user for a coordinate
     * 2. update world
     *
     * */
}

