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
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
} 

//NOTE:
//string::find_first_of("aeiou", pos);	//只要aeiou有任何一个字符匹配就返回该位置.
//string::find("", pos);	//必须aeiou这个字符串整体匹配才返回

//线程安全, 只能以字符作为分隔符
void getlineSplit(){    
    stringstream ss("google|twitter|facebook|microsoft|apple|ibm|");
    string str;
    //istream& getline (istream& is, string& str, char delim);
    while(getline(ss, str, '|')){
        cout << "\"" << str << "\"" << endl;
    }
}

//线程安全, 支持字符串作为分隔符.
void ownSplit(){    
    string str = "google||twitter||facebook||microsoft||apple||ibm||";
    const string delim = "||";
    const int len = delim.length();
    size_t index = 0;
    size_t pos = str.find(delim, index);
    while(pos != string::npos){
    	//string substr (size_t pos = 0, size_t len = npos) const;
        string ss = str.substr(index, pos-index);
        cout << "\"" << ss << "\"" << endl;
        index = pos + len;
        pos = str.find(delim,index);
    }
    
    if(index < str.length() - 1){
        string ss = str.substr(index, str.length() - index);
        cout << "\"" << ss << "\"" << endl;
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
        cout << string::npos << endl;	//string::npos maximum of size_t;
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
    str += '1' + '2'; //'1': 49   '2': 50   49+50==99('c');
    cout << str << endl;	//ac
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

    //trim
    cout << "trim(string& str)" << endl;
    str = " lxw \n  ";
    cout << "\"" << trim(str) << "\"" << endl;	//only space, without "\n"
    cout << "--------------------------------" << endl;

    //split
    getlineSplit();
    ownSplit();	
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
ac
a
--------------------------------
string += char is OK. but "string + char" is NOT OK.
bc

--------------------------------
str: hello
str: ehllo
str1: olhel
str1: ehllo
str1 == str
--------------------------------
*/
