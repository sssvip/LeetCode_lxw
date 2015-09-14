//File: demo4.cpp
//Author: lxw
//Time: 2015-09-12

#include <iostream>
using namespace std;

int main(void){
	int * arr = new int[3];
	cout << arr << endl;
	cout << *arr << endl;
	delete[] arr;	//YES
	//delete arr;	//YES
	return 0;
}

/*
Both "delete[] arr;" and "delete arr;" are OK

lxw@07:38:19:delete_delete[]$ ./a.out 
0x9818008
0
lxw@07:39:07:delete_delete[]$
*/
