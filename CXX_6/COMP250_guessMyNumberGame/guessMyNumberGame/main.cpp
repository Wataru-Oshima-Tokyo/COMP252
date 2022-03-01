//
//  main.cpp
//  guessMyNumberGame
//
//  Created by Wataru Oshima on 2019/09/17.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int targetNumber = 10;
    int x = 0;
    int i = 1;
Loop:
    if (i<=3) {
        cout << "Enter your guess: " << endl;
        cin >> x;
        
        if (targetNumber < x) {
            if (targetNumber < (x-3)) {
                cout << "too high.";
                i = i + 1;
                if (i<4) {
                    cout << " Guess again." << endl;
                }
                goto Loop;
            }else {
                cout << "high";
                i = i + 1;
                if (i<4) {
                    cout << " Guess again." << endl;
                }
                goto Loop;
            }
        } else if (targetNumber > x) {
            if (targetNumber > (x+3)) {
                cout << "too low." ;
                i = i + 1;
                if (i<4) {
                    cout << " Guess again." << endl;
                }
                goto Loop;
            }else {
                cout << "low.";
                i = i + 1;
                if (i<4) {
                    cout << " Guess again." << endl;
                }
                goto Loop;
            }
        } else if (targetNumber == x) {
            cout << "Your guess is correct. And you guessed it right after " << i << " times" << endl;
        }
    } else {
        cout << " \nYou attemptted 3 times. Then you have no chance any more." << endl;
    }
    return 0;
}
