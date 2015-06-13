// File: num035.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num 035: Search Insert Position 
Source: https://leetcode.com/problems/search-insert-position/

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int binSearch(vector<int>& nums, int begin, int end, int target){
        int middle = 0;
        while(begin <= end){
            middle = (begin + end) / 2;
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] > target){
                end = middle - 1;
            }
            else{
                begin = middle + 1;
            }
        }
        if(nums[middle] > target){
            ++end; //Important
            return end;
        }
        else{
            return begin;
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        if(length < 1){
            return 0;
        }
        return binSearch(nums, 0, length-1, target);
    }
};
