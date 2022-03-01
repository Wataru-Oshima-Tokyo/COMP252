//
//  main.cpp
//  StackPractice
//
//  Created by Wataru Oshima on 2020/03/17.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>

using namespace std;
string stack[50];
int n = 50, top = -1;

void push(string val) {
    if (top >= n-1) {
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top <=-1) {
        cout << "Stack Underflow" << endl;
    } else {
        top--;
    }
}

void display() {
    for (int i = top; i >=0; i--) {
        cout << stack[i] << endl;
    }
}
int main(int argc, const char * argv[]) {
    int ch;
    string val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    do {
       cout<<"Enter your choice: "<<endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to be pushed";
                cin >>val;
                push(val);
                break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "The input is invalid" << endl;
                break;
        }
    } while (ch != 4);
    return 0;
}
