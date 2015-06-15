// Not too much: unordered_set(Hash table) is a little slower than the following method(Array).
//File: num036_array.cpp
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
public:
    bool rowColValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            vector<int> rowV(9, 0);
            vector<int> colV(9, 0);
            for(int j = 0; j < 9; ++j){
                char ch = board[i][j];
                if(ch != '.'){
                    if(rowV[ch-'1'] > 0){//in
                        return false;
                    }
                    else{
                        ++rowV[ch-'1'];
                    }
                }
                ch = board[j][i];
                if(ch != '.'){
                    if(colV[ch-'1'] > 0){//in
                        return false;
                    }
                    else{
                        ++colV[ch-'1'];
                    }
                }
            }
        }
        return true;
    }
    bool boxValid(vector<vector<char>>& board){
        for(int i = 0; i < 7; i+=3){
            for(int j = 0; j < 7; j+=3){
                vector<int> boxV(9, 0);
                for(int k = 0; k < 3; ++k){
                    for(int l = 0; l < 3; ++l){
                        char ch = board[i+k][j+l];
                        if(ch != '.'){
                            if(boxV[ch-'1'] > 0){//in
                                return false;
                            }
                            else{
                                ++boxV[ch-'1'];
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //size valid
        if(board.size() != 9){
            return false;
        }
        else{
            for(int i = 0; i < 9; ++i){
                if(board[i].size() != 9){
                    return false;
                }
            }
        }
        //row/col/box valid
        return (rowColValid(board) && boxValid(board));
    }
};
