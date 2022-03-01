//Flight Ticket Booking Program
//

#include "Function.hpp"
#include <time.h>
#include <iostream>


int main(){

    srand(time(NULL)); //random seed generator for the random number generator link in the document

    Function function;    //Creating the functions
    function.TicketGenerator(function.X_Y, 9); //Randomly generating all the functions
    function.Login(); //Interface, every other function interact with each  other in the function cpp file
    
    
    return 0;

}
