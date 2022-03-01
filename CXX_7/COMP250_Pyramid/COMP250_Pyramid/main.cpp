//
//  main.cpp
//  COMP250_Pyramid
//
//  Created by Wataru Oshima on 2019/09/24.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int i, n, e, x;
    
    string blank, asterrisk, line;
    cout << "Enter a number: ";
    cin >> n;
    //put the original value of n into x which will be used for counting the number of *
    x = n;
    while ((n-1) >= 0) {
        //put the leading blank whose number is porportional to the "n"
        for (e = 1; e <= n; e++) {
        blank = " ";
        line = line + blank;
        }
            //put the "*" into "line" and it should be counted from x to (n-1)
            for (i = x; i != (n-1); i--) {
                if (i == n) {
                  // the first one should be 1 asterisk
                  asterrisk = "*";
                } else {
                  // after the secoond one, the number of asterisk will be added with 2 for each time
                  asterrisk = "**";
                }
                line = line + asterrisk;
            }
        cout << line << endl;
        // need to clear the line before getting new one
        line = "";
        n = n - 1;
    }
    
    return 0;
}
