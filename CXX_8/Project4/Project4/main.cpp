//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <time.h>
//#include <cmath>
#include "Function.hpp"
//using namespace std;


int main(){
    srand(time(NULL)); //random generator seed

    Function function;
    function.TicketGenerator(function.X_Y, 9);
    function.Login();
    
    
    return 0;

}

