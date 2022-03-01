//
//  Birthday.hpp
//  main
//
//  Created by Wataru Oshima on 2019/12/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Birthday_hpp
#define Birthday_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Birthday {
    int day;
    int month;
    int year;
    
public:
    Birthday(int m, int d, int y);
    void showBirthDate();
};
#endif /* Birthday_hpp */
