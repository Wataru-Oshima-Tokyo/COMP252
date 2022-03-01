#include <iostream>
#include <String>

using namespace std;

//class testClass {
//public:
//    int x;
//    void testFunction(int a, int b){
//        c = a*b;
//        cout << c << endl;
//    }
//private:
//    int y;
//protected:
//    int c;
//
//
//};

//class clockType {
//private:
//    int hour = 0;
//    int minute = 0;
//    int second = 0;
//public:
//
//    int  get_hour(int a) {
//        hour = a;
//        return hour;
//    };
//
//    int get_minute(int a ) {
//        minute = a;
//        return minute;
//    };
//
//    int get_second(int a) {
//        second = a;
//        return second;
//    };
//};
//
//void showTime(int a, int b, int c);

class mclock {
private:
    int hour = 0;
    string minute = "";
    float second = 0.0;
    
public:
    int get_hour(){
        return hour;
    };
    void set_hour(int h) {
        hour = h;
//        return true;
    }
    string get_minute() {
        return minute;
    };

    void set_minute(string m) {
        minute = m;
//        return true;
    }

    float get_second() {
        return second;
    };
    void set_second(float s) {
        second = s;
    }
    
    mclock(int a, string b, float c){
        hour = a;
        minute = b;
        second = c;
    }
    mclock(int a, string b){
        mclock(a, b, 0);
    }
    mclock(int a){
        mclock(a, "", 0.0);
    }
    
    mclock(){
        mclock(0, "", 0.0); // avoiding memory to be put in the memory
    }
    
    ~mclock(){
        cout << "The objects are properly parged" << endl;
    }
};

int main(int argc, const char * argv[]) {


    mclock x(5); // why it shows 0 thogh I defined 5
    cout << x.get_hour() << endl;
    
    return 0;
}

