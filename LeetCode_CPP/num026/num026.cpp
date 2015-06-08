// File: num026.cpp
// Author: lxw
// Date: 2015-06-08

/*
Num num026: Remove Duplicates from Sorted Array 
Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    //Really Slow.
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0){
            return 0;
        }
        //erase()效率不高
        for(int i = 0; i < nums.size(); ++i){
            int target = nums[i];
            int index = i + 1;
            while(index < nums.size() && nums[index] == target){
                ++index;
            }
            if(index > i+1){
                nums.erase(nums.begin()+i+1, nums.begin()+index);
            }
        }
        return nums.size();
    }

    //Much better. Very fast.    
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length <= 0){
            return 0;
        }
        int index = 1;
        for(int i = 1; i < length; ++i){
            if(nums[i] != nums[i-1]){
                nums[index] = nums[i];
                ++index;
            }
        }
        nums.erase(nums.begin()+index, nums.end());
        return index;
    }
};
