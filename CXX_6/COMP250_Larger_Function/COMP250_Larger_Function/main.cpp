//
//  main.cpp
//  COMP250_Larger_Function
//
//  Created by Wataru Oshima on 2019/10/01.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

double larger(double x, double y) {
    if (x > y) {
        return x;
    }
        return y;
}

int main(int argc, const char * argv[]) {
    
    int a, b, max;
    cout << "Please put two numbers. \n First: ";
    cin >> a;
    cout << "Second: ";
    cin >> b;
    
    max = larger(a, b);
    
    cout << "The larger number is " << max << endl;
    
    return 0;
}
