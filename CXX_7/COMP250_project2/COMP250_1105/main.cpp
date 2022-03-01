


#include <iostream>
#include <string>
using namespace std;


struct Flightinfo {
    string Current;
    string Destination;
    string Departure;
    string Airrival;
    float FlightTime;
};

int Administrator (int x);

int Customer(int x);


void Bookflight(int x);
void Cancelflight(int x);

int main() {
//Choose to log in as admin or customer
    int login, choiceA = 0, choiceB = 0;

Back:
    cout << "Would you like to log in as Admin or Customer?" << endl;
    cout << "1. Administator\n";
    cout << "2. Customer\n";
    cin >> login;
    if (login == 1)
        choiceA = Administrator(login);
    else
        choiceB = Customer(login);

    switch (choiceA) {
        case 1:
                Addticket(choiceA);
                break;
        case 2:
                Deleteticket(choiceA);
                break;
        case 3:
                goto Back;
                break;
        default:
                break;
    }

    switch (choiceB) {
        case 1:
                Bookflight(choiceB);
                break;
        case 2:
                Cancelflight(choiceB);
                break;
        case 3:
                goto Back;
                break;
        default:
                break;
    }
    return 0;
}




int Adminstrator(int x) {
    int a;
    cout << "What do you want to do?";
    cout << "1. Add flight tickets";
    cout << "2. Delete flight tickets";
    cout << "3. Go Back";
    cin >> a;
    return a;
}


int Customer(int x) {
    int a;
    cout << "What do you want to do?";
    cout << "1. Book a Flight";
    cout << "2. Cancel Flight";
    cout << "3. Go Back";
    cin >> a;
    return a;
}

class manageTicket {
    void Addticket(int x){
        
    };
    void Deleteticket(int x);
};
