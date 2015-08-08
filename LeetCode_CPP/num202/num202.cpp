// File: num202.cpp
// Author: lxw
// Date: 2015-08-08

/*
Num 202: Happy Number
Source: https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        int square, mod;
        us.insert(n);
        
        while(1){
            square = 0;
            while(n != 0){
                mod = n % 10;
                square += mod * mod;
                n /= 10;
            }
            //cout << "square: " << square << endl;
            if(square == 1)
                return true;
            if(us.find(square) != us.end())
                return false;
            us.insert(square);
            n = square;
        }
    }
};

int main(void){
	Solution sol;
	cout << sol.isHappy(117) << endl;
	return 0;
}