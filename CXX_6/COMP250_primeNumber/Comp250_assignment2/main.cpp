//
//  main.cpp
//  Comp250_assignment2
//
//  Created by Wataru Oshima on 2019/09/18.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int n,A,B,C;
    string x;
    
    int a = 2;
    string totalNumber = "2";
    cout << "Please enter a number: ";
    cin >> n;
    if (n==0) {
        totalNumber = "nothing.";
    }
    n = n - 2;
    if (n >= 0) {
        a = a + 1;
        x = to_string(a);
        totalNumber = totalNumber + ", " +x;
    }
    while (n > 0) {
        a = a + 2;
        A = a%3;
        B = a%5;
        C = a%7;
        if ((A != 0 && B != 0 && C !=0) || a == 3 || a == 5 || a == 7){
            x = to_string(a);
            totalNumber = totalNumber + ", " +x;
            n = n -1;
        }
    }
    
    cout << "The prime numbers you want are \n" <<totalNumber << endl;
    
    return 0;
}
