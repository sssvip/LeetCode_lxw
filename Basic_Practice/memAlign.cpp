// I really do not understand pragma.
// File: memAlign.cpp
// Author: lxw
// Date: 2015-08-24

#pragma pack(2)
#include <iostream>
using namespace std;

/*
//9
//#pragma pack(1)
//12
//#pragma pack(4)
//12 ??
//#pragma pack(8)
struct student{
	char sex;
	double b;
};*/

/*
//25
//#pragma pack(1)
//26
//#pragma pack(2)
//28
//#pragma pack(4)
//28
//#pragma pack(8)
struct student{
	int age;
	char sex;
	union{		
		char name[20];
		float salary;
	};
};*/


//28
//compare with the former demo.	
//#pragma pack(2)
//32//compare with the former demo.	
//#pragma pack(4)
//32//compare with the former demo.	
//#pragma pack(8)
struct student{
	int age;
	char sex;
	union{
		char name[21];
		float salary;
	};
};

int main(void){
	struct student s;
	cout << sizeof(s) << endl;
	cout << sizeof(double) << endl;	//8
	cout << sizeof(float) << endl;	//4
	return 0;
}
