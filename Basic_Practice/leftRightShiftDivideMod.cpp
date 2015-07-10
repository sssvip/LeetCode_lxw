// File: leftRightShiftDivideMod.cpp
// Author: lxw
// Date: 2015-07-10

#include <iostream>
using namespace std;

int main(void){
    int a = 10;
    cout << (a << 1) << endl;   //20
    a = -10;
    cout << (a << 1) << endl;   //-20
    a = 10;
    cout << (a >> 1) << endl;   //5
    a = -10;
    cout << (a >> 1) << endl;   //-5
    a = 3;
    cout << (a << 1) << endl;   //6
    a = -3;
    cout << (a << 1) << endl;   //-6
    a = 3;
    cout << (a >> 1) << endl;   //1
    //NOTE: negative integer ">>1" MAY NOT EQUAL TO "/2".
    a = -3;
    cout << (a >> 1) << ", " << a / 2 << endl;   //-2, -1. NOTE: NOT -1, -1. NOT -2, -2.

    a = 1;
    cout << (a & 0x01) << endl; //1
    a = -1;
    cout << (a & 0x01) << endl; //1
    a = 0;
    cout << (a & 0x01) << endl; //0
    a = 2;
    cout << (a & 0x01) << endl; //0
    a = -2;
    cout << (a & 0x01) << endl; //0

    cout << 13 % 4 << endl;         //1
    cout << 13 % (-4) << endl;      //1
    cout << (-13) % 4 << endl;      //-1
    cout << (-13) % (-4) << endl;   //-1
    cout << 15 % 4 << endl;         //3
    cout << 15 % (-4) << endl;      //3
    cout << (-15) % 4 << endl;      //-3
    cout << (-15) % (-4) << endl;   //-3
    return 0;
}
/*
lxw LeetCode_lxw$ ./a.out 
20
-20
5
-5
6
-6
1
-2, -1
1
1
0
0
0
1
1
-1
-1
3
3
-3
-3
*/
