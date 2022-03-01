//
//  main.cpp
//  BubbleSort
//
//  Created by Wataru Oshima on 2020/04/24.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
//#include "BubbleSortType.h"
//using namespace std;

template <class bubbleType>
class BubbleSortTyep {
    void bubbleSort(bubbleType list[], int length);
    void println(bubbleType list[], int length);
};

template <class bubbleType>
void bubbleSort(bubbleType list[], int length)
{
    bubbleType temp;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j<length - i; j++) {
            if (list[j] > list[j+1]) {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

template <class bubbleType>
void println(bubbleType list[], int length)
{
    for (int i = 0; i<length; i++) {
        if (i == length-1) {
            std::cout << list[i] << std::endl;
        } else {
            std::cout << list[i] << ", ";
        }
    }
}


int main(int argc, const char * argv[]) {
    int list[10] = {31, 31, 553, 142, 512, 542, 23, 22, 66, 10};
    std::cout << "Unsorted list is: ";
    println(list, 10);
    bubbleSort(list, 10);
    std::cout << "Sorted list is  : ";
    println(list, 10);
    return 0;
}
