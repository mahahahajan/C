#include <stdbool.h>
#include <stdio.h>
#include "stack_ll.h"



const int MAX = 80;

void main(int argc, char *argv[]) {

    char *fName = argv[1];
    char *equation[MAX];
    int numRows = 0;

    //printf("HELLO WORLD \n");
    createEquation(fName, MAX, equation, &numRows);
    int counter = 0;
    Stack312 *myStack = (Stack312 *) malloc(sizeof(Stack312));
    makeStack(myStack);
    //printf("Rows is : %d \n", numRows);
    // printf("Original: \n");
    //showEquation(equation, 1);
    while(counter < numRows ){
        //DO STUFF
        parseEquation(equation, counter, myStack);
        counter++;
    }
}