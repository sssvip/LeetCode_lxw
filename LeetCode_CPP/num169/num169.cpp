// File: num169.cpp
// Author: lxw
// Date: 2015-08-28

/*
Num num169: Majority Element
Source: https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        //Method 1:
        int length = nums.size();
        sort(nums.begin(), nums.end());
        return nums[length / 2];
        */
        
        //Method 2:
        unordered_map<int, int> um;
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            if(um.find(nums[i]) != um.end()){
                ++um[nums[i]];
            }
            else{
                um[nums[i]] = 1;
            }
        }
        int count = length >> 1; //length / 2
        unordered_map<int, int>::iterator it;
        for(it = um.begin(); it != um.end(); ++it){
            if(it->second > count) //not '>='
                return it->first;
        }
    }
};