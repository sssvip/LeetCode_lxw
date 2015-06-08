// File: num029.cpp
// Author: lxw
// Date: 2015-06-08

/*
Num num029: Divide Two Integers
Source: https://leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dividendAbs = dividend >= 0 ? dividend : -(long long)dividend;  //注意不是(long long)-dividend;
        long long divisorAbs = divisor >= 0 ? divisor : -(long long)divisor;
        bool sign = ((dividend >= 0 && divisor <= 0) || (dividend <= 0 && divisor >= 0));
        long long temp = 0;
        long long result = 0;
        while(dividendAbs >= divisorAbs){
            temp = divisorAbs;
            for(int i = 0; dividendAbs >= temp;){
                dividendAbs -= temp;
                result += (1<<i);
                ++i;
                temp <<= 1;
            }
        }
        if(sign){
            return max((long long)INT_MIN, -result);
        }
        else{
            return min((long long)INT_MAX, result);
        }
    }
};
