// File: sizeofEmptyVirtual.cpp
// Author: lxw
// Date: 2015-09-14

#include <iostream>
using namespace std;

class Base{
};

class Base1{
public:
    void f(){}
    void g(){}
};

class Base2{
    public:
    virtual void f(){}
    virtual void g(){}
};

class Derive:public Base{
};

class Derive1:public Base1{
};

class Derive2:public Base2{
};

int main(void){
    Base b;
    Base1 b1;
    Base2 b2;
    cout << sizeof(Base) << endl;       //1
    cout << sizeof(Base1) << endl;      //1
    cout << sizeof(Base2) << endl;      //4
    cout << sizeof(b) << endl;          //1
    cout << sizeof(b1) << endl;         //1
    cout << sizeof(b2) << endl;         //4
    cout << "-----------------------------------" << endl;
    Derive d;
    Derive1 d1;
    Derive2 d2;
    cout << sizeof(Derive) << endl;     //1
    cout << sizeof(Derive1) << endl;    //1
    cout << sizeof(Derive2) << endl;    //4
    cout << sizeof(d) << endl;          //1
    cout << sizeof(d1) << endl;         //1
    cout << sizeof(d2) << endl;         //4
    return 0;
}
