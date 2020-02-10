#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//Write a function which checks if given string is palindrome or not recursively
//returns true if its a palindrome and false if its not.

bool palindrome(char word[], int start, int end)
{
	// printf("%s \n", word);
	// printf("Word start is: %c ", word[start]);
	// printf(" | Word end is: %c \n", word[end - 1]);
	if (start <= end)
	{
		if (word[start] == word[end - 1])
		{
			return palindrome(word, start + 1, end - 1);
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	char wordPal[25];
	printf("\n\n Recursion : Check a given string is Palindrome or not :\n");
	printf("----------------------------------------------------------\n");

	printf(" Input  a word to check for palindrome : ");
	scanf("%s", wordPal);
	bool result;
	int end;
	end = strlen(wordPal);
	//call the function
	result = palindrome(wordPal, 0, end);
	if (result)
	{
		printf("%s is a Palindrome \n", wordPal);
	}
	else
	{
		printf("%s is not a Palindrome \n", wordPal);
	}

	return 0;
}
