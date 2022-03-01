//
//  main.cpp
//  COMP250_1105class
//
//  Created by Wataru Oshima on 2019/11/05.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Human {
    // Client: int main @42
    //all valuables are private
    
public:
    Human(int a) {
        age = a;
        
    };
    //this one enters the age frm the cons
    int age;
    //inline declaring function
    void set_age_from_user(){
        int inputAge;
        cout << "Please enter the age here: ";
        cin >> inputAge;
        if (inputAge > 0 && inputAge < 150) {
            age = inputAge;
        } else {
            cout << "What you entered is invalid. Plesase try again." << endl;
        }
    };  // setter function
    int get_age();  // getter function
    void display_age() {
        cout << "Your object has an age of = " << age << endl;
    };
    
};
//out of line declaring function
int Human::get_age(){
    return age;
};
int main(int argc, const char * argv[]) {
    // 'main' is a client of the class 'Human'
    Human myHuman;
    myHuman.set_age_from_user();
    myHuman.display_age();
    return 0;
}
