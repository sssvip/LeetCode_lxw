// File: num018.cpp
// Author: lxw
// Date: 2015-06-01

/*
Num 018: 4Sum
Source: https://leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
1. Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
2. The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
        (-1,  0, 0, 1)
        (-2, -1, 1, 2)
        (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        int length = nums.size();
        if(length < 4){
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < length - 3; ++i){
            for(int j = i + 1; j < length - 2; ++j){
                int k = j + 1;
                int l = length - 1;
                while(k < l){
                    if(nums[i] + nums[j] + nums[k] + nums[l] < target){
                        ++k;
                    }
                    else if(nums[i] + nums[j] + nums[k] + nums[l] > target){
                        --l;
                    }
                    else{
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                        while(k < l && nums[k] == nums[k-1]){
                            ++k;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            --l;
                        }
                    }
                }
                while(j < length && nums[j] == nums[j+1]){
                    ++j;
                }
            }
            while(i < length && nums[i] == nums[i+1]){
                ++i;
            }
        }
        return result;
    }
};
