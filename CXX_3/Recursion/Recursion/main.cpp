//
//  main.cpp
//  Recursion
//
//  Created by Wataru Oshima on 2020/02/25.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>


int largest(const int list[], int lowerIndex, int upperIndex)

{

int max;

if (lowerIndex == upperIndex) //size of the sublist is one

    return list[lowerIndex];

else{

    max = largest(list, lowerIndex + 1, upperIndex);

        if (list[lowerIndex] >= max)

                return list[lowerIndex];
        else

                return max;

        }

}

int smallest(const int list[], int lowerindex, int upperindex) {
    int min;
    
    if (lowerindex == upperindex) {
        return list[lowerindex];
    } else {
        
        min = smallest(list, lowerindex+1, upperindex);
        
        if (list[lowerindex] <= min)
            return list[lowerindex];
        else
            return min;
    }
}

void functionX(int x) {
    try {
        cout << x << endl;
        if (x<=0)
            throw x;
        functionX(x -1);
    }
    catch (int x) {
        cout << "now x is 0";
    }
    
}

void moveDisks(int count, int needle1, int needle3, int needle2) {
    if (count > 0) {
        moveDisks(count - 1, needle1, needle2, needle3);
        cout << "Move disk " << count << " from " << needle1 << " to " << needle3 << "." << endl;
        moveDisks(count - 1, needle2, needle3, needle1);
      
    }

}


int Fibonach(int x ) {
    int z = 0;
    for (int i = 0; i<x; i++) {
        z = z + pow(2, i);
    }
    return z;
}
void functionY();
int main(int argc, const char * argv[]) {
//    int intArray[10] = {10, 28, 65, 28, 21, 87, 12, 87, 21, 99};
////    functionX(10);
//    cout << largest(intArray, 0, 4) << endl;
//    cout << smallest(intArray, 0, 10) << endl;
//    moveDisks(10, 1, 2, 3);
    int intArry[10] = {1};
    moveDisks(2, 1, 2, 3);
    cout << Fibonach(5) << endl;
    return 0;
}
