//
//  InsertionSortHeader.hpp
//  InsertionSort
//
//  Created by Wataru Oshima on 2020/04/22.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef InsertionSortHeader_h
#define InsertionSortHeader_h

#include <stdio.h>
#include <iostream>
template <class insertType>
class InsertionSortHeader {
public:
    void insertionSort(insertType list[], int length);
    void println(insertType list[], int length);
};

template <class insertType>
void InsertionSortHeader<insertType>::insertionSort(insertType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder<length; firstOutOfOrder++) {
        
        if (list[firstOutOfOrder] < list[firstOutOfOrder-1]) {
            insertType temp = list[firstOutOfOrder];
            int loc = firstOutOfOrder;
            do {
                list[loc] = list[loc-1];
                loc = loc - 1;
            } while (loc > 0 && list[loc-1] > temp);
            
            list[loc] = temp;
        }
    }
}

template <class insertType>
void InsertionSortHeader<insertType>::println(insertType list[], int length)
{
    for (int i=0; i<length; i++) {
        if (i == length -1)
            std::cout << list[i] << std::endl;
        else
            std::cout << list[i] << ", ";
    }
}
#endif /* InsertionSortHeader_hpp */
