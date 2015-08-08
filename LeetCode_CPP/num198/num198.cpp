// File: num198.cpp
// Author: lxw
// Date: 2015-08-08

/*
Num num198: House Robber
Source: https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        if(length == 1)
            return nums[0];
        if(length == 2)
            return max(nums[0], nums[1]);
        vector<int> profit(length);
        profit[0] = nums[0];
        profit[1] = nums[1];
        profit[2] = nums[0] + nums[2];
        for(int i = 3; i < length; ++i){
            profit[i] = max(profit[i-3], profit[i-2]) + nums[i];
        }
        return max(profit[length-2], profit[length-1]);
    }
};