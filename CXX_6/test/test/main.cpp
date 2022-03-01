//
//  main.cpp
//  test
//
//  Created by Wataru Oshima on 2019/09/17.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
#include <iomanip>
int main(int argc, const char * argv[]) {

    
    double x = 1565.683;
    double y = 85.78;
    double z = 123.982;
    
    cout << fixed << showpoint;
    cout << setprecision(3) << x << ' ';
    
    
    cout << setprecision(4) << y << ' ' << setprecision(2) << z << endl;

    return 0;
}
