// File: num039.cpp
// Author: lxw
// Date: 2015-06-23

/*
Num 039: Combination Sum
Source: https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        sort(candidates.begin(), candidates.end());        
        vector<int> vi;
        combinationSum(candidates, target, 0, vi);
        return this->vvi;
    }
    
private:
    vector<vector<int> > vvi;
    void combinationSum(vector<int> &candidates, int target, int i, vector<int> &vi){        
        if(target == 0){
            this->vvi.push_back(vi);
            return;
        }
        int size = candidates.size();
        for(int j = i; j < size; ++j){
        	/*
            cout << "target: " << target << ", j: " << j << ", vi: ";
	        int size = vi.size();
	        for(int k = 0; k < size; ++k){
	            cout << vi[k] << ", ";
	        }
	        cout << endl;
	        */    
            if(target < candidates[j]){
            	return;
            }
            vi.push_back(candidates[j]);
            combinationSum(candidates, target - candidates[j], j, vi);
            vi.pop_back();
        }
    }
};

int main(void){
    Solution sol;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    vector<vector<int> > vvi = sol.combinationSum(nums, 7);
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
