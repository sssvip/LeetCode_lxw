// File: num231.cpp
// Author: lxw
// Date: 2015-07-25

/*
Num num231: Power of Two 
Source: https://leetcode.com/problems/power-of-two/

Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        int length = sizeof(int) * 8 - 1;
        /* 有必要吗？
        int * array = new int[length];
        for(int i = 0; i < length; ++i){
            array[i] = 1 << i;
        }*/
        for(int i = 0; i < length; ++i){
            if(n == (1 << i)){
                return true;
            }
        }
        return false;
    }
};