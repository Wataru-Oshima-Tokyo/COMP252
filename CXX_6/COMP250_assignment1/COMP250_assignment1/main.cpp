//
//  main.cpp
//  COMP250_assignment1
//
//  Created by Wataru Oshima on 2019/09/01.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

//How many miles I drove the car?
//
//25 miles in city
//55 miles in highway
//What is my car tank capacity
//
//
//When did I put gas in the car
//
//At the beginning of this experiment
//Filled it up
//(full)
//
//
//At the end of the experiment, I refueled
//
//I put x gallons of the gas in the car
//
//
//
//
//
//
//Calculate and show the gas mileage
//
//
//
//
//
//Gas mileage =  Distance / gas consumed

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int gas_mileage;
    int distance;
    int gas_consumed;

    
    distance = 25 + 55;
    cout <<"entetr the amount of gas you put after you drove: ";
    cin >> gas_consumed;
    gas_mileage = distance / gas_consumed;
    cout << "This is the gas mileage: ";
    
    
    cout << gas_mileage << endl;
    
    return 0;
}
