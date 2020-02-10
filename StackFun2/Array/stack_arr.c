#include "stack_arr.h"
#include <stdbool.h>
#include <stdio.h>


char openDictionary[] = {'(', '[', '<'};
char closeDictionary[] = {')', ']', '>'};

void makeStack(Stack312 *s) { s->top = -1; }

bool isFull(Stack312 s) {
    if (s.top == (MAX_ELEMENTS - 1)) {
        return true;
    }
    return false;
}

bool isEmpty(Stack312 s) {
    if (s.top == -1) {
        return true;
    }
    return false;
}

void push(StackEntry e, Stack312 *s) {
    int i = s->top;
    i++;
    s->elements[i] = e;

    s->top = i;
}

StackEntry pop(Stack312 *s) {
    int i = s->top;
    StackEntry value = s->elements[i];
    s->elements[i] = NULL;
    i--;
    s->top = i;
    return value;
}
//Read file and get all equations - put them into 2D array
void createEquation(char fname[], int MAX, char *equation[], int *numRows) {
    FILE *worldFile = fopen(fname, "r");
    if (worldFile == NULL) {  // Do some error checking
        printf("ERROR \n");
        exit(0);
    }
    char temp[MAX];
    int rows = 0;
    int cols = 0;
    while (fgets(temp, MAX, worldFile)) {
        equation[rows] = (char *)malloc(strlen(temp) + 1);
        strcpy(equation[rows], temp);
        rows++;

        //*length = strlen(temp) - 1;
    }
    *numRows = rows;
}
//print out equations based on location in 2d Array
void showEquation(char *equation[], int numRow) {
   for (int i = 0; i < strlen(equation[numRow]) ; i++) {
       if(equation[numRow][i] != '\n'){
           printf("%c", equation[numRow][i]);
       }
       
   }
}
//check against a dictionary of values 
//return the index of said character in the dictionary
//, or return -1 if not found
int checkDictionary(char dictionary[], char element){
    for(int i = 0; i < 3; i++){
        if(element == dictionary[i]){
            return i;
        }
    }
    return -1;
}
//Go through equation character by character
//while looking at opening ones -> push to stack
//while looking at closing, pop from stack
//see if they have same position in dictionary - if they match
//then we're good. Else equation is not valid
void parseEquation(char *equation[], int numRow, Stack312 *s) {
    int gotAnswer = 0;
    for (int i = 0; i < strlen(equation[numRow]) ; i++) {
        char currChar = equation[numRow][i];
        if(checkDictionary(openDictionary, currChar) != -1){
            //This is an open character
            StackEntry e = (StackEntry ) currChar;
            push(e, s);
        }
        if(checkDictionary(closeDictionary, currChar) != -1){
            //This is an close character
            StackEntry e = currChar;
            char lastOpen = pop(s);
            int openPosition = checkDictionary(openDictionary, lastOpen);
            int closePosition = checkDictionary(closeDictionary, currChar);
            if(openPosition != closePosition){
                showEquation(equation, numRow);
                printf("=== missing %c \n", closeDictionary[openPosition]);
                gotAnswer = 1;
            }
        }
    }
    if(!isEmpty(*s)){

        if(gotAnswer == 0){
            char lastOpen = pop(s);
            int openPosition = checkDictionary(openDictionary, lastOpen);
            showEquation(equation, numRow) ;
            printf(" === missing %c \n",closeDictionary[openPosition]);
        }
        
    }
    else{
        if(gotAnswer == 0){
            showEquation(equation, numRow);
        printf(" === valid expression \n");
        }
        
    }
}

