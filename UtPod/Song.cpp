// For each song we will store the title (string), artist (string),  and size
// (int) in MB the title and artist cannot be blank the size must be greater
// than zero

// TODO: Make it so that the title artist and MB cannot be blank and size has to
// TODO: be greater than 0
// TODO: Handle other error cases
// TODO: Comment all functions

#include "Song.h"

// string title;
// string artist;
// int size;

Song::Song() {

    title = "Young, Wild, and Free";
    artist = "Snoop Dogg";
    size = 5;
}

Song::Song(string _artist, string _title, int _size) {
    title = _title;
    artist = _artist;
    if (_size <= 0) {
        size = 5;
    } else {
        size = _size;
    }
}

string Song::getArtist() const { return artist; }
string Song::getTitle() const { return title; }
int Song::getSize() const { return size; }
void Song::setArtist(string _artist) { artist = _artist; }
void Song::setTitle(string _title) { title = _title; }
void Song::setSize(int _size) { size = _size; }

bool Song::operator >(Song const &s) const {
    if (artist.compare(s.getArtist()) == 0) {
        // if both artists are the same
        if (title.compare(s.getTitle()) == 0) {
            // if both titles are the same
            return size > s.getSize();
        }
        else{
            if(title.compare(s.getTitle())< 0){
                return true;
            }
            else{
                return false;
            }
        }
    } else {
        if (artist.compare(s.getArtist()) < 0) {
            // comes first
            return true;
        } else {
            return false;
        }
    }
}
bool Song::operator<(Song const &s) const {
    if (artist.compare(s.getArtist()) == 0) {
        // if both artists are the same
        if (title.compare(s.getTitle()) == 0) {
            // if both titles are the same
            return size < s.getSize();
        }
        else{
            if(title.compare(s.getTitle()) > 0){
                return true;
            }
            else{
                return false;
            }
        }
    } else {
        if (artist.compare(s.getArtist()) > 0) {
            // this one comes second
            return true;
        } else {
            return false;
        }
    }
}
bool Song::operator==(Song const &s) const {
    return ((artist.compare(s.getArtist()) == 0) &&
            (title.compare(s.getTitle()) == 0) && (size == s.getSize()));
}

void Song::print(){
    cout << "Artist: " << getArtist() << " | Title: " << getTitle() << " | Size: " << getSize() << endl;
}
// Song(string title, string artist, int size);

// //     set and get all instance variables
//  overload ==, <,and > operators (used in sorting)
//  for < and > use artist, then title, then size

// bool operator>(Song const &s) const;
// bool operator<(Song const &s) const;
// bool operator==(Song const &s) const;
