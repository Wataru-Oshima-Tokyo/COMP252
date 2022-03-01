//
//  main.cpp
//  StackImplimentationExample
//
//  Created by Wataru Oshima on 2020/03/30.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "myStack.h"
#include <array>
using namespace std;
void println ();
void descending();
int factor(int n);
void factorWithN(int c, int n);
int i = 0;
int myArray[20];
string errorcode = "The input is invalid.";
stackType<int> stack(100);


int factor(int n) {
    stack.initializeStack();
    if (n%2 == 0) {
        stack.push(2);
        n = n/2;
        if (n==1) {
            return 0;
        }
    }
    factorWithN(n, 3);
    return 0;
}

void factorWithN(int n, int p) {
    if (n == p || n <p) {
        stack.push(n);
    }  else if (n%p == 0) {
        stack.push(p);
        n = n/p;
        factorWithN(n, p);
    } else {
        p = p + 2;
        factorWithN(n, p);
    }
}
 
void println (int x) {
    switch (i) {
        case 1:
            cout << "The prime factors for " << x <<" is ";
            break;
        default:
            cout << "The prime factors for " << x <<" are ";
            break;
    }
    
    for (int z = 0; z < i; z++) {
        cout << myArray[z] << " ";
    }
    cout << endl;
}

void descending(int x) {
    int temp = 0;
    while (!stack.isEmptyStack()) {
        myArray[i] = stack.top();
        i = i + 1;
        stack.pop();
    }
    if (i > 1) {
        for (int m = 0; m < i; m++) {
            for (int j = m+1; j <i; j++) {
                if (myArray[m] > myArray[j]) {
                    temp = myArray[j];
                    myArray[j] = myArray[m];
                    myArray[m] = temp;
                }
            }
        }
        
    }
    println(x);
}




int main()
{
    int y;
    try {
        cout << "Enter the number :";
        cin >> y;
        if (!cin) {
            throw errorcode;
    } else if (y <=0){
            throw y;
        }
    else {
        factor(y);
        descending(y);
    }
    } catch (int x) {
        cout << "You entered " << x << ". It should be more than 0. " << endl;
    } catch (string s) {
        cout << s << endl;
    }
 
return 0;
}
