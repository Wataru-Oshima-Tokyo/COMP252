//
//  Student.cpp
//  Composition
//
//  Created by Wataru Oshima on 2019/12/05.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Student.hpp"
#include <iostream>
using namespace std;
StudentInfo::StudentInfo(string n, int id, string nat, Birthday b)
:name(n), ID(id), Nationality(nat) ,BO(b)

{
    
};

void StudentInfo::showStudentInfo() {
    cout << "And his info is here: " << "Name: " << name << " ID: "  << endl;
};
