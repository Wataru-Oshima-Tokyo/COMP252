//
//  main.cpp
//  gradeCalculation
//
//  Created by Wataru Oshima on 2020/05/17.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;
void caluculateGrade(double midTermsPercentage, double quizzesPercentage, double labsPercentage, double labFinalPercentage);

void caluculateGrade(double midTermsPercentage, double quizzesPercentage, double labsPercentage, double labFinalPercentage)
{
    double midtermsRatio = .45, quizzesRatio = .05, labsRatio = .05, labFinalRatio = .05, finalExamRatio = .25, homeWorkRatio = .15;
    double currentTotal = midtermsRatio + quizzesRatio + labsRatio + labFinalRatio + homeWorkRatio;
    cout << currentTotal << endl;
    double currentGrade = (midTermsPercentage/100 * midtermsRatio + quizzesPercentage/100 * quizzesRatio + labsPercentage/100 * labsRatio + labFinalPercentage/100 * labFinalRatio + 0.98*homeWorkRatio) / currentTotal;
    cout << "Your current grade is " << currentGrade*100 << endl;
    
    double total = currentTotal + finalExamRatio;
    int n = 0;
    double expectedFinalExamScore = 0.0;
    double finalExamPercentage =0.0;
    double finalPercentage = 0.0;
    while (n!=-1)
    {
        cout << "Put your expected score for the final exam: ";
        cin >> expectedFinalExamScore;
        finalExamPercentage = expectedFinalExamScore/100;
        finalPercentage = (midTermsPercentage/100 * midtermsRatio + quizzesPercentage/100 * quizzesRatio + labsPercentage/100 * labsRatio + labFinalPercentage/100 * labFinalRatio + 0.98*homeWorkRatio + finalExamPercentage*finalExamRatio) / total;
        cout << "Your expected final score is " << finalPercentage*100 << endl;
        cout << "If you want to end this program, please put -1. If not put anynumber: ";
        cin >>n;
        expectedFinalExamScore = 0.0;
    }
    
    
}
int main(int argc, const char * argv[]) {

    double midTermsPercentage = 89.09, quizzesPercentage = 95.31, labsPercentage = 98.15, labFinalPercentage = 95;
//    cout << "Put your Midterms percentage: ";
//    cin >> midTermsPercentage;
//    cout << "Put your quizzes percentage: ";
//    cin >> quizzesPercentage;
//    cout << "Put your labs percentage: ";
//    cin >>labsPercentage;
//    cout << "Put your lab percentage: ";
//    cin >>labFinalPercentage;
    caluculateGrade(midTermsPercentage, quizzesPercentage, labFinalPercentage, labFinalPercentage);
    return 0;
}
