
#include "stack_ll.h"
#include <stdbool.h>
#include <stdio.h>

void createWorld(char fname[], char *world[], int MAX, int *rows, int *cols);
void showWorld(char *world[], int rows, int cols);
void promptUser(int *row, int *col, char *color);
// void updateWorld(char *world[], int row, int col, char color);

void makeStack(Stack312 *s) {
  s->top = NULL; 
}
void toStringEntry(StackEntry e){
  int row = e.row;
  int col = e.col;
  int color = e.color;
  printf("Node is Row: %d Col: %d Color: %c \n", row, col, color);
}

void toString(StackNode e){
  int row = e.pixel.row;
  int col = e.pixel.col;
  int color = e.pixel.color;
  StackNode *next = (e.next);
  printf("Next is: " );
  toString(*next);
  printf("Node is Row: %d Col: %d Color: %c  \n", row, col, color);
}

int equals(StackNode x, StackNode y) { //returns 1 if they are the same
  int xRow = x.pixel.row;
  int xCol = x.pixel.col;
  int yRow = y.pixel.row;
  int yCol = y.pixel.col;
  char xColor = x.pixel.color;
  char yColor = y.pixel.color;
  if (xRow == yRow) {
    if (xCol == yCol) {
      if (xColor == yColor) {
	return 1;
      }
    }
  }
  return -1;
}
int indexOf(Stack312 *s, StackNode e) { //returns 1 if found
  Stack312 *temp = s;
  StackNode *currNode = (temp->top);

  while (temp->top != NULL) {
    if (equals(*currNode, e) == 1) {  // checked if the pixels are the same
      return 1;
    }
    temp->top = (*currNode).next;
    currNode = (temp->top);
  }
  return 0;
}

bool isFull(Stack312 s) {
  if (s.top == NULL) {
    return false;
  } else {
    return true;
  }
}

bool isEmpty(Stack312 s) {
  if (s.top == NULL) {
    return true;
  } else {
    return false;
  }
}

void push(StackEntry e, Stack312 *s) {
  StackNode *oldTop = s -> top;
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  newNode->pixel = e;
  newNode->next = oldTop;
  s->top = newNode;
  
  
}

StackEntry pop(Stack312 *s) {
  StackEntry x;
  if (!isEmpty(*s)) {
    printf("Test point 3 \n");

    StackNode *poppedNode;
    poppedNode = (s->top);

    toString(*poppedNode);

    s->top = poppedNode->next;
    StackEntry temp = poppedNode->pixel;
    free(poppedNode);
    return temp;
  } else {
    x = (StackEntry){NULL};
    return x;  // Stack underflow
  }
}

void createWorld(char fname[], char *world[], int MAX, int *rows, int *cols) {
  FILE *worldFile = fopen(fname, "r");
  if (worldFile == NULL) {  // Do some error checking
    printf("ERROR \n");
    exit(0);
  }

  char temp[MAX];
  int numRows = 0;
  int numCols = 0;
  while (fgets(temp, MAX, worldFile)) {
    world[numRows] = (char *)malloc(strlen(temp) + 1);
    strcpy(world[numRows], temp);
    numRows++;
    numCols = strlen(temp) - 1;
  }
  *rows = numRows;
  *cols = numCols;
  // show world
  printf("Original World: \n");
  showWorld(world, numRows, numCols);
}

void showWorld(char *world[], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int userCol = 0; userCol < cols; userCol++) {
      // printf("Test point \n");
      printf("%c", world[i][userCol]);
    }
    printf("\n");
  }
}

void promptUser(int *row, int *col, char *color) { //TODO: ERROR HANDLING
  printf("Enter coordinates and color \n");

  printf("Row: \n");
  scanf("%d", row);
  // if(*row < 0 || *row > 24){

  // }

  printf("Col: \n");
  scanf("%d", col);

  printf("Color: \n");
  scanf(" %c", color);  // space needed before %c in order to clear STDIN
}


void checkNeighbors(char *world[], int rows, int cols, int userRow, int userCol, char color, Stack312 *s) {
  //Counter-clockwise from top left
  int newNeighborCounter = 0;


  if (world[userRow - 1][userCol - 1] == color) {  // top left
    StackEntry temp = {userRow - 1, userCol - 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      toStringEntry(temp);
      push(temp, s);
    }
	}
  printf("Test Point 1 \n");
	if (world[userRow - 1][userCol] == color) {  // top neighbor
	  StackEntry temp = {userRow - 1, userCol, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      printf("Test point 2 \n");
      newNeighborCounter++;
       toStringEntry(temp);
      push(temp, s);
    }
	}
	if (world[userRow - 1][userCol + 1] == color) {  // top right neighbor
	  StackEntry temp = {userRow - 1, userCol + 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
	if (world[userRow][userCol - 1] == color) {  // left neighbor
	  StackEntry temp = {userRow, userCol - 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
	if (world[userRow][userCol + 1] == color) {  // right neighbor
	  StackEntry temp = {userRow, userCol + 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
	if (world[userRow + 1][userCol - 1] == color) {  // bottom left corner
	  StackEntry temp = {userRow + 1, userCol - 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
	if (world[userRow + 1][userCol] == color) {  // bottom neighbor
	  StackEntry temp = {userRow + 1, userCol, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
	if (world[userRow + 1][userCol + 1] == color) {  // bottom right neighbor
	  StackEntry temp = {userRow + 1, userCol + 1, color};
    StackNode tempNode = {temp, NULL};
    if(indexOf(s, tempNode) != 1){
      newNeighborCounter++;
      push(temp, s);
    }
	}
  printf("New Neighbors = %d\n", newNeighborCounter);
}

void updateWorld(char *world[], int rows, int cols, int userRow, int userCol,
                 char color, Stack312 *s) {
    char oldColor = world[userRow][userCol];
    StackEntry first = {userRow, userCol, oldColor};
    StackNode firstNode = {first, NULL};
    int lastChar = rows - 1;
    int lastRow = cols - 1;

    if(userRow == 0 || userRow == lastRow){
        //checkForSpecialCases();
    }
    else if(userCol == 0 || userCol == lastChar){
        //checkForSpecialCases();
    }
    else{
        checkNeighbors(world, rows, cols, userRow, userCol, oldColor, s);
    }

    while(isFull(*s)){
        printf("Test point 4 \n");
        StackEntry popped = pop(s);
        //toStringEntry(popped);
        world[popped.row][popped.col] = color;
    }
}