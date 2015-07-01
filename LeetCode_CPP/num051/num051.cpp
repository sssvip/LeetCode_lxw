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
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void showVec(vector<string> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << endl;
    }
    cout << vec[length-1] << endl;
    cout << endl;
}
void showVecVec(vector<vector<string>> & vvi){
    int length = vvi.size();
    if(length < 1)
        return;
    for(int i = 0; i < length; ++i){
        showVec(vvi[i]);
    }
}
class Solution {
private:
    vector<vector<string> > result;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> position(n, -1);
        placeOneRow(position, 0, n);
        return this->result;
    }
    
    void placeOneRow(vector<int> & pos, int row, int n){
        if(row == n){
            vector<string> vs(n, string(n, '.'));
            for(int i = 0; i < n; ++i){
                vs[i][pos[i]] = 'Q';
            }
            result.push_back(vs);
            return;
        }
        for(int j = 0; j < n; ++j){
            if(place(pos, row, j)){
                pos[row] = j;
                placeOneRow(pos, row+1, n);
                pos[row] = -1;
            }
        }
    }
    
    bool place(vector<int> & position, int row, int col){
        for(int i = 0; i < row; ++i){
            //   same column.                 diagonal.
            if(position[i] == col || abs(position[i] - col) == abs(i - row)){
                return false;
            }
        }
        return true;
    }
};

int main(void){
	Solution sol;	
	//2 dimensions vecotr
	vector<vector<string> > nQueens;
	nQueens = sol.solveNQueens(5);
    showVecVec(nQueens);
    return 0;
}
