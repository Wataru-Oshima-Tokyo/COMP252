////
////  main.cpp
////  Friend
////
////  Created by Wataru Oshima on 2020/02/05.
////  Copyright © 2020 Wataru Oshima. All rights reserved.
////
//
#include <iostream>
using namespace std;
//
////class Rectangle {
////private:
////    int width, height;
////public:
////    Rectangle(){}
////    Rectangle (int x, int y) : width(x), height(y) {}
////    int area() {return width*height;}
////    friend Rectangle duplicate (const Rectangle&);
////
////};
////
////Rectangle duplicate (const Rectangle& param) {
////    Rectangle rec;
////    rec.width = param.width*2;
////    rec.height = param.height*2;
////    return rec;
////};
//
//
//
class Triangle {
private:
    int width, height;
public:
    Triangle() {}
    Triangle (int x, int y): width(x), height(y) {}
    int area() {return width*height/2;}
    friend Triangle duplicate (const Triangle&);
};

Triangle duplicate (const Triangle& a) {
    Triangle tri;
    tri.width = a.width*2;
    tri.height =a.height*2;
    return tri;
};

int main(int argc, const char * argv[]) {
//    Rectangle foo;
//    Rectangle bar (2,3);
//    foo = duplicate(bar);
//    cout << bar.area() << endl;
    Triangle foo;
    Triangle ex(2,3);
    foo = duplicate(ex);
    cout << foo.area() << endl;
    return 0;
}

//class Square;
//
//class Rectangle {
//    int width, height;
//public:
//    Rectangle(){}
//    int area() {return width*height;}
//    void convert (Square a);
//};
//
//class Square {
//    friend class Rectangle;
//private:
//    int side;
//public:
//    Square (int a): side(a){}
//};
//
//void Rectangle::convert(Square a) {
//    width = a.side;
//    height = a.side;
//}

int main(){
    Rectangle rec;
    Square sqr(4);
    rec.convert(sqr);
    cout << rec.area() << endl;
    
    return 0;
}
