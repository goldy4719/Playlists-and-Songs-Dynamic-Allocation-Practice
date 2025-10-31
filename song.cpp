//
// Created by Miles Goldberger on 10/24/25.
//

#include "song.h"
#include <cstring>
#include <iomanip>
using namespace std;

//Set title and artist to null and size to 0
Song::Song() {
    title[0] = '\0';
    artist[0] = '\0';
    size = 0;

}

//get the title and artist and size from menu
void Song::Set(const char* t, const char* a, Style st, int sz) {
    strcpy(title, t);
    strcpy(artist, a);
    size = sz;
    category = st;

}

//Get title, convert it
const char* Song::GetTitle() const {
    return title;
}

//Get artist and convert it
const char* Song::GetArtist() const {
    return artist;
}

//Get size and convert it
int Song::GetSize() const {
    return size;
}

//Get category and convert it
Style Song::GetCategory() const {
    return category;
}

//Overload operator so it prints proper
ostream& operator<<(ostream& os, const Song& s) {
    os << left;
    os << setw(35) << s.GetTitle();
    os << setw(20) << s.GetArtist();
    //Figure out what abbreviation to use
    if (s.category == POP) {
        os << setw(4) << "Pop";
    }
    else if (s.category == ROCK) {
        os << setw(4) << "Rock";
    }
    else if (s.category == ALTERNATIVE) {
        os << setw(4) << "Alt";
    }
    else if (s.category == COUNTRY) {
        os << setw(4) << "Ctry";
    }
    else if (s.category == HIPHOP) {
        os << setw(4) << "HH";
    }
    else if (s.category == PARODY) {
        os << setw(4) << "Par";
    }

    os << left << showpoint << setprecision(1) << setw(9) << ((double)s.GetSize()/1000.0);
    os << right << noshowpoint << endl;

    return os;
}
