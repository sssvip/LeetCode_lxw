// File: num268.cpp
// Author: lxw
// Date: 2015-08-26

/*
Num num268: Missing Number
Source: https://leetcode.com/problems/missing-number/

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int start = 0;
        int end = length - 1;
        int mid;
        sort(nums.begin(), nums.end());
        if(length < 1 || nums[0] != 0)
            return 0;
        int missing;
        while(start <= end){
            mid = (start + end) >> 1;
            if(nums[mid] != mid){
                end = mid - 1;
                missing = mid;
            }
            else{
                start = mid + 1;
                missing = start;
            }
        }
        return missing;
    }
};