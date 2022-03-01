//
//  main.cpp
//  COMP250_StructHW
//
//  Created by Wataru Oshima on 2019/10/30.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

//#include <fstream>
//int Input() {
//    int id, testScore;
//    string firstName, lastName, student;
//    char grade;
//    for (int i = 0; i <3; i++) {
//    fstream myStream ("database.text");
//        student = student[i];
//
//        myStream <<
//    }
//}

#include <iostream>
#include <string>
using namespace std;




struct studentType {
    // id, fn, ln, status (Sp, j, Sn), major
    string firstName = "";
    string lastName = "";
    int testScore;
    char grades;
};

int EnterStudent(studentType& student, int a) {
    //call the function and create a fully initialized student
    string empty = "0";
    a = a+1;
    cout << "What is student " << a << "'s first name ?" << endl;
    getline(cin, student.firstName);
    cout << "What is student " << a << "'s last name ?: " << endl;
    getline(cin, student.lastName);
    cout << "What is student " << a << "'s test score ?: " << endl;
    cin >> student.testScore;
    
    if (student.testScore >= 90){
        student.grades = 'A';
    } else if (student.testScore >= 80){
        student.grades = 'B';
    } else if (student.testScore >= 70) {
        student.grades = 'C';
    } else if (student.testScore >= 60) {
        student.grades = 'D';
    } else {
        student.grades = 'F';
    }
    getline(cin, empty);
    return 0;
};



void asscending (int a[], int b){
    bool answer = true;
    while (answer == true) {
        answer = false;
        for (int i = 0 ; i < b; i++) {
            if (a[i] > a[i + 1]) {
                 swap(a[i], a[i+1]);
                answer = true;
            }

        }
    }

}


void InputTheData () {
    int n = 0;
    int inoputDataTotal = 20;
    int testscore[inoputDataTotal];
    studentType stundentNumber[inoputDataTotal];
    for (n = 0; n <inoputDataTotal; n++) {
        EnterStudent(stundentNumber[n], n);
        testscore[n] = stundentNumber[n].testScore;
    }
    asscending(testscore, inoputDataTotal);
    int HighestScore = testscore[inoputDataTotal];
    
    cout << "The higestScore is " << HighestScore;
    for (int m = 0; m <inoputDataTotal; m++) {
        if (HighestScore == stundentNumber[m].testScore) {
            cout << " and the stundet who got the point is ";
            cout << stundentNumber[m].firstName << endl;
            
        }
    }
    for (n = 0; n <inoputDataTotal; n++) {
         cout << "This student " << n+1 << " is " << stundentNumber[n].lastName << ", " << stundentNumber[n].firstName << endl;
    }
}


int main(int argc, const char * argv[]) {
    InputTheData();
    return 0;
}
