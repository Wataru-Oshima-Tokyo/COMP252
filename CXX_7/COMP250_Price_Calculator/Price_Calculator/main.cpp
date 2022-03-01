//
//  main.cpp
//  Price_Calculator
//
//  Created by Wataru Oshima on 2019/09/29.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, const char * argv[]) {

    //plan A = 15.95 + .20n
    //plan B = 25.95 + .10n
    //plan C = 45.95
    string n, plan, notPlan, costSaving, comment1, comment2, comment3, costString;
    int numberOfMessages;
    double difference = 0.0, cost;
    char caseOfPlan;

Loop:
    caseOfPlan = 1;
    cout << "Please put the number of messages you may send or 'n' if you want to finish this calculator: ";
    cin >> n;
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    if (n == "n") {
        //goto LoopEnd;
    } else {
        stringstream geek (n);
        geek >> numberOfMessages;
        if ((15.95 + .20*(numberOfMessages -10)) <= 25.95) {
            plan = "A";
            notPlan = "B";
            cost = 15.95 + .20*(numberOfMessages -10);
            difference = 25.95 - (15.95 + .20 * (numberOfMessages-10));
            if ((15.95 + .20*(numberOfMessages -10)) == 25.95) {
                caseOfPlan = 2;
            }
            goto CommentOut;

        } else if ((25.95 < (15.95 + .20 * (numberOfMessages-10))) && (45.95 > (25.95 + .10 * (numberOfMessages-20)))){
            plan = "B";
            notPlan = "A";
            cost = 25.95 + .10 * (numberOfMessages-20);
            difference =  (15.95 + .20 * (numberOfMessages-10)) - 25.95;
            goto CommentOut;

        } else if (45.95 <= (25.95 + .10 * (numberOfMessages-20))){
            plan = "C";
            notPlan = "B";
            cost = 45.95;
            difference = (25.95 + .10 * (numberOfMessages-20)) - 45.95;
            if (45.95 == (25.95 + .10 * (numberOfMessages-20))) {
                caseOfPlan = 2;
            }
            goto CommentOut;
        } else {
            cout << "Your input is invalid. Please put a number or 'n'" << endl;
            goto LoopEnd;
        }
    CommentOut:
        costSaving = to_string(difference);
        costString = to_string(cost);
        comment1 = "I recommend you to choose plan " + plan + ".\n";
        comment3 = "The cost will be " + costString + ".\n";
        switch (caseOfPlan) {
            case 2:
                comment2 = "And you can choose plan " + plan + " or plan " + notPlan + ". Because it costs you the same amount of moeny.";
                break;
            case 1:
                comment2 = "And you can save money $" + costSaving + " rather than choosing plan " + notPlan + ".";
            default:
                break;
        }
        cout << comment1 << comment3 << comment2 << endl;
        goto Loop;
    }

LoopEnd:
    cout << "Thank you for using this calculator!!" << endl;
    return 0;


    
}
