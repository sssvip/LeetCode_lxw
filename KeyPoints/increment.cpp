// File: test.cpp
// Author: lxw
// Date: 2015-10-22
//
// ++a; & a += 1; is left value.
// a++; is right value;

#include <iostream>
using namespace std;

int main(void){
    int a = 10;
    (++a) += 1; //"++a" return the current(after increment) value of a.(left value)
    cout << a << endl;
    //(a++) += 1; //Error. "a++" return the original(before increment) value of a.(right value)

    cout << endl;
    cout << "a: " << a << endl;
    //cout << "++(a++):" << ++(a++) << endl << endl;    //Error.
    cout << "a: " << a << endl;
    cout << "++(++a):" << ++(++a) << endl;
    cout << "a: " << a << endl;
    cout << "(++a)++:" << (++a)++ << endl;
    cout << "a: " << a << endl;
    cout << "a += 1: " << (a += 1) << endl; //16
    cout << "a += 1 = 10: " << ((a += 1) = 10) << endl; //10 (a += 1 = 10) not OK. //a += 1; return the current value of a. (left value)
    cout << "a: " << a << endl;

    return 0;
}

/*
Output:
lxw KeyPoints$ ./a.out 
12

a: 12
a: 12
++(++a):14
a: 14
(++a)++:15
a: 16
a += 1: 17
a += 1 = 10: 10
a: 10
lxw KeyPoints$ 
*/
