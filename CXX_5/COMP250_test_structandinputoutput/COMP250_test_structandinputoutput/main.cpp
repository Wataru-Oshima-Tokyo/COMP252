//
//  main.cpp
//  COMP250_test_structandinputoutput
//
//  Created by Wataru Oshima on 2019/11/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Output () {
    
    for (int i = 0; i <4; i++) {
        int studentNumber[4] = {1,2,3,4};
        string stu = "student";
        string number = to_string(studentNumber[i]);
            stu = stu + number + ".txt";
            cout << stu;
            if (myStream.is_open()) {
                myStream << "This is a test for class. \n";
                myStream << "This is another line fo this test. \n";
                myStream.close();
            } else {
                cout << "It's already open";
            }
    }
    
    return 0;
}
int main(int argc, const char * argv[]) {
    Output();
    
//    string line;
//    ifstream myfile ("test.txt");
//    if (myfile.is_open()) {
//        while (getline(myfile, line)) {
//            cout << line << endl;
//        }
//        } else {
//            cout << "unable to open the file. \n";
        
//    }
    
    
    return 0;
}
