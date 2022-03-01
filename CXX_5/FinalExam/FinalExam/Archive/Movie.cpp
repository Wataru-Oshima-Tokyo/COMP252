//
//  Movie.cpp
//  FinalExam
//
//  Created by Wataru Oshima on 2019/12/09.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Movie.hpp"
#include <string>
#include <iostream>
using namespace std;

Movie::Movie(){
    name = "";
    rating = "";
    watched = 0;
}
Movie::Movie(string n, string r, int w)
:name(n), rating(r), watched(w)
{
};

void Movie::showInfo() {
    cout << name << ", " << rating << ", " << watched << endl;
};

