//
//  main.cpp
//  RecursiveSequentialsearchAlgorithm
//
//  Created by Wataru Oshima on 2020/04/15.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int recursiveFunction(int list[], int length, int value) {
    if (length == 0) {
        return -1;
    } else if (value == list[length -1]) {
        return length -1;
    } else {
        return recursiveFunction(list, length -1, value);
    }
}
int main(int argc, const char * argv[]) {
    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    int input, result;
    cout << "pleae put a number: ";
    cin >> input;
    result = recursiveFunction(list, 10, input);
    if (result == -1) {
        cout << "There is no number equivalnet to the number you put." << endl;
    } else {
        cout << "It is found at " << result + 1 << "th in the list" <<endl;
    }
    return 0;
}
