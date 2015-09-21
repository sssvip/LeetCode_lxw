// File: vTable.cpp
// Author: lxw
// Date: 2015-09-21
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;
class Base1 {
public:
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
	virtual void h() { cout << "Base1::h" << endl; }
};
class Base2 {
public:
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
};
//NO: class Derive:public Base1, Base2 {
class Derive : public Base1, public Base2 {
public:
	virtual void f() { cout << "Derive::f" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

int main(void){
	Derive d;
	Base1 * pt1 = &d;
	Base2 * pt2 = &d;
	d.f();		//Derive::f
	d.g1();		//Derive::g1
	d.h1();		//Derive::h1
	//当多个父类中有相同的方法,并且派生类未覆写该方法,则通过派生类实例去访问该方法时会出现编译错误
	//d.g();	//vTable.cpp:38:4: error: request for member ‘g’ is ambiguous.
	//d.h();	//vTable.cpp:39:4: error: request for member ‘h’ is ambiguous.

	pt1->f();	//Derive::f
	//即使是多态,通过基类的指针或者引用也只能调用派生类中重写父类的那些virtual方法,而不能调用派生类中新增加的方法
	//pt1->g1();	//vTable.cpp:42:7: error: ‘class Base1’ has no member named ‘g1’.
	//pt1->h1();	//vTable.cpp:43:7: error: ‘class Base1’ has no member named ‘h1’.
	pt1->g();	//Base1::g
	pt1->h();	//Base1::h

	pt2->f();	//Derive::f
	//pt2->g1();	//Derive::g1 //vTable.cpp:48:7: error: ‘class Base2’ has no member named ‘g1’.
	//pt2->h1();	//Derive::h1 //vTable.cpp:49:7: error: ‘class Base2’ has no member named ‘h1’.
	pt2->g();	//Base2::g
	pt2->h();	//Base2::h
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