//
//  main.cpp
//  randomNumberGenerator
//
//  Created by Wataru Oshima on 2020/05/17.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;


void fakeValueGenerator(int length, float distance, float ramda);
void randomNumberGenerator(int length, int numberOfQ, int angle);

void fakeValueGenerator(int length, float distance, float ramda)
{
    float y, tans, s, sins, d, percentD;
    y = (length * ramda)/distance;
    tans = y/length;
    s = atan(tans);
    sins = sin(s);
    d = ramda/sins;
    percentD = d - distance;
    if (percentD < 0)
        percentD = -1 * percentD;
    percentD = (percentD/(d + distance))*50;
    cout << "   For L[cm]=" << length << ", y[cm]=" << y << ", tanθ=" << tans << ", θ[rad]=" << s << ", sinθ=" << sins << ", d[um]=" << d*1e6 << ", d[um] with approx=" << distance*1e6 << ", %diff=" << percentD <<"%" <<endl;
    
}
void randomNumberGenerator(int length, int numberOfQ, int angle)
{
    float radian = angle * 3.14/180;
    float d380 = (380e-9)/(sin(radian));
    float d760 = (760e-9)/(sin(radian));
    float L = 20;
//    cout << d380 << endl;
    srand(time(NULL));
    cout << "For ramda = 380 * 10^-9" << endl;
    for (int i = 0; i<length; i++) {
        float a = 0;
        a = rand()%numberOfQ + 1;
        d380 = d380 + (a/10000)*1e-6;
        fakeValueGenerator(L, d380, 380e-9);
        L = L + 10;
    }
        L = 20;
    cout << "For ramda = 760 * 10^-9" << endl;
    for (int i = 0; i<length; i++) {
        float a = 0;
        a = rand()%numberOfQ + 1;
        d760 = d760 + (a/9999)*1e-6;
        fakeValueGenerator(L, d760, 760e-9);
        L = L + 10;
    }
    
}
int main(int argc, const char * argv[]) {
    float angle = 0;
    cout << "please put any angle you want to examine: ";
    cin >> angle;
    randomNumberGenerator(4, 1000, angle);
    cout << endl;
    return 0;
}
