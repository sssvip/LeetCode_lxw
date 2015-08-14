#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

/*
-------------------------------------------------------------
memcpy.cpp:13:9: error: ISO C++ forbids incrementing a pointer of type ‘void*’ [-fpermissive]
   *(dest++) = *(src++);
         ^
-------------------------------------------------------------
//NO
void * memcpy(void * dest, const void * src, size_t count){
	assert(src != NULL && dest != NULL);	//OK
	/*	//OK
	if(src == NULL || dest == NULL)
		throw "Invalid arguments";
	* /
	void * result = dest;
	for(size_t i = 0; i < count; ++i){
		*(dest++) = *(src++);
	}
	return dest;
}*/

void * memcpy(void * dest, const void * src, size_t count){
	assert(src != NULL && dest != NULL);
	const char * srcStr = (const char *)src;	//cast is essential.
	char * destStr = (char *)dest;
	for(size_t i = 0; i < count; ++i){
		*(destStr++) = *(srcStr++);
	}
	return dest;
}

int main(void){
	char str1[] = "hello";
	char * str2 = new char[strlen(str1)+1];
	cout << "str2: " << str2 << endl;
	cout << strlen((char *)memcpy(str2, str1, 5)) << endl;
	cout << "str2: " << str2 << endl;
	cout << strlen((char *)memcpy(str2, str1, 6)) << endl;
	cout << "str2: " << str2 << endl;
	delete str2;
	return 0;
}

/*
str2: 
3
str2: hel
5	//not 6
str2: hello
*/