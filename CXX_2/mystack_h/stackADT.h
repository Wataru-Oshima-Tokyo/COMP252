//
//  stackADT.hpp
//  Stack1
//
//  Created by Wataru Oshima on 2020/03/22.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//
/*
 –initializeStack
 –isEmptyStack
 –isFullStack
 –push
 –top
 –pop
 */
#ifndef stackADT_hpp
#define stackADT_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>

template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    
    virtual void push(const Type& newItem) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};
#endif /* stackADT_hpp */
