//
//  main.cpp
//  COMP250_Power
//
//  Created by Wataru Oshima on 2019/10/01.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>

double power(double a, double b) {
    double z;
    z = pow(a, b);
    return z;
}

int main(int argc, const char * argv[]) {

    double x, y, a, b, c;
    string n;

LOOP:

    cout << "Please put any two numbers.\nFirst number: ";
    cin >> x;
    cout << "Second number: ";
    cin >> y;

    a = power(x, y);
    b = power(y, x);
    cout << "The number which is the first number to the power of the second number is " << a << ". \nAnd the number which is the second number to the power of the first number is " << b << endl;
    c = a + b;
    cout << "The sum of them is " << c << endl;
    cout << "If you want to finish it, please put 'n' or just put any letter to continue: ";
    cin >> n;
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    if (n != "n") {
        goto LOOP;
    } else {
        goto LOOPEND;
    }
LOOPEND:
    cout << "Thank you for using this program. Bye!" << endl;
    return 0;
}
