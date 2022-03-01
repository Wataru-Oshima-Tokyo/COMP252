//
//  main.cpp
//  Linkedlist
//
//  Created by Wataru Oshima on 2020/03/09.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

/*
 Develop code to satisfy the following requirements;

 Create a list containing integers :     7, 5, 16, 8
 Enter from user and add an integer (i.e. number 25) to the front of the list
 Enter from user and add an integer (i.e. number 13) to the back of the list
 Enter from user and Insert an integer before 16 by searching (i.e. number 14)
 Iterate and print values of the list
 If using the example values above,  your output should look like this:
 */
#include <iostream>
using namespace std;
int stack[7], n = 7, top = -1;


struct node {
    int data;
    struct node *next;
};

node *start=NULL;
node *createNode(){
    node *temp;
    temp = new node;
    return temp;
}

void initializedNode(int a,int b, int c, int d){
    node *temp,*traverse;
    int n = 0;
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                n = a;
                break;
             case 1:
                n = b;
                break;
            case 2:
                n = c;
            break;
            case 3:
                n = d;
            break;
            default:
                break;
        }
        temp = createNode();
        temp->data = n;
        temp->next = NULL;
        if(start == NULL){
            start = temp;
        }
        else{
            traverse = start;
            while(traverse->next != NULL){
                traverse= traverse->next;
            }
            traverse->next= temp;
            }
    }
    
}

void topNode(int top){
    node *temp,*traverse;
    temp = createNode();
    traverse = createNode();
    temp->data = start ->data;
    temp->next = start->next;
    start = traverse;
    traverse->data = top;
    traverse->next = temp;
}

void bottomNode(int bottom){
    node *temp,*traverse;
    temp = createNode();
    traverse = start;
    while(traverse->next != NULL){
        traverse = traverse->next;
    }
    traverse->next= temp;
    temp->data = bottom;
    temp->next = NULL;
    
}

void insertNode(int insert){
    node *temp,*traverse, *nextnext;
    temp = createNode();
    traverse = start;
    while(traverse->next->data != 16){
        traverse = traverse->next;
    }
    nextnext = traverse ->next;
    traverse->next= temp;
    temp->data = insert;
    temp->next = nextnext;
}

void printlist(){
    int i = 1;
    node *traverse = start;
    cout << "This is the list you currently have." << endl;
    cout << endl;
    while(traverse != NULL){

        cout<<traverse->data<<endl;
        traverse = traverse->next;
        i = ++i;
        }
    }
void inputValues() {
    int n;
    for (int i = 0; i < 4; i++) {
        n = 0;
        switch (i) {
            case 0:
                
                cout << "please put a number which you want add to the front of the list: " << endl;
                cin >> n;
                if (cin.fail()) {
                    cout << "The input is invalid." <<endl;
                    i = 5;
                } else {
                   topNode(n);
                }
                break;
            case 1:
                cout << "please put a number which you want add to the back of the list: " << endl;
                cin >> n;
                if (cin.fail()) {
                    cout << "The input is invalid." <<endl;
                    i = 5;
                } else {
                    bottomNode(n);
                }
                break;
            case 2:
                cout << "please put a number which you want add before 16: " << endl;
                cin >> n;
                if (cin.fail()) {
                    cout << "The input is invalid." <<endl;
                    i = 5;
                } else {
                    insertNode(n);
                }
            break;
            case 3:
               printlist();
            default:
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    initializedNode(7, 5, 16, 8);
    printlist();
    cout << endl;
    inputValues();
    return 0;
}
