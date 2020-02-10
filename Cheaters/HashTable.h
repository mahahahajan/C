#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <map> 

using namespace std;


class HashTable
{
private:
    static const int TABLE_SIZE = 1000000;
    struct HashNode
    {
        int data;
        HashNode *next;
    };
    HashNode * Table [TABLE_SIZE];
public:
    HashTable();
    void hashFunc (string &s, int key);
    void getcollisions(int numofdocs, vector<string> &files, int minCollisions, vector<string> &fileNames, vector<int> &numCollisions);
    ~HashTable();
};

#endif