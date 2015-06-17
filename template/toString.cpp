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
#include <cstdlib>
using namespace std;

class intCharStar{
private:
	int number;
	char * pointer;
public:
	intCharStar(int number, char * ptr):number(number), pointer(ptr){}

	int charStarToInt(){
		/*
		char* -> int
		#include <cstdlib>
		int atoi(const char *nptr);
		long atol(const char *nptr);
		long long atoll(const char *nptr);
		long long atoq(const char *nptr);
		*/
		return atoi(this->pointer);
	}

	char * intToCharStar(){
		/*
		int -> char *
		itoa(i,num,10);
		i 需要转换成字符的数字
		num 转换后保存字符的变量
		10 转换数字的基数（进制）10就是说按照10进制转换数字。还可以是2，8，16等等你喜欢的进制类型
		原形：char *itoa(int value, char* string, int radix);
		*/

		/*
		int i=1234;
		char s[5];
		itoa(i,s,10);
		printf("%s",s);
		*/
		itoa(this->number, this->pointer, 10);
		return this->pointer;
	}
};

class ToString{
public:
    //char * -> string
    string toString(const char * pointer){
        string result = pointer;
        return result;
    }

    //char -> string
    string toString(char ch){
    	/*
        stringstream ss;
        ss << ch;
        string result = ss.str();*/
        string result = ch;
        return result;
    }
    //int -> string
    string toString(int number){
        /*
        stringstream ss;
        ss << number;
        string result = ss.str();
        */
        string result = number + '0';
        return result;
    }
};

int main(void){
    ToString ts;
    char * helloStr;
    helloStr = "hello world!";
    cout << ts.toString(helloStr) << endl;
    char ch = 'a';
    cout << ts.toString(ch) << endl;
    int number = 123;
    cout << ts.toString(number) << endl;
    return 0;
}
