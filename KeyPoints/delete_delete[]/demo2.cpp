//File: demo2.cpp
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
	T * arr = new T();
	cout << arr << endl;
	//delete[] arr;	//NO
	delete arr;	//YES
	return 0;
}

/*
delete[] arr;

lxw@07:38:19:delete_delete[]$ ./a.out 
constructor
0x9c74008
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
destructor
*** Error in `./a.out': free(): invalid pointer: 0x09c74004 ***
Aborted (core dumped)
lxw@07:38:21:delete_delete[]$ 

*/

/*
delete arr;

lxw@07:39:07:delete_delete[]$ ./a.out 
constructor
0x881a008
destructor
lxw@07:39:07:delete_delete[]$
*/
