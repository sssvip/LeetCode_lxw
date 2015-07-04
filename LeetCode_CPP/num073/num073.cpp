// File: num073.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num num073: Set Matrix Zeroes 
Source: https://leetcode.com/problems/set-matrix-zeroes/
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m < 1)
            return;
        int n = matrix[0].size();
        if(n < 1)
            return;
        unordered_set<int> si;
        bool flag = false;
        for(int i = 0; i < m; ++i){
            flag = false;
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    si.insert(j);
                    flag = true;
                }
            }
            if(flag){
                for(int j = 0; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(auto index : si){
            for(int i = 0; i < m; ++i){
                matrix[i][index] = 0;
            }
        }
    }
};