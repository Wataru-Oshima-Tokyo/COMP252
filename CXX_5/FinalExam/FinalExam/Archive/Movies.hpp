//
//  Movies.hpp
//  FinalExam
//
//  Created by Wataru Oshima on 2019/12/09.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Movies_hpp
#define Movies_hpp

#include <stdio.h>
#include <string>
#include "Movie.hpp"
class Movies {
    // declaring "i" for counting how many movies are added
    int i = 0;
    //declaring movie[] as array which has 50 spots to be able to add.
    Movie movie[50];
public:
    void display();
    int add_movie(string n, string rating, int watched);
    int increment_watched(string n);
};

#endif /* Movies_hpp */
