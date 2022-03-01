#include "Movie.hpp"
#include<iostream>
#include<string>
using namespace std;


Movie::Movie() {
    Name = "";
    Rating = "";
    Watched = 0;
}

void Movie::set_info(string name, string rating, int watched) {
    Name = name;
    Rating = rating;
    Watched = watched;
}

string Movie::get_name(string name) {
    return name;
}
void Movie::show_info() {
    cout << Movie::Name << "," << Movie::Rating << "," << Movie::Watched << endl;
};

void Movie::add_watch() {
    Watched++;
};
