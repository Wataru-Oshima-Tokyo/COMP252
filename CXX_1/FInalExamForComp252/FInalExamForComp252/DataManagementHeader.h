//
//  DataManagementHeader.hpp
//  FInalExamForComp252
//
//  Created by Wataru Oshima on 2020/05/20.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef DataManagementHeader_hpp
#define DataManagementHeader_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

struct SDBNode {
    string firstName;
    string lastName;
    string cource;
    string section;
    string overallGPA;
    struct SDBNode *next;
};

class DataManagementHeader {
public:
    void initializeNode();
    void insertNode(string fn, string ln, string course, string section, string GPA);
    void addNode(string fn, string ln, string course, string section, string GPA);
    void deleteNode(int studentnumber);
    void serchNode();
    void println();
    void printlnOnly(SDBNode *temp);
    void tempInitializeNode();
    void modifyData();
    void searchDB(string category, string value, bool gpa);

    clock_t initiaiTime, endTime, totalTime;
};

#endif /* DataManagementHeader_hpp */
