#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

//GOOD
char * strstr0(const char * str, const char * target){
	assert(str != NULL && target != NULL);
    int len = strlen(target);
    for(; *str != '\0'; ++str){
        if(*str == *target && strncmp(str, target, len) == 0){
            return (char *)str; //cast here is essential.
        }
    }
    return NULL;
}

//NOT GOOD.
char * strstr1(const char * str, const char * target){
	assert(str != NULL && target != NULL);
	const char * pt;
	char * result;
	while(str != '\0'){
		pt = target;
		while(*str != *pt){
			++str;
		}
		result = (char *)str;
		while(*pt != '\0' && *(str++) == *(pt++)){
			;
		}
		if(*pt == '\0'){
			return result;
		}
	}
	return NULL;
}

int main(void){
	char str1[] = "hello";
	char str2[] = "e";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << strstr(str1, str2) << endl;
	cout << strstr0(str1, str2) << endl;
	cout << strstr1(str1, str2) << endl;
	return 0;
}
