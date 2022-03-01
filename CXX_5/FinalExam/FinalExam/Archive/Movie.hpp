//
//  Movie.hpp
//  FinalExam
//
//  Created by Wataru Oshima on 2019/12/09.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Movie_hpp
#define Movie_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Movie {
public:
    string name = "";
    string rating = "";
    int watched = 0;

    Movie();
    Movie(string n, string r, int w);
    void showInfo();
};
#endif /* Movie_hpp */
