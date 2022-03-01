//#include <iostream>
//using namespace std;
//int main()
//{
//    string str = "C++ Programming is awesome";
//    char checkCharacter = 'i';
//    int count = 0;
//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] == checkCharacter)
//            {
//            ++ count;
//            }
//    }
//cout << "Number of " << checkCharacter << " = " << count << endl;
//return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//    char c[] = "C++ programming is not easy.", check = 'a';
//    int count = 0;
//    for(int i = 0; c[i] != '\0'; ++i)
//    {
//    if(check == c[i])
//    ++count;
//    }
//    cout << "Frequency of " << check << " = " << count;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main() {
//string line;
//cout << "Enter a string: ";
//getline(cin, line);
//for(int i = 0; i < line.size(); ++i)
//{
//if (!((line[i] >= 'a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z')))
//{
//line[i] = '\0';
//}
//}
//cout << "Output String: " << line << endl;
//return 0;
//}
//This program below takes a string (C-style string) input from the user and removes all characters except alphabets.

#include <iostream>
using namespace std;
int main() {
char line[100], alphabetString[100];
int j = 0;
cout << "Enter a string: ";
cin.getline(line, 100);
for(int i = 0; line[i] != '\0'; ++i)
{
if ((line[i] >= 'a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z'))
{
alphabetString[j++] = line[i];
}
}
alphabetString[j] = '\0';
cout << "Output String: " << alphabetString << endl;
return 0;
}
