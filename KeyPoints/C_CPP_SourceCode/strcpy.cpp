#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

//返回char *使函数能够支持链式表达式
char * strcpy(char * dest, const char * src){
	assert(src != NULL && dest != NULL);	//OK
	/*	//OK
	if(src == NULL || dest == NULL)
		throw "Invalid arguments";
	*/
	char * result = dest;
	while((*(dest++) = *(src++)) != '\0'){
		;	//empty
	}
	return result;
}

int main(void){
	char str1[] = "hello";
	char * str2 = new char[strlen(str1)+1];
	cout << "str2: " << str2 << endl;
	cout << strlen(strcpy(str2, str1)) << endl;
	cout << "str2: " << str2 << endl;
	delete str2;
	return 0;
}