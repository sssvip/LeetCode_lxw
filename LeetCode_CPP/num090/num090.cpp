// File: num090.cpp
// Author: lxw
// Date: 2015-07-27

/*
Num 090: Subsets II
Source: https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
private:
    vector<vector<int> > vvi;
    void subsets(vector<int>& nums, int start, int end, int count, vector<int>& vi) {
        if(count == 0){
            this->vvi.push_back(vi);
            return;
        }
        if(start > end)
            return;
        for(int i = start; i <= end; ++i){
            vi.push_back(nums[i]);
            subsets(nums, i + 1, end, count - 1, vi);
            vi.pop_back();
            while(i < end && nums[i+1] == nums[i])
                ++i;
            //i == end || nums[i+1] != nums[i]
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int length = nums.size();
        vector<int> vi;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= length; ++i){
            subsets(nums, 0, length-1, i, vi);
        }
        return this->vvi;
    }
};