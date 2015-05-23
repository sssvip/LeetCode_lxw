// File: num009_generic.cpp
// Author: lxw
// Date: 2015-05-23

/*
Num 009: Palindrome Number
Source: https://leetcode.com/problems/palindrome-number/
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
*/

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int x1 = x;
        int length = 1;
        while(x > 9){
            x /= 10;
            length *= 10;
        }
        x = x1;
        int leftMost = 0;
        int rightMost = 0;
        while(x != 0){
            leftMost = x / length;
            rightMost = x % 10;
            if(leftMost != rightMost)
                return false;
            x = (x % length) / 10;
            length /= 100;
        }
        return true;
    }
};

int main(int argc, const char * argv[])
{
    Solution sol;
    int array[] = {12321, 12345, 252, 1, -2342432, -2, -2147447412};
    int length = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i< length; ++i){
        cout << array[i] << ", " << sol.isPalindrome(array[i]) << endl;
    }
    return 0;
}

