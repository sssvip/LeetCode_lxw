#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string str ="hello";
    if(str.find("t") != string::npos){
        cout << "found" << endl;
    }
    else{
        cout << str.find("t") << endl; 
        cout << string::npos << endl; 
    }

    int a = 10;
    char ch = 'a';
    stringstream ss;
    ss << a;
    ss << ch;
    cout << ss.str() << endl;   //10a

    a = 9;
    str += a + '0';	//no '-='
    cout << str << endl; //hello9    
    str += ch;
    cout << str << endl;    //hello9a

	//NOTE:
	str = "";
    str += 'a';
    cout << str << endl;
    str += 'b' + 'c'; //NO: str is still "a".
    cout << str << endl;
    str += "b" + 'c';   //NO: messy code.
    cout << str << endl;
    cout << "b" + 'c' << endl;	//NO: messy code.
    cout << "end" << endl;
    return 0;
}

/*
4294967295
4294967295
10a
hello9
hello9a
a
a
a��
�
end
*/