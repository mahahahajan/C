// flood_fill.c
// EE 312

/* Student information for project:
 *
 * 
 *
 * On my honor, Sylvia Vu, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Sylvia Vu
 * email address: sylviavu@utexas.edu
 * UTEID: sav987
 * Section 5 digit ID: 16015
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void readFile (char fName[], char *grid[], int *numRows, int *numCols);

void printGrid(char *grid[], int numRows, int numCols);

void promptInput(char *grid[], int *row, int *col, char *newColor, char *oldColor);

void floodFill(char *grid[], int numRows, int numCols, char newColor, char oldColor, int row, int col);



int main(int argc, char *argv[]){

    char *fName = argv[1];

    const int MAX_ROWS = 25;

    char *grid[MAX_ROWS];
    int numRows;
    int numCols;
    char newColor;
    char oldColor;
    int row;
    int col;

    readFile(fName, grid, &numRows, &numCols);

    printGrid(grid, numRows, numCols);

    promptInput(grid, &row, &col, &newColor, &oldColor);

    floodFill(grid, numRows, numCols, newColor, oldColor, row, col);
    printGrid(grid, numRows, numCols);

}

void readFile (char fName[], char *grid[], int *numRows, int *numCols){

    *numRows = 0;
    *numCols = 0;

    FILE *fptr;
    fptr = fopen(fName, "r");

    if(fptr == NULL){
        printf("Unable to open file \n");
        exit(0);
    }

    else{
        char buf[BUFSIZ];

        while(fgets(buf, sizeof(buf), fptr)){
            *numCols = strlen(buf);
            *numCols = *numCols - 1;
            char *s = (char *) malloc(strlen(buf));
            strncpy(s, buf, *numCols);
            grid[*numRows] = s;
            (*numRows)++;
        }

        fclose(fptr);
    }
}

void printGrid(char *grid[], int numRows, int numCols){

    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void promptInput(char *grid[], int *row, int *col, char *newColor, char *oldColor){

    printf("Enter a row number: ");
    scanf("%d", row);
    printf("\n");
    if((*row < 0 && *row != -1) || *row > 24){
        printf("This is an invalid row number. Enter a number from 0 to 24: ");
        scanf("%d", row);
        printf("\n");
    }
    if(*row == -1)
        exit(0);

    printf("Enter a column number: ");
    scanf("%d", col);
    printf("\n");
    if((*col < 0 && *col != -1) || *col > 24){
        printf("This is an invalid column number. Enter a number from 0 to 24: ");
        scanf("%d", col);
        printf("\n");
    }
    if(*col == -1)
        exit(0);

    printf("Enter a color: ");
    scanf(" %c", newColor);
    printf("\n");

    *oldColor = grid[*row][*col];


}


void floodFill(char *grid[], int numRows, int numCols, char newColor, char oldColor, int row, int col){

    if(grid[row][col] == oldColor){
        
        grid[row][col] = newColor;

        /******* top-left corner *******/
        if(row == 0 && col == 0){

            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
        }

        /******* bottom-left corner *******/
        else if(row == numRows-1 && col == (numCols-1)){

            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
        }

        /******* top-right corner *******/
        else if(row == 0 && col == (numCols-1)){

            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
        }

        /******* bottom-right corner *******/
        else if(row == (numRows-1) && col == (numCols-1)){

            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
        }

        /******* left-most column *******/
        else if((row != 0 && row != numRows-1) && col == 0){
            
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
        }

        /******* right-most column *******/
        else if((row != 0 && row != (numRows-1)) && col == numCols-1){

            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
        }

        /******* top-most row *******/
        else if(row == 0 && (col != 0 && col != (numCols-1))){
            printf("TEST\n");
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
        }

        /******* bottom row *******/
        else if(row == numRows-1 && (col != 0 && col != numCols-1)){

            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
        }

        /******* all remaining cells (no cells on the border) *******/
        else{

            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col-1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col);
            floodFill(grid, numRows, numCols, newColor, oldColor, row+1, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row, col+1);
            floodFill(grid, numRows, numCols, newColor, oldColor, row-1, col+1);
        }
    }

    
}