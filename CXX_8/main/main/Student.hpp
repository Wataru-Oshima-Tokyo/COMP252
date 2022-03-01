//
//  Student.hpp
//  Composition
//
//  Created by Wataru Oshima on 2019/12/05.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include "Birthday.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class StudentInfo{
    string name;
    int ID;
    string Nationality;
    Birthday BO;
public:
    StudentInfo(string n, int id, string nat, Birthday b);
    void showStudentInfo();
};
#endif /* Student_hpp */
