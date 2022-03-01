//
//  SelectionSortHeader.hpp
//  SelectionSort
//
//  Created by Wataru Oshima on 2020/04/22.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef SelectionSortHeader_hpp
#define SelectionSortHeader_hpp

#include <stdio.h>
#include <iostream>

template <class listType>
class SelectionSortHeader {
public:
    int minlocation(listType list[], int first, int length);
    void swap(listType list[], int first, int last);
    void sorting(listType list[], int length);
    void println(listType list[], int length);
};

template <class listType>
int SelectionSortHeader<listType>::minlocation(listType list[], int first, int length)
{
    int minIndex;
    minIndex = first;
    
    for (int loc = first+1; loc < length; loc++) {
        if (list[loc] < list[minIndex])
            minIndex = loc;
    }
    return minIndex;
}

template <class listType>
void SelectionSortHeader<listType>::swap(listType list[], int first, int second)
{
    int temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class listType>
void SelectionSortHeader<listType>::sorting(listType list[], int length)
{
    int minIndex;
    
    for (int loc = 0; loc < length; loc++) {
        minIndex = SelectionSortHeader<listType>::minlocation(list, loc, length);
        SelectionSortHeader<listType>::swap(list, loc, minIndex);
    }
}

template <class listType>
void SelectionSortHeader<listType>::println(listType list[], int length)
{
    for (int i=0; i<length; i++) {
        if (i == length -1)
            std::cout << list[i] << std::endl;
        else
            std::cout << list[i] << ", ";
    }
}


#endif /* SelectionSortHeader_hpp */
