// File: bigLittleEndian.cpp
// Author: lxw
// Date: 2015-08-12

#include <iostream>
using namespace std;

void bigLittleEndian(){
	int num = 0x01;
	int lowByte = *(char *)(&num);
	if(lowByte == 0x01){
		cout << "Little Endian" << endl;
	}
	else{
		cout << "Big Endian" << endl;
	}
}

void bigLittleEndian1(){
	union intChar{
		int num;
		char ch;
	}u;
	u.num = 1;
	if(u.ch == 1){
		cout << "Little Endian" << endl;
	}
	else{
		cout << "Big Endian" << endl;
	}

}

int main(void){
	bigLittleEndian();
	bigLittleEndian1();
    return 0;
}
