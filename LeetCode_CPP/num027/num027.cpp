// File: num027.cpp
// Author: lxw
// Date: 2015-06-30

/*
Num num027: Remove Element
Source: https://leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int begin = 0, end = length -1;
        while(begin <= end){
            if(nums[begin] != val){
                ++begin;
            }
            else{
                nums[begin] = nums[end];
                --end;
            }
        }
        return end + 1;
    }
};