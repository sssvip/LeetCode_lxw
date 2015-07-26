// File: num219.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num219: Contains Duplicate II
Source: https://leetcode.com/problems/contains-duplicate-ii/

Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int length = nums.size();
        if(length <= 1)
            return false;
        unordered_map<int, int> valueIndices;
        unordered_map<int, int>::iterator it;
        for(int i = 0; i < length; ++i){
            it = valueIndices.find(nums[i]);
            if(it == valueIndices.end()){   //no
                valueIndices[nums[i]] = i;
            }
            else{
                if(i - valueIndices[nums[i]] <= k)
                    return true;
                else
                    valueIndices[nums[i]] = i;
            }
        }
        return false;
    }
};