// File: num036_better.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num 036: Valid Sudoku 
Source: https://leetcode.com/problems/valid-sudoku/

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
private:
	int row[9], col[9], sqr[3][3];
	bool check(int x, int y, int val) {
		return !((row[x]>>val)&1) && !((col[y]>>val)&1) && !((sqr[x/3][y/3]>>val)&1);
	}
	void mark(int x, int y, int val) {
		row[x] |= (1<<val);
		col[y] |= (1<<val);
		sqr[x/3][y/3] |= (1<<val);
	}
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(sqr, 0, sizeof(sqr));
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
				if (board[i][j] != '.') {
					if (!check(i, j, board[i][j] - '1'))
						return false;
					mark(i, j, board[i][j] - '1');
				}
		return true;
    }
};
