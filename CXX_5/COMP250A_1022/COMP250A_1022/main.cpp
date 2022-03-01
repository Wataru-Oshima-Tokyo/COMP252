//
//  main.cpp
//  COMP250A_1022
//
//  Created by Wataru Oshima on 2019/10/22.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    string fullname, firstname, lastname;
    getline(cin, fullname);
    cout << fullname << endl;
    n = fullname.length();
    bool ans = true;
    for (int i = 0; i < n; i ++) {
        if (ans) {
            firstname = firstname + fullname[i];
            if (fullname[i+1] == ' ') {
                i = i+1;
                ans = false;
            }
        } else {
            lastname = lastname + fullname[i];
        }
        
    
    }
    
    cout << lastname << endl;
    cout << firstname << endl;

    return 0;
}
