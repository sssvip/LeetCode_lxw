// File: singleton.cpp
// Author: lxw
// Date: 2015-07-29

#include <iostream>
#include <mutex>
using namespace std;

class Lock{
private:
	mutex m;
public:
	Lock(mutex mt):m(mt){
		this->m.Lock();
	}
	~Lock(){
		this->m.Unlock();
	}
};

class Singleton{
private:
	Singleton(){}
	static Singleton * instance;
	static mutex m;
public:
	static Singleton * getInstance(){
		if(instance == NULL){
			Lock lock(m);
			if(instance == NULL)
				instance = new Singleton();
		}
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

