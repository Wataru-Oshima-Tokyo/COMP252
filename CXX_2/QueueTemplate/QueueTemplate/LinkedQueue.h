//
//  LinkedQueue.hpp
//  QueueTemplate
//
//  Created by Wataru Oshima on 2020/04/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include <stdio.h>
#include <iostream>
#include "QueueADT.h"
using namespace std;

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class LinkedQueueType: public QueueADT<Type>
{
public:
    const LinkedQueueType<Type>& operator=(const LinkedQueueType<Type>&);
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue() const;
    Type front() const;
    Type back() const;
    void addQueue(const Type& newElement = 0);
    void deleteQueue();
    LinkedQueueType ();
    LinkedQueueType (const LinkedQueueType<Type>&);
    ~LinkedQueueType();
    
private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;
    
    void copyLinkedQueue(const LinkedQueueType<Type>& otherLinkedQueue);
};

template <class Type>
bool LinkedQueueType<Type>::isEmptyQueue() const
{
    return (queueFront == nullptr);
}
template <class Type>
bool LinkedQueueType<Type>::isFullQueue() const
{
    return false;
}

template <class Type>
void LinkedQueueType<Type>::initializeQueue() const
{
    nodeType<Type> *temp;
    while (queueFront !=nullptr) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    queueRear = nullptr;
}
template <class Type>
Type LinkedQueueType<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
}

template <class Type>
Type LinkedQueueType<Type>::back() const
{
    assert(queueRear != nullptr);
    return queueRear->info;
}

template <class Type>
void LinkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newElement;
    newNode->link = nullptr;

    if (queueFront == nullptr) {
        queueFront = newNode;
        queueRear = newNode;
    }
    else {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}

template <class Type>
void LinkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
    if (!isEmptyQueue()) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
        if (queueFront == nullptr) {
            queueRear = nullptr;
        }
    }else {
        cout << "Your queue is empty. You cannot delete an element unless you put a number on the queue" << endl;
    }
}

template <class Type>
LinkedQueueType<Type>::LinkedQueueType()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

template <class Type>
LinkedQueueType<Type>:: ~LinkedQueueType() //destructor
{
    while (queueFront !=nullptr) {
        queueFront = queueFront->link;
    }
    queueRear = nullptr;//deallocate the memory occupied by the array
}//end destructor

template <class Type>
LinkedQueueType<Type>::LinkedQueueType(const LinkedQueueType<Type>& otherLinkedQueue)
{
//     = nullptr;
//    
//    copyStack(otherStack);
}

template <class Type>
const LinkedQueueType<Type>& LinkedQueueType<Type>::operator=(const LinkedQueueType<Type>& otherLinkedQueue)
{
    if (this != &otherLinkedQueue) //avoid self-copy
        copyStack(otherLinkedQueue);
        
        return *this;
}


#endif /* LinkedQueue_hpp */
