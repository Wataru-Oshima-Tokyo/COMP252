//
//  People.cpp
//  main
//
//  Created by Wataru Oshima on 2019/12/03.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include "People.hpp"
#include "Birthday.hpp"
using namespace std;

People::People(string n, Birthday b)
:name(n), BO(b) // do not terminate this line which is only one line we do not need to put ";"
{

};

void People::showPeople(){
    cout << "The person's name is " << name << " and his birthday is " ;
    BO.showBirthDate();
};
