#include <iostream>
using namespace std;

int main(void){
    /*
    //No Crash.
    char str[] = "hello";
    cout << str << endl;
    str[0] = 'H';
    cout << str << endl;
    */
    //Crash
    char * str = "hello";
    cout << str << endl;
    str[0] = 'H';
    cout << str << endl;
    return 0;
}
