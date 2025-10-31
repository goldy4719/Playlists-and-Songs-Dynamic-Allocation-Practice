// Miles Goldberger

/* Created a menu, song, and playlist classes
 *
 * Song has an operator overload so that it prints properly. Song holds
 * Title, artist and size, playlist holds songs, and menu is a menu to edit these

*/



#include <iomanip>
#include <iostream>
#include "song.h"
#include "playlist.h"

using namespace std;

void printMenu();
char menuChoice();


int main() {
    //Create playlist called playlist
    playlist playlist;
    /*Need char for selection, holder for title artist and category, and category char to Style
     as well as songSize and a bool to check for correct input*/
    char selection;
    char title[35];
    char artist[20];
    char category;
    Style categoryStyle;
    int songSize;
    bool correctInput = false;

    //Loop through menu process as many times as user doesn't hit exit
    do {
        printMenu();
        selection = menuChoice();

        //If else blocks for every choice
        if (selection == 'A') {
            //Get users input for new song
            cout << "Enter song title (max 35 characters): ";
            cin.ignore();
            cin.getline(title, 35);
            cout << "Enter artist (max 20 characters): ";
            cin.getline(artist, 20);

            //do while loop to make sure a valid char for category was given
            do {
                cout << "Enter category (P - pop, R - Rock, A - Alternative, C - Country, H - HipHop, Y - Parody): ";
                cin >> category;
                category = toupper(category);
                if (category != 'P'&& category != 'R' && category != 'A'
                    && category != 'C' && category != 'H' && category != 'Y') {
                    cout << "Incorrect input, try again." <<endl;
                    correctInput = false;
                    }
                else {
                    correctInput = true;
                }
            }while (correctInput == false);

            correctInput = false;

            //do while to make sure valid size was given
            do {
                cout << "Enter song size in kilobytes: ";
                cin >> songSize;

                if (songSize >= 0) {
                    correctInput = true;
                }
                else {
                    cout << "Must enter a positive integer, try again.";
                    correctInput = false;
                }
            }while (!correctInput);
            cin.ignore();
            correctInput = false;
            category = toupper(category);

            //Need to get the Style value of the char
            if (category == 'P') {
                categoryStyle = POP;
            }
            else if (category == 'R') {
                categoryStyle = ROCK;
            }
            else if (category == 'A') {
                categoryStyle = ALTERNATIVE;
            }
            else if (category == 'C') {
                categoryStyle = COUNTRY;
            }
            else if (category == 'H') {
                categoryStyle = HIPHOP;
            }
            else {
                categoryStyle = PARODY;
            }
            //Create new song
            Song newSong;
            //Add new information to song
            newSong.Set(title, artist, categoryStyle, songSize);
            //Use add song function to add new song to playlist
            playlist.addSong(newSong);
        }

        //Gather title or artist of song and let function do the work
        else if (selection == 'F') {
            cout << "Enter song title or artist name (max 35 or 20): ";
            cin.ignore();
            cin.getline(title, 35);
            playlist.findSong(title);
        }

        //Get the title of the song and let the function do the work
        else if (selection == 'D') {
            cout << "Enter song title (max 35): ";
            cin.ignore();
            cin.getline(title, 35);
            playlist.removeSong(title);
        }

        //Let function carry away
        else if (selection == 'S') {
            playlist.printAllSongs();
        }

        //Get the category char, convert to style, and call function
        else if (selection == 'C') {
            cout << "Enter category (P - pop, R - Rock, A - Alternative, C - Country, H - HipHop, Y - Parody): ";
            cin >> category;
            category = toupper(category);

            //turn category char into style
            if (category == 'P') {
                categoryStyle = POP;
            }
            else if (category == 'R') {
                categoryStyle = ROCK;
            }
            else if (category == 'A') {
                categoryStyle = ALTERNATIVE;
            }
            else if (category == 'C') {
                categoryStyle = COUNTRY;
            }
            else if (category == 'H') {
                categoryStyle = HIPHOP;
            }
            else {
                categoryStyle = PARODY;
            }

            playlist.printCategories(categoryStyle);
        }

        //Get double from function and print
        else if (selection == 'Z') {
            cout << "Total playlist storage size (MB): " << playlist.getTotalStorage();
        }

        //Blank as we will just loop again
        else if (selection == 'M') {

        }

        //Inform user program will exit
        else if (selection == 'X') {
            cout << "Exiting program.";
        }
        //If user enters wrong character, will tell them and loop again
        else {
            cout << "Invalid input, try again.";
        }
    }while (selection != 'X');
    return 0;
}

//Simple function to print the menu
void printMenu() {
    cout << "  A:   Add a song to the playlist\n";
    cout << "  F:   Find a song on the playlist\n";
    cout << "  D:   Delete a song on the playlist\n";
    cout << "  S:   Show the entire playlist\n";
    cout << "  C:   Category summary\n";
    cout << "  Z:   Show playlist size\n";
    cout << "  M:   Show this menu\n";
    cout << "  X:   Exit the program\n";
}

//Simple function to get menu choice and turn it to upper
char menuChoice() {
    char choice;
    cin >> choice;
    choice = toupper(choice);
   return choice;
}

