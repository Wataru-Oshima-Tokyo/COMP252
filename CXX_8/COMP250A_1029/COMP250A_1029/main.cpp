//
//  main.cpp
//  COMP250A_1029
//
//  Created by Wataru Oshima on 2019/10/29.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


struct studentType {
    // id, fn, ln, status (Sp, j, Sn), major
    int id;
    string firstName;
    string LastName;
    string Status;
    string Major;
};

void EnterStudent(studentType& student1) {
    //call the function and create a fully initialized student
    cout << "put your student id: ";
    cin >> student1.id;
    cout << "put your first and last name" << endl;
    cout << "First: ";
    cin >> student1.firstName;
    cout << "Last: ";
    cin >> student1.LastName;
    cout << "What is you status? ";
    cin >> student1.Status;
    
    cout << "What is your major? : ";
    getline(cin, student1.Major);
};


void ShowStudent(studentType& a) {
  //Displaying student into as folllow:
  //This student is named ... and he is a ... and is enabled in ... major
    cout << "This student is named" << a.id << endl;
    cout << "This student's first name is  " << a.firstName << endl;
    cout << "This student's last name is" << a.id << endl;
    cout << "This student's status is " << a.Status << endl;
    cout << "This student's major is" << a.Major << endl;
};

int main(int argc, const char * argv[]) {
    int numberOfStudent[100], n;
    studentType myStudent;
    EnterStudent(myStudent);
    ShowStudent(myStudent);

    
    
    // if I do not assing anything in the valuables. it couls be garbages because the valuables alrady used the memomry. So do not forget to initialize the valuables I made.

    
    return 0;
}
