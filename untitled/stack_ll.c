#include "stack_ll.h"
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

char* showEquation(char *equation[], int numRow) {
//    for (int i = 0; i < strlen(equation[numRow]) - 1; i++) {
//        printf("%c", equation[numRow][i]);
//    }

    return equation[numRow];
    printf("\n");
}

int checkDictionary(char dictionary[], char element){
    for(int i = 0; i < 3; i++){
        if(element == dictionary[i]){
            return i;
        }
    }
    return -1;
}

void parseEquation(char *equation[], int numRow, Stack312 *s) {
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
                printf("%s  === missing %c \n", showEquation(equation, numRow), closeDictionary[openPosition]);
            }
        }
    }
    if(!isEmpty(*s)){
        char lastOpen = pop(s);
        int openPosition = checkDictionary(openDictionary, lastOpen);

        printf("%s === missing %c \n", showEquation(equation, numRow) ,closeDictionary[openPosition]);
    }
    else{
        printf("%s === valid \n", showEquation(equation, numRow));
    }
}

