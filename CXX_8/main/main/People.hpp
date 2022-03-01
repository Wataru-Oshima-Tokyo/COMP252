//
//  People.hpp
//  main
//
//  Created by Wataru Oshima on 2019/12/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef People_hpp
#define People_hpp

#include <stdio.h>
#include <string>
#include "Birthday.hpp"
using namespace std;
class People {
    string name;
    Birthday BO;
public:
    People(string n, Birthday b);
    void showPeople();
};
#endif /* People_hpp */
