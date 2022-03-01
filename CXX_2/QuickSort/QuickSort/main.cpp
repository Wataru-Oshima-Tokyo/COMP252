//
//  main.cpp
//  QuickSort
//
//  Created by Wataru Oshima on 2020/04/27.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "QuickSortHeader.h"

int main(int argc, const char * argv[]) {
    int listType[5] = {4,6,7,3,2};
    QuickSortHeader<int> Type;
    Type.quickSort(listType, 5);
    Type.println(listType, 5);
    return 0;
}
