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

class Information;
void addingInfo(Information &a, int b[], int c);
void deletingInfo(Information &a);
void printingInfo(Information &a);


class Information{
public:
    class Information *next;
        friend std::ostream & operator << (std::ostream &out, const Information &c);
        friend std::istream & operator >> (std::istream &in, Information &c);

        
        Information();
        Information(string a, string b, int c, int d) {
        name = a;
        address = b;
        phoneNumber = c;
        DOB = d;
    };
        
        string name;
        string address;
        long phoneNumber;
        string DOB;
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
    Information info("", "", 0, 0);
    int n;
    cout << "Insert Info";
    cout << "If you are done, put 0";
    cin >> n;
    while ( n!=0){
       cin >> info;
//        temp = createInformation();
        temp->name = info.name;
        temp->address = info.address;
        temp->phoneNumber = info.phoneNumber;
        temp->DOB = info.DOB;
        
        if (start == NULL) {
            start = temp;
        } else {
            previous = temp;
            while (previous->next != NULL) {
                previous = previous->next;
            }
            previous->next = temp;
        }
        cout << "Insert Info";
        cout << "If you are done, put 0";
        cin >> n;
    }

}

std::ostream & operator << (std::ostream &out, const Information &c) {
    out << " The information is below \nName: " << c.name << "\nAddress: " << c.address << "\nPhone number: " << c.phoneNumber << "\nDate of Birth: " << c.DOB << endl;
    return out;
};

std::istream & operator >> (std::istream &in, Information &c) {
    std::cout << "Please enter your name: ";
    in >> c.name;
    getline(in, c.name);
    std::cout << "Please enter your address: ";
    getline(in, c.address);
    std::cout << "Please enter your phone number without - and spaces: ";
    in >> c.phoneNumber;
    std::cout << "Please enter your DOB (MM/DD/YYYY): ";
    in >> c.DOB;
    return in;
};
    
    
void addingInfo(Information &a, int b[], int c) {
        cin >> a;
}
    
void deletingInfo(Information &a) {
        cin >> a;
}

void printingInfo(Information &a) {
        cout << a;
}
    
    
int main(int argc, const char * argv[]) {
    Information info("", "", 0, 0);
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
              deletingInfo(info);
             break;
      case 3:
              printingInfo(info);
             break;
          }
      } while(option != 3);
          return 0;
}
