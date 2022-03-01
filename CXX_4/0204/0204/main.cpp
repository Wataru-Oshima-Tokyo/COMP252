//
//  main.cpp
//  0204
//
//  Created by Wataru Oshima on 2020/02/04.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

//class square;
//
//class myClock {
//private:
//    int hour = 0;
//    int minute = 0;
//public:
//
//    void getHour(int h) {
//        hour = h;
//    }
////    int setHour() {
////        return hour;
////    };
//
//    void getMinute(int m) {
//        minute = m;
//    }
////    int setMinute() {
////        return minute;
////    };
//
//    void showClock() {
//        cout << hour << minute << endl;
//    }
//
////    myClock(int a, int b) {
////        a = hour;
////        b = minute;
////    };
//////    myClock(){
//////        myClock(0, 0);
//////    };
//
//};
//
//void resetClock(myClock& a) {
//    a.getHour(0);
//    a.getMinute(0);
//}
//
////myClock::print() {
////    cout << hour << minute << endl;
////}
//
//int main() {
//    myClock crockOne;
//    crockOne.getHour(5);
//    crockOne.getMinute(3);
//    crockOne.showClock();
//    resetClock(crockOne);
//    crockOne.showClock();
//
////    resetClock(crockOne);
////    crockOne.print();
//    return 0;
//}

//class Shape {
//protected:
//    int width, height;
//public:
//    Shape(int a = 0, int b = 0) {
//        width =a;
//        height = b;
//    }
//
//    virtual int area() {
//        cout << "Parent class area :" << endl;
//        return 0;
//    }
//};
//
//class Rectangle: public Shape {
//public:
//    Rectangle(int a = 0, int b = 0):Shape(a, b){ }
//
//    int area() {
//        cout << "Rectangle class area : " << (width* height) << endl;
//        return 0;
//        }
//};
//
//class Triangle: public Shape {
//public:
//    Triangle(int a = 0, int b =0):Shape(a, b){}
//
//    int area() {
//        cout << "Triangle class area :" << (width* height /2) <<endl;
//        return 0;
//    }
//};
//
//
//int main() {
//    Shape *shape;
//    Rectangle rec(10,7);
//    Triangle tri(10,5);
//
//    shape = &rec;
//    shape -> area();
//    shape = &tri;
//    shape -> area();
//
//
//    return 0;
//};

class Shape {
protected:
    int height, width;
public:
    Shape(int a = 0, int b = 0) {
        height = a;
        width = b;
    };
    
    virtual int area() {
        cout << "This is parent class : " << endl;
        return 0;
    }
};

class Rectangle: public Shape {
public:
    Rectangle(int a = 0, int b = 0):Shape(a, b) {};
    
    int area() {
        cout << "This is the rectangle class: " << (height * width) << endl;
        return 0;
    }
};

class Triangle: public Shape {
public:
    Triangle(int a = 0, int b = 0):Shape(a, b) {};
    
    int area() {
        cout << "This is the triangle class: " << (height * width/ 2) << endl;
        return 0;
    }
};

class Diagonal: public Shape {
public:
    Diagonal(int a = 0, int b =0):Shape(a, b) {};
    
    int area() {
        double squres = pow(width, 2) + pow(height, 2);
        cout << "This is the Diagonal class: " << (sqrt(squres)) << endl;
        return 0;
    }
};

int main () {
    
    Shape *shape;
    Rectangle rec(6, 5);
    Triangle tri(7,8);
    Diagonal dig(3, 7);
    shape = &rec;
    shape -> area();
    shape = &tri;
    shape -> area();
    shape = &dig;
    shape -> area();
    
    
    
    return 0;
}
