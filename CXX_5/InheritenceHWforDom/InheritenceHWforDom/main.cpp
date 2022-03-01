//
//  main.cpp
//  InheritenceHWforDom
//
//  Created by Wataru Oshima on 2020/04/08.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
class base
{
public:
    void print() const;
    //Outputs the values of num and x.
    double compute(int n);
    // returns n + manipulate(n, n);
    void setNum(int a);
    int getNum() const;
    void setX(double d);
    double getX() const;
    base(int n = 0, double d = 0);
protected:
    double manipulate(int a, int b) {
        return (num * a + x * b);
    };
// returns num * a + x * b;
private:
    int num;
    double x;
};

void base::print() const {
    cout << "num: " << num << endl;
    cout << "x: " << x << endl;
}
double base::compute(int n) {
    return (n+manipulate(n, n));
}

void base::setNum(int a) {
    num = a;
}
int base::getNum() const {
    return num;
}
void base::setX(double d) {
    x = d;
}

double base::getX() const {
    return x;
}

base::base(int n, double d)
{
    setNum(n);
    setX(d);
}

class derived: public base
{
public:
    void print() const;
    //outputs the values of instance variables.
    void setZ(double t);
    double getZ() const;
    double compute(int a, double b);
    // returns compute(a) + z * manipulate(0, b);
    derived(int n = 0, double a = 0, double b = 0);
    //Sets num = n, x = a, z = b.
private:
    double z;
};

void derived::print() const
{
    cout << "z: " << z << endl;
}

void derived::setZ(double t) {
    z = t;
}

double derived::getZ() const {
    return z;
}

double derived::compute(int a, double b)
{
    return (base::compute(a) + z *manipulate(0, b));
}
derived::derived(int n, double a, double b)
{
    setNum(n);
    setX(a);
    setZ(b);
}

//Write the definition of the function print, compute, and
//manipulate of the class base.
//Write the definition of the function print and compute of the
//class derived.
//What is the output of the following C++ code?

int main(int argc, const char * argv[]) {
    base baseObj(2, 5.5);
//    cout << fixed << showpoint << setprecision(2);
    baseObj.print();
    cout << endl;
    cout << baseObj.compute(7) << endl;
    derived derivedObj(3, 1.5, 2.0);
    derivedObj.print();
    cout << endl;
    cout << derivedObj.compute(1, 4) << endl;
    return 0;
}
