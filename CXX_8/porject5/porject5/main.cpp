
#include "Function.hpp"

int main(){
    srand(time(NULL)); //random generator seed

    Function function;
    function.TicketGenerator(function.X_Y, 9);
    function.Login();
    
    
    return 0;

}
