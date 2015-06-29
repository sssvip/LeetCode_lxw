// File: num059.cpp
// Author: lxw
// Date: 2015-06-29

/*
Num num059: Spiral Matrix II 
Source: https://leetcode.com/problems/spiral-matrix-ii/

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > vvi;
        for(int i = 0; i < n; ++i){
            vvi.push_back(vector<int>(n, 0));
        }
        int start = 0;
        int number = 1;
        while(start < n-1-start){
            int offset = n - 1 - 2 * start;
            for(int j = start; j < n-1-start; ++j){
                vvi[start][j] = number;
                vvi[j][n-1-start] = number + offset;
                vvi[n-1-start][n-1-j] = number + offset * 2;
                vvi[n-1-j][start] = number + offset * 3;
                ++number;
            }
            number += offset * 3; //note here.
            ++start;
        }
        if(start == n-1-start){
            vvi[start][start] = number;
        }
        return vvi;
    }
};