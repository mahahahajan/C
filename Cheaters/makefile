final: main.o HashTable.o 
	g++ -o plagiarismCatcher main.o HashTable.o
main.o: main.cpp HashTable.h
	g++ -c -g main.cpp
HashTable.o: HashTable.h 
	g++ -c -g HashTable.cpp
