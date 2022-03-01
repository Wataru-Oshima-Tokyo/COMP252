//
//  main.cpp
//  COMP250_InClassProject
//
//  Created by Wataru Oshima on 2019/09/24.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int n, m;
    string y;
    int current = 1;
    int previous1 = 0;
    int previous2 = 0;
    string totalNumber;

    cout << "Please enter a number: ";
    cin >> n ;
    //Becasue I already put "1" into the "cuurent"
    n = n - 1;
    //put "n" into "m" for confirm the first time in loop.
    m = n;
    if ( n < 0 ) {
        totalNumber = "nothing";
    }
    while (n >= 0) {
        y = to_string(current);
        //only for the first time, the number should be first on the line
        if (n == m) {
            totalNumber = y;
        } else {
        //from the second time, "," shoudl be included before the number.
            totalNumber = totalNumber + ", " + y;
        }
        
        previous1 = current;
        current = current + previous2;
        previous2 = previous1;
        n = n - 1;
    }
    
    cout << "Fibonacci Series are: \n" << totalNumber << endl;
    return 0;
}
