// File: num066.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num066: Plus One
Source: https://leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int length  = digits.size();
        int digit = 0;
        int carry = 1;
        for(int i = length-1; i >= 0; --i){
            digit = digits[i] + carry;
            if(digit > 9){
                digit -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            digits[i] = digit;
        }
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};