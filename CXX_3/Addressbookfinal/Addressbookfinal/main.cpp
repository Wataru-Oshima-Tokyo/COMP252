//
//  main.cpp
//  Linkedlist
//
//  Created by Wataru Oshima on 2020/03/09.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;
void printlist();
void printlistWithOnlyNames();
int deletingInformation(int x);
int insertNode(int x);

struct node{
    string name;
    string address;
    string phoneNumber;
    string DOB;
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
    string name1, address1, empty, phoneNumber1, DOB1;

    while(n!=-1){
        cout<<"Enter -1 to End. Or put any positve number to continue: ";
        cin >> n;
    if (i == 500) {
        cout << "you cannot add any more" << endl;
        return 500;
    } else if (n == -1) {
        return i;
    } else {
        getline(cin, empty);
        cout << "Please enter the name: ";
        getline(cin, name1);
        cout << "Please enter the address: ";
        getline(cin, address1);
        cout << "Please enter the phone number: ";
        getline(cin, phoneNumber1);
        cout << "Please enter the DOB (MMDDYYYY): ";
        getline(cin, DOB1);
    }
    
    temp = createNode();
    temp->name = name1;
    temp->address = address1;
    temp->phoneNumber = phoneNumber1;
    temp->DOB = DOB1;
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
    if (x == 0) {
        cout << "Yod do not have any members in your address book" << endl;
        return x;
    }
    int i, m, a = x;
    node *temp, *current;
    printlistWithOnlyNames();
    current = start;
    cout << "Who do you want to delete from your address book? Put the number of the person: ";
    cin >> i;
    if (i == 1) {
        cout << "   " <<current->name << endl;
    } else {
        for (int n = 1; n < i-1; n++) {
            current = current->next;
        }
        cout << "   " << current->next->name<< endl;
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
            printlistWithOnlyNames();
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
        cout <<  i <<". " << "Name: " << traverse->name<< endl;
        cout << "   " << "Address: " << traverse->address << endl;
        cout << "   " << "Phone number: " << traverse->phoneNumber << endl;
        cout << "   " << "BOD: " <<traverse->DOB<< endl;
        cout << endl;
        traverse = traverse->next;
        i = ++i;
        }
    }

void printlistWithOnlyNames() {
    int i = 1;
    node *traverse = start;

    while(traverse != NULL){
        cout <<  i <<". " << "Name: " << traverse->name<< endl;
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
