//
//  main.cpp
//  wataru_test1
//
//  Created by Wataru Oshima on 2019/08/27.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//
//  comments are always good to tell what I want to do.

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){

//  declaration
    int input1;
    int input2;
    int input3;
    int output;

//    intraction
    cout << "Please enter your birth year \n";
    cin >> input1;
    cout << "Please enter your birth month \n";
    cin >> input2;
    cout << "Please enter your birth day \n";
    cin >> input3;
    
//  calculation
    int today = 2018 * 365 + 30 * 7 + 27;
    int birthday = (input1 -1)* 365 + (input2 - 1) *30 + input3;
    output =  today - birthday;
    cout << "The days you have lived since you were born is: \n";
    cout << output <<endl;
    
    return 0;
}
