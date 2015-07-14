// File: num079.cpp
// Author: lxw
// Date: 2015-07-14

/*
Num num079: Word Search
Source: https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

class Solution {
public:
    //如果允许重复
    bool exist(vector<vector<char> > & board, int i, int j, int rows, int cols, const string & word, int index){
        if(index == word.length()-1)
            return true;
        if(i-1 >= 0 && board[i-1][j] == word[index+1])
            if(exist(board, i-1, j, rows, cols, word, index+1))
                return true;
        if(j-1 >= 0 && board[i][j-1] == word[index+1])
            if(exist(board, i, j-1, rows, cols, word, index+1))
                return true;
        if(j+1 <= cols && board[i][j+1] == word[index+1])
            if(exist(board, i, j+1, rows, cols, word, index+1))
                return true;
        if(i+1 <= rows && board[i+1][j] == word[index+1])
            if(exist(board, i+1, j, rows, cols, word, index+1))
                return true;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size() - 1;
        int cols = board[0].size() - 1;
        for(int i = 0; i <= rows; ++i){
            for(int j = 0; j <= cols; ++j){
                if(board[i][j] == word[0]){
                    if(exist(board, i, j, rows,cols, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

int main(void){
	
	vector<char> vec;
    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('C');
    vec.push_back('E');
    
	vector<vector<char> > matrix;
	matrix.push_back(vec);
	vec.clear();
	vec.push_back('S');
    vec.push_back('F');
    vec.push_back('C');
    vec.push_back('S');
    matrix.push_back(vec);
	vec.clear();
	vec.push_back('A');
    vec.push_back('D');
    vec.push_back('E');
    vec.push_back('E');
    matrix.push_back(vec);
	/*
	matrix.push_back("ABCE");
	matrix.push_back("SFCS");
	matrix.push_back("ADEE");*/
	Solution sol;
	cout << sol.exist(matrix, "ABCCED") << endl;	
	cout << sol.exist(matrix, "SEE") << endl;
	cout << sol.exist(matrix, "ABCB") << endl;
	cout << sol.exist(matrix, "ABCCD") << endl;
    return 0;
}