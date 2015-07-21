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
        //unordered_set is faster than set.
        //这种方法比sort->unique->resize的花费时间要长
        unordered_set<int> numSet(nums.begin(), nums.end());
        int length = numSet.size();
        if(length <= 1)
            return length;
        int high = 0;
        int low = 0;
        int maxLength = 1;
        while(!numSet.empty()){
            unordered_set<int>::iterator it = numSet.begin();
            high = *it;
            low = *it;
            numSet.erase(it);
            while((it = numSet.find(++high)) != numSet.end())
                numSet.erase(it);
            while((it = numSet.find(--low)) != numSet.end())
                numSet.erase(it);
            if(maxLength < high - low - 1)
                maxLength = high - low - 1;
        }
        return maxLength;
    }
};