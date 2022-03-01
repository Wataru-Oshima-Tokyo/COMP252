//
//  Movies.cpp
//  COMP250_test
//
//  Created by Wataru Oshima on 2019/12/10.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Movies.hpp"
#include <string>
#include <iostream>
Movies::Movies() {
    name = "";
    rating = "";
    int watched = 0;
};

Movies::Movies(string name, string rating, int watched)
:name(name), rating(rating), watched(watched)
{
};

void Movies::showMovieInfo(){
    cout << name << ", " << rating << ", " << watched;
    
};
