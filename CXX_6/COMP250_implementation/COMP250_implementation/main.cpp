//
//  main.cpp
//  COMP250_implementation
//
//  Created by Wataru Oshima on 2019/11/19.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include "Employee.hpp"
using namespace std;

//Employee::Employee (int ID, string NAME, float SALARY){
//    Employee(ID, NAME, SALARY)
//};


int main(int argc, const char * argv[]) {
    Employee Wataru(100, "Wataru", 100);
    Employee copy(Wataru);
//    copy = Wataru;
    cout << copy.get_Employee_salary() << "::::::This is the salary of the copy" << endl;
    cout << copy.get_Employee_name() << "::::::This is the name of the copy" << endl;
    cout << copy.get_Employee_id() << "::::::This is the id of the copy" << endl;
//    cout << Wataru.get_Employee_id() <<endl;
    return 0;
}
