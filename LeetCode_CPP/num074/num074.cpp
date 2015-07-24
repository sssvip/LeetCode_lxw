// File: num074.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num num074: Search a 2D Matrix 
Source: https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m < 0)
            return false;
        int n = matrix[0].size();
        if(n < 0)
            return false;
        
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        while((right >= left && top  <= bottom)){
            if(target == matrix[top][right]){
                return true;
            }
            if(target < matrix[top][right]){
                //current row
                --right;
                bottom = top;
            }
            else{
                //remove one row.
                ++top;
            }
        }
        return false;
    }
};