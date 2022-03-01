//
//  main.cpp
//  COMP250_PracticeCode_for_Function
//
//  Created by Wataru Oshima on 2019/10/01.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

char courseGrade(int score) {
  
    switch (score) {
        case 4:
            return 'A';
            break;
         case 3:
            return 'B';
            break;
        case 2:
            return 'C';
            break;
        case 1:
            return 'D';
            break;
        default:
            break;
    }

    return score;
}

int main(int argc, const char * argv[]) {
    
    int score;
    char grade;
    cout << "Put your score: "; cin >> score;
    grade = courseGrade(score);
    cout << "Your grade is " << grade << endl;
    return 0;
}
