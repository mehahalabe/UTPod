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

    Song s1("Justin Bieber", "Never Say Never", 10);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    //t.showSongList();

    Song s2("Mariah Carey", "All I Want for Christmas is You", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    // t.showSongList();

    Song s3("Michael Buble", "Feeling Good", 20);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Michael Buble", "Feeling Good", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Trusha Tiwari", "I'm a Potato", 241);
    result = t.addSong(s5);

    Song s6("Green Day", "Boulevard of Broken Dreams", 87);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    Song s7("Childish Gambino", "Bonfire", 57);
    result = t.addSong(s7);
    cout << "result = " << result << endl;

    Song s8("Miley Cyrus","Wrecking Ball", 89);
    result = t.addSong(s8);
    cout << "result = " << result << endl;

    Song s9("Ariana Grande", "7 Rings", 7);
    result = t.addSong(s9);
    cout << "result = " << result << endl;

    Song sl("John Legend", "All of Me", 9);
    result = t.addSong(sl);
    cout << "result = " << result << endl;

    t.showSongList();
    cout << "\n";

    result = t.addSong(s3);
    cout << "add result = " << result << endl;
    

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    t.shuffle();
    t.showSongList();
    cout << "\n";
    t.sortSongList();
    t.showSongList();


    cout << "memory = " << t.getRemainingMemory() << endl;


}
