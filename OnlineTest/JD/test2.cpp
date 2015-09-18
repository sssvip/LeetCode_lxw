// File: test2.cpp
// Author: lxw
// Date: 2015-09-18

#include <iostream>
using namespace std;

int getLen(int num){
	int length = 0;
	length += num;
	num >>= 1;
	while(num){		
		length += (num << 1);
		num >>= 1;
	}
	return length;
}

int main(void){
	int h1, h2, h3, h4;
	while(cin >> h1 >> h2 >> h3 >> h4){
		cout << getLen(h1) + getLen(h2) + getLen(h3) + getLen(h4) << endl;
	}
	return 0;
}