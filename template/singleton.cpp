// File: singleton.cpp
// Author: lxw
// Date: 2015-07-29

#include <iostream>
using namespace std;

class Singleton{
private:
    Singleton(){}
    static Singleton instance;
public:
    static Singleton getInstance(){
        if(instance == NULL)
            instance = Singleton();
        return instance;
    }
}

int main(void){
    Singleton::getInstance();
    return 0;
}
