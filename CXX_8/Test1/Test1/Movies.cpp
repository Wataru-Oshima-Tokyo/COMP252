#include <iostream>
#include <string>
#include "Movies.hpp"
#include "Movie.hpp"
using namespace std;


void Movies::display() {
    bool exist = false;
    for (int i = 0; i <= 50; i++) {
        if (movie[i].Movie::Name != "") {
            movie[i].Movie::show_info();
            exist = true;
        }
        if (!exist)
            cout << "No movies currently" << endl;

    }
};

int Movies::add_movie(string name, string rating, int watched) {
    bool set = false;
    int duplicate = 1;
    for (int j = 0; j <= 50; j++) {

        if (movie[j].Name == name) {
                set = true;
                duplicate = 0;
        }

        if (movie[j].Movie::Name != "" && !set) {
            movie[j].Movie::set_info(name, rating, watched);
            set = true;
        }
        
    }
    return duplicate;
};

int Movies::increment_watched(string name) {
    int a = 0;
    for (int k = 0; k <= 50; k++) {
        if (movie[k].Movie::Name == name) {
            movie[k].Movie::add_watch();
            a = 1;
        }
    }
    return a;
};



