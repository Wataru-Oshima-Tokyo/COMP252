//
//  main.cpp
//  Stack1
//
//  Created by Wataru Oshima on 2020/03/17.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "myStack.h"
using namespace std;

void testCopyConstructor(stackType<int> otherStack);

int main() {

    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);
    copyStack = stack;

    cout << "The elements of copyStack: ";
    while (!copyStack.isEmptyStack())
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;

    copyStack = stack;
    testCopyConstructor(stack);
    if (!stack.isEmptyStack()) {
        cout << "The original stack is not empty." << endl;
        cout << "The top element of the original stack: " << copyStack.top() << endl;
    }

    dummyStack = stack;

    cout << "The elements of dummyStack: ";
    while (!dummyStack.isEmptyStack()) {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;

    return 0;
}

void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack()) {
        cout << "OtherStack is not empty.\nThe top element of otherStack: " << otherStack.top() << endl;
    }
}

