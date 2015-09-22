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
	func fu = (func)*( ((int *)( (int *)( (*(int *)&d)+0 ) )) + 0);
	cout << fu << endl;
	fu();		//OK
	(*fu)();	//OK
	fu = (func)*( ((int *)( (int *)( (*(int *)&d)+0 ) )) + 1);
	cout << fu << endl;
	fu();		//no
	(*fu)(); 	//no
	return 0;
}


/*
//Output:

lxw virtual$ ./a.out 
1
Base::f
Base::f
1
Segmentation fault (core dumped)
lxw virtual$ 
*/