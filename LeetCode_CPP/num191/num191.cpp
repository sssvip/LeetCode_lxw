// File: num191.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num191: Number of 1 Bits
Source: https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        /*
        for(int i = 0; i < 32; ++i){
            if((n >> i) & 0x01)
                ++count;
        }*/
        //Each time of "n &= n - 1", we delete one '1' from n.
        while(n != 0){
            n = n & (n-1);
            ++count;
        }
        return count;
    }
};