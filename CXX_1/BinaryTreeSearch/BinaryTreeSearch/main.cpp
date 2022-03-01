//
//  main.cpp
//  BinaryTreeSearch
//
//  Created by Wataru Oshima on 2020/05/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "BinaryTreeSearhHeader.cpp"

int main(int argc, const char * argv[]) {
    int list[30];
    int length = 30;
    int input = 0;
    BinaryTreeSearchHeader<int> Mytree;
    Mytree.randomNumberGenerator(list, length);
    cout << "The list before adding numbers: " << endl;
    Mytree.printlnInOrder();
    for (int i = 0; i<length; i++) {
        Mytree.addLeaf(list[i]);
    }
    cout << "The list after adding numbers: " << endl;
    Mytree.printlnInOrder();
    cout << endl;
//
//    for (int i = 0; i<10; i++) {
//        Mytree.printChildren(list[i]);
//        cout << endl;
//    }
    cout << "The smallest value is " <<Mytree.findSmallest() << endl;
    
    cout << "Please put the number you want to remove. " <<endl;
    while (input != -1) {
        input = 0;
        cout << "Delete node: ";
        cin >> input;
        if (input != -1) {
            Mytree.removeNode(input);
            Mytree.printlnInOrder();
            cout << endl;
        }
    }
    cout << endl;
    
    return 0;
}
