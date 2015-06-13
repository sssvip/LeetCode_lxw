// File: num036.cpp
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
    bool rowValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            unordered_set<char> us;
            for(int j = 0; j < 9; ++j){
                char ch = board[i][j];
                if(ch != '.'){
                    if(us.find(ch) != us.end()){//in
                        return false;
                    }
                    else{
                        us.insert(ch);
                    }
                }
            }
        }
        return true;
    }
    bool colValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            unordered_set<char> us;
            for(int j = 0; j < 9; ++j){
                char ch = board[j][i];
                if(ch != '.'){
                    if(us.find(ch) != us.end()){//in
                        return false;
                    }
                    else{
                        us.insert(ch);
                    }
                }
            }
        }
        return true;
    }
    bool boxValid(vector<vector<char>>& board){
        for(int i = 0; i < 7; i+=3){
            for(int j = 0; j < 7; j+=3){
                unordered_set<char> us;
                for(int k = 0; k < 3; ++k){
                    for(int l = 0; l < 3; ++l){
                        char ch = board[i+k][j+l];
                        if(ch != '.'){
                            if(us.find(ch) != us.end()){//in
                                return false;
                            }
                            else{
                                us.insert(ch);
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
        if(rowValid(board) && colValid(board) && boxValid(board)){
            return true;
        }
        else{
            return false;
        }
    }
};
