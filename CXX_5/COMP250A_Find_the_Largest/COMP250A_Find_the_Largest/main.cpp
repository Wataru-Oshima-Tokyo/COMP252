////
////  main.cpp
////  COMP250A_Find_the_Largest
////
////  Created by Wataru Oshima on 2019/10/22.
////  Copyright © 2019 Wataru Oshima. All rights reserved.
////
//
#include <iostream>
using namespace std;

void asscending (int a[], int b){
    bool answer = true;
    while (answer == true) {
        answer = false;
        for (int i = 0 ; i < b; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i+1]);
                answer = true;
            }

        }
    }

}

void COUT (int a[]) {
    for (int i = 0; i < 25; i++) {
        if (i !=24) {
        cout << a[i] << ", ";
        } else {
        cout << a[i] << ". \n" ;
        }
    }
}
int main(int argc, const char * argv[]) {
    int n, number[25];
    cout << "put 25 numbers. " << endl;
    for (int i = 0; i < 25; i++) {
        cout << "put " << i+1 << " number. : " ;
        cin >>n;
        number[i] = n;
    }
//    cout << "Your original array is ";
//    COUT(number);
    asscending(number, 25);
//    cout << "The asscending array is ";
//    COUT(number);
    cout << "The largest number is " << number[24] << endl;

    return 0;
}


//#include <iostream>
//using namespace std;
//
//
//void ascending (int num[25]);
//void descending(int num[25]);
//float average(int num[25]);
//
//int main() {
//
//    cout << "Sorting Program\n";
//    cout << "Enter your number\n";
//    int num[25] = {0};
//    for(int i = 0; i < 25; i++){
//        cout << i+1 << ". ";
//        cin >> num[i];
//
//    }
//    int choice = 1;
//    cout << "Please choose your sort type \n";
//    cout << "1. Ascending\n";
//    cout << "2. Descending\n";
//    cin >> choice;
//
////User chooses
//    string choices;
//    if(choice == 1){
//        ascending (num);
//        choices = "ascending";
//
//    }
//    else{
//        descending (num);
//        choices = "descending";
//
//    }
////max and min
//    int max, min;
//    if(choice == 1){
//        max = num[24];
//        min = num[0];
//    }else{
//        max = num[0];
//        min = num[24];
//    }
//
//    //Output
//    cout << endl;
//    cout << "Your " << choices << " Array is ";
//    for(int j = 0; j < 25; j++){
//        cout << num[j] << ",";
//    }
//    cout << endl;
//    cout << "Your average is " << average(num) << endl;
//    cout << "The max is " << max << endl;
//    cout << "The min is " << min << endl;
//    cout << "The median is " << num[12] << endl;
//
//    return 0;
//}
//
//void ascending(int num[25]){
//    bool sorted = false;
//
//    int temp;
//
//    while(!sorted){
//        sorted = true;
//        for(int a = 0; a < 24; a++){
//
//            if(num[a] > num[a+1]){
//
//                temp = num[a+1];
//                num[a+1] = num[a];
//                num[a] = temp;
//
//                sorted = false;
//                }
//            }
//        }
//    }
//void descending(int num[25]){
//    int temp;
//    bool sorted = false;
//    while(!sorted){
//        sorted = true;
//        for(int a = 0; a < 24; a++){
//
//            if(num[a] < num[a+1]){
//                temp = num[a+1];
//                num[a+1] = num[a];
//                num[a] = temp;
//                sorted = false;
//            }
//        }
//    }
//}
//float average(int num[25]){
//    float sum = 0;
//    for(int i = 0; i < 25; i++){
//        sum = sum + num[i];
//    }
//    float avg = sum/25;
//    return avg;
//}
