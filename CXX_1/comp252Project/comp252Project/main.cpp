//
//  main.cpp
//  comp252Project
//
//  Created by Wataru Oshima on 2020/05/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "RDPHeader.h"
#include <stdlib.h>
using namespace std;

string errormessage = "The input is invalid. Please try again.";

void case1(RDPH rdph);
void case2(RDPH rdph);
void case3(RDPH rdph);
void case4(RDPH rdph);
void case5(RDPH rdph);
void case6(RDPH rdph);
int checkNDL(RDPH rdph, int deapthInput, bool valid);
string checkPG(RDPH rdph, int deapthInput, int divingTime, bool flag);
string checkPGMultiple(RDPH rdph, string pressureGroup, int surfaceInterval);
int checkNDLMultiple(RDPH rdph, int deapthInput, string pressureGroup, bool flag);
int checkDeapthMultiple(RDPH rdph, string pressureGroup, int divingTime);
int checkTBT(RDPH rdph, int deapthInputForSecond , int dinvingTimeForSecond);
int converterDeapth(int deapthInput);
void suggestionForSafety(string pressureGroup);

void case1(RDPH rdph)
{
    rdph.initializeNode();
    int deapthInput;
    try {
        cout << "Please choose the depath (metric) you want to dive in from the below list" << endl;
        rdph.println();
        cout << ": ";
        cin >> deapthInput;
        deapthInput = converterDeapth(deapthInput);
        if (!cin) {
            throw errormessage;
        }
        checkNDL(rdph, deapthInput, true);
    } catch (string s) {
        cout << errormessage << endl;
    }
}

void case2(RDPH rdph){
    rdph.initializeNode();
    int divingTime=0;
    int deapthInput=0;
    string pressureGroup;
    try {
        cout << "Please choose the depath (metric) you want to dive in from the below list." << endl;
        rdph.println();
        cout << "Put here: ";
        cin >> deapthInput;
        deapthInput = converterDeapth(deapthInput);
        if (!cin) {
            throw errormessage;
        }
        checkNDL(rdph, deapthInput, true);
        cout << "How long are you planning to dive? Please put the miniute here: ";
        cin >>divingTime;
        if (!cin) {
            throw errormessage;
        }
        checkPG(rdph, deapthInput, divingTime, true);
    } catch (string s) {
        cout << errormessage << endl;
    }
}

void case3 (RDPH rdph)
{
    rdph.initializeNode();
    int divingTime=0;
    int deapthInputFirst=0;
    int deapthInputSecond=0;
    int surfaceInterval=0;
    string pressureGoup, pressureGroupforSecond;
        try {
            cout << "Please choose the depath (metric) you want to dive in for the first time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputFirst;
            deapthInputFirst = converterDeapth(deapthInputFirst);
            if (!cin) {
                throw errormessage;
            }
            checkNDL(rdph, deapthInputFirst, false);
            cout << "How long are you planning to dive for your first dive? Please put miniutes here: ";
            cin >>divingTime;
            if (!cin) {
                throw errormessage;
            
            }
            pressureGoup = checkPG(rdph, deapthInputFirst, divingTime, true);
            suggestionForSafety(pressureGoup);
            cout << "Please put the interval time you are taking after the first dive in minute: ";
            cin >> surfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGroupforSecond = checkPGMultiple(rdph, pressureGoup, surfaceInterval);
            cout << "Please choose the depath (metric) you want to dive in for the second time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputSecond;
            deapthInputSecond = converterDeapth(deapthInputSecond);
            if (!cin) {
                throw errormessage;
            }
            checkNDL(rdph, deapthInputSecond, false);
            checkNDLMultiple(rdph, deapthInputSecond, pressureGroupforSecond, true);
        } catch (string s) {
            cout << errormessage << endl;
        }
}


void case4(RDPH rdph)
{
    rdph.initializeNode();
    int divingTimeForFirst=0;
    int deapthInputFirst=0;
    int divingTimeForSecond=0;
    int surfaceInterval=0;
    string pressureGoup, pressureGroupforSecond;
        try {
            cout << "Please choose the depath (metric) you want to dive in for the first time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputFirst;
            deapthInputFirst = converterDeapth(deapthInputFirst);
            if (!cin) {
                throw errormessage;
            }
            checkNDL(rdph, deapthInputFirst, false);
            cout << "How long are you planning to dive for your first dive? Please put miniutes here: ";
            cin >>divingTimeForFirst;
            if (!cin) {
                throw errormessage;
            
            }
            pressureGoup = checkPG(rdph, deapthInputFirst, divingTimeForFirst, true);
            suggestionForSafety(pressureGoup);
            cout << "Please put the interval time you are taking after the first dive in minute: ";
            cin >> surfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGroupforSecond = checkPGMultiple(rdph, pressureGoup, surfaceInterval);
            if (!cin) {
                throw errormessage;
            }
            cout << "Please put the time you want to dive in for the second time in minute: ";
            cin >> divingTimeForSecond;
            if (!cin) {
                throw errormessage;
            }
            checkDeapthMultiple(rdph, pressureGroupforSecond, divingTimeForSecond);
            } catch (string s) {
                cout << errormessage << endl;
            }
    
}


void case5(RDPH rdph)
{
    rdph.initializeNode();
    int divingTimeForFirst=0;
    int deapthInputFirst=0;
    int deapthInputForSecond=0;
    int divingTimeForSecond=0;
    int firstSurfaceInterval=0;
    int tbt = 0;
    int deapthInputForThird = 0;
    int secondSurfaceInterval = 0;
    string pressureGoup, pressureGroupforSecond, pressureGroupforThird, pressureGoupAfterSecondinterval;
        try {
            cout << "Please choose the depath you want to dive in for the first time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputFirst;
            deapthInputFirst = converterDeapth(deapthInputFirst);
            if (!cin) {
                throw errormessage;
            }
            checkNDL(rdph, deapthInputFirst, false);
            cout << "How long are you planning to dive for your first dive? Please put miniute here: ";
            cin >>divingTimeForFirst;
            if (!cin) {
                throw errormessage;
            
            }
            pressureGoup = checkPG(rdph, deapthInputFirst, divingTimeForFirst, true);
            suggestionForSafety(pressureGoup);
            cout << "Please put the interval time you are taking after the first dive in minute: ";
            cin >> firstSurfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGroupforSecond = checkPGMultiple(rdph, pressureGoup, firstSurfaceInterval);
            if (!cin) {
                throw errormessage;
            }
            
            cout << "Please put the deapth (metric) you want to dive in for the second time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputForSecond;
            deapthInputForSecond = converterDeapth(deapthInputForSecond);
            if (!cin) {
                throw errormessage;
            }
            cout << "How long are you planning to dive for your second dive? Please put miniute here: ";
            cin >> divingTimeForSecond;
            if (!cin) {
                throw errormessage;
            }
            tbt = checkTBT(rdph, deapthInputForSecond, divingTimeForSecond);
            pressureGroupforThird = checkPG(rdph, deapthInputForSecond, tbt, true);
            suggestionForSafety(pressureGroupforThird);
            cout << "Please put the interval time you are taking after the second dive in minute: ";
            cin >> secondSurfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGoupAfterSecondinterval = checkPGMultiple(rdph, pressureGroupforThird, secondSurfaceInterval);
            cout << "Please put the deapth (metric) you want to dive in for the third time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputForThird;
            deapthInputForThird = converterDeapth(deapthInputForThird);
            if (!cin) {
                throw errormessage;
            }
            checkNDLMultiple(rdph, deapthInputForThird, pressureGoupAfterSecondinterval, false);
            } catch (string s) {
                cout << errormessage << endl;
            }

}
void case6(RDPH rdph)
{
    rdph.initializeNode();
    int divingTimeForFirst=0;
    int deapthInputFirst=0;
    int deapthInputForSecond=0;
    int divingTimeForSecond=0;
    int firstSurfaceInterval=0;
    int tbt = 0;
    int divingTimeForThird = 0;
    int secondSurfaceInterval = 0;
    string pressureGoup, pressureGroupforSecond, pressureGroupforThird, pressureGrouopForThirdAfterinterval;
        try {
            cout << "Please choose the depath you want to dive in for the first time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputFirst;
            deapthInputFirst = converterDeapth(deapthInputFirst);
            if (!cin) {
                throw errormessage;
            }
            checkNDL(rdph, deapthInputFirst, false);
            cout << "How long are you planning to dive for your first dive? Please put miniute here: ";
            cin >>divingTimeForFirst;
            if (!cin) {
                throw errormessage;
            
            }
            pressureGoup = checkPG(rdph, deapthInputFirst, divingTimeForFirst, true);
            suggestionForSafety(pressureGoup);
            cout << "Please put the interval time you are taking after the first dive in minute: ";
            cin >> firstSurfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGroupforSecond = checkPGMultiple(rdph, pressureGoup, firstSurfaceInterval);
            if (!cin) {
                throw errormessage;
            }
            
            cout << "Please put the deapth (metric) you want to dive in for the second time from the below list." << endl;
            rdph.println();
            cout << "Put here: ";
            cin >> deapthInputForSecond;
            deapthInputForSecond = converterDeapth(deapthInputForSecond);
            if (!cin) {
                throw errormessage;
            }
            cout << "How long are you planning to dive for your second dive? Please put miniute here: ";
            cin >> divingTimeForSecond;
            if (!cin) {
                throw errormessage;
            }
            tbt = checkTBT(rdph, deapthInputForSecond, divingTimeForSecond);
            pressureGroupforThird = checkPG(rdph, deapthInputForSecond, tbt, true);
            suggestionForSafety(pressureGroupforThird);
            cout << "Please put the interval time you are taking after the second dive in minute: ";
            cin >> secondSurfaceInterval;
            if (!cin) {
                throw errormessage;
            }
            pressureGrouopForThirdAfterinterval = checkPGMultiple(rdph, pressureGroupforThird, secondSurfaceInterval);
            cout << "How long are you planning to dive for your third dive? Please put miniute here: ";
            cin >> divingTimeForThird;
            if (!cin) {
                throw errormessage;
            }
            checkDeapthMultiple(rdph, pressureGrouopForThirdAfterinterval, divingTimeForThird);
            } catch (string s) {
                cout << errormessage << endl;
            }
            
}

//************ Functions are below *******************************

//checking the no decompression limit
int checkNDL(RDPH rdph, int deapthInput, bool valid)
{
    int ndl;
    bool flag = false;
    ndl = rdph.searchNDL(deapthInput);
    if (valid) {
        if (ndl == 0) {
            cout << " You cannot exceed 42 m for recreational dive" << endl;
            flag = true;
        } else if (ndl >0 ) {
            cout << "The NDL is " << ndl << endl;
        } else {
            cout <<"The deapht "<< deapthInput << " cannot be found. Please put the below number for yoru diving" << endl;
            rdph.println();
            flag = true;
        }
    }
    else
    {
        if (ndl == 0) {
            cout << " You cannot exceed 42 m for recreational dive" << endl;
            flag = true;
        }
        else if (ndl >0 )
        {
         
        }
        else
        {
            cout <<"The deaph "<< deapthInput << " cannot be found. Please put the below number for yoru diving" << endl;
            rdph.println();
            flag = true;
        }
    }
    if (flag) {
        exit(5);
    }
    return ndl;
}

//checking the pressue group before the surface interval
string checkPG(RDPH rdph, int deapthInput, int divingTime, bool flag)
{
    string pressureGroup;
    pressureGroup = rdph.searchPG(deapthInput, divingTime);
    if (flag) {
        if (pressureGroup != "") {
            cout << "Your Pressure group is " << pressureGroup << endl;
        }
    }
    else
    {
    }
    
    return pressureGroup;
}

//checking the pressure group after the interval
string checkPGMultiple(RDPH rdph, string pressureGroup, int surfaceInterval)
{
    string PGMultiple = rdph.searchPGMultiple(pressureGroup, surfaceInterval);
    cout << "Your Pressure group for the seoncd is " << PGMultiple << endl;
    return PGMultiple;
}

//checking no decompression limit after the interval
int checkNDLMultiple(RDPH rdph, int deapthInput, string pressureGroup, bool flag)
{
    int x;
    x = rdph.searchNDL(deapthInput, pressureGroup);
    if (flag) {
        cout << "The NDL for the second dive is " << x << endl;
    }
    else
    {
        cout << "The NDL for the third dive is " << x << endl;
    }
    return x;
}

//checking the deapth the user can dive in after the inteval
int checkDeapthMultiple(RDPH rdph, string pressureGroup, int divingTime)
{
    int x;
    x = rdph.checkDeapthForSecond(pressureGroup, divingTime);
    cout << "The maximum deapth you can dive in for the second time is " << x << " m." <<endl;
    return x;
}

    
//cheking total bottom time
int checkTBT(RDPH rdph, int deapthInputForSecond , int dinvingTimeForSecond)
    {
        int x;
        x = rdph.checkTBT(deapthInputForSecond, dinvingTimeForSecond);
        if (x !=-1) {
            cout << "The TBT for the second time is " << x << endl;
        }
        else
        {
            cout << "You cannot dive the deapth for your safety." << endl;
            exit(1);
        }
        return x;
        
    }

//If a user typed the deapth that is not int the list, then change the value to the valid one (rounded up)
int converterDeapth(int deapthInput)
{
    int x=0;
    if (deapthInput <=10) {
        x = 10;
    }
    else if (deapthInput >10 && deapthInput <=12)
    {
        x = 12;
    }
    else if (deapthInput >12 && deapthInput <=14)
    {
        x = 14;
    }
    else if (deapthInput >14 && deapthInput <=16)
    {
        x = 16;
    }
    else if (deapthInput >16 && deapthInput <=18)
    {
        x = 18;
    }
    else if (deapthInput >18 && deapthInput <=20)
    {
        x = 20;
    }
    else if (deapthInput >20 && deapthInput <=22)
    {
        x = 22;
    }
    else if (deapthInput >22 && deapthInput <=25)
    {
        x = 25;
    }
    else if (deapthInput >25 && deapthInput <=30)
    {
        x = 30;
    }
    else if (deapthInput >30 && deapthInput <=35)
    {
        x = 35;
    }
    else if (deapthInput >35 && deapthInput <= 40)
    {
        x = 40;
    }
    else if (deapthInput >40 && deapthInput <=42)
    {
        x = 42;
    }
    else {
        x = -1;
    }
    return x;
}

//If pressure group is W ~ Z, then show a warning comment
void suggestionForSafety(string pressureGroup)
{
    if (pressureGroup == "W" || pressureGroup == "X") {
        cout << "You shoud take a surface interval more than 1 hour for your saftety." << endl;
    } else if (pressureGroup == "Y" || pressureGroup == "Z") {
        cout << "You shoud take a surface interval more than 3 hour for your saftety." << endl;
    }
    else
    {
        
    }
}
    
//***********************Functions are avobe *********************************







int main(int argc, const char * argv[]) {
    RDPH rdph;
    int choice;
    cout <<"********************************************************************************************" << endl;
    cout <<"Please choose your option" << endl;
    cout << "1. Single Dive (know the depth you want to dive to)." << endl;
    cout << "2. Single Dive (know the depth you want to dive to and the time you want to spend there)" << endl;
    cout << "3. Double Dive (know the depth and time for dive one and depth for dive two plus the surface interval)" <<endl;
    cout << "4. Double Dive (know the depth and time for dive one and time for dive two plus the surface interval.) "<< endl;
    cout << "5. Multiple Dive (know the depth and time for both dives one and two and depth for dive three plus the surface intervals.)" << endl;
    cout << "6. Multiple Dive (know the depth and time for both dives one and two and time for dive three plus the surface intervals.)" << endl;
    cout <<"********************************************************************************************" << endl;
    cout << "Put here: ";
    cin >> choice;
    switch (choice) {
        case 1:
            case1(rdph);
            break;
        case 2:
            case2(rdph);
        break;
        case 3:
            case3(rdph);
        break;
        case 4:
            case4(rdph);
        break;
        case 5:
            case5(rdph);
        break;
        case 6:
            case6(rdph);
        break;
        default:
            cout << errormessage << endl;
            break;
    }
    return 0;
}
