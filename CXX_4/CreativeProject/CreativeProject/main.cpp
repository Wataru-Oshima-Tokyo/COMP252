//
//  main.cpp
//  CreativeProject
//
//  Created by Wataru Oshima on 2020/02/08.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape {
public:
    void setWidth(int w) {
        width = w;
    }
    
    void setHeight(int h) {
        height = h;
    }
protected:
    int width, height;
};
//another base class

class PaintCost {
public:
    int getCost(int area) {
        return (area*70);
    }
};
//derived class
class Rectangle: public Shape, public PaintCost {
public:
    int getArea() {
        return (height*width);
    }
    
    
};

//Polymorphism
class AnotherShape {
protected:
    int width, height;
public:
    AnotherShape (int a = 0, int b = 0) {
        width = a;
        height = b;
    }
    virtual int area() {
        cout << "This is parent class" << endl;
        return 0;
    }
};
class Triangle: public AnotherShape {
public:
    Triangle(int a=0, int b=0):AnotherShape(a, b) {}
    int area() {
        cout << "This is the Triangle class " << width*height/2 <<  endl;
        return (width*height/2);
    }
};
int main(int argc, const char * argv[]) {
    int area;
    Rectangle rect;
    rect.setWidth(7);
    rect.setHeight(8);
    area = rect.getArea();
    
    cout << "The area is " << area << endl;
    cout << "The cost is " << rect.getCost(area) << endl;
    
    cout << "From here, this is the polymorphism" << endl;
    AnotherShape *shape;
    Triangle tri(5,6);
    shape = &tri;
    shape -> area();
    
    return 0;
}
