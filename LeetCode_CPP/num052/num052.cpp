// File: num052.cpp
// Author: lxw
// Date: 2015-07-01

/*
Num num052: N-Queens
Source: https://leetcode.com/problems/n-queens-ii/

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int count;
public:
    int totalNQueens(int n) {
        this->count = 0;
        vector<int> position(n, -1);
        placeOneRow(position, 0, n);
        return this->count;
    }
    
    void placeOneRow(vector<int> & pos, int row, int n){
        if(row == n){
            ++this->count;
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
    
    bool place(vector<int> & pos, int row, int col){
        for(int i = 0; i < row; ++i){
            if(pos[i] == col || abs(pos[i] - col) == abs(i - row)){
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
	cout << sol.totalNQueens(4) << endl;
    return 0;
}
