//
//  Movies.hpp
//  COMP250_test
//
//  Created by Wataru Oshima on 2019/12/10.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Movies_hpp
#define Movies_hpp

#include <stdio.h>
#include <string>
#include <iostream>
class Movies {
public:
    string name;
    string rating;
    int watched;
    
    Movies();
    Movies(string name, string rating, int watched);
    void showMovieInfo();
};
#endif /* Movies_hpp */
