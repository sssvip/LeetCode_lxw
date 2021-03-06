#include <iostream>
using namespace std;

class A{
public:
    virtual void f(int a=3){ cout << "A: " << a << endl;}
};
class B:public A{
public:
    virtual void f(int a=5){ cout << "B: " << a << endl;}
};

int main(void){ 
    B b;
    b.f();  //B: 5
    A * a = &b;
    a->f(); //B: 3
    return 0;
}

//Reference: http://www.geeksforgeeks.org/output-of-c-program-set-12-2/
/*
We observe that f() of derived class is called and default value of base class f() is used.
The default value is used at compile time. When compiler sees that an argument is missing
in a function call, it substitutes the default value given. Therefore, in the above program,
value of x is substituted at compile time, and at run time derived class’s fun() is called.

In general, it is a best practice to avoid default values in virtual functions to avoid confusion.
*/