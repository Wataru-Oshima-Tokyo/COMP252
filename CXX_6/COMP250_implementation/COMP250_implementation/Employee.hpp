//
//  Employee.hpp
//  COMP250_implementation
//
//  Created by Wataru Oshima on 2019/11/19.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Employee_hpp  // preprocessor
#define Employee_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Employee {

private:
  
    int Employee_id;
    string Employee_name;
    int Employee_zipcode;
    float Employee_salary;
    int Obj_counter;
    
public:
    
    Employee ();
    Employee (int ID);
    Employee (int ID, string NAME);
    Employee (int ID, string NAME, float SALARY);
    
    Employee (const Employee &obj);
    
    int get_Employee_id();
    void set_Employee_id(int ID);
    
    string get_Employee_name();
    void set_Employee_name(string NAME);
    
    float get_Employee_salary();
    void set_Employee_salary(float SALARY);
    
    int Objcount();
    ~Employee();
};

#endif /* Employee_hpp */
