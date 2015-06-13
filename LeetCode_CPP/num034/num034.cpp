// File: num034.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num num034: Search for a Range
Source: https://leetcode.com/problems/search-for-a-range/
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    int bsConvert(vector<int>& nums, int begin, int end, int target){
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
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> vec(2, -1);
        if(length == 0){
            return vec;
        }
        int index = bsConvert(nums, 0, length-1, target);
        if(index == -1){
            return vec;
        }
        int i = index;
        int j = index;
        while(nums[i] == target && i >= 0){
            --i;
        }
        ++i;
        while(nums[j] == target && j < length){
            ++j;
        }
        --j;
        vec[0] = i;
        vec[1] = j;
        return vec;
    }
};
