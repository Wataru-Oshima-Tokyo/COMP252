//
//  main.cpp
//  COMP250A_class
//
//  Created by Wataru Oshima on 2019/10/24.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    ofstream myStream ("test.txt");
    if (myStream.is_open()) {
        myStream << "This is a test for class. \n";
        myStream << "This is another line fo this test. \n";
        myStream.close();
    } else {
        cout << "It's already open";
    }
    
    string line;
    ifstream myfile ("test.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        } else {
            cout << "unable to open the file. \n";
        
    }
    
    
    return 0;
}
