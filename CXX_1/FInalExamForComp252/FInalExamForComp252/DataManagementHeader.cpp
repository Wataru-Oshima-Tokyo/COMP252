//
//  DataManagementHeader.cpp
//  FInalExamForComp252
//
//  Created by Wataru Oshima on 2020/05/20.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include "DataManagementHeader.h"
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;





SDBNode *start = NULL;
SDBNode *createNode(){
    SDBNode *temp;
    temp = new SDBNode;
    return temp;
}


void  DataManagementHeader::initializeNode(){
    SDBNode *temp,*traverse;
    string n = "";
        temp = createNode();
    temp->firstName = n;
    temp->lastName = n;
    temp->cource = n;
    temp->section = n;
    temp->overallGPA = n;
        temp->next = NULL;
        if(start == NULL){
            start = temp;
        }
        else{
            traverse = start;
            while(traverse->next != NULL){
                traverse= traverse->next;
            }
            traverse->next= temp;
            }
}
//inserting a student;
void DataManagementHeader::insertNode(string fn, string ln, string course, string section, string GPA){
    SDBNode *temp,*traverse, *nextnext;
    temp = createNode();
    traverse = start;
    nextnext = traverse ->next;
    traverse->next= temp;
    temp->firstName = fn;
    temp->lastName = ln;
    temp->cource = course;
    temp->section = section;
    temp->overallGPA = GPA;
    temp->next = nextnext;
}

//adding a student on top;
void DataManagementHeader::addNode(string fn, string ln, string course, string section, string GPA)
{

    SDBNode *temp, *traverse;
    temp = createNode();
    traverse = createNode();
    temp->firstName = start->firstName;
    temp->lastName = start->lastName;
    temp->cource = start->cource;
    temp->section = start->section;
    temp->overallGPA = start->overallGPA;
    temp->next = start ->next;
    start = traverse;
    traverse->firstName = fn;
    traverse->lastName = ln;
    traverse->cource = course;
    traverse->section = section;
    traverse->overallGPA = GPA;
    traverse->next = temp;
}

void DataManagementHeader::println()
{
    int i = 1;
    SDBNode *traverseNode = start;

    while(traverseNode->next != NULL){
        std::cout << i << "." << endl;
        std::cout<< "The student name is " << traverseNode->firstName<< " " << traverseNode->lastName << endl;;
        std::cout<< "She/He is taking " << traverseNode->cource<< " " << traverseNode->section << endl;
        std::cout << "Her/his overall GPA is " << traverseNode->overallGPA << endl;
        traverseNode = traverseNode->next;
        i = i+1;
        }
    std::cout<< std::endl;
}

void DataManagementHeader::deleteNode(int studentnumber)
{
    char x;
    SDBNode *temp, *current = start, *previous=start;
    
    for (int i = 1; i < studentnumber; i++) {
        current = current->next;
    }
    for (int i = 1; i < studentnumber-1; i++) {
        previous = previous->next;
    }
    
    
    cout << "Do you really want to delete the student " << current->firstName << " " << current->lastName << " from the DB? (y/n): ";
    cin >> x;
    initiaiTime = clock();
    if (x == 'y') {
        if (studentnumber == 1) {
            start = current->next;
        } else
        {
            temp = previous->next->next;
            previous->next = temp;
        }
        cout << "Deleting completes. Now you have the database below" << endl;
        println();
        endTime = clock();
        totalTime = endTime-initiaiTime;
        cout << "The total time for the program is " <<totalTime << endl;
    } else {
        cout << "Going back to the main menu: " << endl;
    }
}

void DataManagementHeader::tempInitializeNode()
{
    string firstNameArray[6] = {"Wataru", "Kakeru", "Kimheng", "Eddy", "Oudom", "Yokei"};
    string lastNameArray[6] = {"Oshima", "Oshima", "Peng", "Khant", "Seang", "Fujibayashi"};
    string course[6] = {"COMP","MATH", "ENGR", "MATH", "ENG", "PHYS"};
    string section[6] = {"252", "252", "100", "253", "110", "260"};
    string gpa[6] = {"3.0", "3.2", "3.9", "4.0", "3.5", "2.8"};
    for (int i = 0; i<6; i++) {
        addNode(firstNameArray[i], lastNameArray[i], course[i], section[i], gpa[i]);
    }
}

void DataManagementHeader::modifyData()
{
    string fn, ln, course, section, GPA;
    char x;
    int choice;
    SDBNode *current = start;
    
    println();
    cout << "Which person do you want to modify?: " << endl;
    cin >> choice;
    for (int i = 1; i < choice; i++) {
        if (current->next->next == NULL) {
            current = current->next;
            i = choice+1;
        }
        current = current->next;
    }
    cout << "Do you really want to modify " <<  current->firstName <<"'s data? (y/n): ";
    cin >> x;
    if (x =='y') {
        cout << "Please put a new data below." << endl;
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
        current->firstName = fn;
        current->lastName = ln;
        current->cource = course;
        current->section = section;
        current->overallGPA = GPA;
        cout << "Now you have the DB below" << endl;
        println();
        endTime = clock();
        totalTime = endTime-initiaiTime;
        cout << "The total time for the program is " <<totalTime << endl;
    }

}

void DataManagementHeader::printlnOnly(SDBNode *temp)
{
    std::cout << std::endl;
    std::cout<< "The student name is " << temp->firstName<< " " << temp->lastName << endl;;
    std::cout<< "She/He is taking " << temp->cource<< " " << temp->section << endl;
    std::cout << "Her/his overall GPA is " << temp->overallGPA << endl;
}

void DataManagementHeader::searchDB(string category, string value, bool gpa)
{
    SDBNode *temp = start;
    string letter = "There is no data equivalent to the input.", tempString;
    int categopryInt = stoi(category);
    int gpaInt= 0, gpaIntInput = 0;
    initiaiTime = clock();
    switch (categopryInt) {
        case 1:
            while (temp->next !=NULL) {
                if (temp->firstName == value) {
                    printlnOnly(temp);
                    letter ="";
                }
                temp = temp->next;
            }
            break;
        case 2:
            while (temp->next !=NULL) {
                if (temp->lastName == value) {
                    printlnOnly(temp);
                    letter ="";
                }
                temp = temp->next;
            }
        case 3:
            while (temp->next !=NULL) {
                if (temp->cource == value) {
                    printlnOnly(temp);
                    letter ="";
                }
                temp = temp->next;
            }
        case 4:
            while (temp->next !=NULL) {
                if (temp->section == value) {
                    printlnOnly(temp);
                    letter ="";
                }
                temp = temp->next;
            }
        case 5:
            if (!gpa) {
                while (temp->next !=NULL) {
                    if (temp->overallGPA == value) {
                        printlnOnly(temp);
                        letter ="";
                    }
                    temp = temp->next;
                }
            }
            else
            {
                gpaIntInput = stod(value);
               while (temp->next !=NULL) {
                   tempString = temp->overallGPA;
                   if (tempString == "") {
                   }else
                   {
                       gpaInt = stod(tempString);
                   }
                   if (gpaInt >= gpaIntInput) {
                       printlnOnly(temp);
                       letter ="";
                   }
                   temp = temp->next;
               }
            }
        default:
            break;
    }
    cout << letter << endl;
    cout << endl;
    endTime = clock();
    totalTime = endTime-initiaiTime;
    cout << "The total time for the program is " <<totalTime << endl;
}
