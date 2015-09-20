// File: num283.cpp
// Author: lxw
// Date: 2015-09-20

/*
Num num283: Move Zeroes
Source: https://leetcode.com/problems/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if(length < 2){
            return;
        }
        int i = 0, j = 0;
        while(i < length && j < length){
            if(nums[j] == 0){
                ++j;
                continue;
            }
            else if(i != j){
                nums[i] = nums[j];
            }
            ++i;
            ++j;
        }
        while(i < length){
            nums[i++] = 0;
        }
    }
};