#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string str ="hello";
    cout << str.find("t") << endl; 

    int a = 10;
    char ch = 'a';
    stringstream ss;
    ss << a;
    ss << ch;
    cout << ss.str() << endl;

    str += a + '0';
    cout << str << endl;
    //str -= a + '10';
    //cout << str << endl;
    str += ch;
    cout << str << endl;
    //str -= ch;
    //cout << str << endl;
    return 0;
}
