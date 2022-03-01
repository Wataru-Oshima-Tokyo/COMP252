//
//  Queue.hpp
//  QueueTemplate
//
//  Created by Wataru Oshima on 2020/04/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include "QueueADT.h"
using namespace std;
template <class Type>
class QueueType: public QueueADT<Type>
{
public:
    const QueueType<Type>& operator=(const QueueType<Type>&);
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue() const;
    Type front() const;
    Type back() const;
    void addQueue(const Type& queueElement = 0);
    void deleteQueue();
    QueueType (int queueSize = 100);
    QueueType (const QueueType<Type>& otherQueue);
    ~QueueType();
    
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;
};


template <class Type>
bool QueueType<Type>::isEmptyQueue() const
{
    return (count == 0);
}
template <class Type>
bool QueueType<Type>::isFullQueue() const
{
    return (count = maxQueueSize);
}

template <class Type>
void QueueType<Type>::initializeQueue() const
{
    count = 0;
    queueFront = 0;
    queueRear = maxQueueSize - 1;
}
template <class Type>
Type QueueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront];
}

template <class Type>
Type QueueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
}

template <class Type>
void QueueType<Type>::addQueue(const Type& queueElement)
{
    Type newElement;
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;
        count++;
        list[queueRear] = newElement;
    }
    else {
        cout << "The size of your queue is full. You cannot add a new element unless you remove one element from the queue" <<endl;
    }
}

template <class Type>
void QueueType<Type>::deleteQueue()
{
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront +1) %maxQueueSize;
    }else {
        cout << "Your queue is empty. You cannot delete an element unless you put a number on the queue" << endl;
    }
}

template <class Type>
QueueType<Type>::QueueType(int queueSize)
{
    if (queueSize <= 0) {
        cout << "Your input is invalid, it should be more than 0. Please put a number again.: " << endl;
        cin >>maxQueueSize;
    }
    else maxQueueSize = queueSize;
    
    queueFront = 0;
    queueRear = maxQueueSize -1;
    count =0;
    list = new Type(maxQueueSize);
}


template <class Type>
QueueType<Type>::~QueueType() {
    delete [] list;
};

#endif /* Queue_hpp */
