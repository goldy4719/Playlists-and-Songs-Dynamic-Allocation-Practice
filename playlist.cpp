//
// Created by Miles Goldberger on 10/24/25.
//

#include "playlist.h"

#include <iomanip>

using namespace std;

playlist::playlist() {
    list = new Song[5];
    count = 0;
    list_length = 5;
}
//Look for song by title, and print, if matches artist find every artist's songs and print
void playlist::findSong(const char* t) const {

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(t, list[i].GetTitle()) == 0) {
            cout << list[i];
            found = true;
        }
        else if (strcmp(t, list[i].GetArtist()) == 0) {
            cout << list[i];
            found = true;
        }
    }
    if (!found) {
        cout << "Sorry, that song or artist was not found." << endl;
    }
}
//Add song to playlist from count position
void playlist::addSong(const Song s) {

    list[count] = s;
    count++;
    checkLength();

}
//Remove song and then shift all over
void playlist::removeSong(const char* s) {

    bool deleted = false;

    for (int i = 0; i < count; i++) {
        if (strcmp(s, list[i].GetTitle()) == 0) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            deleted = true;
            checkLength();
        }
    }
    if (!deleted) {
        cout << "could not find song that matched that title." << endl;
    }
}

//filter by categorty and print
void playlist::printCategories(const Style c) const {
    double size = 0;
    int songCount = 0;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (c == list[i].GetCategory()) {
            cout << list[i];
            size += list[i].GetSize();
            songCount++;
            found = true;
        }

    }
    if (found) {
        cout << "File size: " << showpoint << setprecision(2) << size / 1000.0 <<endl;
    }
    else {
        cout << "No songs in this playlist are in that genre.";
    }
}

//Get total storage
double playlist::getTotalStorage() const {
    int playlistSize = 0;

    for (int i = 0; i < count; i++) {
        playlistSize += list[i].GetSize();
    }

    cout << showpoint << setprecision(2);
    return (double)playlistSize / 1000.0;
}


//Print all songs
void playlist::printAllSongs() const {
    cout << left;
    cout << setw(35) << "Title" << setw(20) << "Artist";
    cout << setw(9) << "Style" << "Size (MB)" << endl;;
    for (int i = 0; i < count; i++) {
        cout << list[i];
    }
    cout << "Total songs: " << count << endl;
    cout <<  "Total storage size: " << getTotalStorage() << endl;
}


//Check length (going from 5-10-15 and so on. If gap of more than 5, decrease.
void playlist::checkLength() {

    if (count == list_length) {
        list_length += 5;
        Song* newList = new Song[list_length];

        for (int i = 0; i < count; i++) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
    }
    else if (list_length - count > 5) {
        list_length -= 5;
        Song* newList = new Song[list_length];
        for (int i = 0; i < count; i++) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
    }
}