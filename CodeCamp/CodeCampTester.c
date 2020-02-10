#include <stdio.h>
#include <stdbool.h>

// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Pulkit Mahajan
 * email address: pmahajan@utexas.edu
 * UTEID: pm28838
 * Section 5 digit ID: 16015
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num);
//****************************

int main()
{
   printf("\n"); //Put this to format my output a little nicer on my terminal

   //Custom Test 1 - hamming distance
   int testArray1[] = {2, 4, 8, 16, 32, 64, 128, 256, 512};
   int testArray2[] = {2, 4, 8, 16, 321, 64, 128, 256, 512};
   int expected = 1;
   int actual = hammingDistance(testArray1, testArray2, 9);
   printf("Custom Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 1, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 1, hamming distance\n\n");

   //Custom Test 2 - hamming distance
   int testArray3[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
   int testArray4[] = {1, 2, 3, 15, 8, 13, 12, 34, 55, 89};
   expected = 2;
   actual = hammingDistance(testArray3, testArray4, 10);
   printf("Custom Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 2, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 2, hamming distance\n\n");

   //Custom Test 3 - Last Digit
   int testNum1 = 351;
   int testNum2 = 11;
   expected = true;
   actual = lastDigit(testNum1, testNum2);
   printf("Custom Test 3 last digit: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 3, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 3, hamming distance\n\n");

   //Custom Test 4 - Last Digit
   int testNum3 = 38;
   int testNum4 = 10008;
   expected = true;
   actual = lastDigit(testNum3, testNum4);
   printf("Custom Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 4, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 4, hamming distance\n\n");

   //Custom Test 5 - Last Digit
   int testNum5 = 38;
   int testNum6 = 10009;
   expected = false;
   actual = lastDigit(testNum5, testNum6);
   printf("Custom Test 5 last digit: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 5, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 5, hamming distance\n\n");

   printf("--------------------------------------------------------------------------------\n");
   // test 7, sum of multiples of 3 or 5
   //Didn't touch this test case
   expected = 233168;
   actual = sum3or5Multiples();
   printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("passed test 7, sum of multiples of 3 or 5\n\n");
   else
      printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

   printf("--------------------------------------------------------------------------------\n"); 
   printf("\n");  

   //Custom Test 6 - reverse int
   int reverseNum1 = 42; // answer to the universe
   expected = 24;
   actual = reverseInt(reverseNum1);
   printf("Custom Test 6 reverse int: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 6, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 6, hamming distance\n\n");

  

   //Custom Test 7 - reverse int
   reverseNum1 = 11; // answer to the universe
   expected = 11;
   actual = reverseInt(reverseNum1);
   printf("Custom Test 7 reverse int: expected value: %d, actual value: %d\n", expected, actual);

   if (expected == actual)
      printf("---- PASSED ---- Custom Test 7, hamming distance\n\n");
   else
      printf("**** FAILED **** Custom Test 7, hamming distance\n\n");

}
