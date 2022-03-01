//
//  main.cpp
//  Address book
//
//  Created by Wataru Oshima on 2020/03/09.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


//a. Add or delete a new entry to the address book.
//b. Allow the user to save the data in the address book.

//Using classes, design an online address book to keep track of the names,
//addresses, phone numbers, and dates of birth of family members, close
//friends, and certain business associates. Your program should be able to
//handle a maximum of 500 entries.

//void addingInfo(Information &a, int b[], int c);
//void deletingInfo(Information &a);
//void printingInfo(Information &a);


struct Information{
    string firstname;
    string lastname;
    string address;
    long phoneNumber;
    string DOB;
    struct Information *next;
};

//linkedlist
Information *start = NULL;

Information *createInformation()
{
    Information *temp;
    temp = new Information;
    return temp;
}

void InsertInformation() {
    Information *temp, *previous;
    string name1, name2, address1, DOB1, empty, n;
    long phoneNumber1;
    cout << "Insert Info " << endl;
    while ( n!= "n"){
        temp = createInformation();
        std::cout << "Please enter the first name: ";
        cin >> name1;
        std::cout << "Please enter the first name: ";
        cin >> name2;
        std::cout << "Please enter the address: ";
        cin >> address1;
        std::cout << "Please enter the phone number without - and spaces: ";
        cin >> phoneNumber1;
        std::cout << "Please enter the DOB (MM/DD/YYYY): ";
        cin >> DOB1;
        temp->firstname = name1;
        temp->lastname = name2;
        temp->address = address1;
        temp->phoneNumber = phoneNumber1;
        temp->DOB = DOB1;
        temp ->next = NULL;
        if (start == NULL) {
            start = temp;
        } else {
            previous = start;
            while (previous->next != NULL) {
                previous = previous->next;
            }
            previous->next = temp;
        }
        cout << "If you are done, put 'n': ";
        cin >> n;
    }

}

void deletingInformation() {
    Information *temp, *current, *previous;
    current = start;
    while (current !=NULL) {
        if (current->next == NULL) {
            previous = current;
        }
        current = current -> next;
    }
    temp = current;
            cout << temp->firstname << endl;
}

void printlist(){
    int i=1;
    Information *previous = start;
    while (previous !=NULL) {
        cout << i <<". " <<   "The name is " << previous->firstname<< " " << previous->lastname << endl;
        cout <<  i <<". " << "The address is " << previous->address << endl;
        cout <<  i <<". " << "The phone number is " << previous->phoneNumber << endl;
        cout <<  i <<". " << "The BOD is " <<previous->DOB<< endl;
        cout << endl;
        previous = previous -> next;
        i = i+1;
        
    }
};

//std::istream & operator >> (std::istream &in, Information &c) {
//    std::cout << "Please enter your name: ";
//    in >> c.name;
//    getline(in, c.name);
//    std::cout << "Please enter your address: ";
//    getline(in, c.address);
//    std::cout << "Please enter your phone number without - and spaces: ";
//    in >> c.phoneNumber;
//    std::cout << "Please enter your DOB (MM/DD/YYYY): ";
//    in >> c.DOB;
//    return in;
//};
    
    
   
 
    
int main(int argc, const char * argv[]) {
    string falseStatement = "Your input is not valid. Please try again.";
    int option;
 Loop:
    do{
        try {
      cout<<"\n\n ***************** Main Menu ******************"<<endl;
      cout<<" 1. Add info"<<endl;
      cout<<" 2. Delete info"<<endl;
      cout<<" 3. See the info"<<endl;
      cout<<" 4. Exit"<<endl;
      cout << "Put your choice : ";
      cin>>option;
    if (!cin) {
    throw falseStatement;
    }
    }
    catch (string s) {
    cout << "Line 90: " << s << endl;
    break;
    }
      switch(option){
      case 1:
              InsertInformation();
             break;
      case 2:
             break;
      case 3:
              printlist();
             break;
          }
      } while(option != 3);
          return 0;
}
