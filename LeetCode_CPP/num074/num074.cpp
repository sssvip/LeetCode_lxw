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
        
        int i = 0;
        int j = n - 1;
        int rowStart = 0;
        int rowEnd = m - 1;
        int colStart = 0;
        int colEnd = n - 1;
        while(1){
            if(target == matrix[i][j]){
                return true;
            }
            else if(target < matrix[i][j]){
                //current row
                --j;
                --colEnd;
                rowStart = rowEnd = i;
                if(colEnd < colStart)
                    return false;
            }
            else{
                //following columns
                ++i;
                ++rowStart;
                if(rowStart > rowEnd){
                    return false;
                }
            }
        }
    }
};