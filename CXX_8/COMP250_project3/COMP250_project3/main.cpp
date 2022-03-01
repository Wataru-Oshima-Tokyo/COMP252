#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

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


//CHANGES: AirTickets
const int z = 9;
string CT[z] = { "","United States","Japan","China","Australia","United Kingdom", "India", "France", "Egypt" };//CT are the country names
string AP[z] = { "","Los Angeles", "Tokyo","Beijing","Sydney","London", "New Delhi", "Paris", "Cairo" };//Airport name
string Airline[z] = { "", "Raccoon Airline", "Emerald Airway","Golden Dawn SkyTravel", "Chicken Airline","LowKey Airway" };//Airline name

struct AirTicket {
    string Scountry = "Country's Name";//country name
    string Dcountry = "Country's Name";//country name
    string Source = "City's Name"; //city name
    string Destination = "City's Name"; //city name
    string DDate = "11/14/2019"; //Will be base on user once we create the interface
    int Dtime = 00;
    int Atime = 00;
    int cost = 00;
    int flightime = 00;
    float scaling = 0; //Scaling determines best airline
    int id = 0;
};//Client ShowTicket, TicketGenerator

AirTicket X_Y[1000]; // I just store everything into an array of structure. X_Y[(Current Location)(Destination)(TicketNo.)]. For example, ticket from US to UK would be X_Y[152].
AirTicket Storage[10]; //Storage for when customer book a ticket
int nct = 0; //Number of customer's tickets booked

void ShowTicket(AirTicket x[], int Ticket, int codeS, int codeD); //prototype
void TicketGenerator(AirTicket x[], int Ticket); //prototype
void Login();
void Adminstrator();
void Customer();
void SearchTicket();
void ShowLocation();
void BookFlight(AirTicket x[], AirTicket y[]);
void ShowFlight(AirTicket x[], int j, int tickets);
void CancelFlight(); // INCOMPLETE
void DeleteTicket(string target[], string y);
void AddTicket(string target[], string x);
void Confirmation(int a);
int ConfirmArrayNumber(string target[]);
void PasswordConfirmation();


int main()
{
    srand(time(NULL)); //random generator seed

    TicketGenerator(X_Y, z);//TicketGenerator(AirTicket codename, Number of ticket you want to generate for each X -> Y)
//    cout << X_Y[423].Source << X_Y[423].Destination << endl;
    Login();


    return 0;

}

//TICKETGENERATOR FUNCTION
void TicketGenerator(AirTicket x[], int Ticket) {

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

                x[i].Dtime = rand() % 23 + 1;
                x[i].flightime = rand() % 8 + 5;
                x[i].Atime = x[i].Dtime + x[i].flightime;
                if (x[i].Atime >= 24)
                    x[i].Atime -= 24;

                a = rand() % 9 + 1;
                x[i].scaling = a * 0.1 + 1;
                float b = (10000 / x[i].flightime);
                //Since Cost is proportional to flightime, Scaling determine how expensive the airline is
                b = b * x[i].scaling;
                x[i].cost = (int)b;

            }
        }
    }


};

void ShowTicket(AirTicket x[], int Ticket, int codeS, int codeD) {
    int j = codeS * 100 + codeD * 10;
    cout << x[j].Scountry << "-->" << x[j].Dcountry << endl;
    cout << endl;
    int a, b;
    for (int i = 0; i < Ticket; i++) {
        a = rand() % 6 + 0; //Random Minutes(Doesn't matter)
        b = rand() % 6 + 0; //Random Minutes(Doesn't Matter)
        cout << i + 1 << "." << "  " << Airline[i + 1] << endl;
        j = codeS * 100 + codeD * 10 + i;

        cout << "\tCurrent: " << x[j].Source << " Airport\t" << "\tDestination: " << x[j].Destination << " Airport";
        cout << "\tDD: " << x[j].DDate << endl;
        cout << "\tDepartureTime:\t" << x[j].Dtime << ":" << a << "0" << "\t\tArrivalTime:\t" << x[j].Atime << ":" << b << "0" << "\t\tCost:\t" << x[j].cost << " $" << endl;
        cout << endl;
    }

};//FIX THE MINUTES

void PasswordConfirmation() {
    int i = 0;
    string password, empty;
    getline(cin, empty);
    while (i != 3) {
        cout << "What is the admin password?: ";
        getline(cin, password);
        if (password == "123") {
            Adminstrator();
        } else if (i < 2) {
            cout << "It is incorrect. Please try again" << endl;
            i = i + 1;
        } else {
            i = i +1;
        }
    }

    cout << "Yout failed to put the password 3 times. Please re-start this program again." << endl;
}

void Login() {
    int x;
    cout << "Accessing as:\n";
    cout << "1. Adminstrator\t\t\t2. Customer\n";
    cout << "Enter Your Option:";
    cin >> x;
    switch (x) {
    case 1:
        PasswordConfirmation();
        break;
    case 2:
        Customer();
        break;
    default:
        cout << "Invalid Input. Please try again." << endl;
        Login();
    }
};

//CONFIRM HOW MANY DATA IS IN THE AIRLINE[]
int ConfirmArrayNumber(string target[]) {
    int n = z - 1;
    for (int i = 1; i < z; i++) {
        if (target[i] == "") {
            n = i - 1;
            i = z;
        }
    }
    return n;
}

//ADDING TICKETS HERE
void AddTicket(string target[], string x, int a) {

    int n = 0;
    string AddedValue = "", empty;
    // ask admin to put the source, destination,
    for (int i = z; i > 0; i--) {
        if (target[i] == "") {
            n = i;
        }
    }
    if (target[z - 1] != "") {
        cout << "\n******** It does not have enough space to add a " << x << " anymore. **********" << endl;

        Adminstrator();
    }
    cout << "Put the " << x <<  " name to be added.: ";
    //I need to put it twice because the first one reads the previous input.
    getline(cin, empty);
    getline(cin, AddedValue);
    target[n] = AddedValue;
    if (a == 1) {
    cout << "Put the airport name to be added.: ";
    getline(cin, AddedValue);
        AP[n] = AddedValue;
    }

};

void DeleteTicket(string target[], string y, int a) {
        int x;
    int n = ConfirmArrayNumber(target);
        cout << "\nHere is what you have so far in the " << y << "[]. \n";
        for (int i = 1; i < n+1; i ++) {
            cout << i << ". " << target[i] << endl;
        }
        cout << "Which one do you want to erase? If you want to go back, please put 10: ";
        cin >> x;
    if (x != 10) {
        target[x] = "";
        for (int p = 1; p < n; p++ ) {
            if (target[p] == "" ) {
                switch (a) {
                    case 1:
                        target[p] = target[p+1];
                        target[p+1] = "";
                        AP[p] = AP[p+1];
                        AP[p+1] = "";
                        break;
                    case 2:
                        target[p] = target[p+1];
                        target[p+1] = "";
                    default:
                        break;
                }


            }

        }
        cout << "Then you have these in the " << y << "[]." << endl;
        for (int i = 1; i < ConfirmArrayNumber(target)+1; i ++) {
            switch (a) {
                case 1:
                    cout << i << ". " << target[i] << ", " <<AP[i] << endl;
                    break;
                case 2:
                    cout << i << ". " << target[i] << endl;
                default:
                    break;
            }
        }
    }

};

void Confirmation(int a) {
    int x = 0;
    cout << "1. Location \n2. AirLine" << endl;
    cout << "Which one do you want to change?: ";
    cin >> x;
    switch (x) {
        case 1:
            if (a == 2) {
            AddTicket(CT, "Location", x);
            } else {
            DeleteTicket(CT, "Location", x);
            }
            break;
        case 2:
            if (a == 2) {
            AddTicket(Airline, "AirLine", x);
            } else {
            DeleteTicket(Airline, "AirLine", x);
            }
            break;
        default:
            break;
    }
};

void Adminstrator() {
    int x;
    cout << "This is Adminstrator" << endl;
    cout << "1. View Tickets" << endl;
    cout << "2. Add Tickets" << endl;
    cout << "3. Delete Tickets" << endl;
    cout << "4. Go Back" << endl;
    cout << "Choose Your Option: ";
    cin >> x;
    switch (x) {
    case 1:
        SearchTicket();
        Adminstrator();
        break;
    case 2:
        Confirmation(x);
        Adminstrator();
        break;
    case 3:
        Confirmation(x);
        Adminstrator();
        break;
    case 4:
        Login();
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
        Adminstrator();
        break;

    }//OPTION FOR ADMIN
};

void Customer() {
    int x;
    cout << endl;
    cout << "\t\t----------------->FLIGHT BOOKING SERVICE<-----------------" << endl;
    cout << "Choose Your Service(s)" << endl;
    cout << "1. Book a Flight" << endl;
    cout << "2. Find your Flight" << endl;
    cout << "3. Cancel a Flight" << endl;
    cout << "4. Show all the Location" << endl;
    cout << "5. Go Back" << endl;
    cout << "Choose Your Option: ";
    cin >> x;
    switch (x) {
    case 1:
        BookFlight(X_Y, Storage);
        break;
    case 2:
        ///ShowFlight();
        break;
    case 3:
        CancelFlight();
        break;
    case 4:
        ShowLocation();
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

void SearchTicket(){
    int x, y;
    ShowLocation();
    cout << "Choose Your Current Location: ";
    cin >> x;
    cout << "Choose Your Destination: ";
    cin >> y;
    ShowTicket(X_Y, ConfirmArrayNumber(Airline), x, y); //SHOW 5 TICKETS ADD TICKET NEEDS CHANGE


}; //USE SHOWTICKET

void ShowLocation() {
    cout << "Location:" << endl;
    for (int i = 1; i <= ConfirmArrayNumber(CT); i++) {
        cout << i << ". " << CT[i] << endl;
    }
};

void BookFlight(AirTicket x[], AirTicket y[]) {
    int codeS, codeD;
    int choice;
    int ticket = 0;
    char ans;

    ShowLocation();
    cout << "Choose Your Current Location: ";
    cin >> codeS;
    cout << "Choose Your Destination: ";
    cin >> codeD;
Back1:
    cout << endl;
    ShowTicket(X_Y, ConfirmArrayNumber(Airline), codeS, codeD); //SHOW 5 TICKETS ADD TICKET NEEDS CHANGE
    cout << endl;

    cout << "1. Book the ticket" << endl;
    cout << "2. Go Back" << endl;
Back2:
    cout << "Choose Your Option: ";
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
    cout << "PROCESSING...This is the flight you want to book?(y/n)\n";
    cout << endl;
     y[nct].Scountry =x[j].Scountry;
     y[nct].Dcountry= x[j].Dcountry;
     y[nct].Source= x[j].Source;
     y[nct].Destination= x[j].Destination;
     y[nct].DDate =x[j].DDate;
     y[nct].Dtime =x[j].Dtime;
    y[nct].Atime= x[j].Atime;
    y[nct].cost =x[j].cost;
    y[nct].flightime =x[j].flightime;
    y[nct].scaling =x[j].scaling;
    y[nct].id = j;
    //INSERT SHOWFLIGHT FUNCTION
    ShowFlight(Storage, nct, ticket);
        cout << "Answer: ";
        cin >> ans;
        if (ans == 'n')
            goto Back1;
        cout << "This Flight will cost: " << y[nct].cost << "$." << endl;
        cout << "Please Enter your Paypal Number: ";
        int paypal = 0;
        cin >> paypal;
        cout << "Account number identified.";
        cout << " Confirm Payment?(y/n): ";
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

void ShowFlight(AirTicket x[], int j, int tickets) {
    cout << x[j].Scountry << "-->" << x[j].Dcountry << endl;
    cout << tickets << "." << "  " << Airline[tickets] << endl;
    cout << "\tCurrent: " << x[j].Source << " Airport\t" << "\tDestination: " << x[j].Destination << " Airport";
    cout << "\tDD: " << x[j].DDate << endl;
    cout << "\tDepartureTime:\t" << x[j].Dtime << ":" << "00" << "\t\tArrivalTime:\t" << x[j].Atime << ":"<< "00" << "\t\tCost:\t" << x[j].cost << " $" << endl;
    cout << endl;
}; //FIX THE MINUTES

void CancelFlight() {
    cout << "This is Cancelflight Function" << endl;
}; // INCOMPLETE
