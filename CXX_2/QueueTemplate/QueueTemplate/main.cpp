//
//  main.cpp
//  QueueTemplate
//
//  Created by Wataru Oshima on 2020/04/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "LinkedQueue.h"
#include "QueueType.h"
using namespace std;

int main()

{
    QueueType<int> queue;
    LinkedQueueType<int> abc;

int x, y;

queue.initializeQueue();

x = 20;

y = 35;

queue.addQueue(x);

queue.addQueue(y);

x = queue.front();

queue.deleteQueue();

queue.addQueue(x + 7);

queue.addQueue(78);

queue.addQueue(x);

queue.addQueue(y - 6);

cout << "Queue Elements: ";

while (!queue.isEmptyQueue())

{

cout << queue.front() << " ";

queue.deleteQueue();

}

cout << endl;

return 0;

}
