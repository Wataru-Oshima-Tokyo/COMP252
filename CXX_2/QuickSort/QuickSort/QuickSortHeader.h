//
//  QuickSortHeader.hpp
//  QuickSort
//
//  Created by Wataru Oshima on 2020/04/27.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef QuickSortHeader_h
#define QuickSortHeader_h

#include <stdio.h>
#include <iostream>
#include <array>
template <class elemType>
class QuickSortHeader {
public:
    int partition(elemType list[], int first, int last);
    void swap(elemType list[], int first, int second);
    void recQuickSort(elemType list[], int first, int last);
    void quickSort(elemType list[], int length);
    void println(elemType list[], int length);
    
};

template <class elemType>
int QuickSortHeader<elemType>::partition(elemType list[], int first, int last)
{
    elemType pivot;
    int smallIndex;

    swap(list, first, (first + last) / 2);
    pivot = list[first];
    smallIndex = first;
    for (int index = first + 1; index <= last; index++)
        if (list[index] < pivot)
            {
                smallIndex++;
                swap(list, smallIndex, index);
            }
    swap(list, first, smallIndex);
    return smallIndex;
}

template <class elemType>
void QuickSortHeader<elemType>::swap(elemType list[], int first, int second)
{
    elemType temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap


template <class elemType>
void QuickSortHeader<elemType>::recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;
    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }

} //end recQuickSort

//Finally, we write the quick sort function, quickSort, that calls the function
//
//recQuickSort on the original list:

template <class elemType>
void QuickSortHeader<elemType>::quickSort(elemType list[], int length)
{
    recQuickSort(list, 0, length - 1);
} //end quickSort

template <class elemType>
void QuickSortHeader<elemType>::println(elemType list[], int length)
{
    for (int i=0; i<length; i++) {
        if (i == length -1)
            std::cout << list[i] << std::endl;
        else
            std::cout << list[i] << ", ";
    }
}
#endif /* QuickSortHeader_hpp */
