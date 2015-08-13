// File: virtualDestructor.cpp
// Author: lxw
// Date: 2015-08-13

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class A{
public:
    A() {
        cout<<"I am A"<<endl;
    }

    /*
    //case 4:
    ~A() {
        cout<<"Leave A"<<endl;
    }*/
    //case 5:
    virtual ~A() {
        cout<<"Leave A"<<endl;
    }
};
class B:public A{
public:
    B() {
        cout<<"I am B"<<endl;
    }
    ~B() {
        cout<<"Leave B"<<endl;
    }
};
int main() {
    //case 1.
    B b;

    //case 2.
    //const A & a = B();    //'const' is essential.

    //case 3.
    //A & a = b;

    //case 4.
    //A * aPtr = new B();
    //delete aPtr;

    //case 5.
    //A * aPtr = new B();
    //delete aPtr;

    //case 6.
    //A * aPtr = &b;

    //casd 7.
    A * aPtr = &b;
    delete aPtr;
}

/*
case 1:
I am A
I am B
Leave B
Leave A

case 2:
I am A
I am B
Leave B
Leave A

case 3:
I am A
I am B
Leave B
Leave A

------------------------------------------
case4:  //NOTE
I am A.
I am B.
Leave A.    //only 'Leave A. NO Leave B.', Because 'virtual' was not specified in the base class A.
------------------------------------------

case5:
I am A
I am B
Leave B
Leave A

case6:
I am A
I am B
Leave B
Leave A

case 7:
I am A
I am B
Leave B
Leave A
*** Error in `./a.out': free(): invalid pointer: 0xbfeed298 ***
Aborted (core dumped)
*/
