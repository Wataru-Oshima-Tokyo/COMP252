//
//  main.cpp
//  COMP250_projectAirine
//
//  Created by Wataru Oshima on 2019/11/12.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


void InputData(string a, string b, int timedepart, int typeclass){

}; //customer //adminstrator //In_ViewTicket

void BookTicket();

class customerData{
public:
    int id;
    string source;
    string destination;
    int departuredate;
    int timedepart;
    int timearrive;
    int cost;
    int typeclass;
    string fullname;
    int age;
    int cardnumber;
    int cvv;
    int expiredate;

    void Cancelticket(int id);

    customerdata();
};


class TicketType{
private:
    int id[4];
    string source;
    string destination;
    int departuredate;
    int timedepart[4];
    int timearrive[4];
    int cost[4];
    int typeclass[2];
public:

    int TotalCost();
    void AddTicket(); //adminstrator
    void ViewTicket();//customer //adminstrator
    void DeleteTicket(); //adminstrator
    void customerDate(int i){
       customerData customer[5];
        customer[i].source = source;
        customer[i].destination = destination;
        customer[i].departuredate = departuredate;
        
    }; //customer
};


int main(){
    TicketType tickets[8];






}
