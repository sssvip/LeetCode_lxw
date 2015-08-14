// File: singleton.cpp
// Author: lxw
// Date: 2015-07-29

#include <iostream>
using namespace std;

class Singleton{
private:
	Singleton(){}
	static Singleton * instance;
public:
	static Singleton * getInstance(){
		if(instance == NULL)
			instance = new Singleton();
		return instance;
	}
	~Singleton(){
		if(instance != NULL)
			delete instance;
	}
    void sayHello(){
        cout << "hello" << endl;
    }
};

Singleton * Singleton::instance = NULL;     //NOTE: essential.
int main(void){
	Singleton * s = Singleton::getInstance();
    s->sayHello();
    return 0;
}

