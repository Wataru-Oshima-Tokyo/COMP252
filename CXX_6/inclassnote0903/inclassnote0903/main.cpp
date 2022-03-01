//
//  main.cpp
//  inclassnote0903
//
//  Created by Wataru Oshima on 2019/09/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
//#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    int result = 54 + 6;
//
//    cout << result << endl;
    string name = "Wataru";
    string lname = " Oshima";
    string fname;
    fname = name + lname;
    int u,h,o; double c,w,p;
    
    cout << fname << endl;
    int x = 0;
    int y = 0;
    
    x = x +1;
    y = x;
    cout << "This is the velue of x = " << x << endl;
    cout << "This is the velue of y = " << y << endl;
    cout << "" << endl;
    x++;
    y = x;
    cout << "This is the velue of x = " << x << endl;
    cout << "This is the velue of y = " << y << endl;
    cout << "" << endl;
    ++x;
    y = x;
    cout << "This is the velue of x = " << x << endl;
    cout << "This is the velue of y = " << y << endl;
    cout << "" << endl;
    return 0;
}
