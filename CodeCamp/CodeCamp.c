#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Pulkit Mahajan, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Pulkit Mahajan
 * email address: pmahajan@utexas.edu
 * UTEID: pm28838
 * Section 5 digit ID:
 * 16015
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
  int hammingDist = 0;
  // EE 312 Students: put your code here
  for(int i = 0; i < len; i++){
    if(aList[i] != bList[i]){ 
      hammingDist++;
    }
  }
  return hammingDist;
}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
  bool sameDigit = false;
  int lastDigit1 = abs(num1 % 10);
  int lastDigit2 = abs(num2 % 10);
  if(lastDigit1 == lastDigit2){
    sameDigit = true;
  }
  else{
    sameDigit = false;
  }
  return sameDigit;
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
  int sum = 0;
  // EE 312 Students: put your code here
  for(int i = 0; i < 1000; i++){
    if(i % 5 == 0){
      sum += i;
    }
    else if(i % 3 == 0){
      sum += i;
    }
    else{
      //do nothing
    }
  }
  return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
  int multiplier = 10;
  long newNumLong = 0;
  while(num != 0){
    int digit = num % 10;
    num /= 10; 
    //Formula - take the current number and multiply by 10 (eg. 24 * 10 = 240). Then add the new digit (eg. 240 + 1 = 241).
    newNumLong = (newNumLong * multiplier) + digit; 
  }
  //Cast long into an int and compare - if they're the same then the number is reversible. If not - return 0.
  int newNum = (int) newNumLong;
  if(newNum != newNumLong){
    newNum = 0;
  }
  return newNum;
}

  

