//
//  main.cpp
//  modCalculator
//
//  Created by Wataru Oshima on 2020/05/20.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <cmath>
int main(int argc, const char * argv[]) {
    long x, result;
    x = pow(7.0, 21.0);
    result = x%17;
    std::cout << result << std::endl;
    return 0;
}
