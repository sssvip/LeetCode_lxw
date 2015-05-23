#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
        bool sign = true;
        long long absNum = 0;
        if(x < 0){
            sign = false;
            absNum = (long long)-x;
        }
        else{
            absNum = (long long)x;
        }

		// "unsinged int" is NOT OK(Because reverse of 2^31-1 is LARGER than 2^32-1).  "32bits long" is NOT OK, either.
        long long num = 0;
        while(absNum > 0){
            num = num * 10 + absNum % 10;
            absNum /= 10;
        }

        if(!sign){
            num = -num;
        }
        int int_max = 0x7fffffff;
        int int_min = 0x80000000;
        return num > (long long)int_max || num < (long long)int_min ? 0 : num;
    }
};

int main(int argc, char** argv){
    Solution s;
    int a = 0x7fffffff;
    int b = 0x80000000;
    int c = 123456;
    cout << "1534236469, reverse: " << s.reverse(1534236469) << endl;
    cout << a << ", reverse: " << s.reverse(a) << endl;
    cout << b << ", reverse: " << s.reverse(b) << endl;
    cout << c << ", reverse: " << s.reverse(c) << endl;
    return 0;
}
