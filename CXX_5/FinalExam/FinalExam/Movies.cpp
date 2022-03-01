//
//  Movies.cpp
//  FinalExam
//
//  Created by Wataru Oshima on 2019/12/09.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Movies.hpp"
#include "Movie.hpp"
#include <iostream>


void Movies::display() {
    cout << "===================================" << endl;
    if (i >= 1){
    //display the movie and loop as the same time as the number of movies in the movie[].
        for (int x = 0; x <=i; x++) {
            if (movie[x].name != "")
                movie[x].showInfo();
            
            }
    } else {
        cout << "Sorry, no movies to display." << endl;
    }
    cout << "===================================" << endl;
};

int Movies::add_movie(string n, string r, int w){
    // check if the movie exists or not. If it already exists, then return 0 which means false
    if (i >= 1) {
        for (int p = 0; p < i; p++) {
            if (movie[p].name == n) {
                return 0;
            }
        }
    }
    // storing info into movie[i] which I declared in the Movies.hpp. And it contains name, rating and watched
    movie[i].name = n;
    movie[i].rating = r;
    movie[i].watched = w;
    //Once the movie is added, the number of the array increases by 1
    i = i + 1;
    return 1;
}

int Movies::increment_watched(string n){
    for (int p = 0; p < i; p++) {
            //check if the movie exists or not. If it exits, add 1 onto the "watched"
            if (movie[p].name == n) {
                movie[p].watched = movie[p].watched + 1;
                return 1;
            }
        }
    return 0;
}

void inputFunction() {
    string n; 
};



