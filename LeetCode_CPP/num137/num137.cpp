// File: num137.cpp
// Author: lxw
// Date: 2015-08-03

/*
Num num137: Single Number II
Source: https://leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> numMap;
        int length = nums.size();
        if(length == 0)
            return -1;
        if(length == 1)
            return nums[0];
        if(length < 4)
            return -1;
        for(int i = 0; i < length; ++i){
            if(numMap.find(nums[i]) == numMap.end()){
                numMap[nums[i]] = 1;
            }
            else{
                ++numMap[nums[i]];
            }
        }
        /*
        //NO
        for(auto item : numMap){
            if(numMap[item]  != 3)
                return item;
        }*/
        for(map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it){
            if(it->second != 3) 
                return it->first;
        }
        return 0;
    }
};