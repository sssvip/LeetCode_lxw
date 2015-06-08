// Time Limit Exceeded.
// File: num029_TLE.cpp
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
    int divide(int dividend, int divisor) { //(被除数, 除数)
        int maxInt = 0x7fffffff;
        if(divisor == 0 || (divisor == -1 && dividend == -maxInt - 1)){
            return maxInt;
        }
        if(dividend == 0){
            return 0;
        }
        int sign1 = 1;
        int sign2 = 1;
        //long long is essential: special case -> -MAX_INT
        long long dividendAbs = dividend;
        long long divisorAbs = divisor;
        if(dividend < 0){
            sign1 = -1;
            dividendAbs = -dividend;
        }
        if(divisor < 0){
            sign2 = -1;
            divisorAbs = -divisor;
        }
        long long result = 0;
        if((sign1 == 1 && sign2 == 1) || (sign1 == -1 && sign2 == -1)){ //same sign
            if(divisorAbs == 1){
                return dividendAbs;
            }
            while(1){
                dividendAbs -= divisorAbs;
                //下面的两个if和++result这条语句的顺序 注意
                if(dividendAbs < 0){
                    return result;
                }
                ++result;
                if(dividendAbs == 0){
                    return result;
                }
            }
        }
        else{   //different sign
            if(divisorAbs == 1){
                return -dividendAbs;
            }
            while(1){
                dividendAbs -= divisorAbs;
                ++result;
                if(dividendAbs <= 0){
                    return -result;
                }
            }
        }
    }
};

