#include <iostream>
using namespace std;

class A{
public:
	A(int i){
		cout << this << endl;
		x = i;
	}
	void dispa(){
		cout << this << endl;
		cout << this->x << endl;
	}
private:
	int x;
};

class B : public A{
public:
	B(int i) : A(i+10){
		x = i;
	}
	void dispb(){
		dispa();
		cout << this << endl;
		cout << this->x << endl;
	}
private:
	int x;
};

int main(void){
    A a(1);
    a.dispa();
    cout << endl;

	B b(2);
	b.dispb();

    return 0;
}

/*
lxw LeetCode_lxw$ ./a.out 
0xbfc1abb4
0xbfc1abb4
1

0xbfc1abb8
0xbfc1abb8
12
0xbfc1abb8
2
*/
