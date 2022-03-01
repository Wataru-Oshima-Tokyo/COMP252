//
//  main.cpp
//  overloadingAndTemplate
//
//  Created by Wataru Oshima on 2020/02/11.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

//class clockType {
//public:
//    void setTime(int hours, int minutes, int seconds);
//    void printTime() const;
//
//    clockType reduceMinutesandSecondByTwo() {
//
//        min = min -2;
//        sec = sec -2;
//        return *this;
//    }
//    bool operator==(const clockType& otherClock) const;
//    //overload the operator ==
//
//    friend std::ostream & operator << (std::ostream &out, const clockType &c);
//    friend std::istream & operator >> (std::istream &in, clockType &c);
//
//    clockType(int a, int b, int c) {
//        hr = a;
//        min = b;
//        sec = c;
//    };
//private:
//    int hr;
//    int min;
//    int sec;
//
//};
//
//bool clockType::operator==(const clockType& otherClock) const {
//    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
//}
//std::ostream & operator << (std::ostream &out, const clockType &c) {
//    out << "The current Time on your clock is: " << c.hr << " hours and " << c.min << " minutes and " << c.sec << " seconds" << std::endl;
//    return out;
//}
//
//std::istream & operator >> (std::istream &in, clockType &c) {
//    std::cout << "Please enter the clock hour: ";
//    in >> c.hr;
//    std::cout << "Please entere the clock minutes: ";
//    in >> c.min;
//    std::cout << "Please entere the clock seconds: ";
//    in >> c.sec;
//    return in;
//};


class clockType {
public:
    void setTime(int hr, int min, int sec);
    void printTime() const;

    clockType reduceMinutesandSecondsByTwo() {
        min = min -2;
        sec = sec -2;
        return *this;
    }
    bool operator==(const clockType& otherClock) const;
   
    friend std::ostream & operator << (std::ostream &out, const clockType &c);
    friend std::istream & operator >> (std::istream &in, clockType &c);
    clockType (int a, int b, int c) {
        hr = a;
        min = b;
        sec = c;
    };
private:
    int hr, min, sec;
};


bool clockType::operator==(const clockType& otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
};

std::ostream & operator << (std::ostream &out, const clockType &c) {
    out << "The current Time on your clock is: " << c.hr << " hours and " << c.min << " minutes and " << c.sec << " seconds" << std::endl;
    return out;
};

std::istream & operator >> (std::istream &in, clockType &c) {
    std::cout << "Please enter the clock hour: ";
    in >> c.hr;
    std::cout << "Please entere the clock minutes: ";
    in >> c.min;
    std::cout << "Please entere the clock seconds: ";
    in >> c.sec;
    return in;
};



int main(int argc, const char * argv[]) {
    clockType myClock(6, 8, 50);
    clockType yourClock(6, 8, 50);
    clockType someonesClock(5, 7, 40);
    std::cout << yourClock;
    yourClock.reduceMinutesandSecondsByTwo();
    
//    std::cin >> someonesClock;
    std::cout << yourClock;

    if (myClock == someonesClock) {
        cout << "Same" << endl;
    } else {
        cout << "Different" << endl;
    }
    return 0;
}
