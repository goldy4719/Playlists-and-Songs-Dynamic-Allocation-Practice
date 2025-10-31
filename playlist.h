//
// Created by Miles Goldberger on 10/24/25.
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "song.h"


class playlist {



public:

    //Default constructor, just makes a Song array[5]
    playlist();
    //Find song in playlist
    void findSong(const char* t) const;
    //Add song to playlist
    void addSong(const Song s);
    //remove song from playlist and shift down
    void removeSong(const char* t);
    //Print songs of a given category
    void printCategories(const Style c) const;
    //Get total storage all songs take up
    double getTotalStorage() const;
    //Print all songs in the playlist
    void printAllSongs() const;





private:
    //Dynamic array
    Song* list;
    //How big the array is
    int list_length;
    //How many songs there are
    int count;
    //Check the length of the list (if 5 or more, set size to 10, if 10 set to 15 and so on)
    void checkLength();




};



#endif //PLAYLIST_H
