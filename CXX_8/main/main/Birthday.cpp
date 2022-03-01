//
//  Birthday.cpp
//  main
//
//  Created by Wataru Oshima on 2019/12/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Birthday.hpp"
#include <iostream>
using namespace std;

Birthday::Birthday(int m, int d, int y){
    month = m;
    day = d;
    year = y;
};

void Birthday::showBirthDate(){
    cout << day << "/" << month << "/" << year << endl;
}
