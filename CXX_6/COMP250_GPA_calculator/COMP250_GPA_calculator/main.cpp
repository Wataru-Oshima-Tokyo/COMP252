//
//  main.cpp
//  COMP250_GPA_calculator
//
//  Created by Wataru Oshima on 2019/11/02.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

struct studentType {
    string firstName;
    string lastName;
    int testScore;
    int programmingScore;
    char courseGrade;
    char GPA;
};

void readIn(studentType& student){

    int score;
    cout << "FirstName" << endl;
    cin >> student.firstName;
    cout << "lastName" << endl;
    cin >> student.lastName;
    cout << "testScore" << endl;
    cin >> student.testScore;
    cout << "programmingScore" << endl;
    cin >> student.programmingScore;
    cout << "GPA" << endl;
    cin >> student.GPA;

    score = (student.programmingScore + student.testScore) /2;    //complete this statement to calculate the average of programming and test score for student

    if (score >= 90)

    student.courseGrade = 'A';

    else if (score >= 80)

    student.courseGrade = 'B';

    else if (score >= 70)

    student.courseGrade = 'C';

    else if (score >= 60)

    student.courseGrade = 'D';

    else

    student.courseGrade = 'F';

}

void showStudent(studentType& a) {
    cout << a.firstName << endl;
    cout << a.lastName<< endl;
    cout << a.testScore << endl;
    cout << a.programmingScore << endl;
    cout << a.GPA << endl;
    cout << a.courseGrade << endl;
    
}

void testInteger(int a = 0, int b = 0) {
    int c = 0;
    a = 60;
    b = 70;
    c = a + b;
    cout << c << endl;
//    return c;
}



int main(int argc, const char * argv[]) {
    studentType studentType;
    readIn(studentType);
    showStudent(studentType);
    testInteger();
    cout << "" << endl;
    return 0;
}
