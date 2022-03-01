//
//  main.cpp
//  Linkedlist
//
//  Created by Wataru Oshima on 2020/03/09.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include<iostream>

using namespace std;
void printlist();
struct node{
    int data;
    struct node *next;
};

node *start=NULL;
node *createNode(){
    node *temp;
    temp = new node;
    return temp;
}

int insertNode(int x){
    node *temp,*traverse;
    int n=0, i = x;
    
    while(n!=-1){
    if (i >= 5) {
        cout << "you cannot add any more" << endl;
        return 5;
    } else if (n == -1) {
        return i;
    } else {
        cout<<"Enter -1 to End"<<endl;
        cout<<"Enter the values to be added in List"<<endl;
        cin>>n;
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
    //for stopping it, once it reaches the certain number
        i = i +1;
    }
    return i;
}

//I need to figure out how to delete the link, i mean how to pass to the next next...
int deletingInformation(int x) {
    int i, m, a = x;
    node *temp, *current;
    printlist();
    current = start;
    cout << "Who do you want to delete from your address book? Put the number of the person: ";
    cin >> i;
    if (i == 1) {
        cout << current->data << endl;
    } else {
        for (int n = 1; n < i-1; n++) {
            current = current->next;
        }
        cout << current->next->data << endl;
    }
    
    cout << "Do you really erase the person? if yes, put 1: ";
    cin >> m;
    switch (m) {
        case 1:
            if (i == 1) {
                //if so, the second address is the start point.
                temp = current->next;
                start = temp;
                current = start;
                delete temp;
            } else {
                temp = current->next;
                    current->next = temp->next;
                    delete temp;
            }
            printlist();
            a = a-1;
            return a;
            break;
        default:
            return a;
            break;
            }
    
}


void printlist(){
    int i = 1;
    node *traverse = start;

    while(traverse != NULL){
        
        cout<< i <<". " << traverse->data<<endl;
        traverse = traverse->next;
        i = ++i;
        }
    }



int main(){
  int option;
    int x = 0;
  do{
      
    cout<<"\n\n ***************** Main Menu ******************"<<endl;
    cout<<" 1. Create List"<<endl;
    cout<<" 2. Print List"<<endl;
      cout<<" 3. delete List"<<endl;
    cout<<" 4. Exit"<<endl;
      cout << "Now you have " << x << " members in your address book" << endl;
      cout << "put your choice: ";
    cin>>option;
    switch(option){
    case 1:
           x = insertNode(x);
           break;
    case 2:
            printlist();
           break;
    case 3:
            x = deletingInformation(x);
            break;
        }
    } while(option != 4);
        return 0;
}
