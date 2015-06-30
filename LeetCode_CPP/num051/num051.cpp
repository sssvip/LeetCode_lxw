// File: num051.cpp
// Author: lxw
// Date: 2015-06-30

/*
Num num051: N-Queens
Source: https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > ret;
    vector<vector<string> > solveNQueens(int n) {
        int *a = new int[n];
        memset(a, 0, n);
        backTrace(a, 0, n);
        return ret;
    }
    void backTrace(int a[], int k, int n) {
        if (k == n) {
            string s = "";
            for (int i = 0; i < n; i ++)
                s += ".";
            vector<string> v(n, s);
            for (int i = 0; i < n; i ++)
                v[i][a[i]] = 'Q';
            ret.push_back(v);
            return ;
        }
        for (int i = 0; i < n; i ++) {
            if (place(a, k, i)) {
                a[k] = i;
                backTrace(a, k + 1, n);
                a[k] = 0;
            }
        }
    }
    bool place(int a[], int k, int pos) {
        for (int i = 0; i < k; i ++) {
            //  same column.       diagonal.
            if (a[i] == pos || abs(i - k) == abs(a[i] - pos))  
                return false;
        }
        return true;
    }
};
