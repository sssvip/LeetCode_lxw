//File: demo1.cpp
//Author: lxw
//Time: 2015-09-12

#include <iostream>
using namespace std;

class T{
public:
	T(){
		cout << "constructor" << endl;
	}
	~T(){
		cout << "destructor" << endl;
	}
};
int main(void){
	T * arr = new T[3];
	cout << arr << endl;
	delete[] arr;	//YES
	//delete arr;	//NO
	return 0;
}

/*
delete[] arr;

lxw@07:27:48:KeyPoints$ ./a.out 
constructor
constructor
constructor
0x8aa000c
destructor
destructor
destructor
lxw@07:27:49:KeyPoints$ 
*/

/*
delete arr;

lxw@07:29:02:KeyPoints$ ./a.out 
constructor
constructor
constructor
0x85b100c
destructor
*** Error in `./a.out': munmap_chunk(): invalid pointer: 0x085b100c ***
Aborted (core dumped)
lxw@07:29:03:KeyPoints$ 
*/
