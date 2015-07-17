// File: num221.cpp
// Author: lxw
// Date: 2015-07-17

/*
Num num221: Maximal Square
Source: https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

/*
状态转移方程：
dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
上式中，dp[x][y]表示以坐标(x, y)为右下角元素的全1正方形矩阵的最大长度（宽度）
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        vector<vector<int> > vvi(rows, vector<int>(cols, 0));
        int max = 0;
        for(int j = 0; j < cols; ++j){
            if(matrix[0][j] == '1'){
                vvi[0][j] = 1;
                max = 1;
            }
        }
        for(int j = 0; j < rows; ++j){
            if(matrix[j][0] == '1'){
                vvi[j][0] = 1;
                max = 1;
            }
        }
        for(int i = 1; i < rows; ++i){
            for(int j = 1; j < cols; ++j){
                if(matrix[i][j] == '1'){
                    vvi[i][j] = min(vvi[i-1][j], min(vvi[i][j-1], vvi[i-1][j-1])) + 1;
                    if(vvi[i][j] > max)
                        max = vvi[i][j];
                }
            }
        }
        return max * max;
    }
};

/*
special case:
0001  1101  1111 0111 0111
->
0001
1102
2213
0324
0435
如果中间有小值,则会找不出来 如 4 3 5.

//wrong idea
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        vector<vector<int> > vvi(rows, vector<int>(cols, 0));
        for(int j = 0; j < cols; ++j){
            if(matrix[0][j] == '1')
                vvi[0][j] = 1;
        }
        for(int i = 1; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(matrix[i][j] == '1')
                    vvi[i][j] = vvi[i-1][j] + 1;
            }
        }
        int maxArea = 0;
        int temp = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                //left->right
                if(vvi[i][j] > cols - j){
                    continue;
                }
                int k = 1;
                for(; k < vvi[i][j]; ++k){
                    if(vvi[i][j+k] < vvi[i][j])
                        break;
                }
                if(k == vvi[i][j]){
                    temp = vvi[i][j] * vvi[i][j];
                    if(temp > maxArea)
                        maxArea = temp;
                }
                
                //right->left
                if(vvi[i][cols-1-j] > cols - j){
                    continue;
                }
                k = 1;
                for(; k < vvi[i][cols-1-j]; ++k){
                    if(vvi[i][cols-1-j-k] < vvi[i][cols-1-j])
                        break;
                }
                if(k == vvi[i][cols-1-j]){
                    temp = vvi[i][cols-1-j] * vvi[i][cols-1-j];
                    if(temp > maxArea)
                        maxArea = temp;
                }
            }
        }
        return maxArea;
    }
};