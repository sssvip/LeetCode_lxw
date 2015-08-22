// File: num263.cpp
// Author: lxw
// Date: 2015-08-22

/*
Num num263: Ugly Number
Source: https://leetcode.com/problems/ugly-number/

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    bool isPrime(int num){
        //cout << "isPrime() num:" << num << endl;
        int maxFactor = sqrt(num);
        for(int i = 2; i <= maxFactor; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num < 7)
            return true;
        //num > 6, sqrt(num) > 2
        int maxFactor = sqrt(num);
        int quotient;
        for(int i = 1; i <= maxFactor; ++i){
            if(num % i == 0){
                if(i == 1 || i == 2 || i == 3 || i == 5){
                    quotient = num / i;
                    if(quotient == 2 || quotient == 3 || quotient == 5)
                        continue;
                    else{
                        if(isPrime(quotient))
                            return false;
                    }
                }
                else{
                    if(isPrime(i))
                        return false;
                    quotient = num / i;
                    if(quotient == 2 || quotient == 3 || quotient == 5)
                        continue;
                    if(isPrime(quotient)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(void){
    Solution sol;
    cout << sol.isUgly(15) << endl;
    return 0;
}
