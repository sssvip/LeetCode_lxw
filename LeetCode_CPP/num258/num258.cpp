// File: num258.cpp
// Author: lxw
// Date: 2015-08-22

/*
Num num258: Add Digits
Source: https://leetcode.com/problems/add-digits/

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int addDigits(int num) {
        /*
        //Method 1:
        if(num < 0)
            return -1;
        if(num < 10)
            return num;
        int sum = 0;
        while(1){
            while(num != 0){
                sum += num % 10;
                num /= 10;
            }
            if(sum < 10)
                return sum;
            num = sum;
            sum = 0;
        }
        */
        //Method 2:
        if(num < 0)
            return -1;
        if(num == 0)
            return 0;
        return num-(num-1)/9*9;
    }
};