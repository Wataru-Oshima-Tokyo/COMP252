//
//  main.cpp
//  FibonacchiwithRecursive
//
//  Created by Wataru Oshima on 2020/03/02.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int Fibonacci (int a, int b, int c) {
    int nthsum = 0;
    if (c == 1 ) {
        return a;
    } else if ( c == 2) {
        return b;
    } else {
        nthsum = Fibonacci(a, b, c-1) + (Fibonacci(a, b, c-2));
        return nthsum;
    }
}
int main(int argc, const char * argv[]) {
    cout << Fibonacci(2, 3, 7) << endl;
    return 0;
}
