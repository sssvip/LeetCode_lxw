// File: toString.cpp
// Author: lxw
// Date: 2015-06-16

#include <iostream>
#include <sstream> //std::stringstream, std::stringbuf
using namespace std;

class ToString{
    public:
    //char * -> string
    string toString(const char * pointer){
        string result = pointer;
        return result;
    }

    //char -> string
    string toString(char ch){
        stringstream ss;
        ss << ch;
        string result = ss.str();
        return result;
    }
    //int -> string
    string toString(int number){
        stringstream ss;
        ss << number;
        string result = ss.str();
        return result;
    }
};
int main(void){
    ToString ts;
    /*char * helloStr;
    helloStr = "hello world!";????????????????????
    cout << ts.toString(helloStr) << endl;*/
    char ch = 'a';
    cout << ts.toString(ch) << endl;
    int number = 10;
    cout << ts.toString(number) << endl;
    return 0;
}
