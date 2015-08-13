// File: singleton.cpp
// Author: lxw
// Date: 2015-07-29

#include <iostream>
using namespace std;

class Singleton{
private:
	Singleton(){}
	static Singleton * instance = NULL;
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

//Singleton * Singleton::instance = NULL;     //NOTE: essential.
int main(void){
	Singleton * s = Singleton::getInstance();
    s->sayHello();
    return 0;
}


/*
class Singleton {
public:
    static Singleton* getInstance();
    //析构的时候释放资源~
    ~Singleton() {
        if(_instance != NULL)
            delete _instance;
    }
protected:
    Singleton();
private:
    static Singleton* _instance;
};
 
Singleton *Singleton::_instance = NULL;
Singleton* Singleton::getInstance() {
    if( _instance == NULL) {
        _instance = new Singleton();
    }
    return _instance;
}*/
