// File: test.cpp
// Author: lxw
// Date: 2015-08-27

#include <iostream>
using namespace std;

int main(void){
    int i = 5;
    int a = (++i)--;
    cout << i << ", " << a << endl;
    return 0;
}
