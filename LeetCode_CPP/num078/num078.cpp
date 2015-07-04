// File: num078.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num num078: Subsets
Source: https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
private:
    vector<vector<int> > vvi;
    void subsets(vector<int> & nums, int start, int end, int count, vector<int> & vi){
        if(count == 0){
            this->vvi.push_back(vi);
            return;
        }
        if(start > end){
            return;
        }
        for(int i = start; i <= end; ++i){
            vi.push_back(nums[i]);
            subsets(nums, i+1, end, count-1, vi);
            vi.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size();
        if(length < 1){
            return this->vvi;
        }
        sort(nums.begin(), nums.end());
        vector<int> vi;
        for(int i = 0; i <= length; ++i){
            subsets(nums, 0, length-1, i, vi);
        }
        return this->vvi;
    }
};