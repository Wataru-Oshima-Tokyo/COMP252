//
//  main.cpp
//  Template
//
//  Created by Wataru Oshima on 2020/03/17.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <iostream>
using namespace std;

//テンプレートベーシックタイプ
template <typename T_n>
T_n Add(T_n tnA, T_n tnB) {
    return tnA + tnB;
}

//変数パラメータ付き
template <class T_n, class T_p1, class T_p2>
T_n Multiply(T_p1 tnA, T_p2 tnB) {
    return tnA * tnB;
}

//変数異型、最初からデータタイプを宣言している状態
template <int iV>
int Add(int iValue){
    return iValue + iV;
}
int main(int argc, const char * argv[]) {
    double dValue = Add(5.0, 5.1);
    int iValue = Add<int>(5, 1);
    float mValue = Multiply<int>(2.6, 1.7);
    int iValue2 = Add<3>(5);
    cout << iValue2 << endl;
    return 0;
}
