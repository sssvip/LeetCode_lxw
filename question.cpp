#include <iostream>
using namespace std;

class A{
public:
	A(int i){
		cout << this << endl;
		y = i;
	}
	void dispa(){
		cout << this << endl;
		cout << this->y << endl;
	}
private:
	int y;
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

	B b(2);
	b.dispb();

    return 0;
}
