#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

int strlen1(const char * src){
	assert(src != NULL);
	int length = 0;
	while(*(src++) != '\0'){
		++length;
	}
	return length;
}

int main(void){
	char str1[] = "hello";
	char * str2 = new char[strlen(str1)+1];
	cout << "str2: " << str2 << endl;
	cout << strlen1(strcpy(str2, str1)) << endl;
	cout << "str2: " << str2 << endl;
	cout << strlen1("") << endl;
	delete[] str2;
	return 0;
}
