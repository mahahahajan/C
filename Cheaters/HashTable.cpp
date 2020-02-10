#include "HashTable.h"
#include <iostream>
#include <string>
#include <vector>

HashTable::HashTable(){};

void HashTable::hashFunc(string &s, int key)
{  // takes a n word string and then places it into the hash map
	int multiplier = 1;
	const int mult = 7;
	int index = 0;
	//cout<<s;
	for (int i = 0; i < s.length(); i += 2) {
		multiplier = mult * multiplier;
		index += (s[i] * multiplier);
	}
	index = index % TABLE_SIZE;
	if (index < 0) {
		index = index * -1;
	}
	//cout<<" " <<index;
	HashNode *temp = new HashNode;
	temp->data = key;
	//cout<<" "<< key<< endl;
	if (Table[index] == NULL) {
		temp->next = NULL;
		Table[index] = temp;
	}
	else {
		temp->next = Table[index];
		Table[index] = temp;
	}
}

void HashTable::getcollisions(int numOfDocs, vector<string> &files, int minCollisions, vector<string> &fileNames, vector<int> &numCollisions)
{  //still need to pass in argument with minumin number of collisions to determine cheating,
	//also need to print out those entries that have those minimum number of entries
	//ask max if he wants to return the array, and how to.
	cout << "The following files have collisions: " << endl;
	int collisionArr[numOfDocs][numOfDocs];
	for (int i = 0; i < numOfDocs; i++) {
		for (int j = i + 1; j < numOfDocs; j++) {
			collisionArr[j][i] = 0;
		}
	}

	for (int i = 0; i < TABLE_SIZE; i++) {
		while (Table[i] != NULL) {
			HashNode *cur = Table[i];
			int data = cur->data;
			while (cur != NULL) {
				if (data != cur->data) {
					collisionArr[data][cur->data]++;
				}
				cur = cur->next;
			}
			cur = Table[i];
			Table[i] = Table[i]->next;
			delete (cur);
		}
	}
	vector<string> filesNames;
	vector<int> collisionNumbers;

	for (int i = 0; i < numOfDocs; i++) {
		for (int j = i + 1; j < numOfDocs; j++) {
			if (collisionArr[i][j] > minCollisions) {
				//TODO: CHANGE THIS SO INSTEAD IT JUST PUSHES THIS INFORMATION INTO AN ARRAY
				// string filesString = files[i] + ", " + files[j];
				// int numberCollisions = collisionArr[i][j];
				// filesNames.push_back(filesString);
				// collisionNumbers.push_back(numberCollisions);
				cout << collisionArr[i][j] << ": " << files[i] << ", " << files[j] << endl;
			}
		}
	}
}

HashTable::~HashTable(){};