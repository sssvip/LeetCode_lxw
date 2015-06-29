// File: num050.cpp
// Author: lxw
// Date: 2015-06-29

/*
Num num050: Pow(x, n)
Source: https://leetcode.com/problems/powx-n/

Implement pow(x, n).
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0){
            return 1.0 / myPowRecursive(x, -n);
        }
        else{
            return myPowRecursive(x, n);
        }
    }
    //4ms
    double myPowRecursive(double x, int n){
        double result = 1.0; //overflow?
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1.0;
        }
        double half = myPow(x, n>>1);
        result = half * half;
        if(n & 0x01){
            result *= x;
        }
        return result;
    }
    //20ms
    double myPowIterative_slow(double x, int n){
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        if(abs(x-1.0) < 0.000000001)
            return 1.0;
        if(abs(x+1.0) < 0.000000001){
            return n & 0x01 ? -1.0 : 1.0;
        }
        int count = 0;
        double result = 1;
        /*//The following code block is NOT OK, do you know why?
        while(count < n && abs(result) > 0.000000001){
            result = result * result;
            count *= 2; //count << 1;
        }
        */
        while(count < n && abs(result) > 0.000000001){
            result *= x;
            ++count;
        }
        return result;
    }
    //4ms
    double myPowIterative(double x, int n){
        double result = 1.0;
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1.0;
        }
        while(n > 0){
            if(n % 2){
                result *= x;
            }
            n >>= 1;
            x *= x;
        }
        return result;
    }
};