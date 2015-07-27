#include <iostream>
#include <climits>
using namespace std;

int main(void){
    //@1:~num == -(num+1)
    
    int num = 100;
    cout << "num: " << num << ", -num: " << -num << ", -(num+1): " << -(num+1) << ", ~num: " << ~num << endl;
    //num: 100, -num: -100, -(num+1): -101, ~num: -101
    
    //NOTE: -INT_MIN
    num = INT_MIN;
    cout << "num: " << num << ", -num: " << -num << ", -(num+1): " << -(num+1) << ", ~num: " << ~num << endl;
    //num: -2147483648, -num: -2147483648, -(num+1): 2147483647, ~num: 2147483647
    
    num = INT_MAX;
    cout << "num: " << num << ", -num: " << -num << ", -(num+1): " << -(num+1) << ", ~num: " << ~num << endl;
    //num: 2147483647, -num: -2147483647, -(num+1): -2147483648, ~num: -2147483648
    
    cout << (-INT_MIN == INT_MIN) << endl;

    //@2:
    return 0;
}
