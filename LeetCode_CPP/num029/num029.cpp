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
/*
//OK
    int divide(int dividend, int divisor) {
		long long a = dividend >= 0 ? dividend : -(long long)dividend;
		long long b = divisor >= 0 ? divisor : -(long long)divisor;
		long long result = 0, c = 0;
		bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

		while (a >= b) {
			c = b;
			for (int i = 0; a >= c; ++i, c <<= 1) {
				a -= c;
				result += (1<<i);
			}
		}
		if (sign) { //different sign
			return max((long long)INT_MIN, -result);
		} else { //same sign
			return min((long long)INT_MAX, result);
		}
    }
*/
//WRONG
    int divide(int dividend, int divisor) {
        long long dividendAbs = dividend >= 0 ? dividend : -(long long)dividend;  //注意不是(long long)-divident;
        long long divisorAbs = divisor >= 0 ? divisor : -(long long)divisor;
        bool sign = ((dividendAbs >= 0 && divisor <= 0) || (dividendAbs <= 0 && divisor >= 0));
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
