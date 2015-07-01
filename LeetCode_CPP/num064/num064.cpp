// File: num064.cpp
// Author: lxw
// Date: 2015-07-01

/*
Num num064: Minimum Path Sum 
Source: https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //get the result each line
        int row = grid.size();
        if(row < 1){
            return 0;
        }
        int col = grid[0].size();
        if(col < 1){
            return 0;
        }
        /*
        vector<vector<int> > minPathArr;
        vector<int> vec(col, 0);
        for(int i = 0; i < row; ++i){
            minPathArr.push_back(vec);
        }*/
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(i == 0 && j == 0){
                    continue;
                }
                else if(i == 0){
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }
                else if(j == 0){
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }
                else{
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
            }
        }
        return grid[row-1][col-1];
    }

    //tmn: Although the same time cost, but I think his idea and logic is better.
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m < 1)
            return 0;
        int n = grid[0].size();
        if (n < 1)
            return 0;
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i - 1];
        if (m == 1)
            return grid[0][n - 1];
        if (n == 1)
            return grid[m - 1][0];

        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j ++)
                grid[i][j] = grid[i][j] + (grid[i - 1][j] < grid[i][j -1] ? grid[i -1][j] : grid[i][j -1]);
                
        return grid[m - 1][n - 1];
    }
};