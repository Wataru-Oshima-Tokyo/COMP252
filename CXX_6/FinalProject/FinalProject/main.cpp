#include "Function.hpp"
#include <time.h>



int main(){

    srand(time(NULL)); //random seed generator

    Function function;
    function.TicketGenerator(function.X_Y, 9);
    function.Login();
    
    
    return 0;

}
