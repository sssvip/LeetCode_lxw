// File: num128.cpp
// Author: lxw
// Date: 2015-07-21

/*
Num num128: Longest Consecutive Sequence
Source: https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //O(nlogn)
        vector<int>::iterator it = unique(nums.begin(), nums.end());    //O(n)
        nums.resize(distance(nums.begin(), it));
        int length = nums.size();
        if(length <= 1)
            return length;
        int i = 0;
        int start = 0;
        int maxLength = 0;
        while(i < length){  //O(n)
            start = i;
            ++i;
            while(i < length && nums[i] == nums[start] + i - start){
                ++i;
            }
            if(i - start > maxLength)
                maxLength = i - start;
            if(i == length)
                break;
        }
        return maxLength;
    }
};