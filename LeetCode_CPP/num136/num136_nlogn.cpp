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
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < length-1; i += 2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[length-1];
    }
};
