// File: num040_8ms.cpp
// Author: lxw
// Date: 2015-06-24

/*
Num num040: Combination Sum II 
Source: https://leetcode.com/problems/combination-sum-ii/
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> vvi;
    void combinationSum2(vector<int> & candidates, int target, int start, vector<int> & vi){
        if(target == 0){
            this->vvi.push_back(vi);
            return;
        }
        int length = candidates.size();
        for(int i = start; i < length;){
            if(target < candidates[i]){
                return;
            }
            vi.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], i+1, vi);
            vi.pop_back();
            while(1){
                ++i;
                if(candidates[i] != candidates[i-1] || i == length)
                    break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<int> vi;
        combinationSum2(candidates, target, 0, vi);
        return this->vvi;
    }
};

int main(void){
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    vector<vector<int> > vvi = sol.combinationSum2(nums, 7);
    int length = vvi.size();
    for(int i = 0; i < length; ++i){
        int size = vvi[i].size();
        for(int j = 0; j < size; ++j){
            cout << vvi[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
