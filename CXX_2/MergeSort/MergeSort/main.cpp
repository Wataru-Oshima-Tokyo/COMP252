//
//  main.cpp
//  MergeSort
//
//  Created by Wataru Oshima on 2020/04/28.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <array>

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
    void mergeSort(int list[], int temp[], int leftStart, int rightEnd, int length);
    void mergeHalves(int list[], int temp[], int leftStart, int rightEnd, int length);


};

template <class mergeType>
void MergeSortType<mergeType>::mergeSort(int list[], int length)
{
    int temp[length];
    mergeSort(list, temp, 0, length-1, length);
}
template <class mergeType>
void MergeSortType<mergeType>::mergeSort(int list[], int temp[], int leftStart, int rightEnd, int length)
{
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd)/2;
//    if (middle <=2) {
//        insertionSort(list, 2);
//    } else {
        mergeSort(list, temp, leftStart, middle, length);
        mergeSort(list, temp, middle+1, rightEnd, length);
        mergeHalves(list, temp, leftStart, rightEnd, length);
//    }
    

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
   srand(time(NULL));
    for (int i = 0; i<length; i++) {
        list[i] = rand()%length + 1;
    }
}
int main(int argc, const char * argv[]) {
    int arrayType[20];
    int length = 20;
    randomNumberGenerator<int>(arrayType, length);
    println(arrayType, length);
    MergeSortType<int> mergeSort;
    mergeSort.mergeSort(arrayType, length);
    println(arrayType, length);
    return 0;
}


//template <class Type>
//class unorderedLinkedList {
//    void divideList(nodeType<Type>* first1,nodeType<Type>* &first2);
//    Type mergeList(nodeType<Type>* first1, nodeType<Type>* first2);
//
//};
//
// template <class Type>
// void unorderedLinkedList<Type>::divideList(nodeType<Type>* first1,nodeType<Type>* &first2)
// {
//     nodeType<Type>* middle;
//     nodeType<Type>* current;
//
//     if (first1 == nullptr) //list is empty
//         first2 = nullptr;
//     else if (first1->link == nullptr) //list has only one node
//         first2 = nullptr;
//     else
//     {
//         middle = first1;
//         current = first1->link;
//         if (current != nullptr) //list has more than two nodes
//             current = current->link;
//         while (current != nullptr)
//         {
//             middle = middle->link;
//             current = current->link;
//                if (current != nullptr)
//                    current = current->link;
//         } //end while
//    first2 = middle->link; //first2 points to the first
//         //node of the second sublist
//    middle->link = nullptr; //set the link of the last node of the first sublist to nullptr
//     } //end else
// } //end divideList
//
// template <class Type>
// nodeType<Type>* unorderedLinkedList<Type>::mergeList(nodeType<Type>* first1, nodeType<Type>* first2)
// {
//     nodeType<Type> *lastSmall; //pointer to the last node of the merged list
//     nodeType<Type> *newHead; //pointer to the merged list
//     if (first1 == nullptr) //the first sublist is empty
//         return first2;
//     else if (first2 == nullptr) //the second sublist is empty
//         return first1;
//     else
//     {
//         if (first1->info < first2->info) //compare the first nodes
//         {
//             newHead = first1;
//             first1 = first1->link;
//             lastSmall = newHead;
//         }
//         else
//         {
//             newHead = first2;
//             first2 = first2->link;
//             lastSmall = newHead;
//         }
//         while (first1 != nullptr && first2 != nullptr)
//             {
//                 if (first1->info < first2->info)
//                     {
//                         lastSmall->link = first1;
//                         lastSmall = lastSmall->link;
//                         first1 = first1->link;
//                     }
//                 else
//                     {
//                         lastSmall->link = first2;
//                         lastSmall = lastSmall->link;
//                         first2 = first2->link;
//                     }
//            } //end while
//
//         if (first1 == nullptr) //first sublist exhausted first
//         lastSmall->link = first2;
//         else //second sublist exhausted first
//         lastSmall->link = first1;
//         return newHead;
//     }
// }//end mergeList
//
// template <class Type>
// void unorderedLinkedList<Type>::recMergeSort(nodeType<Type>* &head)
// {
//     nodeType<Type> *otherHead;
//     if (head != nullptr) //if the list is not empty
//         if (head->link != nullptr) //if the list has more than one node
//
//     {
//         divideList(head, otherHead);
//         recMergeSort(head);
//         recMergeSort(otherHead);
//         head = mergeList(head, otherHead);
//     }
// } //end recMergeSort
//
// template <class Type>
// void unorderedLinkedList<Type>::mergeSort()
// {
//     recMergeSort(first);
//     if (first == nullptr)
//         last = nullptr;
//     else
//     {
//         last = first;
//         while (last->link != nullptr)
//             last = last->link;
//     }
// } //end mergeSort
 
