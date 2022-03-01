//
//  main.cpp
//  BinarySearch
//
//  Created by Wataru Oshima on 2020/04/16.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

void println(int list[], int length);
int binarySearch(int list[], int length, int value, int first, int last);
int decensding (int list[], int length, int value, int first, int last);
int recursiveFunction(int list[], int length, int value);

int decensding (int list[], int length, int value, int first, int last) {
    int temp = 0;
    int x = 0;
    for (int m = 0; m < length; m++) {
        for (int j = m+1; j <length; j++) {
            if (list[m] > list[j]) {
                temp = list[j];
                list[j] = list[m];
                list[m] = temp;
            }
        }
    }
    cout << "The sorted list" << endl;
    for (int i = 0; i< length; i++) {
        if (i == length-1)
           cout << list[i] << endl;
        else
            cout << list[i] << ", " ;
    }
//    cout << "The last is " << list[last -1] << endl;
    if (length < 15) {
      x = binarySearch(list, length, value, 0, last);
    } else {
        x = recursiveFunction(list, length, value);
    }
    
    
    return x;
}


int binarySearch(int list[], int length, int value, int first, int last) {
    int middle = (first+last)/2;
    bool found = false;
    while ( first <= last && (!found))
    {
        cout << list[middle] << endl;
        if (list[middle] == value) {
            found = true;
            return middle + 1;
        } else if (list[middle] < value) {
            first = middle + 1;
        } else {
            last = middle -1;
        }
        middle = (first + last)/2;
    }
    return -1;
}

int recursiveFunction(int list[], int length, int value) {
    if (length == 0) {
        return -1;
    } else if (value == list[length -1]) {
        return length -1;
    } else {
        return recursiveFunction(list, length -1, value);
    }
}

void println(int list[], int length)
{
    cout << "The list" << endl;
    for (int i = 0; i<length; i++) {
        if (i == length-1)
           cout << list[i] << endl;
        else
            cout << list[i] << ", " ;
        
    }
}
int main(int argc, const char * argv[]) {
    int result = 0;
    string errorCode = "Your input is invalid";
    int input = 0;
    srand(time(0));
    int list[1000];
    for (int i = 0; i < 1000; i++) {
        list[i]=rand()%1000+1;
    }
    
    try {
        cout << "Please put a number: ";
        cin >> input;
        if (!cin)
            throw errorCode;
        println(list, 1000);
    } catch (string s) {
        cout << s << endl;
        return 0;
    }
    
    result = decensding(list, 1000, input, 0, 1000);
    if (result == -1)
        cout << "There is no number equivalent to the number you put." << endl;
    else
        cout << "The number you put is " << result <<"th in the list. " << endl;

    return 0;
}
