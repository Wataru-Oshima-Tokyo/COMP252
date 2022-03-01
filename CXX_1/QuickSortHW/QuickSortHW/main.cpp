//
//  main.cpp
//  QuickSortHW
//
//  Created by Wataru Oshima on 2020/04/29.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

template <class insertType>
void insertionSort(insertType list[], int length)
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


template <class mergeType>
class MergeSortType {
public:
    void mergeSort(int list[], int length);
    void mergeSortD(int list[], int length);
    void mergeSort(int list[], int temp[], int leftStart, int rightEnd, int length);
    void mergeHalves(int list[], int temp[], int leftStart, int rightEnd, int length);
    void mergeSortD(int list[], int temp[], int leftStart, int rightEnd, int length);

};

template <class mergeType>
void MergeSortType<mergeType>::mergeSort(int list[], int length)
{
    int temp[length];
    mergeSort(list, temp, 0, length-1, length);
}
template <class mergeType>
void MergeSortType<mergeType>::mergeSortD(int list[], int length)
{
    int temp[length];
    mergeSort(list, temp, 0, length-1, length);
}
template <class mergeType>
void MergeSortType<mergeType>::mergeSortD(int list[], int temp[], int leftStart, int rightEnd, int length)
{
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd)/2;
    if (middle <=20) {
        insertionSort(list, 20);
    } else {
        mergeSortD(list, temp, leftStart, middle, length);
        mergeSortD(list, temp, middle+1, rightEnd, length);
        mergeHalves(list, temp, leftStart, rightEnd, length);
    }
    

}
template <class mergeType>
void MergeSortType<mergeType>::mergeSort(int list[], int temp[], int leftStart, int rightEnd, int length)
{
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd)/2;
        mergeSort(list, temp, leftStart, middle, length);
        mergeSort(list, temp, middle+1, rightEnd, length);
        mergeHalves(list, temp, leftStart, rightEnd, length);
    

}

template <class mergeType>
void MergeSortType<mergeType>::mergeHalves(int list[], int temp[], int leftStart, int rightEnd, int length)
{
    int leftEnd = (rightEnd + leftStart)/2;
    int rightStart = leftEnd +1;
    int size = rightEnd - leftStart +1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (list[left] <= list[right]) {
            temp[index] = list[left];
            left++;
        } else {
            temp[index] = list[right];
            right++;
        }
        index++;
    }
    int tempLeft = left;
    int tempRight = right;
    for (int i = 0; i<leftEnd - left+1; i++) {
        temp[index] = list[tempLeft];
        tempLeft++;
        index++;
    }

    for (int i = 0; i<rightEnd - right+1; i++) {
        temp[index] = list[tempRight];
        tempRight++;
        index++;
    }
    for (int i = 0; i<size; i++) {
        list[leftStart] = temp[leftStart];
        leftStart++;
    }
}
using namespace std;
template <class elemType>
class QuickSortHeader {
public:
    int partition(elemType list[], int first, int last);
    void swap(elemType list[], int first, int second);
    void recQuickSort(elemType list[], int first, int last);
    void recQuickSortC(elemType list[], int first, int last);
    void quickSort(elemType list[], int length);
    void quickSortC(elemType list[], int length);
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

template <class elemType>
void QuickSortHeader<elemType>::recQuickSortC(elemType list[], int first, int last)
{
    int pivotLocation;
    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        if (pivotLocation <20) {
            insertionSort(list, 20);
        } else {
        recQuickSortC(list, first, pivotLocation - 1);
        recQuickSortC(list, pivotLocation + 1, last);
        }
    }

}

//Finally, we write the quick sort function, quickSort, that calls the function
//
//recQuickSort on the original list:

template <class elemType>
void QuickSortHeader<elemType>::quickSort(elemType list[], int length)
{
    recQuickSort(list, 0, length - 1);
} //end quickSort

template <class elemType>
void QuickSortHeader<elemType>::quickSortC(elemType list[], int length)
{
    recQuickSortC(list, 0, length - 1);
} //end quickSort

template <class Type>
void println(Type list[], int length)
{
    for (int i=0; i<length; i++) {
        if (i == length -1)
            std::cout << list[i] << std::endl;
        else
            std::cout << list[i] << ", ";
    }
}
template <class Type>
void randomNumberGenerator(int list[], int length)
{
//   srand(time(NULL));
    for (int i = 0; i<length; i++) {
        list[i] = rand()%length + 1;
    }
}
int main(int argc, const char * argv[]) {
    int arrayType[10000];
    int length = 10000;
    QuickSortHeader<int> quickType;
    MergeSortType<int> mergeType;
    clock_t initiaiTime, endTime, totalTime;
    randomNumberGenerator<int>(arrayType, length);
    initiaiTime = clock();
    quickType.quickSort(arrayType, length);
    endTime = clock();
    totalTime = endTime - initiaiTime;
    cout << "The total time for the middle (a) is " <<totalTime << endl;
    println(arrayType, length);
    randomNumberGenerator<int>(arrayType, length);
    initiaiTime = clock();
    mergeType.mergeSort(arrayType, length);
    endTime = clock();
    totalTime = endTime - initiaiTime;
    cout << "The total time for the median (b) is " <<totalTime << endl;
    println(arrayType, length);
    randomNumberGenerator<int>(arrayType, length);
    initiaiTime = clock();
    quickType.quickSortC(arrayType, length);
    endTime = clock();
    totalTime = endTime - initiaiTime;
    cout << "The total time for the middle (C) is " <<totalTime << endl;
    println(arrayType, length);
    randomNumberGenerator<int>(arrayType, length);
    initiaiTime = clock();
    mergeType.mergeSortD(arrayType, length);
    endTime = clock();
    totalTime = endTime - initiaiTime;
    cout << "The total time for the median (d) is " <<totalTime << endl;
    println(arrayType, length);
    return 0;
}
