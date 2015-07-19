#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring> //strlen
#include <climits>
using namespace std;

string& trim(string &s){  
    if (s.empty()){
        return s;  
    }  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
} 

//注意：当字符串为空时，也会返回一个空字符串  
void split(string& s, string& delim, vector<string>* ret){  
    size_t last = 0;  
    size_t index = s.find_first_of(delim,last);  
    while (index != string::npos){  
        ret->push_back(s.substr(last, index-last));  
        last = index+1;  
        index = s.find_first_of(delim, last);  
    }  
    if (index-last > 0){  
        ret->push_back(s.substr(last, index-last));  
    }  
}

void TestGetLineWithStringStream(){
    //1.线程安全的,但是只能以字符作为分隔符
    stringstream ss("google|twitter|facebook|microsoft|apple|ibm|");
    string str;
    while(getline(ss,str,'|')){
        cout << str << endl;
    }
}


void TestStringFind(){
    //1.自己实现,线程安全,支持字符串作为分隔符.缺点可能就是代码量多.
    string str = "google||twitter||facebook||microsoft||apple||ibm||";
    const char* delim = "||";
    const int len = strlen(delim);
    size_t index = 0;
    size_t pos = str.find(delim,index);
    while(pos != string::npos){
        string ss = str.substr(index,pos-index);
        cout << ss << endl;
        index = pos+len;
        pos = str.find(delim,index);
    }
 
    //cout << "is last?" << " index:" << index << " str.length():" << str.length() << endl;
    if((index+1) < str.length()){
        string ss = str.substr(index,str.length() - index);
        cout << ss << endl;
    }
}

int main(void){
    cout << "string.find()" << endl;
    string str ="hello";
    if(str.find("t") != string::npos){
        cout << "found" << endl;
    }
    else{
        cout << str.find("t") << endl; 
        cout << string::npos << endl;
        cout << string::npos + 1 << endl;   //0
        cout << string::npos - 1 << endl; 
        cout << INT_MAX << endl;
        cout << LONG_MAX << endl;
    }
    cout << "--------------------------------" << endl;

    cout << "stringstream" << endl;
    int a = 10;
    char ch = 'a';
    stringstream ss;
    ss << a;
    ss << ch;
    cout << ss.str() << endl;   //10a
    cout << "--------------------------------" << endl;

    //Actually it is "string += char".
    //if string += int. int will be casted to char;
    cout << "string += char" << endl;
    a = 9;
    str += a + '0';	//no '-='
    cout << str << endl; //hello9    
    str += ch;
    cout << str << endl;    //hello9a
    cout << "--------------------------------" << endl;

	//NOTE:
	str = "";
    str += 'a';
    cout << str << endl;    //a
    str += 'b' + '0'; //NO: messy code.
    cout << str << endl;
    str = "a";
    str += "b" + 'c';   //NO: messy code.
    cout << str << endl;
    cout << "--------------------------------" << endl;

    cout << "string += char is OK. but \"string + char\" is NOT OK." << endl;
    str = "b";
    str += 'c';
    cout << str << endl;    //bc
    cout << "b" + 'c' << endl;	//NO: messy code.
    cout << "--------------------------------" << endl;
    
    //sort
    str = "hello";
    cout << "str: " << str << endl;
    sort(str.begin(), str.end());
    cout << "str: " << str << endl;
    string str1 = "olhel";
    cout << "str1: " << str1 << endl;
    sort(str1.begin(), str1.end());
    cout << "str1: " << str1 << endl;
    if(str1 == str){
        cout << "str1 == str" << endl;
    }
    cout << "--------------------------------" << endl;
    return 0;
}

/*
string.find()
4294967295
4294967295
0
4294967294
2147483647
2147483647
--------------------------------
stringstream
10a
--------------------------------
string += char
hello9
hello9a
--------------------------------
a
a
a
--------------------------------
string += char is OK. but "string + char" is NOT OK.
bc
e
--------------------------------
str: hello
str: ehllo
str1: olhel
str1: ehllo
str1 == str
--------------------------------
*/
