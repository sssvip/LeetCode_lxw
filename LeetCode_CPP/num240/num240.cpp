// File: num240.cpp
// Author: lxw
// Date: 2015-07-23

/*
Num num240: Search a 2D Matrix II
Source: https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;
        while(left <= right && top <= bottom){
            if(target == matrix[top][right])
                return true;
            if(target < matrix[top][right]){
                --right;
            }
            if(target > matrix[top][right]){
                ++top;
            }
        }
        return false;
    }
};