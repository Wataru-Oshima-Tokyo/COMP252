//
//  Function.cpp
//  Project4
//
//  Created by Wataru Oshima on 2019/12/06.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "Function.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;


void Function::TicketGenerator(AirTicket x[], int Ticket) {

    int a = 1; //FlightTime Constant
    int i;
    int codeS, codeD;

    for (int q = 1; q < z; q++) {
        codeS = q;
        for (int w = 1; w < z; w++) {
            codeD = w;

            for (int g = 0; g < Ticket; g++) {
                i = codeS * 100 + codeD * 10 + g;
                x[i].Scountry = CT[codeS];
                x[i].Dcountry = CT[codeD];
                x[i].Source = AP[codeS];
                x[i].Destination = AP[codeD];

                if(g < 6)
                x[i].AirlineNo = g + 1;

                x[i].Dtime = rand() % 23 + 1;
                x[i].flightime = rand() % 8 + 5;
                x[i].Atime = x[i].Dtime + x[i].flightime;
                if (x[i].Atime >= 24)
                    x[i].Atime -= 24;
                x[i].Amin = rand() % 49 + 10;
                x[i].Dmin = rand() % 49 + 10;

                if ((x[i].Dtime < 5) || (x[i].Dtime > 21)) {
                    a = rand() % 3 + 1;
                }
                else {
                    a = rand() % 3 + 5;
                }

                x[i].scaling = a * 0.1 + 1;
                float b = (10000 / x[i].flightime);
                //Since Cost is proportional to flightime, Scaling determine how expensive the airline is
                b = b * x[i].scaling;
                x[i].cost = (int)b;

            }
        }
    }
};

void Function::Login() {
    int x;
    cout << "Accessing as:\n";
    cout << "\n1. Adminstrator\t  2. Customer\t  3. Exit\n";
    cout << "\nEnter Your Option: ";
    cin >> x;
    switch (x) {
    case 1:
        Adminstrator();
        break;
    case 2:
        Customer();
        break;
    default:
        break;
    }
};

void Function::Adminstrator() {
    int x;
    cout << "\nThis is Adminstrator." << endl;
    cout << "\n   1. View Tickets" << endl;
    cout << "   2. Add Tickets" << endl;
    cout << "   3. Go Back" << endl;
    cout << "\nChoose Your Option: ";
    cin >> x;
    switch (x) {
    case 1:
        SearchTicket();
        Adminstrator();
        break;
    case 2:
        AddTicket();
        Adminstrator();
        break;

    case 3:
        Login();
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
        Adminstrator();
        break;

    }//OPTION FOR ADMIN
};

void Function::Customer() {
int x;
cout << endl;
cout << "\t\t----------------->FLIGHT BOOKING SERVICE<-----------------" << endl;
cout << "\nChoose Your Service(s)\n" << endl;
cout << "   1. Book a Flight" << endl;
cout << "   2. Find your Flight" << endl;
cout << "   3. Cancel a Flight" << endl;
cout << "   4. Show all the Location" << endl;
cout << "   5. Go Back" << endl;
cout << "\nChoose Your Option: ";
cin >> x;
switch (x) {
case 1:
    BookFlight(X_Y, Storage);
    break;
case 2:
    FindFlight(Storage);
    Customer();
    break;
case 3:
    CancelFlight(Storage);
    Customer();
    break;
case 4:
    ShowLocation();
    Customer();
    break;
case 5:
    Login();
    break;
default:
    cout << "Invalid input. Please try again." << endl;
    Customer();
    break;
};
};//OPTION FOR CUSTOMER

void Function::ShowAllTickets(AirTicket x[], int Ticket, int codeS, int codeD) {
    int j = codeS * 100 + codeD * 10;
    cout << x[j].Scountry << " --> " << x[j].Dcountry << endl;
    cout << endl;
    for (int i = 0; i < Ticket; i++) {
        j = codeS * 100 + codeD * 10 + i;

        cout << i + 1 << ". " << Airline[x[j].AirlineNo] << endl;


        cout << "\tCurrent: " << x[j].Source << " Airport\t" << "\tDestination: " << x[j].Destination << " Airport";
        cout << "\tDD: " << x[j].DDate << endl;
        cout << "\tDepartureTime:\t" << x[j].Dtime << ":" << x[j].Dmin << "\t\tArrivalTime:\t" << x[j].Atime << ":" << x[j].Amin << "\t\tCost:\t" << "$ " << x[j].cost << endl;
        cout << "\tEstimated Flight Time: " << x[j].flightime << "hrs" << endl;
        cout << endl;
    }

};

void Function::SearchTicket() {
    int x, y;
    ShowLocation();
    cout << "\nChoose Your departure Location: ";
    cin >> x;
    cout << "Choose Your Destination: ";
    cin >> y;

    ShowAllTickets(X_Y, ConfirmArrayNumber(X_Y, x, y), x, y);


}; //USE SHOWTICKET

void Function::ShowLocation() {
    cout << "\nLocation:" << "\n" << endl;
    for (int i = 1; i < z; i++) {
        cout << "\t " << i << ". " << CT[i] << endl;
    }
};


//ADDING TICKETS HERE
void Function::AddTicket() {
    string airlineName = "";
    int codeS, codeD;

    cout << endl;
    Function::ShowLocation();
    cout << "\nEnter Current Location: ";
    cin >> codeS;
    cout << "Enter Destination: ";
    cin >> codeD;

    int j = codeS * 100 + codeD * 10 + Function::ConfirmArrayNumber(X_Y, codeS, codeD);

    cout << "Put the airline name to be added: ";
    //I need to put it twice because the first one read the previous input.
    getline(cin, airlineName);
    getline(cin, airlineName);
    Function::Airline[Function::ConfirmArrayNumber(X_Y, codeS, codeD)+1] = airlineName;
    X_Y[j].AirlineNo = Function::ConfirmArrayNumber(X_Y, codeS, codeD) + 1;

    cout << "Enter the Base cost($): ";
    cin >> X_Y[j].cost;
    cout << "Enter the Desired Flight Time (in hr): ";
    cin >> X_Y[j].flightime;

    X_Y[j].Atime = X_Y[j].Dtime + X_Y[j].flightime;
    if (X_Y[j].Dtime >= 24)
        X_Y[j].Dtime -= 24;

    X_Y[j].scaling = (X_Y[j].cost * X_Y[j].flightime) / 10000;

    cout << "Ticket Successfully Added" << endl;
    cout << endl;
    cout << "Ticket Info: " << endl;
    Function::ShowFlight(X_Y, j, Function::ConfirmArrayNumber(X_Y, codeS, codeD));

};




void Function::BookFlight(AirTicket x[], AirTicket y[]) {
    int codeS, codeD;
    int choice;
    int ticket = 0;
    char ans;

    Function::ShowLocation();
    cout << "\nChoose Your Current Location: ";
    cin >> codeS;
    cout << "Choose Your Destination: ";
    cin >> codeD;

    string ddate;
    cout << "Date of Departure (MM/DD/YYYY): ";
    cin >> ddate;

    for (int t = 0; t < 1000; t++) {
        Function::X_Y[t].DDate = ddate;
    }


    int choice1 = 0;
    cout << "\nResult would be sorted by: \n";
    cout << "\n   1. Cheapest\n";
    cout << "   2. Fastest\n";
    cout << "   3. Best\n";
    cout << "\nChoose Your Option: ";
    cin >> choice1;

    switch (choice1) {
    case 1:
        Function::SortingByPrice(Function::X_Y, Function::ConfirmArrayNumber(Function::X_Y, codeS, codeD), codeS, codeD);
        break;
    case 2:
        Function::SortingByFlightTime(Function::X_Y, Function::ConfirmArrayNumber(Function::X_Y, codeS, codeD), codeS, codeD);
        break;
    default:
        Function::SortingByBest(Function::X_Y, Function::ConfirmArrayNumber(X_Y, codeS, codeD), codeS, codeD);
        break;
    }

    cout << endl;
    ShowAllTickets(X_Y, ConfirmArrayNumber(X_Y, codeS, codeD), codeS, codeD); //SHOW 5 TICKETS ADD TICKET NEEDS CHANGE
    cout << endl;

    cout << "1. Book the ticket" << endl;
    cout << "2. Go Back" << endl;
Back2:
    cout << "\nChoose Your Option: ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Choose Your Ticket No.: ";
        cin >> ticket;
        break;
    case 2:
        Customer();
        break;
    default:
        cout << "INVALID INPUT. PLEASE TRY AGAIN\n";
        goto Back2;
    };
Back3:
    int j = codeS * 100 + codeD * 10 + (ticket - 1); //Array starts from 0
    cout << endl;

    CopyingTicket(y, nct, x, j);
    ShowFlight(Storage, nct, ticket);
    cout << "This is the flight you want to book?\n";

        cout << "Answer(Y/N): ";
        cin >> ans;
        if (ans == 'n')
            Customer();



        int choose = 0;

        cout << endl;
        cout << "1. First Class    - Total Cost = " << "$ " << y[nct].cost + 532 << endl;;
        cout << "2. Business Class - Total Cost = " << "$ " << y[nct].cost + 317 << endl;
        cout << "3. Economy Class  - Total Cost = " << "$ " << y[nct].cost << endl;
        cout << "\nChoose Your Option: ";
        cin >> choose;

        switch (choose) {
        case 1:
            y[nct].cost += 532;
            cout << "You have been upgraded to First Class." << endl;
            cout << "\nThis Flight will cost: " << "$ " << y[nct].cost << endl;
            break;
        case 2:
            y[nct].cost += 317;
            cout << "You have been upgraded to Business Class." << endl;
            cout << "\nThis Flight will cost: " << "$ " << y[nct].cost << endl;
            break;
        default:
            cout << "You have chosen Economy Class." << endl;
            cout << "\nThis Flight will cost: " << "$ " << y[nct].cost << endl;
            break;
        }


        cout << "\nPlease Enter your Paypal Number: ";
        int paypal = 0;
        cin >> paypal;
        cout << "Account number identified." << endl;
        cout << "Confirm Payment?(Y/N): ";
        cin >> ans;
        if (ans == 'n')
            goto Back3;
        cout << endl;
        cout << "IMPORTANT" << endl;
        cout << "You have bought this ticket successfully.";
        cout << " Your Ticket ID is " << y[nct].id << endl;
        cout << endl;
        nct++;
        Customer();
};//USE SHOWTICKET


void Function::ShowFlight(AirTicket x[], int j, int tickets) {
    cout << x[j].Scountry << " --> " << x[j].Dcountry << endl;
    cout << "\n" << tickets << ". " << Airline[x[j].AirlineNo] << endl;
    cout << "\tCurrent: " << x[j].Source << " Airport\t" << "\tDestination: " << x[j].Destination << " Airport";
    cout << "\tDD: " << x[j].DDate << endl;
    cout << "\tDepartureTime:\t" << x[j].Dtime << ":" << x[j].Dmin << "\t\tArrivalTime:\t" << x[j].Atime << ":"<< x[j].Amin << "\t\tCost:\t" << "$ " << x[j].cost << endl;
    cout << "\tEstimated Flight Time: " << x[j].flightime << "hrs" << endl;
    cout << endl;
};

void Function::FindFlight(AirTicket x[]) {
    int ticketnumber;
    int counter = 0;
    cout << "Enter your Ticket Number: ";
    cin >> ticketnumber;
    for (int i = 0; i <= nct; i++) {
        if (ticketnumber == x[i].id) {
            cout << endl;
            cout << "Here is your ticket info: " << endl;
            cout << endl;
            ShowFlight(Storage, i, i + 1);
            counter = 1;
        }
    }
    if (counter == 0) {
        cout << endl;
        cout << "\t\t*********Invalid Ticket Number. Please Try again.*********" << endl;
    }

};

void Function::CancelFlight(AirTicket x[]) {
    int ticketnumber;
    int counter = 0;
    int i;

    cout << "Please Enter Your Ticket Number: ";
    cin >> ticketnumber;
    for (i = 0; i <= nct; i++) {
        if (ticketnumber == x[i].id) {
            cout << endl;
            cout << "Here is your ticket info" << endl;
            ShowFlight(Storage, i, i + 1);
            counter = 1;
        }
    }
    if (counter == 0) {
        cout << endl;
        cout << "\t\t*********Invalid Ticket Number. Please Try again.*********" << endl;
        Customer();
    }

    char answer;
    cout << "Do you want to cancel the book for this ticket? (y/n)" << endl;
    cout << "Answer: ";
    cin >> answer;
    if (answer == 'y') {
        cout << "Cancellation Successful. The cost will be refunded to your account." << endl;
        CopyingTicket(Storage, i, X_Y, 0);
    }

};

void Function::CopyingTicket(AirTicket y[], int i, AirTicket x[], int j) {
    y[i].Scountry = x[j].Scountry;
    y[i].Dcountry = x[j].Dcountry;
    y[i].Source = x[j].Source;
    y[i].Destination = x[j].Destination;
    y[i].DDate = x[j].DDate;
    y[i].Dtime = x[j].Dtime;
    y[i].Atime = x[j].Atime;
    y[i].Dmin = x[j].Dmin;
    y[i].Amin = x[j].Amin;
    y[i].cost = x[j].cost;
    y[i].flightime = x[j].flightime;
    y[i].scaling = x[j].scaling;
    y[i].AirlineNo = x[j].AirlineNo;
    y[i].id = j;
}

void Function::SortingByPrice(AirTicket x[], int Ticket, int codeS, int codeD) {
    int j = codeS * 100 + codeD * 10;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < Ticket-1; i++) {

            if (x[j + i].cost > x[j + i + 1].cost) {
                CopyingTicket(x, 10, x, j + i);
                CopyingTicket(x, j + i, x, j + i + 1);
                CopyingTicket(x, j + i + 1, x, 10);
                sorted = false;
            }

        }
    }
}

void Function::SortingByFlightTime(AirTicket x[], int Ticket, int codeS, int codeD){
    int j = codeS * 100 + codeD * 10;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < Ticket-1; i++) {

            if (x[j + i].flightime > x[j + i + 1].flightime) {
                CopyingTicket(x, 10, x, j + i);
                CopyingTicket(x, j + i, x, j + i + 1);
                CopyingTicket(x, j + i + 1, x, 10);
                sorted = false;
            }

        }
    }
}

void Function::SortingByBest(AirTicket x[], int Ticket, int codeS, int codeD) {
    int j = codeS * 100 + codeD * 10;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < Ticket-1; i++) {

            if (x[j + i].scaling > x[j + i + 1].scaling) {
                CopyingTicket(x, 10, x, j + i);
                CopyingTicket(x, j + i, x, j + i + 1);
                CopyingTicket(x, j + i + 1, x, 10);
                sorted = false;
            }

        }
    }

}

//CONFIRM HOW MANY DATA IS IN THE AIRLINE[]
int Function::ConfirmArrayNumber(AirTicket x[], int codeS, int codeD) {
    int n = 0;
    int j = codeS * 100 + codeD * 10;

    for (int i = 0; i < z; i++) {
        if (x[j + i].AirlineNo != 0) {
            n++;
        }
    }
    return n;
}


