//
//  main.cpp
//  PenguinSpieces
//
//  Created by Wataru Oshima on 2020/02/18.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//prototype
class Environment;
void addingNewOne();

class Penguin {
protected:
    int fly, swim, walk, resistence;
    string name;
public:
    Penguin();
    Penguin(int f, int s, int w, int r, string n): fly(f), swim(s), walk(w), resistence(r), name(n) {};
    friend Penguin ordinary ();
    //overloading
    bool operator==(const Penguin& otherspeices) const;
    friend std::ostream & operator << (std::ostream &out, const Penguin &c);
    friend std::istream & operator >> (std::istream &in, Penguin &c);
    
    //pointer
    Penguin extremelyColdTemperature() {
        swim = swim -2;
        walk = walk -2;
        resistence = resistence -2;
        return *this;
    }
    
    

};
//
bool Penguin::operator==(const Penguin& otherspeices) const{
    return (fly == otherspeices.fly && swim == otherspeices.swim && walk==otherspeices.walk && resistence == otherspeices.resistence);
}

std::ostream & operator << (std::ostream &out, const Penguin &c) {
    out << "The ability of " << c.name << " penguin is below: " << endl;
    out << "Fly: " << c.fly << "\n" << "Swim: " << c.swim << "\n" << "Walk: " << c.walk <<"\n" << "Resistence: " << c.resistence << endl;
    return out;
};

std::istream & operator >> (std::istream &in, Penguin &c) {
    cout << "What is the name of penguin: " << endl;
    in >> c.name;
    cout << "What is the fly ability of penguin: " << endl;
    in >> c.fly;
    cout << "What is the swim ability of penguin: " << endl;
    in >> c.swim;
    cout << "What is the walk ability of penguin: " << endl;
    in >> c.walk;
    cout << "What is the resistence ability of penguin: " << endl;
    in >> c.resistence;
    return in;
};


//base class
class Environment {
protected:
    int temperature = 0, humidity = 0;
public:
    void setTemperature(double a) {
        temperature = a;
    }
    void setHumidity(double b) {
        humidity = b;
    }
};

//inheritence
class iceField: public Environment {
public:
    float getCondition(){
        float a = 0.0;
        a = (5.0/7.0 * temperature) + (13.0/10.0 * humidity);
        return a;
    }
};

void askingsomethingNew() {
    int x;
    cout << "If you want to add more penguins, pls put 1. If not, just put any number other than 1 :";
    cin >> x;
    if (x == 1)
        addingNewOne();
}

void addingNewOne() {
    Penguin unknown(0,0,0,0,"");
    cin >>unknown;
    cout << unknown;
};
void comparingTwoClassObjects(Penguin &a, Penguin &b) {
    if (a == b)
        cout << "same" << endl;
    else
        cout << "different" << endl;
}

int main(int argc, const char * argv[]) {
    float field;
    iceField arctic;
    arctic.setHumidity(10.0);
    arctic.setTemperature(-50.0);
    field = arctic.getCondition();
    
    Penguin emperor(0, 6, 7, 9, "Emperor");
    Penguin adeli(0,7,8,5, "Adeli");
    comparingTwoClassObjects(emperor, adeli);
    if (field < -20) {
        emperor.extremelyColdTemperature();
        adeli.extremelyColdTemperature();
    }
    cout << emperor;
    cout << adeli;
    askingsomethingNew ();
    return 0;
}
