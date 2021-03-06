// File: singleton.cpp
// Author: lxw
// Date: 2015-07-29

#include <iostream>
using namespace std;

class Singleton{
private:
	Singleton(){
        cout << "constructor" << endl;
    }
	static Singleton * instance;
public:
	static Singleton * getInstance(){
        cout << "getInstance" << endl;
		if(instance == NULL)
			instance = new Singleton();
		return instance;
	}
	~Singleton(){
        cout << "goodbye" << endl;
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

