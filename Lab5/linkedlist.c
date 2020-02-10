#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

//Write a recursive function which prints the LinkedList recursively
void printList(struct Node* head){
    if(head -> next == NULL){
        printf("Data of this node is: %d \n", (head -> data));
        printf("Done \n");
    }
    else{
        printf("Data of this node is: %d \n", (head -> data));
        printList(head->next);
    }
}


//Write a recursive function which prints the LinkedList in reverse order recursively
void printReverseList(struct Node* head){
    if(head -> next == NULL){
        printf("Data of this node is: %d \n", (head -> data));
        return;
    }
    else{
        printReverseList(head->next);
        printf("Data of this node is: %d \n", (head -> data));
        
    }
}

int main( )
{
    struct Node nodes[10];
    for(int i = 0; i < 9 ; i++){
        nodes[i].data = i;
        nodes[i].next = &nodes[i+1];
    }

    nodes[9].data = 9;
    nodes[9].next = NULL;

    printList(&nodes[0]);
    printReverseList(&nodes[0]);
    return 0;
}
