//
//  main.cpp
//  COMPtest
//
//  Created by Wataru Oshima on 2019/10/21.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

void zigzagfunc (int a[], int n) {
    bool ans = true;

    for (int i = 0; i < n-2; i++) {
        if (ans) {
            if (a[i] > a[i+1])
                swap(a[i], a[i+1]);
        } else {
        if (a[i] < a[i+1])
            swap(a[i], a[i+1]);

        }
        
        ans = !ans;
    }
}

void Cout (int a[], int b) {
    for (int p = 0; p < b; p++) {
        if (p != b-1)
        cout << a[p] << ", ";
        else
        cout << a[p] << "." << endl;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string a;
    int x;
    int zigzagarray[10];
    cout << "Enter 10 numbers." << endl;

    for (int i = 0; i < 10; i++) {
        cout << "type " << i+1 << " number: ";
        cin >> a;
        stringstream geek(a);
        geek >> x;
        zigzagarray[i] = x;
    }
    
       int n = sizeof(zigzagarray)/sizeof(zigzagarray[0]);
    cout << "Your original array is " ;
    Cout(zigzagarray, n);
    zigzagfunc(zigzagarray, n);
    cout << "The zig-zag array is ";
    Cout(zigzagarray, n);
    
    return 0;
}

