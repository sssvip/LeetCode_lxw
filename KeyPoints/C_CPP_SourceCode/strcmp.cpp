#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

//GOOD
int strcmp0(const char * str1, const char * str2){
	assert(str1 != NULL && str2 != NULL);
	while(*str1 == *str2){
		if(*str1 == '\0')
			return 0;
		else{
			++str1;
			++str2;
		}
	}
	return *str1 > *str2 ? 1 : -1;
}

//BAD
int strcmp1(const char * dest, const char * src){
	assert(dest != NULL && src != NULL);
	while(*dest != '\0' && *src != '\0'){
		if(*dest == *src){
			++dest;
			++src;
		}
		else if(*dest < *src){
			return -1;
		}
		else{
			return 1;
		}
	}
	if(*dest == '\0' && *src == '\0'){
		return 0;
	}
	else if(*dest == '\0'){
		return -1;
	}
	else{
		return 1;
	}
}

int main(void){
	char str1[] = "hello";
	char str2[] = "hello1";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << strcmp(str1, str2) << endl;
	cout << strcmp0(str1, str2) << endl;
	cout << strcmp1(str1, str2) << endl;
    //The values of str3 and str4 are not defined.
    char * str3, * str4;    //NOT: char * str3, str4;
    cout << str1 << ": " << str2 << ": " << str3 << ": " << str4 << endl;
	cout << strcmp(str3, str4) << endl;
	cout << strcmp0(str3, str4) << endl;
	cout << strcmp1(str3, str4) << endl;
	return 0;
}
