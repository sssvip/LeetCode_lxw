// File: bigLittleEndian.cpp
// Author: lxw
// Date: 2015-08-12

#include <iostream>
using namespace std;

class Singleton{
private:
	Singleton(){}
public:
	static Singleton & getHandle(){
		Singleton handle;
		return handle;
	}
};

int main(void){
	//Singleton s;
	Singleton::getHandle();
	return 0;
}