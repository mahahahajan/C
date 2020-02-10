#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "life.h"

void seedStatus(char *grid[], char *tempGrid[], int i, int j, int neighborCounter);
void checkForSpecialCases(char *grid[], char *tempGrid[], int i, int j, int numRows, int numCols);

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    int rows, cols, reachedEndFlag = 0;
    FILE *worldFile = fopen(fname, "r");
    if (worldFile != NULL) {
        printf("OPENED \n");
    } else {
        printf("ERROR \n");
    }
    int numEndFlags = 0;
    char ch = fgetc(worldFile);
    while (ch != EOF) {
        if (ch == '\n') {
            rows++;
            reachedEndFlag = 1;
            numEndFlags++;
        }
        if (reachedEndFlag == 0) {
            cols++;
        }
        ch = fgetc(worldFile);
    }
    // printf("Number of end lines: %d \n", numEndFlags);

    printf("Rows is: %d || cols is: %d \n", rows, cols);


    for (int i = 0; i < rows; i++) {
        printf("Iteration number: %d \n", i);
        grid[i] = (char *) malloc(cols * sizeof(char));
    }
    *numRows = rows;
    *numCols = cols;
    fclose(worldFile);
    worldFile = fopen(fname, "r");

    ch = fgetc(worldFile);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols; j++) {
            if (ch != '\n') {
                grid[i][j] = ch;
            }
            ch = fgetc(worldFile);
        }
    }
    fclose(worldFile);
}

void showWorld(char *grid[], int numRows, int numCols) {
    // printf("Number of rows is: %d || Number of cols is: %d \n", numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            char ch = grid[i][j];
            if (ch == '0') {
                ch = '.';
            }
            if (ch == '1') {
                ch = '*';
            }
            printf("%c", ch);
        }
        printf("\n");
    }
    printf("\n");
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    char *tempGrid[numRows];

    int neighborCounter = 0;
    int lastChar = numCols - 1;
    int lastRow = numRows - 1;
    /**
     *
     * 1. Check for corners
     * 2. Check for edges
     * 3. check others
     *
     * */
    for (int i = 0; i < numRows; i++) {
        tempGrid[i] = (char *) malloc(numCols * sizeof(char));
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if(i == 0 || i == lastRow || j == 0 || j == lastChar){
                checkForSpecialCases(grid, tempGrid, i, j, numRows, numCols);
            }
            else{
                if (grid[i - 1][j - 1] == '1') { // top left
                    neighborCounter++;
                }
                if (grid[i - 1][j] == '1') { // top neighbor
                    neighborCounter++;
                }
                if (grid[i - 1][j + 1] == '1') { // top right neighbor
                    neighborCounter++;
                }
                if (grid[i][j - 1] == '1') { //left neighbor
                    neighborCounter++;
                }
                if (grid[i][j + 1] == '1') { //right neighbor
                    neighborCounter++;
                }
                if (grid[i + 1][j - 1] == '1') { // bottom left corner
                    neighborCounter++;
                }
                if (grid[i + 1][j] == '1') { // bottom neighbor
                    neighborCounter++;
                }
                if (grid[i + 1][j + 1] == '1') { // bottom right neighbor
                    neighborCounter++;
                }
                seedStatus(grid, tempGrid, i, j, neighborCounter);
                neighborCounter = 0;
            }
        }
    }

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            // printf("Changing grid pls hold \n");
            grid[i][j] = tempGrid[i][j];
        }
    }
    // printf("This is temp grid: \n");
    // showWorld(tempGrid, numRows, numCols);
    //  printf("This is world grid: \n");
    // showWorld(grid, numRows, numCols);

    for(int i = 0; i < numRows; i++){
        free(tempGrid[i]);
    }
    //free(tempGrid);
}

void checkForSpecialCases(char *grid[], char *tempGrid[], int i, int j, int numRows, int numCols) {
    int neighborCounter = 0;
    int lastChar = numCols - 1;
    int lastRow = numRows - 1;
    if (i == 0) {    // top row
        if (j == 0) {  // top left corner
            if (grid[0][1] == '1') {
                neighborCounter++;
            }
            if (grid[1][0] == '1') {
                neighborCounter++;
            }
            if (grid[1][1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        } else if (j == lastChar) { //top right corner
            if (grid[0][lastChar - 1] == '1') {
                neighborCounter++;
            }
            if (grid[1][lastChar] == '1') {
                neighborCounter++;
            }
            if (grid[1][lastChar - 1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        } else { //topRow stuff
            if (grid[i][j - 1] == '1') {
                neighborCounter++;
            }
            if (grid[i][j + 1] == '1') {
                neighborCounter++;
            }
            if (grid[i + 1][j - 1] == '1') {
                neighborCounter++;
            }
            if (grid[i + 1][j] == '1') {
                neighborCounter++;
            }
            if (grid[i + 1][j + 1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        }
    }
    else if(i == lastRow){ //bottom row
        if (j == 0) {  // bottom left corner
            if (grid[lastRow][1] == '1') {
                neighborCounter++;
            }
            if (grid[lastRow-1][0] == '1') {
                neighborCounter++;
            }
            if (grid[lastRow-1][1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        } else if (j == lastChar) { //bottom right corner
            if (grid[lastRow][lastChar - 1] == '1') {
                neighborCounter++;
            }
            if (grid[lastRow - 1][lastChar] == '1') {
                neighborCounter++;
            }
            if (grid[lastRow - 1][lastChar - 1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        } else { //bottomRow stuff
            if (grid[i][j - 1] == '1') {
                neighborCounter++;
            }
            if (grid[i][j + 1] == '1') {
                neighborCounter++;
            }
            if (grid[i - 1][j - 1] == '1') {
                neighborCounter++;
            }
            if (grid[i - 1][j] == '1') {
                neighborCounter++;
            }
            if (grid[i - 1][j + 1] == '1') {
                neighborCounter++;
            }
            seedStatus(grid, tempGrid, i, j, neighborCounter);
            neighborCounter = 0;
        }
    }
    else if(j == 0){ // left column
        if(grid[i-1][j] == '1'){
            neighborCounter++;
        }
        if(grid[i-1][j+1] == '1'){ // top right neighbor
            neighborCounter++;
        }
        if(grid[i][j+1] == '1'){ // right neighbor
            neighborCounter++;
        }
        if(grid[i+1][j+1] == '1'){ // bottom right neighbor
            neighborCounter++;
        }
        if(grid[i+1][j] == '1'){
            neighborCounter++;
        }
        seedStatus(grid, tempGrid, i, j, neighborCounter);
        neighborCounter = 0;
    }
    else if(j == lastChar){
        if(grid[i-1][j] == '1'){
            neighborCounter++;
        }
        if(grid[i-1][j-1] == '1'){ // top left neighbor
            neighborCounter++;
        }
        if(grid[i][j-1] == '1'){ // left neighbor
            neighborCounter++;
        }
        if(grid[i+1][j-1] == '1'){ // left right neighbor
            neighborCounter++;
        }
        if(grid[i+1][j] == '1'){
            neighborCounter++;
        }
        seedStatus(grid, tempGrid, i, j, neighborCounter);
        neighborCounter = 0;
    }
}


void seedStatus(char *grid[], char *tempGrid[], int i, int j, int neighborCounter) {
    if (neighborCounter == 0 || neighborCounter == 1 || neighborCounter >= 4) {
        // Seed dies

        // printf("This is a test to see if a seed dies \n");
        tempGrid[i][j] = '0';

    } else if (neighborCounter == 3 && grid[i][j] == '0') {
        // Seed stays alive
        // printf("This is a test to see if a seed lives \n");
        tempGrid[i][j] = '1';
    }
    else{
        tempGrid[i][j] = tempGrid[i][j];
    }
}