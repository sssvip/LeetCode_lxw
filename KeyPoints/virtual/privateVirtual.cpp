// File: privateVirutal.cpp
// Author: lxw
// Date: 2015-09-21
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;
class Base {
private:
	virtual void f() { cout << "Base::f" << endl; }
};
class Derive : public Base {	
};

int main(void){
	typedef void (*func)();	
	Derive d;
	//
	func fu = (func)*((int *)*(int *)&d);
	(*fu)();
	return 0;
}


/*
//Output:

lxw virtual$ ./a.out 
Derive::f
Derive::g1
Derive::h1
Derive::f
Base1::g
Base1::h
Derive::f
Base2::g
Base2::h
lxw virtual$ 
*/