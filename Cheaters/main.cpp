#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "HashTable.h"

using namespace std;

/*function... might want it in some class?*/
//gets all files in directory
int getFilesInDir(string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	fstream x;
	string word;
	int num = 0;

	while ((dirp = readdir(dp)) != NULL) {
		files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

void getAllWords(string folder, string file)
{
	string filename = folder + file;
	fstream currFile;
	currFile.open(filename.c_str());
	string word;
	int num = 0;
	//cout << "THIS IS A TEST " << s << endl;

	if (currFile.is_open()) {
		cout << "TEST 1 " << endl;
		while (currFile >> word) {
			num++;
		}
	}
	cout << "Num was: " << num << endl;
	currFile.close();
}

void getAllChunks(string folder, string file, int n, vector<string> &chunks)
{
	string filename = folder + file;
	fstream currFile;
	currFile.open(filename.c_str());
	string word;
	string chunk;
	int counter = 0;
	//cout << "THIS IS A TEST " << s << endl;
	if (currFile.is_open()) {
		cout << "TEST 1 " << endl;
		while (currFile >> word) {
			//n length chunks
			counter++;
			chunk += word + " ";
			if (counter % n == 0 && counter != 0) {
				chunks.push_back(chunk);
				chunk = "";
			}
		}
	}
	currFile.close();
}
//Clean up strings to make it eaiser to handle the data
//TODO: Clean up this method
void parser(string &str)
{
	for (int i = 0; i < str.length(); i++) {
		if (96 < str[i] && str[i] < 123) {
			str[i] = str[i] - 32;
		}
		if (str[i] < 64 || str[i] > 91) {
			str.erase(str.begin() + i);
			i--;
		}
	}
}

int main(int argc, char **argv)
{
	HashTable *hashTable = new HashTable;
	string dir = string(argv[1]);
	vector<string> files = vector<string>();
	int n = atoi(argv[2]);
	int minCollisions =  atoi(argv[3]);
    if(argc > 2){
       cout << "TESTING PURPOSE" << endl;
    }  
	vector<string> chunks = vector<string>();

	getFilesInDir(dir, files);

	// for (unsigned int i = 0; i < files.size(); i++) {
	// 	cout << i << " : " << files[i] << endl;
	// 	getAllChunks(dir, files[i], n, chunks);
	// }
	// for (long x = 0; x < chunks.size(); x++) {
	// 	cout << chunks[x] << endl;
	// }
	for (int i = 0; i < files.size(); i++) {
		if (files[i].substr(0, 1) == ".") {
			files.erase(files.begin() + i);
			i--;
		}
	}
	ifstream myfile;
	for (int i = 0; i < files.size(); i++) {
		//            string fileptr = "sm_doc_set/" + files[i];
		string fileptr = dir + '/' + files[i];

		myfile.open(fileptr.c_str());
		if (myfile.good() && myfile.is_open()) {
			string word;
			vector<string> wordQueue;
			while (!myfile.eof()) {
				while (wordQueue.size() < n && !myfile.eof()) {  // replace 6 with the n word sequence{
					myfile >> word;
					parser(word);
					if (word.length() != 0) {
						wordQueue.push_back(word);
					}
				}
				string mystring;
				for (int j = 0; j < wordQueue.size(); j++) {
					mystring += wordQueue[j];
				}
				hashTable->hashFunc(mystring, i);
				wordQueue.erase(wordQueue.begin());
				//cout<< endl;
			}
		}
		else {
			cout << "Files not found!";
			return 0;
		}
		myfile.close();
	}
	vector<string> filesNames;
	vector<int> numCollisions;
	hashTable->getcollisions(files.size(), files, minCollisions, filesNames, numCollisions);
	int max = 0;
	int index = 0;
	while (filesNames.size() > 0) {
		for (int i = 0; i < filesNames.size(); i++) {
            cout << "TEST: " << filesNames.at(i) << endl;
			int curr = numCollisions.at(i);
			if (curr > max) {
				index = i;
				max = curr;
			}
		}
		cout << numCollisions.at(index) << ": " << filesNames.at(index) << endl;
		filesNames.erase(filesNames.begin() + index);
		numCollisions.erase(numCollisions.begin() + index);
	}

	delete (hashTable);
}
