#ifndef SONG_H
#define SONG_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Song {
private:
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;
    static const int MAX_MEMORY = 512;

    string title;
    string artist;
    int size;

public:


    Song();


    Song(string title, string artist, int size);

//     set and get all instance variables
// overload ==, <,and > operators (used in sorting)
// for < and > use artist, then title, then size
    string getTitle() const;
    void setTitle(string title);

    string getArtist() const;
    void setArtist(string artist);

    int getSize() const;
    void setSize(int size);
    void print();

    bool operator >(Song const &s) const;
    bool operator <(Song const &s) const;
    bool operator ==(Song const &s) const;




};

#endif