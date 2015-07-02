// File: num062.cpp
// Author: lxw
// Date: 2015-07-02

/*
Num num062: Unique Paths 
Source: https://leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
        if(m == 1 || n == 1)
            return 1;
        vector<vector<int> > vvi;
        vector<int> vi(n, 1);
        for(int i = 0; i < m; ++i){
            vvi.push_back(vi);
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                vvi[i][j] = vvi[i-1][j] + vvi[i][j-1];
            }
        }
        return vvi[m-1][n-1];
    }
};