//
//  Employee.cpp
//  COMP250_implementation
//
//  Created by Wataru Oshima on 2019/11/19.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Employee.hpp"
using namespace std;

Employee::Employee (){
    Employee(0, "NAME", 0);
};
Employee::Employee (int ID){
    Employee(ID, "NAME", 0);
};
Employee::Employee (int ID, string NAME){
    Employee(ID, NAME, 0);
};
Employee::Employee (int ID, string NAME, float SALARY){
    Employee_id = ID;
    Employee_name = NAME;
    Employee_salary = SALARY;
    Obj_counter++;
};

Employee::Employee (const Employee &obj) {
    //the original value cannot be manipulated due to the "const"
    Employee_id = obj.Employee_id + 10;
    Employee_name = "Hehehehe";
    Employee_salary = obj.Employee_salary * 2;
    
};

int Employee::get_Employee_id(){
    return Employee_id;
};
void Employee::set_Employee_id(int ID){
    Employee_id = ID;
};

string Employee::get_Employee_name(){
    return Employee_name;
};
void Employee::set_Employee_name(string NAME){
    Employee_name = NAME;
};

float Employee::get_Employee_salary(){
    return Employee_salary;
};
void Employee::set_Employee_salary(float SALARY){
    Employee_salary = SALARY;
};

Employee::~Employee() {
    Obj_counter--;
};

int Employee::Objcount(){
    return Obj_counter;
};


