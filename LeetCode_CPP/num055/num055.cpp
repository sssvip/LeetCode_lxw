// File: num055.cpp
// Author: lxw
// Date: 2015-06-28

/*
Num num055: Jump Game
Source: https://leetcode.com/problems/jump-game/
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if(length < 2)
            return true;
        int i = 0;
        while(i < length){
            int step = nums[i];
            if(i + step >= length-1){
                return true;
            }
            int index = -1;
            int max = -1;
            int j = 0;
            while(j < step){
                int tempIndex = i + j + 1;
                if(nums[tempIndex] + tempIndex > max + index ){
                    max = nums[tempIndex];
                    index = tempIndex;
                }
                ++j;
            }
            i = index;
            if(nums[i] == 0){
                return false;
            }
        }
    }
};
