//
//  main.cpp
//  comp2520128_Inheritence
//
//  Created by Wataru Oshima on 2020/01/28.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//class Shape {
//public:
//    void setWidth(int w) {
//        width = w;
//    }
//
//    void setHeight(int h) {
//        height = h;
//    }
//protected:
//    int width;
//    int height;
//};
////Base class PaintCost
//
//class PaintCost {
//public:
//    int getCost(int area) {
//        return (area*70);
//    }
//};
////derived class
//class Rectangle: public Shape, public PaintCost {
//public:
//    int getArea(){
//        return (height * width);
//    }
//};


//Inheritence

class Shape {
protected:
    int width, height;
public:
    void setWidth(int a) {
        width = a;
    }
    
    void setHeight(int a) {
        height = a;
    }
};

class paintCost {
public:
    int getCost(int area) {
        return (area*70);
    }
};

class Triangle: public Shape, public paintCost {
public:
    int getArea () {
        return (width*height/2);
    }
};
int main(int argc, const char * argv[]) {

    int area;
    Triangle rect;
    rect.setWidth(5);
    rect.setHeight(7);
    
    area = rect.getArea();
    //printing the area of the object
    cout << "total area " << rect.getArea() << endl;
    cout << "total cost " << rect.getCost(area) << endl;
    return 0;
}
