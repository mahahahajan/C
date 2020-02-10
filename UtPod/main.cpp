/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    cout <<"Created Pod"<< endl;

    cout << "memory = " << t.getRemainingMemory() << endl;  // refers to memory left that can still be used
    cout << "totalMem = " << t.getTotalMemory() << endl <<endl;

    Song s0("DJ Snake feat. Lauv ", "A Different Way ", 515);
    cout<<s0.getArtist() << s0.getTitle() << s0.getSize()<<endl;
    t.addSong(s0);
    t.showSongList();
    cout<<endl;

    Song s1("Ariana Grande ", "imagine ", 7);
    cout<<s1.getArtist() << s1.getTitle() << s1.getSize()<<endl;
    t.addSong(s1);
    t.showSongList();
    cout<<endl;

    Song s2("Bruno Mars ", "Runaway Baby ", 5);
    cout<<s2.getArtist() << s2.getTitle() << s2.getSize()<<endl;
    t.addSong(s2);
    t.showSongList();
    cout<<endl;

    t.shuffle();
    t.showSongList();

    Song s3("Charlie Puth ", "Cheating on You ", 6);
    cout<<s3.getArtist() << s3.getTitle() << s3.getSize()<<endl;
    t.addSong(s3);
    t.showSongList();
    cout<<endl;

    Song s4("Ariana Grande feat. Zedd ", "Break Free ", 4);
    cout<<s4.getArtist() << s4.getTitle() << s4.getSize()<<endl;
    t.addSong(s4);
    t.showSongList();
    cout<<endl;

    Song s5("Bruno Mars ", "Versace on the Floor ", 241);
    cout<<s5.getArtist() << s5.getTitle() << s5.getSize()<<endl;
    t.addSong(s5);
    t.showSongList();
    cout<<endl;

    Song s6("Charlie Puth ", "I Warned Myself ", 249);
    cout<<s6.getArtist() << s6.getTitle() << s6.getSize()<<endl;
    t.addSong(s6);
    t.showSongList();
    cout<<endl;

    Song s7("Ariana Grande ", "in my head ", 249);
    cout<<s7.getArtist() << s7.getTitle() << s7.getSize()<<endl;
    t.addSong(s7);
    t.showSongList();
    cout<<endl;

    t.removeSong(s6);

    t.showSongList();
    cout<<endl;

    Song s8("Charlie Puth ", "Cheating on You ", 6);//Duplicate
    cout<<s8.getArtist() << s8.getTitle() << s8.getSize()<<endl;
    t.addSong(s8);

    t.showSongList();
    cout<<endl;

    int result = 0;
    result = t.removeSong(s8);
    t.showSongList();
    cout<<endl;

    result = t.addSong(s4);
    t.showSongList();
    cout<<endl;

    result = t.removeSong(s4);
    t.showSongList();
    cout<<endl;

    cout<< "SORT -------- " <<endl;
    t.sortSongList();
    t.showSongList();
    cout <<endl;

    cout<< "SHUFFLE -------- " <<endl;
    t.shuffle();
    t.showSongList();
    cout <<endl;


    cout<< "SORT -------- " <<endl;
    t.sortSongList();
    t.showSongList();
    cout<<endl;

    cout<< "MEMORY CLEARED -------- " <<endl;
    t.clearMemory();
    t.showSongList();
    cout<<endl;

    cout<< "NEW POD IS CREATED -------- " <<endl;
    UtPod s(600);
    cout<<s0.getArtist() << s0.getTitle() << s0.getSize()<<endl;
    result= s.addSong(s0);
    cout<< " add result = " << result <<endl;
    cout<<endl;

    cout<<s1.getArtist() << s1.getTitle() << s1.getSize()<<endl;
    result = s.addSong(s1);
    cout<< " add result = " << result <<endl;
    cout<<endl;

    cout<<s2.getArtist() << s2.getTitle() << s2.getSize()<<endl;
    result =  s.addSong(s2);
    cout<< " add result = " << result <<endl;
    cout<<endl;

    cout<<s3.getArtist() << s3.getTitle() << s3.getSize()<<endl;
    result = s.addSong(s3);
    cout<< " add result = " << result <<endl;
    cout<<endl;

    cout<<s4.getArtist() << s4.getTitle() << s4.getSize()<<endl;
    result = s.addSong(s4);
    cout<< " add result = " << result <<endl;
    cout<<endl;

    s.showSongList();

    cout<<s1.getArtist() << s1.getTitle() << s1.getSize()<<endl;
    result = s.removeSong(s1);
    cout<< " remove result = " << result <<endl;
    cout<<endl;

    s.showSongList();

    cout<<"REMAINING MEMORY " <<s.getRemainingMemory()<<endl;

    cout<< "TOTAL MEMORY " << s.getTotalMemory()<<endl;
    cout<<endl;
    cout<< "SORT -------- " <<endl;
    s.sortSongList();
    s.showSongList();
    cout<<endl;

    cout<< "Shuffle -------- " <<endl;
    s.shuffle();
    s.showSongList();
    cout<<endl;

    cout<< "SORT -------- " <<endl;
    s.sortSongList();
    s.showSongList();
    cout<<endl;

    cout<< "SORT -------- " <<endl;
    s.sortSongList();
    s.showSongList();

}