// File: test2.cpp
// Author: lxw
// Date: 2015-09-28

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int is_include(char * a, char * b){
    if(a == NULL)
    	return 0;
    if(b == NULL)
    	return 1;
	while(*a != '\0'){
		if(*a == *b && strncmp(a, b, strlen(b)) == 0){
			return 1;
		}
		++a;
	}
	return 0;
}

int main(void){
	string str1;
	string str2;	
	cin >> str1 >> str2;
	cout << is_include((char *)str1.c_str(), (char *)str2.c_str()) << endl;	
	return 0;
}