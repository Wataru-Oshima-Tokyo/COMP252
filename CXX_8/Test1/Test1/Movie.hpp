#pragma once
#include<iostream>
#include<string>
using namespace std;

class Movie
{
private:


public:
    string Name = "";
    string Rating = "";
    int Watched = 0;


    Movie();

    string get_name(string name);
    void set_info(string name, string rating, int watched);
    void show_info();
    void add_watch();
};
