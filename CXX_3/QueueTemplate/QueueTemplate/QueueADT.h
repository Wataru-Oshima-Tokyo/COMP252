//
//  QueueADT.hpp
//  QueueTemplate
//
//  Created by Wataru Oshima on 2020/04/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef QueueADT_hpp
#define QueueADT_hpp

#include <stdio.h>
template <class Type>
class QueueADT
{
public:
    virtual bool isEmptyQueue() const = 0;
    virtual bool isFullQueue() const = 0;
    virtual void initializeQueue() = 0;
    virtual Type front() const = 0;
    virtual Type back() const = 0;
    virtual void addQueue(const Type& queueElement = 0);
    virtual void deleteQueue() = 0;
    
    
};
#endif /* QueueADT_hpp */
