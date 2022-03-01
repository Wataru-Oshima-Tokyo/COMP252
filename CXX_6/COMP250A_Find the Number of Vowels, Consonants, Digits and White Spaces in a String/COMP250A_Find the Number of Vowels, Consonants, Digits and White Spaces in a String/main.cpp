//
//  main.cpp
//  COMP250A_Find the Number of Vowels, Consonants, Digits and White Spaces in a String
//
//  Created by Wataru Oshima on 2019/10/14.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int whitespace(char a[], int b) {
    int i, count = 0;
    for (i = 0; i != b; i++) {
        tolower(a[i]);
        if (a[i] == ' '){
            count = count + 1;
        }
    }
    return count;
}

char Vowles(char a[], int b) {
    int i, count = 0;
    char z;
        for (i = 0; i != b; i++) {
            z = tolower(a[i]);
            if (z == 'a' || z == 'i' || z == 'u' || z == 'u' || z == 'e' || z == 'o'){
                count = count + 1;
            }
        }
    return count;
}

char Consonants(char a[], int b) {
    int i , count = 0;
    char z;
    for (i = 0; i != b; i++) {
        z = tolower(a[i]);
         if (z == 'q' || z == 'w' || z == 'r' || z == 't' || z == 'y' || z == 'p' || z == 's' || z == 'd' || z == 'f' || z == 'g' || z == 'h' || z == 'j' || z == 'k' || z == 'l' || z == 'z' || z == 'x' || z == 'c' || z == 'v' || z == 'b' || z == 'n' || z == 'm'){
                count = count + 1;
        }
    }
    return count;
}


int main(int argc, const char * argv[]) {

    char str[100];
    int white, vowels, consonants;
    cout << "Enter a line:";
    cin.get(str, 100);
    size_t a = strlen(str);
    white = whitespace(str, a);
    vowels = Vowles(str, a);
    consonants = Consonants(str, a);
    cout << "Vowles: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << a << endl;
    cout << "White spaces: " << white << endl;
    return 0;
}
