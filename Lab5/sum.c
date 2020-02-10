#include <stdio.h>

//Write recursive function sum which adds up the first n numbers recursively

int sum(int n){
    //Fill in your code here
    if(n == 0){
        return n;
    }
    else{
        return n + sum(n-1);
    }
}

int main() {
    printf("Enter Number \n");
    int number;
    scanf("%d",&number);
    int result = sum(number);
    printf("Sum of first %d numbers is : %d",number,result);
    return 0;
}