// File: num216.cpp
// Author: lxw
// Date: 2015-08-08

/*
Num num216: Combination Sum III
Source: https://leetcode.com/problems/combination-sum-iii/

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
private:
    vector<vector<int>> vvi;
    void combinationSum3(int k, int n, vector<int>& vi, int start){
        if(k == 0){
            if(n == 0)
                this->vvi.push_back(vi);
            return;
        }
        for(int i = start; i <=9; ++i){
            vi.push_back(i);
            combinationSum3(k-1, n-i, vi, i+1);
            vi.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vi;
        combinationSum3(k, n, vi, 1);
        return this->vvi;
    }
};