//
//  Function.hpp
//  Project4
//
//  Created by Wataru Oshima on 2019/12/06.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Function {
public:
    /*
    Location
    1.United States
    2.Japan
    3.China
    4.Australia
    5.United Kingdom
    6.India
    7.France
    8.Egypt
    */
    const static int z = 9;
    string CT[z] = { "","United States","Japan","China","Australia","United Kingdom", "India", "France", "Egypt" };//CT are the country names
    string AP[z] = { "","Los Angeles", "Tokyo","Beijing","Sydney","London", "New Delhi", "Paris", "Cairo" };//Airport name
    string Airline[10] = { "", "Raccoon Airline", "Emerald Airway","Golden Dawn SkyTravel", "Chicken Airline","Lewis Airway", "Book Airline","","",""};//Airline name

    struct AirTicket {
        string Scountry = "Country's Name";//country name
        string Dcountry = "Country's Name";//country name
        string Source = "City's Name"; //city name
        string Destination = "City's Name"; //city name
        string DDate = "12/10/2019"; //Will be base on user once we create the interface
        int Dtime = 00;
        int Atime = 00;
        int Dmin = 00;
        int Amin = 00;
        int cost = 00;
        int flightime = 00;
        float scaling = 0; //Scaling determines best airline
        int AirlineNo = 0;
        int id = 0;
        string status = "Economy Class";
    };//Client: Copying Ticket, TicketGenerator (Line 93)

    AirTicket X_Y[1000]; // I just store everything into an array of structure. X_Y[(Current Location)(Destination)(TicketNo.)]. For example, ticket from US to UK would be X_Y[152].
    AirTicket Storage[10]; //Storage for when customer book a ticket
    int nct = 0; //Number of customer's tickets booked


    void TicketGenerator(AirTicket x[], int Ticket); //Generate All tickets with Randomize members (Line 93)

    //INTERFACE
    void Login(); //Login Interface (Line 143)
    void Adminstrator(); //Admin Interface (Line 162)
    void Customer(); //Customer Interface (Line 192)

    //ADMINSTARTOR INTERFACE

    void ShowAllTickets(AirTicket x[], int Ticket, int codeS, int codeD); //Show Available Tickets from codeS to codeD (Line 231)
    void SearchTicket();//Input codeS and codeD, uses Showticket (Line 250)
    void ShowLocation();//(Line 263)
    void AddTicket();//Add ticket to specific codeS -> codeD (Line 272)

    //CUSTOMER INTERFACE
    void BookFlight(AirTicket x[], AirTicket y[]); //Booking a Flight user interface and save to storage (Line 317)
    void ShowFlight(AirTicket x[], int j, int tickets); //Show specific flight by ID (Line 440)
    void FindFlight(AirTicket x[]);//Find booked flight from storage (Line 450)
    void CancelFlight(AirTicket x[]);//Cancel Booked Flight (Line 471)


    //OTHER FUNCTIONS
    void CopyingTicket(AirTicket y[], int i, AirTicket x[], int j); //Copy all items between 2 structs or the same structs (Line 503)
    void SortingByPrice(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting All tickets by price (Line 520)
    void SortingByFlightTime(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting All tickets by flighttime (Line 538)
    void SortingByBest(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting all tickets by Best (Line 556)
    int ConfirmArrayNumber(AirTicket x[], int codeS, int codeD); //Confirm how many tickets from CodeS to CodeD (Line 576)

};
#endif /* Function_hpp */
