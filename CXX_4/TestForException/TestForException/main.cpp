//
//  main.cpp
//  TestForException
//
//  Created by Wataru Oshima on 2020/02/25.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
#include "myException.h"
using namespace std;

//void functionA() throw(myException);
//void functionB() throw(myException);
//void functionC() throw(myException);
int main(int argc, const char * argv[]) {
    string sentence, str1, str2, str3;

    try {
        sentence = "Testing sgring exceptions!";
        cout << "Line 11: sentence = " << sentence << endl;
        cout << "Line 12: sentence.length() = " << static_cast<int>(sentence.length()) << endl;
        str1 = sentence.substr(8, 20);
        cout << "Line 14: str1 = " << str1 << endl;
        str2 = sentence.substr(10, 12);
        cout << "Line 16: str2 = " << str2 << endl;
        str3 = "Exception handling. " + sentence;
        cout << "Line 18: str3 = " << str3 << endl;
    } catch (out_of_range re) {
        cout << "Line 22: In the out_of_range catch block: " << re.what() << endl;
    } catch (length_error le) {
        cout << "Line 26: In the length error catch block: " << le.what() << endl;
    }

}
