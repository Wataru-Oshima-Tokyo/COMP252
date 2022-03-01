//
//  main.cpp
//  SelectionSort
//
//  Created by Wataru Oshima on 2020/04/22.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "SelectionSortHeader.h"
using namespace std;

//template <class listType>
//class SelectionSortType {
//
//    int minlocation(listType list[], int first, int length);
//    void swap(listType list[], int first, int last);
//    void sorting(listType list[], int length);
//    void println(listType list[]);
//};
//
//template <class listType>
//int minlocation(listType list[], int first, int length)
//{
//    int minIndex;
//    minIndex = first;
//    
//    for (int loc = first+1; loc < length; loc++) {
//        if (list[loc] < list[minIndex])
//            minIndex = loc;
//    }
//    return minIndex;
//}
//
//template <class listType>
//void swap(listType list[], int first, int second)
//{
//    int temp;
//    temp = list[first];
//    list[first] = list[second];
//    list[second] = temp;
//}
//
//template <class listType>
//void sorting(listType list[], int length)
//{
//    int minIndex;
//    
//    for (int loc = 0; loc < length; loc++) {
//        minIndex = minlocation<listType>(list, loc, length);
//        swap<listType>(list, loc, minIndex);
//    }
//}
//
//template <class listType>
//void println(listType list[], int length)
//{
//    for (int i=0; i<length; i++) {
//        if (i == length -1)
//            cout << list[i] << endl;
//        else
//            cout << list[i] << ", ";
//    }
//}


int main(int argc, const char * argv[]) {
    int example[10] = {45, 5, 8, 87, 12, 4, 54, 32, 12, 10};
    SelectionSortHeader<int> selectionSort;
    cout << "Unsorted list is :";
    selectionSort.println(example, 10);
    selectionSort.sorting(example, 10);
    cout << "Sorted list is :";
    selectionSort.println(example, 10);
    return 0;
}
