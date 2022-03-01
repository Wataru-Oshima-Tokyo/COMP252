//
//  RDPHeader.hpp
//  comp252Project
//
//  Created by Wataru Oshima on 2020/05/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef RDPHeader_hpp
#define RDPHeader_hpp

#include <stdio.h>
#include <string>
//#include <iostream>



class RDPHoriginal{
public:
    int searchNDP(int deapthInput);
    void initializeNode();
    void println();
private:
    int deapth[12] = {10, 12, 14, 16, 18, 20, 22, 25, 30, 35, 40, 42};
    int length = 12;
    std::string PG[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X", "Y", "Z"};
    int NDP[12] = {219, 147, 98, 72, 56, 45, 37, 29, 20, 14, 9, 9};
};
    

#endif /* RDPHeader_hpp */
