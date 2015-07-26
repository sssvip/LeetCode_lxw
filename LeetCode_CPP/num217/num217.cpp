// File: num217.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num217: Contains Duplicate
Source: https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*Method 1:
        //52ms
        unordered_set<int> us(nums.begin(), nums.end());
        return us.size() != nums.size();*/
        
        /*Method 2:
        //96ms
        set<int> s;
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            if(s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                return true;
        }
        return false;
        */
        
        //Method 3:
        //40ms
        int length = nums.size();
        if(length <= 1)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < length-1; ++i){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};