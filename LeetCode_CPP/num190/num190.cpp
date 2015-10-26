// File: num190.cpp
// Author: lxw
// Date: 2015-10-26

/*
Num num190: Reverse Bits
Source: https://leetcode.com/problems/reverse-bits/

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    //Method 1:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t high = 0x80000000;
        uint32_t low = 0x01;
        for(int i = 0; i < 16; ++i){
            result |= ((n & high) >> (31 - (i << 1)));            
            result |= ((n & low) << (31 - (i << 1)));            
            high >>= 1;
            low <<= 1;
        }
        return result;
    }
    //Method 2:
    uint32_t reverseBits1(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 31; ++i){            
            result |= (n & 0x01);
            result <<= 1;
            n >>= 1;
        }
        result |= (n & 0x01);
        return result;
    }
};

int main(void){ 
    Solution sol;
    cout << "Reverse result: " << sol.reverseBits(65536) << endl;
    cout << "Reverse result_1: " << sol.reverseBits1(65536) << endl;
    return 0;
}