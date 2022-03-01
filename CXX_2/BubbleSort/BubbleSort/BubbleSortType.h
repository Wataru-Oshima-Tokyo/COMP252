//
//  BubbleSortType.hpp
//  BubbleSort
//
//  Created by Wataru Oshima on 2020/04/24.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef BubbleSortType_hpp
#define BubbleSortType_hpp

#include <stdio.h>
#include <iostream>
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
#endif /* BubbleSortType_hpp */
