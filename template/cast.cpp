// File: toString.cpp
// Author: lxw
// Date: 2015-06-16

#include <iostream>
#include <sstream> //std::stringstream, std::stringbuf
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm> //std::reverse
using namespace std;

class IntCharStar{
private:
	int number;
	char * pointer;
public:
	IntCharStar(int number, char * ptr):number(number){
        int length = strlen(ptr);
        this->pointer = new char[length+1];
        strcpy(pointer, ptr);
    }
    ~IntCharStar(){
        delete[] this->pointer;
    }

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
		if (tmp_value < 0)
            *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
};

char * reverse(char * arr){
    int length = strlen(arr);
    int middle = length / 2;
    char ch;
    for(int i = 0; i < middle; ++i){
        ch = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = ch;
    }
    return arr;
}

//int -> string
//Implement casting int to string on myself.
string int2String(int number){
    char t[24];
    int i = 0;	 
    while (number) {
        t[i++] = (number % 10) + '0';
        number /= 10;
    }
    t[i] = 0;	 
    return string(reverse(t));
}

int main(void){	
    //char * ptr = "123"; //warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]

    //char * -> int
	char ptr[] = "123";
	IntCharStar ics(10, ptr);
    int number = ics.charStarToInt();
	cout << number << endl; //123
	cout << ics.intToCharStar() << endl << endl; //10

    //char * -> string
    //1
    string str;
    char ptr1[] = "world";
    str = ptr1;
    cout << "str: " << str << endl; //world
    //2
    //string s(char *); 只能初始化，在不是初始化的地方最好还是用assign().
    string str1(ptr1);
    cout << "str1: " << str1 << endl; //world
    //3
    str1.assign(ptr1, strlen(ptr1));
    cout << "str1: " << str1 << endl << endl; //world

    //char -> string
    char ch = 'a';
    stringstream ss;
    ss << ch;
    str = ss.str();
    cout << "str: " << str << endl << endl; //a
    str += 'a'; //operator += can add string & char
    cout << "str: " << str << endl << endl; //a

    //int -> string
    stringstream ss1;
    number = 123;
    ss1 << number;
    str = ss1.str();
    cout << "str: " << str << endl << endl;//123

    //string -> const char *    
    //只能转换成const char*，如果去掉const编译不能通过  //error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
    const char * constStr = str.c_str();
    const char * constStr1 = str.data();
    cout << "constStr: " << constStr << endl;   //123
    cout << "constStr1: " << constStr1 << endl; //123

    //string -> char *
    int length = str.length();
    char * chStr = new char[length + 1];
    str.copy(chStr, length, 0);
    cout << "chStr: " << chStr << endl << endl; //123
    delete[] chStr;
    return 0;
}
