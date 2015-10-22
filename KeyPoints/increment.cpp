// File: test.cpp
// Author: lxw
// Date: 2015-10-22

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

    return 0;
}

/*
Output:

lxw Desktop$ ./a.out 
12

a: 12
a: 12
++(++a):14
a: 14
(++a)++:15
a: 16
*/
