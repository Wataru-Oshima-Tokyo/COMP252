//
//  main.cpp
//  COMP250_assignment
//
//  Created by Wataru Oshima on 2019/09/18.
//  Copyright © 2019 Wataru Oshima. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
 
    string a,b,c,d,w,x,y,z,A,B,C,D;
    
    
    cout << "Enter 4 names" << endl;
    cout << "a: ";
    cin >> a;
    A = a;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    cout << "b: ";
    cin >> b;
    B = b;
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    cout << "c: ";
    cin >> c;
    C = c;
    transform(c.begin(), c.end(), c.begin(), ::tolower);
    cout << "d: ";
    cin >> d;
    D = d;
    transform(d.begin(), d.end(), d.begin(), ::tolower);
    
//    compare << a << b << c << d << endl;
    if (a > b) {
        if (a > c) {
            if (a>d) {
                z = A;
                if (b>c) {
                    if (b>d) {
                        y = B;
                        if (c > d) {
                            x = C;
                            w = D;
                        } else {
                            x = D;
                            w = C;
                        }
                    } else {
                        y = D;
                        x = B;
                        w = C;
                    }
                } else {
                    if (b > d) {
                        y = C;
                        x = B;
                        w = D;
                    } else {
                        w = B;
                        if (d > c) {
                            y = D;
                            x = C;
                        } else {
                            y = C;
                            x = D;
                        }
                    }
                }
            } else {
                z = D;
                y = A;
                if (b > c) {
                    x = B;
                    w = C;
                } else {
                    x = C;
                    w = B;
                }
            }
        } else {
            if (a > d) {
                z = C;
                y = A;
                if (b >d) {
                    x = B;
                    w = D;
                } else {
                    x = D;
                    w = B;
                }
            } else {
                x = A;
                w = B;
                if (c > d) {
                    z = C;
                    y = D;
                } else {
                    z = D;
                    y = C;
                }
            }
        }
    } else {
        if (a > c) {
            if (a > d) {
                z = B;
                y = A;
                if (d > c) {
                    x = D;
                    w = C;
                } else {
                    x = C;
                    w = D;
                }
            } else {
                x = A;
                w = C;
                if (b > d) {
                    z = B;
                    y = D;
                } else {
                    z = D;
                    y = B;
                }
            }
        } else {
            if (a > d) {
                x = A;
                w = D;
                if (b > c) {
                    z = B;
                    y = C;
                } else {
                    z = D;
                    y = B;
                }
            } else {
                w = A;
                if (b > c) {
                    if (c > d) {
                        z = B;
                        y = C;
                        x = D;
                    } else {
                        if (b > d) {
                            z = B;
                            y = D;
                            x = C;
                        } else {
                            z = D;
                            y = B;
                            x = C;
                        }
                    }
                } else {
                    if (b > d) {
                        z = C;
                        y = B;
                        x = D;
                    } else {
                        x = B;
                        if (d > c) {
                            z = D;
                            y = C;
                        } else {
                            z = C;
                            y = D;
                        }
                    }
                }
            }
        }
    }
    cout << "If the names are in order alphabetically, they should be: " << w << " " << x << " " << y << " " << z << endl;
    
    return 0;
}
