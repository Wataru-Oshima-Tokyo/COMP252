//
//  main.cpp
//  Kim_linkedlist
//
//  Created by Wataru Oshima on 2020/03/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//


#include <iostream>
#include <string>

template <typename type>
void print(type a)  { std::cout << a << std::endl;}

int fact(int a){
    if(a == 0)
        return 1;
    if(a == 1)
        return 1;
    if(a > 1){
        return a* fact(a-1);
    }else{
        std::cout << "Invalid input\n";
        return 0;
    }
}

int main(){
    
    std::cout << fact(5) << std::endl;
    return 0;
}
