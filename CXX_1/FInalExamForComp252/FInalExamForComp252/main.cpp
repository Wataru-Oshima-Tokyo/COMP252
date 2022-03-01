//
//  main.cpp
//  FInalExamForComp252
//
//  Created by Wataru Oshima on 2020/05/20.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
#include "DataManagementHeader.h"
#include <ctime>
#include <time.h>

using namespace std;
void inputvalues();
void deleteStudent();
void modifyData();
void searchForTheStudent();
clock_t initiaiTime, endTime, totalTime;

void searchForTheStudent()
{
    
    string x, gpa, value;
    DataManagementHeader dmh;
    cout << "What category do you want to search for?" << endl;

    cout << "1.By first name" << endl;
    cout << "2.By last name" << endl;
    cout << "3.By course" << endl;
    cout << "4.By section" << endl;
    cout << "5.By GPA" << endl;
    cout << "Put the number here: ";
    cin >> x;
    cout <<"Then put the word/number that you want to serch for (Please be carefull searching is case-sensitive. :";
    cin >>value;
    if (x == "5") {
        cout << "Do you want to search the exact same as the GPA you put or higher? "
        << "If you want to search for the higher GPA, put 1:otherwise put any number: ";
        cin >> gpa;
        if (gpa == "1") {
            dmh.searchDB(x,value, true);
        }
        else
        {
            dmh.searchDB(x,value, false);
        }
    } else{
            dmh.searchDB(x,value, false);
    }

    
}

void modifyData()
{
   DataManagementHeader dmh;
    dmh.modifyData();
}

void deleteStudent()
{
    int x;
    DataManagementHeader dmh;
    dmh.println();
    cout << "Please put the number that you want to delete: ";
    cin >> x;
    dmh.deleteNode(x);
    
}

void inputvalues(){
    DataManagementHeader dmh;
    string fn, ln, course, section, GPA;
    cout << "Plesae put the first name: ";
    cin >> fn;
    cout << "Plesae put the last name: ";
    cin >> ln;
    cout << "Plesae put the course she/he is taking: ";
    cin >> course;
    cout << "Plesae put the section: ";
    cin >> section;
    cout << "Plesae put her/his overall GPA: ";
    cin >> GPA;
    initiaiTime = clock();
    dmh.addNode(fn, ln, course, section, GPA);
    cout << "Now you have the list in the DB" << endl;
    dmh.println();
    endTime = clock();
    totalTime = endTime-initiaiTime;
    cout << "The total time for the program is " <<totalTime << endl;
}
int main(int argc, const char * argv[]) {

    int choice = 0;
    DataManagementHeader dmh;
    dmh.initializeNode();
    dmh.tempInitializeNode();
    cout << "Initially, you have the list in the DB " << endl;
    dmh.println();
    while (choice !=5) {
        cout <<"********************************************************************************************" << endl;
        cout << "Please choose what you want to do" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Add more stundets" << endl;
        cout << "2. Delete students" << endl;
        cout << "3. Search for a student" << endl;
        cout << "4. Modify the data " << endl;
        cout << "5. Finish the program" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Put your choice here: ";
        cin >> choice;
        switch (choice) {
            case 1:
                inputvalues();
                break;
            case 2:
                deleteStudent();
                break;
            break;
            case 3:
                searchForTheStudent();
                break;
            case 4:
                modifyData();
                break;
            break;
            default:
                break;
        }
    }
    return 0;
}
