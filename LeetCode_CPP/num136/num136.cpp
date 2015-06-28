// File: num136.cpp
// Author: lxw
// Date: 2015-06-28

/*
Num num136: Single Number
Source: https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            result ^= nums[i];
        }
        return result;
    }
};