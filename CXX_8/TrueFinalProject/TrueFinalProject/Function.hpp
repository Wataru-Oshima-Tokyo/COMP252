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
    //Each country are assignment to a number Eg. US is 1

    const static int z = 9; //Number of cities and Countries
    string CT[z] = { "","United States","Japan","China","Australia","United Kingdom", "India", "France", "Egypt" };//CT are the country names, Position of each country is the same to its assigned number
    string AP[z] = { "","Los Angeles", "Tokyo","Beijing","Sydney","London", "New Delhi", "Paris", "Cairo" };//Airport name aligned with the country names array
    string Airline[10] = { "", "Raccoon Airline", "Emerald Airway","Golden Dawn SkyTravel", "Chicken Airline","Lewis Airway", "Book Airline","","",""};//Airline names

    struct AirTicket {
        string Scountry = "Country's Name";//country name
        string Dcountry = "Country's Name";//country name
        string Source = "City's Name"; //city name
        string Destination = "City's Name"; //city name
        string DDate = "12/10/2019"; //Will be base on user once we create the interface
        int Dtime = 00;//Departure Time Will be randomized using rand
        int Atime = 00;//Arrival Time Will use Dtime + flighttime
        int Dmin = 00; //Departure minutes will be randomized
        int Amin = 00; //Arrival minutes will be randomized
        int cost = 00; //We have a formula to calculate it in TicketGenerator Function
        int flightime = 00;//Will be randomized
        float scaling = 0; //Scaling determines best airline (Formula in TicketGenerator Function)
        int AirlineNo = 0;// Assign it the airline
        int id = 0; //CodeS*100 + CodeD*10 + ticket (each id can tell you the current location and destination by comparing it to the number assigned to each country
        string status = "Economy Class"; //Default class
    };//Client: Copying Ticket, TicketGenerator (Line 93)

    AirTicket X_Y[1000]; // I just store everything into an array of structure. X_Y[(Current Location)(Destination)(TicketNo.)]. For example, ticket from US to UK would be X_Y[152].
    AirTicket Storage[10]; //Storage for when customer book a ticket
    int nct = 0; //Number of customer's tickets booked


    void TicketGenerator(AirTicket x[], int Ticket); //Generate All tickets with Randomize members

    //INTERFACE
    void Login(); //Login Interface
    void Adminstrator(); //Admin Interface
    void Customer(); //Customer Interface

    //ADMINSTARTOR INTERFACE

    void ShowAllTickets(AirTicket x[], int Ticket, int codeS, int codeD); //Show Available Tickets from codeS to codeD
    void SearchTicket();//Input codeS and codeD, uses Showticket
    void ShowLocation();
    void AddTicket();//Add ticket to specific codeS -> codeD
    //CUSTOMER INTERFACE
    void BookFlight(AirTicket x[], AirTicket y[]); //Booking a Flight user interface and save to storage
    void ShowFlight(AirTicket x[], int j, int tickets); //Show specific flight by ID
    void FindFlight(AirTicket x[]);//Find booked flight from storage
    void CancelFlight(AirTicket x[]);//Cancel Booked Flight


    //OTHER FUNCTIONS
    void CopyingTicket(AirTicket y[], int i, AirTicket x[], int j); //Copy all items between 2 structs or the same structs
    void SortingByPrice(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting All tickets by price
    void SortingByFlightTime(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting All tickets by flighttime
    void SortingByBest(AirTicket x[], int Ticket, int codeS, int codeD); //Sorting all tickets by Best
    int ConfirmArrayNumber(AirTicket x[], int codeS, int codeD); //Confirm how many tickets from CodeS to CodeD (

};
#endif /* Function_hpp */
