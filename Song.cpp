//
// Created by mehah on 10/27/2019.
//

#include "Song.h"


    Song::Song()
    {
        title = "";
        artist = "";
        size = 0;
    }

    Song::Song(string art,string titl, int siz)
    {
        title = titl;
        artist = art;
        size = siz;
    }

    bool Song::operator >(Song const &rhs)
    {
        if(artist < rhs.artist)
            return true;
        else if(title < rhs.title)
            return true;
        else if(size < rhs.size)
            return true;
        else
            return false;

    }
    bool Song::operator <(Song const &rhs)
    {
        if(artist<rhs.artist)
            return true;
        else if (artist>rhs.artist)
            return false;
        else if(title < rhs.title)
            return true;
        else if (title>rhs.title)
            return false;
        else if(size < rhs.size)
            return true;
        else
            return false;

    }
    bool Song::operator ==(Song const &rhs)
    {
        return (artist == rhs.artist && title == rhs.title && size == rhs.size);
    }