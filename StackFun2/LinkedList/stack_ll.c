
#include "stack_ll.h"
#include <stdbool.h>
#include <stdio.h>

void createWorld(char fname[], char *world[], int MAX, int *rows, int *cols);

void showWorld(char *world[], int rows, int cols);

void promptUser(int *row, int *col, char *color);

void checkNeighbors(char *world[], int rows, int cols, int userRow, int userCol, char color, Stack312 *s);

void checkSpecialCases(char *world[], int rows, int cols, int userRow, int userCol, char color, Stack312 *s);
// void updateWorld(char *world[], int row, int col, char color);

int foundNeighbors = 0;

void makeStack(Stack312 *s) {
    s->top = NULL;
}

void toStringEntry(StackEntry e) {
    int row = e.row;
    int col = e.col;
    int color = e.color;
//    printf("Node is Row: %d Col: %d Color: %c \n", row, col, color);
}

void toString(StackNode e) {
    int row = e.pixel.row;
    int col = e.pixel.col;
    int color = e.pixel.color;

//    printf("Node is Row: %d Col: %d Color: %c  \n", row, col, color);
}
//compare 2 nodes to make sure coordinates are same
int equals(StackNode x, StackNode y) { //returns 1 if they are the same
    int xRow = x.pixel.row;
    int xCol = x.pixel.col;
    int yRow = y.pixel.row;
    int yCol = y.pixel.col;

    if (xRow == yRow) {
        if (xCol == yCol) {

                return 1;

        }
    }
    return -1;
}
//see if node exists in stack already
int indexOf(Stack312 *s, StackNode e) { //returns 1 if found
    Stack312 *temp = s;
    if (!isEmpty(*s)) {
        StackNode *currNode = (temp->top);
        StackNode tempNode = *currNode;
        while (tempNode.next != NULL) {
            if(tempNode.pixel.row == 0 && tempNode.pixel.col == 6){
                printf("test \n");
            }
            if (equals(tempNode, e) == 1) {  // checked if the pixels are the same
                return 1;
            }

            tempNode = *(tempNode).next;

        }
        if (equals(tempNode, e) == 1) {  // checked if the pixels are the same
            return 1;
        }
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
    StackNode *oldTop = s->top;
    StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
    newNode->pixel = e;
    newNode->next = oldTop;
    (s->top) = newNode;


}

StackEntry pop(Stack312 *s) {
    StackEntry x;
    if (!isEmpty(*s)) {
//        printf("Test point 3 \n");

        StackNode *poppedNode;
        poppedNode = (s->top);


        s->top = poppedNode->next;
        StackEntry temp = poppedNode->pixel;
        free(poppedNode);
        return temp;
    } else {
        x = (StackEntry) {NULL};
        return x;  // Stack underflow
    }
}
//create World by reading in file 
void createWorld(char fname[], char *world[], int MAX, int *rows, int *cols) {
    FILE *worldFile = fopen(fname, "r");
    if (worldFile == NULL) {  // Do some error checking
//        printf("ERROR \n");
        exit(0);
    }

    char temp[MAX];
    int numRows = 0;
    int numCols = 0;
    while (fgets(temp, MAX, worldFile)) {
        world[numRows] = (char *) malloc(strlen(temp) + 1);
        strcpy(world[numRows], temp);
        numRows++;
        numCols = strlen(temp) - 1;
    }
    *rows = numRows;
    *cols = numCols;
    // show world
//    printf("Original World: \n");
    showWorld(world, numRows, numCols);
}
//print world
void showWorld(char *world[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int userCol = 0; userCol < cols; userCol++) {
//             printf("Test point \n");
            printf("%c", world[i][userCol]);
        }
        printf("\n");
    }
}
//prompt user for input about which row and col to be changed
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
//update world based on old color and color to be replaced
void updateWorld(char *world[], int rows, int cols, int userRow, int userCol, char oldColor, char colorToReplace, Stack312* s) {

    StackEntry first = {userRow, userCol, oldColor};
    StackNode firstNode = {first, NULL};

    if (world[userRow][userCol] == oldColor) {
        if (indexOf(s, firstNode) != 1) {
            push(first, s);
            world[userRow][userCol] = colorToReplace;
        }
    }

    int lastChar = rows - 1;
    int lastRow = cols - 1;

    if (userRow == 0 || userRow == lastRow) {
        checkSpecialCases(world, rows, cols, userRow, userCol, oldColor, s);
    } else if (userCol == 0 || userCol == lastChar) {
        checkSpecialCases(world, rows, cols, userRow, userCol, oldColor, s);
    } else {
        checkNeighbors(world, rows, cols, userRow, userCol, oldColor, s);
    }
//    if (!isEmpty(*s)) {
//        StackNode *currNode = (s->top);
//        StackNode tempNode = *currNode;
//        while (tempNode.next != NULL) {
//            world[tempNode.pixel.row][tempNode.pixel.col] = colorToReplace;
//            tempNode = *(tempNode).next;
//        }
//    }

    StackNode *currNode = (s->top);
    StackNode tempNode;
    if(currNode != NULL){
        tempNode = *currNode;
        while (tempNode.next != NULL) {
            world[tempNode.pixel.row][tempNode.pixel.col] = colorToReplace;
            tempNode = *(tempNode).next;
        }
    }


    while (isFull(*s)) {
//        printf("Test point 4 \n");
        StackEntry popped = pop(s);
        //world[popped.row][popped.col] = colorToReplace;
        updateWorld( world, rows, cols, popped.row, popped.col, oldColor, colorToReplace, s);
        //toStringEntry(popped);

    }
}
//checking against neighbors
void checkNeighbors(char *world[], int rows, int cols, int userRow, int userCol, char color, Stack312 *s) {
    //Counter-clockwise from top left
    int newNeighborCounter = 0;


    if (world[userRow - 1][userCol - 1] == color) {  // top left
        StackEntry temp = {userRow - 1, userCol - 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            toStringEntry(temp);
            push(temp, s);
        }
    }

    if (world[userRow - 1][userCol] == color) {  // top neighbor
        StackEntry temp = {userRow - 1, userCol, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            toStringEntry(temp);
            push(temp, s);
        }
    }
    if (world[userRow - 1][userCol + 1] == color) {  // top right neighbor
        StackEntry temp = {userRow - 1, userCol + 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if (world[userRow][userCol - 1] == color) {  // left neighbor
        StackEntry temp = {userRow, userCol - 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if (world[userRow][userCol + 1] == color) {  // right neighbor
        StackEntry temp = {userRow, userCol + 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if (world[userRow + 1][userCol - 1] == color) {  // bottom left

        StackEntry temp = {userRow + 1, userCol - 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if (world[userRow + 1][userCol] == color) {  // bottom neighbor
        StackEntry temp = {userRow + 1, userCol, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if (world[userRow + 1][userCol + 1] == color) {  // bottom right neighbor
        StackEntry temp = {userRow + 1, userCol + 1, color};
        StackNode tempNode = {temp, NULL};
        if (indexOf(s, tempNode) != 1) {
            newNeighborCounter++;
            push(temp, s);
        }
    }
    if(newNeighborCounter > 0 ){
        foundNeighbors  = 1;
    }
    //printf("New Neighbors = %d\n", newNeighborCounter);
}
//check against special cases
void checkSpecialCases(char *world[], int rows, int cols, int userRow, int userCol, char color, Stack312 *s) {

    int neighborCounter = 0;
    int lastChar = cols - 1;
    int lastRow = rows - 1;
    if (userRow == 0) {    // top row
        if (userCol == 0) {  // top left corner
            if (world[0][1] == color) { //right neighbor
                StackEntry temp = {0, 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }

            }
            if (world[1][0] == color) { //bottom neigbor
                StackEntry temp = {1, 0, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }

            }
            if (world[1][1] == color) { //bottom right neighbor
                StackEntry temp = {1, 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }

            }
        } else if (userCol == lastChar) { //top right corner
            if (world[0][lastChar - 1] == color) {
                StackEntry temp = {0, lastChar - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }

            }
            if (world[1][lastChar] == color) {
                StackEntry temp = {1, lastChar, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[1][lastChar - 1] == color) {
                StackEntry temp = {1, lastChar - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }

            neighborCounter = 0;
        } else { //topRow stuff
            if (world[userRow][userCol - 1] == color) { //left
                StackEntry temp = {userRow, userCol - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    //toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow][userCol + 1] == color) { //right
                StackEntry temp = {userRow, userCol +1 , color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow + 1][userCol - 1] == color) { //bottom left
                StackEntry temp = {userRow + 1,userCol-1 , color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow + 1][userCol] == color) { // bottom
                StackEntry temp = {userRow + 1, userCol, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow + 1][userCol + 1] == color) { //bottom right
                StackEntry temp = {userRow + 1, userCol + 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
        }
    } else if (userRow == lastRow) { //bottom row
        if (userCol == 0) {  // bottom left corner
            if (world[lastRow][1] == color) {
                StackEntry temp = {lastRow, 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[lastRow - 1][0] == color) {
                StackEntry temp = {lastRow -1, 0, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[lastRow - 1][1] == color) {
                StackEntry temp = {lastRow - 1, 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
        } else if (userCol == lastChar) { //bottom right corner
            if (world[lastRow][lastChar - 1] == color) {
                StackEntry temp = {lastRow, lastChar - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[lastRow - 1][lastChar] == color) {
                StackEntry temp = {lastRow - 1, lastChar, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[lastRow - 1][lastChar - 1] == color) {
                StackEntry temp = {lastRow - 1, lastChar - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
        } else { //bottomRow stuff
            if (world[userRow][userCol - 1] == color) {  //left neigbor
                StackEntry temp = {userRow, userCol - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow][userCol + 1] == color) { //right neigbor
                StackEntry temp = {userRow, userCol +1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow - 1][userCol - 1] == color) { //top left neighbor
                StackEntry temp = {userRow - 1, userCol - 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow - 1][userCol] == color) { // top  neighbor
                StackEntry temp = {userRow - 1, userCol, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
            if (world[userRow - 1][userCol + 1] == color) { //top right neighbor
                StackEntry temp = {userRow - 1, userCol + 1, color};
                StackNode tempNode = {temp, NULL};
                if (indexOf(s, tempNode) != 1) {
                    neighborCounter++;
                    toStringEntry(temp);
                    push(temp, s);
                }
            }
        }
    } else if (userCol == 0) { // left column
        if (world[userRow - 1][userCol] == color) { //top neighbor
            StackEntry temp = {userRow -1 , userCol, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow - 1][userCol + 1] == color) { // top right neighbor
            StackEntry temp = {userRow -1 , userCol+1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow][userCol + 1] == color) { // right neighbor
            StackEntry temp = {userRow  , userCol+1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow + 1][userCol + 1] == color) { // bottom right neighbor
            StackEntry temp = {userRow +1 , userCol + 1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow + 1][userCol] == color) { //bottom neighbor
            StackEntry temp = {userRow + 1 , userCol, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }

        neighborCounter = 0;
    } else if (userCol == lastChar) {
        if (world[userRow - 1][userCol] == color) { //top neighbor
            StackEntry temp = {userRow -1 , userCol, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow - 1][userCol - 1] == color) { // top left neighbor
            StackEntry temp = {userRow -1 , userCol - 1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow][userCol - 1] == color) { // left neighbor
            StackEntry temp = {userRow , userCol - 1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow + 1][userCol - 1] == color) { // left right neighbor
            StackEntry temp = {userRow + 1 , userCol - 1, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }
        if (world[userRow + 1][userCol] == color) { // Bottom neighbor
            StackEntry temp = {userRow + 1 , userCol, color};
            StackNode tempNode = {temp, NULL};
            if (indexOf(s, tempNode) != 1) {
                neighborCounter++;
                toStringEntry(temp);
                push(temp, s);
            }
        }

    }
    if(neighborCounter > 0){
        foundNeighbors = 1;
    }
}