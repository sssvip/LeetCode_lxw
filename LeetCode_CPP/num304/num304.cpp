// File: num304.cpp
// Author: lxw
// Date: 2015-11-23

/*
Num num304: Range Sum Query 2D - Immutable
Source: https://leetcode.com/problems/range-sum-query-2d-immutable/
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
Subscribe to see which companies asked this question
*/

class NumMatrix {
private:
    vector<vector<int> > dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int rowLen = matrix.size();
        if(rowLen == 0)
            return;
        int colLen = matrix[0].size();
        //use vector<vector<int> > like a 2-dimension array.
        dp.resize(rowLen);
        for(int row = 0; row < rowLen; ++row){
            dp[row].resize(colLen);
        }
        //row 0
        dp[0][0] = matrix[0][0];
        for(int col = 1; col < colLen; ++col){
            dp[0][col] = dp[0][col-1] + matrix[0][col];
        }
        
        //col 0
        for(int row = 1; row < rowLen; ++row){
            dp[row][0] = dp[row-1][0] + matrix[row][0];
        }
        //1,1 ~ rowLen, colLen
        //dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
        for(int row = 1; row < rowLen; ++row){
            for(int col = 1; col < colLen; ++col){
                dp[row][col] = dp[row-1][col] + dp[row][col-1] - dp[row-1][col-1] + matrix[row][col];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int rowLen = dp.size();
        if(rowLen == 0)
            return -1;
        int colLen = dp[0].size();
        if(row1 > row2 || col1 > col2 || row2 >= rowLen || col2 >= colLen || row1 < 0 || col1 < 0)
            return -1;
        if(row1 == 0 && col1 == 0)
            return dp[row2][col2];
        if(row1 == 0)
            return dp[row2][col2] - dp[row2][col1-1];
        if(col1 == 0)
            return dp[row2][col2] - dp[row1-1][col2];
        //result = dp[r2][c2] + dp[r1-1][c1-1] - dp[r1-1][c2] - dp[r2][c1-1];
        return dp[row2][col2] + dp[row1-1][col1-1] - dp[row1-1][col2] - dp[row2][col1-1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);