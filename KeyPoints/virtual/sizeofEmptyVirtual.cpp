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
//No matter it is public or private, the results are identical.
//public:
private:
    virtual void f(){}
    virtual void g(){}
};
class Base3{
private:
    virtual void f(){}
    virtual void g(){}
};

class Derive:public Base{
};

class Derive1:public Base1{
};

class Derive2:public Base2{
};

class Derive3:public Base1, public Base2{
};

class Derive4:public Base2, public Base3{
};

int main(void){
    Base b;
    Base1 b1;
    Base2 b2;
    Base3 b3;
    cout << sizeof(Base) << endl;       //1
    cout << sizeof(Base1) << endl;      //1
    cout << sizeof(Base2) << endl;      //4
    cout << sizeof(Base3) << endl;      //4
    cout << sizeof(b) << endl;          //1
    cout << sizeof(b1) << endl;         //1
    cout << sizeof(b2) << endl;         //4
    cout << sizeof(b3) << endl;         //4
    cout << "-----------------------------------" << endl;
    Derive d;
    Derive1 d1; Derive2 d2;
    Derive3 d3;
    Derive4 d4;
    cout << sizeof(Derive) << endl;     //1
    cout << sizeof(Derive1) << endl;    //1
    cout << sizeof(Derive2) << endl;    //4
    cout << sizeof(Derive3) << endl;    //4
    cout << sizeof(Derive4) << endl;    //8
    cout << sizeof(d) << endl;          //1
    cout << sizeof(d1) << endl;         //1
    cout << sizeof(d2) << endl;         //4
    cout << sizeof(d3) << endl;         //4
    cout << sizeof(d4) << endl;         //8
    return 0;
}

/*
//Output:
lxw virtual$ ./a.out 
1
1
4
4
1
1
4
4
-----------------------------------
1
1
4
4
8
1
1
4
4
8
lxw virtual$ 
*/