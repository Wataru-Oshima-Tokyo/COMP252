//
//  main.cpp
//  COMP250A_Stringexamples
//
//  Created by Wataru Oshima on 2019/10/13.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//char str[100];
//cout << "Enter a string: ";
//cin >> str;
//cout << "You entered: " << str << endl;
//cout << "\nEnter another string: ";
//cin >> str;
//cout << "You entered: "<<str<<endl;
//return 0;
//}
////Example 2: C++ String to read a line of text
//#include <iostream>
//using namespace std;
//int main()
//{
//char str[100];
//cout << "Enter a string: ";
//cin.get(str, 100);
//cout << "You entered: " << str << endl;
//return 0;
//}
//
//Example 3: C++ string using string data type

//
//#include <iostream>
//using namespace std;
//int main()
//{
//// Declaring a string object
//string str;
//cout << "Enter a string: ";
//getline(cin, str);
//cout << "You entered: " << str << endl;
//return 0;
//}
//Passing String to a Function
#include <iostream>
using namespace std;
void display(char *);
void display(string);
int main()
{
string str1;
char str[100];
cout << "Enter a string: ";
getline(cin, str1);
cout << "Enter another string: ";
cin.get(str, 100, '\n');
display(str1);
display(str);
return 0;
}
void display(char s[])
{
cout << "Entered char array is: " << s << endl;
}
void display(string s)
{
cout << "Entered string is: " << s << endl;
}
