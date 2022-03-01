//
//  main.cpp
//  Queue.HW
//
//  Created by Wataru Oshima on 2020/04/08.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "myStack.h"
using namespace std;
int main(int argc, const char * argv[]) {
    stackType<double> stack(50);

    double num;
    double arraynumber[10] = {25, 64, -3, 6.25, 36, -4.5, 86, 14, -12, 9};
    for (int i = 9; i>=0; i--) {
        num = arraynumber[i];
        if (num >0)
            num = sqrt(num);
            else num = pow(num,2);
        
            stack.push(num);
    }
    
        while (!stack.isEmptyStack()) {
            cout << stack.top() << " ";
            stack.pop();
        }
    cout << endl;
        
    
    return 0;
}
