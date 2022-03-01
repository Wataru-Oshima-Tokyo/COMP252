//
//  main.cpp
//  COMP250_classHW
//
//  Created by Wataru Oshima on 2019/11/11.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class productType //Line 1

{ //Line 2

public: //Line 3

    productType(); //Line 4

    productType(int, double, double); //Line 5

    productType(string a, int x , double y, double z) {
        a = "";
        x = quantitiesInStock;
        y = price;
        z = discount;
    }; //Line 6

    productType(string a, string b, string c, int x, double y, double z){
        a = "";
        b = "";
        c = "";
        x = 0;
        y = 0.0;
        z = 0.0;
    }; //Line 7
    
    productType(string a, int x , double y, double z) {
        a = id;
        x = quantitiesInStock;
        y = price;
        z = discount;
    }; //Line 6

    void set(string, string, string, int,

    double, double); //Line 8

    void print() const; //Line 9

    void setQuantitiesInStock(int x); //Line 10

    void updateQuantitiesInStock(int x); //Line 11

    int getQuantitiesInStock() const; //Line 12

    void setPrice(double x); //Line 13

    double getPrice() const; //Line 14

    void setDiscount(double d); //Line 15

    double getDiscount() const; //Line 16

private: //Line 17

    string productName; //Line 18

    string id; //Line 19

    string manufacturer; //Line 20

    int quantitiesInStock; //Line 21

    double price; //Line 22

    double discount; //Line 23

    
//    A.
       productType product1;  //line4;
       productType product2("Microwave", "M3562", "GeneralPool", 35, 175.00, 0.1); //Line 7;
       productType product3("D1290", 25, 375.00, 0.05); //Line 6;
       productType product4(10, 8.50, 0.2); //Line 5;

//    B. Line4
        productType() {
            productName = "";
            id = "";
            manufacturer = "";
            quantitiesInStock = 0;
            price = 0.0;
            discount = 0.0;
        };

//    C. Line5
        productType(int x , double y , double z) {
            productName = "";
            id = "";
            manufacturer = "";
            quantitiesInStock = x;
            price = y;
            discount = z;
        };

//    D. Line6
        productType(string a, int x, double y, double z) {
            productName = "";
            manufacturer = "";
            id = x;
            quantitiesInStock = y;
            price = c;
            discount = z;
        };

//    E. line7
        productType(string a, string b, string c, int x, double y, double z) {
            productName = a;
            id = b;
            manufacturer = c;
            quantitiesInStock = x;
            price = y;
            discount = z;
        };
}; //Line 24


int main(int argc, const char * argv[]) {
    productType product1;  //line4;
    productType product2("Microwave", "M3562", "GeneralPool", 35, 175.00, 0.1); //Line 7;
    productType product3("D1290", 25, 375.00, 0.05); //Line 6;
    productType product4(10, 8.50, 0.2); //Line 5;
    productType("", "", "", 0, 0.0, 0.0);
    return 0;
}
