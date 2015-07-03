#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str = "";
    str += 'a';
    cout << str << endl;
    str += 'b' + 'c';
    cout << str << endl;
    return 0;
}
