// File: toString.cpp
// Author: lxw
// Date: 2015-06-16

/*
char* -> string 
string s(char *); 
你的只能初始化，在不是初始化的地方最好还是用assign().
string str;
str.assign(const char *s, size_t n);

string 转 char * 
string aa("aaa");
char *c = aa.c_str();
*/

#include <iostream>
#include <sstream> //std::stringstream, std::stringbuf
#include <string>
#include <cstdlib>
#include <algorithm> //std::reverse
using namespace std;

class intCharStar{
private:
	int number;
	char * pointer;
public:
	intCharStar(int number, char * ptr):number(number), pointer(ptr){}

	//char* -> int
	int charStarToInt(){
		/*		
		#include <cstdlib>
		int atoi(const char *nptr);
		long atol(const char *nptr);
		long long atoll(const char *nptr);
		long long atoq(const char *nptr);
		*/
		return atoi(this->pointer);
	}

	//int -> char *
	char * intToCharStar(){
		/*
		itoa(i,num,10);
		i 需要转换成字符的数字
		num 转换后保存字符的变量
		10 转换数字的基数（进制）10就是说按照10进制转换数字。还可以是2，8，16等等你喜欢的进制类型
		
		Demo:
		int i=1234;
		char s[5];
		itoa(i,s,10);
		printf("%s",s);
		*/
		return itoa(this->number, this->pointer, 10);
	}

	//int -> string
	// std::string style "itoa":
	std::string itoa(int value, int base) {
		std::string buf;

		// check that the base if valid
		if (base < 2 || base > 16) return buf;

		enum { kMaxDigits = 35 };
		buf.reserve( kMaxDigits ); // Pre-allocate enough space.

		int quotient = value;

		// Translating number to string with base:
		do {
			buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
			quotient /= base;
		} while ( quotient );

		// Append the negative sign
		if ( value < 0)
			buf += '-';

		std::reverse(buf.begin(), buf.end());
		return buf;
	}

	//int -> char *
	//char* style "itoa":
	char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
};

int main(void){
    ToString ts;
    char * helloStr = "hello world!";
    cout << ts.toString(helloStr) << endl;

    char ch = 'a';
    cout << ts.toString(ch) << endl;

    int number = 123;
    cout << ts.toString(number) << endl;


    string str;
	char * ptr = "hello";
    //char * -> string
    str = ptr;  // ????
    cout << "str: " << str << endl;

    //char -> string
    char ch = 'a';
    stringstream ss;
    ss << ch;
    str = ss.str();
    cout << "str: " << str << endl;

    //int -> string
    int number = 123;
    stringstream ss;
    ss << number;
    str = ss.str();
    cout << "str: " << str << endl;

    //string -> const char *    
    //只能转换成const char*，如果去掉const编译不能通过
    const char * constStr = str.c_str();
    const char * constStr1 = str.data();
    cout << "constStr: " << cStr << endl;
    cout << "constStr1: " << cStr1 << endl;

    //string -> char *
    int length = str.length();
    char * chStr = new char[length + 1];
    str.copy(chStr, length, 0);
    delete[] chStr;
    cout << "str: " << str << endl;
    return 0;
}
