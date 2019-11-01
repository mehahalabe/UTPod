//
// Created by mehah on 10/27/2019.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
using namespace std;
class Song
{
private:
    string title, artist;
    int size;



public:

    Song();

    Song(string art,string titl, int siz);

    string getTitle(){
        return title;
    }

    string getArtist(){
        return artist;
    }

    int getSize() {
        return size;
    }

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);
};


#endif //UTPOD_SONG_H
