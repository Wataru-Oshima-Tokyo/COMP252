//
//  main.cpp
//  Power Recursive function
//
//  Created by Wataru Oshima on 2020/03/02.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
double Power (double x, double y) {
    double power = 0.0;
    if (y < 0 ){
        return 1/Power(x, -y);
    }
      else  if (y == 0 ) {
        return 1.0;
    } else if ( y == 1) {
        return x;
    } else if ( y > 1){
        power = x * Power(x, y-1);
        return power;
    }
    return 0.0;
}

int main(int argc, const char * argv[]) {
    cout << Power(2, -6) << endl;
    return 0;
}
