//
//  main.cpp
//  main
//
//  Created by Wataru Oshima on 2019/12/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "Birthday.hpp"
#include "People.hpp"
#include "Student.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Birthday myBirthday(8, 14, 1999);
//    myBirthday.showBirthDate();
//    People myPeople("Wataru", myBirthday);
//    myPeople.showPeople();
    StudentInfo myStudent("Wataru", 01208555, "JApan", myBirthday);
    myStudent.showStudentInfo();
    return 0;
}
