// File: num220.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num220: Contains Duplicate III
Source: https://leetcode.com/problems/contains-duplicate-iii/

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0)
            return false;
        multiset<int> mset;
        for (int i = 0; i < nums.size(); i ++) {
            auto it = mset.lower_bound(nums[i] - t);
            if (it != mset.end()) {
            	//如果nums[i] < *it, 则*it - nums[i]可能比t大的，所以在内部又增加了一个判断条件
                int diff = abs(nums[i] - *it);
                if (diff <= t)
                    return true;
            }
            if (mset.size() == k)
                mset.erase(nums[i - k]);
            mset.insert(nums[i]);
        }
        return false;
    }
};