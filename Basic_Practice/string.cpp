#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string str ="hello";
    cout << str.find("t") << endl; 
    int a = 10;
    char c = 'a';
    stringstream ss;
    ss << a;
    ss << c;
    cout << ss.str() << endl;
    return 0;
}
