//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <NAME>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name:
 * email address:
 * UTEID:
 * Section 5 digit ID:
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "life.h"


#if defined(_WIN32) || defined(_WIN64)
const char* os = "W";
#else
const char* os = "L";
#endif


int main(int argc, char *argv[]) {

    //edit these two lines and use the command line arguments
    printf("Number of command line arguments: %d \n", argc);
    for(int i = 0; i < argc; i++){
        printf("Argument %d: %s \n", i, argv[i]);
    }
    //char fName[] = "world.txt";
    char *fName = argv[1];
    const int numGenerations  = atoi(argv[2]); //set to a smaller number for debugging

    printf("The FileName is: %s \n", fName);


    //int * rowColHolder= getWorldSize(fName);
    //printf("rowColHolder is %d \n", rowColHolder[1]);


    const int MAX_ROWS = 80; //we want the world to fit on one screen

    //array of strings that will hold the grid
    char *world[MAX_ROWS];
    int numRows;
    int numCols;

    //  printf("The size of grid is: %d \n",  sizeof(* (world[0])) );
    populateWorld(fName, world, &numRows, &numCols);

    //  printf("Row is: %d || Col is: %d \n", numRows, numCols);

    showWorld(world, numRows, numCols);
    printf("Used show World \n");
    for (int iteration = 0; iteration < numGenerations; iteration++) {

        // code to clear screen goes here
//      if(os == "W"){
//        system("cls"); //Windows only
//      }
//      else{
//        system("clear"); //Linux only
//      }

        iterateGeneration(world, numRows, numCols);

        showWorld(world, numRows, numCols);
    }

    for(int i = 0; i < numRows; i++){
        free(world[i]);
    }
    //free(world);
    return 0;
}



