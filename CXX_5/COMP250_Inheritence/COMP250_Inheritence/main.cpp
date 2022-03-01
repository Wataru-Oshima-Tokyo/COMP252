//
//  main.cpp
//  COMP250_Inheritence
//
//  Created by Wataru Oshima on 2019/11/26.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
//base class
class Shape{
public:
    void setWidth(int W){
        width = W;
    }
    void setheight(int h){
        height = h;
    }
protected:
    int width;
    int height;
};
//Base C;ass Paint class
class PaintCost {
    public:
    int getCost(int area) {
        return area * 70;
    }
};


//Derived class
class Rectangle: public Shape, public PaintCost{
public:
    int getArea(){
        return (height*width);
    }
};



int main(int argc, const char * argv[]) {
    int area;
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setheight(7);
    area = Rect.getArea();
    //print the area of the object
    cout << "Total area is : " << Rect.getArea() << endl;
    cout << "Total cost is : " << Rect.getCost(area) << endl;
    return 0;
}
