#pragma once
#include <iostream>
#include <string>
#include "Movie.hpp"

using namespace std;

class Movies
{
private:
    Movie movie[50];

public:
    void display();
    int add_movie(string name, string rating, int watched);
    int increment_watched(string name);

};

