//
//  main.cpp
//  InsertionSort
//
//  Created by Wataru Oshima on 2020/04/22.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "InsertionSortHeader.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int list[10] = {21, 57, 2124, 135, 124, 431, 1234, 4214, 22, 1};
    InsertionSortHeader<int> insertSort;
    cout << "Unsorted list is :";
    insertSort.println(list, 10);
    insertSort.insertionSort(list, 10);
    cout << "Sorted list is   :";
    insertSort.println(list, 10);
}
